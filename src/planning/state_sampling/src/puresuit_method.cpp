//
// Created by yangt on 19-5-8.
//

#include "state_sampling/purepsuit_method.hpp"
namespace hmpl {

PurepursuitSampling::PurepursuitSampling(const hmpl::InternalGridMap &in_gm,
                                         const hmpl::State &vehicle_state)
    : collision_checker_(in_gm),
      vehicle_state_(vehicle_state),
      max_preview_distance_(5.0),
      max_offset_(3.0),
      offset_interval_(0.3) {

}

void PurepursuitSampling::puerpursuitSampling(const std::vector<hmpl::State> &ref_path,
                                              std::vector<hmpl::State> *output) {
    std::vector<std::vector<hmpl::State>> ref_path_set;
    const double dir = vehicle_state_.z + M_PI_2;
    double offset = -max_offset_;
    while (offset <= max_offset_) {
        std::vector<hmpl::State> offset_path;
        hmpl::State new_state;
        for (const auto &state : ref_path) {
            new_state = state;
            /// from right to left (negative offset is right)
            new_state.x = state.x + offset * cos(dir);
            new_state.y = state.y + offset * sin(dir);
            offset_path.push_back(new_state);
        }
        ref_path_set.push_back(offset_path);
        offset += offset_interval_;
    }

    this->observe_.ref_path_set = ref_path_set;

    std::vector<std::vector<hmpl::State>> candidate_path;
    this->generateCandidatePathSet(ref_path_set, &candidate_path);
    const size_t center_id = candidate_path.size() / 2;
    size_t longest_id = 0;
    size_t nearest_id = 0;
    double max_length = 0;
    for (size_t i(0); i < candidate_path.size(); ++i) {
        if (candidate_path.at(i).empty()) {
            continue;
        }
        const auto path_length = candidate_path.at(i).back().s;
        if (path_length > max_length) {
            max_length = candidate_path.at(i).back().s;
            longest_id = i;
        }
        if ((path_length > 30 || path_length > ref_path.back().s * 3 / 4)
            && std::abs(i - center_id) < std::abs(nearest_id - center_id)) {
            nearest_id = i;
        }
    }
    if (nearest_id != 0) {
        *output = candidate_path.at(nearest_id);
    } else {
        *output = candidate_path.at(longest_id);
    }
    this->observe_.sampling_path_set = candidate_path;
}

void PurepursuitSampling::generateCandidatePathSet(
    const std::vector<std::vector<hmpl::State>> &ref_path_set,
    std::vector<std::vector<hmpl::State>> *candidate_path) {
    candidate_path->clear();
    for (const auto &ref_path : ref_path_set) {
        std::vector<hmpl::State> path;
        puerpursuitPathGeneration(ref_path, &path);
        candidate_path->push_back(path);
    }
}

void PurepursuitSampling::puerpursuitPathGeneration(
    const std::vector<hmpl::State> &ref_path,
    std::vector<hmpl::State> *output) {
    if (ref_path.empty()) {
        std::cout << "control sampling: global path is empty. sampling stop."
                  << "\n";
        return;
    }
    output->clear();

    hmpl::State tmp_vehicle_state = vehicle_state_;
    output->push_back(tmp_vehicle_state);

    double max_steering_angle_by_stability =
        atan(MAXLATERALACC * LFR / pow(ref_path.front().v, 2)) * 180 / M_PI;
    max_steering_angle_by_stability =
        MAX(MAXLATERALACC_LOWERBOUND, max_steering_angle_by_stability);
    max_steering_angle_by_stability =
        MIN(MAXLATERALACC_UPPERERBOUND, max_steering_angle_by_stability);
    double incremental_threshold = 0.2;
    double actual_path_length = ref_path.back().s;
    double preview_distance = 1.2 * vehicle_state_.v;
    preview_distance =
        std::min(30.0, std::max(max_preview_distance_, preview_distance));
    while (output->back().s < actual_path_length) {
        double steering_angle = 0.0;
        /// find nearest point to tmp_vehicle from ref_path
        size_t min_index = 0;
        double mindis = std::numeric_limits<double>::infinity();
        for (size_t j = 0; j < ref_path.size(); j++) {
            double dis = hmpl::distance(ref_path.at(j), tmp_vehicle_state);
            if (dis < mindis) {
                mindis = dis;
                min_index = j;
            }
        }
        /// find preview state
        hmpl::State preview_state = ref_path.at(min_index);
        for (size_t i = min_index; i < ref_path.size(); i++) {
            preview_state = ref_path.at(i);
            double dis = hmpl::distance(preview_state, tmp_vehicle_state);
            if (dis > preview_distance)
                break;
        }
        this->observe_.preview_state_set.push_back(preview_state);
        double actual_preview_dis =
            hmpl::distance(preview_state, tmp_vehicle_state);
        if (actual_preview_dis >= preview_distance) {
            /// pure pursuit algorithm
            auto target_state_local = hmpl::globalToLocal(tmp_vehicle_state,
                                                          preview_state);
            double LD = sqrt(pow(target_state_local.x, 2) +
                pow(target_state_local.y, 2));

            if (LD > preview_distance) {
                target_state_local.x =
                    target_state_local.x * preview_distance / LD;
                target_state_local.y =
                    target_state_local.y * preview_distance / LD;
                LD = preview_distance;
            }
            if (target_state_local.x < 0) {
                if (target_state_local.y <= 0) {
                    steering_angle = -STEERINGANGLELIMIT;
                } else {
                    steering_angle = STEERINGANGLELIMIT;
                }
            } else {
                steering_angle = -purePursuitByDeltay(-target_state_local.y, LD,
                                                      LFR);
            }
        } else {
            ///stanly algorithm
            hmpl::State frontwheel_state;
            frontwheel_state.x =
                tmp_vehicle_state.x + LFR * cos(tmp_vehicle_state.z);
            frontwheel_state.y =
                tmp_vehicle_state.y + LFR * sin(tmp_vehicle_state.z);
            frontwheel_state.z = tmp_vehicle_state.z;
            size_t min_index1 = 0;
            double mindis = std::numeric_limits<double>::infinity();
            for (size_t j = 0; j < ref_path.size(); j++) {
                double dis = hmpl::distance(ref_path.at(j), frontwheel_state);
                if (mindis > dis) {
                    mindis = dis;
                    min_index1 = j;
                }
            }
            if (min_index1 + 1 == ref_path.size()) {
                break;
            }
            State target_state = ref_path.at(min_index1);
            auto target_state_local =
                globalToLocal(tmp_vehicle_state, target_state);
            if (target_state_local.x < 0) {
                if (target_state_local.y <= 0)
                    steering_angle = -STEERINGANGLELIMIT;
                else
                    steering_angle = STEERINGANGLELIMIT;
            } else {
                double deltatheta = target_state_local.z;
                while (deltatheta >= M_PI) {
                    deltatheta = deltatheta - 2 * M_PI;
                }
                while (deltatheta < -M_PI) {
                    deltatheta = deltatheta + 2 * M_PI;
                }
                auto target_state_in_frontwheel =
                    globalToLocal(frontwheel_state, target_state);
                double deviation = -target_state_in_frontwheel.y;
                double v = vehicle_state_.v;
                if (v < 4.0) {
                    v = 4.0;
                }
                steering_angle = this->stanley(deltatheta, deviation, 0.5, v);
            }
        }

        if (steering_angle > max_steering_angle_by_stability) {
            steering_angle = max_steering_angle_by_stability;
        } else if (steering_angle < -max_steering_angle_by_stability) {
            steering_angle = -max_steering_angle_by_stability;
        }
        steering_angle = MIN(MAX(-STEERINGANGLELIMIT, steering_angle),
                             STEERINGANGLELIMIT);
        /// update vehicle state according to calculated steering
        if (fabs(steering_angle) > 0.03) {
            // right is negtive and left is possitive
            double radius = LFR / tan(steering_angle * M_PI / 180.0);
            // calculate vehicle steering center
            hmpl::State center_vehicle_state;
            center_vehicle_state.x =
                tmp_vehicle_state.x - radius * sin(tmp_vehicle_state.z);
            center_vehicle_state.y =
                tmp_vehicle_state.y + radius * cos(tmp_vehicle_state.z);
            double delta_theta = incremental_threshold / radius;
            tmp_vehicle_state.z = tmp_vehicle_state.z + delta_theta;
            tmp_vehicle_state.x =
                center_vehicle_state.x + radius * sin(tmp_vehicle_state.z);
            tmp_vehicle_state.y =
                center_vehicle_state.y - radius * cos(tmp_vehicle_state.z);
            tmp_vehicle_state.k = tan(steering_angle * M_PI / 180.0) / LFR;
        } else {
            hmpl::State intermediate_state;
            intermediate_state.x = tmp_vehicle_state.x + incremental_threshold *
                cos(tmp_vehicle_state.z);
            intermediate_state.y = tmp_vehicle_state.y + incremental_threshold *
                sin(tmp_vehicle_state.z);
            tmp_vehicle_state.x = intermediate_state.x;
            tmp_vehicle_state.y = intermediate_state.y;
            tmp_vehicle_state.k = tan(steering_angle * M_PI / 180.0) / LFR;
        }
        if (collision_checker_.isSingleStateCollisionFreeImproved(
            tmp_vehicle_state)
            || !output->empty() && output->back().s < 4) {

            hmpl::State path_point = tmp_vehicle_state;
            if (output->empty()) {
                path_point.s = 0;
            } else {
                double dx = path_point.x - output->back().x;
                double dy = path_point.y - output->back().y;
                double gap = sqrt(dx * dx + dy * dy);
                path_point.s = output->back().s + gap;
            }
            output->push_back(path_point);
        } else {
            break;
        }
    }
}

double PurepursuitSampling::purePursuitByDeltay(double deltay, double Ld,
                                                double axis_dis) {
    if (deltay > Ld) {
        deltay = Ld;
    } else if (deltay < -Ld) {
        deltay = -Ld;
    }
    double exp_ang = atan2(2 * axis_dis * deltay, (Ld * Ld));
    exp_ang = exp_ang * 180 / M_PI;
    return exp_ang;
}
double PurepursuitSampling::stanley(double deltatheta, double deviation,
                                    double k, double v) {
    double exp_ang = 0.0;
    exp_ang = deltatheta + atan(k * deviation / v);
    exp_ang = exp_ang * 180 / M_PI;
    return exp_ang;
}

}
