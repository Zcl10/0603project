//
// Created by yangt on 19-5-1.
//

#ifndef LOCAL_PATH_PLANNER_VISUALIZATION_HPP
#define LOCAL_PATH_PLANNER_VISUALIZATION_HPP

#include "common_function.hpp"

#include <guidancePoint/guidance_point_selection.hpp>
#include <visual_tools/visual_tools.h>
#include <state_sampling/state_sampling.hpp>
#include <ros/ros.h>

class PathPlannerVisualTools : public hmpl::VisualTools {
 public:
    PathPlannerVisualTools(ros::NodeHandle &nh,
                           ros::NodeHandle &pnh,
                           const std::string &frame_id);
    void pushRoadNetMarker(const Roadnet &roadnet,
                           const geometry_msgs::Point &ref_point);
    void pushCirclePath(const std::vector<hmpl::Circle> &circles);
    void pushOffsetPathSet(const std::map<int, PathWithCost> &path_set,
                           const StatePath &best);
    void pushGuidancePointProgress(const std::vector<Knot> &progress);
    void pushStateSamplineProgress(const hmpl::StateSampling::ObserveVariable &observe);
    void pushSamplingReferencePath(const std::vector<hmpl::State> &ref_path);
    void displayAllMarker();
 private:
    const std::string ns_;
    const std::string frame_id_;
    unsigned int marker_num_;
};

#endif //LOCAL_PATH_PLANNER_VISUALIZATION_HPP
