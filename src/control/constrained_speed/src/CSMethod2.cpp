#include <deque>
#include "CSMethod2.hpp"
namespace constrained_speed {

    CSMethod2::CSMethod2(ros::NodeHandle node_handle, ros::NodeHandle private_node_handle)
        : reconfigSrv_{private_node_handle}, params_{private_node_handle} {

        this->nh_ = node_handle;
        this->private_nh_ = private_node_handle;

//        glogInit();
        paramsInit();
        setHandle();

        this->reconfigSrv_.setCallback(boost::bind(&CSMethod2::reconfigureRequest, this, _1, _2));
        this->params_.fromParamServer();
        //// todo SETTING. modify topic name as you need
        this->roadnet_sub_ = this->nh_.subscribe(this->yaml_params_.road_net_topic, 1, &CSMethod2::roadnetCb, this);
        this->path_sub_ = this->nh_.subscribe("/global_path/traj_plan", 1, &CSMethod2::pathCb, this);
        this->collision_sub_ = this->nh_.subscribe("/collisionspeed_ref", 1, &CSMethod2::collisionCb, this);
        if (this->yaml_params_.vrep_sim) {
            this->steer_cmd_sub_ = this->nh_.subscribe("/cmd_str", 1, &CSMethod2::steerCmdCbSim, this);
            this->ecu_sub_ = this->nh_.subscribe("/vehicle_state", 1, &CSMethod2::vehicleStateCbSim, this);
        } else {
            this->steer_cmd_sub_ = this->nh_.subscribe("/steercmd", 1, &CSMethod2::steerCmdCb, this);
            this->ecu_sub_ = this->nh_.subscribe("/ecudatareport", 1, &CSMethod2::ecuCb, this);
        }

        if (strcmp(ISSUE_MODE, "cycle") == 0) {
            this->process_timer_ =
                this->nh_.createTimer(ros::Duration(PROCESS_PERIOD), boost::bind(&CSMethod2::planning, this));
        }
        this->check_timer_ =
            this->nh_.createTimer(ros::Duration(TIME_CHECK_PERIOD), boost::bind(&CSMethod2::time_check, this));
    }

    void CSMethod2::glogInit() {
        this->sLog_.init("constrained_speed", "log_constrained_speed", google::ERROR);
        LOG_INFO << "program start";
        LOG_WARN << "program start";
        LOG_ERROR << "program start";
    }

    void CSMethod2::paramsInit() {
        bool tmp_result = true;
        tmp_result &= this->private_nh_.getParam("vrep_sim", this->yaml_params_.vrep_sim);
        tmp_result &= this->private_nh_.getParam("acc_lat_max", this->yaml_params_.acc_lat);
        tmp_result &= this->private_nh_.getParam("acc_lon_max", this->yaml_params_.acc_max);
        tmp_result &= this->private_nh_.getParam("dec_lon_max", this->yaml_params_.acc_min);
        tmp_result &= this->private_nh_.getParam("safe_dec", this->yaml_params_.safe_dec);
        tmp_result &= this->private_nh_.getParam("v_max", this->yaml_params_.v_max);
        tmp_result &= this->private_nh_.getParam("jerk", this->yaml_params_.jerk);
        tmp_result &= this->private_nh_.getParam("road_net_topic", this->yaml_params_.road_net_topic);
        if (!tmp_result) {
            ROS_WARN_STREAM("CS: param not retrieved");
            ros::shutdown();
        }
        this->yaml_params_.acc_lat = fabs(this->yaml_params_.acc_lat);
        this->yaml_params_.acc_max = fabs(this->yaml_params_.acc_max);
        this->yaml_params_.acc_min = -fabs(this->yaml_params_.acc_min);
        this->yaml_params_.safe_dec = -fabs(this->yaml_params_.safe_dec);
        this->yaml_params_.v_max = fabs(this->yaml_params_.v_max);
        this->yaml_params_.jerk = fabs(this->yaml_params_.jerk);
    }

    void CSMethod2::setHandle() {
        this->path_sub_handle_ = this->sub_times_.time_handle.newHandle("check the period of path");
        this->ecu_sub_handle_ = this->sub_times_.time_handle.newHandle("check the period of ecu");
        this->roadnet_sub_handle_ = this->sub_times_.time_handle.newHandle("check the period of roadnet");
        this->steer_cmd_sub_handle_ = this->sub_times_.time_handle.newHandle("check the period of steer cmd");
        this->collision_sub_handle_ = this->sub_times_.time_handle.newHandle("collision");
    }

    void CSMethod2::time_check() {
        //// todo SETTING. modify check range as you need
        bool path_till_now_check = this->sub_times_.checkSingleTimestampTillNow(this->path_sub_handle_, -1, 300);
        bool ecu_till_now_check = this->sub_times_.checkSingleTimestampTillNow(this->ecu_sub_handle_, -1, 300);
        bool roadnet_till_now_check = this->sub_times_.checkSingleTimestampTillNow(this->roadnet_sub_handle_, -1, 4000);
        bool steer_cmd_till_now_check =
            this->sub_times_.checkSingleTimestampTillNow(this->steer_cmd_sub_handle_, -1, 100);
        bool collision_check = this->sub_times_.checkSingleTimestampDuration(this->collision_sub_handle_, -1, 1000);

        this->no_msg_ = (!path_till_now_check) || (!ecu_till_now_check);
        if (!path_till_now_check) {
            ROS_WARN_STREAM_THROTTLE(1, "CS: path not update");
        }
        if (!ecu_till_now_check) {
            ROS_WARN_STREAM_THROTTLE(1, "CS: ecu not update");
        }
        if (!roadnet_till_now_check) {
            this->way_.vel_limit = 100.0;
            this->way_.task_area = "none";
            this->way_.foggy_area = 0;
        }
        if (!steer_cmd_till_now_check) {
            this->control_steer_.steer = 0.0;
        }
        if (!collision_check) {
            this->collision_.collision = 0;
        }
    }

    void CSMethod2::reconfigureRequest(cs_method2Config &config, uint32_t level) {
    }

    void CSMethod2::roadnetCb(const lanelet_map_msgs::Way &msg) {
        this->way_ = msg;
        this->sub_times_.pushTimestamp(this->roadnet_sub_handle_);
    }

    void CSMethod2::pathCb(const plan2control_msgs::Trajectory &msg) {
        this->trajectory_ = msg;
        this->sub_times_.pushTimestamp(this->path_sub_handle_);
        if (strcmp(ISSUE_MODE, "direct") == 0) {
            this->planning();
        }
    }

    void CSMethod2::collisionCb(const movobsplan_msgs::Movobspeed &msg) {
        this->collision_ = msg;
        this->sub_times_.pushTimestamp(this->collision_sub_handle_);
    }

    void CSMethod2::ecuCb(const control_msgs::Report &msg) {
        static std::deque<std::pair<double_t, double_t >> vt_deq;
        this->cur_brake_ = (msg.brake.left_pressure_back + msg.brake.right_pressure_back) / 2;
        this->cur_speed_ = fabs(msg.motion.velocity);
        vt_deq.push_back(std::make_pair(msg.motion.velocity, msg.header.stamp.toSec()));
        while (!vt_deq.empty() && (vt_deq.back().second - vt_deq.front().second > 0.6 || vt_deq.size() > 1000))
            vt_deq.pop_front();
        if (vt_deq.size() < 2 || vt_deq.back().second - vt_deq.front().second < 0.001)
            this->cur_acc_ = 0;
        else
            this->cur_acc_ =
                (vt_deq.back().first - vt_deq.front().first) / (vt_deq.back().second - vt_deq.front().second);
        this->sub_times_.pushTimestamp(this->ecu_sub_handle_);
    }

    void CSMethod2::steerCmdCb(const control_msgs::ControlSteer &msg) {
        this->control_steer_ = msg;
        this->sub_times_.pushTimestamp(this->steer_cmd_sub_handle_);
    }

    void CSMethod2::vehicleStateCbSim(const anm_msgs::VehicleState &msg) {
        static double_t last_vehicle_speed = 0.;
        static double_t last_time_stamp = 0.;
        this->cur_speed_ = msg.velocity.linear.x;
        this->cur_acc_ = (cur_speed_ - last_vehicle_speed) / (msg.header.stamp.toSec() - last_time_stamp);
        last_vehicle_speed = cur_speed_;
        last_time_stamp = msg.header.stamp.toSec();
        this->sub_times_.pushTimestamp(this->ecu_sub_handle_);
    }

    void CSMethod2::steerCmdCbSim(const std_msgs::Float32 &msg) {
        this->control_steer_.steer = msg.data * 17.7;
        this->sub_times_.pushTimestamp(this->steer_cmd_sub_handle_);
    }

    void CSMethod2::planning() {
        ros::WallTime plan_start = ros::WallTime::now();
        if (this->no_msg_) {
            return;
        }
        if (!this->pointsPretreat()) {
            this->v_.assign(this->v_.size(), 0.);
            this->publish();
            return;
        }
        if (!this->pointsAttributes()) {
            return;
        }
        this->v_.assign(this->points_size_, 100.0);
        if (!this->setVMax()) {
            return;
        }
        if (!this->limitLatAcc()) {
            return;
        }
        if (!this->limitBySteer()) {
            return;
        }
        if (!this->safeStopSpeed()) {
            return;
        }
        if (!this->smoothSlowDown()) {
            return;
        }
        if (!this->blindHandle()) {
            return;
        }
        if (!this->smoothSpeed()) {
            return;
        }
        if (!this->calTime()) {
            return;
        }
        if (!this->calAcc()) {
            return;
        }
        if (!this->calJerk()) {
            return;
        }
        if (!this->publish()) {
            return;
        }
        ros::WallTime plan_end = ros::WallTime::now();
        ROS_INFO_STREAM("Time cost: " << (plan_end.toSec() - plan_start.toSec()) * 1000.);
    }

    bool CSMethod2::pointsPretreat() {
        //// todo SETTING. modify value below as you need
        double_t min_total_length = 0.1;

        if (this->trajectory_.points.size() < 2) {
            LOG_ERROR << "CS: receive points size: " << this->trajectory_.points.size();
            return false;
        }
        if (this->trajectory_.points.size() > 10000) {
            LOG_ERROR << "CS: receive points size: " << this->trajectory_.points.size();
            return false;
        }

        this->x_points_.clear();
        this->y_points_.clear();
        this->points_size_ = this->trajectory_.points.size();
        size_t direction_index = 0;
        for (size_t i = 0; i < this->points_size_; ++i) {
            this->x_points_.emplace_back(this->trajectory_.points[i].position.x);
            this->y_points_.emplace_back(this->trajectory_.points[i].position.y);
            if (this->trajectory_.points[i].forward != this->trajectory_.points[0].forward) {
                break;
            }
            direction_index = i;
        }
        static shawn::SPoints sPoints;
        sPoints.calculate_intervals_arc_lengths(x_points_, y_points_, intervals_, arc_lengths_);

        if ((this->arc_lengths_.back() < min_total_length) || (direction_index == 0)) {
            this->x_points_.clear();
            this->y_points_.clear();
            ++direction_index;
            for (size_t i = direction_index; i < this->points_size_; ++i) {
                this->x_points_.emplace_back(this->trajectory_.points[i].position.x);
                this->y_points_.emplace_back(this->trajectory_.points[i].position.y);
                if (this->trajectory_.points[i].forward != this->trajectory_.points[direction_index].forward) {
                    break;
                }
                direction_index = i;
            }
            sPoints.calculate_intervals_arc_lengths(x_points_, y_points_, intervals_, arc_lengths_);
            if (this->intervals_.empty() || intervals_.size() != arc_lengths_.size()) {
                LOG_ERROR << "CS: receive points illegal";
                return false;
            }
            if (this->arc_lengths_.back() < min_total_length) {
                LOG_ERROR << "CS: length of path: " << this->arc_lengths_.back();
                return false;
            }
            if (direction_index != (this->trajectory_.points.size() - 1)) {
                LOG_ERROR << "CS: path change direction more than once";
            }
        }

        this->direction_ = this->trajectory_.points[direction_index].forward ? direction::forward : direction::backward;

        //// todo xi shu jian cha

        this->points_size_ = this->x_points_.size();
        return true;
    }

    bool CSMethod2::pointsAttributes() {
        //// todo SETTING. modify value below as you need
        double_t waist_length = 1.0;
        double_t concerned_curvature = 0.06;
        double_t max_unsigned_curvature = 1.25;

//        static shawn::SThreePointsCurvature sCurvature;
//        sCurvature.speedPlanningCurvature(this->x_points_,
//                                          this->y_points_,
//                                          this->arc_lengths_,
//                                          this->intervals_,
//                                          waist_length,
//                                          concerned_curvature,
//                                          max_unsigned_curvature,
//                                          this->curvatures_);
        ToolKit::getCurvature(this->x_points_, this->y_points_, &this->curvatures_);
        for (int i = 0; i < curvatures_.size(); i++)
            curvatures_[i] = fabs(curvatures_[i]);
        if (this->curvatures_.size() != this->points_size_) {
            ROS_ERROR_STREAM("empty curvatures");
            this->curvatures_.assign(this->points_size_, max_unsigned_curvature);
        }
        return true;
    }

    bool CSMethod2::setVMax() {
        //// todo SETTING. modify value below as you need
        double_t v_max = 100.0;
        if (this->collision_.collision == 1) {
            this->way_.vel_limit = std::max(this->way_.vel_limit, this->collision_.exp_vel);
        } else {
            v_max = std::min(v_max, this->yaml_params_.v_max);
        }

        v_max = std::min(v_max, this->way_.vel_limit);
        if (this->direction_ == direction::backward) {
            v_max = std::min(v_max, 1.5);
        }
        if (this->trajectory_.header.frame_id == "search_base_link") {
            v_max = std::min(v_max, this->trajectory_.points[0].velocity.linear.x);
        }
        if (this->way_.task_area == "patrol_area") {
            v_max = std::min(v_max, 1.5);
        }
        if (this->way_.foggy_area == 1) {
            v_max = std::min(v_max, 1.5);
        }

        this->v_.assign(this->points_size_, v_max);
        return true;
    }

    bool CSMethod2::limitLatAcc() {
        double_t zero_curvature = this->yaml_params_.acc_lat / 10000;
        //// todo make small curvature to zero
        zero_curvature = 0.01;
        for (size_t i = 0; i < points_size_; ++i) {
            if (this->curvatures_[i] > zero_curvature) {
                this->v_[i] = std::min(this->v_[i], pow(this->yaml_params_.acc_lat / this->curvatures_[i], 0.5));
            }
        }
        return true;
    }

    bool CSMethod2::limitBySteer() {
        double_t delta = this->control_steer_.steer / 17.7 * M_PI / 180.;
//        delta = std::max(fabs(delta), this->control_steer_.max_abs_angle);
        // v*v*tan(delta) / L = a_lat
        double_t v = sqrt(fabs(this->yaml_params_.acc_lat * 2.73 / std::max(fabs(tan(delta)), 0.0001)));
        for (size_t i = 0; i < this->points_size_; ++i) {
            this->v_[i] = std::min(this->v_[i], v);
        }
        return true;
    }

    bool CSMethod2::safeStopSpeed() {
        //// todo SETTING. modify value below as you need
        //// todo SETTING. remember adjust safe redundancy in different mode
        double_t general_space_front = 2.0;
        double_t general_space_rear = 2.5;
        double_t search_space_front = 3.8;
        double_t search_space_rear = 1.2;

        double_t safe_redundancy = 2.0;
        safe_redundancy += general_space_front;
        double_t dec_delay = 0.3;

        double_t at = fabs(this->yaml_params_.safe_dec * dec_delay);
        double_t effective_length = std::max((this->arc_lengths_.back() - safe_redundancy), 0.0);
        if (effective_length < 0.1) {
            this->way_.vel_limit = std::min(this->way_.vel_limit, 0.0);
        }
        double_t v_safe = sqrt(pow(at, 2.0) + 2.0 * fabs(this->yaml_params_.safe_dec) * effective_length) - at;
        for (size_t i = 0; i < this->points_size_; ++i) {
            this->v_[i] = std::min(this->v_[i], v_safe);
        }
        return true;
    }

    bool CSMethod2::smoothSlowDown() {
        double_t jerk_slow_down_forward = this->yaml_params_.jerk;
        double_t jerk_slow_down_middle = this->yaml_params_.jerk;
        double_t slow_down_diff = 0.001;
        size_t slow_down_cycles = 100;
        this->v_[0] = this->cur_speed_;
        if (this->v_[0] > this->v_[1]) {
            sJerk.smooth_slow_down(this->v_,
                                   this->intervals_,
                                   this->v_[1],
                                   std::min(this->cur_acc_, 0.0),
                                   this->yaml_params_.acc_max,
                                   this->yaml_params_.acc_min,
                                   jerk_slow_down_forward,
                                   jerk_slow_down_middle,
                                   slow_down_diff,
                                   slow_down_cycles);
        }
        return true;
    }

    bool CSMethod2::blindHandle() {
        //// todo SETTING. modify value below as you need
        bool blind = false;
        bool use_blind_time = true;
        double_t blind_time = 0.5;
        double_t blind_area = 10.0;
        double_t blind_dec = -0.2;
        double_t blind_limit_v = 2.0;
        bool blind_reactive = true;

        if (!blind) {
            return true;
        }

        if (this->cur_speed_ < blind_limit_v) {
            return true;
        }

        if (use_blind_time) {
            blind_time = std::min(blind_time, this->cur_speed_ / fabs(blind_dec));
            blind_area = this->cur_speed_ * blind_time - 0.5 * fabs(blind_dec) * pow(blind_time, 2.0);
        }
        size_t end_index = this->points_size_;
        for (size_t i = 1; i < this->points_size_; ++i) {
            if (this->arc_lengths_[i] > blind_area) {
                end_index = i;
                break;
            }
        }
        double_t tmp_speed = this->v_[0];
        double_t tmp_v_min = this->v_[0];
        for (size_t j = 1; j <= end_index; ++j) {
            tmp_v_min = std::min(tmp_v_min, this->v_[j]);
            tmp_speed = sJerk.calculate_next_speed(tmp_speed,
                                                   0,
                                                   this->intervals_[j],
                                                   0,
                                                   -fabs(blind_dec),
                                                   -fabs(blind_dec),
                                                   false);
            this->v_[j] = std::max(this->v_[j], tmp_speed);
        }
        if (blind_reactive) {
            this->v_[end_index + 1] = std::min(this->v_[end_index + 1], tmp_v_min);
        }
        return true;
    }

    bool CSMethod2::smoothSpeed() {
        //// todo SETTING. modify value below as you need
        double_t jerk_forward_pass = this->yaml_params_.jerk;

        double_t jerk_backward_pass = this->yaml_params_.jerk;
        double_t slide_dec = -0.2;
        double_t a_end = 0.0;
        double_t v_begin_threshold = 0.01;
        bool remove_dec = false;
        double_t remove_dec_value = -0.2;
        double_t remove_dec_limit_v = std::max(this->cur_speed_, 2.0);

        double_t jerk_middle_pass = this->yaml_params_.jerk;
        double_t middle_cycle_diff = 0.001;
        size_t middle_cycles = 100;

        this->v_[0] = this->cur_speed_;
        sJerk.forward_pass_concave(this->v_,
                                   this->intervals_,
                                   jerk_forward_pass,
                                   this->yaml_params_.acc_max,
                                   this->yaml_params_.acc_min,
                                   this->cur_acc_);

        if (this->v_.size() >= 2)
            this->v_.at(v_.size() - 2) = this->v_.at(v_.size() - 1) = 0.0;
        std::vector<double_t> origin_v = this->v_;
        bool tmp_result = false;
//    if (!tmp_result) {
//        this->v_ = origin_v;
//        tmp_result = sJerk.backward_pass_concave(this->v_,
//                                                 this->intervals_,
//                                                 jerk_backward_pass,
//                                                 this->yaml_params_.acc_max,
//                                                 slide_dec,
//                                                 a_end,
//                                                 v_begin_threshold,
//                                                 remove_dec,
//                                                 remove_dec_value,
//                                                 remove_dec_limit_v);
//    }
        if (!tmp_result) {
            this->v_ = origin_v;
            tmp_result = sJerk.backward_pass_concave(this->v_,
                                                     this->intervals_,
                                                     jerk_backward_pass,
                                                     this->yaml_params_.acc_max,
                                                     this->yaml_params_.acc_min,
                                                     a_end,
                                                     v_begin_threshold,
                                                     remove_dec,
                                                     remove_dec_value,
                                                     remove_dec_limit_v);
        }
        if (!tmp_result) {
            this->v_ = origin_v;
            tmp_result = sJerk.backward_pass_concave(this->v_,
                                                     this->intervals_,
                                                     DBL_MAX,
                                                     this->yaml_params_.acc_max,
                                                     this->yaml_params_.acc_min,
                                                     a_end,
                                                     v_begin_threshold,
                                                     remove_dec,
                                                     remove_dec_value,
                                                     remove_dec_limit_v);
        }
        if (!tmp_result) {
            this->v_ = origin_v;
            tmp_result = sJerk.backward_pass_concave(this->v_,
                                                     this->intervals_,
                                                     DBL_MAX,
                                                     this->yaml_params_.acc_max,
                                                     this->yaml_params_.safe_dec,
                                                     a_end,
                                                     v_begin_threshold,
                                                     remove_dec,
                                                     remove_dec_value,
                                                     remove_dec_limit_v);
        }

        if (!tmp_result) {
            LOG_ERROR << "CS: backward pass powerless";
        }
        sJerk.middle_pass_convex_cycle(this->v_, this->intervals_, jerk_middle_pass, middle_cycle_diff, middle_cycles);
        return true;
    }

    bool CSMethod2::calTime() {
        //// todo SETTING. modify value below as you need
        double_t zero_speed = 0.01;

        this->time_.clear();
        this->time_.emplace_back(0.0);
        this->time_interval_.clear();
        this->time_interval_.emplace_back(0.0);
        bool speed_zero = true;
        for (size_t i = 1; i < this->points_size_; ++i) {
            speed_zero = ((this->v_[i] < zero_speed) && (this->v_[i - 1] < zero_speed));
            if (speed_zero) {
                this->time_interval_.emplace_back(DBL_MAX);
                this->time_.emplace_back(DBL_MAX);
            } else {
                this->time_interval_.emplace_back(2.0 * this->intervals_[i] / (this->v_[i - 1] + this->v_[i]));
                this->time_.emplace_back(this->time_[i - 1] + this->time_interval_[i]);
            }
        }
        return true;
    }

    bool CSMethod2::calAcc() {
        this->acc_.clear();
        this->acc_.emplace_back(this->cur_acc_);
        for (size_t i = 1; i < this->points_size_; ++i) {
            this->acc_.emplace_back((pow(this->v_[i], 2.0) - pow(this->v_[i - 1], 2.0)) * 0.5 / this->intervals_[i]);
        }
        return true;
    }

    bool CSMethod2::calJerk() {
        this->jerk_.clear();
        this->jerk_.emplace_back(0.0);
        for (size_t i = 1; i < this->points_size_; ++i) {
            this->jerk_.emplace_back((this->acc_[i] - this->acc_[i - 1]) / this->time_interval_[i]);
        }
        return true;
    }

    bool CSMethod2::publish() {
        //// todo SETTING. modify value below as you need
        double_t acc_delay = 0.25; // this->time_.size() > 1 ? this->time_[1] : 0.1;
        double_t dec_delay = 2.0;

        static Publish publish;
        double collision_limit = (this->collision_.collision == 2) ? (this->collision_.exp_vel) : 100.0;
        collision_limit = std::min(collision_limit, this->way_.vel_limit);

        speed_issue issue_result = publish.publish(this->nh_,
                                                   this->time_,
                                                   this->v_,
                                                   this->acc_,
                                                   acc_delay,
                                                   (this->direction_ == direction::forward),
                                                   collision_limit,
                                                   this->cur_brake_);
        ROS_INFO_STREAM("current speed " << cur_speed_);
        ROS_INFO_STREAM("publish speed " << issue_result.v);
        ROS_INFO_STREAM("publish acceleration " << issue_result.acc);
        if (yaml_params_.vrep_sim) {
            static ros::Publisher sim_vel_pub = this->nh_.advertise<std_msgs::Float32>("cmd_vel", 10);
            static std_msgs::Float32 sim_velocity;
            sim_velocity.data = issue_result.v * 2.76;
            sim_vel_pub.publish(sim_velocity);
        }
        std::vector<double_t> tmp_issue_result;
        tmp_issue_result.emplace_back(issue_result.v);
        tmp_issue_result.emplace_back(issue_result.acc);
//        additionPublish(tmp_issue_result);

        return true;
    }

    void CSMethod2::additionPublish(std::vector<double_t> issue) {
        static speed_debug_msgs::speed_debug speed_debug;
        static ros::Publisher debug_pub = this->nh_.advertise<speed_debug_msgs::speed_debug>("/speed_debug", 1);
        speed_debug.points.resize(this->points_size_);
        for (size_t i = 0; i < this->points_size_; ++i) {
            speed_debug.points[i].v.v_constrained = this->v_[i];
            speed_debug.points[i].curv.curv_final = fabs(this->curvatures_[i]);
            speed_debug.points[i].time.time = this->time_[i];
            speed_debug.points[i].x = this->x_points_[i];
            speed_debug.points[i].y = this->y_points_[i];
            speed_debug.points[i].s = this->arc_lengths_[i];
            speed_debug.points[i].acc = this->acc_[i];
            speed_debug.points[0].curv.curv_final =
                std::max(speed_debug.points[0].curv.curv_final, speed_debug.points[i].curv.curv_final);
        }
        speed_debug.issue.v = issue[0];
        speed_debug.issue.acc = issue[1];
        speed_debug.pub_ros_time = ros::Time::now().toSec();
        debug_pub.publish(speed_debug);
        ROS_INFO_STREAM(speed_debug.points[0].curv.curv_final);

        //// trajectory publish
        {
            static ros::Publisher publisher = this->nh_.advertise<plan2control_msgs::Trajectory>("/trajectory", 1);
            for (size_t i = 0; i < this->points_size_; ++i) {
                this->trajectory_.points[i].velocity.linear.x = this->v_[i];
                this->trajectory_.points[i].velocity.linear.y = this->time_[i];
            }
            publisher.publish(this->trajectory_);
        }
    }
}
