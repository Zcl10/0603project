#ifndef CONSTRAINED_SPEED_CSMETHOD2_HPP
#define CONSTRAINED_SPEED_CSMETHOD2_HPP

#include "DEFINEs.hpp"

namespace constrained_speed {

    enum class direction {
        stop = 0,
        forward = 1,
        backward = 2
    };

    struct params {
        bool vrep_sim;
        double_t acc_lat;
        double_t acc_max;
        double_t acc_min;
        double_t safe_dec;
        double_t v_max;
        double_t jerk;
        std::string road_net_topic;
    };

    class CSMethod2 {
    public:
        CSMethod2(ros::NodeHandle node_handle, ros::NodeHandle private_node_handle);

    private:
        /// \brief  store params from file(yaml)
        params yaml_params_;

        /// \brief  store the direction from the path
        direction direction_;
        /// \brief  current speed of the car
        double_t cur_speed_;
        /// \brief  current acceleration of the car, signed
        double_t cur_acc_;
        /// \brief  current brake of the car, unsigned
        double_t cur_brake_;

        /// \brief  store the points number of the received path
        size_t points_size_;
        /// \brief  store the x coordinates of the received path
        std::vector<double_t> x_points_;
        /// \brief  store the y coordinates of the received path
        std::vector<double_t> y_points_;
        /// \brief  store the intervals of the received path
        std::vector<double_t> intervals_;
        /// \brief  store the arc-lengths of the received path
        std::vector<double_t> arc_lengths_;
        /// \brief  store the curvatures of the received path
        std::vector<double_t> curvatures_;
        /// \brief store time attribute of speed profile
        std::vector<double_t> time_;
        /// \brief store time interval attribute of speed profile
        std::vector<double_t> time_interval_;
        /// \brief  the speed profile
        std::vector<double_t> v_;
        /// \brief store acceleration attribute of speed profile
        std::vector<double_t> acc_;
        /// \brief store jerk attribute of speed profile
        std::vector<double_t> jerk_;

        /// \brief  init the log tool
        void glogInit();
        /// \brief  init the params
        void paramsInit();
        /// \brief  set handles
        void setHandle();
        /// \brief  check the time period of variety functions
        void time_check();
        /// \brief mark if no msg received from ros
        bool no_msg_;
        /// \brief  the function of speed planning
        void planning();
        /// \brief  pretreat the received path
        bool pointsPretreat();
        /// \brief  calculate some attributes of the received path
        bool pointsAttributes();
        /// \brief  set v max of the trajectory
        bool setVMax();
        /// \brief  limit the latitude acceleration of the trajectory
        bool limitLatAcc();
        /// \brief limit speed profile by steer command
        bool limitBySteer();
        /// \brief  the car should have ability to avoid from danger
        bool safeStopSpeed();
        /// \brief smooth the speed slow down
        bool smoothSlowDown();
        /// \brief  this function is not from theory, but should be used in practice
        bool blindHandle();
        /// \brief  smooth the speed profile along the path
        bool smoothSpeed();
        /// \brief calculate time of neighboring points
        bool calTime();
        /// \brief calculate acceleration of speed profile
        bool calAcc();
        /// \brief calculate jerk of speed profile
        bool calJerk();
        /// \brief publish results to ros
        bool publish();
        /// \brief additional publish
        void additionPublish(std::vector<double_t> issue);

        /// \brief ros nodehandle
        ros::NodeHandle nh_;
        /// \brief ros private nodehandle
        ros::NodeHandle private_nh_;
        /// \brief  callback function of the roadnet
        void roadnetCb(const lanelet_map_msgs::Way &msg);
        /// \brief  callback function of the path
        void pathCb(const plan2control_msgs::Trajectory &msg);
        /// \brief  callback function of the dynamic obstacle
        void collisionCb(const movobsplan_msgs::Movobspeed &msg);
        /// \brief  callback function of the steer command
        void steerCmdCb(const control_msgs::ControlSteer &msg);
        /// \brief  callback function of ecu on cw platform
        void ecuCb(const control_msgs::Report &msg);
        /// \brief  callback function of the vrep sim steer command
        void steerCmdCbSim(const std_msgs::Float32 &msg);
        /// \brief  callback function of the vrep sim vehicle state
        void vehicleStateCbSim(const anm_msgs::VehicleState &msg);

        /// \brief  the subscriber of the roadnet
        ros::Subscriber roadnet_sub_;
        /// \brief  the subscriber of the path
        ros::Subscriber path_sub_;
        /// \brief  the subscriber of the dynamic obstacle
        ros::Subscriber collision_sub_;
        /// \brief  the subscriber of the steer command
        ros::Subscriber steer_cmd_sub_;
        /// \brief  the subscriber of the ecu on cw platform
        ros::Subscriber ecu_sub_;
        /// \brief  the process timer of speed planning
        ros::Timer process_timer_;
        /// \brief  the timer of time check
        ros::Timer check_timer_;

        /// \brief  ros msg of trajectory
        plan2control_msgs::Trajectory trajectory_;
        /// \brief ros msg of roadnet
        lanelet_map_msgs::Way way_;
        /// \brief ros msg of steer command
        control_msgs::ControlSteer control_steer_;
        /// \brief ros msg of dynamic obstacle
        movobsplan_msgs::Movobspeed collision_;

        /// \brief  log tool
        shawn::SLog sLog_;
        /// \brief speed planning core
        shawn::SJerk sJerk;
        /// \brief time check tool for subscribing
        shawn::STime sub_times_;
        /// \brief path subscriber handle
        shawn::handle path_sub_handle_;
        /// \brief ecu subscriber handle
        shawn::handle ecu_sub_handle_;
        /// \brief roadnet subscriber handle
        shawn::handle roadnet_sub_handle_;
        /// \brief steer command subscriber handle
        shawn::handle steer_cmd_sub_handle_;
        /// \brief dynamic obstacle subscriber handle
        shawn::handle collision_sub_handle_;

        /// \brief dynamic reconfigure params
        cs_method2Parameters params_;
        /// \brief  dynamic reconfigure service
        dynamic_reconfigure::Server<cs_method2Config> reconfigSrv_;
        /// \brief callback function of dynamic reconfigure
        void reconfigureRequest(cs_method2Config &config, uint32_t level);
    };

}

#endif //CONSTRAINED_SPEED_CSMETHOD2_HPP