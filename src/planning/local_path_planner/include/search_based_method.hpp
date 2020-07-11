//
// Created by yangt on 18-11-13.
//

#ifndef LOCAL_PATH_PLANNER_SEARCH_BASED_METHOD_HPP
#define LOCAL_PATH_PLANNER_SEARCH_BASED_METHOD_HPP

#pragma once
#include "common_function.hpp"
#include "guidancePoint/guidance_point_selection.hpp"

class SearchMethod {
 public:
    /**
     * constructor function for parameters initilization
     * @param gridmap : ETH grid map contains distance layer and obstacle layer
     * @param roadnet : roadnet
     * @param vehicle_state : current vehicle state
     * @param last_state : last vehicle state
     * @param last_guid_pt : the guidance point choosed in last period
     */
    SearchMethod(hmpl::InternalGridMap &gridmap, const PathWithCost &global_way,
                 const hmpl::State &vehicle_state,
                 const hmpl::State &last_guid_pt);

    /**
     * a interface function for obtaining the result of this method
     * @param search_result : the result path of searching method
     */
    void SearchPath(StatePath *search_result);

    /**
     * a interface function for obtaining goal point
     * @return  : goal point
     */
    hmpl::State GetGoalState();

    /**
     * a interface function for obtaining the selecting process of guidance point
     * @return the selecting process of guidance point
     */
    std::vector<Knot> GetGoalProgress();

    std::string GetTextMessage();

 private:

    /**
     * check wether the specified state is aviliable
     * @param test_state : input state
     * @param vehicle_state : vehicle state
     * @return : true:  the specified state is aviliable
     *            false: the specified state is unaviliable
     */
    bool IsStateAviliable(const hmpl::State &test_state,
                          const hmpl::State &vehicle_state);

    /**
     * select the guidance point
     * @param global_path : reference roadnet
     * @return : guidance point
     */
    hmpl::Pose2D SelectGoalPoint(const StatePath &global_path);

    /**
     * choose the best result from 8 different searching strategy
     * @param path_set 8 different path in terms of different search strategy
     * @param path choosed path
     */
    void chooseBestSearchPath(const std::vector<PathWithCost> &path_set,
                              StatePath *path);

    bool isPathFeasible(const PathWithCost &modified_path);

 private:
    /// ETH grid map contains distance layer and obstacle layer
    hmpl::InternalGridMap &in_gm_;
    /// guidance point selected in last period
    const hmpl::State &last_guid_pt;
    /// basic roadnet
    const PathWithCost &roadnet_;
    /// vehicle state
    const hmpl::State &vehicle_state_;
    /// goal state
    hmpl::Pose2D goal_state_;
    /// the process of guidance selection
    std::vector<Knot> goal_progress_;
    /// text message
    std::string message_;

};
#endif //LOCAL_PATH_PLANNER_SEARCH_BASED_METHOD_HPP
