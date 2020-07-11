//
// Created by yao on 19-10-9.
//

#ifndef PATH_TRACKING_EKF_ESTIMATE_H
#define PATH_TRACKING_EKF_ESTIMATE_H

#include <iostream>
#include <deque>
#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/Dense"

struct State {
    Eigen::MatrixXd A;
    Eigen::VectorXd x_;
    Eigen::VectorXd z;
    Eigen::VectorXd x;
    State(Eigen::MatrixXd A, Eigen::VectorXd x_, Eigen::VectorXd z, Eigen::VectorXd x)
        : A(A), x_(x_), z(z), x(x) {}
};

class EKFEstimate {
public:
    Eigen::VectorXd x;
    Eigen::MatrixXd P;
public:
    EKFEstimate();
    void inputMeasureState(double *meas);
private:
    Eigen::VectorXd x_;
    Eigen::MatrixXd P_;
    Eigen::VectorXd q;
    Eigen::MatrixXd Q;
    Eigen::VectorXd r;
    Eigen::MatrixXd R;
private:
    const bool use_measures;
    double timer;
    double last_heading;
    double last_vx;
    double last_vy;

    std::deque<State *> history;
    int k;
};

class KalmanFilter {
public:
    KalmanFilter();
    void inputMeasureState(double velocity, double acceleration, double dt);
    double getVelocity() { return x[0]; }
    double getAcceleration() { return x[1]; }
    double getJerk() { return x[2]; }
private:
    Eigen::Vector3d x;
    Eigen::Matrix3d P;
    Eigen::Vector3d x_;
    Eigen::Matrix3d P_;
    Eigen::Matrix3d Q;
    Eigen::Matrix2d R;
    Eigen::MatrixXd H;
};

#endif //PATH_TRACKING_EKF_ESTIMATE_H
