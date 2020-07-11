# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "three_one_msgs: 16 messages, 0 services")

set(MSG_I_FLAGS "-Ithree_one_msgs:/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(three_one_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg" "three_one_msgs/ControlWeapon:three_one_msgs/ControlSteer:three_one_msgs/ControlSuspension:three_one_msgs/ControlSpeed"
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg" NAME_WE)
add_custom_target(_three_one_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "three_one_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg" "three_one_msgs/ReportCylinderPressure:three_one_msgs/ReportVehicleState:three_one_msgs/ReportControlData:three_one_msgs/ReportTorque:three_one_msgs/ReportGiveBack:three_one_msgs/ReportMotion:three_one_msgs/ReportCylinderPosition:three_one_msgs/ReportDistance"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_cpp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(three_one_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(three_one_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(three_one_msgs_generate_messages three_one_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_cpp _three_one_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(three_one_msgs_gencpp)
add_dependencies(three_one_msgs_gencpp three_one_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS three_one_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)
_generate_msg_eus(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(three_one_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(three_one_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(three_one_msgs_generate_messages three_one_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_eus _three_one_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(three_one_msgs_geneus)
add_dependencies(three_one_msgs_geneus three_one_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS three_one_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)
_generate_msg_lisp(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(three_one_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(three_one_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(three_one_msgs_generate_messages three_one_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_lisp _three_one_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(three_one_msgs_genlisp)
add_dependencies(three_one_msgs_genlisp three_one_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS three_one_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)
_generate_msg_nodejs(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(three_one_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(three_one_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(three_one_msgs_generate_messages three_one_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_nodejs _three_one_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(three_one_msgs_gennodejs)
add_dependencies(three_one_msgs_gennodejs three_one_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS three_one_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg;/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)
_generate_msg_py(three_one_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(three_one_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(three_one_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(three_one_msgs_generate_messages three_one_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportGiveBack.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportDistance.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportTorque.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlWeapon.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPosition.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportMotion.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportVehicleState.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataRecv.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Control.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSuspension.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportControlData.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/RawdataSend.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSteer.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ControlSpeed.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/ReportCylinderPressure.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg/Report.msg" NAME_WE)
add_dependencies(three_one_msgs_generate_messages_py _three_one_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(three_one_msgs_genpy)
add_dependencies(three_one_msgs_genpy three_one_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS three_one_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/three_one_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/three_one_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/three_one_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/three_one_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/three_one_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
