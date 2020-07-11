#ifndef MPC_CONTROLLER_SRC_MPC_CONTROLLER_CORE_H_
#define MPC_CONTROLLER_SRC_MPC_CONTROLLER_CORE_H_

#include "path_tracking.h"
#include "path_tracking/observer.h"

#include "ipopt_solver.h"
#include "ribbon.h"
#include "pure_pursuit.h"

enum ControllerId { ReferPoint, Polynomial, Spline };

class LateralControlCore {
public:
    LateralControlCore();
    ~LateralControlCore();
    void run();
    double steer_next;
    double max_abs_steer;
    double velocity_next;
    double acceleration_next;

private:
    ros::NodeHandle nh, pnh;
    ros::Subscriber sim_path_sub, sim_vehicleState_sub, sim_steering_sub;
    ros::Subscriber ecudatareport_sub, path_sub, pose_sub, imu_sub, ins_sub;

    std::unique_ptr<IpoptSolver> p_ipopt_solver = nullptr;
    Ribbon ribbon;
    PurePursuit pp;
    std::vector<std::vector<double> >* ptr_refer_path_ = nullptr;
    std::vector<std::vector<double> >* ptr_predict_path_ = nullptr;

    VehicleParameter vehicle_parameter;
    ControlParameter control_parameter;
    FrenetCoordinate frenet_coordinate;

    plan2control_msgs::TrajectoryPtr p_trajectory;
    anm_msgs::VehicleState vehicle_state;
    control_msgs::Report ecu_report;

    std::string rviz_frame;
    bool path_forward;

private:
    void callbackFromPythonSimPath(const plan2control_msgs::TrajectoryPtr &p_msg);
    void callbackFromWayPointsSim(const nav_msgs::Path &msg);
    void callbackVehicleStateSim(const anm_msgs::VehicleState &msg);
    void callbackFromSteeringSim(const dbw_mkz_msgs::SteeringReport &msg);

    void callbackFromWayPoints(const plan2control_msgs::TrajectoryPtr &p_msg);
    void callbackEcuDataReport(const control_msgs::Report &msg);
    void callbackVehiclePose(const sensor_driver_msgs::GpswithHeading &msg);
    void callbaskInsVelocity(const sensor_driver_msgs::InsVelocity &msg);
    void callbackImuData(const sensor_msgs::Imu &msg);

    void parametersInit();
    void rosTopicInit();
    void controllerInit();

    void messagePublish();
    void sendMessageToRviz(const std::vector<double> &local_path_x, const std::vector<double> &local_path_y);

    bool wayPoint2VehicleCoords(std::vector<double> *ptr_local_path_x,
                                std::vector<double> *ptr_local_path_y);
    bool calculateTrackingError(const std::vector<double> &local_path_s,
                                const std::vector<double> &local_path_x,
                                const std::vector<double> &local_path_y);
private:
    // params
    int pp_id_;
    int ribbon_id_;
    int ipopt_id_;
    std::string traj_topic_;
    std::string gps_topic_;
    std::string steer_topic_;
    std::string tracking_mode_;

    bool vrep_sim_enable_;
    bool python_sim_enable_;
    bool rviz_enable_;

    TimeHandle ecu_;
    TimeHandle path_;
    TimeHandle pose_;
    TimeHandle imu_;
    TimeHandle ins_;
};
#endif /* MPC_CONTROLLER_SRC_MPC_CONTROLLER_CORE_H_ */
