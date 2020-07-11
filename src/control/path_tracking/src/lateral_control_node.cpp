// ROS Includes
#include "lateral_control_core.h"
int main(int argc, char **argv) {
    ros::init(argc, argv, "nmpc");
    LateralControlCore mpc;
    mpc.run();
    return 0;
}


