/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC),
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: space_explore_visual_tools.cpp
 *   Created on: 11, 23, 2018
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include <space_explore/space_explore_visual_tools.hpp>

namespace hmpl {

SpaceExploreVisualTools::SpaceExploreVisualTools(const ros::NodeHandle &nh,
                                                 const ros::NodeHandle &private_nh)
    :VisualTools(nh, private_nh),
     reconfigSrv_(private_nh),
     param_(private_nh) {
    this->param_.fromParamServer();
    reconfigSrv_.setCallback(boost::bind(&SpaceExploreVisualTools::reconfigureRequest, this, _1, _2));
}
void SpaceExploreVisualTools::publishDisk(const Circle &node) {
    visualization_msgs::Marker disk = createDisk(node.r, "node", GREEN, "/map");
    disk.color.a = 0.1;
    disk.scale.z = 0.001;
    disk.pose.position.x = node.position.x;
    disk.pose.position.y = node.position.y;
    i++;
    disk.id = i;
    pushMarker(disk);
}

void SpaceExploreVisualTools::publishCircle(const Circle &node) {
    Eigen::Vector3d center(node.position.x, node.position.y, 0.05);
    visualization_msgs::Marker circle = createCircle(
            center,
            node.r,
            param_.circle_marker_size,
            param_.circle_marker_name,
            getColor(param_.circle_marker_color),
            param_.circle_marker_frame);
    circle.color.a = static_cast<float>(param_.circle_marker_alpha);
    i++;
    circle.id = i;
    pushMarker(circle);
}

void SpaceExploreVisualTools::publishChildNodes(const Circle &node) {
    Eigen::Vector3d center(node.position.x, node.position.y, 0.05);

}


void SpaceExploreVisualTools::publishStart(const Circle &start) {
    visualization_msgs::Marker cube = createCube(
            param_.start_marker_size,
            param_.start_marker_name,
            getColor(param_.start_marker_color),
            param_.start_marker_frame);
    cube.color.a = static_cast<float>(param_.start_marker_alpha);
    cube.pose.position.x = start.position.x;
    cube.pose.position.y = start.position.y;
    pushMarker(cube);
}

void SpaceExploreVisualTools::publishGoal(const Circle &goal) {
    visualization_msgs::Marker cube = createCube(
            param_.goal_marker_size,
            param_.goal_marker_name,
            getColor(param_.goal_marker_color),
            param_.goal_marker_frame);
    cube.color.a = static_cast<float>(param_.goal_marker_alpha);
    cube.pose.position.x = goal.position.x;
    cube.pose.position.y = goal.position.y;
    pushMarker(cube);
}

void SpaceExploreVisualTools::publishPath(const CircleNodePtrArray &circle_path) {
    visualization_msgs::Marker path = createLineStrip(
            param_.inter_path_width,
            param_.inter_path_name,
            getColor(param_.inter_path_marker_color),
            param_.inter_path_marker_frame);
    visualization_msgs::Marker spheres = createSpheres(
            param_.path_node_size,
            param_.path_node_name,
            getColor(param_.path_node_color),
            param_.path_node_frame);
    path.color.a = static_cast<float>(param_.inter_path_marker_alpha);
    spheres.color.a =static_cast<float>(param_.path_node_alpha);
    geometry_msgs::Point pt;
    i++;
    path.id = i;
    spheres.id = i;
    for (const auto &itr: circle_path.circles) {
        pt.x = itr->circle.position.x;
        pt.y = itr->circle.position.y;
        pt.z = 0.1;
        spheres.points.push_back(pt);
        path.points.push_back(pt);
    }
    pushMarker(spheres);
    pushMarker(path);

}

void SpaceExploreVisualTools::publishCirclePath(const CircleNodePtrArray &circle_path) {
    visualization_msgs::Marker path = createLineStrip(
            param_.circle_path_width,
            param_.circle_path_name,
            getColor(param_.circle_path_color),
            param_.circle_path_frame);
    visualization_msgs::Marker spheres = createSpheres(
            param_.circle_path_node_size,
            param_.circle_path_node_name,
            getColor(param_.circle_path_node_color),
            param_.circle_path_node_frame);
    path.color.a = static_cast<float>(param_.circle_path_alpha);
    spheres.color.a =static_cast<float>(param_.circle_path_node_alpha);
    geometry_msgs::Point pt;
    i++;
    path.id = i;
    spheres.id = i;
    for (const auto &itr: circle_path.circles) {
        pt.x = itr->circle.position.x;
        pt.y = itr->circle.position.y;
        pt.z = 0.1;
        spheres.points.push_back(pt);
        path.points.push_back(pt);
    }
    pushMarker(spheres);
    pushMarker(path);
}


void SpaceExploreVisualTools::publishFinalPath(const std::vector<Vector2D<double>> &dense_path) {
    visualization_msgs::Marker path = createLineStrip(
            param_.final_path_width,
            param_.final_path_name,
            getColor(param_.final_path_color),
            param_.final_path_frame);
    path.color.a = static_cast<float>(param_.final_path_alpha);
    geometry_msgs::Point pt;
    i++;
    path.id = i;
    for (const auto &itr: dense_path) {
        pt.x = itr.x;
        pt.y = itr.y;
        pt.z = 0.15;
        path.points.push_back(pt);
    }
    pushMarker(path);
}

std_msgs::ColorRGBA SpaceExploreVisualTools::getColor(int color) {
    std_msgs::ColorRGBA temp_color;
    switch(color) {
        using space_explore::VisualParameters;
        case VisualParameters::shared_colors_BLACK:
            temp_color = BLACK;
            break;
        case VisualParameters::shared_colors_BLUE:
            temp_color = BLUE;
            break;
        case VisualParameters::shared_colors_DARK_CYAN:
            temp_color = DARK_CYAN;
            break;
        case VisualParameters::shared_colors_CYAN:
            temp_color = CYAN;
            break;
        case VisualParameters::shared_colors_GREEN:
            temp_color = GREEN;
            break;
        case VisualParameters::shared_colors_GREY:
            temp_color = GREY;
            break;
        case VisualParameters::shared_colors_LIGHT_GREEN:
            temp_color = LIGHT_GREEN;
            break;
        case VisualParameters::shared_colors_PINK:
            temp_color = PINK;
            break;
        case VisualParameters::shared_colors_RED:
            temp_color = RED;
            break;
        case VisualParameters::shared_colors_SKY_BLUE:
            temp_color = SKY_BLUE;
            break;
        case VisualParameters::shared_colors_WHITE:
            temp_color = WHITE;
            break;
        default:
            temp_color = BLACK;
            break;
    }
    return temp_color;
}

void SpaceExploreVisualTools::reconfigureRequest(space_explore::VisualConfig &config,
                                         uint32_t) {
    param_.fromConfig(config);
}

}
