# CMake generated Testfile for 
# Source directory: /home/bit2/0603_project/tang_ws/src/planning/dependent_package/opt_solver
# Build directory: /home/bit2/0603_project/tang_ws/build/opt_solver
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_opt_solver_gtest_quadratic_cost_function_test "/home/bit2/0603_project/tang_ws/build/opt_solver/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/bit2/0603_project/tang_ws/build/opt_solver/test_results/opt_solver/gtest-quadratic_cost_function_test.xml" "--return-code" "/home/bit2/0603_project/tang_ws/devel/.private/opt_solver/lib/opt_solver/quadratic_cost_function_test --gtest_output=xml:/home/bit2/0603_project/tang_ws/build/opt_solver/test_results/opt_solver/gtest-quadratic_cost_function_test.xml")
add_test(_ctest_opt_solver_gtest_nlp_solver_test "/home/bit2/0603_project/tang_ws/build/opt_solver/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/bit2/0603_project/tang_ws/build/opt_solver/test_results/opt_solver/gtest-nlp_solver_test.xml" "--return-code" "/home/bit2/0603_project/tang_ws/devel/.private/opt_solver/lib/opt_solver/nlp_solver_test --gtest_output=xml:/home/bit2/0603_project/tang_ws/build/opt_solver/test_results/opt_solver/gtest-nlp_solver_test.xml")
subdirs(gtest)
