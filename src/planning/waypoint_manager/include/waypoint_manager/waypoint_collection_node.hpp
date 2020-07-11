//
// Created by yangt on 7/7/18.
//
#include "waypoint_manager/ros_interface.hpp"
#include <fstream>
#ifndef WAYPOINT_MANAGER_WAYPOINT_COLLECTION_NODE_HPP
#define WAYPOINT_MANAGER_WAYPOINT_COLLECTION_NODE_HPP
class WayPointCollection {
 private:
    RosSubscriber sub_;
    /// state variable
    const Configuration &cfg_;
    int count_;
    VehicleState old_pose_;

    /// ros related:
    ros::NodeHandle *nh_;
    ros::Timer timer_;
 public:
    WayPointCollection(const Configuration& cfg, ros::NodeHandle *nh);
 private:
    void TimerCb();
};
#endif //WAYPOINT_MANAGER_WAYPOINT_COLLECTION_NODE_HPP
