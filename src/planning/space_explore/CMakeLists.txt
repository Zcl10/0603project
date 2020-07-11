cmake_minimum_required(VERSION 2.8.3)

project(space_explore)

## Add support for C++11, supported in ROS Kinetic and newer
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_STANDARD 11)

set(catkin_deps
  roscpp
  opt_utils
  roslib
  nav_msgs
  internal_grid_map
  grid_map_ros
  rosparam_handler
  dynamic_reconfigure
  visual_tools
  voronoi
  tinyspline_ros)

find_package(catkin REQUIRED COMPONENTS
  ${catkin_deps})

find_package(OpenCV REQUIRED)

generate_ros_parameter_files(
  cfg/Visual.params    ## for generating parameters header files
)


catkin_package(
  INCLUDE_DIRS include ${CATKIN_DEVEL_PREFIX}/include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS ${catkin_deps}
  DEPENDS OpenCV
)

include_directories(include
  ${OpenCV_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  )

add_library(space_explore
  src/space_explore.cpp
  src/space_explore_visual_tools.cpp
  )

target_link_libraries(space_explore
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES})

set(linked_libs
  ${PROJECT_NAME}
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES})


catkin_add_gtest(holonomic_astar_test
  tests/holonomic_test.cpp)

target_link_libraries(holonomic_astar_test
  ${linked_libs})


#add_executable(demo_holonomic
#    src/holonomic_demo.cpp)
#target_link_libraries(demo_holonomic
#    ${linked_libs})


add_executable(modified_path_node
  src/global_path_node.cpp)

target_link_libraries(modified_path_node
  ${linked_libs})

add_executable(visualization_node
  src/visualization_node.cpp)

target_link_libraries(visualization_node
  ${linked_libs})

add_dependencies(visualization_node space_explore_genparam) ## To generate SomeParamters.h file
add_dependencies(visualization_node space_explore_gencfg) ## To generate SomeConfig.h file

#add_dependencies(demo_holonomic space_explore_genparam) ## To generate SomeParamters.h file
#add_dependencies(demo_holonomic space_explore_gencfg) ## To generate SomeConfig.h file

add_dependencies(modified_path_node space_explore_genparam) ## To generate SomeParamters.h file
add_dependencies(modified_path_node space_explore_gencfg) ## To generate SomeConfig.h file
