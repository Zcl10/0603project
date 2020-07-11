cmake_minimum_required(VERSION 2.8.3)
project(constrained_speed)

add_compile_options(-std=c++11)

set(catkin_deps
        roscpp
        plan2control_msgs
        speed_debug_msgs
        lanelet_map_msgs
        control_msgs
        movobsplan_msgs
        dbw_mkz_msgs
        anm_msgs
        )

find_package(catkin REQUIRED
        COMPONENTS
        rosparam_handler
        dynamic_reconfigure
        ${catkin_deps}
        )
find_package(controllib REQUIRED)

generate_ros_parameter_files(cfg/cs_method2.params)

catkin_package(
        INCLUDE_DIRS include
        CATKIN_DEPENDS ${catkin_deps}
        #  CATKIN_DEPENDS other_catkin_pkg
        #  DEPENDS system_lib
)

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${controllib_INCLUDE_DIRS}
)

add_executable(constrained_speed
        include
        src/ConstrainedSpeedNode.cpp
        src/CSMethod2.cpp
        )

add_dependencies(constrained_speed
        ${PROJECT_NAME}_gencfg
        )

target_link_libraries(constrained_speed
        ${catkin_LIBRARIES}
        ${controllib_LIBRARIES}
        glog
        )

install(
        TARGETS constrained_speed
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
        launch cfg
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
        )

if (CATKIN_ENABLE_TESTING)
    find_package(rostest REQUIRED)
    add_rostest_gtest(tests_constrained_speed test/constrained_speed.test test/test.cpp)
    target_link_libraries(tests_constrained_speed ${catkin_LIBRARIES})
endif ()
