#ifndef HYBRID_ASTAR_HOLOMIC_HEURISTIC_INFO_HPP
#define HYBRID_ASTAR_HOLOMIC_HEURISTIC_INFO_HPP

#include <queue>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <tinyspline_ros/tinysplinecpp.h>
#include <voronoi_diagram.hpp>
#include <opt_utils/circle.hpp>
#include <opt_utils/pose2d.hpp>
#include <internal_grid_map/internal_grid_map.hpp>
#include <ros/ros.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <ros/ros.h>
#include "space_explore_visual_tools.hpp"
#include "circle_node.hpp"
#include "circle_node_comparator.hpp"

namespace hmpl {
// whether to display the internal process of the algorithm
// 1: display   0: not display
using hmpl::CircleNodePtrDistanceComparator;
using hmpl::CircleNodePtrRadiusComparator;
using hmpl::CircleNodePtrValueComparator;
using hmpl::CircleNodePtrArray;

// forward declare
class SpaceExploreVisualTools;
class SpaceExplore {
 private:
    ros::Rate r_;

    const VoronoiDiagram &voronoi_;

    // instance first
    hmpl::InternalGridMap &internal_grid;
    // the eigen grid map reference
    // the current start pose
    Pose2D start;

    // the current goal pose
    Pose2D goal;

    // the complete circle
    double twopi;

    // the step angle
    double piece_angle;

    // the value hold the best cost to reach goal
    double f_goal_;

    // overlap threshold in meter
    double overlap_threshold_;

    // the width of the car, explore the space with radius of the circle at
    // least the width of the car to make sure the topology path is feasible
    // for the robot to pass.
    double lower_boundary_;
    // the upper boundary of the expanded circle radius
    double upper_boundary_;
    // the safe margin of the car
    double safety_margin_;

    // the flag that indicates whether the optimization is finished
    bool optimized_;

    //  the max scalar of curvatures for the car.
    double curvature_max_;

    // tinyspline
    tsBSpline spline_;// = {0, 0, 0, 0, 0, NULL, NULL};  //  c++11 feature

    // the resulting circle path
    CircleNodePtrArray circle_path;

    // the value sort open queue
    std::priority_queue<CircleNodePtr, std::vector<CircleNodePtr>,
                        CircleNodePtrValueComparator>
            best_open;

    // the closed set
    std::vector<CircleNodePtr> closed;
    std::vector<Vector2D<double>> path_;
    std::vector<hmpl::State> state_path_;

    bool overlap_path_flag;
    // THE HEURISTIC PRIVATE METHODS

    // verify if two circles overlaps with each other
    bool overlap(const Circle &, const Circle &,
                 double factor = 0.5);

    // get the nearest circle from a given pose
    CircleNodePtr nearestCircleNode(const Pose2D &);

    // get the circle children
    /**
     * Don't limit the expanding direction of the circle
     * @param max_radius
     * @return
     */
    CircleNodePtrArrayPtr getChildrenWithoutLimit(CircleNodePtr,
                                                  double max_radius);

    /**
     * Limit the expanding direction of the circle
     * @param node_ptr
     * @param max_radius
     * @return
     */
    CircleNodePtrArrayPtr getChildren(CircleNodePtr node_ptr,
                                      double max_radius);

    double getMaxHeadingChange(double radius, double max_curvature);

    double getMaxHeadingChange();

    void sampleChild(Vector2D<double> &ncp, CircleNodePtr parent_node,
                     double max_radius,
                     std::vector<CircleNodePtr> *circles);

    // clear the current CircleNodePtr sets
    void removeAllCircleNodes();

    // rebuild the circle array
    void rebuildCirclePath(CircleNodePtr cn);

    // try to find a radundant circle in closed set
    bool nodeExistInClosedSet(CircleNodePtr cn);

    // explore a given circle node
    void exploreCircleNode(CircleNodePtr cn);

    // process a given node
    // astar routine
    bool processNode(CircleNodeRef goal, CircleNodePtr cn);

    // the current search method
    // biggest clearance routine

    // astar routine
    bool spaceExploration();

    //void drawStartAndEnd(cv::Mat *image, const Vector2D<double> &start,
    //                     const Vector2D<double> &end);

    Circle getInterpolatingCircle(const CircleRef first,
                                  const CircleRef second,
                                  const CircleRef third);

    Circle getPerpendicularCircle(const CircleRef first,
                                  const CircleRef second,
                                  const CircleRef third);

 public:
    // THE HEURISTIC OBJECT METHODS

    // basic constructor
    // basic constructor for eigen grid map
    SpaceExplore(hmpl::InternalGridMap &gmap,
                 bool display_flag = false,
                 const VoronoiDiagram &voronoi = VoronoiDiagram());

    ~SpaceExplore();

    // update the Heuristic circle path with a new grid map, start and goal
    // poses
    void solve(hmpl::InternalGridMap &grid, const Pose2D &,
               const Pose2D &);

    // get the heuristic value given a pose
    double getHeuristicValue(const Pose2D &pose);

    /**
     * Use my own optimization strategy, limit the curvature
     */
    void optimizePathLength();

    void optimizePathLengthNew();


    void optimizePath();

    void optimizePathImproved();

    void updateCircleCenter(const CircleRef parent,
                            const CircleRef first,
                            CirclePtr second,
                            const CircleRef third);

    void updateCircleCenterWithoutLimit(const CircleRef first,
                                        CirclePtr second,
                                        const CircleRef third);

    void updateCircleCenterWithoutLimitNew(const CircleRef first,
                                        CirclePtr second,
                                        const CircleRef third);

    /**
     * Use the opimization strategy from ChenChao
     */
    void optimizePathC();

    void interpolateCurve();

    void interpolateBspline();

    double getLengthOfPath();

    std::string window_name_;

    // get the smoothness of the path
    double getCirclePathSmoothness(bool ompl = 0);

    double getCirclePathEnergy();

    bool getOptimizedFlag() { return this->optimized_; };

    // be careful with the size of the image, should match the size of the map
    // the reason of using pointer is that we don't want to maintain an image
    // in our class, but the gridmap is kind of loosely coupled with the image.
    // CV_8UC4  yes, we need alpha channel

    void setLowerBoundary(double width) { this->lower_boundary_ = width; };

//    cv::Mat display_;

    std::vector<Vector2D<double>> &getDensePath() {
        return this->path_;
    };

    std::vector<hmpl::State> getStatePath() const {
        return state_path_;
    }

    std::vector<CircleNodePtr> getCirclePath() const {
        return this->circle_path.circles;
    }

    std::shared_ptr<SpaceExploreVisualTools> sp_rviz_;

    bool display_rviz_{true};
    void setDisplayRVIZ(bool flag);
    bool getDisplayRVIZ();
    void updateDisplayRvizFlagFromRqt();
    std::vector<CircleNodePtr> raw_path;
};
}

#endif
