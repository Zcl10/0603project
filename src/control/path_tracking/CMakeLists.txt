cmake_minimum_required(VERSION 2.8.3)

project(path_tracking)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 ${CMAKE_CXX_FLAGS}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(catkin_deps message_generation roscpp rospy roslib
        std_msgs anm_msgs nav_msgs dbw_mkz_msgs sensor_msgs sensor_driver_msgs plan2control_msgs control_msgs)
## find ros packages and combine them with catkin
find_package(catkin REQUIRED COMPONENTS ${catkin_deps})
find_package(controllib REQUIRED)
find_package(IPOPT REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)

add_message_files(DIRECTORY msg FILES observer.msg ModelParameter.msg)
generate_messages(DEPENDENCIES std_msgs anm_msgs control_msgs)
message(STATUS "CMAKE SOURCE DIR:" ${CMAKE_MODULE_PATH})
catkin_package(CATKIN_DEPENDS ${catkin_deps})
include_directories(include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} ${controllib_INCLUDE_DIRS})
add_executable(${PROJECT_NAME}_node
        include
        src/lateral_control_node.cpp
        src/lateral_control_core.cpp
        src/filter_and_estimate.cpp
        src/ipopt_solver_refer_point.cpp
		src/ipopt_solver_refer_point_dynamic.cpp
        src/ipopt_solver_polynomial.cpp
        src/ipopt_solver_spline.cpp
		src/ribbon.cpp
		src/pure_pursuit.cpp src/communication_sub_sim.cpp src/communication_sub_real.cpp src/communication_pub.cpp)
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES} ${IPOPT_LIBRARIES} ${controllib_LIBRARIES})
install(
		TARGETS ${PROJECT_NAME}_node
		EXPORT ${PROJECT_NAME}Export
		ARCHIVE DESTINATION lib
		LIBRARY DESTINATION lib
		RUNTIME DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
		DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
		FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
		)

install(DIRECTORY
		launch config msg script
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
		)
