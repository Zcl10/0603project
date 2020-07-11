cmake_minimum_required(VERSION 2.8.3)
project(map_server)
#set(CMAKE_BUILD_TYPE "Release")
add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra ${CMAKE_CXX_FLAGS}")

set(catkin_deps
	roscpp
	roslib
	grid_map_ros
	opt_utils
	internal_grid_map
	transform_tools
	std_msgs
	iv_slam_ros_msgs
	sensor_driver_msgs
	visualization_msgs
	lanelet_map_msgs
	plan2control_msgs
	geometry_msgs
	nav_msgs
	anm_msgs
	tf2
	message_filters)

find_package(catkin REQUIRED COMPONENTS
${catkin_deps})

find_package(OpenCV REQUIRED)

find_package(PCL REQUIRED COMPONENT io)

include_directories(
	include
	${catkin_INCLUDE_DIRS}
	${PCL_INCLUDE_DIRS}/pcl-1.8)

catkin_package(
  CATKIN_DEPENDS ${catkin_deps}
  DEPENDS OpenCV
)


add_executable(${PROJECT_NAME}_node
	src/map_server_node.cpp
	src/ros_interface.cpp
	src/display_thread.cpp)
target_include_directories(${PROJECT_NAME}_node
	SYSTEM PUBLIC
	${catkin_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}_node
	${catkin_LIBRARIES}
	${OpenCV_LIBS}
	${PCL_LIBRARIES})
