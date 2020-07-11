//
// Created by yangt on 18-11-14.
//
#include "local_planner_node.hpp"

void LocalPlanner::SimulationVehicleStateCb(
    const anm_msgs::VehicleState &state) {
    vehicle_state_.x = state.position.x;
    vehicle_state_.y = state.position.y;
    vehicle_state_.v = state.velocity.linear.x;
    vehicle_state_.z = state.orientation.z;
    flag_.start_state_update = true;
}

void LocalPlanner::SimulationSteeringCb(
    const dbw_mkz_msgs::SteeringReport &steering) {
    this->vehicle_state_.k = tan(steering.steering_wheel_angle / 16) / 2.86;
}

void LocalPlanner::VehicleFusionPoseCb(const sensor_driver_msgs::GpswithHeading &pose) {
    double theta = pose.heading * M_PI / 180.0 + M_PI_2;
    if (theta > M_PI) {
        theta -= 2 * M_PI;
    }
    this->vehicle_state_.z = theta;
    cartographer::transform::TransformTools tft;
    tft.geographic_to_utm(pose.gps.longitude, pose.gps.latitude,
                          &(vehicle_state_.x),
                          &(vehicle_state_.y));
    flag_.start_state_update = true;
}

void LocalPlanner::GridMapCb(const grid_map_msgs::GridMap &map) {
    this->gridmap_msgs_ = map;
    flag_.map_update = true;
}

void LocalPlanner::WaypointCb(const lanelet_map_msgs::Way &way) {
    this->ref_waypoint_ = way;
}

void LocalPlanner::TaskPointCb(const lanelet_map_msgs::Way &way) {
    this->ref_waypoint_ = way;
}
void LocalPlanner::EcuDataCb(const control_msgs::Report &ecu) {
    this->vehicle_state_.v = ecu.motion.velocity;
    this->kappa_(tan(ecu.motion.steer / 17.7) / 2.73);
    this->vehicle_state_.k = tan(ecu.motion.steer / 17.7) / 2.73;
}

void LocalPlanner::PlanningOriginCb(const geometry_msgs::Point &origin) {
    this->planning_origin_ = origin;
    this->flag_.planning_origin_set = true;
}

void LocalPlanner::FinishSearchCb(const std_msgs::UInt8 &flag) {
    flag_.finish_search_task = flag.data;
}

void LocalPlanner::PublishPathMsg(const StatePath &path) {
    plan2control_msgs::Trajectory traj_msg;
    nav_msgs::Path path_msg;
    GetPathMsg(path, &traj_msg, &path_msg);
    traj_pub_.publish(traj_msg);
    rviz_path_pub_.publish(path_msg);

    std_msgs::UInt8 flag;
    flag.data = 0;
    this->normal_plan_end_pub_.publish(flag);
}

void LocalPlanner::GetPathMsg(const StatePath &best_path,
                              plan2control_msgs::Trajectory *trajectory_msg,
                              nav_msgs::Path *path_msg) {
    trajectory_msg->points.clear();
    path_msg->poses.clear();
    plan2control_msgs::Traj_Node traj_node;
    geometry_msgs::PoseStamped pose;
    path_msg->header.frame_id = this->in_gm_.maps.getFrameId();
    path_msg->header.stamp = ros::Time::now();
    trajectory_msg->header = path_msg->header;
    trajectory_msg->header.frame_id = "base_link";
    pose.header = path_msg->header;
    traj_node.forward = flag_.is_forward_search ? 1 : 0;
    if (!flag_.is_forward_search) {
        vehicle_state_planning_.z += M_PI;
        if (vehicle_state_planning_.z > M_PI) {
            vehicle_state_planning_.z -= M_PI * 2.0;
        }
    }
    int count = 0;
    for (const auto &point_itr : best_path) {
        // path for display
        pose.pose.position.x = point_itr.x;
        pose.pose.position.y = point_itr.y;
        tf::Quaternion q = tf::createQuaternionFromYaw(point_itr.z);
        pose.pose.orientation.x = q.x();
        pose.pose.orientation.y = q.y();
        pose.pose.orientation.z = q.z();
        pose.pose.orientation.w = q.w();
        path_msg->poses.push_back(pose);
        // path for control
        traj_node.id = count;
        hmpl::State local_state =
            hmpl::globalToLocal(vehicle_state_planning_, point_itr);
        traj_node.position.x = local_state.x;
        traj_node.position.y = local_state.y;
        traj_node.orientation = pose.pose.orientation;
        traj_node.curvature = point_itr.k;
        trajectory_msg->points.push_back(traj_node);
        count++;
    }
}

