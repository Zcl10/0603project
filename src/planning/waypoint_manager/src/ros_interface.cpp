//
// Created by yangt on 19-1-5.
//
#include "waypoint_manager/ros_interface.hpp"
#include <nav_msgs/Path.h>

RosSubscriber::RosSubscriber(const Configuration &config,
                             ros::NodeHandle *nh) :
        cfg_(config),
        nh_(nh),
        is_rcv_pose_(false){
    if(cfg_.is_simulation) {
        vehicle_pose_sub_ = nh_->subscribe("/vehicle_state", 1,
                                           &RosSubscriber::VehiclePoseSimulationCb,
                                           this);
    } else {
        vehicle_pose_sub_ = nh_->subscribe(cfg_.vehicle_pose_topic, 1,
                                           &RosSubscriber::VehiclePoseCb,
                                           this);
    }
}

bool RosSubscriber::IsStateUpdate() const {
    return is_rcv_pose_;
}

const VehicleState& RosSubscriber::GetVehiclePose() const {
    return vehicle_state_;
}

const sensor_msgs::NavSatFix& RosSubscriber::GetVehicleGps() const {
    return vehicle_gps_;
}
void RosSubscriber::ResetFlag() {
    this->is_rcv_pose_ = false;
}

void RosSubscriber::VehiclePoseSimulationCb(
        const anm_msgs::VehicleState &pose_msg) {
    vehicle_state_ = pose_msg;
    vehicle_gps_.longitude = vehicle_state_.position.x;
    vehicle_gps_.latitude = vehicle_state_.position.y;
    vehicle_gps_.altitude = vehicle_state_.position.z;
    this->is_rcv_pose_ = true;
}

void RosSubscriber::VehiclePoseCb(
        const sensor_driver_msgs::GpswithHeading &pose_msg) {
    this->vehicle_gps_ = pose_msg.gps;
    /// geograpic to utm
    cartographer::transform::TransformTools tft;
    tft.geographic_to_utm(pose_msg.gps.longitude,
                          pose_msg.gps.latitude,
                          &(vehicle_state_.position.x),
                          &(vehicle_state_.position.y));
    this->vehicle_state_.position.z = pose_msg.gps.altitude;
    double theta = pose_msg.heading + M_PI / 2.0;
    if(theta > M_PI) {
        theta = 2 * M_PI - theta;
    }
    this->vehicle_state_.orientation.z = theta;
    this->is_rcv_pose_ = true;
}

RosPublisher::RosPublisher(const Configuration &config, ros::NodeHandle *nh)
        : cfg_(config),
          nh_(nh) {
    if(cfg_.is_simulation) {
        global_way_pub_ = nh_->advertise<Way>("/global_way", 1);
        global_path_pub_ = nh_->advertise<nav_msgs::Path>("/global_path", 1);
    } else {
        global_way_pub_ = nh_->advertise<Way>("/global_way", 1);
    }

}

void RosPublisher::PublishWay(const Way &way) {
    if(cfg_.is_simulation) {
        nav_msgs::Path path;
        path.header.frame_id = "/odom";
        path.header.stamp = ros::Time::now();
        geometry_msgs::PoseStamped pose;
        pose.header = path.header;
        for(const auto & pt : way.points) {
            pose.pose.position = pt.point;
            path.poses.push_back(pose);
        }
        global_path_pub_.publish(path);
        global_way_pub_.publish(way);
    } else {
        global_way_pub_.publish(way);
    }
}

double Distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
}

double Distance(const VehicleState &pose1, const VehicleState &pose2) {
    return Distance(pose1.position.x, pose1.position.y,
                    pose2.position.x,pose2.position.y);
}

double Distance(const Node &node1, const Node &node2) {
    return Distance(node1.point.x, node1.point.y,
                    node2.point.x, node2.point.y);
}
double Distance(const Node &node1, const VehicleState &node2) {
    return Distance(node1.point.x, node1.point.y,
                    node2.position.x, node2.position.y);
}