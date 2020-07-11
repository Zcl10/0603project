cmake_minimum_required(VERSION 2.8.3)
project(waypoint_manager)

## Compile as C++11, supported in ROS Kinetic and newer
 add_compile_options(-std=c++11)
#set(CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")

## Find catkin macros and libraries
set(catkin_deps
  roscpp
  sensor_driver_msgs
  lanelet_map_msgs
  nav_msgs
  opt_utils
  anm_msgs
  roslib
  transform_tools
  tinyspline_ros)
find_package(catkin REQUIRED COMPONENTS
  ${catkin_deps}
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES waypoint_manager
  CATKIN_DEPENDS ${catkin_deps}
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
#${GeographicLib_LIBRARIES}

add_executable(waypoint_collection
  src/waypoint_collection_node.cpp
  src/ros_interface.cpp)
target_link_libraries(waypoint_collection
  ${catkin_LIBRARIES})

add_executable(route_publisher
  src/route_publisher_node.cpp
  src/ros_interface.cpp)
target_link_libraries(route_publisher
  ${catkin_LIBRARIES})

install(
  TARGETS waypoint_collection route_publisher #待安装库、可执行文件名
  EXPORT ${PROJECT_NAME}Export #待输出安装配置文件　note 2
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
 DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
 FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)

install(DIRECTORY
	launch config waypoint_files
	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
