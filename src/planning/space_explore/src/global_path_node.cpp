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
}

int main(int argc, char **argv) {
    // Initialize the node, publishers and subscribers.
    ros::init(argc, argv, "global_path");
    ros::NodeHandle nh("~");
    std::string image_dir = ros::package::getPath("space_explore");
    std::string base_dir = image_dir;
    std::string image_file = "obstacles.png";
    image_dir.append("/" + image_file);
    cv::Mat img_src = cv::imread(image_dir, CV_8UC1);

    int rows = img_src.rows;
    int cols = img_src.cols;
    double resolution = 0.1;  // in meter
    hmpl::InternalGridMap in_gm;
    in_gm.initializeFromImage(img_src, resolution, grid_map::Position::Zero());
    in_gm.addObstacleLayerFromImage(img_src, 0.5);
    in_gm.updateDistanceLayer();

    bool display_flag = false;
    hmpl::SpaceExplore holonomic(in_gm, display_flag);
    in_gm.maps.setFrameId("/map");

    ROS_INFO("Created map with size %f x %f m (%i x %i cells).",
             in_gm.maps.getLength().x(), in_gm.maps.getLength().y(),
             in_gm.maps.getSize()(0), in_gm.maps.getSize()(1));
    // Create publishers and subscribers
    ros::Publisher path_publisher =
            nh.advertise<nav_msgs::Path>("modified_path", 1, true);
    ros::Publisher publisher =
            nh.advertise<nav_msgs::OccupancyGrid>("grid_map", 1, true);

    // callback function for start and goal
    ros::Subscriber start_sub = nh.subscribe("/initialpose", 1, startCb);
    ros::Subscriber end_sub = nh.subscribe("/move_base_simple/goal", 1, goalCb);

    // Publisher in a loop.
    ros::Rate rate(0.1);
    while (nh.ok()) {
        // Add data to grid map.
        ros::Time time = ros::Time::now();
        holonomic.sp_rviz_->i = 0;

        // publish the grid_map
        in_gm.maps.setTimestamp(time.toNSec());
        nav_msgs::OccupancyGrid message;
        grid_map::GridMapRosConverter::toOccupancyGrid(
                in_gm.maps, in_gm.obs, in_gm.FREE, in_gm.OCCUPY, message);

        // search through the environment to get a path
        auto start = std::chrono::steady_clock::now();

        holonomic.solve(in_gm, start_point, end_point);

        auto end = std::chrono::steady_clock::now();
        double elapsed_secondes =
                std::chrono::duration_cast<std::chrono::duration<double> >(
                        end - start)
                        .count();

        std::cout << "search time:" << elapsed_secondes << std::endl;

        nav_msgs::Path path_msg;
        geometry_msgs::PoseStamped pose;
        path_msg.header.frame_id = in_gm.maps.getFrameId();
        path_msg.header.stamp = ros::Time::now();
        pose.header = path_msg.header;
        for (auto &point_itr : holonomic.getDensePath()) {
            pose.pose.position.x = point_itr.x;
            pose.pose.position.y = point_itr.y;
            pose.pose.position.z = 0;
            path_msg.poses.push_back(pose);
        }

        path_publisher.publish(path_msg);
        publisher.publish(message);
        ROS_INFO_THROTTLE(1.0, "Grid map (timestamp %f) published.",
                          message.header.stamp.toSec());
        // Wait for next cycle.
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
