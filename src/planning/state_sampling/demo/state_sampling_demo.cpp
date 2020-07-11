/* Copyright (c) 2017, Yu Zhang, Intelligent Vehicle Research Center(IVRC),
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: state_sampling_demo.cpp
 *   Created on: 05, 07, 2017
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include "state_sampling/state_sampling.hpp"
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Path.h>
#include <ros/package.h>
#include <ros/ros.h>
#include <visualization_msgs/MarkerArray.h>
#include <chrono>
#include <grid_map_ros/grid_map_ros.hpp>
#include <internal_grid_map/internal_grid_map.hpp>
#include <car_model/car_geometry.hpp>
#include <opt_solver/nlp_solver.hpp>
#include <opt_utils/opt_utils.hpp>
#include <space_explore/space_explore.hpp>
#include <tf/transform_datatypes.h>

hmpl::Pose2D start_point(35.0, 30.0, M_PI);
hmpl::Pose2D end_point(-30.0, 30.0, M_PI / 2.0);

void fillCurve(std::vector<hmpl::State> *curve) {
    if (curve->empty()) {
        return;
    }
    std::size_t size = curve->size();
    double s = 0;
    for (std::size_t i = 0; i < size - 1; i++) {
        if (i == 0) {
            curve->at(i).k = 0;
            curve->at(i).s = 0;
        }
        hmpl::State &state1 = curve->at(i);
        hmpl::State &state2 = curve->at(i + 1);
        double dx = state2.x - state1.x;
        double dy = state2.y - state1.y;
        double delta_s = sqrt(dx * dx + dy * dy);
        curve->at(i).z = atan2(dy, dx);
        s += delta_s;
        curve->at(i + 1).s = s;
        if (i + 2 < size - 2) {
            hmpl::Vector2D<double> pt1(state1.x, state1.y);
            hmpl::Vector2D<double> pt2(state2.x, state2.y);
            hmpl::Vector2D<double> pt3(curve->at(i + 2).x, curve->at(i + 2).y);
            curve->at(i + 1).k = hmpl::getCurvature(pt1, pt2, pt3);
        }
    }
    curve->back().z = curve->at(size - 2).z;
    curve->back().k = 0;
}
void publishFinalPath(const ros::Publisher &pub,
                      const std::vector<hmpl::PathWithCost> &final_path,
                      const hmpl::State &current) {
    if (final_path.empty()) {
        return;
    }
    visualization_msgs::Marker path_marker;
    visualization_msgs::MarkerArray path_set_marker;
    path_marker.header.frame_id = "/map";
    path_marker.header.stamp = ros::Time::now();
    path_marker.ns = "final_path";
    path_marker.id = 400;  //  make an id space for path only.
    path_marker.type = visualization_msgs::Marker::LINE_STRIP;
    path_marker.pose.orientation.x = 0.0;
    path_marker.pose.orientation.y = 0.0;
    path_marker.pose.orientation.z = 0.0;
    path_marker.pose.orientation.w = 1.0;
    path_marker.lifetime = ros::Duration(1.0);
    path_marker.pose.position.x = 0;
    path_marker.pose.position.y = 0;
    path_marker.pose.position.z = 0.0;
    path_marker.scale.x = 0.05;  // 2.5

    for (auto &path_itr : final_path) {
        if (path_itr.collision_free) {
            path_marker.color.a = 1.0;
            path_marker.color.b = 1.0;
            path_marker.color.r = 0.0;
            path_marker.color.g = 0.0;
        } else {
            path_marker.color.a = 1.0;
            path_marker.color.b = 0.0;
            path_marker.color.r = 1.0;
            path_marker.color.g = 0.0;
        }
        path_marker.id += 1;
        path_marker.points.clear();

        // ego to map

        for (auto &point_itr : path_itr.path) {
            geometry_msgs::Point p;
            p.x = point_itr.x;
            p.y = point_itr.y;
            p.z = 0.0;
            path_marker.points.push_back(p);
        }
        path_set_marker.markers.push_back(path_marker);
    }
    pub.publish(path_set_marker);
}
void publishSingleBestPath(const ros::Publisher &pub,
                           const hmpl::PathWithCost &best,
                           const hmpl::State &current) {
    if (best.path.empty()) {
        return;
    }
    visualization_msgs::Marker path_marker;
    visualization_msgs::MarkerArray path_set_marker;
    path_marker.header.frame_id = "/map";
    path_marker.header.stamp = ros::Time::now();
    path_marker.ns = "best_path";
    path_marker.id = 500;  //  make an id space for path only.
    path_marker.type = visualization_msgs::Marker::LINE_STRIP;
    path_marker.pose.orientation.x = 0.0;
    path_marker.pose.orientation.y = 0.0;
    path_marker.pose.orientation.z = 0.0;
    path_marker.pose.orientation.w = 1.0;
    path_marker.pose.position.x = 0;
    path_marker.pose.position.y = 0;
    path_marker.pose.position.z = 0.0;
    path_marker.scale.x = 0.2;

    if (best.collision_free) {
        path_marker.color.a = 1.0;
        path_marker.color.b = 1.0;
        path_marker.color.r = 0.0;
        path_marker.color.g = 0.0;
    } else {
        path_marker.color.a = 1.0;
        path_marker.color.b = 1.0;
        path_marker.color.r = 0.0;
        path_marker.color.g = 0.0;
    }
    path_marker.id += 1;
    path_marker.points.clear();

    // ego to map

    for (auto point_itr = best.path.begin(); point_itr != best.path.end();
         ++point_itr) {
//        hmpl::State global_state = hmpl::localToGlobal(current, *point_itr);
        geometry_msgs::Point p;
        p.x = point_itr->x;
        p.y = point_itr->y;
//        p.x = global_state.x;
//        p.y = global_state.y;
        p.z = 0.0;
        path_marker.points.push_back(p);
    }
    path_set_marker.markers.push_back(path_marker);
    pub.publish(path_set_marker);
}

void publishFootPrint(const ros::Publisher &pub,
                      const std::vector<hmpl::Circle> &centers) {
    if (centers.empty()) {
        return;
    }
    visualization_msgs::Marker center_marker;
    visualization_msgs::MarkerArray center_set_marker;
    center_marker.header.frame_id = "/map";
    center_marker.header.stamp = ros::Time::now();
    center_marker.ns = "car";
    center_marker.id = 500;
    center_marker.type = visualization_msgs::Marker::SPHERE;
    center_marker.action = visualization_msgs::Marker::ADD;

    if (centers.empty()) return;

    center_marker.pose.orientation.x = 0.0;
    center_marker.pose.orientation.y = 0.0;
    center_marker.pose.orientation.z = 0.0;
    center_marker.pose.orientation.w = 1.0;

    center_marker.color.a = 0.5;
    center_marker.color.b = 1.0;
    center_marker.points.clear();
    center_set_marker.markers.clear();

    for (auto &center_itr : centers) {
        center_marker.id += 1;
        center_marker.pose.position.x = center_itr.position.x;
        center_marker.pose.position.y = center_itr.position.y;
        center_marker.pose.position.z = 0;
        double scale = 2 * center_itr.r;
        center_marker.scale.x = scale;
        center_marker.scale.y = scale;
        center_marker.scale.z = scale;
        center_set_marker.markers.push_back(center_marker);
    }

    pub.publish(center_set_marker);
}

void publishSinglePathSet(const ros::Publisher &pub,
                          const hmpl::StateSampling::ObserveVariable &observe) {
    if (observe.path_set.empty()) {
        ROS_WARN("no sampling result!");
        return;
    }
    visualization_msgs::Marker path_marker;
    visualization_msgs::MarkerArray path_set_marker;
    path_marker.header.frame_id = "/map";
    path_marker.header.stamp = ros::Time::now();
    path_marker.ns = "state_sampling_demo";
    path_marker.id = 400;  //  make an id space for path only.
    path_marker.type = visualization_msgs::Marker::LINE_STRIP;
    path_marker.pose.orientation.x = 0.0;
    path_marker.pose.orientation.y = 0.0;
    path_marker.pose.orientation.z = 0.0;
    path_marker.pose.orientation.w = 1.0;
    path_marker.pose.position.x = 0;
    path_marker.pose.position.y = 0;
    path_marker.pose.position.z = 0.0;
    path_marker.scale.x = 0.02;

    for (const auto &singel_phase_path_set:observe.path_set) {
        for (const auto &path_itr:singel_phase_path_set) {
            if (path_itr.collision_free) {
                path_marker.color.a = 1.0;
                path_marker.color.b = 0.0;
                path_marker.color.r = 0.0;
                path_marker.color.g = 1.0;
            } else {
                path_marker.color.a = 1.0;
                path_marker.color.b = 0.0;
                path_marker.color.r = 1.0;
                path_marker.color.g = 0.0;
            }
            path_marker.id += 1;
            path_marker.points.clear();
            // ego to map
            for (const auto &pt :path_itr.path) {
                geometry_msgs::Point p;
                p.x = pt.x;
                p.y = pt.y;
                p.z = 0.0;
                path_marker.points.push_back(p);
            }
            path_set_marker.markers.push_back(path_marker);
        }
    }
    pub.publish(path_set_marker);
}

void publishSpline(const ros::Publisher &pub,
                   const std::vector<hmpl::State> &curve) {
    if (curve.empty()) {
        return;
    }
    visualization_msgs::Marker path_marker;
    visualization_msgs::MarkerArray path_set_marker;
    path_marker.header.frame_id = "/map";
    path_marker.header.stamp = ros::Time::now();
    path_marker.ns = "bspline";
    path_marker.id = 0;  //  make an id space for path only.
    path_marker.type = visualization_msgs::Marker::LINE_STRIP;
    path_marker.pose.orientation.x = 0.0;
    path_marker.pose.orientation.y = 0.0;
    path_marker.pose.orientation.z = 0.0;
    path_marker.pose.orientation.w = 1.0;
    path_marker.pose.position.x = 0;
    path_marker.pose.position.y = 0;
    path_marker.pose.position.z = 0.0;
    path_marker.scale.x = 0.03;

    // ego to map
    for (std::size_t i = 0; i < curve.size() - 1; i++) {
        if (curve.at(i).v > 0) {
            path_marker.color.a = 1.0;
            path_marker.color.b = 0.5;
            path_marker.color.r = 0.5;
            path_marker.color.g = 0.0;
        } else {
            path_marker.color.a = 1.0;
            path_marker.color.b = 0.0;
            path_marker.color.r = 0.5;
            path_marker.color.g = 0.5;
        }
        path_marker.id += 1;
        path_marker.points.clear();

        geometry_msgs::Point p, p1;
        p.x = curve.at(i).x;
        p.y = curve.at(i).y;
        p.z = 0.0;
        p1.x = curve.at(i + 1).x;
        p1.y = curve.at(i + 1).y;
        p1.z = 0;
        path_marker.points.push_back(p);
        path_marker.points.push_back(p1);
        path_set_marker.markers.push_back(path_marker);
    }
    pub.publish(path_set_marker);
}

void publishCurvature(const ros::Publisher &pub,
                      const std::vector<hmpl::State> &curve, double scale,
                      double curvature_max) {
    if (curve.empty()) {
        return;
    }
    visualization_msgs::MarkerArray kappa_set;
    // publisher path in global frame
    visualization_msgs::Marker kappa_list;
    kappa_list.header.frame_id = "map";
    kappa_list.header.stamp = ros::Time::now();
    kappa_list.ns = "modifed_path";
    kappa_list.id = 1;
    kappa_list.type = visualization_msgs::Marker::LINE_LIST;
    kappa_list.action = visualization_msgs::Marker::ADD;
    kappa_list.scale.x = 0.1;  // arrow length
    kappa_list.color.a = 1.0;  // Don't forget to set the alpha!
    kappa_list.color.r = 1.0;
    kappa_list.color.g = 1.0;
    kappa_list.color.b = 0.0;
    geometry_msgs::Point pt1, pt2;

    auto begin = curve.begin();
    for (auto itr = curve.begin(); itr != curve.end(); ++itr) {
        if ((itr - begin) % 2) {
            pt1.x = itr->x;
            pt1.y = itr->y;
            pt1.z = 0;
            double heading;
            if (itr->k > 0) {
                heading = itr->z - M_PI / 2.0;
            } else if (itr->k == 0) {
                heading = itr->z;
            } else {
                heading = itr->z + M_PI / 2.0;
            }

            pt2.x =
                pt1.x + cos(heading) * scale * fabs(itr->k) / curvature_max;
            pt2.y =
                pt1.y + sin(heading) * scale * fabs(itr->k) / curvature_max;

            kappa_list.points.push_back(pt1);
            kappa_list.points.push_back(pt2);
            kappa_set.markers.push_back(kappa_list);
        }
    }

    pub.publish(kappa_set);
}

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
    std::string image_dir = ros::package::getPath("state_sampling");
    std::string base_dir = image_dir;
    std::string image_file = "obstacles.png";
    image_dir.append("/" + image_file);
    cv::Mat img_src = cv::imread(image_dir, CV_8UC1);

    int rows = img_src.rows;
    int cols = img_src.cols;
    double resolution = 0.2;  // in meter
    hmpl::InternalGridMap in_gm;
    in_gm.initializeFromImage(img_src,
                              resolution,
                              grid_map::Position::Zero());
    in_gm.addObstacleLayerFromImage(img_src, 0.5);
    in_gm.updateDistanceLayer();

    // save the map data
    hmpl::CSVFile dis_map("distance_map.csv");  // throws exceptions!
    //
    std::cout << "save map data." << std::endl;
    dis_map << "dx"
            << "dy"
            << "cost" << hmpl::endrow;
    for (std::size_t i = 0; i < in_gm.maps.getSize()(0); i++) {
        for (std::size_t j = 0; j < in_gm.maps.getSize()(1); j++) {
            grid_map::Index index(i, j);
            dis_map << i << j << in_gm.getObstacleDistance(index)
                    << hmpl::endrow;
        }
    }

    bool display_flag = false;
    VoronoiDiagram voronoi(in_gm.maps, 5);
    hmpl::SpaceExplore holonomic(in_gm, display_flag, voronoi);
    in_gm.maps.setFrameId("/map");

    ROS_INFO("Created map with size %f x %f m (%i x %i cells).",
             in_gm.maps.getLength().x(), in_gm.maps.getLength().y(),
             in_gm.maps.getSize()(0), in_gm.maps.getSize()(1));
    // Create publishers and subscribers
    ros::Publisher path_publisher =
        nh.advertise<nav_msgs::Path>("modified_path", 1, true);
    ros::Publisher publisher =
        nh.advertise<nav_msgs::OccupancyGrid>("grid_map", 1, true);

    ros::Publisher curvature_pub =
        nh.advertise<visualization_msgs::MarkerArray>("curvature", 1, true);

    // publisher path set
    ros::Publisher path_set_pub =
        nh.advertise<visualization_msgs::MarkerArray>("path_set", 1, true);

    // callback function for start and goal
    ros::Subscriber start_sub = nh.subscribe("/initialpose", 1, startCb);
    ros::Subscriber
        end_sub = nh.subscribe("/move_base_simple/goal", 1, goalCb);

    // Publisher in a loop.
    ros::Rate rate(10.0);
    while (nh.ok()) {
        // Add data to grid map.
        ros::Time time = ros::Time::now();

        // publish the grid_map
        in_gm.maps.setTimestamp(time.toNSec());
        nav_msgs::OccupancyGrid message;
        grid_map::GridMapRosConverter::toOccupancyGrid(
            in_gm.maps, in_gm.obs, in_gm.FREE, in_gm.OCCUPY, message);

        // search through the environment to get a path

        holonomic.setLowerBoundary(1.1);
        holonomic.solve(in_gm, start_point, end_point);

        std::vector<hmpl::State> curve;
        for (auto const &point_itr : holonomic.getDensePath()) {
            hmpl::State state;
            state.x = point_itr.x;
            state.y = point_itr.y;
            state.s = 0;
            curve.push_back(state);
        }
        fillCurve(&curve);

        //
        // fix lookahead distance
        hmpl::State vehicle_state;
        vehicle_state.x = start_point.position.x;
        vehicle_state.y = start_point.position.y;
        vehicle_state.z = start_point.orientation;

        hmpl::State vehicle_goal;
        vehicle_goal.x = end_point.position.x;
        vehicle_goal.y = end_point.position.y;
        vehicle_goal.z = end_point.orientation;

        hmpl::StateSampling state_sampling(in_gm, vehicle_state,
                                           vehicle_goal);

        auto start = std::chrono::steady_clock::now();
        state_sampling.deepStateSampling(curve, vehicle_state,
                                         vehicle_goal);
        auto end = std::chrono::steady_clock::now();
        double elapsed_secondes =
            std::chrono::duration_cast<std::chrono::duration<double> >(
                end - start)
                .count();

        std::cout << "sampling time:" << elapsed_secondes << std::endl;

        //
        publishSinglePathSet(path_set_pub,
                             state_sampling.observeVariable());

        // publishFootPrint(path_set_pub,
        //    state_sampling.getCar().getCurrentCenters(state_sampling.getLocalGoal()));

        publishFinalPath(path_set_pub,
                         state_sampling.getSquentialPathSet(),
                         vehicle_state);
        // set a goal set
        // state sampling
        // get the second goal
        // get the
        publishCurvature(curvature_pub, curve, 2, 0.5);
        hmpl::CollisionChecker collision_checker(in_gm);
        collision_checker.collisionCheckingHelper(&curve);
        //state_sampling.improvedCollisionChecking(&curve);
        publishSpline(path_set_pub, curve);
        try {
            hmpl::CSVFile
                csv("final_trajectory.csv");  // throws exceptions!
            hmpl::CSVFile csv1("spline_trajectory.csv");
            // Hearer
            csv << "index"
                << "s"
                << "x"
                << "y"
                << "z"
                << "k" << hmpl::endrow;
            csv1 << "index"
                 << "s"
                 << "x"
                 << "y"
                 << "z"
                 << "k" << hmpl::endrow;
            // Data
            std::size_t i = 0;
            for (auto &itr : state_sampling.getFinalPath()) {
                if (itr.z < 0) {
                    itr.z += 2 * M_PI;
                }
                csv << i << itr.s << itr.x << itr.y << itr.z << itr.k
                    << hmpl::endrow;
                i++;
            }
            i = 0;
            for (auto &spline_itr : curve) {
                if (spline_itr.z < 0) {
                    spline_itr.z += 2 * M_PI;
                }
                csv1 << i << spline_itr.s << spline_itr.x << spline_itr.y
                     << spline_itr.z << spline_itr.k << hmpl::endrow;
                i++;
            }
        } catch (const std::exception &ex) {
            std::cout << "Exception was thrown: " << ex.what() << std::endl;
        }

        // path_publisher.publish(path_msg);
        publisher.publish(message);
        ROS_INFO_THROTTLE(1.0, "Grid map (timestamp %f) published.",
                          message.header.stamp.toSec());
        // Wait for next cycle.
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}