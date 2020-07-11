//
// Created by yangt on 7/7/18.
//

#ifndef WAYPOINT_MANAGER_ROUTE_PUBLISHER_NODE_HPP
#define WAYPOINT_MANAGER_ROUTE_PUBLISHER_NODE_HPP

#include "ros_interface.hpp"
class RoutePublisher {
 public:
    RoutePublisher(const Configuration &config, ros::NodeHandle *nh);

 private:
    bool readWaypointFromFile(lanelet_map_msgs::Way *raw_points);
    void InterpolationBspline(const lanelet_map_msgs::Way &raw_points);
    void linearInterpolation(const lanelet_map_msgs::Way &origin_way,
                        lanelet_map_msgs::Way *result);
    /// callback function:
    void TimerCb();
 private:
    /// ros related
    ros::NodeHandle *nh_;
    const Configuration &cfg_;
    RosPublisher pub_;
    RosSubscriber sub_;
    ros::Timer timer_;

    /// state variable
    lanelet_map_msgs::Way waypoint_;

    /// bool variable
    int nearest_id_;
};
#endif //WAYPOINT_MANAGER_ROUTE_PUBLISHER_NODE_HPP
