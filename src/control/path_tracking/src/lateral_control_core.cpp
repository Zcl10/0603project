#include "lateral_control_core.h"

LateralControlCore::LateralControlCore() {
    this->nh = ros::NodeHandle();
    this->pnh = ros::NodeHandle("~");
    parametersInit();
    rosTopicInit();
    controllerInit();
}

LateralControlCore::~LateralControlCore() {}

void LateralControlCore::parametersInit() {
    bool get_param = true;

    get_param &= pnh.getParam("pp_id", this->pp_id_);
    get_param &= pnh.getParam("ribbon_id", this->ribbon_id_);
    get_param &= pnh.getParam("ipopt_id", this->ipopt_id_);
    get_param &= pnh.getParam("traj_topic", this->traj_topic_);
    get_param &= pnh.getParam("gps_topic", this->gps_topic_);
    get_param &= pnh.getParam("steer_topic", this->steer_topic_);
    get_param &= pnh.getParam("tracking_mode", this->tracking_mode_);
    get_param &= pnh.getParam("vrep_sim_enable", this->vrep_sim_enable_);
    get_param &= pnh.getParam("python_sim_enable", this->python_sim_enable_);
    get_param &= pnh.getParam("rviz_enable", this->rviz_enable_);
    get_param &= pnh.getParam("state_elapse_time_ms", this->ecu_.elapse_time_);
    get_param &= pnh.getParam("path_elapse_time_ms", this->path_.elapse_time_);
    get_param &= pnh.getParam("pose_elapse_time_ms", this->pose_.elapse_time_);
    get_param &= pnh.getParam("imu_elapse_time_ms", this->imu_.elapse_time_);
    get_param &= pnh.getParam("ins_elapse_time_ms", this->ins_.elapse_time_);

    get_param &= pnh.getParam("VehicleParameter/r", vehicle_parameter.r);
    get_param &= pnh.getParam("VehicleParameter/L", vehicle_parameter.L);
    get_param &= pnh.getParam("VehicleParameter/B", vehicle_parameter.B);
    get_param &= pnh.getParam("VehicleParameter/a", vehicle_parameter.a);
    get_param &= pnh.getParam("VehicleParameter/b", vehicle_parameter.b);
    get_param &= pnh.getParam("VehicleParameter/m", vehicle_parameter.m);
    get_param &= pnh.getParam("VehicleParameter/I", vehicle_parameter.I);
    get_param &= pnh.getParam("VehicleParameter/Cf", vehicle_parameter.Cf);
    get_param &= pnh.getParam("VehicleParameter/Cr", vehicle_parameter.Cr);

    get_param &= pnh.getParam("ControlParameter/dynamic", control_parameter.dynamic);
    get_param &= pnh.getParam("ControlParameter/control_rate", control_parameter.control_rate);
    get_param &= pnh.getParam("ControlParameter/predict_N", control_parameter.predict_N);
    get_param &= pnh.getParam("ControlParameter/sample_time", control_parameter.sample_time);
    get_param &= pnh.getParam("ControlParameter/delay_time", control_parameter.delay_time);
    get_param &= pnh.getParam("ControlParameter/lowest_length", control_parameter.lowest_length);
    get_param &= pnh.getParam("ControlParameter/lowest_velocity", control_parameter.lowest_velocity);
    get_param &= pnh.getParam("ControlParameter/desire_velocity", control_parameter.desire_velocity);
    get_param &= pnh.getParam("ControlParameter/max_acceleration", control_parameter.max_acceleration);
    get_param &= pnh.getParam("ControlParameter/max_deceleration", control_parameter.max_deceleration);
    get_param &= pnh.getParam("ControlParameter/max_steer", control_parameter.max_steer);
    get_param &= pnh.getParam("ControlParameter/max_steer_rate", control_parameter.max_steer_rate);
    get_param &= pnh.getParam("ControlParameter/steer_ratio", control_parameter.steer_ratio);
    get_param &= pnh.getParam("ControlParameter/lateral_acc", control_parameter.lateral_acc);

    get_param &= pnh.getParam("ControlParameter/Weight/vel", control_parameter.weight.vel);
    get_param &= pnh.getParam("ControlParameter/Weight/acc", control_parameter.weight.acc);
    get_param &= pnh.getParam("ControlParameter/Weight/acc_rate", control_parameter.weight.acc_rate);
    get_param &= pnh.getParam("ControlParameter/Weight/cte", control_parameter.weight.cte);
    get_param &= pnh.getParam("ControlParameter/Weight/epsi", control_parameter.weight.epsi);
    get_param &= pnh.getParam("ControlParameter/Weight/steer", control_parameter.weight.steer);
    get_param &= pnh.getParam("ControlParameter/Weight/steer_rate", control_parameter.weight.steer_rate);

    get_param &= pnh.getParam("ControlParameter/max_steer", ribbon.params.max_steer);
    get_param &= pnh.getParam("Ribbon/road_width", ribbon.params.road_width);
    get_param &= pnh.getParam("Ribbon/distance", ribbon.params.distance);
    get_param &= pnh.getParam("Ribbon/first_point_distance", ribbon.params.first_point_distance);

    get_param &= pnh.getParam("ControlParameter/max_steer", pp.params.max_steer);
    get_param &= pnh.getParam("PP/k", pp.params.k);

    if (!get_param) {
        ROS_ERROR("Get params failed");
        ros::shutdown();
    }
}

void LateralControlCore::rosTopicInit() {
    if (vrep_sim_enable_ || python_sim_enable_) {
        //// subscribers
        if (vrep_sim_enable_) {
            if ("global" == tracking_mode_)
                sim_path_sub = nh.subscribe("global_path", 1, &LateralControlCore::callbackFromWayPointsSim, this);
            if ("local" == tracking_mode_)
                sim_path_sub = nh.subscribe(traj_topic_, 1, &LateralControlCore::callbackFromWayPoints, this);
            sim_steering_sub =
                nh.subscribe("vehicle/steering_report", 1, &LateralControlCore::callbackFromSteeringSim, this);
        } else {
            sim_path_sub = nh.subscribe(traj_topic_, 1, &LateralControlCore::callbackFromPythonSimPath, this);
        }
        sim_vehicleState_sub = nh.subscribe("vehicle_state", 1, &LateralControlCore::callbackVehicleStateSim, this);

    } else {
        ecudatareport_sub = nh.subscribe("ecudatareport", 1, &LateralControlCore::callbackEcuDataReport, this);
        path_sub = nh.subscribe(traj_topic_, 1, &LateralControlCore::callbackFromWayPoints, this);
        pose_sub = nh.subscribe(gps_topic_, 1, &LateralControlCore::callbackVehiclePose, this);
        imu_sub = nh.subscribe("imudata", 1, &LateralControlCore::callbackImuData, this);
        ins_sub = nh.subscribe("insvelocity", 1, &LateralControlCore::callbaskInsVelocity, this);
    }
}

void LateralControlCore::controllerInit() {
    if (pp_id_ < 0 && ribbon_id_ < 0 && ipopt_id_ < 0) {
        ROS_ERROR("Get controller failed");
        ros::shutdown();
    }
    if (ipopt_id_ >= 0) {
        if (ReferPoint == ipopt_id_)
            p_ipopt_solver = std::unique_ptr<IpoptSolver>(new ReferPointIpoptSolver());
        else if (Polynomial == ipopt_id_)
            p_ipopt_solver = std::unique_ptr<IpoptSolver>(new PolynomialIpoptSolver());
        else if (Spline == ipopt_id_)
            p_ipopt_solver = std::unique_ptr<IpoptSolver>(new SplineIpoptSolver());
        else {
            ROS_ERROR("Get controller failed");
            ros::shutdown();
        }
        p_ipopt_solver->init(&vehicle_parameter, &control_parameter, &frenet_coordinate, &vehicle_state, &ecu_report);
    }
}

void LateralControlCore::run() {
    ros::Rate loop_rate(control_parameter.control_rate);
    while (ros::ok()) {
        std::cout << std::endl;
        double time_start = ros::Time::now().toSec();
        ros::spinOnce();
        ecu_.is_update &= (ros::WallTime::now().toSec() - ecu_.last_timestamp) * 1000 < ecu_.elapse_time_;
        path_.is_update &= (ros::WallTime::now().toSec() - path_.last_timestamp) * 1000 < path_.elapse_time_;
        pose_.is_update &= (ros::WallTime::now().toSec() - pose_.last_timestamp) * 1000 < pose_.elapse_time_;
        ins_.is_update &= (ros::WallTime::now().toSec() - ins_.last_timestamp) * 1000 < ins_.elapse_time_;
        imu_.is_update &= (ros::WallTime::now().toSec() - imu_.last_timestamp) * 1000 < imu_.elapse_time_;
        std::vector<double> local_path_x, local_path_y;
        bool run_flag = wayPoint2VehicleCoords(&local_path_x, &local_path_y);
        if (!ecu_.is_update || !path_.is_update || !pose_.is_update || !ins_.is_update || !imu_.is_update
            || !run_flag) {
            // path must be updated, because it's in local frame!
            ROS_WARN("Receive delay exceed time! or tf fail!");
            ROS_WARN_STREAM(
                "ecu: " << ecu_.is_update << ", path: " << path_.is_update << " pose: " << pose_.is_update << " imu: "
                        << imu_.is_update << " ins: " << ins_.is_update << " tf: " << run_flag);
            steer_next = velocity_next = acceleration_next = 0.;
            messagePublish();
            loop_rate.sleep();
            continue;
        }

        std::vector<double> local_path_s, arc_length, heading, curvature;
        // search ref points by predictive distance
        double total_t =
            (control_parameter.predict_N * control_parameter.sample_time + control_parameter.delay_time) * 1.2;
        double s_limit =
            (vehicle_state.velocity.linear.x + fabs(control_parameter.max_acceleration) * total_t / 2) * total_t;
        s_limit = std::max(s_limit, control_parameter.lowest_length);
        int truncation = ToolKit::getCurveLength(local_path_x, local_path_y, &local_path_s, &arc_length, s_limit);
        local_path_x.resize(truncation);
        local_path_y.resize(truncation);
        ROS_INFO_STREAM("resize local path to:  " << truncation);
        ToolKit::getHeading(local_path_x, local_path_y, &heading);//TODO: 使用路径点上的四元数航向 车的航向 考虑好坐标转换
        ToolKit::getCurvature(local_path_x, local_path_y, &curvature);//TODO: 更加准确的求曲率的方法
        if (local_path_x.size() < 4 || local_path_x.size() != local_path_y.size()
            || local_path_x.size() != heading.size() || local_path_x.size() != curvature.size()
            || local_path_x.size() != local_path_s.size() || local_path_x.size() != arc_length.size()) {
            ROS_ERROR_STREAM("size: x " << local_path_x.size() << " y " << local_path_y.size());
            ROS_ERROR_STREAM("size: heading " << heading.size() << " curvature " << curvature.size());
            ROS_ERROR_STREAM("size: s " << local_path_s.size() << " arc_length " << arc_length.size());
            ROS_ERROR_STREAM("local_path size error!");
            run_flag = false;
        }

        run_flag &= calculateTrackingError(local_path_s, local_path_x, local_path_y);

        if (run_flag) {
            bool solve_flag = false;
            if (!solve_flag && pp_id_ >= 0) {
                solve_flag = pp.solve(local_path_x,
                                      local_path_y,
                                      frenet_coordinate.d,
                                      ecu_report.motion.velocity,
                                      steer_next);
            }
            if (!solve_flag && ribbon_id_ >= 0) {
                solve_flag = ribbon.solve(local_path_x, local_path_y, local_path_s.back(), steer_next);
                ptr_predict_path_ = ribbon.getPredictPath();
            }
            if (!solve_flag && p_ipopt_solver != nullptr) {
                solve_flag =
                    p_ipopt_solver->solve(local_path_x, local_path_y, heading, curvature, local_path_s, arc_length);
                steer_next = p_ipopt_solver->getNextSteer();
                max_abs_steer = p_ipopt_solver->getMaxAbsSteer();
                velocity_next = p_ipopt_solver->getNextVelocity();
                acceleration_next = p_ipopt_solver->getNextAcceleration();
                ptr_refer_path_ = p_ipopt_solver->getReferPath();
                ptr_predict_path_ = p_ipopt_solver->getPredictPath();
            }
            run_flag = solve_flag;
        } else
            steer_next = velocity_next = acceleration_next = 0.;
        messagePublish();
        if (rviz_enable_)
            sendMessageToRviz(local_path_x, local_path_y);

        double time_cost = (ros::Time::now().toSec() - time_start) * 1000;
        ROS_INFO_STREAM("time_cost: " << time_cost << " ms");

        static ros::Publisher observer_pub = nh.advertise<path_tracking::observer>("observer", 1);
        // To observation
        path_tracking::observer ob_msg;
        ob_msg.header.stamp = ros::Time::now();
        ob_msg.header.frame_id = "observer";
        ob_msg.vehicle_state = vehicle_state;
        ob_msg.ecu_report = ecu_report;
        ob_msg.speed_cmd = 0;
        ob_msg.steer_cmd = steer_next;
        ob_msg.lateral_error = frenet_coordinate.d;
        ob_msg.heading_error = frenet_coordinate.phi * 180 / M_PI;
        ob_msg.time_cost = time_cost;
        observer_pub.publish(ob_msg);
        loop_rate.sleep();
    }

}

bool LateralControlCore::wayPoint2VehicleCoords(std::vector<double> *ptr_local_path_x,
                                                std::vector<double> *ptr_local_path_y) {
    if (p_trajectory == nullptr)
        return false;
    // calculation
    double px = 0;
    double py = 0;
    double psi = 0;
    if ("global" == tracking_mode_) {
        px = vehicle_state.position.x; // unit is already meter.
        py = vehicle_state.position.y;
        psi = vehicle_state.orientation.z;
    } else if ("local" == tracking_mode_) {
        psi = 0;// + vehicle_state.vx * (-vehicle_state.curvature) / vehicle_params.L * path_elapse_time_count;
        px = 0;// + vehicle_state.vx * cos(psi) * path_elapse_time_count;
        py = 0;// + vehicle_state.vx * sin(psi) * path_elapse_time_count;
    } else {
        ROS_ERROR(
            "tracking_mode is not global or local! Use local as default params. Please check the config.yaml to modify...");
    }
    int index_min = -1;
    double min = DBL_MAX;
    for (unsigned int i = 0; i < p_trajectory->points.size(); i++) {
        double delta_x = p_trajectory->points[i].position.x - px;
        double delta_y = p_trajectory->points[i].position.y - py;
        double dist = pow(delta_x, 2) + pow(delta_y, 2);
        if (dist < min) {
            min = dist;
            index_min = i;
        }
    }
    ROS_INFO_STREAM("global_path.size: " << p_trajectory->points.size());
    ROS_INFO_STREAM("index_min is:     " << index_min);
    if (index_min < 0 || index_min + 3 > (int) p_trajectory->points.size())
        return false;
    path_forward = p_trajectory->points.at(index_min).forward;
    ROS_INFO_STREAM("path_forward is: " << (int) path_forward);
    if (!path_forward) { // if reverse
        psi = psi + M_PI;
        if (psi > M_PI) psi = psi - 2 * M_PI;
    }
    for (int j = index_min; j < p_trajectory->points.size(); j++) {
        if (p_trajectory->points.at(j).forward != path_forward) {
            if (ptr_local_path_x->size() <= 3) { // polyfit need at least 4 points, if not, exit.
                ptr_local_path_x->clear();
                path_forward = p_trajectory->points.at(j).forward;
                j--;
                continue;
            }
            ROS_INFO("find the path_forward/reverse switch point:%d", p_trajectory->points.at(j).id);
            break;
        }
        double delta_x = p_trajectory->points[j].position.x - px;
        double delta_y = p_trajectory->points[j].position.y - py;
        double next_x = delta_x * cos(psi) + delta_y * sin(psi);
        double next_y = delta_y * cos(psi) - delta_x * sin(psi);
        if (ptr_local_path_x->empty()
            || ToolKit::calculateDistance(next_x, next_y, ptr_local_path_x->back(), ptr_local_path_y->back()) > 0.01) {
            ptr_local_path_x->emplace_back(next_x);
            ptr_local_path_y->emplace_back(next_y);
        }
    }
    return true;
}

bool LateralControlCore::calculateTrackingError(const std::vector<double> &local_path_s,
                                                const std::vector<double> &local_path_x,
                                                const std::vector<double> &local_path_y) {
    assert(local_path_x.size() == local_path_y.size());
    double min_distance = DBL_MAX;
    int min_index = -1;
    for (int i = 0; i < local_path_x.size(); ++i) {
        double distance = ToolKit::calculateDistance(local_path_x[i], local_path_y[i], 0, 0);
        if (distance < min_distance) {
            min_distance = distance;
            min_index = i;
        }
    }
    if (min_index < 0 || min_index >= local_path_x.size() - 1)
        return false;
    int rear_index = std::max(0, min_index - 1);
    double rear_distance =
        ToolKit::calculateDistance(local_path_x[rear_index], local_path_y[rear_index], 0, 0);
    int front_index = std::min(int(local_path_x.size() - 1), min_index + 1);
    double front_distance =
        ToolKit::calculateDistance(local_path_x[front_index], local_path_y[front_index], 0, 0);
    int i = std::max(rear_distance < front_distance ? min_index - 1 : min_index, 0);
    double l = ToolKit::calculateDistance(local_path_x[i], local_path_y[i], local_path_x[i + 1], local_path_y[i + 1]);
    std::pair<double, double> vec1 = {local_path_x[i] - 0., local_path_y[i] - 0.};
    std::pair<double, double> vec2 = {local_path_x[i + 1] - local_path_x[i], local_path_y[i + 1] - local_path_y[i]};
    frenet_coordinate.s = local_path_s[i] + ToolKit::calculateDotProduct(vec1, vec2) / l;
    // When Kappa is left positive and right negative, On road left d is positive, road right d is negative
    frenet_coordinate.d = ToolKit::calculateCrossProduct(vec1, vec2) / l;
    // On road counter-clockwise is positive,clockwise is negative
    frenet_coordinate.phi = 0. - atan2(local_path_y[i + 1] - local_path_y[i], local_path_x[i + 1] - local_path_x[i]);
    ToolKit::normalizeAngle(frenet_coordinate.phi);
    return true;
}
