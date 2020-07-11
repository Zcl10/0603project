//
// Created by ldr on 2020/5/31.
//

#include "pure_pursuit.h"

bool PurePursuit::solve(const std::vector<double> &local_path_x,
                        const std::vector<double> &local_path_y,
                        const double &lateral_error,
                        const double &velocity,
                        double &steer_next) {
    ROS_INFO_STREAM("pure_pursuit controller");
    if (local_path_x.size() < 2 || local_path_x.size() != local_path_y.size()) {
        ROS_ERROR_STREAM("pure_pursuit false");
        return false;
    }
    this->local_path_x = local_path_x;
    this->local_path_y = local_path_y;
    this->lookahead_distance = std::max(params.k * velocity, 1.5 * fabs(lateral_error));
    std::pair<double, double> goal;
    if (calculateDistance(local_path_x.front(), local_path_y.front()) > lookahead_distance)
        goal = {local_path_x[1], local_path_y[1]};
    else {
        if (calculateDistance(local_path_x.back(), local_path_y.back()) < lookahead_distance)
            ToolKit::fillPoints(this->local_path_x, this->local_path_y, 20.);
        int near_index = findWayPoint();
        goal = findGoalPoint(near_index);
    }
    //利用纯跟踪方法进行计算
    steer_curv = goal.second / (2 * lookahead_distance * lookahead_distance);
    if (steer_curv > params.max_steer) {
        steer_curv = params.max_steer;
    }
    if (steer_curv < -params.max_steer) {
        steer_curv = -params.max_steer;
    }
    steer_next = steer_curv;
    return true;
}
int PurePursuit::findWayPoint() {
    int goal_point_index = local_path_x.size() - 1;
    //找出目标路点
    for (int i = 0; i + 1 < local_path_x.size(); ++i) {
        double min_distance = calculateDistance(local_path_x.at(i), local_path_y.at(i));
        double max_distance = calculateDistance(local_path_x.at(i + 1), local_path_y.at(i + 1));
        if (min_distance <= lookahead_distance && max_distance > lookahead_distance)
            goal_point_index = i;
    }
    return goal_point_index;
}
std::pair<double, double> PurePursuit::findGoalPoint(int index) {
    if (index == local_path_x.size() - 1)
        return std::make_pair(local_path_x.back(), local_path_y.back());
    // (local_path_x[index], local_path_y[index]), (local_path_x[index+1], local_path_y[index+1])
    std::pair<double, double> point1 = {local_path_x[index], local_path_y[index]};
    std::pair<double, double> point2 = {local_path_x[index + 1], local_path_y[index + 1]};
    double dis = calculateDistance((point1.first + point2.first) / 2., (point1.second + point2.second) / 2.);
    while (fabs(dis - lookahead_distance) >= 0.01) {
        if (dis > lookahead_distance)
            point2 = {(point1.first + point2.first) / 2., (point1.second + point2.second) / 2.};
        else if (dis < lookahead_distance)
            point1 = {(point1.first + point2.first) / 2., (point1.second + point2.second) / 2.};
        dis = calculateDistance((point1.first + point2.first) / 2., (point1.second + point2.second) / 2.);
    }
    return std::make_pair((point1.first + point2.first) / 2., (point1.second + point2.second) / 2.);
}
