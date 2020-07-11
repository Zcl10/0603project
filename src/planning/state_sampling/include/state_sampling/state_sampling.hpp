/* Copyright (c) 2017, Yu Zhang, Intelligent Vehicle Research Center(IVRC),
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: state_sampling.hpp
 *   Created on: 05, 07, 2017
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#ifndef STATE_SAMPLING_STATE_SAMPLING_HPP
#define STATE_SAMPLING_STATE_SAMPLING_HPP
//#include <internal_grid_map/internal_grid_map.hpp>
#include <opt_solver/nlp_solver.hpp>
#include <opt_utils/utils.hpp>
//#include <car_model/car_geometry.hpp>
#include "collosion_checker.hpp"

namespace hmpl {

class StateSampling {
 public:
    struct ObserveVariable {
        std::vector<std::vector<hmpl::State>> goal_state_set;
        std::vector<std::vector<hmpl::PathWithCost>> path_set;
    };

    StateSampling(InternalGridMap &grid_map, const State &start,
                  const State &end);

    double angleDiffRad(double rad1, double rad2);

    /**
     * The function is to get lateral goal sets represented in recent vehicle
     * frame.
     * The reason all the paths should be in recent vehicle frame is that all
     * collsion checking need to be done in
     * If some of the goal states are not collision free, the goal state won't
     * be pushed
     * local frame.  The grid map data lie in ego frame.
     * @param state Goal state in global frame
     * @return The goal state set represented in local frame
     */
    std::vector<hmpl::State> getLatGoalSetInMapFrame(const State &state);

    /**
     * The function will generate offset goal set based on the clearance
     * Given an upper bound for the clearance, the distance between nerbouring
     * goal are
     * adaptive.
     * Implementation.TODO
     * @param state
     * @param upper_bounds
     * @return
     */
    std::vector<hmpl::State> getLatGoalSetAdaptive(const State &state,
                                                   double upper_bounds);

    /**
     * Segment the longitudinal planning stages
     * @param start Current vehicle state
     * @param curve The global path
     * @param lookahead The look ahead distance of every segment in terms of
     * arclenth
     * @return The Longitude goal set
     */
    std::vector<hmpl::State> getLonGoalSet(const State &start,
                                           const std::vector<State> &curve,
                                           double lookahead);

    /**
     * Get the closest point to the recent vehicle state on the path
     * @param recent_state The recent state of the car
     * @param curve The modified global path
     * @return The path point in the global frame
     */
    bool getClosestPointOnPath(const State &recent_state,
                               const std::vector<State> &curve, State *closest,
                               std::size_t *closest_index);

    /**
     * Get the sequencial goals represented in global frame
     * @param recent_state The current state of the vehicle
     * @param curve  The modified path in global frame
     * @param longitude_goals The vector to store generated sequential goal
     * states
     * @param lookahead The arc length of every segment
     * @return true if succeed
     */
    bool generateSequentialGoals(const State &recent_state,
                                 const std::vector<State> &curve,
                                 std::vector<State> *longitude_goals,
                                 double lookahead);

    /**
     * Both states are in the global frame
     * @param start_intermediate start state in gloal_frame
     * @param end_intermediate end state in global frame
     * @return true if get a feasible best path
     */
    bool singlePhaseStateSampling(const State &start_intermediate,
                                  const State &end_intermediate);

    bool selectBestPath(const std::vector<PathWithCost> &path_set);

    /**
     *
     * @param grid_map
     * @param curve
     * @param start
     * @param end
     */
    void deepStateSampling(std::vector<State> &curve, const State &start,
                           const State &end);

    void setMaxCurvature(double velocity);

    /**
     * Safe distance
     * @param distance The distance
     */
    void setSafeDistance(double distance) { this->safe_distance_ = distance; }

    /**
     *
     * @param offset
     */
    void setOffsetDistance(double offset) { this->offset_distance_ = offset; }

    /**
     *
     * @param half_num
     */
    void setHalfNumOfPath(std::size_t half_num) { this->half_num_ = half_num; }

    /**
     * Set the lookahead distance for segmenting
     * @param distance lookahead distance
     */
    void setLookaheadDistance(double distance) { this->lookahead_ = distance; }

    /**
     *
     * @param path_set Path represented in ego frame
     * @return
     */
    void staticCollisionChecking(std::vector<PathWithCost> *path_set);

    /**
     *   Get the lookahead distance
     * @return the distance
     */
    double getLookaheadDistance() { return this->lookahead_; }

    double getHalfNum() { return this->half_num_; }

    State getLocalGoal() { return this->local_goal_state_; }

    const ObserveVariable &observeVariable() const {
        return this->observe_;
    }

    std::vector<PathWithCost> getSquentialPathSet() const {
        return this->sequential_path_set_;
    }

    /// final path in global frame
    std::vector<State> getFinalPath();

 private:
    hmpl::State start_state_;          // in global frame
    hmpl::State goal_state_;           // in global frame
    hmpl::State local_start_state_;    // in global frame
    hmpl::State local_goal_state_;     // in global frame
    hmpl::CollisionChecker collision_checker_;
    double max_curvature_;

    double safe_distance_;    //
    double offset_distance_;  // offset distance between paths
    std::size_t half_num_;  // the total path number is always odd. To guarantee
    // this, we use
    // half number of the path, total path = 2 * half_num_ + 1
    double lookahead_;  // lookahead distance
    double map_resolution_;

    // multiple phase paths
    std::vector<PathWithCost> sequential_path_set_{};

    ObserveVariable observe_;

    // the final path
    std::vector<State> final_path_;
};
}  // namespace hmpl

#endif  // STATE_SAMPLING_STATE_SAMPLING_HPP
