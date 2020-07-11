cmake_minimum_required(VERSION 2.8.3)
project(guidance_point)

## Compile as C++11, supported in ROS Kinetic and newer
set(CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra ${CMAKE_CXX_FLAGS}")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
set(catkin_deps
  roscpp
  roslib
  gps_utils
  nav_msgs
  unique_id
  opt_utils
  anm_msgs
  lanelet_map_msgs
  sensor_driver_msgs
  internal_grid_map
  plan2control_msgs
  control_msgs
  transform_tools)
find_package(catkin REQUIRED COMPONENTS
  ${catkin_deps}
  )

find_package(Boost REQUIRED)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS ${catkin_deps}
  DEPENDS Boost
  LIBRARIES ${PROJECT_NAME}_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  )

## C++ library without ROS interface
add_library(${PROJECT_NAME}_lib
  src/guidance_point_selection.cpp
  src/laser_beam_method.cpp
  src/cg_solver.cpp)

## Link the libraries
target_link_libraries(${PROJECT_NAME}_lib
  ${catkin_LIBRARIES})
## Declare a C++ executable
#add_executable(${PROJECT_NAME}_node
#  src/guidance_point_node.cpp)

## Specify libraries to link a library or executable target against
#target_link_libraries(${PROJECT_NAME}_node
#  ${catkin_LIBRARIES}
#  ${PROJECT_NAME}_lib)
