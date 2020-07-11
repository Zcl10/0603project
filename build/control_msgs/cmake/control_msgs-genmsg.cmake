# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "control_msgs: 13 messages, 0 services")

set(MSG_I_FLAGS "-Icontrol_msgs:/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Isensor_driver_msgs:/home/bit2/0603_project/tang_ws/src/msgs/sensor_driver_msgs/msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Inav_msgs:/opt/ros/kinetic/share/nav_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(control_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg" "control_msgs/ControlSteer:control_msgs/ControlSpeed:std_msgs/Header:control_msgs/ControlMode"
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg" "control_msgs/ReportControl:control_msgs/ReportWheel:control_msgs/ReportMotion:std_msgs/Header:control_msgs/ControlMode:control_msgs/ReportBrake:control_msgs/ReportThrottle:control_msgs/ControlSpeed:control_msgs/ReportVehicleWorkMode:control_msgs/ReportHMI:control_msgs/ControlSteer"
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg" "control_msgs/ControlSteer:control_msgs/ControlSpeed:std_msgs/Header:control_msgs/ControlMode"
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg" NAME_WE)
add_custom_target(_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "control_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)
_generate_msg_cpp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(control_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(control_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(control_msgs_generate_messages control_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_cpp _control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(control_msgs_gencpp)
add_dependencies(control_msgs_gencpp control_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS control_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)
_generate_msg_eus(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(control_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(control_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(control_msgs_generate_messages control_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_eus _control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(control_msgs_geneus)
add_dependencies(control_msgs_geneus control_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS control_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)
_generate_msg_lisp(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(control_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(control_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(control_msgs_generate_messages control_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_lisp _control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(control_msgs_genlisp)
add_dependencies(control_msgs_genlisp control_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS control_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)
_generate_msg_nodejs(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(control_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(control_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(control_msgs_generate_messages control_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_nodejs _control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(control_msgs_gennodejs)
add_dependencies(control_msgs_gennodejs control_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS control_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)
_generate_msg_py(control_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg;/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(control_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(control_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(control_msgs_generate_messages control_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Control.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSteer.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportHMI.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Rawdata.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlSpeed.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportVehicleWorkMode.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ControlMode.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportWheel.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportThrottle.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportMotion.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/Report.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportControl.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg/ReportBrake.msg" NAME_WE)
add_dependencies(control_msgs_generate_messages_py _control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(control_msgs_genpy)
add_dependencies(control_msgs_genpy control_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS control_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/control_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(control_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_driver_msgs_generate_messages_cpp)
  add_dependencies(control_msgs_generate_messages_cpp sensor_driver_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/control_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(control_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET sensor_driver_msgs_generate_messages_eus)
  add_dependencies(control_msgs_generate_messages_eus sensor_driver_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/control_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(control_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_driver_msgs_generate_messages_lisp)
  add_dependencies(control_msgs_generate_messages_lisp sensor_driver_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/control_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(control_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_driver_msgs_generate_messages_nodejs)
  add_dependencies(control_msgs_generate_messages_nodejs sensor_driver_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/control_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(control_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET sensor_driver_msgs_generate_messages_py)
  add_dependencies(control_msgs_generate_messages_py sensor_driver_msgs_generate_messages_py)
endif()
