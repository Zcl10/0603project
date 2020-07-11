//
// Created by yangt on 18-11-12.
//

#ifndef LOCAL_PATH_PLANNER_BASIC_FUNCTION_HPP
#define LOCAL_PATH_PLANNER_BASIC_FUNCTION_HPP

#pragma once
#include "geometry_msgs/Pose.h"
#include "lanelet_map_msgs/Way.h"

#include <opt_utils/opt_utils.hpp>
#include <opt_utils/stringprintf.h>

#include <vector>
#include <map>

typedef std::vector<hmpl::State> StatePath;

typedef lanelet_map_msgs::Way Roadnet;

struct PathWithCost {
    PathWithCost()
        : id(0),
          max_curvature(0.0),
          dis_to_max_curvature(std::numeric_limits<double>::infinity()),
          dis_to_obs(0),
          dis_to_vehicle(std::numeric_limits<double>::infinity()),
          bending_energy(std::numeric_limits<double>::infinity()) {
    }
    int id;
    double dis_to_obs;
    double dis_to_vehicle;
    double dis_to_max_curvature;
    double max_curvature;
    double bending_energy;
    StatePath path;

};

/**
 * calculate 2-dim Eculid distance
 * @param x1 : point one's x axis value
 * @param y1 : point one's y axis value
 * @param x2 : point two's x axis value
 * @param y2 : point two's y axis value
 * @return : the Eculid distance
 */
double Distance(double x1, double y1, double x2, double y2);

/**
 * calculate the absolute difference of two angles
 * @param rad1 angle one in radian
 * @param rad2 angle two in radian
 * @return two angle's difference, the range is [0, pi]
 */
double AngleDiffRad(double rad1, double rad2);

/**
 * convert a pose from global frame to local frame
 * @param ref_pose : the reference pose in global frame
 * @param target_pt : te target pose in global frame
 * @return : target pose represented in reference pose frame
 */
geometry_msgs::Point GlobalToLocal(const hmpl::Pose2D &ref_pose,
                                   const geometry_msgs::Point &target_pt);

/**
 * covert a pose frome local frame to global frame
 * @param ref_pose : the reference pose in global frame
 * @param target_pt : the target pose in reference frame
 * @return : the target pose represented in global frame
 */
geometry_msgs::Point LocalToGlobal(const hmpl::Pose2D &ref_pose,
                                   const geometry_msgs::Point &target_pt);

/**
 * a template function to calculate 2-dim Eculid distance
 * @tparam PointType1 : template type required a point type
 * @tparam PointType2 : template type required a point type
 * @param p1 : input point one
 * @param p2 : input point two
 * @return : calculate the distance of two points
 */
template<class PointType1, class PointType2>
double Distance(PointType1 &p1, PointType2 &p2) {
    return Distance(hmpl::xRef(p1),
                    hmpl::yRef(p1),
                    hmpl::xRef(p2),
                    hmpl::yRef(p2));
}

/**
 * a template function to calculate 2-dim vector addition
 * @tparam PointType : template type required a point type
 * @param p1 : input point one
 * @param p2 : input point two
 * @return the result of 2-dim vector addition
 */
//template<class PointType>
//PointType PointAdd(const PointType &p1, const PointType &p2) {
//    PointType result = p1;
//    hmpl::xRef(result) = hmpl::xRef(p1) + hmpl::xRef(p2);
//    hmpl::yRef(result) = hmpl::yRef(p1) + hmpl::yRef(p2);
//    return result;
//}
//
///**
// * a template function to calculate 2-dim vector substraction
// * @tparam PointType : template type required a point type
// * @param p1 : input point one
// * @param p2 : input point two
// * @return : the result of 2-dim vector substraction
// */
//template<class PointType>
//PointType PointSubtract(const PointType &p1, const PointType &p2) {
//    PointType result = p1;
//    hmpl::xRef(result) = hmpl::xRef(p1) - hmpl::xRef(p2);
//    hmpl::yRef(result) = hmpl::yRef(p1) - hmpl::yRef(p2);
//    return result;
//}

//template<class PointType>
//double angle(const PointType &p1, const PointType &p2) {
//    const double dy = hmpl::yRef(p2) - hmpl::yRef(p1);
//    const double dx = hmpl::xRef(p2) - hmpl::yRef(p1);
//    return atan2(dy, dx);
//}

template<class BasicType>
char sign(BasicType x) {
    if (x >= 0) {
        return 1;
    } else {
        return -1;
    }
}

template<class BasicType1, class BasicType2>
bool isSameSign(BasicType1 x1, BasicType2 x2) {
    if (sign(x1) == sign(x2)) {
        return true;
    } else {
        return false;
    }
}

#endif //LOCAL_PATH_PLANNER_BASIC_FUNCTION_HPP
