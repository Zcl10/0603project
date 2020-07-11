//
// Created by yao on 20-4-18.
//

#ifndef PATH_TRACKING_PATH_TRACKING_H
#define PATH_TRACKING_PATH_TRACKING_H

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cmath>
#include <ros/ros.h>
#include "toolkit.h"
#include "spline.h"
#include "polynomial_fitting.h"
#include "std_msgs/Float32.h"
#include "anm_msgs/VehicleState.h"
#include "dbw_mkz_msgs/SteeringReport.h"
#include "control_msgs/Control.h"
#include "control_msgs/Report.h"
#include "nav_msgs/Path.h"
#include "plan2control_msgs/Trajectory.h"
#include "sensor_msgs/Imu.h"
#include "sensor_driver_msgs/GpswithHeading.h"
#include "sensor_driver_msgs/InsVelocity.h"

struct TimeHandle {
    bool is_update;
    double elapse_time_;
    double last_timestamp;
    TimeHandle() {
        is_update = false;
        elapse_time_ = 200;
        last_timestamp = 0;
    }
};

struct FrenetCoordinate {
    double s;
    double d;
    double phi;
};

struct VehicleParameter {
    double r;
    double L;
    double B;
    double a;
    double b;
    double m;
    double I;
    double Cf;
    double Cr;
};

struct Weight {
    double vel;
    double acc;
    double acc_rate;
    double cte;
    double epsi;
    double steer;
    double steer_rate;
};

struct ControlParameter {
    bool dynamic;
    int control_rate;
    int predict_N;
    double sample_time;
    double delay_time;
    double lowest_length;
    double lowest_velocity;
    double desire_velocity;
    double max_acceleration;
    double max_deceleration;
    double max_steer;
    double max_steer_rate;
    double steer_ratio;
    double lateral_acc;
    Weight weight;
};

struct RibbonParams {
    double road_width;
    double distance;
    double first_point_distance;
    double max_steer;
};

struct PPParams {
    double k;
    double max_steer;
};

#endif //PATH_TRACKING_PATH_TRACKING_H
