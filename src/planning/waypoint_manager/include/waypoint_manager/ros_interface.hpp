//
// Created by yangt on 19-1-5.
//

#ifndef WAYPOINT_MANAGER_ROS_INTERFACE_HPP
#define WAYPOINT_MANAGER_ROS_INTERFACE_HPP

#include <ros/ros.h>
#include <ros/package.h>
#include <anm_msgs/VehicleState.h>
#include <lanelet_map_msgs/Way.h>
#include "sensor_driver_msgs/GpswithHeading.h"
#include "transform_tools/transform_interface.hpp"

struct Configuration {
    std::string vehicle_pose_topic;
    std::string file_name;
    bool wait_vehicle_pos;
    std::string interpolate_type;
    std::string package_dir;
    bool use_gps_point;
    bool is_simulation;
    bool is_multi_circle_mode;
    double save_period;
    double interval;
};

typedef sensor_driver_msgs::GpswithHeading GpswithHeading;
typedef anm_msgs::VehicleState VehicleState;
typedef lanelet_map_msgs::Way Way;
typedef lanelet_map_msgs::Node Node;

class RosSubscriber {
 public:
    explicit RosSubscriber(const Configuration &config, ros::NodeHandle *nh);
    bool IsStateUpdate() const;
    const VehicleState& GetVehiclePose() const;
    const sensor_msgs::NavSatFix & GetVehicleGps() const;
    void ResetFlag();
 private:
    const Configuration &cfg_;
    ros::NodeHandle *nh_;
    ros::Subscriber vehicle_pose_sub_;

    VehicleState vehicle_state_;
    sensor_msgs::NavSatFix vehicle_gps_;

    bool is_rcv_pose_;

    void VehiclePoseCb(const GpswithHeading &gps);
    void VehiclePoseSimulationCb(const VehicleState &state);
};

class RosPublisher {
 public:
    explicit RosPublisher(const Configuration &config, ros::NodeHandle *nh);
    void PublishWay(const Way &way);
 private:
    const Configuration &cfg_;
    ros::NodeHandle *nh_;
    ros::Publisher global_path_pub_;
    ros::Publisher global_way_pub_;
};

extern double Distance(double x1, double y1, double x2, double y2);
extern double Distance(const VehicleState &pose1, const VehicleState &pose2);
extern double Distance(const Node &node1, const Node &node2);
extern double Distance(const Node &node1, const VehicleState &node2);

#endif //WAYPOINT_MANAGER_ROS_INTERFACE_HPP
