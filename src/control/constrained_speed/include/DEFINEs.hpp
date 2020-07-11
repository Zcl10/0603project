#ifndef CONSTRAINED_SPEED_DEFINES_HPP
#define CONSTRAINED_SPEED_DEFINES_HPP

#define LOG_INFO LOG(INFO)<<std::setiosflags(std::ios::fixed)<<ros::Time::now().toSec()<<" "
#define LOG_WARN LOG(WARNING)<<std::setiosflags(std::ios::fixed)<<ros::Time::now().toSec()<<" "
#define LOG_ERROR LOG(ERROR)<<std::setiosflags(std::ios::fixed)<<ros::Time::now().toSec()<<" "
#define LOG_FATAL LOG(FATAL)<<std::setiosflags(std::ios::fixed)<<ros::Time::now().toSec()<<" "
#define FIXED std::setiosflags(std::ios::fixed)<<

#define PROCESS_PERIOD 0.1
#define ISSUE_MODE "direct" // direct cycle
#define TIME_CHECK_PERIOD 0.2

#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include "constrained_speed/cs_method2Parameters.h"
#include "lanelet_map_msgs/Way.h"
#include "plan2control_msgs/Trajectory.h"
#include "movobsplan_msgs/Movobspeed.h"
#include "control_msgs/Report.h"
#include "control_msgs/Control.h"
#include "speed_debug_msgs/speed_debug.h"
#include "anm_msgs/VehicleState.h"
#include "dbw_mkz_msgs/SteeringReport.h"
#include "std_msgs/Float32.h"

#include "toolkit.h"
#include "SHandle.hpp"
#include "SLog.hpp"
#include "SJerk.hpp"
#include "SPoints.hpp"
#include "SThreePointsCurvature.hpp"
#include "STime.hpp"
#include "Publish.hpp"

#endif //CONSTRAINED_SPEED_DEFINES_HPP