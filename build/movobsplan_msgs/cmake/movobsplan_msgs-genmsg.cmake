# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "movobsplan_msgs: 4 messages, 0 services")

set(MSG_I_FLAGS "-Imovobsplan_msgs:/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(movobsplan_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg" NAME_WE)
add_custom_target(_movobsplan_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "movobsplan_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg" ""
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg" NAME_WE)
add_custom_target(_movobsplan_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "movobsplan_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg" "movobsplan_msgs/Movobspoint:std_msgs/Header:geometry_msgs/Point"
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg" NAME_WE)
add_custom_target(_movobsplan_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "movobsplan_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg" "geometry_msgs/Point"
)

get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg" NAME_WE)
add_custom_target(_movobsplan_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "movobsplan_msgs" "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg" "geometry_msgs/Point"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_cpp(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_cpp(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_cpp(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/movobsplan_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(movobsplan_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/movobsplan_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(movobsplan_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(movobsplan_msgs_generate_messages movobsplan_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_cpp _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_cpp _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_cpp _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_cpp _movobsplan_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(movobsplan_msgs_gencpp)
add_dependencies(movobsplan_msgs_gencpp movobsplan_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS movobsplan_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_eus(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_eus(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_eus(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/movobsplan_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(movobsplan_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/movobsplan_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(movobsplan_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(movobsplan_msgs_generate_messages movobsplan_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_eus _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_eus _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_eus _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_eus _movobsplan_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(movobsplan_msgs_geneus)
add_dependencies(movobsplan_msgs_geneus movobsplan_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS movobsplan_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_lisp(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_lisp(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_lisp(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/movobsplan_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(movobsplan_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/movobsplan_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(movobsplan_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(movobsplan_msgs_generate_messages movobsplan_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_lisp _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_lisp _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_lisp _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_lisp _movobsplan_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(movobsplan_msgs_genlisp)
add_dependencies(movobsplan_msgs_genlisp movobsplan_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS movobsplan_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_nodejs(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_nodejs(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_nodejs(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/movobsplan_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(movobsplan_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/movobsplan_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(movobsplan_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(movobsplan_msgs_generate_messages movobsplan_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_nodejs _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_nodejs _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_nodejs _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_nodejs _movobsplan_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(movobsplan_msgs_gennodejs)
add_dependencies(movobsplan_msgs_gennodejs movobsplan_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS movobsplan_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_py(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg"
  "${MSG_I_FLAGS}"
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_py(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/movobsplan_msgs
)
_generate_msg_py(movobsplan_msgs
  "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/movobsplan_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(movobsplan_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/movobsplan_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(movobsplan_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(movobsplan_msgs_generate_messages movobsplan_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspeed.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_py _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoints.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_py _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspath.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_py _movobsplan_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/movobsplan_msgs/msg/Movobspoint.msg" NAME_WE)
add_dependencies(movobsplan_msgs_generate_messages_py _movobsplan_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(movobsplan_msgs_genpy)
add_dependencies(movobsplan_msgs_genpy movobsplan_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS movobsplan_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/movobsplan_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/movobsplan_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(movobsplan_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(movobsplan_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/movobsplan_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/movobsplan_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(movobsplan_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(movobsplan_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/movobsplan_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/movobsplan_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(movobsplan_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(movobsplan_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/movobsplan_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/movobsplan_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(movobsplan_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(movobsplan_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/movobsplan_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/movobsplan_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/movobsplan_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(movobsplan_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(movobsplan_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
