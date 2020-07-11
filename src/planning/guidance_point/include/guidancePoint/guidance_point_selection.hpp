
#ifndef ROUTE_PUBLISHER_GUIDANCE_POINT_SELECTION_HPP
#define ROUTE_PUBLISHER_GUIDANCE_POINT_SELECTION_HPP
#include <lanelet_map_msgs/Way.h>
#include "internal_grid_map/internal_grid_map.hpp"
#include "internal_grid_map/eigen2cv.hpp"
#include <anm_msgs/VehicleState.h>
#include <geometry_msgs/Point.h>
#include <opt_utils/opt_utils.hpp>
#include "nav_msgs/Path.h"

#define LASERBEAM    0
#define DFFS         1
#define ROAD_NET     2

enum searchDir {
    LEFT_DIR = 3,
    RIGHT_DIR = 2,
    FRONT_LEFT_DIR = 1,
    FRONT_RIGHT_DIR = 0
};

enum mapDir {
    UP = 0, LEFT = 1, RIGHT = 2, DOWN = 3
};

enum Condition {
    BEST = 3,
    GOOD = 2,
    BAD = 1,
    EMPTY = 0
};

struct Knot {
    mapDir next_dir;
    grid_map::Position pt;
};

struct RoughPath {
    std::vector<Knot> path;
    Condition condition;
    double angle;
};

class guidancePointSelection {
 public:

    /**
     * constructor function for parameters initialization
     * @param map : ETH grid map, contains distance layer and obstacle layer
     * @param roadnet : global roadnet
     * @param vehicle_state : vehicle state in current period
     * @param local_frame : wether searching in ego frame
     */
    guidancePointSelection(hmpl::InternalGridMap &map,
                           const std::vector<hmpl::State> &roadnet,
                           const hmpl::State &vehicle_state,
                           bool local_frame);

    /**
     * the interface function for other package's call to search guidance point
     */
    void searchPath();

    /**
     * convert a pose from global frame to reference frame
     * @param ref_pt : reference pose in global frame
     * @param goal_pt : target pose in global frame
     * @return target pose in reference frame
     */
    lanelet_map_msgs::Node globalToLocal(const hmpl::State &ref_pt,
                                         const lanelet_map_msgs::Node &goal_pt);

    /**
     * convert a pose from reference frame to global frame
     * @param ref_pt : reference pose in global frame
     * @param goal_pt : target pose in referene frame
     * @return target pose in global frame
     */
    lanelet_map_msgs::Node localToGlobal(const hmpl::State &ref_pt,
                                         const lanelet_map_msgs::Node &goal_pt);

    /**
     * move given point toward target point starightly
     * @param start_pt : point need to be moved
     * @param target_pt : target point
     * @param adjust_dist : moving distance
     */
    void adjustToTargetPoint(lanelet_map_msgs::Node *start_pt,
                             const grid_map::Position &target_pt,
                             double adjust_dist = 0.0);

 private:
    /**
     * judge wehter the point is in the grid map, which is same as the paper
     * @param pt : given point
     * @return  true : given point is in the map
     *           false : given point is out of the map
     */
    bool Travel(const grid_map::Position &pt);

    bool isReachBoundary(const Knot &pt);

    /**
     * calculate next knot, which is same as the paper
     * @param knot_cur : current knot
     * @param next_knot : next knot
     */
    void NextKnot(const Knot &knot_cur, Knot *next_knot);

    /**
     * calculate next search direction, which is same as the paper
     * @param current_dir : current search direction
     * @param dir_set     : direction set
     */
    void NextDirection(mapDir *current_dir,
                       const std::vector<mapDir> &dir_set);

    /**
     * the interface function for using laser beam method
     * @param goal_pt : goal position
     * @param path : the searching process
     * @return  true: get a guidance poitn successfully
     *           false: search failed
     */
    bool laserBeamMehtodSearch(const grid_map::Position &goal_pt,
                               RoughPath *path);

    /**
     * set the searching direction of dffs method, decide which direction is
     * forward direction
     */
    void setDffsSearchDir();

    /**
     * the interface function for using dffs method
     * @param goal_pt : goal point
     * @param path : the search process
     * @return : true: get a guidance poitn successfully
     *            false: search failed
     */
    bool dffsMethodSearch(const grid_map::Position &goal_pt, RoughPath *path);

    /**
     * three-stage searching strategy, which call basic dffs function three
     * times with different direction
     * @param dir_id : the id of direction combination
     * @param dir_set: direction combination, including two kinds of combination
     * @param start_pt : searching start point
     * @return the process of dffs searching
     */
    RoughPath DFFS_Search(const int dir_id[],
                          const std::vector<std::vector<mapDir> > &dir_set,
                          grid_map::Position start_pt);

    /**
     * the core algorithm of dffs method, which is same as the paper
     * @param direction : search direction
     * @param start_pt : the start point of searching
     * @return the process of searching, the last point is guidance point
     */
    RoughPath dffsSearchBasic(const std::vector<mapDir> &direction,
                              const grid_map::Position &start_pt);

    /**
     * judge wehter the given point reach the final point on roadnet
     * @param ref_state : given point
     * @param global_way : global roadnet
     * @return    : true: given point has reached the final waypoint
     *               false: given point didn't reach the final waypoitn yet
     */
    bool IsReachFinalWayPoint(const hmpl::State &ref_state,
                              const std::vector<hmpl::State> &global_way);

    inline double angle(const lanelet_map_msgs::Node &node1,
                        const lanelet_map_msgs::Node &node2) {
        return atan2(node2.point.y - node1.point.y,
                     node2.point.x - node1.point.x);
    }

    /**
     * calculate the absolute diference of two angles represented in degree
     * @param angle1 : given angle one
     * @param angle2 : given angle two
     * @return :the diference of two given angles, range in [0, 180]
     */
    inline double angleDiff(double angle1, double angle2) {
        double result = fabs(angle1 - angle2);
        result = result > 180 ? (360 - result) : result;
        return fabs(result);
    }

    /**
     * calculate the absolute diference of two angles represented in radian
     * @param angle1 : given angle one
     * @param angle2 : given angle two
     * @return :the diference of two given angles, range in [0, pi]
     */
    inline double angleDiffRad(double rad1, double rad2) {
        double result = fabs(rad1 - rad2);
        result = result > M_PI ? (2 * M_PI - result) : result;
        return fabs(result);
    }


 public:
    /// the process of guidance point searching
    RoughPath search_path;
    /// final selected guidance point
    lanelet_map_msgs::Node point_selected;
    /// choosed target  waypoint in roadnet
    geometry_msgs::Point next_way_point;
    /// roadnet point in ego frame
    std::vector<geometry_msgs::Point> ref_way_local;
    /// collision distance threshold
    double dis_threshold;
    /// roadnet angle
    double road_angle;
    /// the distance from vehicle to roadnet
    double road_offset;
 private:
    /// grid map contains two layers(obstacle, distance)
    hmpl::InternalGridMap &gridmap_;
    /// current vehicle state
    const hmpl::State &vehicle_state_;
    /// reference way point
    const std::vector<hmpl::State> &global_way_;
    /// search step
    double step_;
    /// dffs search direction combination
    std::vector<std::vector<mapDir> > up_as_front;
    std::vector<std::vector<mapDir> > down_as_front;
    std::vector<std::vector<mapDir> > left_as_front;
    std::vector<std::vector<mapDir> > right_as_front;
    std::vector<std::vector<mapDir> > search_forward_;
    std::vector<std::vector<mapDir> > search_back_;
    /// DF-FS algrithom iteration times limits
    int iteration_limit_;
    /// preview distance
    double preview_distance_;
    /// bool variable
    bool use_local_frame_;
};

#endif //ROUTE_PUBLISHER_GUIDANCE_POINT_SELECTION_HPP
