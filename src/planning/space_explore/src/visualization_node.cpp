/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC),
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: detailed_node.cpp
 *   Created on: 11, 23, 2018
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Path.h>
#include <ros/package.h>
#include <ros/ros.h>
#include <chrono>
#include <grid_map_ros/grid_map_ros.hpp>
#include <tf/transform_datatypes.h>
#include "space_explore/space_explore.hpp"

hmpl::Pose2D start_point(35.0, 30.0, M_PI);
hmpl::Pose2D end_point(-30.0, 30.0, M_PI);
bool trigger_flag = true;

void startCb(const geometry_msgs::PoseWithCovarianceStampedConstPtr &start) {
    start_point.position.x = start->pose.pose.position.x;
    start_point.position.y = start->pose.pose.position.y;
    start_point.orientation = tf::getYaw(start->pose.pose.orientation);
    std::cout << "get initial state." << std::endl;
}

void goalCb(const geometry_msgs::PoseStampedConstPtr &goal) {
    end_point.position.x = goal->pose.position.x;
    end_point.position.y = goal->pose.position.y;
    end_point.orientation = tf::getYaw(goal->pose.orientation);
    std::cout << "get the goal." << std::endl;
    trigger_flag = true;
}

int main(int argc, char **argv) {
    // Initialize the node, publishers and subscribers.
    ros::init(argc, argv, "visualization_node");
    ros::NodeHandle nh("~");
    std::string image_dir = ros::package::getPath("space_explore");
    std::string base_dir = image_dir;
    std::string image_file = "obstacles.png";
    image_dir.append("/" + image_file);
    cv::Mat img_src = cv::imread(image_dir, CV_8UC1);

    int rows = img_src.rows;
    int cols = img_src.cols;
    double resolution = 0.2;  // in meter
    hmpl::InternalGridMap in_gm;
    in_gm.initializeFromImage(img_src, resolution, grid_map::Position::Zero());
    in_gm.addObstacleLayerFromImage(img_src, 0.5);
    in_gm.updateDistanceLayer();
    in_gm.maps.setFrameId("/map");

    ROS_INFO("Created map with size %f x %f m (%i x %i cells).",
             in_gm.maps.getLength().x(), in_gm.maps.getLength().y(),
             in_gm.maps.getSize()(0), in_gm.maps.getSize()(1));
    // Create publishers and subscribers
    ros::Publisher path_publisher =
            nh.advertise<nav_msgs::Path>("modified_path", 1, true);
    ros::Publisher path_publisher_original =
        nh.advertise<nav_msgs::Path>("modified_path_original", 1, true);
    ros::Publisher publisher =
            nh.advertise<nav_msgs::OccupancyGrid>("grid_map", 1, true);

    ros::Publisher pcl_pub =
            nh.advertise<sensor_msgs::PointCloud2>("pontential_field", 1, true);

    // callback function for start and goal
    ros::Subscriber start_sub = nh.subscribe("/initialpose", 1, startCb);
    ros::Subscriber end_sub = nh.subscribe("/move_base_simple/goal", 1, goalCb);
    std::cout << "trigger the loop." << std::endl;
    trigger_flag = true;
    // Add data to grid map.
    ros::Time time = ros::Time::now();


    // publish the grid_map
    in_gm.maps.setTimestamp(time.toNSec());
    nav_msgs::OccupancyGrid message;
    grid_map::GridMapRosConverter::toOccupancyGrid(
            in_gm.maps, in_gm.obs, in_gm.FREE, in_gm.OCCUPY, message);
    publisher.publish(message);
    ROS_INFO_THROTTLE(1.0, "Grid map (timestamp %f) published.",
                      message.header.stamp.toSec());

    // voronoi field
    auto voro_start = std::chrono::steady_clock::now();
    VoronoiDiagram voronoi(in_gm.maps, 3);
    auto voro_end = std::chrono::steady_clock::now();
    double voro_secondes =
        std::chrono::duration_cast<std::chrono::duration<double> >(
            voro_end - voro_start)
            .count();
    std::cout << "voronoi diagram time cost: " << voro_secondes << std::endl;

    grid_map::GridMap gmap;
    voronoi.getPotentialField(in_gm.maps, &gmap);
    gmap.get("potential") *= 10.0;
    sensor_msgs::PointCloud2 pcl_msg;
    grid_map::GridMapRosConverter::toPointCloud(gmap, "potential", pcl_msg);
    pcl_pub.publish(pcl_msg);
    std::cout << "publish point cloud msgs size: " << gmap.getSize();

    bool display_flag = false;
    hmpl::SpaceExplore holonomic(in_gm, display_flag, voronoi);
    holonomic.setLowerBoundary(1.1);
    hmpl::SpaceExplore holonomic_original(in_gm, display_flag);
    holonomic_original.setLowerBoundary(1.1);

    // Wait for next cycle.
    // Publisher in a loop.
    while (nh.ok()) {
        if (trigger_flag == true) {
//            holonomic.sp_rviz_->clearDisplay();
//            holonomic.sp_rviz_->i = 0;
//            holonomic.sp_rviz_->clearMarkerArray();
//            holonomic.updateDisplayRvizFlagFromRqt();
            // search through the environment to get a path
            auto start = std::chrono::steady_clock::now();

            holonomic.solve(in_gm, start_point, end_point);

            auto end = std::chrono::steady_clock::now();
            double elapsed_secondes =
                    std::chrono::duration_cast<std::chrono::duration<double> >(
                            end - start)
                            .count();
            std::cout << "total search time:" << elapsed_secondes << std::endl;

            auto start_original = std::chrono::steady_clock::now();
            holonomic_original.solve(in_gm, start_point, end_point);
            auto end_original = std::chrono::steady_clock::now();
            double elapsed_secondes_original =
                std::chrono::duration_cast<std::chrono::duration<double> >(
                    end_original - start_original)
                    .count();
            std::cout << "total search time of original method:" << elapsed_secondes_original << std::endl;

            nav_msgs::Path path_msg;
            geometry_msgs::PoseStamped pose;
            path_msg.header.frame_id = in_gm.maps.getFrameId();
            path_msg.header.stamp = ros::Time::now();
            pose.header = path_msg.header;
            for (const auto &point_itr : holonomic.getDensePath()) {
                pose.pose.position.x = point_itr.x;
                pose.pose.position.y = point_itr.y;
                pose.pose.position.z = 0;
                path_msg.poses.push_back(pose);
            }

            path_publisher.publish(path_msg);

            nav_msgs::Path path_msg_original;
            geometry_msgs::PoseStamped pose_original;
            path_msg_original.header.frame_id = in_gm.maps.getFrameId();
            path_msg_original.header.stamp = ros::Time::now();
            pose_original.header = path_msg_original.header;
            for (const auto &point_itr : holonomic_original.getDensePath()) {
                pose_original.pose.position.x = point_itr.x;
                pose_original.pose.position.y = point_itr.y;
                pose_original.pose.position.z = 0;
                path_msg_original.poses.push_back(pose_original);
            }

            path_publisher_original.publish(path_msg_original);

            trigger_flag = false;

        }
        ros::spinOnce();
    }
    return 0;
}
