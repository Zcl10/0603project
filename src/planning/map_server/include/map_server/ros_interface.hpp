//
// Created by yangt on 19-1-5.
//

#ifndef MAP_SERVER_ROS_INTERFACE_HPP
#define MAP_SERVER_ROS_INTERFACE_HPP
#include <opencv2/highgui/highgui.hpp>
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <grid_map_ros/grid_map_ros.hpp>
#include <nav_msgs/OccupancyGrid.h>
#include <std_msgs/UInt8.h>
#include <tf/transform_broadcaster.h>
#include <opt_utils/opt_utils.hpp>
#include <sensor_driver_msgs/GpswithHeading.h>
#include <sensor_driver_msgs/OdometrywithGps.h>
#include <visualization_msgs/Marker.h>
#include <internal_grid_map/internal_grid_map.hpp>
#include <lanelet_map_msgs/Way.h>
#include <plan2control_msgs/Trajectory.h>
#include <transform_tools/transform_interface.hpp>
#include <iv_slam_ros_msgs/TraversableArea.h>
#include <anm_msgs/VehicleState.h>
#include <tf2/convert.h>
#include <tf2_sensor_msgs/tf2_sensor_msgs.h>
#include <tf2/utils.h>
#include <tf2_ros/transform_listener.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/subscriber.h>

/**
 * @brief This is a struct including all variables that need to read from
 * config file
 */
struct ConfigVariable {
    /// simulation flag
    bool is_simulation;
    /// offset of the rear axle center
    double base_shift;
    /// topic name of map, using for normal travel
    std::string normal_map_topic;
    /// topic name of map, using for back-up
    std::string back_up_map_topic;
    /// topic name of map, using for smoke area
    std::string smoke_area_map_topic;
    /// topic name of laser odometry
    std::string odom_pose_topic;
    /// topic name of fuse position
    std::string vehicle_fuse_pose_topic;
    /// topic name of global roadnet
    std::string road_net_topic;
    /// topic name of final ETH grid map
    std::string publish_map_topic;
    /// map frame id
    std::string frame_id;
    /// wether generate map in ego frame
    bool use_local_frame;
    // wehter use roadnet to limit drivable area
    bool use_roadnet_limit_fessible_area;
};

/**
 * @brief this is a struct of flag for global logic judgement
 */
struct FlagVariable {
    /// whether receive map message
    FlagVariable() {
        rcv_map = false;
        rcv_final_map = false;
        rcv_fuse_pose = false;
        rcv_odom_pose = false;
        is_on_lawn_area = false;
        is_multi_map_valid = false;
        is_finding_moving_target = false;
        is_first_rcv_pose = true;
    }
    bool rcv_final_map;
    bool rcv_map;
    /// wether receive odometry pose message
    bool rcv_odom_pose;
    /// wether receive fuse pose message
    bool rcv_fuse_pose;
    /// wwther on lawn area
    bool is_on_lawn_area;
    /// is first receive vehicle pose
    bool is_first_rcv_pose;
    /// multi frame map valid?
    bool is_multi_map_valid;
    bool is_finding_moving_target;
};

struct Time {
    ros::Time map_update_time;
};

enum TaskType {
    NORMAL_TRAVEL = 0,
    BACKUP = 1,
    SMOKE_AREA = 2,
    WATER_AREA = 3,
    LAWN_AREA = 4,
    SEARCH_AREA = 5
};

typedef iv_slam_ros_msgs::TraversableArea IvGridMap;
typedef std::vector<geometry_msgs::Point> PointSet;
typedef lanelet_map_msgs::Way Way;

class RosSubscriber {
 public:
    RosSubscriber(const ConfigVariable &config, ros::NodeHandle *nh);

    bool IsStateUpdate();

    void ResetFlag();

    void CheckLawnAreaCount() {
        on_lawn_area_count_++;
    }

    const hmpl::State &vehicleState() const {
        return vehicle_state_;
    }

    const cartographer::transform::Rigid3d &vehicleInFusionFrame() const {
        return this->vehicle_in_fuse_;
    }

    const cartographer::transform::Rigid3d &vehicleInOdomFrame() const {
        return this->vehicle_in_odom_;
    }

    const cartographer::transform::Rigid3d &planningOrigin() const {
        return this->planning_frame_origin_;
    }

    const Way &GlobalWay() const {
        return global_way_;
    }

    const TaskType &Task() const {
        return current_task_;
    }

    const IvGridMap &IVRCGridMap() const {
        return TraversibleArea_;
    }

    const sensor_msgs::PointCloud2 &SimulationPointCloud() const {
        return simulation_point_cloud_;
    }

    const tf2_ros::Buffer &TfBuffer() const {
        return tf_buffer_;
    }

    const FlagVariable &Flag() const {
        return flag_;
    }

    int EmptyPathCount() const {
        return empty_traj_count_;
    }

 private:
    /// coresponding configuration variable
    const ConfigVariable &cfg_;
    FlagVariable flag_;
    Time time_observe_;
    /// ros related
    ros::NodeHandle *nh_;
    /// ros subscriber of delphi map
    ros::Subscriber delphiMap_sub_;
    /// ros subscriber of multi-frame map
    ros::Subscriber multiFrameMap_sub_;
    /// ros subscriber of single-frame map
    ros::Subscriber singleFrameMap_sub_;
    /// ros subscriber of moving target map
    ros::Subscriber moving_target_map_sub_;
    // /// ros subscriber of odometry pose
     ros::Subscriber vehicle_odom_pose_sub_;
    // /// ros subscriber of fuse pose
     ros::Subscriber vehicle_state_sub_;

   /// ros subscriber of odometry pose
//   message_filters::Subscriber<sensor_driver_msgs::OdometrywithGps>
//           vehicle_odom_pose_sub_;
//   /// ros subscriber of fuse pose
//   message_filters::Subscriber<sensor_driver_msgs::GpswithHeading>
//           vehicle_state_sub_;
//   message_filters::TimeSynchronizer<sensor_driver_msgs::OdometrywithGps,
//                                     sensor_driver_msgs::GpswithHeading>
//           pose_sync_;
    /// ros subscriber of global roadnet
    ros::Subscriber roadnet_sub_;
    /// ros subscriber of planning result
    ros::Subscriber planning_path_sub_;
    /// ros subscriber of pointcloud in simulation
    ros::Subscriber simulation_point_cloud_sub_;
    /// ros subscriber of vehicle state in simulation
    ros::Subscriber simulation_vehicle_state_sub_;

    /// set the first point as origin
    cartographer::transform::Rigid3d planning_frame_origin_;
    /// vehicle pose in fusion frame
    cartographer::transform::Rigid3d vehicle_in_fuse_;
    /// vehicle pose in odometry frame
    cartographer::transform::Rigid3d vehicle_in_odom_;
    /// vehicle statte in fusion frame
    hmpl::State vehicle_state_;
    /// RCIV grid map comes from perception module
    IvGridMap TraversibleArea_;
    /// global roadnet
    lanelet_map_msgs::Way global_way_;
    /// current task type
    TaskType current_task_;
    /// empty trajectory counter , comes from planning module
    int empty_traj_count_;
    /// cout how long the car has been on lawn area
    int on_lawn_area_count_;
    /// simulation point cloud
    sensor_msgs::PointCloud2 simulation_point_cloud_;
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;

    /**
     * callback function, subscribe multi-frame RCIV map result
     * @param map_msg
     */
    void multiFrameLidarMapCb(const IvGridMap &map_msg);

    /**
     * callback function, subscribe single-frame RCIV map result
     * @param map_msg
     */
    void sigleFrameLidarMapCb(const IvGridMap &map_msg);

    /**
     * callback function, subscribe delphi radar map result
     * @param map_msg
     */
    void delphiMapCb(const IvGridMap &map_msg);

    void movingTargetMapCb(const IvGridMap &map_msg);

    /**
     * callback function, subscribe vehicle pose in origin laser slam Odometry
     * frame. this result has higher real-time performance than previous one
     * @param pose_msg
     */
    void vehicleOriginOdomCb(
        const sensor_driver_msgs::OdometrywithGps &pose_msg);

    /**
     * callback function, subscribe the fusion position result
     * @param pose_msg
     */
    void vehicleFusePoseCb(const sensor_driver_msgs::GpswithHeading &pose_msg);

    void vehicleSyncPoseCb(const sensor_driver_msgs::OdometrywithGpsConstPtr &odom,
                           const sensor_driver_msgs::GpswithHeadingConstPtr &fuse);


    /**
     * callback function, subscribe the global roadnet
     * @param road
     */
    void roadnetCb(const lanelet_map_msgs::Way &road);

    /**
     * callback function, subscribe the panning result
     * @param traj
     */
    void planningPathCb(const plan2control_msgs::Trajectory &traj);

    /**
     * callback function, subscribe the point cloud in simulation
     * @param point_cloud
     */
    void SimulationPointCloudCb(
        const sensor_msgs::PointCloud2ConstPtr &point_cloud);

    /**
     * callback function, subscribe the vehicle state in simulation
     * @param state
     */
    void SimulationVehicleStateCb(const anm_msgs::VehicleState &state);
};

extern double Distance(double x1, double y1, double x2, double y2);

#endif //MAP_SERVER_ROS_INTERFACE_HPP
