#ifndef MPC_FRENET_CONTROLLER
#define MPC_FRENET_CONTROLLER

#include "path_tracking.h"
#include <cppad/cppad.hpp>
#include <cppad/ipopt/solve.hpp>
using CppAD::AD;
using Pair_ADd = std::pair<AD<double>, AD<double>>;

class IpoptSolver {
public:
    IpoptSolver() {
        this->steer_next = 0.;
        this->steer_max_abs = 0.;
        this->velocity_next = 0.;
        this->acceleration_next = 0.;
        this->initref_path_.clear();
        this->predict_path_.clear();
        this->p_vehicle_parameter = nullptr;
        this->p_control_parameter = nullptr;
        this->p_frenet_coordinate = nullptr;
        this->p_vehicle_state = nullptr;
        this->p_ecu_report = nullptr;
    }

    virtual ~IpoptSolver() {}

    void init(VehicleParameter *p_vehicle_parameter,
              ControlParameter *p_control_parameter,
              FrenetCoordinate *p_frenet_coordinate,
              anm_msgs::VehicleState *p_vehicle_state,
              control_msgs::Report *p_ecu_report) {
        this->p_vehicle_parameter = p_vehicle_parameter;
        this->p_control_parameter = p_control_parameter;
        this->p_frenet_coordinate = p_frenet_coordinate;
        this->p_vehicle_state = p_vehicle_state;
        this->p_ecu_report = p_ecu_report;
    }

    virtual bool solve(const std::vector<double> &local_path_x,
                       const std::vector<double> &local_path_y,
                       const std::vector<double> &heading,
                       const std::vector<double> &curvature,
                       const std::vector<double> &local_path_s,
                       const std::vector<double> &arc_length)=0;

    inline double getNextSteer() { return steer_next; }
    inline double getMaxAbsSteer() { return steer_max_abs; }
    inline double getNextVelocity() { return velocity_next; }
    inline double getNextAcceleration() { return acceleration_next; }
    inline std::vector<std::vector<double> > *getReferPath() { return &initref_path_; }
    inline std::vector<std::vector<double> > *getPredictPath() { return &predict_path_; }

    std::vector<std::vector<double> > initref_path_;
    std::vector<std::vector<double> > predict_path_;

    VehicleParameter *p_vehicle_parameter;
    ControlParameter *p_control_parameter;
    FrenetCoordinate *p_frenet_coordinate;
    anm_msgs::VehicleState *p_vehicle_state;
    control_msgs::Report *p_ecu_report;

protected:
    double steer_next;
    double steer_max_abs;
    double velocity_next;
    double acceleration_next;
};

class ReferPointIpoptSolver : public IpoptSolver {
public:
    const std::string name = "ReferPointIpoptSolver";
    bool solve(const std::vector<double> &local_path_x,
               const std::vector<double> &local_path_y,
               const std::vector<double> &heading,
               const std::vector<double> &curvature,
               const std::vector<double> &local_path_s,
               const std::vector<double> &arc_length);
private:
    void renewPeriodStep(const std::vector<double> &curvature);
    void delayProcessing();
    void selectReferPoints(const std::vector<double> &local_path_x,
                           const std::vector<double> &local_path_y,
                           const std::vector<double> &heading,
                           const std::vector<double> &local_path_s,
                           const std::vector<double> &arc_length);
    bool kineticSolve();
    bool dynamicSolve();
private:
    double x_init;
    double y_init;
    double yaw_init;
    double speed;
    double angle;
};

class PolynomialIpoptSolver : public IpoptSolver {
public:
    const std::string name = "PolynomialIpoptSolver";
    bool solve(const std::vector<double> &local_path_x,
               const std::vector<double> &local_path_y,
               const std::vector<double> &heading,
               const std::vector<double> &curvature,
               const std::vector<double> &local_path_s,
               const std::vector<double> &arc_length);
public:
    Polynomial poly;
};

class SplineIpoptSolver : public IpoptSolver {
public:
    const std::string name = "SplineIpoptSolver";
    bool solve(const std::vector<double> &local_path_x,
               const std::vector<double> &local_path_y,
               const std::vector<double> &heading,
               const std::vector<double> &curvature,
               const std::vector<double> &local_path_s,
               const std::vector<double> &arc_length);
    std::vector<double> path_kappa;
public:
    tk::spline x_spline;
    tk::spline y_spline;
    tk::spline k_spline;
};

#endif /* MPC_FRENET_CONTROLLER */
