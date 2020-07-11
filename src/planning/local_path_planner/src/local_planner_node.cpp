#include "local_planner_node.hpp"

#include <state_sampling/state_sampling.hpp>
#include <state_sampling/purepsuit_method.hpp>
#include <path_smoothing/path_smoothing.hpp>

LocalPlanner::LocalPlanner() :
    pnh_("~"),
    current_task_(NORMAL_TRAVEL),
    kappa_((ba::tag::rolling_window::window_size = 20)) {
    // init params
    InitParams();
    // initilize publishers
    rviz_path_pub_ = pnh_.advertise<nav_msgs::Path>("modified_path", 1, true);
    traj_pub_ = pnh_.advertise<plan2control_msgs::Trajectory>("traj_plan", 1, true);
    normal_plan_end_pub_ = pnh_.advertise<std_msgs::UInt8>("/normal_plan_end", 1, true);

    this->lp_rviz_ = std::make_shared<PathPlannerVisualTools>(pnh_, pnh_, cfg_.frame_id);
    this->lp_rviz_->clearMarkerArray();

    // initilize subscribers
    gridmap_sub_ = pnh_.subscribe("/local_grid_map", 1, &LocalPlanner::GridMapCb, this);
    planning_origin_sub_ = pnh_.subscribe("/planning_origin", 1, &LocalPlanner::PlanningOriginCb, this);
    if (cfg_.is_simulation) {
        vehicle_fuse_pose_sub_ = pnh_.subscribe("/vehicle_state", 1, &LocalPlanner::SimulationVehicleStateCb, this);
        ecudata_sub_ = pnh_.subscribe("/vehicle/steering_report", 1, &LocalPlanner::SimulationSteeringCb, this);
    } else {
        vehicle_fuse_pose_sub_ =
            pnh_.subscribe(cfg_.vehicle_fuse_pose_topic, 1, &LocalPlanner::VehicleFusionPoseCb, this);
        ecudata_sub_ = pnh_.subscribe("/ecudatareport", 1, &LocalPlanner::EcuDataCb, this);
        finish_search_sub_ = pnh_.subscribe("/search_plan_end", 1, &LocalPlanner::FinishSearchCb, this);
    }
    waypoint_sub_ = pnh_.subscribe(cfg_.roadnet_topic, 1, &LocalPlanner::WaypointCb, this);
    if (cfg_.use_origin_task_point) {
        task_point_sub_ = pnh_.subscribe("/global_way", 1, &LocalPlanner::TaskPointCb, this);
    }
}

void LocalPlanner::InitParams() {
    // read parameters from config file
    cfg_.roadnet_topic = pnh_.param<std::string>("road_net_topic", "/topology_global_path");
    cfg_.vehicle_fuse_pose_topic = pnh_.param<std::string>("vehicle_fuse_pose_topic", "/sensor_fusion_output");
    cfg_.use_roadnet = pnh_.param("use_roadnet", true);
    cfg_.use_state_sampling = pnh_.param("use_state_sampling", true);
    cfg_.pure_roadnet_mode = pnh_.param("pure_roadnet_mode", false);
    cfg_.use_origin_task_point = pnh_.param("use_origin_task_point", false);
    cfg_.path_length = pnh_.param("generate_path_length", 40.0);
    cfg_.remained_length = 25;
    cfg_.offset_interval = pnh_.param("roadnet_offset_interval", 0.1);
    cfg_.roadnet_max_offset = pnh_.param("roadnet_max_offset", 5.0);
    cfg_.is_simulation = pnh_.param("is_simulation", false);
    cfg_.frame_id = pnh_.param<std::string>("frame_id", "odom");

    // initilize flag
    flag_.finish_search_task = false;
    flag_.is_forward_search = true;
    flag_.map_update = false;
    flag_.start_state_update = false;
    flag_.planning_origin_set = false;
    this->ref_waypoint_.points.clear();
}

bool LocalPlanner::CheckTaskArea(const lanelet_map_msgs::Way &way) {
    if (current_task_ == SEARCH_TASK && !flag_.finish_search_task) {
        return false;
    }
    if (!(way.is_forward)) {
        flag_.is_forward_search = false;
        vehicle_state_.z += M_PI;
        if (vehicle_state_.z > M_PI) {
            vehicle_state_.z -= M_PI * 2.0;
        }
        ROS_WARN("need backup!!!");
    } else {
        flag_.is_forward_search = true;
    }
    if (way.task_area == "park_area") {
        ROS_INFO("into park area!!!");
        this->current_task_ = PARKING_AREA;
    } else if (way.task_area == "patrol_area") {
        ROS_INFO("into patrol area!!!");
        this->current_task_ = PATROL_TASK;
    } else if (way.task_area == "hidden_area" && !flag_.finish_search_task) {
        this->current_task_ = SEARCH_TASK;
    } else {
        this->current_task_ = NORMAL_TRAVEL;
    }

    if (this->current_task_ == SEARCH_TASK || this->current_task_ == PARKING_AREA) {
        if (fabs(this->vehicle_state_.v) < 0.4) {
            std_msgs::UInt8 flag;
            flag.data = 1;
            this->normal_plan_end_pub_.publish(flag);
            ROS_INFO("in special area, waiting for search over......");
        } else {
            ROS_INFO("in special area, waiting for switch......");
        }
        return false;
    }
    return true;
}

void LocalPlanner::UpdateGridMap() {
    if (flag_.map_update) {
        grid_map::GridMap gridmap;
        grid_map::GridMapRosConverter::fromMessage(this->gridmap_msgs_, gridmap);
        this->in_gm_.init(gridmap.getFrameId(), gridmap.getLength(),
                          gridmap.getResolution());
        this->in_gm_.maps.get(in_gm_.obs) = gridmap.get(in_gm_.obs);
        this->in_gm_.maps.setPosition(gridmap.getPosition());
        this->in_gm_.maps.setFrameId(gridmap.getFrameId());
        this->in_gm_.updateDistanceLayer();
        this->time_observe_.map_update_time = ros::Time::now();
        this->time_observe_.waiting_map_interval = 0.0;
    } else {
        auto time = ros::Time::now();
        this->time_observe_.waiting_map_interval = fabs(time.toSec() - time_observe_.map_update_time.toSec());
    }
}

void LocalPlanner::interceptAviliablePath(const hmpl::State &current_state,
                                          const StatePath &ref_path,
                                          StatePath *aviliable_path,
                                          std::string *message) {
    if (ref_path.empty()) {
        *message += hmpl::StringPrintf("    empty old path\n");
        return;
    }

//     find nearest point to vehicle head. we will ignore the obstacle behind the vehicle
    hmpl::State head_state = current_state;
    head_state.x = current_state.x + 4 * cos(current_state.z);
    head_state.y = current_state.y + 4 * sin(current_state.z);
    size_t head_id = 0;
    double dis_to_head = std::numeric_limits<double>::max();
    size_t center_id = 0;
    double dis_to_center = std::numeric_limits<double>::max();
    for (size_t i(0); i < ref_path.size(); ++i) {
        double dist = Distance(ref_path.at(i), head_state);
        if (dist < dis_to_head) {
            dis_to_head = dist;
            head_id = i;
        }
        dist = Distance(ref_path.at(i), current_state);
        if (dist < dis_to_center) {
            dis_to_center = dist;
            center_id = i;
        }
    }
    // intercept path is far away from vehicle
    if (dis_to_center > 3.0) {
        *message +=
            hmpl::StringPrintf("    vehicle is %f far away last path!\n",
                               dis_to_center);
        return;
    }
    // intercept collision free path
    hmpl::State tmp_state;
    hmpl::CollisionChecker collision_checker(this->in_gm_);
//    hmpl::Vector2D<double> rear_right(-1.0, -1.5);
//    hmpl::Vector2D<double> front_right(3.86, -1.5);
//    hmpl::Vector2D<double> front_left(3.86, 1.5);
//    hmpl::Vector2D<double> rear_left(-1.0, 1.5);
//    collision_checker.setCarFootPrint(rear_right, front_right, front_left,
//                                      rear_left);
    size_t start_id = center_id < 5 ? 0 : center_id - 5;
    for (size_t i(start_id); i < ref_path.size(); ++i) {
        tmp_state = ref_path.at(i);
        if (i < head_id) {
            aviliable_path->push_back(tmp_state);
        } else {
            if (collision_checker.isSingleStateCollisionFreeImproved(tmp_state)) {
                if (i == head_id) {
                    tmp_state.s = Distance(ref_path.at(head_id), ref_path.at(center_id));
                } else {
                    tmp_state.s = aviliable_path->back().s + Distance(tmp_state, aviliable_path->back());
                }
                aviliable_path->push_back(tmp_state);
            } else {
                break;
            }
        }
    }
    if (aviliable_path->empty()) {
        *message += hmpl::StringPrintf("    no aviliable path in last path\n");
    } else if (aviliable_path->back().s < cfg_.remained_length) {
        *message += hmpl::StringPrintf("    aviliable path length %f is shorter than %f\n",
                                       aviliable_path->back().s,
                                       cfg_.remained_length);
        aviliable_path->clear();
    } else {
        *message += hmpl::StringPrintf("    intercept old path %f m\n", aviliable_path->back().s);
    }
    // intercpet path's length is not enough!!!
}

void LocalPlanner::GenerateSamplingPath(StatePath *result_path) {
    this->lp_rviz_->pushSamplingReferencePath(*result_path);
    hmpl::State goal_state = result_path->back();
    vehicle_state_planning_.k = 0;//ba::rolling_mean(kappa_);
//    printf("****Debug: vehicle k: %f, roll mean: %f, speed: %f\n",
//           vehicle_state_.k,
//           vehicle_state_planning_.k,
//           vehicle_state_.v);
    StatePath sampling_path;
    size_t index = result_path->size() / 2;
    if (AngleDiffRad(result_path->at(index).z, vehicle_state_.z) < M_PI / 3.0) {
        std::cout << "Into state samplig!\n";
        hmpl::StateSampling
            state_sampling(in_gm_, vehicle_state_planning_, goal_state);
        // state_sampling.setMaxCurvature(vehicle_state_.v);
        state_sampling.deepStateSampling(*result_path,
                                         vehicle_state_planning_,
                                         goal_state);
        // rviz display
//        this->lp_rviz_->pushStateSamplineProgress(state_sampling.observeVariable());
        sampling_path = state_sampling.getFinalPath();
        if (sampling_path.empty()
            || sampling_path.back().s < result_path->back().s / 2.0) {
            std::cout << "Into control samplig!\n";
            hmpl::PurepursuitSampling
                control_sampling(in_gm_, vehicle_state_planning_);
            sampling_path.clear();
            control_sampling.puerpursuitSampling(*result_path, &sampling_path);
        }
    } else {
        std::cout << "Into control samplig!\n";
        hmpl::PurepursuitSampling
            control_sampling(in_gm_, vehicle_state_planning_);
        sampling_path.clear();
        control_sampling.puerpursuitSampling(*result_path, &sampling_path);
    }
    if (!sampling_path.empty()
        && sampling_path.back().s > 0.5 * result_path->back().s) {
        *result_path = sampling_path;
    }
    auto t6 = hmpl::now();
}

void LocalPlanner::evaluatePath(const StatePath &ref_path) {
    if (ref_path.empty()) {
        return;
    }
    double max_curvature = 0;
    double heading_error = 0.0;
    double location_error = 0.0;
    size_t nearest_id = 0;
    double nearest_dist = std::numeric_limits<double>::infinity();
    for (size_t i = 0; i < ref_path.size(); ++i) {
        const double
            dist = hmpl::distance(ref_path.at(i), vehicle_state_planning_);
        if (dist < nearest_dist) {
            nearest_id = i;
            nearest_dist = dist;
        }
        if (fabs(ref_path.at(i).k) > fabs(max_curvature)) {
            max_curvature = ref_path.at(i).k;
        }
    }
    heading_error = ref_path.at(nearest_id).z - vehicle_state_planning_.z;
    location_error = nearest_dist;
    printf("****[%d] heading error: %f, location error: %f; max curvature: %f\n",
           nearest_id,
           heading_error * 180.0 / M_PI,
           location_error,
           max_curvature);
}

void LocalPlanner::Run() {
    ros::Rate rate(30);
    if (!cfg_.pure_roadnet_mode) {
        while ((!(flag_.map_update) || !(flag_.start_state_update) || !(flag_.planning_origin_set)) && ros::ok()) {
            ros::spinOnce();
            rate.sleep();
        }
        // init internal grid map
        this->UpdateGridMap();
    }

    bool force_keep_track = false;
    int planning_mode = -1;
    int last_roadnet_id = INT32_MAX;
    hmpl::State guidance_point;
    StatePath last_planned_path;
    guidance_point = vehicle_state_;
    const unsigned int search_mode_period = 5;
    unsigned int search_mode_count = 2 * 5;
    // main progress
    while (ros::ok()) {
        ros::spinOnce();
        if (!flag_.start_state_update || ref_waypoint_.points.empty()) {
            continue;
        } else {
            auto t1 = hmpl::now();
            //  publish global way marker
            // ******** check task
            if (!CheckTaskArea(this->ref_waypoint_)) {
                rate.sleep();
                continue;
            }
            // set path length
            if (!force_keep_track) {
                if (ref_waypoint_.vel_limit > 12 && vehicle_state_.v > 10) {
                    cfg_.path_length = 70;
                    cfg_.remained_length = 60;
                } else {
                    cfg_.path_length = 45;
                    cfg_.remained_length = 30;
                }
            }
            //  ******** update grid map
            if (!cfg_.pure_roadnet_mode) {
                this->UpdateGridMap();
                if (this->time_observe_.waiting_map_interval > 2.0) {
                    ROS_ERROR("map updating interval exceed 2.0 s, which means map not update!!!");
                    continue;
                }
            } else {
                cfg_.path_length = 1000;
            }
            vehicle_state_planning_ = vehicle_state_;
            vehicle_state_planning_.x = vehicle_state_.x - planning_origin_.x;
            vehicle_state_planning_.y = vehicle_state_.y - planning_origin_.y;
            this->lp_rviz_->clearMarkerArray();
            this->lp_rviz_->pushRoadNetMarker(ref_waypoint_, planning_origin_);

            auto t2 = hmpl::now();
            StatePath final_path;
            PathWithCost basic_roadnet;
            RoadnetHandler roadnet_mode(in_gm_,
                                        vehicle_state_,
                                        planning_origin_,
                                        last_roadnet_id,
                                        cfg_.path_length);
            roadnet_mode.getPathFromRoadnet(ref_waypoint_,
                                            &basic_roadnet);
            if (fabs(basic_roadnet.max_curvature) > 0.22 &&
                fabs(basic_roadnet.dis_to_max_curvature - 15) < 1.0) {
                last_planned_path.clear();
                cfg_.remained_length = 10;
                force_keep_track = true;
            }
            std::cout << "\n";
            auto t3 = hmpl::now();
            //  ********use last path;
            if (!cfg_.pure_roadnet_mode && flag_.is_forward_search) {
                std::string message = "Use last path:\n";
                interceptAviliablePath(vehicle_state_planning_,
                                       last_planned_path,
                                       &final_path, &message);
                if (force_keep_track) {
                    ROS_WARN("force keep track!");
                }
                planning_mode = 0;
                std::cout << message;
            }

            auto t4 = hmpl::now();
            if (!final_path.empty()) {
                std::cout << "Basic RoadNET INFO: \n" << roadnet_mode.getTextMessage();
                guidance_point = final_path.back();
            } else {
                if (!last_planned_path.empty()) {
                    force_keep_track = false;
                }
            }
            if (cfg_.pure_roadnet_mode) {
                ROS_INFO("pure roadnet mode!!!");
                final_path = basic_roadnet.path;

            } else if (cfg_.use_roadnet
                && search_mode_count >= search_mode_period
                && flag_.is_forward_search && final_path.empty()) {
                planning_mode = 1;
                // **** Roadnet Mode:
                std::map<int, PathWithCost> path_set;
                roadnet_mode.getOffsetPathSet(basic_roadnet, &path_set);
                roadnet_mode.chooseBestPath(basic_roadnet,
                                            &path_set,
                                            &final_path);
                this->lp_rviz_->pushOffsetPathSet(path_set, final_path);
                if (!final_path.empty()) {
                    using namespace path_smoothing;
                    DistanceFunction2D distance_func(in_gm_.maps, "");
                    PathSmoothing::Options options;
                    options.function = &distance_func;
                    options.lower_boundary = 2.0;
                    options.smoother_type = NON_DERIVATIVE_METHOD;
                    std::unique_ptr<PathSmoothing> smoother
                        (PathSmoothing::createSmoother(options,
                                                       final_path));
                    smoother->smoothPath(options);
                    smoother->getSmoothPath(&final_path);
                    last_roadnet_id = roadnet_mode.BestRoadId();
                    guidance_point = final_path.back();
                    std::cout << "Road Mode Success: \n"
                              << roadnet_mode.getTextMessage();
                } else {
                    std::cout << "Road Mode Fail: \n"
                              << roadnet_mode.getTextMessage();
                }
            }
            auto t5 = hmpl::now();
            if (final_path.empty()) {
                planning_mode = 2;
                // ********search mode:
                SearchMethod search_mode(in_gm_, basic_roadnet,
                                         vehicle_state_planning_,
                                         guidance_point);
                search_mode.SearchPath(&final_path);
                guidance_point = search_mode.GetGoalState();
                lp_rviz_->pushGuidancePointProgress(search_mode.GetGoalProgress());
                std::cout << "Search Mode " << search_mode_count << " :\n"
                          << search_mode.GetTextMessage();
                search_mode_count = (search_mode_count + 1) %
                    (search_mode_period + 1);
                last_roadnet_id = INT32_MAX;
            }
            auto t6 = hmpl::now();
            // ******** state sampling
            hmpl::fillStatePath(&final_path);
            if (cfg_.use_state_sampling && final_path.size() > 5
                && planning_mode > 0 && flag_.is_forward_search) {
                //final_path.back().z = basic_roadnet.path.back().z;
                GenerateSamplingPath(&final_path);
            } else {
                printf(
                    "**** Debug: sampling condition not meet, path size: %d!!!\n",
                    final_path.size());
            }

            last_planned_path = final_path;
            // ******** publish msg
            this->PublishPathMsg(final_path);
//            this->lp_rviz_->clearDisplay();
            this->lp_rviz_->displayAllMarker();
            this->evaluatePath(final_path);

            auto t7 = hmpl::now();
            printf("Time cost Report:%f\n"
//                           "    initialize: %f\n"
//                           "    convert roadnet:%f\n"
//                           "    intercept last:%f\n"
//                           "    roadnet mode:%f\n"
                       "    search mode:%f\n"
                       "    sampling:%f\n",
                   hmpl::getDurationInSecs(t1, t7),
//                   hmpl::getDurationInSecs(t1, t2),
//                   hmpl::getDurationInSecs(t2, t3),
//                   hmpl::getDurationInSecs(t3, t4),
//                   hmpl::getDurationInSecs(t4, t5),
                   hmpl::getDurationInSecs(t5, t6),
                   hmpl::getDurationInSecs(t6, t7));
            this->flag_.start_state_update = false;
            this->flag_.map_update = false;
        }
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "local_planner");
    LocalPlanner global_path;
    global_path.Run();
    /// main loop.
    return 0;
}

