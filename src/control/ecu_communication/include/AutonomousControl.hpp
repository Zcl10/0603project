#ifndef ECU_COMMUNICATION_AUTONOMOUSCONTROL_HPP
#define ECU_COMMUNICATION_AUTONOMOUSCONTROL_HPP

#include <ros/ros.h>
#include <cmath>
#include <thread>
#include <mutex>
#include <vector>

#include "control_msgs/Report.h"
#include "control_msgs/Control.h"
#include "sensor_driver_msgs/VehicleState.h"

#include "STime.hpp"
#include "SLog.hpp"
#include "SHandle.hpp"

#include "ThreeOne.hpp"
#include "DEFINEs.hpp"
#include "DataUpload.hpp"
#include "DataDownload.hpp"
#include "geometry_msgs/Vector3Stamped.h"
namespace ecu_communication {

class AutonomousControl {
public:
    struct {
        struct {
            int current;
            int spare;
        } total;
        struct {
            uint8_t current;
            uint8_t spare;
        } speed;
        struct {
            uint8_t current;
            uint8_t spare;
        } steer;
        struct {
            uint8_t current;
            uint8_t spare;
        } mode;
        struct {
            uint8_t current;
            uint8_t spare;
        } gear;
    } msg_priority;

    ros::Timer priority_check_timer_;
    void priorityCheck();

    //// time check
    shawn::STime msg_update_times;
    shawn::handle speed_sub_handle_;
    shawn::handle steer_sub_handle_;
    shawn::handle mode_sub_handle_;

    //// ROS Variables
    ros::NodeHandle nh_;
    ros::Subscriber speed_sub_;
    ros::Subscriber steer_sub_;

    ros::Subscriber ModeCmd_Sub;

    //// markers
    bool send_switch_;
    bool receive_switch_;

    //modeenable


    //// communication data and variables
    DataUpload *p_data_upload_;
    DataDownload *p_data_download_;
    std::mutex *p_data_upload_mutex_;
    std::mutex *p_data_download_mutex_;
    sensor_driver_msgs::VehicleState *p_gps_;

    three_one_feedback::control_mode *p_control_mode_;
    std::mutex *p_control_mode_mutex_;
    bool *p_need_halt_;

    void init(ros::NodeHandle node_handle,
              DataDownload *p_data_download, DataUpload *p_data_upload,
              std::mutex *p_data_upload_mutex, std::mutex *p_data_download_mutex,
              three_one_feedback::control_mode *p_control_mode, std::mutex *p_control_mode_mutex,
              sensor_driver_msgs::VehicleState *p_gps,
              bool *p_need_halt);
    void setHandles();
    void receive_init();
    void dataProcess();
    void reportControlData();
    bool rosmsgUpdateCheck();
    void speedCb(const control_msgs::ControlSpeed &msg);
    void steerCb(const control_msgs::ControlSteer &msg);
    void ModeCb(const control_msgs::ControlMode &msg);
    void QRdetectCb( geometry_msgs::Vector3Stamped msg);
    bool gpsCheck();
    void gpsInit();
};

}

#endif //ECU_COMMUNICATION_AUTONOMOUSCONTROL_HPP