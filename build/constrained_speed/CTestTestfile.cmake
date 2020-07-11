# CMake generated Testfile for 
# Source directory: /home/bit2/0603_project/tang_ws/src/control/constrained_speed
# Build directory: /home/bit2/0603_project/tang_ws/build/constrained_speed
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_constrained_speed_rostest_test_constrained_speed.test "/home/bit2/0603_project/tang_ws/build/constrained_speed/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/bit2/0603_project/tang_ws/build/constrained_speed/test_results/constrained_speed/rostest-test_constrained_speed.xml" "--return-code" "/opt/ros/kinetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/bit2/0603_project/tang_ws/src/control/constrained_speed --package=constrained_speed --results-filename test_constrained_speed.xml --results-base-dir \"/home/bit2/0603_project/tang_ws/build/constrained_speed/test_results\" /home/bit2/0603_project/tang_ws/src/control/constrained_speed/test/constrained_speed.test ")
subdirs(gtest)
