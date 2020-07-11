//
// Created by yangt on 19-1-5.
//

#include "map_server/ros_interface.hpp"

RosSubscriber::RosSubscriber(const ConfigVariable &config,
                             ros::NodeHandle *nh)
    : cfg_(config),
      flag_(),
      nh_(nh),
      on_lawn_area_count_(0),
      empty_traj_count_(0),
      current_task_(NORMAL_TRAVEL),
      tf_buffer_(),
      tf_listener_(tf_buffer_) {
    if (cfg_.is_simulation) {
        simulation_point_cloud_sub_ = nh_->subscribe("/ros_lidar", 1, &RosSubscriber::SimulationPointCloudCb, this);
        simulation_vehicle_state_sub_ =
            nh->subscribe("/vehicle_state", 1, &RosSubscriber::SimulationVehicleStateCb, this);
    } else {
        multiFrameMap_sub_ = nh_->subscribe(cfg_.normal_map_topic, 1, &RosSubscriber::multiFrameLidarMapCb, this);
        singleFrameMap_sub_ = nh_->subscribe(cfg_.back_up_map_topic, 1, &RosSubscriber::sigleFrameLidarMapCb, this);
        delphiMap_sub_ = nh_->subscribe(cfg_.smoke_area_map_topic, 1, &RosSubscriber::delphiMapCb, this);
        moving_target_map_sub_ = nh_->subscribe("/MovingTargetMap", 1, &RosSubscriber::movingTargetMapCb, this);
        vehicle_odom_pose_sub_ = nh_->subscribe(cfg_.odom_pose_topic, 1, &RosSubscriber::vehicleOriginOdomCb, this);
        vehicle_state_sub_ = nh_->subscribe(cfg_.vehicle_fuse_pose_topic, 1, &RosSubscriber::vehicleFusePoseCb, this);

//        vehicle_odom_pose_sub_.subscribe(*nh_, cfg_.odom_pose_topic, 1);
//        vehicle_state_sub_.subscribe(*nh_, cfg_.vehicle_fuse_pose_topic, 1);
//        this->pose_sync_.registerCallback(&RosSubscriber::vehicleSyncPoseCb, this);

        roadnet_sub_ = nh_->subscribe(cfg_.road_net_topic, 1, &RosSubscriber::roadnetCb, this);
        planning_path_sub_ = nh_->subscribe("/global_path/traj_plan", 1, &RosSubscriber::planningPathCb, this);
    }
}

void RosSubscriber::multiFrameLidarMapCb(const IvGridMap &map_msg) {
    flag_.rcv_final_map = true;
    flag_.is_multi_map_valid = map_msg.valid;
    if (current_task_ != SMOKE_AREA && current_task_ != BACKUP && flag_.is_multi_map_valid
        && !flag_.is_finding_moving_target) {
        this->TraversibleArea_ = map_msg;
        this->TraversibleArea_.header.stamp = ros::Time::now();
        cartographer::transform::TransformTools tft;
        tft.geographic_to_utm(map_msg.triD_submap_pose.position.x,
                              map_msg.triD_submap_pose.position.y,
                              &(TraversibleArea_.triD_submap_pose.position.x),
                              &(TraversibleArea_.triD_submap_pose.position.y));
        flag_.rcv_map = true;
    }
}

void RosSubscriber::sigleFrameLidarMapCb(
    const IvGridMap &map_msg) {
    if (this->current_task_ == BACKUP || !(flag_.is_multi_map_valid) && !flag_.is_finding_moving_target) {
        this->TraversibleArea_ = map_msg;
        this->TraversibleArea_.header.stamp = ros::Time::now();
        cartographer::transform::TransformTools tft;
        tft.geographic_to_utm(map_msg.triD_submap_pose.position.x,
                              map_msg.triD_submap_pose.position.y,
                              &(TraversibleArea_.triD_submap_pose.position.x),
                              &(TraversibleArea_.triD_submap_pose.position.y));
        flag_.rcv_map = true;
    }
}

void RosSubscriber::movingTargetMapCb(const IvGridMap &map_msg) {
    flag_.is_finding_moving_target = map_msg.valid;
    if (this->current_task_ != BACKUP && flag_.is_finding_moving_target) {
        this->TraversibleArea_ = map_msg;
        this->TraversibleArea_.header.stamp = ros::Time::now();
        cartographer::transform::TransformTools tft;
        tft.geographic_to_utm(map_msg.triD_submap_pose.position.x,
                              map_msg.triD_submap_pose.position.y,
                              &(TraversibleArea_.triD_submap_pose.position.x),
                              &(TraversibleArea_.triD_submap_pose.position.y));
        flag_.rcv_map = true;
    }
}

void RosSubscriber::delphiMapCb(const IvGridMap &map_msg) {
    if (this->current_task_ == SMOKE_AREA) {
        this->TraversibleArea_ = map_msg;
        this->TraversibleArea_.header.stamp = ros::Time::now();
        flag_.rcv_map = true;
    }
}

void RosSubscriber::vehicleOriginOdomCb(const sensor_driver_msgs::OdometrywithGps &pose_msg) {
    if (this->current_task_ != SMOKE_AREA) {
        using namespace cartographer::transform;
        double x, y;
        // gps to Decare
        cartographer::transform::TransformTools tft;
        tft.geographic_to_utm(pose_msg.gps.longitude,
                              pose_msg.gps.latitude,
                              &(x), &(y));
        Eigen::Vector3d t(x, y, pose_msg.gps.altitude);
        Eigen::Quaterniond q(pose_msg.odometry.pose.pose.orientation.w,
                             pose_msg.odometry.pose.pose.orientation.x,
                             pose_msg.odometry.pose.pose.orientation.y,
                             pose_msg.odometry.pose.pose.orientation.z);
        this->vehicle_in_odom_ = Rigid3d(t, q);
        flag_.rcv_odom_pose = true;
    }
}

void RosSubscriber::vehicleFusePoseCb(const sensor_driver_msgs::GpswithHeading &pose_msg) {
    using namespace cartographer::transform;
    double yaw = pose_msg.heading * M_PI / 180.0 + M_PI_2;
    if (yaw > M_PI) {
        yaw = yaw - 2 * M_PI;
    }
    cartographer::transform::TransformTools tft;
    tft.geographic_to_utm(pose_msg.gps.longitude,
                          pose_msg.gps.latitude,
                          &(vehicle_state_.x),
                          &(vehicle_state_.y));
    vehicle_state_.z = yaw;
    Eigen::Vector3d t(vehicle_state_.x, vehicle_state_.y, pose_msg.gps.altitude);
    if (flag_.is_first_rcv_pose) {
        planning_frame_origin_ = Rigid3d(t, Eigen::Quaterniond(1.0, 0.0, 0.0, 0.0));
        flag_.is_first_rcv_pose = false;
    }
    auto q = RollPitchYaw(pose_msg.roll * M_PI / 180.0,
                          pose_msg.pitch * M_PI / 180.0,
                          pose_msg.heading * M_PI / 180.0);
    vehicle_in_fuse_ = Rigid3d(t, q);
    flag_.rcv_fuse_pose = true;
}

void RosSubscriber::vehicleSyncPoseCb(const sensor_driver_msgs::OdometrywithGpsConstPtr &odom,
                                      const sensor_driver_msgs::GpswithHeadingConstPtr &fuse) {
    using namespace cartographer::transform;
    cartographer::transform::TransformTools tft;
    /// fill vehicle pose in odometry frame
    double x, y;
    // gps to Decare
    tft.geographic_to_utm(odom->gps.longitude,
                          odom->gps.latitude,
                          &(x), &(y));
    Eigen::Vector3d odom_t(x, y, odom->gps.altitude);
    Eigen::Quaterniond odom_q(odom->odometry.pose.pose.orientation.w,
                              odom->odometry.pose.pose.orientation.x,
                              odom->odometry.pose.pose.orientation.y,
                              odom->odometry.pose.pose.orientation.z);
    this->vehicle_in_odom_ = Rigid3d(odom_t, odom_q);

    /// fill vehicle pose in fusion frame
    double yaw = fuse->heading * M_PI / 180.0 + M_PI_2;
    if (yaw > M_PI) {
        yaw = yaw - 2 * M_PI;
    }
    tft.geographic_to_utm(fuse->gps.longitude,
                          fuse->gps.latitude,
                          &(vehicle_state_.x),
                          &(vehicle_state_.y));
    vehicle_state_.z = yaw;
    Eigen::Vector3d
        fuse_t(vehicle_state_.x, vehicle_state_.y, fuse->gps.altitude);
    if (flag_.is_first_rcv_pose) {
        planning_frame_origin_ =
            Rigid3d(fuse_t, Eigen::Quaterniond(1.0, 0.0, 0.0, 0.0));
        flag_.is_first_rcv_pose = false;
    }
    auto fuse_q = RollPitchYaw(fuse->roll * M_PI / 180.0,
                               fuse->pitch * M_PI / 180.0,
                               fuse->heading * M_PI / 180.0);
    this->vehicle_in_fuse_ = Rigid3d(fuse_t, fuse_q);

    flag_.rcv_fuse_pose = true;
    flag_.rcv_odom_pose = true;
}

void RosSubscriber::roadnetCb(const lanelet_map_msgs::Way &road) {
    this->global_way_ = road;
    if (!global_way_.is_forward) {
        this->current_task_ = BACKUP;
    } else if (global_way_.foggy_area) {
        this->current_task_ = SMOKE_AREA;
    } else if (global_way_.lawn_area) {
        this->current_task_ = LAWN_AREA;
    } else if (global_way_.task_area == "hidden_area") {
        this->current_task_ = SEARCH_AREA;
    } else {
        this->current_task_ = NORMAL_TRAVEL;
    }
}
void RosSubscriber::planningPathCb(const plan2control_msgs::Trajectory &traj) {
    if (traj.points.empty()) {
        empty_traj_count_++;
    } else {
        double dx = traj.points.back().position.x - traj.points.front().position.x;
        double dy = traj.points.back().position.y - traj.points.front().position.y;
        double dist = sqrt(dx * dx + dy * dy);
        if (dist < 10.0) {
            empty_traj_count_++;
        } else {
            empty_traj_count_ = 0;
            if (flag_.is_on_lawn_area && on_lawn_area_count_ > 150) {
                flag_.is_on_lawn_area = false;
                this->on_lawn_area_count_ = 0;
            }
        }
    }
    if (empty_traj_count_ > 3) {
        flag_.is_on_lawn_area = true;
    }
}

void RosSubscriber::SimulationPointCloudCb(
    const sensor_msgs::PointCloud2ConstPtr &point_cloud) {
    simulation_point_cloud_ = *point_cloud;
    flag_.rcv_map = true;
}

void RosSubscriber::SimulationVehicleStateCb(
    const anm_msgs::VehicleState &state) {
    using namespace cartographer::transform;
    vehicle_state_.x = state.position.x;
    vehicle_state_.y = state.position.y;
    vehicle_state_.z = state.orientation.z;
    vehicle_state_.v = state.velocity.linear.x;
    if (flag_.is_first_rcv_pose) {
        planning_frame_origin_ =
            Rigid3d(Eigen::Vector3d(vehicle_state_.x, vehicle_state_.y, 0.0),
                    Eigen::Quaterniond(1.0, 0.0, 0.0, 0.0));
        flag_.is_first_rcv_pose = false;
    }
    flag_.rcv_fuse_pose = true;
}

bool RosSubscriber::IsStateUpdate() {
    if (cfg_.is_simulation) {
        return (flag_.rcv_map & flag_.rcv_fuse_pose);
    } else {
        if (flag_.rcv_map || flag_.rcv_final_map) {
            time_observe_.map_update_time = ros::Time::now();
            return (flag_.rcv_odom_pose & flag_.rcv_fuse_pose);
        } else {
            auto t = ros::Time::now();
            auto time_interval = fabs(t.toSec() - time_observe_.map_update_time.toSec());
            if (time_interval > 2.0) {
                ROS_WARN("waiting for map updating...");
                return false;
            } else {
                return (flag_.rcv_odom_pose & flag_.rcv_fuse_pose);
            }
        }
    }
}

void RosSubscriber::ResetFlag() {
    flag_.rcv_odom_pose = false;
    flag_.rcv_fuse_pose = false;
    flag_.rcv_map = false;
    flag_.rcv_final_map = false;
}

double Distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}