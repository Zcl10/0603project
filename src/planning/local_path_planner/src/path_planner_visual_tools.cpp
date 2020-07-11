//
// Created by yangt on 19-5-1.
//

#include "path_planner_visual_tools.hpp"

PathPlannerVisualTools::PathPlannerVisualTools(ros::NodeHandle &nh,
                                               ros::NodeHandle &pnh,
                                               const std::string &frame_id)
    : VisualTools(nh, pnh, frame_id, "visual_marker"),
      ns_("local_path_planner"),
      frame_id_(frame_id),
      marker_num_(0) {

}

void PathPlannerVisualTools::pushRoadNetMarker(const Roadnet &roadnet,
                                               const geometry_msgs::Point &ref_point) {
    auto color = hmpl::GenerateColorRGBA(0.0, 0.0, 1.0, 0.4);
    auto name = this->ns_ + "/roadnet";
    auto path_marker = createSpheres(0.4, name, color, frame_id_);
    geometry_msgs::Point pt_tmp;
    for (const auto &pt : roadnet.points) {
        pt_tmp.x = pt.point.x - ref_point.x;
        pt_tmp.y = pt.point.y - ref_point.y;
        pt_tmp.z = 1.0;
        path_marker.points.push_back(pt_tmp);
    }
    path_marker.id = marker_num_++;
    pushMarker(path_marker);
}

void PathPlannerVisualTools::pushCirclePath(const std::vector<hmpl::Circle> &circles) {
    auto path_color = hmpl::BLACK;
    auto path_name = this->ns_ + "/circle_path";
    auto circle_name = this->ns_ + "/circles";
    auto circle_color = hmpl::SKY_BLUE;
    auto path_marker = createLineStrip(0.05, path_name, path_color, frame_id_);
    auto circle_marker =
        createSpheres(0.05, circle_name, circle_color, frame_id_);
    geometry_msgs::Point pt;
    path_marker.id = marker_num_++;
    circle_marker.id = marker_num_++;
    for (const auto &itr: circles) {
        pt.x = itr.position.x;
        pt.y = itr.position.y;
        pt.z = 0.1;
        circle_marker.points.push_back(pt);
        path_marker.points.push_back(pt);
    }
    pushMarker(circle_marker);
    pushMarker(path_marker);
}

void PathPlannerVisualTools::pushOffsetPathSet(const std::map<int, PathWithCost> &path_set,
                                               const StatePath &best) {
    auto path_name = this->ns_ + "/offset_road";
    auto path_set_marker =
        createSpheres(0.09, path_name, hmpl::SKY_BLUE, frame_id_);
    path_set_marker.id = this->marker_num_++;
    geometry_msgs::Point pt;
    for (const auto &path : path_set) {
        for (const auto &itr: path.second.path) {
            pt.x = itr.x;
            pt.y = itr.y;
            pt.z = 0.1;
            path_set_marker.points.push_back(pt);
        }
    }
    pushMarker(path_set_marker);
    auto path_marker = createLineStrip(0.05, path_name, hmpl::RED, frame_id_);
    path_marker.id = marker_num_++;
    for (const auto &itr: best) {
        pt.x = itr.x;
        pt.y = itr.y;
        pt.z = 0.1;
        path_marker.points.push_back(pt);
    }
    pushMarker(path_marker);
}

void PathPlannerVisualTools::pushGuidancePointProgress(
    const std::vector<Knot> &progress) {
    auto path_name = this->ns_ + "/guidance_point_progress";
    auto path_marker =
        createSpheres(0.4, path_name, hmpl::RED, frame_id_);
    path_marker.id = this->marker_num_++;
    geometry_msgs::Point pt;
    for (const auto &knot : progress) {
        pt.x = knot.pt(0);
        pt.y = knot.pt(1);
        pt.z = 0.1;
        path_marker.points.push_back(pt);
    }
    pushMarker(path_marker);
}

void PathPlannerVisualTools::pushStateSamplineProgress(
    const hmpl::StateSampling::ObserveVariable &observe) {
    auto path_name = this->ns_ + "state_sampling";
    auto path_marker = createLineStrip(0.05, path_name, hmpl::GREEN, frame_id_);
    for(const auto &single_stage_path_set:observe.path_set) {
        for(const auto &path:single_stage_path_set) {
            path_marker.id = this->marker_num_ ++;
            path_marker.points.clear();
            if(path.collision_free) {
                path_marker.color = hmpl::GREEN;
            } else {
                path_marker.color = hmpl::RED;
            }
            for(const auto &state:path.path) {
                geometry_msgs::Point pt;
                pt.x = state.x;
                pt.y = state.y;
                path_marker.points.push_back(pt);
            }
            pushMarker(path_marker);
        }
    }
}

void PathPlannerVisualTools::pushSamplingReferencePath(const std::vector<hmpl::State> &ref_path) {
    auto path_name = this->ns_ + "state_sampling_ref";
    auto path_marker = createLineStrip(0.05, path_name, hmpl::PINK, frame_id_);
    path_marker.id = marker_num_++;
    geometry_msgs::Point pt;
    for(const auto &state:ref_path) {
        pt.x = state.x;
        pt.y = state.y;
        path_marker.points.push_back(pt);
    }
    pushMarker(path_marker);
}

void PathPlannerVisualTools::displayAllMarker() {
//    if (this->marker_num_ > 500) {
//        marker_num_ = 0;
//        this->clearDisplay();
//    }
    marker_num_ = 0;
    display();
}