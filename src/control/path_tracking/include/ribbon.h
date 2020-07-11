//
// Created by yao on 20-5-29.
//

#ifndef PATH_TRACKING_RIBBON_H
#define PATH_TRACKING_RIBBON_H

#include "path_tracking.h"

class Ribbon {
public:
    Ribbon() : steering(0.) {}
    bool solve(const std::vector<double> &local_path_x,
               const std::vector<double> &local_path_y,
               const double &path_length,
               double &steer_next);
    inline std::vector<std::vector<double> > *getPredictPath() { return &predict_path_; }

    RibbonParams params;
private:
    double calculatePointCurvature(int i, std::string direction);
    double bestSteering(double cmin, double cmax);
private:
    std::vector<std::vector<double> > predict_path_;
    std::vector<double> local_path_x;
    std::vector<double> local_path_y;
    double steering;
    int pace;
};

#endif //PATH_TRACKING_RIBBON_H
