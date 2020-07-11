//
// Created by yao on 20-4-14.
//

#ifndef CHASSIS_TESTING_CHASSIS_TESTING_H
#define CHASSIS_TESTING_CHASSIS_TESTING_H

#include <iostream>
#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include "control_msgs/Control.h"

struct StaticTestingParameters {
    int publish_rate;
    int gear;
    double target_torque;
    double halt;
    double steer_degree;
};

struct DynamicTestingParameters {
    int publish_rate;
    int lateral_acc;
    double max_speed;
    double prepare_time;
    double maintain_time;
};

class ChassisTesting {
public:
    ChassisTesting() {
        nh = ros::NodeHandle();
        speed_pub = nh.advertise<control_msgs::ControlSpeed>("speedcmd", 1);
        steer_pub = nh.advertise<control_msgs::ControlSteer>("steercmd", 1);
    }
    void messagesPublish(const control_msgs::Control &tang) {
        speed_pub.publish(tang.Speed);
        steer_pub.publish(tang.Steer);
    }
private:
    ros::NodeHandle nh;
    ros::Publisher speed_pub, steer_pub;
};

#endif //CHASSIS_TESTING_CHASSIS_TESTING_H
