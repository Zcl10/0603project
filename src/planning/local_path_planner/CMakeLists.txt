cmake_minimum_required(VERSION 2.8.3)
#set(CMKAE_BUILD_TYPE "Release")
project(local_path_planner)

## Add support for C++11, supported in ROS Kinetic and newer
add_definitions(-std=c++11)

#set(CMAKE_CXX_FLAGS "-Wall -Wextra ${CMAKE_CXX_FLAGS}")

set(catkin_deps
  opt_utils
  roslib
  roscpp
  grid_map_ros
  nav_msgs
  space_explore
  state_sampling
  internal_grid_map
  visualization_msgs
  car_model
  transform_tools
  guidance_point
  control_msgs
  dbw_mkz_msgs
  path_smoothing)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  ${catkin_deps}
  )

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS ${catkin_deps}
  #DEPENDS OpenCV
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(local_planner_node
        include
  src/local_planner_node.cpp
  src/roadnet_handler.cpp
  src/common_function.cpp
  src/search_based_method.cpp
  src/ros_topic_retelated.cpp
  src/path_planner_visual_tools.cpp
  )

target_link_libraries(local_planner_node
  ${catkin_LIBRARIES}
  glog)


