cmake_minimum_required(VERSION 2.8.3)
project(control_msgs)

## Find catkin macros and libraries
find_package(catkin REQUIRED
    roscpp
    message_generation
    std_msgs
    sensor_driver_msgs
)

## Add messages to be generated
add_message_files(
 FILES
 Control.msg
 ControlMode.msg
 ControlSpeed.msg
 ControlSteer.msg

 Report.msg
 ReportBrake.msg
 ReportControl.msg
 ReportHMI.msg
 ReportMotion.msg
 ReportThrottle.msg
 ReportWheel.msg
 ReportVehicleWorkMode.msg
 Rawdata.msg
)

## Generate messages
generate_messages(
    DEPENDENCIES
    std_msgs
    sensor_driver_msgs
)

catkin_package(
    CATKIN_DEPENDS message_generation roscpp std_msgs
)

#############
## Install ##
#############

## The header files for the messages are automatically copied to install/include/anm_msgs
