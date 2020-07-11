//
// Created by yao on 19-10-21.
//

#include "filter_and_estimate.h"

EKFEstimate::EKFEstimate() : use_measures(true), timer(0.), k(41) {
    this->x = Eigen::VectorXd::Zero(8);
    this->P = Eigen::MatrixXd::Zero(8, 8);
    this->x_ = Eigen::VectorXd::Zero(8);
    this->P_ = Eigen::MatrixXd::Zero(8, 8);

    this->q = Eigen::VectorXd::Zero(8);
    this->Q = Eigen::MatrixXd::Identity(8, 8);

    this->r = Eigen::VectorXd::Zero(8);
    this->R = Eigen::MatrixXd::Identity(8, 8);
//    this->R.block(5, 5, 3, 3) = 10 * Eigen::Matrix3d::Identity();
}

/** @brief
 * Vehicle speed and acceleration estimate.
 * Besides X and Y, other states satisfy vehicle coordinate. To be specific, front is x+, left is y+, counter-clock is heading+.
 * @param meas X, Y, Theta, vx, vy, wz, vxd, vyd.
 */
void EKFEstimate::inputMeasureState(double *meas) {

    Eigen::VectorXd z_meas(8);
    z_meas << meas[0], meas[1], meas[2], meas[3], meas[4], meas[5], meas[6], meas[7];
    double dt = meas[8];
    meas[6] = (meas[3] - last_vx) / dt;
    meas[7] = (meas[4] - last_vy) / dt;
    timer += dt;
    if (timer >= 60 || timer < 0)
        timer = 0.;
    if (timer < 0.5 || use_measures) {
        this->x << meas[0], meas[1], meas[2], meas[3], meas[4], meas[5], meas[6], meas[7];
        last_heading = meas[2];
        last_vx = meas[3];
        last_vy = meas[4];
        return;
    }

    if (meas[2] - last_heading > M_PI)
        this->x[2] += 2 * M_PI;
    else if (meas[2] - last_heading < -M_PI)
        this->x[2] -= 2 * M_PI;
    last_heading = meas[2];
    last_vx = meas[3];
    last_vy = meas[4];

    double c = cos(x[2]);
    double s = sin(x[2]);
    double dt2 = dt * dt / 2.;

    Eigen::MatrixXd A = Eigen::MatrixXd::Identity(8, 8);
    A.block(0, 3, 2, 5) << dt * c, -dt * s, 0., dt2 * c, -dt2 * s, dt * s, dt * c, 0., dt2 * s, dt2 * c;
    A.block(2, 5, 3, 3) = dt * Eigen::Matrix3d::Identity();

    x_ = A * x;
    P_ = A * P * A.transpose() + Q;

    Eigen::MatrixXd H = Eigen::MatrixXd::Identity(8, 8);
    Eigen::MatrixXd S = H * P_ * H.transpose() + R;
    Eigen::MatrixXd Kg = P_ * H.transpose() * S.inverse();
    x = x_ + Kg * (z_meas - H * x_);
    P = (Eigen::MatrixXd::Identity(8, 8) - Kg * H) * P_;

    return;

    State *current_state = new State(A, x_, z_meas, x);
    history.push_back(current_state);
    while (history.size() > k) {
        delete history.front();
        history.front() = nullptr;
        history.pop_front();
    }

    if (history.size() < k)
        return;

    Eigen::VectorXd q_mean = Eigen::VectorXd::Zero(8);
    Eigen::VectorXd r_mean = Eigen::VectorXd::Zero(8);
    for (int i = 1; i < history.size(); ++i) {
        State *s0 = history[i - 1];
        State *s1 = history[i];
        q_mean += (s1->x - s1->A * s0->x);
        r_mean += (s1->z - s1->x);
    }
    q_mean /= (history.size() - 1);
    r_mean /= (history.size() - 1);

    Eigen::MatrixXd Q_vari = Eigen::MatrixXd::Zero(8, 8);
    Eigen::MatrixXd R_vari = Eigen::MatrixXd::Zero(8, 8);
    for (int i = 1; i < history.size(); ++i) {
        State *s0 = history[i - 1];
        State *s1 = history[i];
        Eigen::VectorXd temp1 = (s1->x - s1->A * s0->x) - q_mean;
        Q_vari += (temp1 * temp1.transpose());
        Eigen::VectorXd temp2 = (s1->z - s1->x) - r_mean;
        R_vari += (temp2 * temp2.transpose());
    }
    Q_vari /= (history.size() - 1);
    R_vari /= (history.size() - 1);

    std::cout << q_mean << std::endl;
    std::cout << Q_vari << std::endl;
    std::cout << r_mean << std::endl;
    std::cout << R_vari << std::endl;

    q = (1. - 1. / k) * q + 1. / k * q_mean;
    r = (1. - 1. / k) * r + 1. / k * r_mean;
    Q = (1. - 1. / k) * Q + 1. / k * Q_vari;
    R = (1. - 1. / k) * R + 1. / k * R_vari;
}

KalmanFilter::KalmanFilter() {
    this->x = Eigen::Vector3d::Zero();
    this->P = Eigen::Matrix3d::Zero();
    this->x_ = Eigen::Vector3d::Zero();
    this->P_ = Eigen::Matrix3d::Zero();
    this->Q << 0.1, 0, 0, 0, 0.1, 0, 0, 0, 0.1;
    this->R << 0.04, 0, 0, 0.36;
    Eigen::MatrixXd H(2, 3);
    H << 1, 0, 0,
        0, 1, 0;
    this->H = H;
}

void KalmanFilter::inputMeasureState(double velocity, double acceleration, double dt) {
    Eigen::Matrix3d A;
    A << 1, dt, dt * dt / 2,
        0, 1, dt,
        0, 0, 1;
    x_ = A * x;
    P_ = A * P * A.transpose() + Q;
    Eigen::MatrixXd S = H * P_ * H.transpose() + R;
    Eigen::MatrixXd Kg = P_ * H.transpose() * S.inverse();
    Eigen::Vector2d z_meas;
    z_meas << velocity, acceleration;
    x = x_ + Kg * (z_meas - H * x_);
    P = (Eigen::MatrixXd::Identity(3, 3) - Kg * H) * P_;
}