# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "vertical_wall_grid: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ivertical_wall_grid:/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Inav_msgs:/opt/ros/kinetic/share/nav_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(vertical_wall_grid_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg" NAME_WE)
add_custom_target(_vertical_wall_grid_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "vertical_wall_grid" "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(vertical_wall_grid
  "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/vertical_wall_grid
)

### Generating Services

### Generating Module File
_generate_module_cpp(vertical_wall_grid
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/vertical_wall_grid
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(vertical_wall_grid_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(vertical_wall_grid_generate_messages vertical_wall_grid_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg" NAME_WE)
add_dependencies(vertical_wall_grid_generate_messages_cpp _vertical_wall_grid_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(vertical_wall_grid_gencpp)
add_dependencies(vertical_wall_grid_gencpp vertical_wall_grid_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS vertical_wall_grid_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(vertical_wall_grid
  "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/vertical_wall_grid
)

### Generating Services

### Generating Module File
_generate_module_eus(vertical_wall_grid
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/vertical_wall_grid
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(vertical_wall_grid_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(vertical_wall_grid_generate_messages vertical_wall_grid_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg" NAME_WE)
add_dependencies(vertical_wall_grid_generate_messages_eus _vertical_wall_grid_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(vertical_wall_grid_geneus)
add_dependencies(vertical_wall_grid_geneus vertical_wall_grid_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS vertical_wall_grid_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(vertical_wall_grid
  "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/vertical_wall_grid
)

### Generating Services

### Generating Module File
_generate_module_lisp(vertical_wall_grid
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/vertical_wall_grid
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(vertical_wall_grid_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(vertical_wall_grid_generate_messages vertical_wall_grid_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg" NAME_WE)
add_dependencies(vertical_wall_grid_generate_messages_lisp _vertical_wall_grid_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(vertical_wall_grid_genlisp)
add_dependencies(vertical_wall_grid_genlisp vertical_wall_grid_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS vertical_wall_grid_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(vertical_wall_grid
  "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/vertical_wall_grid
)

### Generating Services

### Generating Module File
_generate_module_nodejs(vertical_wall_grid
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/vertical_wall_grid
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(vertical_wall_grid_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(vertical_wall_grid_generate_messages vertical_wall_grid_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg" NAME_WE)
add_dependencies(vertical_wall_grid_generate_messages_nodejs _vertical_wall_grid_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(vertical_wall_grid_gennodejs)
add_dependencies(vertical_wall_grid_gennodejs vertical_wall_grid_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS vertical_wall_grid_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(vertical_wall_grid
  "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/vertical_wall_grid
)

### Generating Services

### Generating Module File
_generate_module_py(vertical_wall_grid
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/vertical_wall_grid
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(vertical_wall_grid_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(vertical_wall_grid_generate_messages vertical_wall_grid_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bit2/0603_project/tang_ws/src/msgs/vertical_wall_grid_msg/msg/vertical_wall_grid.msg" NAME_WE)
add_dependencies(vertical_wall_grid_generate_messages_py _vertical_wall_grid_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(vertical_wall_grid_genpy)
add_dependencies(vertical_wall_grid_genpy vertical_wall_grid_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS vertical_wall_grid_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/vertical_wall_grid)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/vertical_wall_grid
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(vertical_wall_grid_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET nav_msgs_generate_messages_cpp)
  add_dependencies(vertical_wall_grid_generate_messages_cpp nav_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(vertical_wall_grid_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(vertical_wall_grid_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/vertical_wall_grid)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/vertical_wall_grid
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(vertical_wall_grid_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET nav_msgs_generate_messages_eus)
  add_dependencies(vertical_wall_grid_generate_messages_eus nav_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(vertical_wall_grid_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(vertical_wall_grid_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/vertical_wall_grid)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/vertical_wall_grid
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(vertical_wall_grid_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET nav_msgs_generate_messages_lisp)
  add_dependencies(vertical_wall_grid_generate_messages_lisp nav_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(vertical_wall_grid_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(vertical_wall_grid_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/vertical_wall_grid)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/vertical_wall_grid
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(vertical_wall_grid_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET nav_msgs_generate_messages_nodejs)
  add_dependencies(vertical_wall_grid_generate_messages_nodejs nav_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(vertical_wall_grid_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(vertical_wall_grid_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/vertical_wall_grid)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/vertical_wall_grid\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/vertical_wall_grid
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(vertical_wall_grid_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET nav_msgs_generate_messages_py)
  add_dependencies(vertical_wall_grid_generate_messages_py nav_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(vertical_wall_grid_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(vertical_wall_grid_generate_messages_py std_msgs_generate_messages_py)
endif()
