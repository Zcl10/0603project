//
// Created by yangt on 4/14/18.
//
#include "guidancePoint/guidance_point_selection.hpp"
#include "guidancePoint/cg_solver.hpp"
#include "guidancePoint/laser_beam_method.hpp"

guidancePointSelection::guidancePointSelection(
    hmpl::InternalGridMap &map,
    const std::vector<hmpl::State> &roadnet,
    const hmpl::State &vehicle_state,
    bool local_frame) :
    step_(1.0),
    preview_distance_(45.0),
    dis_threshold(1.0),
    use_local_frame_(local_frame),
    gridmap_(map),
    global_way_(roadnet),
    vehicle_state_(vehicle_state) {
    // TODO: mark if use ego frame, require input vehicle state is (0,0,0)
    /// set dffs search limit counts:
    grid_map::Size map_size = map.maps.getSize();
    this->iteration_limit_ =
        (this->preview_distance_) * 2 / this->step_;
    /// set dffs search direction combination
    up_as_front.resize(4);
    right_as_front.resize(4);
    down_as_front.resize(4);
    left_as_front.resize(4);
    std::vector<mapDir> dir(2);
    // up as front
    dir[0] = UP, dir[1] = LEFT;
    up_as_front[FRONT_LEFT_DIR] = dir;
    dir[0] = UP, dir[1] = RIGHT;
    up_as_front[FRONT_RIGHT_DIR] = dir;
    dir[0] = LEFT, dir[1] = UP;
    up_as_front[LEFT_DIR] = dir;
    dir[0] = RIGHT, dir[1] = UP;
    up_as_front[RIGHT_DIR] = dir;
    // right as front:
    dir[0] = RIGHT, dir[1] = UP;
    right_as_front[FRONT_LEFT_DIR] = dir;
    dir[0] = RIGHT, dir[1] = DOWN;
    right_as_front[FRONT_RIGHT_DIR] = dir;
    dir[0] = UP, dir[1] = RIGHT;
    right_as_front[LEFT_DIR] = dir;
    dir[0] = DOWN, dir[1] = RIGHT;
    right_as_front[RIGHT_DIR] = dir;
    // down as front
    dir[0] = DOWN, dir[1] = RIGHT;
    down_as_front[FRONT_LEFT_DIR] = dir;
    dir[0] = DOWN, dir[1] = LEFT;
    down_as_front[FRONT_RIGHT_DIR] = dir;
    dir[0] = RIGHT, dir[1] = DOWN;
    down_as_front[LEFT_DIR] = dir;
    dir[0] = LEFT, dir[1] = DOWN;
    down_as_front[RIGHT_DIR] = dir;
    // left as front
    dir[0] = LEFT, dir[1] = DOWN;
    left_as_front[FRONT_LEFT_DIR] = dir;
    dir[0] = LEFT, dir[1] = UP;
    left_as_front[FRONT_RIGHT_DIR] = dir;
    dir[0] = DOWN, dir[1] = LEFT;
    left_as_front[LEFT_DIR] = dir;
    dir[0] = UP, dir[1] = LEFT;
    left_as_front[RIGHT_DIR] = dir;
}

void guidancePointSelection::NextKnot(const Knot &knot_cur, Knot *next_knot) {
    next_knot->pt = knot_cur.pt;
    switch (knot_cur.next_dir) {
        case UP:next_knot->pt(0) += this->step_;
            break;
        case DOWN: next_knot->pt(0) -= this->step_;
            break;
        case LEFT: next_knot->pt(1) += this->step_;
            break;
        case RIGHT:next_knot->pt(1) -= this->step_;
            break;
        default:std::cout << "no this direction: " << knot_cur.next_dir << "\n";
    }
    if (!(gridmap_.maps.isInside(next_knot->pt))) {
        next_knot->pt = knot_cur.pt;
    }
}
void guidancePointSelection::NextDirection(mapDir *current_dir,
                                           const std::vector<mapDir> &dir_set) {
//    std::cout << "    current_dir: " << *current_dir << ", dir_set: " << dir_set[0] << ", " << dir_set[1] << std::endl;
    for (size_t i = 0; i < dir_set.size(); ++i) {
        if (dir_set[i] == *current_dir) {
            if (i == dir_set.size() - 1) {
                *current_dir = dir_set.front();
            } else {
                *current_dir = dir_set[i + 1];
            }
            break;
        }
    }
}
RoughPath guidancePointSelection::dffsSearchBasic(const std::vector<mapDir> &direction,
                                                  const grid_map::Position &start_pt) {
    RoughPath temppath;
    temppath.condition = EMPTY;
    Knot next_knot;
    next_knot.next_dir = direction[0];
    next_knot.pt = start_pt;
    int search_count = 0;
    int fail_count = 0;
//    std::cout << "****Debug begin dffs direction: " << direction[0] << std::endl;
    do {
//            std::cout << "search_count: " << search_count << std::endl;
        if (search_count >= this->iteration_limit_ || fail_count > 3) {
            temppath.condition = BAD;
//            std::cout << "  count: " << search_count << ", BAD, size:  " << temppath.path.size() << std::endl;
            break;
        }
        if (this->Travel(next_knot.pt) || search_count < 1) {
            fail_count = 0;
//                std::cout << ">>>2 in Travel! " << std::endl;
            temppath.path.push_back(next_knot);
            if (isReachBoundary(next_knot)) {
                break;
            }
            this->NextKnot(temppath.path.back(), &next_knot);
//                std::cout << ">>>3 in Travel next Node! " << std::endl;
        } else if (!temppath.path.empty()) {
            fail_count++;
//                std::cout << "***2 out map! " << std::endl;
            while ((temppath.path.back().next_dir == direction[1])
                && !temppath.path.empty()) {
                temppath.path.pop_back();
            }
            if (!temppath.path.empty()) {
//                std::cout << "***3 out map, end while:, next d = "
//                          << temppath.path.back().next_dir << std::endl;
                mapDir current_dir = temppath.path.back().next_dir;
                this->NextDirection(&current_dir, direction);
                temppath.path.back().next_dir = current_dir;
//                    std::cout << "***4 out map, next dir: " << current_dir << std::endl;
                this->NextKnot(temppath.path.back(), &next_knot);
//                    std::cout << "***5 out map, next node! " << std::endl;
            }
        }
//        std::cout << "DEbug dffs count: " << search_count << "\n";
        ++search_count;
    } while (!temppath.path.empty());
    return temppath;
}

bool guidancePointSelection::isReachBoundary(const Knot &pt) {
    const double dx = pt.pt(0) - vehicle_state_.x;
    const double dy = pt.pt(1) - vehicle_state_.y;
    const double dist = sqrt(dx * dx + dy * dy);
    if (dist > this->preview_distance_) {
        return true;
    }
    return false;
}

bool guidancePointSelection::Travel(const grid_map::Position &pt) {
    if (gridmap_.maps.isInside(pt)) {
        const auto &dist = gridmap_.maps.atPosition(gridmap_.dis, pt);
        if (dist >= this->dis_threshold) {
            return true;
        }
    }
    return false;
}
lanelet_map_msgs::Node guidancePointSelection::globalToLocal(
    const hmpl::State &ref_pt, const lanelet_map_msgs::Node &goal_pt) {
    hmpl::State result_tmp;
    if (this->use_local_frame_) {
        hmpl::State goal_state;
        goal_state.x = goal_pt.point.x;
        goal_state.y = goal_pt.point.y;
        result_tmp = hmpl::globalToLocal(ref_pt, goal_state);
    } else {
        result_tmp.x = goal_pt.point.x - ref_pt.x;
        result_tmp.y = goal_pt.point.y - ref_pt.y;
    }
    lanelet_map_msgs::Node result;
    result.point.x = result_tmp.x;
    result.point.y = result_tmp.y;
    return result;
}
lanelet_map_msgs::Node guidancePointSelection::localToGlobal(
    const hmpl::State &ref_pt, const lanelet_map_msgs::Node &goal_pt) {
    hmpl::State result_tmp;
    if (this->use_local_frame_) {
        hmpl::State goal_state;
        goal_state.x = goal_pt.point.x;
        goal_state.y = goal_pt.point.y;
        result_tmp = hmpl::localToGlobal(ref_pt, goal_state);
    } else {
        result_tmp.x = goal_pt.point.x + ref_pt.x;
        result_tmp.y = goal_pt.point.y + ref_pt.y;
    }
    lanelet_map_msgs::Node result;
    result.point.x = result_tmp.x;
    result.point.y = result_tmp.y;
    return result;
}

void guidancePointSelection::adjustToTargetPoint(lanelet_map_msgs::Node *start_pt,
                                                 const grid_map::Position &target_pt,
                                                 double adjust_dist) {
    double H_d = atan2(start_pt->point.y - vehicle_state_.y,
                       start_pt->point.x - vehicle_state_.x);
    double step = 0.5;
    const double deltax = target_pt(0) - start_pt->point.x;
    const double deltay = target_pt(1) - start_pt->point.y;
    const double deltas = sqrt(deltax * deltax + deltay * deltay);
    int count = 1;
    double adjust_th = 0.0;
    if (fabs(adjust_dist) > 0.1) {
        adjust_th = std::min(adjust_dist, deltas);
    } else {
        /// u curve
        if (use_local_frame_) {
            if (fabs(road_angle) > 1.2 ||
                start_pt->point.x * target_pt(0) < 0) {
                adjust_th = std::min(7.0, deltas);
            }
        } else {
            if (angleDiffRad(vehicle_state_.z, road_angle) > M_PI / 3.0) {
                adjust_th = std::min(7.0, deltas);
            }
        }
    }
    double tempx = start_pt->point.x + adjust_th / deltas * deltax;
    double tempy = start_pt->point.y + adjust_th / deltas * deltay;
    while (angleDiffRad(H_d, road_angle) > 0.1) { //
        tempx += count * step / deltas * deltax;
        tempy += count * step / deltas * deltay;
        grid_map::Position pt(tempx, tempy);
        if (count > 20 || !(gridmap_.maps.isInside(pt))) {
            break;
        }
        if (gridmap_.maps.atPosition(gridmap_.dis, pt) > this->dis_threshold) {
            start_pt->point.x = tempx;
            start_pt->point.y = tempy;
        } else {
            break;
        }
        H_d = atan2((tempy - vehicle_state_.y), (tempx - vehicle_state_.x));
        ++count;
    }
}

bool guidancePointSelection::laserBeamMehtodSearch(
    const grid_map::Position &goal_pt, RoughPath *path) {
//    std::cout << "Debug Begin laserBeam method!\n";
    path->path.clear();
    ///     0. make sure goal point is in the front of vehicle
    if (angleDiffRad(this->road_angle, this->vehicle_state_.z) > M_PI_2) {
        // road net is behind vehicle
        return false;
    }
    const double start_angle = (this->road_angle - M_PI_2) / M_PI * 180.0;
    const double end_angle = (this->road_angle + M_PI_2) / M_PI * 180.0;
    ///    1. get distance in each angle
    LaserBeamMethod laser_beam_method(this->gridmap_, this->vehicle_state_);
    laser_beam_method.setParams(this->preview_distance_);
    std::vector<AngleDdist> angle_dist_all;
    laser_beam_method.setCollisionThrehold(this->dis_threshold);
    laser_beam_method.getDistInEachAngle(start_angle,
                                         end_angle,
                                         &angle_dist_all);
//    std::cout << "    1. laser number: " << angle_dist_all.size() << "\n";
    if (angle_dist_all.empty() /*|| angle_dist_all.size() < 3*/) { // no laser!
        return false;
    }
    ///     2.get laser beam
    std::vector<std::vector<AngleDdist> > laser_beam_all;
    laser_beam_method.getLaserBeam(angle_dist_all, &laser_beam_all);
//        std::cout << " >>>>beam number: " << laser_beam_all.size() << std::endl;
    if (laser_beam_all.empty()) {
        return false;
    }
    double target_angle = 0;
    ///     3.get the lontitude line
    std::vector<LontituteLine> lon_line_set;
    laser_beam_method.getLontituteLine(-3.6, 3.6, &lon_line_set);
    ///     4.choose the best direction
    double best_offset = laser_beam_method.getBestOffset(lon_line_set);
    target_angle = (road_angle - atan2(best_offset, 20)) * 180.0 / M_PI;

//    std::cout << ".....roadnet angle: " << roadnet_angle << ", other angle: " << target_angle << std::endl;
    ///     5.choose the laser line which nearest to target_angle
    double angle_min = std::numeric_limits<double>::infinity();
    for (size_t i = 0; i < laser_beam_all.size(); ++i) {
        size_t index1 = 0;
        Knot temp_knot;
        for (size_t j = 0; j < laser_beam_all[i].size(); ++j) {
            // TODO: this loop is unnecessary!
            double rad = laser_beam_all[i][j].angle / 180.0 * M_PI;
            double x = vehicle_state_.x + laser_beam_all[i][j].dist * cos(rad);
            double y = vehicle_state_.x + laser_beam_all[i][j].dist * sin(rad);
            grid_map::Position pt(x, y);
            temp_knot.pt = pt;
            path->path.push_back(temp_knot);
//            std::cout << "beam[" << i <<"]" << "[" << j <<"]:" << laser_beam_all[i][j].angle << std::endl;
        }
        size_t th = 4;
        if (laser_beam_all[i].size() >= 2 * th) {
            if (index1 < th) {
                index1 = th;
            } else if (index1 > laser_beam_all[i].size() - th) {
                index1 = (laser_beam_all[i].size() - th);
            }
        } else {
            index1 = (laser_beam_all[i].size() / 2);
        }
        double angle = laser_beam_all[i][index1].angle;
        if (angleDiff(angle, target_angle) <
            angleDiff(angle_min, target_angle)) {
            angle_min = angle;
        }
    }
    /// 6. angle_min has large difference with roadnet angle, return false
    if (angleDiff(target_angle, angle_min) > 30) {
        path->path.clear();
        return false;
    }
//    if(angleDiff(angle_min, 90) < 20 && fabs(road_angle) > 1.0) {
//        return false;
//    }
//    std::cout << "    Debug laser beam2.find min angle: " << angle_min << ", path size: "<< path->path.size()<<"\n";
    ///     7.get guidance point
    double rad = angle_min / 180.0 * M_PI;
    this->point_selected.point.x =
        vehicle_state_.x + preview_distance_ * cos(rad);
    this->point_selected.point.y =
        vehicle_state_.y + preview_distance_ * sin(rad);
    this->point_selected.id = LASERBEAM;
    return true;
}
RoughPath guidancePointSelection::DFFS_Search(
    const int *dir_id,
    const std::vector<std::vector<mapDir> > &dir_set,
    grid_map::Position start_pt) {
    RoughPath path;
    path = dffsSearchBasic(dir_set[dir_id[0]], start_pt);
//    std::cout << "    >>>>1.dir1, condition: " << path.condition << ", angle: "
//              << path.angle << ", (x, y) :" << path.path.back().pt(0) << ", " << path.path.back().pt(1)<< std::endl;
    if (path.condition < GOOD) {
        while (!path.path.empty()) {
            path.path.pop_back();
            if ((!path.path.empty()) &&
                path.path.back().next_dir != LEFT &&
                path.path.back().next_dir != RIGHT) {
                start_pt = path.path.back().pt;
                path.path.pop_back();
                break;
            }
        }
        RoughPath new_path1 =
            dffsSearchBasic(dir_set[dir_id[1]], start_pt);
        if (new_path1.path.empty() && path.path.size() < 5) {
            path.condition = EMPTY;
            return path;
        } else {
            //    TODO: here may be not safe when search_path is empty!!!!!!
            path.path.insert(path.path.end(),
                             new_path1.path.begin(),
                             new_path1.path.end());
            start_pt = path.path.back().pt;
            path.path.pop_back();
            RoughPath new_path =
                dffsSearchBasic(dir_set[dir_id[0]], start_pt);
            path.path.insert(path.path.end(),
                             new_path.path.begin(),
                             new_path.path.end());
        }
    }
    if (path.path.size() > 10 && path.condition == EMPTY) {
        path.condition = GOOD;
    }
    path.angle = atan2(path.path.back().pt(1) - vehicle_state_.y,
                       path.path.back().pt(0) - vehicle_state_.x) / M_PI
        * 180.0;
//    std::cout << "    >>>>2.dir2, condition: " << path.condition << ", angle: "
//              << path.angle << ", (x, y) :" << path.path.back().pt(0) << ", " << path.path.back().pt(1)<< std::endl;
    return path;
}
void guidancePointSelection::setDffsSearchDir() {
    if (use_local_frame_) {
        this->search_forward_ = up_as_front;
    } else {
        double theta = vehicle_state_.z * 180.0 / M_PI;
        if (fabs(theta) < 45) {
            this->search_forward_ = up_as_front;
//            std::cout << "    0. up as front" << "\n";
        } else if (theta > -135 && theta < -45) {
            this->search_forward_ = right_as_front;
//            std::cout << "    0. right as front" << "\n";
        } else if (theta > 45 && theta < 135) {
            this->search_forward_ = left_as_front;
//            std::cout << "    0. left as front" << "\n";
        } else {
            this->search_forward_ = down_as_front;
//            std::cout << "    0. down as front" << "\n";
        }
    }
}

bool guidancePointSelection::dffsMethodSearch(
    const grid_map::Position &goal_pt, RoughPath *path) {
//    std::cout << "****Debug begin DFFS METHOD:********" << "\n";
    path->path.clear();
    this->point_selected.id = DFFS;
    double angle_ref = road_angle * 180.0 / M_PI;
    grid_map::Position start_pt(vehicle_state_.x, vehicle_state_.y);
    RoughPath temp_path;
    std::vector<RoughPath> path_set;
    /// 0. set search direction
    this->setDffsSearchDir();
    /// 1. search 4 direction
//    std::cout << "    1. first right dir: " << std::endl;
    int dir_id[2];
    dir_id[0] = RIGHT_DIR;
    dir_id[1] = FRONT_LEFT_DIR;
    temp_path = DFFS_Search(dir_id, search_forward_, start_pt);
    path_set.push_back(temp_path);
//    std::cout << "    2. second left dir: " << std::endl;
    dir_id[0] = LEFT_DIR;
    dir_id[1] = FRONT_RIGHT_DIR;
    temp_path = DFFS_Search(dir_id, search_forward_, start_pt);
    path_set.push_back(temp_path);
//    std::cout << "    3. third front left dir: " << std::endl;
    dir_id[0] = FRONT_LEFT_DIR;
    dir_id[1] = FRONT_RIGHT_DIR;
    temp_path = DFFS_Search(dir_id, search_forward_, start_pt);
    path_set.push_back(temp_path);
//    std::cout << "    4. fourth front right dir: " << std::endl;
    dir_id[0] = FRONT_RIGHT_DIR;
    dir_id[1] = FRONT_LEFT_DIR;
    temp_path = DFFS_Search(dir_id, search_forward_, start_pt);
    path_set.push_back(temp_path);
    /// 2. choose the nearest point to goal
    double min_angle = std::numeric_limits<double>::max();
    int index_min = -1;
//    printf("****Debug: vehicle pose: (%f, %f)\n", vehicle_state_.x, vehicle_state_.y);
    for (int i = 0; i < path_set.size(); ++i) {
//        double angle_diff = angleDiff(path_set[i].angle, angle_ref);
//        printf("****Debug: [%d]:(%f, %f), angle: %f, ref_angle: %f, diff_angle:%f, condition %d\n", i,
//               path_set[i].path.back().pt(0),
//               path_set[i].path.back().pt(1), path_set[i].angle, angle_ref, angle_diff, path_set[i].condition);
        if (angleDiff(path_set[i].angle, angle_ref) < min_angle
            && path_set[i].condition > EMPTY) {
            min_angle = angleDiff(path_set[i].angle, angle_ref);
            index_min = i;
        }
    }
    if (index_min >= 0) {
        *path = path_set.at(index_min);
//        std::cout << "    5. select point " << index_min
//                  << ": " << path->path.back().pt(0)
//                  << ", " << path->path.back().pt(1) << ", angle:"
//                  << path->angle<< ", size " << path->path.size()<< "\n";
        this->point_selected.point.x = path->path.back().pt(0);
        this->point_selected.point.y = path->path.back().pt(1);
        this->adjustToTargetPoint(&point_selected, goal_pt);
//        double angle =
//            atan2(point_selected.point.y, point_selected.point.x) * 180.0
//                / M_PI;
//        std::cout << "    6. after adjust, point: " << point_selected.point.x
//                  << ", " << point_selected.point.y  << ", angle:" << angle
//                  << "\n";
        return true;
    } else {
//        std::cout << "    EMPTY dffs path\n";
        return false;
    }
}

bool guidancePointSelection::IsReachFinalWayPoint(
    const hmpl::State &ref_state,
    const std::vector<hmpl::State> &global_way) {
    if (global_way.empty() || global_way.back().s < 3.0) {
        return true;
    } else if (global_way.back().s < 10.0) {
        lanelet_map_msgs::Node final_pt;
        final_pt.point.x = global_way_.back().x;
        final_pt.point.y = global_way_.back().y;
        this->use_local_frame_ = true;
        auto local_goal_pt = globalToLocal(vehicle_state_, final_pt);
        this->use_local_frame_ = false;
        if (local_goal_pt.point.x <= 0.0) {
            return true;
        }
    }
    return false;
}

void guidancePointSelection::searchPath() {
    /// clear variable
    this->search_path.path.clear();
    if (IsReachFinalWayPoint(vehicle_state_, global_way_)) {
        point_selected.type = "none";
        point_selected.id = ROAD_NET;
        next_way_point = point_selected.point;
        ROS_WARN("reach end point !!!");
        return;
    }

    // select the target way point:
    grid_map::Position goal_pt(global_way_.back().x, global_way_.back().y);
    this->next_way_point.x = goal_pt(0);
    this->next_way_point.y = goal_pt(1);
    this->road_offset = hmpl::distance(vehicle_state_, global_way_.front());
    this->road_angle = hmpl::angle(global_way_.front(), global_way_.back());

//    std::cout << "road_angle: " << road_angle << ", road offset: "
//              << road_offset << "\n";
    this->preview_distance_ = std::min(preview_distance_, global_way_.back().s);

    if (angleDiffRad(vehicle_state_.z, road_angle) < 25.0 / 180.0 * M_PI) {
        this->laserBeamMehtodSearch(goal_pt, &search_path);
        if (search_path.path.empty()) {
            this->dffsMethodSearch(goal_pt, &search_path);
        }
    } else {
        this->dffsMethodSearch(goal_pt, &search_path);
    }

    this->adjustToTargetPoint(&(point_selected), goal_pt);
    if (this->search_path.path.size() < 5 && point_selected.id == DFFS) {
        point_selected.type = "weak";
    } else {
        this->point_selected.type = "valid";
    }
}


