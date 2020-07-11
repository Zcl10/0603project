# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/usr/local/include;/usr/include/eigen3;/usr/include".split(';') if "${prefix}/include;/usr/local/include;/usr/include/eigen3;/usr/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;roslib;nav_msgs;opt_utils".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lopt_solver;/usr/local/lib/libceres.so.1.12.0".split(';') if "-lopt_solver;/usr/local/lib/libceres.so.1.12.0" != "" else []
PROJECT_NAME = "opt_solver"
PROJECT_SPACE_DIR = "/home/bit2/0603_project/tang_ws/install"
PROJECT_VERSION = "0.0.1"
