//
// Created by ldr on 2020/5/31.
//

#ifndef ZW_WS_PURE_PURSUIT_H
#define ZW_WS_PURE_PURSUIT_H

#include "path_tracking.h"

class PurePursuit {
public:
    PurePursuit() : steer_curv(0.) {}
    bool solve(const std::vector<double> &local_path_x,
                   const std::vector<double> &local_path_y,
                   const double &lateral_error,
                   const double &velocity,
                   double &steer_next);
    PPParams params;
private:
    inline double calculateDistance(const double &x1, const double &y1) { return sqrt(pow(x1, 2) + pow(y1, 2)); }
    int findWayPoint();
    std::pair<double, double> findGoalPoint(int index);

private:
    std::vector<double> local_path_x;
    std::vector<double> local_path_y;
    double steer_curv;
    double lookahead_distance;
};

#endif //ZW_WS_PURE_PURSUIT_H
