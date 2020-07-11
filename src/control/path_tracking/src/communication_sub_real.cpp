//
// Created by yao on 20-7-1.
//

#include "lateral_control_core.h"

void LateralControlCore::callbackEcuDataReport(const control_msgs::Report &msg) {
    ecu_report = msg;
    ecu_.is_update = true;
    ecu_.last_timestamp = ros::WallTime::now().toSec();
}

void LateralControlCore::callbackFromWayPoints(const plan2control_msgs::TrajectoryPtr &p_msg) {
    if ("base_link" == p_msg->header.frame_id || "search_base_link" == p_msg->header.frame_id) {
        p_trajectory = p_msg;
        path_.is_update = true;
        path_.last_timestamp = ros::WallTime::now().toSec();
        rviz_frame = p_msg->header.frame_id;
    } else {
        ROS_WARN_STREAM("The path must be published in the base_link or search_base_link frame! Ignoring path in "
                            << p_msg->header.frame_id.c_str() << " frame!");
    }
}

void LateralControlCore::callbackVehiclePose(const sensor_driver_msgs::GpswithHeading &msg) {
    // change gps to meter-unit.
    ToolKit::positionGPStoMeters(msg.gps.longitude,
                                 msg.gps.latitude,
                                 vehicle_state.position.x,
                                 vehicle_state.position.y);
    vehicle_state.position.z = msg.gps.altitude;
    // heading unit: from deg to rad
    vehicle_state.orientation.x = (msg.roll + 90) * M_PI / 180.0;
    vehicle_state.orientation.y = (msg.pitch + 90) * M_PI / 180.0;
    vehicle_state.orientation.z = (msg.heading + 90) * M_PI / 180.0;
    ToolKit::normalizeAngle(vehicle_state.orientation.z);
    pose_.is_update = true;
    pose_.last_timestamp = ros::WallTime::now().toSec();
}

void LateralControlCore::callbaskInsVelocity(const sensor_driver_msgs::InsVelocity &msg) {
    vehicle_state.velocity.linear.x = msg.linear_velocity.y;
    vehicle_state.velocity.linear.y = -msg.linear_velocity.x;
    vehicle_state.velocity.linear.z = -msg.linear_velocity.z;
    vehicle_state.velocity.angular.z = msg.angular_velocity.z;
    ins_.is_update = true;
    ins_.last_timestamp = ros::WallTime::now().toSec();
}

void LateralControlCore::callbackImuData(const sensor_msgs::Imu &msg) {
    vehicle_state.acceleration.linear.x = msg.linear_acceleration.y;
    vehicle_state.acceleration.linear.y = -msg.linear_acceleration.x;
    vehicle_state.acceleration.linear.z = -msg.linear_acceleration.z;
    imu_.is_update = true;
    imu_.last_timestamp = ros::WallTime::now().toSec();
}