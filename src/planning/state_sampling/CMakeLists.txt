cmake_minimum_required(VERSION 2.8.3)
#set(CMKAE_BUILD_TYPE "Release")
project(state_sampling)
set(CMAKE_BUILD_TYPE "Release")
## Add support for C++11, supported in ROS Kinetic and newer
add_definitions(-std=c++11)

#set(CMAKE_CXX_FLAGS "-Wall -Wextra ${CMAKE_CXX_FLAGS}")

set(catkin_deps
  opt_solver
  opt_utils
  roslib
  roscpp
  grid_map_ros
  nav_msgs
  space_explore
  internal_grid_map
  visualization_msgs
  car_model
  transform_tools
  guidance_point
  control_msgs)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  ${catkin_deps}
)

find_package(yaml-cpp REQUIRED yaml-cpp > 0.5)
find_package(Boost COMPONENTS filesystem REQUIRED)
find_package(OpenCV REQUIRED)
find_package(PCL REQUIRED COMPONENT io)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS ${catkin_deps}
  DEPENDS OpenCV
)

###########
## Build ##
###########

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  ${Boost_FILESYSTEM_INCLUDE_DIRS}
  ${YAML_CPP_INCLUDE_DIRS}
)

message(STATUS "TEST filesystem:" ${Boost_INCLUDE_DIRS})

add_library(${PROJECT_NAME}
  src/state_sampling.cpp
  src/puresuit_method.cpp
  src/collision_checker.cpp)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES})

#add_executable(global_path_node
#  src/global_path_node.cpp)
#target_link_libraries(global_path_node
#  ${catkin_LIBRARIES}
#  ${PROJECT_NAME}
#  ${OpenCV_LIBRARIES})


add_executable(state_sampling_demo
  demo/state_sampling_demo.cpp)

target_link_libraries(state_sampling_demo
  ${catkin_LIBRARIES}
  ${PROJECT_NAME})

add_executable(pursuit_sampling_demo
  demo/puresuit_sampling_demo.cpp)

target_link_libraries(pursuit_sampling_demo
  ${catkin_LIBRARIES}
  ${PROJECT_NAME})


#add_executable(collision_checking_benchmark
#  benchmark/collision_checking_benchmark.cpp)
#
#target_link_libraries(collision_checking_benchmark
#  ${catkin_LIBRARIES}
#  ${YAML_CPP_LIBRARIES}
#  ${Boost_FILESYSTEM_LIBRARIES}
#  ${PROJECT_NAME})
#
#catkin_add_gtest(state_sampling_test
#  tests/state_sampling_test.cpp)
#
#target_link_libraries(state_sampling_test
#  ${catkin_LIBRARIES}
#  ${PROJECT_NAME})

