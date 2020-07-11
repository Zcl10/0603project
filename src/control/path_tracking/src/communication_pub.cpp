//
// Created by yao on 20-7-1.
//

#include "lateral_control_core.h"

const double_t mass = 3150;
const double_t Cd = 0.33;
const double_t A = 2.28;
const double_t fic = 0.0241;
const double_t r = 0.35;

void LateralControlCore::messagePublish() {
    if (vrep_sim_enable_ || python_sim_enable_) {
        static ros::Publisher sim_str_pub = nh.advertise<std_msgs::Float32>("cmd_str", 10);
        static ros::Publisher sim_vel_pub = nh.advertise<std_msgs::Float32>("cmd_vel", 10);
        static ros::Publisher sim_acc_pub = nh.advertise<std_msgs::Float32>("cmd_acc", 10);
        static std_msgs::Float32 sim_steer;
        static std_msgs::Float32 sim_velocity;
        static std_msgs::Float32 sim_acceleration;
        this->velocity_next = std::sqrt(0.5 * 9.8 / 0.196);
        if (python_sim_enable_) {
            sim_steer.data = tan(this->steer_next) / vehicle_parameter.L;
            sim_velocity.data = this->velocity_next;
            sim_acceleration.data = this->acceleration_next;
        } else {
            sim_steer.data = atan(2.86 * this->steer_next);
            sim_velocity.data = 2.76 * this->velocity_next;;
            if (!path_forward)
                sim_velocity.data *= -1;
        }
        sim_str_pub.publish(sim_steer);
        sim_vel_pub.publish(sim_velocity);
        sim_acc_pub.publish(sim_acceleration);
        ROS_INFO_STREAM("sim_steer = " << sim_steer.data);
        ROS_INFO_STREAM("sim_velocity  = " << sim_velocity.data);
        ROS_INFO_STREAM("sim_acceleration = " << sim_acceleration.data);
    } else {
        static ros::Publisher cw_steer_pub = nh.advertise<control_msgs::ControlSteer>(steer_topic_, 1);
        static control_msgs::ControlSteer control_steer;
        control_steer.header.stamp = ros::Time::now();
        control_steer.header.frame_id = "steer";
        control_steer.priority = 0;
        control_steer.steer = this->steer_next * 180 / M_PI * control_parameter.steer_ratio;
        if(ecu_report.motion.drive_mode != 1){
            control_steer.steer = 0;
        }
        cw_steer_pub.publish(control_steer);
        ROS_INFO_STREAM("steer = " << control_steer.steer);
        if (ipopt_id_ == 1) {
            static ros::Publisher cw_speed_pub = nh.advertise<control_msgs::ControlSpeed>("/speedcmd", 1);
            static control_msgs::ControlSpeed control_speed;
            control_speed.header.stamp = ros::Time::now();
            control_speed.header.frame_id = "speed";
            control_speed.priority = 1;
            control_speed.gear = 4;
            control_speed.speed = velocity_next;
            control_speed.acc = acceleration_next;
            double aw = -Cd * A * pow(ecu_report.motion.velocity, 2) / 2 / mass;
            double af = -fic * 9.8;
            if (acceleration_next >= 0) {
                control_speed.torque = mass * r * (acceleration_next - aw - af);
                control_speed.brake = 0;
                ROS_INFO_STREAM("\033[1;42m Drive torque: " << control_speed.torque << "\033[0m.");
            } else if (acceleration_next < af + aw) {
                control_speed.torque = 0;
                control_speed.brake = 0; // (acceleration_next - aw - af) / -0.8;
                ROS_INFO_STREAM("\033[1;41m Brake pressure: " << control_speed.brake << "\033[0m.");
            } else {
                control_speed.torque = 0;
                control_speed.brake = 0;
            }
            if(ecu_report.motion.drive_mode != 1){
                control_speed.gear = 3;
                control_speed.speed = 0;
                control_speed.acc = 0;
                control_speed.torque = 0;
                control_speed.brake = 0;
            }
            cw_speed_pub.publish(control_speed);
        }
    }
}

void LateralControlCore::sendMessageToRviz(const std::vector<double> &local_path_x,
                                           const std::vector<double> &local_path_y) {
    // To rviz
    static ros::Publisher vehicle_pose_pub = nh.advertise<geometry_msgs::PoseStamped>("vehicle_pose_rviz", 1, true);
    static ros::Publisher global_path_pub = nh.advertise<nav_msgs::Path>("global_path_rviz", 1, true);
    static ros::Publisher initref_pub = nh.advertise<nav_msgs::Path>("initref_path", 1, true);
    static ros::Publisher predict_pub = nh.advertise<nav_msgs::Path>("predict_path", 1, true);
    // vehilce_pose_msg
    geometry_msgs::PoseStamped vehilce_pose_msg = {};
    vehilce_pose_msg.header.stamp = ros::Time::now();
    vehilce_pose_msg.pose.position.x = 0;//vehicle_point.pose.x - global_path[0].position.x;
    vehilce_pose_msg.pose.position.y = 0;//vehicle_point.pose.y - global_path[0].position.y;
    vehilce_pose_msg.pose.position.z = 0;
    vehilce_pose_msg.pose.orientation.x = vehicle_state.orientation.z;
    // global_path_msg
    nav_msgs::Path global_path_msg = {};
    geometry_msgs::PoseStamped global_path_rviz;
    global_path_msg.header.stamp = ros::Time::now();
    global_path_rviz.header = global_path_msg.header;
    for (int i = 0; i < local_path_x.size(); ++i) {
        global_path_rviz.pose.position.x = local_path_x[i];
        global_path_rviz.pose.position.y = local_path_y[i];
        global_path_rviz.pose.position.z = 0;
        global_path_msg.poses.emplace_back(global_path_rviz);
    }
    // initref_path_msg
    nav_msgs::Path initref_path_msg = {};
    initref_path_msg.header.stamp = ros::Time::now();
    geometry_msgs::PoseStamped initref_pose;
    initref_pose.header = initref_path_msg.header;
    for (int i = 0; ptr_refer_path_ != nullptr && i < ptr_refer_path_->size(); ++i) {
        initref_pose.pose.position.x = ptr_refer_path_->at(i)[0];
        initref_pose.pose.position.y = ptr_refer_path_->at(i)[1];
        initref_pose.pose.position.z = 0;
        initref_path_msg.poses.emplace_back(initref_pose);
    }
    // predict_path_msg
    nav_msgs::Path predict_path_msg = {};
    predict_path_msg.header.stamp = ros::Time::now();
    geometry_msgs::PoseStamped predict_pose;
    predict_pose.header = predict_path_msg.header;
    for (int i = 0; ptr_predict_path_ != nullptr && i < ptr_predict_path_->size(); ++i) {
        predict_pose.pose.position.x = ptr_predict_path_->at(i)[0];
        predict_pose.pose.position.y = ptr_predict_path_->at(i)[1];
        predict_pose.pose.position.z = 0;
        predict_path_msg.poses.emplace_back(predict_pose);
    }

    vehilce_pose_msg.header.frame_id = this->rviz_frame;
    global_path_msg.header.frame_id = this->rviz_frame;
    initref_path_msg.header.frame_id = this->rviz_frame;
    predict_path_msg.header.frame_id = this->rviz_frame;

    vehicle_pose_pub.publish(vehilce_pose_msg);
    global_path_pub.publish(global_path_msg);
    initref_pub.publish(initref_path_msg);
    predict_pub.publish(predict_path_msg);
}