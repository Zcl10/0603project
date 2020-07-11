//
// Created by yangt on 19-5-8.
//

#ifndef STATE_SAMPLING_COLLOSION_CHECKER_HPP
#define STATE_SAMPLING_COLLOSION_CHECKER_HPP

#include <internal_grid_map/internal_grid_map.hpp>
#include <car_model/car_geometry.hpp>

namespace hmpl {

class CollisionChecker {
 public:
    CollisionChecker(const hmpl::InternalGridMap &in_gm);
    /**
     * Path in global frame.  Collsion checking using footprint of the car.
     * Fill the collision flag to v field of State.  0 : collision,  1:
     * collision-free. Use 0 for collision because the initial value is 0. The
     * collision checking function will update the flag.
     * @param curve Path in ego frame
     * @return true if collision free, false otherwise. This funciton also modify
     * the v field of the state on the path. 0: collision, 1: collision-free
     */
    bool isSinglePathCollisionFree(std::vector<State> *curve);

    /**
     * Path in global frame.  Collsion checking using bounding box first, if
     * collision occures, then check collisions using footprint circles
     * Fill the collision flag to v field of State.  0 : collision,  1:
     * collision-free
     * @param curve Path in the ego frame
     * @return true if the path is collision-free, false otherwise
     */
    bool isSinglePathCollisionFreeImproved(std::vector<State> *curve);

    /**
     * Collsion checking using bounding box first, if
     * collision occures, then check collisions using footprint circles
     * @param current Vehicle state in global frame
     * @return true if collision free, false otherwise
     */
    bool isSingleStateCollisionFreeImproved(const State &current);

    /**
     * Footprint circles collision Checking based on a single global state
     * @param current Current vehicle state in global frame
     * @return true if collision-free, false otherwise
     */
    bool isSingleStateCollisionFree(const State &current);

    /**
     * This funciton is not used by internal collision checking algorithms, it's
     * for global path global collision checking.
     * @param curve Path in global frame, not ego frame
     */
    void collisionCheckingHelper(std::vector<State> *curve);

 private:
    const hmpl::InternalGridMap &in_gm_;
    hmpl::CarGeometry car_;
};

}

#endif //STATE_SAMPLING_COLLOSION_CHECKER_HPP
