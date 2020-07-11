#ifndef ECU_COMMUNICATION_COMMUNICATIONPROCESS_HPP
#define ECU_COMMUNICATION_COMMUNICATIONPROCESS_HPP

#include <ros/ros.h>
#include <cmath>
#include <thread>
#include <mutex>
#include <vector>
#include <glog/logging.h>

#include <dynamic_reconfigure/server.h>
#include "ecu_communication/ecu_communicationParameters.h"
#include "STime.hpp"
#include "SLog.hpp"
#include "SProportion.hpp"

#include "DEFINEs.hpp"
#include "ThreeOne.hpp"
#include "UDPCommunication.hpp"
#include "DataUpload.hpp"
#include "DataDownload.hpp"
#include "AutonomousControl.hpp"
#include "RemoteControl.hpp"


namespace ecu_communication {

struct yaml_params_type {
    bool upper_layer_send;
    bool upper_layer_receive;
    bool lower_layer_send;
    bool lower_layer_receive;
    bool remote_receive;
    bool remote_send;

    std::string ecu_local_ip;
    int ecu_local_port;
    std::string ecu_remote_ip;
    int ecu_remote_port;

    std::string remote_local_ip;
    int remote_local_port;
    std::string remote_remote_ip;
    int remote_remote_port;

    bool reconfig;
    bool send_default_when_no_msg;
    bool log_rawdata;
    bool publish_rawdata;
    bool force_autonomous;

    double limit_speed;
    int limit_thousand_curv;
    std::vector<std::string> files;

    bool chamber_fix_default;
};

class CommunicationProcess {
public:
    CommunicationProcess(ros::NodeHandle node_handle, ros::NodeHandle private_node_handle);
    ~CommunicationProcess();

private:
    sensor_driver_msgs::VehicleState gps_;

    bool three_one_control_;
    three_one_feedback::control_mode control_mode_;
    std::mutex control_mode_mutex_;

    shawn::SLog sLog_;

    //// markers
    bool udp_send_switch_;

    AutonomousControl autonomousControl_;
    RemoteControl remoteControl_;
    std::thread remote_receive_thread_;

    //// time check
    shawn::STime udp_recv_times_;
    shawn::handle udp_recv_handle_;
    shawn::handle udp_recv_correct_handle_;

    shawn::STime pack_recv_times_;
    shawn::handle pack1_recv_handle_;
    shawn::handle pack2_recv_handle_;
    shawn::handle pack3_recv_handle_;
    shawn::handle pack4_recv_handle_;
    shawn::handle pack5_recv_handle_;
    shawn::handle pack6_recv_handle_;
    shawn::handle pack7_recv_handle_;


    //// ROS Variables
    ros::NodeHandle nh_;
    ros::NodeHandle private_nh_;
    ros::Timer time_check_timer_;
    ros::Timer udp_send_timer_;
    ros::Timer ros_publish_timer_;
    ros::Timer remote_send_timer_;
    ros::Publisher udp_recv_rawdata_publisher_;
    ros::Publisher udp_send_rawdata_publisher_;

    //// rosparam handler
    ecu_communicationParameters params_;
    dynamic_reconfigure::Server<ecu_communicationConfig> reconfigSrv_;
    yaml_params_type yaml_params_;


    //// UDP communication
    UDPCommunication udp_;
    std::thread udp_receive_thread;
    shawn::SProportion udp_send_proportion_;
    shawn::handle udp_pack_handle_;

    //// UDP communication data and variables
    DataUpload data_upload_;
    DataDownload data_download_;
    std::mutex data_upload_mutex_;
    std::mutex data_download_mutex_;

    weapon::cmd weapon_cmd_;

    bool halt_by_auto;
    bool halt_by_remote;

    void glogInit();
    void paramsInit();
    void setTimeCheckHandle();
    void reconfigureRequest(ecu_communicationConfig &config, uint32_t level);
    void udpReceive();
    void udpSend();
    void timeCheck();
    bool udpReceiveCheck();
    void fake_issue();

    void remote_fake_issue();

    ros::Timer fuck_timer;
    void fuck_send();
//    SerialPortCommunication serialPortCommunication;
};

}
#endif //ECU_COMMUNICATION_COMMUNICATIONPROCESS_HPP