//
// Created by yao on 20-5-29.
//

#include "ribbon.h"

bool Ribbon::solve(const std::vector<double> &local_path_x,
                   const std::vector<double> &local_path_y,
                   const double &path_length,
                   double &steer_next) {
    ROS_INFO_STREAM("Ribbon controller");
    this->local_path_x = local_path_x;
    this->local_path_y = local_path_y;
    if (this->local_path_x.size() < 2 || this->local_path_x.size() != this->local_path_y.size()) {
        ROS_ERROR_STREAM("Ribbon false");
        return false;
    }
    if (path_length < 10.)
        ToolKit::fillPoints(this->local_path_x, this->local_path_y, 20.);
    int i = 0, pointNum = this->local_path_x.size();
    double length = 0;
    for (int m = 0; m + 1 < pointNum; ++m) {
        length += sqrt(pow(this->local_path_x.at(m + 1) - this->local_path_x.at(m), 2)
                           + pow(this->local_path_y.at(m + 1) - this->local_path_y.at(m), 2));
        if (length >= params.distance) {
            if (m == 0) {
                ROS_WARN("-----This path is too long, try a shorter one!-----");
                pace = 1;
            } else {
                pace = m + 1;
            }
            break;
        }
    }
    /* TODO pointNum必须始终减小，防止道路交叉时车辆找到已经驶过的路点;但是用static是不行的，重新仿真会记住最后点。有待完善。
    static int exPointNum = pointNum;
    if(pointNum>=exPointNum)
        i = pointNum-exPointNum;
    else
        exPointNum = pointNum;*/
    double cmin = -9999, cmax = 9999;
    for (; i + 1 < pointNum; i += 2 * pace) {
        if (this->local_path_x.at(i) > 0) {
            double sum = 0;
            for (int m = 0; m + 1 <= i; ++m) {
                sum += sqrt(pow(this->local_path_x.at(m + 1) - this->local_path_x.at(m), 2)
                                + pow(this->local_path_y.at(m + 1) - this->local_path_y.at(m), 2));
            }
            double cL = calculatePointCurvature(i, "left");
            double cR = calculatePointCurvature(i, "right");
            //从车前而且左侧cur大于右侧cur开始计算，处理车在路外的情况。
            //防止选取的第一个点太近。如果不考虑延迟，可考虑设置参数first_point_distance = 2;若延迟为1s，可考虑设为5。
            if (cL > cR && sum >= params.first_point_distance)
                break;
            //如果没有符合条件的i，输出最后一点。
            if (i + 2 * pace > pointNum - 1) {
                i = pointNum - 2;
                break;
            }
        }
    }
    for (int j = i; j + 1 < pointNum; j += pace) {
        double cL = calculatePointCurvature(j, "left");
        double cR = calculatePointCurvature(j, "right");
        if (cR >= cmin && cR < cmax)
            cmin = cR;
        if (cL <= cmax && cL > cmin)
            cmax = cL;
        if (cL < cmin || cR > cmax || cL <= cR) {
            steering = bestSteering(cmin, cmax);
            break;
        }
        //如果下一个点已经过了路径尽头，那么立即计算最后一点并输出。
        if (j + pace > pointNum - 1) {
            cL = calculatePointCurvature(pointNum - 2, "left");
            cR = calculatePointCurvature(pointNum - 2, "right");
            if (cR >= cmin && cR < cmax)
                cmin = cR;
            if (cL <= cmax && cL > cmin)
                cmax = cL;
            steering = bestSteering(cmin, cmax);
            break;
        }
    }
    steer_next = steering;
    predict_path_.clear();
    double velocity = 3.;
    double dt = 0.1;
    int R;
    if (fabs(steering) < 0.0001) {
        R = 10000;
        if (steering < 0)
            R *= -1;
    } else
        R = 1 / steering;
    for (int i = 0; i < 20; i++) {
        double x = R * sin(i * velocity * steering * dt);
        double y = R * (1 - cos(i * velocity * steering * dt));
        predict_path_.emplace_back(std::vector<double>{x, y, 0.});
    }
    return true;
}

double Ribbon::calculatePointCurvature(int i, std::string direction) {
    std::pair<double, double> v;
    v.first = local_path_x.at(i + 1) - local_path_x.at(i);
    v.second = local_path_y.at(i + 1) - local_path_y.at(i);
    double l = sqrt(pow(v.first, 2) + pow(v.second, 2));
    std::pair<double, double> orthogonal_v = std::make_pair(v.second / l, v.first / l);
    if (direction == "left")
        orthogonal_v.first *= -1;
    else if (direction == "right")
        orthogonal_v.second *= -1;
    std::pair<double, double> point;
    point.first = local_path_x.at(i) + params.road_width / 2 * orthogonal_v.first;
    point.second = local_path_y.at(i) + params.road_width / 2 * orthogonal_v.second;

    double x = point.first;
    double y = point.second;
    double cur;
    double numerator = 2 * cos(atan(x / y));
    double denominator = sqrt(pow(x, 2) + pow(y, 2));
    cur = numerator / denominator;
    if (y > 0)
        return cur;
    else if (y < 0)
        return -cur;
}

//尽可能少调整转角，可以防止过于贴近路边造成转向时反向调整。
double Ribbon::bestSteering(double cmin, double cmax) {
    double curvature_limit = fabs(params.max_steer);
    if (cmin < -curvature_limit) cmin = -curvature_limit;
    if (cmax < -curvature_limit) cmax = -curvature_limit;
    if (cmin > curvature_limit) cmin = curvature_limit;
    if (cmax > curvature_limit) cmax = curvature_limit;
    // last control value
    if (steering >= cmax)
        return cmax;
    else if (steering <= cmin)
        return cmin;
    else
        return steering;
}