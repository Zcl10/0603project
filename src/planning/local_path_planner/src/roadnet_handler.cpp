//
// Created by yangt on 18-11-12.
//
#include "roadnet_handler.hpp"
#include "state_sampling/state_sampling.hpp"

RoadnetHandler::RoadnetHandler(hmpl::InternalGridMap &gridmap,
                               const hmpl::State &ref_state,
                               const geometry_msgs::Point &planning_origin,
                               int last_path_id,
                               double path_length) :
    in_gm_(gridmap),
    vehicle_state_(ref_state),
    planning_origin_(planning_origin),
    desire_max_offset_(5.0),
    offset_interval_(0.2),
    last_path_id_(last_path_id),
    path_length_(path_length),
    allow_max_offset_(5.0),
    message_("") {
    vehicle_state_planning_ = vehicle_state_;
    vehicle_state_planning_.x -= planning_origin_.x;
    vehicle_state_planning_.y -= planning_origin_.y;
}

int RoadnetHandler::BestRoadId() const {
    return this->best_path_id_;
}
void RoadnetHandler::getPathFromRoadnet(const Roadnet &roadnet,
                                        PathWithCost *path) {
    path->path.clear();
    const auto &size = roadnet.points.size();
    if (size <= 3) {
        LOG(WARNING) << "road net size is less than 3!";
        return;
    }
    size_t nearest_index = 0;
    double min_dist = std::numeric_limits<double>::max();

    for (size_t i(0); i < size; ++i) {
        double dist = Distance(roadnet.points[i].point, vehicle_state_);
        if (dist < min_dist) {
            min_dist = dist;
            nearest_index = i;
        }
    }

    path->dis_to_vehicle = min_dist;
    /// get a segment of path from topology_global_path and convert in planning frame
    size_t max_curvature_id = 0;
    double max_curvature = 1e-6;
    const auto start_id = nearest_index > 6 ? nearest_index - 6 : 0;
    hmpl::State state;
    for (std::size_t i(start_id); i + 1 < size; ++i) {
        const auto &point1 = roadnet.points.at(i);
        const auto &point2 = roadnet.points.at(i + 1);
        const double dy = point2.point.y - point1.point.y;
        const double dx = point2.point.x - point1.point.x;
        if(fabs(dy) < 1e-2 && fabs(dx) < 1e-2) {
            continue;
        }
        state.x = point1.point.x - planning_origin_.x;
        state.y = point1.point.y - planning_origin_.y;
        state.z = atan2(dy, dx);
        if (i + 2 < size - 2) {
            state.k = hmpl::getCurvature(point1,
                                         point2,
                                         roadnet.points.at(i + 2));
            if(fabs(state.k) > fabs(max_curvature)) {
                max_curvature = state.k;
                max_curvature_id = i;
            }
        }
        if (i > nearest_index && !(path->path.empty())) {
            state.s = path->path.back().s + Distance(state, path->path.back());
        } else {
            state.s = 0.0;
        }
        path->path.push_back(state);
        if (path->path.back().s > this->path_length_) {
            break;
        }
    }
    path->max_curvature = max_curvature;
    path->dis_to_max_curvature = Distance(roadnet.points.at(max_curvature_id), vehicle_state_);
    double r = 1.0 / (fabs(max_curvature) + 1e-6);
    this->allow_max_offset_ = std::min(desire_max_offset_, r);
    allow_max_id_ = std::round(allow_max_offset_ / offset_interval_);
    this->message_ +=
        hmpl::StringPrintf("    max curvature is: %f, dis to vehicle is %f, dis_to_max_curvature is %f\n",
                           max_curvature, min_dist, path->dis_to_max_curvature);
}

StatePath RoadnetHandler::moveStatePath(const StatePath &ref_path,
                                        double dir, double offset) {
    StatePath tmp_path;
    const size_t &size = ref_path.size();
    hmpl::State new_state;
    for (size_t i(0); i + 1 < size; ++i) {
        const auto &state1 = ref_path.at(i);
        const auto &state2 = ref_path.at(i + 1);
//        const double r = 1.0 / (fabs(state1.k) + 0.001);
        const double dx = state2.x - state1.x;
        const double dy = state2.y - state1.y;
        const double ds = std::sqrt(dx * dx + dy * dy);
        if (ds > 1e-4) {
            new_state.x = state1.x + offset * (-dy) / ds;
            new_state.y = state1.y + offset * dx / ds;
            tmp_path.push_back(new_state);
        }
    }
    hmpl::fillStatePath(&tmp_path);

    // negative value means right dir, possitive value means left dir;
//    hmpl::State new_pt;
//    for (const auto &pt : ref_path) {
//        new_pt = pt;
//        new_pt.x = pt.x + offset * cos(dir);
//        new_pt.y = pt.y + offset * sin(dir);
//        tmp_path.push_back(new_pt);
//    }
    return tmp_path;
}

void RoadnetHandler::getOffsetPathSet(const PathWithCost &base_path,
                                      std::map<int, PathWithCost> *path_set) {
    if (base_path.path.size() < 7) {
        this->message_ += hmpl::StringPrintf(
            "    basic roadnet's size is less than 7, disable roadnet mode!\n");
        return;
    }
    // TODO: different max offset course different path id. We need to keep the consistency of path id !!
    double offset = -allow_max_offset_;
    PathWithCost offset_path;
    int id = -this->allow_max_id_;
    while (id <= this->allow_max_id_) {
        offset_path.id = id;
        offset_path.path = moveStatePath(base_path.path, 0, offset);
        offset_path.dis_to_vehicle =
            hmpl::distance(offset_path.path.at(6), vehicle_state_planning_);
        path_set->insert(std::pair<int, PathWithCost>(offset_path.id,
                                                      offset_path));
        offset += offset_interval_;
        id++;
    }
}

int RoadnetHandler::getNearestPathId(
    const std::map<int, PathWithCost> &path_set) {
    int min_id = INT32_MAX;
    double min_dis = std::numeric_limits<double>::max();
    for (const auto &path : path_set) {
        if (path.second.dis_to_vehicle < min_dis) {
            min_id = path.second.id;
            min_dis = path.second.dis_to_vehicle;
        }
    }
    return min_id;
}

bool RoadnetHandler::isPathAccessible(const PathWithCost &path) {
    if (path.path.empty()) {
        return false;
    } else if (path.path.back().s < 25) {
        return false;
    }
    return true;
}

void RoadnetHandler::interceptCollisionFreePath(PathWithCost *ref_path) {
    size_t current_id = 0;
    hmpl::State ref_state;
    ref_state.x =
        vehicle_state_planning_.x + 3.0 * cos(vehicle_state_planning_.z);
    ref_state.y =
        vehicle_state_planning_.y + 3.0 * sin(vehicle_state_planning_.z);
    double dis_old = Distance(ref_path->path.front(), ref_state);
    double dis_now = Distance(ref_path->path.at(1), ref_state);
    for (size_t i(1); i + 1 < ref_path->path.size(); ++i) {
        const double dis_next = Distance(ref_path->path.at(i + 1), ref_state);
        if (dis_now <= dis_old && dis_now <= dis_next) {
            current_id = i;
            break;
        }
        if (dis_old <= dis_now && dis_now <= dis_next) {
            current_id = i - 1;
            break;
        }
        dis_old = dis_now;
        dis_now = dis_next;
    }

    hmpl::CollisionChecker collision_checker(this->in_gm_);
    grid_map::Position pos(ref_path->path.at(current_id).x,
                           ref_path->path.at(current_id).y);
    ref_path->dis_to_obs = in_gm_.getObstacleDistance(pos);
    StatePath tmp_path;
    int count = 0;
    for (size_t i(current_id); i < ref_path->path.size(); ++i) {
        if (collision_checker.isSingleStateCollisionFreeImproved(ref_path->path.at(
            i))) {
            count++;
        } else {
            auto begin = ref_path->path.begin() + count + current_id;
            ref_path->path.erase(begin, ref_path->path.end());
        }
    }
}
int RoadnetHandler::chooseBestPathIdFromPathSet(std::map<int,
                                                         PathWithCost> *path_set,
                                                const int last_path_id,
                                                const int current_path_id) {

    const auto alow_bias = static_cast<int>(1.4 / this->offset_interval_);
    const int start_id = std::max(current_path_id - alow_bias, -allow_max_id_);
    const int end_id = std::min(allow_max_id_, current_path_id + alow_bias);

    int near_last_id = INT32_MAX;
    int near_current_id = INT32_MAX;
    int safest_id = INT32_MAX;
    int dis_to_last = INT_MAX, dis_to_current = INT_MAX;
    double max_distance_to_obs = 0;
    for (int i(start_id); i < end_id; ++i) {
        this->interceptCollisionFreePath(&(path_set->at(i)));
        if (isPathAccessible(path_set->at(i))) {
            int dist = std::abs(i - last_path_id);
            if (dist < dis_to_last) {
                dis_to_last = dist;
                near_last_id = i;
            }
            dist = std::abs(i - current_path_id);
            if (dist < dis_to_current) {
                dis_to_current = dist;
                near_current_id = i;
            }
            if (max_distance_to_obs < path_set->at(i).dis_to_obs) {
                max_distance_to_obs = path_set->at(i).dis_to_obs;
                safest_id = i;
            }
        }
    }
    if (std::abs(near_current_id) > this->allow_max_id_
        || std::abs(near_last_id) > this->allow_max_id_) {
        this->message_ += hmpl::StringPrintf(
            "    no collision-free roadnet near current position\n");
        return INT32_MAX;
    }

    int best_id = near_last_id;

    if (isSameSign(near_last_id - current_path_id,
                   last_path_id - current_path_id)) {
        best_id = near_last_id;
    } else if (std::abs(near_current_id - last_path_id) < alow_bias) {
        best_id = near_current_id;
    }
    if (path_set->at(best_id).dis_to_obs < 3) {
        if (path_set->at(safest_id).dis_to_obs < 2.0) {
            best_id = safest_id;
        } else {
            auto sign = safest_id - best_id;
            int delta = std::min(2, std::abs(sign));
            best_id = sign > 0 ? best_id + delta : best_id - delta;
        }
    }
    this->message_ += hmpl::StringPrintf(
        "    near last id: %d, near current id: %d, safest id: %d, max dis_to obs: %f\n",
        near_last_id,
        near_current_id,
        safest_id,
        path_set->at(safest_id).dis_to_obs);
    return best_id;
}

const std::string &RoadnetHandler::getTextMessage() const {
    return this->message_;
}

bool RoadnetHandler::chooseBestPath(const PathWithCost &basic_roadnet,
                                    std::map<int, PathWithCost> *path_set,
                                    StatePath *final_path) {

    if (basic_roadnet.path.empty()
        || basic_roadnet.dis_to_vehicle > desire_max_offset_
        || path_set->empty() || fabs(basic_roadnet.max_curvature > 0.21)) {
        this->message_ += hmpl::StringPrintf("    disable roadnet mode!\n");
        return false;
    }

    int nearest_path_id = getNearestPathId(*path_set);
    last_path_id_ = last_path_id_ > INT8_MAX ? nearest_path_id : last_path_id_;
    int best_id = chooseBestPathIdFromPathSet(path_set, last_path_id_,
                                              nearest_path_id);
    message_ +=
        hmpl::StringPrintf("    current id: %d, last id: %d, best id: %d\n",
                           nearest_path_id,
                           last_path_id_,
                           best_id);
    if (best_id > INT8_MAX || path_set->at(best_id).path.empty()) {
        return false;
    } else {
        *final_path = path_set->at(best_id).path;
        this->best_path_id_ = best_id;
    }
    message_ += hmpl::StringPrintf("    best dis to obs: %f\n",
                                   path_set->at(best_id).dis_to_obs);
    return true;
}
