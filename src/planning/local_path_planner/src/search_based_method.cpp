//
// Created by yangt on 18-11-13.
//
#include "search_based_method.hpp"
#include "space_explore/space_explore.hpp"
#include <glog/logging.h>

SearchMethod::SearchMethod(hmpl::InternalGridMap &gridmap,
                           const PathWithCost &global_way,
                           const hmpl::State &vehicle_state,
                           const hmpl::State &last_guid_pt) :
    in_gm_(gridmap),
    vehicle_state_(vehicle_state),
    roadnet_(global_way),
    last_guid_pt(last_guid_pt),
    message_("") {

}

hmpl::State SearchMethod::GetGoalState() {
    hmpl::State result;
    result.x = goal_state_.position.x;
    result.y = goal_state_.position.y;
    result.z = goal_state_.orientation;
    return result;
}

std::vector<Knot> SearchMethod::GetGoalProgress() {
    return this->goal_progress_;
}

bool SearchMethod::isPathFeasible(const PathWithCost &modified_path) {
    if (modified_path.path.empty()) {
        LOG(INFO) << "Empty search result with lower_boundary "
                  << modified_path.dis_to_obs;
        return false;
    }
    if (modified_path.bending_energy > 10.0) {
        LOG(INFO) << "path energy " << modified_path.bending_energy
                  << " is too large "
                  << "in lower_boundary " << modified_path.dis_to_obs;
        return false;
    }
    if (modified_path.path.back().s > 1.8 * roadnet_.path.back().s
        && roadnet_.path.back().s > 35) {
        LOG(INFO) << "lower boundary path " << modified_path.dis_to_obs
                  << " has longer length " << modified_path.path.back().s
                  << " than road net length " << roadnet_.path.back().s;
        return false;
    }
    /// fill curve
    const std::size_t size = modified_path.path.size();
    double path_angle = std::numeric_limits<double>::infinity();
    for (std::size_t i = 1; i < size; i++) {
        const hmpl::State &state = modified_path.path.at(i);
        if (fabs(path_angle) > 2 * M_PI && (state.s > 5.0 || i == size - 1)) {
            path_angle = hmpl::angle(modified_path.path.front(), state);
        }
        // TODO: u-turn may contain large curvature(0.55)
//        if (i + 1 < size) {
//            hmpl::Vector2D<double> pt1(modified_path.path.at(i - 1).x,
//                                       modified_path.path.at(i - 1).y);
//            hmpl::Vector2D<double> pt2(state.x, state.y);
//            hmpl::Vector2D<double> pt3(modified_path.path.at(i + 1).x,
//                                       modified_path.path.at(i + 1).y);
//            double curvature = hmpl::getCurvature(pt1, pt2, pt3);
//            if (curvature > 0.5) {
//                LOG(INFO) << "lower boundary path " << modified_path.dis_to_obs
//                          << " has large curvature " << curvature
//                          << "at length " << state.s;
//                return false;
//            }
//        }
    }
    double road_angle = std::numeric_limits<double>::infinity();
    if (this->roadnet_.path.back().s > 10.0) {
        for (const auto &state : this->roadnet_.path) {
            if (state.s > 10.0) {
                road_angle = hmpl::angle(roadnet_.path.front(), state);
            }
        }
    } else {
        road_angle = hmpl::angle(roadnet_.path.front(), roadnet_.path.back());
    }
    if (AngleDiffRad(path_angle, road_angle) > 3 * M_PI / 4.0) {
        LOG(INFO) << "path_angle " << path_angle << " and road angle "
                  << road_angle << " is different a lot";
        return false;
    }

    if (AngleDiffRad(path_angle, vehicle_state_.z) > 2 * M_PI / 3.0) {
        LOG(INFO) << "path_angle " << path_angle << " and vehicle heading "
                  << vehicle_state_.z << " is different a lot";
        return false;
    }

    return true;
}

bool SearchMethod::IsStateAviliable(const hmpl::State &test_state,
                                    const hmpl::State &vehicle_state) {
    grid_map::Position goal_pos(test_state.x, test_state.y);
    if (!in_gm_.maps.isInside(goal_pos)
        || in_gm_.getObstacleDistance(goal_pos) < 1.2) {
        return false;
    }
    hmpl::Pose2D start_state(vehicle_state.x, vehicle_state.y, vehicle_state.z);
    hmpl::Pose2D goal_state(test_state.x, test_state.y, test_state.z);
    hmpl::SpaceExplore space_explore(in_gm_, false);
    space_explore.setLowerBoundary(1.2);
    space_explore.solve(in_gm_, start_state, goal_state);
    PathWithCost path_with_cost;
    path_with_cost.dis_to_obs = -1;
    path_with_cost.path = space_explore.getStatePath();
    path_with_cost.bending_energy = space_explore.getCirclePathEnergy();
    if (isPathFeasible(path_with_cost)) {
//        Knot knot;
//        for (const auto &state: path_with_cost.path) {
//            knot.pt(0) = state.x;
//            knot.pt(1) = state.y;
//            this->goal_progress_.push_back(knot);
//        }
//        printf("**** Debug choose guidance point size: %d , distance: %f\n",
//               path_with_cost.path.size(),
//               hmpl::distance(test_state, vehicle_state));
        return true;
    }
    return false;

}

hmpl::Pose2D SearchMethod::SelectGoalPoint(const StatePath &global_path) {
    hmpl::Pose2D goal_pose;
    if (global_path.size() < 2) {
        this->message_ += hmpl::StringPrintf(
            "    no guidance point due to road net size is less than 2!\n");
        return goal_pose;
    }
    if (IsStateAviliable(global_path.back(), vehicle_state_)) {
        // use origin roadnet point
        goal_pose.position.x = global_path.back().x;
        goal_pose.position.y = global_path.back().y;
        goal_pose.orientation =
            hmpl::angle(*(global_path.end() - 2), global_path.back());
        // TODO: check *(end()-1) is the last two element?
        this->message_ +=
            hmpl::StringPrintf("    guidance point from roadnet\n");
        return goal_pose;
    } else {
        double delta = 0.2;
        const double right = global_path.back().z - M_PI_2;
        const double left = global_path.back().z + M_PI_2;
        hmpl::State new_state = global_path.back();
        bool new_state_aviliable = false;
        for (int i = 1; i < 5; ++i) {
            const double offset = delta * i;
            new_state.x = global_path.back().x + offset * cos(right);
            new_state.y = global_path.back().y + offset * sin(right);
            if (IsStateAviliable(new_state, vehicle_state_)) {
                new_state_aviliable = true;
                break;
            }
            new_state.x = global_path.back().x + offset * cos(left);
            new_state.y = global_path.back().y + offset * sin(left);
            if (IsStateAviliable(new_state, vehicle_state_)) {
                new_state_aviliable = true;
                break;
            }
        }
        if (new_state_aviliable) {
            goal_pose.position.x = new_state.x;
            goal_pose.position.y = new_state.y;
            goal_pose.orientation =
                hmpl::angle(*(global_path.end() - 2), global_path.back());
            // TODO: check *(end()-1) is the last two element?
            this->message_ +=
                hmpl::StringPrintf("    guidance point from offset roadnet\n");
            return goal_pose;
        }
    }

    hmpl::State start_state = vehicle_state_;
    guidancePointSelection guid_pt(this->in_gm_, global_path,
                                   start_state, false);
    // goal state from guidance_point package:
    guid_pt.searchPath();
    this->goal_progress_ = guid_pt.search_path.path;
    if (guid_pt.point_selected.type == "none") {
        this->message_ +=
            hmpl::StringPrintf("    guidance point type is none\n");
        return goal_pose;
    } else {
        goal_pose = hmpl::Pose2D(guid_pt.point_selected.point.x,
                                 guid_pt.point_selected.point.y,
                                 global_path.back().z);
        if (guid_pt.point_selected.id == DFFS) {
            this->message_ +=
                hmpl::StringPrintf("    guidance point method: DFFS\n");
        } else {
            this->message_ +=
                hmpl::StringPrintf("    guidance point method: laser beam\n");
        }

    }

    hmpl::Pose2D last_pose(last_guid_pt.x, last_guid_pt.y, last_guid_pt.z);

    if (IsStateAviliable(last_guid_pt, vehicle_state_)) {
        if (guid_pt.point_selected.type == "weak") {
            goal_pose = last_pose;
            this->message_ +=
                hmpl::StringPrintf(
                    "    use old guidance point, because new is weak\n");
        } else if (guid_pt.point_selected.type == "valid") {
            double dist_to_old_guid =
                Distance(guid_pt.point_selected.point, last_guid_pt);
            double dist_to_vehicle_old = Distance(last_guid_pt, vehicle_state_);
            double dist_to_vehicle_new =
                Distance(guid_pt.point_selected.point, vehicle_state_);
            if (dist_to_vehicle_old < 15 && dist_to_vehicle_new < 15) {
                goal_pose = last_pose;
                this->message_ +=
                    hmpl::StringPrintf(
                        "    use old guidance point, because old and new are close to vehicle\n");
            } else if (dist_to_old_guid > 1.5 && dist_to_vehicle_old > 25) {
                // if current point is far away from  last point ,
                double dist2goal = Distance(guid_pt.next_way_point,
                                            guid_pt.point_selected.point);
                double dist2goal_last = Distance(guid_pt.next_way_point,
                                                 last_guid_pt);
                double angle_this =
                    atan2(guid_pt.point_selected.point.y - vehicle_state_.y,
                          guid_pt.point_selected.point.x - vehicle_state_.x);

                if (dist2goal > dist2goal_last ||
                    AngleDiffRad(angle_this, guid_pt.road_angle)
                        > M_PI / 4.0) {
                    goal_pose = last_pose;
                    this->message_ +=
                        hmpl::StringPrintf(
                            "    use old guidance point, because old is more close to goal\n");
                }
            }
        }
    }
    goal_pose.orientation = global_path.back().z;
    return goal_pose;

}

std::string SearchMethod::GetTextMessage() {
    return this->message_;
}

void SearchMethod::chooseBestSearchPath(
    const std::vector<PathWithCost> &path_set, StatePath *path) {
    path->clear();
    if (path_set.empty()) {
        this->message_ += "    no search result\n";
        return;
    }
    *path = path_set.back().path;
    this->message_ += hmpl::StringPrintf("    choose path lower boundary:%f\n",
                                         path_set.back().dis_to_obs);
    /**path = path_set.front().path;
    if (path_set.front().energy < 5.0) {
        const double ref_energy = path_set.front().energy * 6.0;
        const double threshold = 1.0 / static_cast<double>(path_set.size());
        double total_energy = 0.0;
        for (auto it = path_set.rbegin(); it < path_set.rend(); ++it) {
            total_energy += it->energy;
        }
        for (auto it = path_set.rbegin(); it < path_set.rend(); ++it) {
            double rate = it->energy / total_energy;
            if ((rate < threshold || it->energy <= 1.0) &&
                    it->energy < ref_energy) {
                message_ += hmpl::StringPrintf(
                        "    use energy, choose lowerbound: %f\n",
                        it->lower_bound);
                *path = it->path;
                break;
            }
        }
    } else {
        double base_angle = atan2(path_set.front().path[10].y,
                                  path_set.front().path[10].x);
        for (auto it = path_set.rbegin(); it < path_set.rend(); ++it) {
            double angle = atan2(it->path[10].y, it->path[10].x);
            if (AngleDiffRad(base_angle, angle) < 0.26) { //15
                message_ += hmpl::StringPrintf(
                        "use heading, choose lowerbound: %f\n",
                        it->lower_bound);
                *path = it->path;
                break;
            }
        }
    }*/
}

void SearchMethod::SearchPath(StatePath *search_result) {
    if (roadnet_.path.empty()) {
        LOG(INFO) << "Road net is empty, search mode failed!";
        return;
    }

    this->goal_state_ = SelectGoalPoint(roadnet_.path);
    hmpl::Pose2D
        start_state(vehicle_state_.x, vehicle_state_.y, vehicle_state_.z);
    // 3.init space_explore configration
    VoronoiDiagram voronoi_diagram(in_gm_.maps, 3);
    bool display_flag = false;
    hmpl::SpaceExplore space_explore(in_gm_, display_flag, voronoi_diagram);

    // 4.search path using different circle radius
    // TODO:using different safe margin will make the path more bent, espetially in narrow place
    PathWithCost search_path;
    std::vector<PathWithCost> search_path_set;
    double lower_boundary = 1.1;
    space_explore.setLowerBoundary(lower_boundary);
//    double step = 0.3;
//    for (int i = 0; i < 4; ++i) {
//        space_explore.solve(in_gm_, start_state, goal_state_);
//        search_path.path = space_explore.getStatePath();
//        search_path.dis_to_obs = lower_boundary;
//        search_path.bending_energy = space_explore.getCirclePathEnergy();
//        if (isPathFeasible(search_path)) {
//            search_path_set.push_back(search_path);
//        } else {
//            break;
//        }
//        lower_boundary += step;
//        space_explore.setLowerBoundary(lower_boundary);
//    }
//    chooseBestSearchPath(search_path_set, search_result);
    space_explore.solve(in_gm_, start_state, goal_state_);
    search_path.path = space_explore.getStatePath();
    search_path.dis_to_obs = lower_boundary;
    search_path.bending_energy = space_explore.getCirclePathEnergy();
    if (isPathFeasible(search_path)) {
        *search_result = search_path.path;
    } else {
        hmpl::Pose2D goal_pose;
        size_t max_id = roadnet_.path.size() - 1;
        for (int i = 2; roadnet_.path[max_id / i].s >= 13; ++i) {
            hmpl::State new_state = roadnet_.path[max_id / i];
            if (IsStateAviliable(new_state, vehicle_state_)) {
                goal_pose.position.x = new_state.x;
                goal_pose.position.y = new_state.y;
                goal_pose.orientation =
                    hmpl::angle(roadnet_.path[max_id / i], roadnet_.path[max_id / i + 1]);
                break;
            }
        }
        space_explore.solve(in_gm_, start_state, goal_pose);
        search_path.path = space_explore.getStatePath();
        search_path.dis_to_obs = lower_boundary;
        search_path.bending_energy = space_explore.getCirclePathEnergy();
        if (isPathFeasible(search_path)) {
            *search_result = search_path.path;
        }
    }
}

