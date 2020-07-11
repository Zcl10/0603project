//
// Created by yangt on 18-11-12.
//
#include <geometry_msgs/Pose.h>
#include "common_function.hpp"

double Distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double AngleDiffRad(double rad1, double rad2) {
    double result = fabs(rad1 - rad2);
    result = result > M_PI ? (2 * M_PI - result) : result;
    return fabs(result);
}

geometry_msgs::Point LocalToGlobal(const hmpl::Pose2D &ref_pose,
                                   const geometry_msgs::Point &target_pt) {

    geometry_msgs::Point result;
    result.x = (target_pt.x * cos(ref_pose.orientation) -
            target_pt.y * sin(ref_pose.orientation)) + ref_pose.position.x;
    result.y = (target_pt.x * sin(ref_pose.orientation) +
            target_pt.y * cos(ref_pose.orientation)) + ref_pose.position.y;
    return result;
}

geometry_msgs::Point GlobalToLocal(const hmpl::Pose2D &ref_pose,
                                   const geometry_msgs::Point &target_pt) {

    geometry_msgs::Point result;
    double deltaX = target_pt.x - ref_pose.position.x;
    double deltaY = target_pt.y - ref_pose.position.y;
    result.x = deltaX * cos(ref_pose.orientation) +
            deltaY * sin(ref_pose.orientation);
    result.y = -deltaX * sin(ref_pose.orientation) +
            deltaY * cos(ref_pose.orientation);
    return result;
}
