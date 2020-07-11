#include <AutonomousControl.hpp>
#include "AutonomousControl.hpp"

namespace ecu_communication {

    void AutonomousControl::init(ros::NodeHandle node_handle,
                                 DataDownload *p_data_download, DataUpload *p_data_upload,
                                 std::mutex *p_data_upload_mutex, std::mutex *p_data_download_mutex,
                                 three_one_feedback::control_mode *p_control_mode, std::mutex *p_control_mode_mutex,
                                 sensor_driver_msgs::VehicleState *p_gps,
                                 bool *p_need_halt) {
        this->nh_ = node_handle;
        this->p_data_download_ = p_data_download;
        this->p_data_upload_ = p_data_upload;
        this->p_data_upload_mutex_ = p_data_upload_mutex;
        this->p_data_download_mutex_ = p_data_download_mutex;
        this->p_control_mode_ = p_control_mode;
        this->p_control_mode_mutex_ = p_control_mode_mutex;
        this->p_gps_ = p_gps;
        this->p_need_halt_ = p_need_halt;
        this->setHandles();
        this->msg_priority.total.current = -1;
        this->msg_priority.total.spare = -1;
        this->msg_priority.speed.current = 0;
        this->msg_priority.speed.spare = 0;
        this->msg_priority.steer.current = 0;
        this->msg_priority.steer.spare = 0;
        this->priority_check_timer_ = this->nh_.createTimer(ros::Duration(MSG_PRIORITY_CHECK_PERIOD),
                                                            boost::bind(&AutonomousControl::priorityCheck, this));
        this->gpsInit();
    }

    void AutonomousControl::setHandles() {
        this->speed_sub_handle_ = this->msg_update_times.time_handle.newHandle("check the period of speed");
        this->steer_sub_handle_ = this->msg_update_times.time_handle.newHandle("check the period of steer");
        this->mode_sub_handle_ = this->msg_update_times.time_handle.newHandle("check the period of mode");
    }
    void AutonomousControl::receive_init() {
        this->speed_sub_ = this->nh_.subscribe("/speedcmd", 1, &AutonomousControl::speedCb, this);
        this->steer_sub_ = this->nh_.subscribe("/steercmd", 1, &AutonomousControl::steerCb, this);
        this->ModeCmd_Sub = this->nh_.subscribe("modecmd", 1, &AutonomousControl::ModeCb, this);
    }

    void AutonomousControl::dataProcess() {
        static ros::Publisher publisher = this->nh_.advertise<control_msgs::Report>("/ecudatareport", 1);
        if (!this->send_switch_) {
            return;
        }
        this->p_data_upload_mutex_->lock();
        if (!this->p_data_upload_->dataCheck()) {
            this->p_data_upload_mutex_->unlock();
            LOG_ERROR << "data to publish check failure";
            return;
        }
        this->p_data_upload_->dataToMsg();

        this->p_data_upload_mutex_->unlock();
        this->p_data_download_mutex_->lock();
        this->reportControlData();
        this->p_data_download_mutex_->unlock();

        this->p_data_upload_->ecuReport.header.stamp = ros::Time::now();
        this->p_data_upload_->ecuReport.header.frame_id = "ecu";

        publisher.publish(this->p_data_upload_->ecuReport);
    }

    void AutonomousControl::reportControlData() {
        this->p_data_upload_->ecuReport.control.Speed = this->p_data_download_->received_control_data.Speed;
        this->p_data_upload_->ecuReport.control.Steer = this->p_data_download_->received_control_data.Steer;
    }

    bool AutonomousControl::rosmsgUpdateCheck() {
        //// todo modify check
        p_data_download_->speed_cmd_receive =
            this->msg_update_times.checkSingleTimestampTillNow(this->speed_sub_handle_, -1, 200);
        p_data_download_->steer_cmd_receive =
            this->msg_update_times.checkSingleTimestampTillNow(this->steer_sub_handle_, -1, 200);
        p_data_download_->mode_cmd_receive =
            this->msg_update_times.checkSingleTimestampTillNow(this->mode_sub_handle_, -1, 200);
        return p_data_download_->speed_cmd_receive && p_data_download_->steer_cmd_receive;

    }

    void AutonomousControl::speedCb(const control_msgs::ControlSpeed &msg) {
        if (!this->receive_switch_) {
            this->msg_update_times.pushTimestamp(this->speed_sub_handle_);
            return;
        }
        this->p_data_download_mutex_->lock();
        this->p_data_download_->received_control_data.Speed = msg;
        this->p_data_download_->SendECUData.torque_ctrl = msg.torque + 12000;
        this->p_data_download_->SendECUData.shift = msg.gear;
        this->p_data_download_->SendECUData.brake_ctrl = msg.brake;
        this->p_data_download_mutex_->unlock();
        this->msg_update_times.pushTimestamp(this->speed_sub_handle_);
    }

    void AutonomousControl::steerCb(const control_msgs::ControlSteer &msg) {
        if (!this->receive_switch_) {
            this->msg_update_times.pushTimestamp(this->steer_sub_handle_);
            return;
        }
        this->p_data_download_mutex_->lock();
        this->p_data_download_->received_control_data.Steer = msg;
        this->p_data_download_->SendECUData.steering_ctrl = (msg.steer + 780.0) * 10;
        this->p_data_download_mutex_->unlock();
        this->msg_update_times.pushTimestamp(this->steer_sub_handle_);
    }
    void AutonomousControl::ModeCb(const control_msgs::ControlMode &msg) {
        if (!this->receive_switch_) {
            this->msg_update_times.pushTimestamp(this->mode_sub_handle_);
            return;
        }
        this->p_data_download_mutex_->lock();
        this->p_data_download_->SendECUData.wipers_enable = msg.RainyLight;
        this->p_data_download_mutex_->unlock();
        this->msg_update_times.pushTimestamp(this->mode_sub_handle_);
    }
    void AutonomousControl::priorityCheck() {
        bool speed_check = true;
        bool steer_check = true;
        bool mode_check = true;
        bool master_check = true;
        //// todo not write master control now
        master_check = false;
        if (!master_check) {
            this->msg_priority.total.current = this->msg_priority.total.spare;
            this->msg_priority.total.spare = -1;
        }
        if (this->msg_priority.total.current != -1) {
            this->msg_priority.speed.spare = this->msg_priority.speed.current;
            this->msg_priority.speed.current = 255;

            this->msg_priority.steer.spare = this->msg_priority.steer.current;
            this->msg_priority.steer.current = 255;

            this->msg_priority.mode.spare = this->msg_priority.mode.current;
            this->msg_priority.mode.current = 255;
            return;
        }
        speed_check = this->msg_update_times.checkSingleTimestampTillNow(this->speed_sub_handle_, -1, 500);
        steer_check = this->msg_update_times.checkSingleTimestampTillNow(this->steer_sub_handle_, -1, 500);
        mode_check = this->msg_update_times.checkSingleTimestampTillNow(this->mode_sub_handle_, -1, 500);
        if (!speed_check) {
            this->msg_priority.speed.current = this->msg_priority.speed.spare;
            this->msg_priority.speed.spare = 0;
        }
        if (!steer_check) {
            this->msg_priority.steer.current = this->msg_priority.steer.spare;
            this->msg_priority.steer.spare = 0;
        }
        if (!mode_check) {
            this->msg_priority.mode.current = this->msg_priority.mode.spare;
            this->msg_priority.mode.spare = 0;
        }
    }
    bool AutonomousControl::gpsCheck() {
//    return this->msg_update_times.checkSingleTimestampTillNow(this->gps_sub_handle_, -1, 500);
        return 0;   //close gps msg receive
    }

    void AutonomousControl::gpsInit() {
        this->p_gps_->linear_velocity.x = 0.0;
        this->p_gps_->linear_velocity.y = 0.0;
        this->p_gps_->linear_velocity.z = 0.0;
        this->p_gps_->gps.latitude = 0.0;
        this->p_gps_->gps.longitude = 0.0;
        this->p_gps_->gps.altitude = 0.0;
        this->p_gps_->yaw = 0.0;
        this->p_gps_->roll = 0.0;
        this->p_gps_->pitch = 0.0;
    }

}
