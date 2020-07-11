/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC),
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: space_explore_visual_tools.hpp
 *   Created on: 11, 23, 2018
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#ifndef SPACE_EXPLORE_SPACE_EXPLORE_VISUAL_TOOLS_HPP
#define SPACE_EXPLORE_SPACE_EXPLORE_VISUAL_TOOLS_HPP

#include <visual_tools/visual_tools.h>
#include <opt_utils/opt_utils.hpp>
#include <space_explore/space_explore.hpp>
#include <dynamic_reconfigure/server.h>
#include "space_explore/VisualParameters.h"
#include "space_explore/VisualConfig.h"
#include "circle_node_comparator.hpp"

namespace hmpl {
    using hmpl::CircleNodePtrArray;
class SpaceExploreVisualTools: public VisualTools {
 public:
    SpaceExploreVisualTools(const ros::NodeHandle &nh,
                            const ros::NodeHandle &private_nh);
    void publishDisk(const Circle &node);
    void publishChildNodes(const Circle &node);
    void publishCircle(const Circle &node);
    void publishPath(const CircleNodePtrArray &circle_path);
    void publishCirclePath(const CircleNodePtrArray &circle_path);
    void publishFinalPath(const std::vector<Vector2D<double>> &dense_path);
    void publishStart(const Circle &start);
    void publishGoal(const Circle &goal);
    std_msgs::ColorRGBA getColor(int color);
    void reconfigureRequest(space_explore::VisualConfig &config, uint32_t);
    unsigned int i = 0;
    // configurable parameters
    space_explore::VisualParameters param_;
    dynamic_reconfigure::Server<space_explore::VisualConfig> reconfigSrv_; // Dynamic reconfiguration service
};


}
#endif  // SPACE_EXPLORE_SPACE_EXPLORE_VISUAL_TOOLS_HPP
