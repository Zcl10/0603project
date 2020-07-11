# CMake generated Testfile for 
# Source directory: /home/bit2/0603_project/tang_ws/src/planning/dependent_package/car_model
# Build directory: /home/bit2/0603_project/tang_ws/build/car_model
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_car_model_gtest_car "/home/bit2/0603_project/tang_ws/build/car_model/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/bit2/0603_project/tang_ws/build/car_model/test_results/car_model/gtest-car.xml" "--return-code" "/home/bit2/0603_project/tang_ws/devel/.private/car_model/lib/car_model/car --gtest_output=xml:/home/bit2/0603_project/tang_ws/build/car_model/test_results/car_model/gtest-car.xml")
subdirs(gtest)
