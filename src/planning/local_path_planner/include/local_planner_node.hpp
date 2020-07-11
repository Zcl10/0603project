//
// Created by yangt on 7/13/18.
//

#ifndef STATE_SAMPLING_GLOBAL_PATH_NODE_HPP
#define STATE_SAMPLING_GLOBAL_PATH_NODE_HPP

#pragma once
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <boost/accumulators/statistics/rolling_window.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/rolling_mean.hpp>

#include <ros/package.h>
#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <plan2control_msgs/Trajectory.h>
#include <sensor_driver_msgs/GpswithHeading.h>
#include <transform_tools/transform_interface.hpp>
#include <car_model/car_geometry.hpp>
#include <control_msgs/Report.h>
#include <std_msgs/UInt8.h>
#include <internal_grid_map/internal_grid_map.hpp>
#include <grid_map_ros/grid_map_ros.hpp>
#include <dbw_mkz_msgs/SteeringReport.h>

#include "path_planner_visual_tools.hpp"
#include "common_function.hpp"
#include "roadnet_handler.hpp"
#include "search_based_method.hpp"

namespace ba = boost::accumulators;
class LocalPlanner {
    /**
     * configuration struct contains parameters reading from config file
     */
    struct Configuration {
        std::string roadnet_topic;
        std::string vehicle_fuse_pose_topic;
        std::string frame_id;
        bool is_simulation;
        bool use_roadnet;
        bool use_state_sampling;
        bool pure_roadnet_mode;
        bool use_origin_task_point;
        double path_length;
        double remained_length;
        double offset_interval;
        double roadnet_max_offset;
    };

    /**
     * flag struct for logic control
     */
    struct Flag {
        bool finish_search_task;
        bool is_forward_search;
        bool map_update;
        bool start_state_update;
        bool planning_origin_set;
    };

    struct Time {
        ros::Time map_update_time;
        double waiting_map_interval=0.0;
    };

    /**
     * task type
     */
    enum TaskType {
        NORMAL_TRAVEL = 0,
        PATROL_TASK = 1,
        SEARCH_TASK = 2,
        SMOKE_AREA = 3,
        WATER_AREA = 4,
        LAWN_AREA = 5,
        PARKING_AREA = 6
    };

 public:
    /**
     * constructor function for parameters initialization
     */
    LocalPlanner();

    /**
     * the main loop of local planner
     */
    void Run();

 private:
    /**
     * initialize parameters
     */
    void InitParams();

    /**
     * check current task type in terms of roadnet attribution
     * @param way : road net
     * @return    : true:  local planning is required in current task
     *               false: local planning should abort in current task
     */
    bool CheckTaskArea(const lanelet_map_msgs::Way &way);

    /**
     * publish the result of local planner
     * @param path the result of locall planner
     */
    void PublishPathMsg(const StatePath &path);

    /**
     * a function path message type convertion
     * @param best_path : input type 'StatePath'
     * @param trajectory_msg : output type 'control_msgs::Trajectory'
     * @param path_msg  : output type 'nav_msgs::Path'
     */
    void GetPathMsg(const StatePath &best_path,
                    plan2control_msgs::Trajectory *trajectory_msg,
                    nav_msgs::Path *path_msg);

    /**
     * update ETH grid map
     */
    void UpdateGridMap();

    /**
     * the process of path sampling
     * @param result_path  :the result of sampling
     */
    void GenerateSamplingPath(StatePath *result_path);

    /**
     * abstruct a collision-free path from planned path in last period
     * @param last_stat : vehicle state in last period
     * @param current_state : current vehicle state
     * @param path : planned path in last period
     * @param aviliable_path : a segment of collision-free path
     */
    void interceptAviliablePath(const hmpl::State &current_state,
                                const StatePath &ref_path,
                                StatePath *aviliable_path,
                                std::string *message);

    /**
     * callback function for grid map
     * @param map
     */
    void GridMapCb(const grid_map_msgs::GridMap &map);

    /**
     * callback function for fusion position
     * @param pose
     */
    void VehicleFusionPoseCb(const sensor_driver_msgs::GpswithHeading &pose);

    /**
     * callback function for roadnet from package 'a_star_double_xml'
     * @param way
     */
    void WaypointCb(const lanelet_map_msgs::Way &way);

    /**
     * callback function for vehicle ECU date
     * @param ecu
     */
    void EcuDataCb(const control_msgs::Report &ecu);

    /**
     * callback function for the state of searching task
     * @param flag
     */
    void FinishSearchCb(const std_msgs::UInt8 &flag);

    /**
     * callback function for roadnet from package 'waypoint_manager'
     * @param way
     */
    void TaskPointCb(const lanelet_map_msgs::Way &way);

    void SimulationVehicleStateCb(const anm_msgs::VehicleState &state);

    void SimulationSteeringCb(const dbw_mkz_msgs::SteeringReport &steering);

    void PlanningOriginCb(const geometry_msgs::Point &origin);

    void evaluatePath(const StatePath &ref_path);

 private:
    /// private ros node handler
    ros::NodeHandle pnh_;
    /// publisher for control layer
    ros::Publisher traj_pub_;
    ros::Publisher rviz_path_pub_;
    /// publisher for the state of local planner
    ros::Publisher normal_plan_end_pub_;
    /// subscriber for ETH grid map
    ros::Subscriber gridmap_sub_;
    /// subscriber for task point
    ros::Subscriber task_point_sub_;
    /// subscriber for fusion position
    ros::Subscriber vehicle_fuse_pose_sub_;
    /// subscriber for roadnet
    ros::Subscriber waypoint_sub_;
    /// subscriber for ECU data
    ros::Subscriber ecudata_sub_;
    /// subscriber for the state of searching task
    ros::Subscriber finish_search_sub_;
    /// planning origin subscriber
    ros::Subscriber planning_origin_sub_;
    /// rviz visualization
    std::shared_ptr<PathPlannerVisualTools> lp_rviz_;

    /// vehicle state
    hmpl::State vehicle_state_;
    hmpl::State vehicle_state_planning_;
    ba::accumulator_set<double, ba::stats<ba::tag::rolling_mean> > kappa_;
    /// planning_origin
    geometry_msgs::Point planning_origin_;
    /// ETH grid map
    hmpl::InternalGridMap in_gm_;
    /// ETH grid map message
    grid_map_msgs::GridMap gridmap_msgs_;
    /// roadnet
    lanelet_map_msgs::Way ref_waypoint_;
    /// current task
    TaskType current_task_;
    /// configuration variable
    Configuration cfg_;
    /// flag variable for logic control
    Flag flag_;

    Time time_observe_;
};
#endif //STATE_SAMPLING_GLOBAL_PATH_NODE_HPP
