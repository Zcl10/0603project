//
// Created by yangt on 4/24/18.
//
#include "guidancePoint/laser_beam_method.hpp"
LaserBeamMethod::LaserBeamMethod(hmpl::InternalGridMap &map,
                                 const hmpl::State &vehicle_state,
                                 double resilution, double step)
    : local_map_(map),
      vehicle_state_(vehicle_state) {
    this->angle_resolution_ = resilution;
    this->laser_line_step_ = step;
    this->collision_circle_ = 1.0;
    this->lat_offset_resolution_ = 0.2;
    this->laser_length_limit_ = 35.0;
}
void LaserBeamMethod::setParams(double pre_distance,
                                double resolution,
                                double step) {
    this->laser_length_limit_ = pre_distance;
    this->angle_resolution_ = resolution;
    this->laser_line_step_ = step;
}
void LaserBeamMethod::setCollisionThrehold(double value) {
    this->collision_circle_ = value;
}
bool LaserBeamMethod::isCollision(double x, double y) {
    grid_map::Position pt(x, y);
    if (local_map_.maps.isInside(pt)) {
        double dist = this->local_map_.maps.atPosition(local_map_.dis, pt);
        if (dist > collision_circle_) {
            return false;
        }
    }
    return true;
}
void LaserBeamMethod::getDistInEachAngle(double start_angle,
                                         double end_angle,
                                         std::vector<AngleDdist> *angle_dist) {
    const auto size =
        static_cast<int>((end_angle - start_angle) / angle_resolution_);
//    std::cout << "angle size:  "<< size <<std::endl;
    AngleDdist temp_ad;
    for (int i = 0; i < size; ++i) {
        /// 与y轴正向夹角为0度，顺时针旋转
        temp_ad.angle = start_angle + (i * angle_resolution_);
        temp_ad.dist = 0.0;
        double dist = 1.5;
        const double tempAngle = temp_ad.angle * M_PI / 180.0;
        while (true) {
            const double x = vehicle_state_.x + dist * cos(tempAngle);
            const double y = vehicle_state_.y + dist * sin(tempAngle);
            if (isCollision(x, y)) {
//                std::cout << i << ":dist " << temp_ad.dist << std::endl;
                if (temp_ad.dist > laser_length_limit_) {
                    angle_dist->push_back(temp_ad);
                }
                break;
            } else {
                temp_ad.dist = dist;
            }
            dist += this->laser_line_step_;
        }
    }
}

void LaserBeamMethod::getLontituteLine(double lower, double upper,
                                       std::vector<LontituteLine> *line_set) {
    //from left to right
    LontituteLine line;
    double lat_offset = lower;
    const double heading = vehicle_state_.z;
    while (lat_offset < upper) {
        line.offset = lat_offset;
        line.dist = 0.0;
        double lon_dist = 2.0;
        while (true) {
            double x = vehicle_state_.x + lat_offset * sin(heading)
                + lon_dist * cos(heading);
            double y = vehicle_state_.y - lat_offset * cos(heading)
                + lon_dist * sin(heading);
            if (isCollision(x, y)) {
//                std::cout << "    offset: " << line.offset << ", dist: " << x << std::endl;
                if (lon_dist > 20.0) {
                    line.dist = lon_dist;
                    line_set->push_back(line);
                }
                break;
            }
            lon_dist += laser_line_step_;
        }
        lat_offset += this->lat_offset_resolution_;
    }
}
double LaserBeamMethod::getBestOffset(
    const std::vector<LontituteLine> &line_set) {
    int right_count = 0;
    int left_count = 0;
    for (const auto &line:line_set) {
        if (line.offset > 0) {
            right_count++;
        } else {
            left_count++;
        }
    }
    double offset = ((right_count - left_count) * lat_offset_resolution_);
//    std::cout << ">>>>>>>>left: " << left_count << ", right: " << right_count << std::endl;
    return offset;
}

void LaserBeamMethod::getLaserBeam(const std::vector<AngleDdist> &disAngle,
                                   std::vector<std::vector<AngleDdist>> *laser_beam) {
    if (disAngle.empty()) {
        return;
    } else if (disAngle.size() < 2) {
        laser_beam->push_back(disAngle);
        return;
    }
    std::vector<AngleDdist> currentBeam;
    currentBeam.push_back(disAngle.at(0));
    double last_angle = disAngle.at(0).angle;
//    std::cout << "input size: " << disAngle.size() << std::endl;
    for (size_t i(1); i < disAngle.size(); ++i) {
        double tempAngle = disAngle.at(i).angle;
        if (fabs(last_angle - tempAngle) > 3 ||
            i == disAngle.size() - 1) { // current beam is over
            if (currentBeam.size() > 1) {
                laser_beam->push_back(currentBeam);
            }
            currentBeam.clear();
        }
        currentBeam.push_back(disAngle.at(i));
        last_angle = tempAngle;
    }
}

//void LaserBeamMethod::selectProbAngle(
//        const std::vector<std::vector<AngleDdist> > &laserBeam,
//        AngleDdist *disAngle) {
//    int beam_id = 0;
//    int max_num = 0;
//    for(int i = 0; i < laserBeam.size(); ++i) {
//        if (laserBeam[i].size() > max_num) {
//            max_num = laserBeam[i].size();
//            beam_id = i;
//        }
//    }
//    int center_id = laserBeam[beam_id].size() / 2;
//    *disAngle = laserBeam[beam_id][center_id];
//}
//void LaserBeamMethod::getAnglesNearTo90InEachBeam(
//        const std::vector<AngleDdist> &input, std::vector<AngleDdist> *output) {
//    output->clear();
//    int size = input.size();
//    if (size <= 0) {
//        std::cout << "input angle-dist parirs is empty!" << std::endl;
//        return;
//    }
//    /// initial angle in each laser beam;
//    double beam_start_angle = input.at(0).angle;
//    int beamAngleNum = 0;
//    std::vector<AngleDdist> currentBeam;
//    currentBeam.push_back(input.front());
//    for(int i = 1; i < input.size(); ++i) {
//        double tempAngle = input.at(i).angle;
//        if (fabs(tempAngle - beam_start_angle) > 2.0) { // current beam is over
//            if (currentBeam.size() < 2) { // just only one laser line!
//                currentBeam.clear();
//            } else {
//                double last_angle = 270;
//                int id = 0;
//                for (int j = 0; j < currentBeam.size(); ++j) {
//                    double a = fabs(last_angle - 90);
//                    double b = fabs(currentBeam[j].angle - 90);
//                    a = (a>180) ? (360-a) : a;
//                    b = (b>180) ? (360-b) : b;
//                    if(b < a) {
//                        last_angle = currentBeam[j].angle;
//                        id = j;
//                    }
//                }
//                output->push_back(currentBeam[id]);
//            }
//            currentBeam.clear();
//            beam_start_angle = tempAngle;
//            currentBeam.push_back(input.at(i));
//        }
//    }
//}
//
//bool LaserBeamMethod::getProbCrossPos(const std::vector<AngleDdist> &input,
//                                      std::vector<Prob_cross> *prob_pos,
//                                      std::vector<Prob_cross> *cross_got) {
//    prob_pos->clear(); // 确定要清空吗？
//    Prob_cross single_road;
//    bool prob_valid = false;
//    for (int i = 0; i < input.size(); ++i) {
//        bool match_failed = true;
//        double out_vec_angle = input[i].angle * M_PI / 180; //lzz
//        for (int j = 0; j < prob_pos->size(); j++) {
////            out_vec_angle = unifytheta(out_vec_angle);
//            double delta_angle =
//                    fabs((out_vec_angle - prob_pos->at(j).d.angle));
//            if (delta_angle < 10 * M_PI / 180) { //delta_angle < 10 才会执行？
//                prob_pos->at(j).d.angle = (prob_pos->at(j).d.angle
//                                           + out_vec_angle) / 2;
//                prob_pos->at(j).update = true;
//                double S = 0;
//                double prob_m_z = 0.7;
//                S = prob_m_z / (1 - prob_m_z) * prob_pos->at(j).weight
//                    / (1 - prob_pos->at(j).weight);
//                prob_pos->at(j).weight = S / (1 + S);
//                if (prob_pos->at(j).weight > 1.0 - 0.02) {
//                    prob_pos->at(j).weight = 1.0 - 0.02;
//                }
//                match_failed = false;
//                break;
//            }
//        }
//        if (match_failed) {
////            double out_vec_angle = input[i].angle * M_PI / 180; //lzz
////            out_vec_angle = unifytheta(out_vec_angle);
//            single_road.d.angle = out_vec_angle;
//            single_road.weight = 0.7;
//            single_road.update = true;
//            prob_pos->push_back(single_road);
//        }
//    }
//    cross_got->clear();
//    for (int i = 0; i < prob_pos->size(); i++) {
//        if (prob_pos->at(i).weight > 0.9) {
//            prob_valid = true;
//            auto d = prob_pos->at(i);
//            cross_got->push_back(d);
//        } else if (prob_pos->at(i).weight < 0.5) {
//            prob_pos->erase(prob_pos->begin() + i);
//            i--;
//        }
//    }
//    // 挑里面概率最大的?
//    double max_prob = 0.0;
//    int id;
//    for(int i = 0; i < prob_pos->size(); ++i) {
//        if(prob_pos->at(i).weight > max_prob) {
//            max_prob = prob_pos->at(i).weight;
//            id = i;
//        }
//    }
//    this->cross_prob = prob_pos->at(id).d;
//    return prob_valid;
//}

