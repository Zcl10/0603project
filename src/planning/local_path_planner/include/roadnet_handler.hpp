//
// Created by yangt on 18-11-12.
//

#ifndef LOCAL_PATH_PLANNER_ROADNET_HANDLER_HPP
#define LOCAL_PATH_PLANNER_ROADNET_HANDLER_HPP

#pragma once
#include "common_function.hpp"
#include <internal_grid_map/internal_grid_map.hpp>

class RoadnetHandler {
 public:
    /**
     * constructor function for parameter initialization
     * @param gridmap : ETH grid map contains distance layer and obstacle layer
     * @param last_path_id : the closet path in last period
     * @param path_length : path length need to be generated
     */
    RoadnetHandler(hmpl::InternalGridMap &gridmap,
                   const hmpl::State &ref_state,
                   const geometry_msgs::Point &planning_origin,
                   int last_path_id,
                   double path_length);

    /**
     * abstract a specified length of path and do a type transformation
     * @param roadnet : the origin road received from topic
     * @param ref_state : current vehicle state
     * @param path : a specified length of roadnet typed 'StatePath'
     */
    void getPathFromRoadnet(const Roadnet &roadnet,
                            PathWithCost *path);

    /**
     * get a series of bias path
     * @param base_path : input basic roadnet
     * @param path_set : all of the offset path
     */
    void getOffsetPathSet(const PathWithCost &base_path,
                          std::map<int, PathWithCost> *path_set);

    /**
     * output the result of this method which gets the best path from a series
     * of bias roadnet
     * @param basic_roadnet : a specified length of basic roadnet
     * @param final_path : the choosed bias roadnet
     * @param path_set : offset path set
     * @return  false : there is no aviliable bias road
     *           true  : get a bias road successfully
     */
    bool chooseBestPath(const PathWithCost &basic_roadnet,
                        std::map<int, PathWithCost>  *path_set,
                        StatePath *final_path);

    /**
     * get the nearset bisa road id . The id of right-most road is 0, increased
     * from right to left
     * @return the nearest bias road id
     */
    int BestRoadId() const;

    /**
     * get debug message when running in roadnet mode
     * @return : debug text message
     */
    const std::string &getTextMessage() const;

 private:
    /**
     * choose the best bias road id from path set. The id of right-most road is
     * 0, increased from right to left
     * @param path_set : a series of bias roadnet
     * @param last_id : the best id choosed in last period
     * @param nearest_id : the nearest bias road id
     * @return the best bias id
     */
    int chooseBestPathIdFromPathSet(std::map<int, PathWithCost>  *path_set,
                                    const int last_path_id,
                                    const int current_path_id);

    /**
     * move the reference path some distance along the specified direction
     * @param ref_path : reference path
     * @param dir : translation direction
     * @param offset : translation distance
     * @return : the path after translation
     */
    StatePath moveStatePath(const StatePath &ref_path, double dir,
                            double offset);

    /**
     * check wether the path is aviliable
     * @param path : input path
     * @return : false: the path is not accessible
     *            true:  the path is accessible
     */
    bool isPathAccessible(const PathWithCost &path);

    /**
     * abstract a segment of collision-free path from reference path, beginning
     * from path head
     * @param ref_path : reference path need to be intercepted
     */
    void interceptCollisionFreePath(PathWithCost *ref_path);

    /**
     * get the nearest path id from a series of bias path
     * @param path_set : a series of path
     * @return : the nearest id
     */
    int getNearestPathId(const std::map<int, PathWithCost> &path_set);

 private:
    /// ETH grid map contains distance layer and obstacle layer
    hmpl::InternalGridMap &in_gm_;
    /// vehicle state
    const hmpl::State &vehicle_state_;
    hmpl::State vehicle_state_planning_;
    /// planning origin point
    const geometry_msgs::Point &planning_origin_;
    /// the max offset distance,
    const double desire_max_offset_;
    int allow_max_id_;
    /// allowable max offset from curvature
    double allow_max_offset_;
    /// the translation resolution
    const double offset_interval_;
    /// the best bias roadnet id
    int best_path_id_;
    /// last best bias roadnet id
    int last_path_id_;
    /// a specified length
    double path_length_;
    /// roadnet related output message
    std::string message_;
};
#endif //LOCAL_PATH_PLANNER_ROADNET_HANDLER_HPP
