/* Copyright (c) 2017, Yu Zhang, Intelligent Vehicle Research Center(IVRC),
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: state_sampling.cpp
 *   Created on: 05, 11, 2017
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include "state_sampling/state_sampling.hpp"

namespace hmpl {

StateSampling::StateSampling(InternalGridMap &grid_map, const State &start,
                             const State &end)
    : collision_checker_(grid_map),
      start_state_(start),
      goal_state_(end),
      safe_distance_(1.3),
      offset_distance_(0.2),
      max_curvature_(0.2),
      half_num_(10),
      lookahead_(16) {
    this->map_resolution_ = grid_map.maps.getResolution();
}

std::vector<hmpl::State> StateSampling::getLatGoalSetInMapFrame(const State &state) {
    // get the feasible region
    const double curvature_dead_zone = 0.05;
    double right_offset_heading;
    double left_offset_heading;
    // turning left
    right_offset_heading = state.z - M_PI / 2.0;
    left_offset_heading = state.z + M_PI / 2.0;

    std::vector<hmpl::State> lat_goals;
    hmpl::State tmp_state{};
    // define the offset sequence  , always from right to left , follow the y
    // direction
    if (state.k > curvature_dead_zone) {
        //  offsets are in right side    from right to left
        for (std::size_t i = this->half_num_ * 2 + 1; i > 0; i--) {
            tmp_state.x = state.x +
                cos(right_offset_heading) * this->offset_distance_ *
                    (i - 1);
            tmp_state.y = state.y +
                sin(right_offset_heading) * this->offset_distance_ *
                    (i - 1);
            tmp_state.z = state.z;
            tmp_state.k = state.k;
            if (collision_checker_.isSingleStateCollisionFreeImproved(tmp_state)) {
                lat_goals.push_back(tmp_state);
            }
        }
    } else if (state.k < -curvature_dead_zone) {
        //  offsets are in the left side   right region   from right to left
        for (std::size_t i = 1; i <= this->half_num_ * 2 + 1; i++) {
            tmp_state.x =
                state.x +
                    cos(left_offset_heading) * this->offset_distance_
                        * (i - 1);
            tmp_state.y =
                state.y +
                    sin(left_offset_heading) * this->offset_distance_
                        * (i - 1);
            tmp_state.z = state.z;
            tmp_state.k = state.k;
            // test collision

            if (collision_checker_.isSingleStateCollisionFreeImproved(tmp_state)) {
                lat_goals.push_back(tmp_state);
            }
        }
    } else {
        // middle region   from right to left
        // right portion
        for (std::size_t i = this->half_num_; i > 0; --i) {
            tmp_state.x =
                state.x +
                    cos(right_offset_heading) * this->offset_distance_
                        * i;
            tmp_state.y =
                state.y +
                    sin(right_offset_heading) * this->offset_distance_
                        * i;
            tmp_state.z = state.z;
            tmp_state.k = state.k;
            if (collision_checker_.isSingleStateCollisionFreeImproved(tmp_state)) {
                lat_goals.push_back(tmp_state);
            }
        }
        // middle state
        if (collision_checker_.isSingleStateCollisionFreeImproved(state)) {
            lat_goals.push_back(state);
        }

        // left portion
        for (std::size_t i = 1; i <= this->half_num_; i++) {
            tmp_state.x = state.x +
                cos(left_offset_heading) * this->offset_distance_ * i;
            tmp_state.y = state.y +
                sin(left_offset_heading) * this->offset_distance_ * i;
            tmp_state.z = state.z;
            tmp_state.k = state.k;
            if (collision_checker_.isSingleStateCollisionFreeImproved(tmp_state)) {
                lat_goals.push_back(tmp_state);
            }
        }
    }
    return lat_goals;
}

void StateSampling::deepStateSampling(std::vector<State> &curve,
                                      const State &start, const State &end) {
    if (curve.empty()) {
        std::cout << "state sampling: global path is empty. sampling stop."
                  << "\n";
        return;
    }
    // get the longitudinal goal set in map frame:
    std::vector<State> longitudinal_set =
        getLonGoalSet(this->start_state_, curve, this->lookahead_);

    this->local_start_state_ = this->start_state_;
    // std::cout << "longitudinal goal set:" << longitudinal_set.size() <<
    // std::endl;
    for (std::size_t i = 0; i < longitudinal_set.size(); i++) {
        // std::cout << "path segment:" << i+1 << std::endl;
        if (!singlePhaseStateSampling(this->local_start_state_,
                                      longitudinal_set.at(i))) {
            break;
        }
    }

    // global path  create
    // this->singlePhaseStateSampling(this->start_state_,
    // longitudinal_set.front());goal
    // this->singlePhaseStateSampling(this->local_start_state_,
    // longitudinal_set.at(0));
    // this->singlePhaseStateSampling(this->local_start_state_,
    // longitudinal_set.at(1));
}

std::vector<hmpl::State> StateSampling::getLonGoalSet(
    const State &start, const std::vector<State> &curve, double lookahead) {
    // search in global frame
    // do a global search and get
    std::size_t closest_index;
    // getClosestPointOnPath(start, curve, )
    std::vector<State> longitude_goal_set;
    this->generateSequentialGoals(start, curve, &longitude_goal_set, lookahead);

    return longitude_goal_set;
}
bool StateSampling::getClosestPointOnPath(const State &recent_state,
                                          const std::vector<State> &curve,
                                          State *closest,
                                          std::size_t *closest_index) {
    double distance = std::numeric_limits<double>::infinity();

    for (std::size_t i = 0; i < curve.size(); i++) {
        double temp_distance = getNorm(recent_state, curve.at(i));
        if (temp_distance <= distance) {
            distance = temp_distance;
            *closest_index = i;
        }
    }
    *closest = curve.at(*closest_index);
    return true;
}
bool StateSampling::generateSequentialGoals(const State &recent_state,
                                            const std::vector<State> &curve,
                                            std::vector<State> *longitude_goals,
                                            double lookahead) {
    // get the closest goal point
    std::size_t closest_index;
    State closest_state;
    this->getClosestPointOnPath(this->start_state_, curve, &closest_state,
                                &closest_index);
    // based on lookahead distance to determine the goal sequence
    //
    double remained_length = curve.back().s - closest_state.s;

    // divide the path base on look ahead distance
    int segs = static_cast<int>(remained_length / lookahead);

    longitude_goals->clear();
    int seg_count = 1;
    for (std::size_t i = closest_index; i < curve.size(); i++) {
        if (curve.at(i).s - closest_state.s > seg_count * lookahead) {
            if (seg_count == segs) {
                longitude_goals->push_back(curve.back());
            } else {
                longitude_goals->push_back(curve.at(i));
            }
            seg_count++;
        }
    }
    if (longitude_goals->empty()) {
        longitude_goals->push_back(goal_state_);
    } else if (hmpl::distance(longitude_goals->back(), goal_state_)
        > lookahead * 2 / 3) {
        longitude_goals->push_back(goal_state_);
    } else {
        longitude_goals->pop_back();
        longitude_goals->push_back(goal_state_);
    }
    // the last goal point
    // longitude_goals->push_back(this->curve_.back());

    return false;
}

bool StateSampling::singlePhaseStateSampling(const State &start_intermediate,
                                             const State &end_intermediate) {
    // the map is known
    // Both inputs are in global frame
    // get a pair of states in ego frame
    double angle_diff = angleDiffRad(end_intermediate.z, start_intermediate.z);
    if (angle_diff > 4*M_PI / 9.0) {
        return false;
    }

    std::vector<State>
        lateral_goal_set = getLatGoalSetInMapFrame(end_intermediate);

    // solve optimize
    // set the lower and upper boundary
    double curvature_max = this->max_curvature_;
    double lower_bounds[3] = {-curvature_max, -curvature_max, 0.0};
    double uppper_bounds[3] = {curvature_max, curvature_max, 100};

    // resolution

    // transform the problem to origin and solve it, generate path in ego frame
    // to do collision checking
    // transform the goals in place
    State opt_start{};
    opt_start.k = start_intermediate.k;
//    opt_start.k = start_in_ego.k;
    std::vector<PathWithCost> path_set;

    // get the local goal on the global path
    // this is used to calculated lateral distance cost to the global path
    State goal_in_local = globalToLocal(start_intermediate, end_intermediate);
    double max_lateral_distance = 0;
    // for each lateral goal
    for (auto &goal_itr : lateral_goal_set) {
        // convert to intermediate local frame

        State offset_goal_local =
            globalToLocal(start_intermediate, goal_itr);  // in place converting

        double distance_to_goal = getNorm(goal_in_local, offset_goal_local);
        if (distance_to_goal > max_lateral_distance) {
            max_lateral_distance = distance_to_goal;
        }

        offset_goal_local.z =
            atan2(sin(offset_goal_local.z), cos(offset_goal_local.z));
        // offset_goal_local.k = 0;
        double dist_lower_bound = getNorm(offset_goal_local);
        double param[3] = {0, 0, dist_lower_bound};
        hmpl::NLPSolver nlp_solver(hmpl::SolverType::CERES);
        ParamKnot solution;
        bool res;
        if (dist_lower_bound == 0) {
            std::cout << "wait for the input." << "\n";
        } else {
            // solve BVP problem
            res = nlp_solver.solve(opt_start, offset_goal_local, param,
                                   lower_bounds, uppper_bounds, &solution);

            if (res) {
                // get the solution and path
                ParamCoefficient param_co = hmpl::knotToCoefficient(solution);
                PathWithCost path;
                std::vector<State> state_path = hmpl::sampleCubicSpiralByLength(
                    opt_start, param_co, this->map_resolution_);
                // the path is still in the opt_start
                path.cost = 0.0;
                for (auto &state_itr : state_path) {
                    // convert back to ego frame
                    state_itr = localToGlobal(start_intermediate, state_itr);
                    // save the path to the vector
                    path.path.push_back(state_itr);
//                    grid_map::Position pt(state_itr.x, state_itr.y);
//                    if(grid_map_.maps.isInside(pt)) {
//                        path.cost += 1.0 / (grid_map_.maps.atPosition(grid_map_.dis, pt) + 0.01);
//                    }
                }
                path.origin = start_intermediate;
                path.goal_cost = distance_to_goal;
                path.param = solution;
                path.bending_cost =
                    SIBendingEnergy::getSIBendingEnergy(solution);
                // convert local goal to global frame, not ego frame
//                State actual_goal_in_global =
//                        localToGlobal(this->start_state_, goal_itr);
//                path.goal = actual_goal_in_global;
                path.goal = goal_itr;
                path.cost += path.goal_cost + 4 * path.bending_cost;
//                std::cout << "*****Debug: goal cost " << path.goal_cost << ", bending: " << path.bending_cost << "\n";
                // now the path is ego frame, ready to do collision checking
                path_set.push_back(path);
            }
        }
    }

    // normalize the goal distance cost
    if (max_lateral_distance != 0) {
        for (auto &path_itr : path_set) {
            path_itr.goal_cost = path_itr.goal_cost / max_lateral_distance;
        }
    }
    // collision checking and path selection
    this->staticCollisionChecking(&path_set);
    this->observe_.path_set.push_back(path_set);
    this->observe_.goal_state_set.push_back(lateral_goal_set);
    if (!this->selectBestPath(path_set)) {
        std::cout << "segment " << observe_.path_set.size()
                  << " doesn't have a path available." << "\n";
        return false;
    }

    // solver optimization

    return true;
}

void StateSampling::staticCollisionChecking(
    std::vector<PathWithCost> *path_set) {
    if (path_set->empty()) {
        std::cout << " No path to check collision. " << "\n";
        return;
    }

    for (auto &path_itr : *path_set) {
        // every path
        path_itr.collision_free =
            collision_checker_.isSinglePathCollisionFreeImproved(&(path_itr.path));
        // path_itr.collision_free = this->isSinglePathCollisionFree(&(path_itr.path));
    }
}

bool StateSampling::selectBestPath(const std::vector<PathWithCost> &path_set) {
    if (path_set.size() == 0) {
        return false;
    }
    int count = 0;
    int min_index = -1;
    double min_distance_cost = std::numeric_limits<double>::max();
    for (auto &path_itr : path_set) {
        if (path_itr.collision_free && path_itr.cost < min_distance_cost) {
            min_distance_cost = path_itr.cost;
            min_index = count;
        }
        count++;
    }
    if (min_index < 0) {
        return false;
    }

    // push the collision free path with minimum cost to
//    this->single_phase_path_ = path_set.at(min_index);
    this->local_start_state_ = path_set.at(min_index).goal;
    this->sequential_path_set_.push_back(path_set.at(min_index));
//    this->single_phase_path_set_ = path_set;
    return true;
}
std::vector<State> StateSampling::getFinalPath() {
    this->final_path_.clear();
    if (this->sequential_path_set_.empty()) {
        return this->final_path_;
    } else {
        double base = 0;
        this->final_path_.push_back(this->start_state_);
        for (auto &path_itr : sequential_path_set_) {
            for (std::size_t i = 1; i < path_itr.path.size(); i++) {
                State state = path_itr.path.at(i);
//                        localToGlobal(this->start_state_, path_itr.path.at(i));
                state.s = state.s + base;
                this->final_path_.push_back(state);
            }
            base = final_path_.back().s;
        }
    }
    return this->final_path_;
}

double StateSampling::angleDiffRad(double rad1, double rad2) {
    double result = fabs(rad1 - rad2);
    result = result > M_PI ? (2 * M_PI - result) : result;
    return fabs(result);
}
void StateSampling::setMaxCurvature(double velocity) {
    if (velocity < 2.0) {
        this->max_curvature_ = 0.22;
    } else if (velocity > 8.0) {
        this->max_curvature_ = 0.0491;
    } else {
        this->max_curvature_ =
            0.0002332 * pow(velocity, 4) - 0.005045 * pow(velocity, 3) +
                0.03894 * pow(velocity, 2) - 0.1496 * pow(velocity, 1)
                + 0.381;
    }
}

}  // namespace hmpl
