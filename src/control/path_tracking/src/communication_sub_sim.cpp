//
// Created by yao on 20-7-1.
//

#include "lateral_control_core.h"

void LateralControlCore::callbackFromWayPointsSim(const nav_msgs::Path &msg) {
    if ("base_link" == msg.header.frame_id || "/odom" == msg.header.frame_id) {
        if (p_trajectory == nullptr)
            p_trajectory = boost::shared_ptr<plan2control_msgs::Trajectory>(new plan2control_msgs::Trajectory());
        p_trajectory->points.clear();
        plan2control_msgs::Traj_Node tmp;
        for (auto it : msg.poses) {
            tmp.position = it.pose.position;
            tmp.forward =
                1;  // TODO: deal with the situation combining path_forward and reverse processes in simulation.
            p_trajectory->points.emplace_back(tmp);
        }
        path_.is_update = true;
        path_.last_timestamp = ros::WallTime::now().toSec();
        rviz_frame = msg.header.frame_id;
    } else {
        ROS_WARN("The path must be published in the base_link frame! Ignoring path in %s frame!",
                 msg.header.frame_id.c_str());
    }
}

void LateralControlCore::callbackFromSteeringSim(const dbw_mkz_msgs::SteeringReport &msg) {
    double delta = msg.steering_wheel_angle / 16;
    vehicle_state.velocity.angular.z = tan(delta) * vehicle_state.velocity.linear.x / 2.86;
}

void LateralControlCore::callbackVehicleStateSim(const anm_msgs::VehicleState &msg) {
    vehicle_state = msg;
    //TODO: IMU_sim_data
    ecu_.is_update = true;
    ecu_.last_timestamp = ros::WallTime::now().toSec();
    pose_.is_update = true;
    pose_.last_timestamp = ros::WallTime::now().toSec();
    ins_.is_update = true;
    ins_.last_timestamp = ros::WallTime::now().toSec();
    imu_.is_update = true;
    imu_.last_timestamp = ros::WallTime::now().toSec();
}

void LateralControlCore::callbackFromPythonSimPath(const plan2control_msgs::TrajectoryPtr &p_msg) {
    if (p_msg->header.frame_id == "base_link") {
        p_trajectory = p_msg;
        path_.is_update = true;
        path_.last_timestamp = ros::WallTime::now().toSec();
        rviz_frame = p_msg->header.frame_id;
    } else {
        ROS_WARN("The path must be published in the base_link frame! Ignoring path in %s frame!",
                 p_msg->header.frame_id.c_str());
    }
}