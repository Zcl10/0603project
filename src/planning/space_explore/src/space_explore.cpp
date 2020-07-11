#include "space_explore/space_explore.hpp"
#include <algorithm>
#include <limits>

namespace hmpl {

// basic constructor
SpaceExplore::SpaceExplore(hmpl::InternalGridMap &gmap,
                           bool display_flag,
                           const VoronoiDiagram &voronoi)
    : internal_grid(gmap),
      voronoi_(voronoi),
      start(),
      goal(),
      twopi(2.0 * M_PI),
      f_goal_(std::numeric_limits<double>::infinity()),
      overlap_threshold_(0.05),
      lower_boundary_(1.2),
      upper_boundary_(4),
      safety_margin_(0),
      optimized_(false),
      curvature_max_(0.4),
      circle_path(),
      best_open(),
      closed(),
      path_(),
      state_path_(0),
      overlap_path_flag(false),
      window_name_("display"),
      display_rviz_(false),
      r_(100) {
    piece_angle = twopi / 36.0;
    if (display_flag) {
        ros::NodeHandle nh("");
        ros::NodeHandle nh_private("~");
        this->sp_rviz_ =
            std::make_shared<SpaceExploreVisualTools>(nh, nh_private);
        this->sp_rviz_->clearMarkerArray();
        this->display_rviz_ = this->sp_rviz_->param_.enable_display;
    }
}

SpaceExplore::~SpaceExplore() {
    while (!(circle_path.circles.empty())) {
        auto cn = circle_path.circles.back();
        delete cn;
        circle_path.circles.pop_back();
    }
}

// verify if two circles overlaps with each other
bool SpaceExplore::overlap(const Circle &a, const Circle &b,
                           double factor) {
    double smaller, greater;

    if (a.r > b.r) {
        smaller = b.r;
        greater = a.r;
    } else {
        smaller = a.r;
        greater = b.r;
    }
    return ((a.position.Distance(b.position) - greater) < (factor * smaller));
}
void SpaceExplore::setDisplayRVIZ(bool flag) {
    this->display_rviz_ = flag;
}

bool SpaceExplore::getDisplayRVIZ() {
    return this->display_rviz_;
}

// get the nearest circle from a given pose
CircleNodePtr SpaceExplore::nearestCircleNode(
    const Pose2D &p) {
    // stupid search
    if (0 < circle_path.circles.size()) {
        // get a direct access
        std::vector<CircleNodePtr> &circles(circle_path.circles);

        // the Vector2D access
        Vector2D<double> position(p.position);

        // iterators
        std::vector<CircleNodePtr>::iterator it = circles.begin();

        // set the first circle as the closer one
        std::vector<CircleNodePtr>::iterator nearest = it;

        // get the end iterator
        std::vector<CircleNodePtr>::iterator end = circles.end();
        std::vector<CircleNodePtr>::iterator next;

        // get the current distance between the pose and the first circle
        double distance = position.Distance((*it)->circle.position);

        // update the current iterator
        ++it;

        // iterate along the circle path
        while (it != end) {
            double d = position.Distance((*it)->circle.position);

            if (d < distance) {
                // update the values
                distance = d;
                nearest = it;
            }

            // update the iterator
            ++it;
        }

        // we got it!
        next = nearest;
        ++next;

        if (next != end) {
            // get the position vectors reference
            Vector2D<double> &next_circle((*next)->circle.position);
            Vector2D<double> &current_circle(
                (*nearest)->circle.position);

            if (current_circle.Distance2(next_circle) >
                position.Distance2(next_circle)) {
                return *next;
            }
        }

        return *nearest;
    }

    return nullptr;
}

double SpaceExplore::getMaxHeadingChange(double radius, double max_curvature) {
    double acos_value = radius * radius * max_curvature * max_curvature / 2 - 1;
    double f = M_PI;
    if (acos_value >= -1 && acos_value <= 1) {
        // the acos_value is in the domain
        f = M_PI - std::acos(acos_value);
    }
    return f;
}

CircleNodePtrArrayPtr SpaceExplore::getChildrenWithoutLimit(
    CircleNodePtr cn, double max_radius) {
    CircleNodePtrArrayPtr children = new CircleNodePtrArray();

    // get the direct access
    std::vector<CircleNodePtr> &circles(children->circles);

    double x = cn->circle.position.x;
    double y = cn->circle.position.y;
    double r = cn->circle.r;

    double theta = 0;
    // the next child position
    Vector2D<double> ncp;

    double max_heading_change;
    max_heading_change = M_PI;
    double delta_heading_change = 2 * max_heading_change / 36.0;
    for (std::size_t i = 0; i < 18; i++) {
        if (0 == i) {
            // the straight line successive circle
            ncp.x = x + r * std::cos(theta);
            ncp.y = y + r * std::sin(theta);
            this->sampleChild(ncp, cn, max_radius, &circles);
        } else {  // push two symetric circle back to the vector
            // left side
            double heading = theta + i * delta_heading_change;
            ncp.x = x + r * std::cos(heading);
            ncp.y = y + r * std::sin(heading);
            this->sampleChild(ncp, cn, max_radius, &circles);

            // right side
            heading = theta - i * delta_heading_change;
            ncp.x = x + r * std::cos(heading);
            ncp.y = y + r * std::sin(heading);
            this->sampleChild(ncp, cn, max_radius, &circles);
        }
    }
    return children;
}

CircleNodePtrArrayPtr SpaceExplore::getChildren(
    CircleNodePtr cn, double max_radius) {
    CircleNodePtrArrayPtr children =
        new CircleNodePtrArray();

    // get the direct access
    std::vector<CircleNodePtr> &circles(children->circles);

    double x = cn->circle.position.x;
    double y = cn->circle.position.y;
    double r = cn->circle.r;

    double theta;
    if (cn->parent == nullptr) {
        // theta = M_PI / 2.0;
        double theta = this->start.orientation;
        double orientation = atan2(sin(theta), cos(theta));
        theta = orientation;
    } else {
        double x_parent = cn->parent->circle.position.x;
        double y_parent = cn->parent->circle.position.y;
        theta = atan2(y - y_parent, x - x_parent);
    }
    // the next child position
    Vector2D<double> ncp;

    double max_heading_change;
    if (r <= 2.0 / this->curvature_max_) {
        max_heading_change = this->getMaxHeadingChange(r, this->curvature_max_);
    } else {
        max_heading_change = M_PI;
    }
    max_heading_change = M_PI;
    double delta_heading_change = 2 * max_heading_change / 36.0;
    for (std::size_t i = 0; i < 18; i++) {
        if (0 == i) {
            // the straight line successive circle
            ncp.x = x + r * std::cos(theta);
            ncp.y = y + r * std::sin(theta);
            this->sampleChild(ncp, cn, max_radius, &circles);
        } else {  // push two symetric circle back to the vector
            // left side
            double heading = theta + i * delta_heading_change;
            ncp.x = x + r * std::cos(heading);
            ncp.y = y + r * std::sin(heading);
            this->sampleChild(ncp, cn, max_radius, &circles);

            // right side
            heading = theta - i * delta_heading_change;
            ncp.x = x + r * std::cos(heading);
            ncp.y = y + r * std::sin(heading);
            this->sampleChild(ncp, cn, max_radius, &circles);
        }
    }
    return children;
}

void SpaceExplore::sampleChild(
    Vector2D<double> &ncp, CircleNodePtr parent, double max_radius,
    std::vector<CircleNodePtr> *circles) {
    // the next child radius
    double ncr;

    // the next child distance from the parent node
    double ncg;

    // the next child distance to the goal
    double ncf;

    grid_map::Position ncp_pos(ncp.x, ncp.y);
    grid_map::Index index;
    this->internal_grid.maps.getIndex(ncp_pos, index);

    if (internal_grid.maps.isInside(ncp_pos)) {
        // get the child radius
        const double dis_to_obs = internal_grid.getObstacleDistance(index);
        ncr = dis_to_obs - this->safety_margin_;
        // ncr = grid.GetObstacleDistance(ncp) - this->safety_margin_;
        // limit the max radius of the circle expanded
        ncr = std::min(ncr, max_radius);

        if (ncr > lower_boundary_) {
            // get the distance from the parent node
            ncg = parent->circle.r + parent->g;

            // get the distance to the goal
            ncf = ncp.Distance(goal.position) + ncg;
            if (voronoi_.isValid()) {
                ncg = 0.2 * parent->circle.r
                    + 0.8 * voronoi_.getPotential(dis_to_obs, index)
                        * parent->circle.r + parent->g;
                ncf = 0.2 * ncp.Distance(goal.position) + ncg;
            }

            // save the circle to the children list
            (*circles).push_back(new CircleNode(Circle(ncp, ncr), ncr,
                                                ncg, ncf, parent));
        }
    }
}

// clear the current CircleNodePtr sets
void SpaceExplore::removeAllCircleNodes() {
    // a helper pointer
    CircleNodePtr tmp;

    // clear the current open set
    while (!best_open.empty()) {
        // remove the min from the priority queue
        tmp = best_open.top();

        // remove the element from the heap
        best_open.pop();

        if (!tmp->explored) {
            // delete from memmory
            delete tmp;
        }
    }

    while (!closed.empty()) {
        // get the last node
        tmp = closed.back();

        // remove from the vector
        closed.pop_back();

        // remove from the heap
        delete tmp;
    }
}

// rebuild the circle array
void SpaceExplore::rebuildCirclePath(CircleNodePtr cn) {
    // get the direct access
    std::vector<CircleNodePtr> &circles(circle_path.circles);

    // a temp circle node
    CircleNodePtr tmp = nullptr;

    // the circle node list, just to prepend the actual circle nodes
    std::list<CircleNodePtr> l;

    // build the goal CircleNode
    tmp = new CircleNode(*cn);

    // append to the list
    l.push_front(tmp);

    // backtrace the path generated by astar algorithm
    while (nullptr != cn) {
        // update the distance between the current node and the it's child
        cn->g = tmp->circle.position.Distance(cn->circle.position) + tmp->g;

        // prepend to the circle path list
        l.push_front(cn);

        // go to the parent node
        tmp = cn;
        cn = cn->parent;
    }

    // copy the entire list to the vector
    if (0 < l.size()) {
        // ge the first iterator
        std::list<CircleNodePtr>::iterator it = l.begin();
        std::list<CircleNodePtr>::iterator end = l.end();

        // get the current circle
        CircleNodePtr parent_c_node = nullptr;
        CircleNodePtr child_c_node = nullptr;

        while (it != end) {
            // build the next circle
            child_c_node = new CircleNode(*(*it));

            // update the parent node
            child_c_node->parent = parent_c_node;

            // append to the circle path
            circles.push_back(child_c_node);

            parent_c_node = child_c_node;

            // update the current iterator
            ++it;
        }

        // delete the last element in the list
        // the last circle was allocated inside this method
        // so it'll not be removed by the RemoveAllCircleNodes() method
        tmp = l.back();
        l.pop_back();
        delete tmp;
    }
}

bool SpaceExplore::nodeExistInClosedSet(CircleNodePtr cn) {
    // may try nanoflann to see the result
    Circle &c(cn->circle);
    for (auto &itr : this->closed) {
        if (itr != cn->parent && this->overlap(c, itr->circle, 0.1)) {
            return true;
        }
    }
    return false;
}

// explore a given circle node
void SpaceExplore::exploreCircleNode(CircleNodePtr cn) {
    // get the children nodes
    // SpaceExplore::CircleNodePtrArrayPtr children =
    //        GetChildren(cn, this->upper_boundary_);

    CircleNodePtrArrayPtr children =
        getChildrenWithoutLimit(cn, this->upper_boundary_);
    // the main loop
    if (0 < children->circles.size()) {
        // get the direct access
        std::vector<CircleNodePtr> &circles(children->circles);

        for (auto &itr : circles) {
            // get the child pointer
            CircleNodePtr child = itr;
            best_open.push(child);
        }
//        closed.push_back(cn); //yt
    }
    closed.push_back(cn);
    delete children;
}

// process a given node
bool SpaceExplore::processNode(CircleNodeRef goal, CircleNodePtr cn) {
    // get the adjacent circles
    exploreCircleNode(cn);

    // verify the overlap case
    if (overlap(cn->circle, goal.circle, 0.5)) {
        goal.parent = cn;
        this->f_goal_ = std::min(this->f_goal_, cn->g);
        // success!
        rebuildCirclePath(&goal);
        if (circle_path.circles.size() == 3) {
            // insert mid point for optimization and curve fitting
            // insert pt1 between the first and second point, insert pt2 between
            // the second and third point.
            // first insert point
            Circle pt1, pt2;
            pt1.position.x = (circle_path.circles.at(0)->circle.position.x +
                circle_path.circles.at(1)->circle.position.x) /
                2.0;
            pt1.position.y = (circle_path.circles.at(0)->circle.position.y +
                circle_path.circles.at(1)->circle.position.y) /
                2.0;
            pt2.position.x = (circle_path.circles.at(1)->circle.position.x +
                circle_path.circles.at(2)->circle.position.x) /
                2.0;
            pt2.position.y = (circle_path.circles.at(1)->circle.position.y +
                circle_path.circles.at(2)->circle.position.y) /
                2.0;
            CircleNodePtr pt1_node = new CircleNode(pt1, lower_boundary_, 0, 0,
                                                    circle_path.circles.at(0));
            CircleNodePtr pt2_node = new CircleNode(pt2, lower_boundary_, 0, 0,
                                                    circle_path.circles.at(1));
            circle_path.circles.at(1)->parent = pt1_node;
            circle_path.circles.at(2)->parent = pt2_node;
            std::vector<CircleNodePtr>::iterator itr;
            itr = circle_path.circles.begin();
            circle_path.circles.insert(itr + 1, pt1_node);
            itr = circle_path.circles.end();
            circle_path.circles.insert(itr, pt2_node);
            this->overlap_path_flag = true;
        }

        // clear the open and closed sets
        removeAllCircleNodes();

        return true;
    }

    return false;
}

bool SpaceExplore::spaceExploration() {
    grid_map::Position start_pos(start.position.x, start.position.y);
    if (!this->internal_grid.maps.isInside(start_pos)) {
        std::cout << "Start point is outside of the grid map." << std::endl;
        return false;
    }
    Circle c_start(this->start.position,
                   internal_grid.getObstacleDistance(start_pos));
    grid_map::Position end_pos(goal.position.x, goal.position.y);
    Circle c_goal(this->goal.position,
                  internal_grid.getObstacleDistance(end_pos));

    double f = c_start.position.Distance(goal.position);

    if (f < c_start.r) {
        // create the node pointer to

//        std::cout << "start and goal overlapped." << std::endl;
        CircleNodePtr start_node =
            new CircleNode(c_start, c_start.r, 0.0, f, nullptr);
        Circle p1, p2;
        Circle mid;
        mid.position.x = (start.position.x + goal.position.x) / 2;
        mid.position.y = (start.position.y + goal.position.y) / 2;
        p1.position.x = (c_start.position.x + mid.position.x) / 2.0;
        p1.position.y = (c_start.position.y + mid.position.y) / 2.0;
        grid_map::Position pose(p1.position.x, p1.position.y);
//        std::cout << "before p1 " << std::endl;
        p1.r = f / 3;

//        std::cout << "p1." << std::endl;
        p2.position.x = c_start.position.x * (1.0 / 3.0) +
            c_goal.position.x * 2.0 / 3.0;
        p2.position.y = c_start.position.y * (1.0 / 3.0) +
            c_goal.position.y * 2.0 / 3.0;
        pose(0) = p2.position.x;
        pose(1) = p2.position.y;
        p2.r = f / 3;

//        std::cout << "p2." << std::endl;
        CircleNodePtr p1_node = new CircleNode(p1, p1.r, 0, f, start_node);
        CircleNodePtr p2_node = new CircleNode(p2, p2.r, 0, f, p1_node);
        CircleNodePtr goal_node =
            new CircleNode(c_goal, c_goal.r, 0, f, p2_node);
//        std::cout << "goal." << std::endl;
//        std::cout << "build circle path." << std::endl;
        rebuildCirclePath(goal_node);
//        removeAllCircleNodes();
        delete start_node;
        delete p1_node;
        delete p2_node;
        delete goal_node;
//        std::cout << "build path done." << std::endl;
        this->overlap_path_flag = true;
        return true;
    }

    // build a new CircleNode
    CircleNodePtr cn =
        new CircleNode(c_start, c_start.r, 0.0, f, nullptr);

    // build the goal CircleNode
    CircleNode gcn(c_goal, c_goal.r, 0.0, 0.0, nullptr);

    // add to the best priority queue
    this->best_open.push(cn);

    cv::Mat overlay;

    if (this->display_rviz_) {
        this->sp_rviz_->publishStart(c_start);
        this->sp_rviz_->publishCircle(c_goal);
        this->sp_rviz_->publishGoal(c_goal);
        this->sp_rviz_->display();
    }
    double time_cost = 0.0;
    while (!best_open.empty()) {
        // pop the min element
        // cn = open.top();
        auto start = hmpl::now();
        cn = best_open.top();
        // remove the top element from the queue
        best_open.pop();

        if (this->display_rviz_) {
            // this->sp_rviz_->publishCircles(cn->circle);
            this->sp_rviz_->publishCircle(cn->circle);
            this->sp_rviz_->display();
            r_.sleep();
            //std::this_thread::sleep_for (std::chrono::microseconds(10000));

        }

        if (this->f_goal_ < cn->f) {
            // break;
        } else if (nodeExistInClosedSet(cn)) {
            delete cn;
            continue;
        }

        // process the current circle node
        // if it's a valid path to the goal it will return true
        // otherwise we got a false value
        if (processNode(gcn, cn)) {
            // rviz display
            if (this->display_rviz_) {
                this->sp_rviz_->publishPath(this->circle_path);
                this->sp_rviz_->display();
            }
            return (this->f_goal_ < std::numeric_limits<double>::infinity());
        }
        auto stop = hmpl::now();
        time_cost += hmpl::getDurationInSecs(start, stop);
        if (time_cost > 0.01) {
            LOG(WARNING) << "search cost " << time_cost << " s, exceed limits!";
            break;
        }
    }

    // let's display here

    // remove the nodes
    removeAllCircleNodes();

    // there is not a free path to the goal
    return false;
}

// THE HEURISTIC OBJECT METHODS

// update the Heuristic circle path with a new grid map, start and goal poses
void SpaceExplore::solve(hmpl::InternalGridMap &grid_map,
                         const Pose2D &start_,
                         const Pose2D &goal_) {
    if (1 /*goal != goal_*/) {
        // update the grid reference
        internal_grid = grid_map;
        // copy the new start pose
        start = start_;

        // save the next goal pose
        goal = goal_;

        // remove from memory
        while (!(circle_path.circles.empty())) {
            auto cn = circle_path.circles.back();
            circle_path.circles.pop_back();
            delete cn;
        }

        path_.clear();

        state_path_.clear();

        optimized_ = false;

        this->overlap_path_flag = false;

        // init for the search
        f_goal_ = std::numeric_limits<double>::infinity();
        // build the new circle path
        if (!spaceExploration()) {
            std::cout << "Could no find a circle path connecting "
                "the start and goal poses!";
            return;
        } else {
            raw_path = circle_path.circles;
            // update the length of the circle center path
            if (!this->overlap_path_flag) {
                int dense = 100;
                int j = 0;
                while (!this->optimized_ && j < 10) {
                    if (j == 0) {
                        if (this->display_rviz_) {
                            this->sp_rviz_->publishCirclePath(circle_path);
                            this->sp_rviz_->display();
                        }
                    }
//                    std::cout << "iteration:" << j << std::endl;
                    j++;
                    if (voronoi_.isValid())
//                        optimizePathImprovedNew();
                        optimizePathLengthNew();
                    else
//                        optimizePathImproved();
                        this->optimizePathLength();
                    if (this->display_rviz_) {
                        if (this->sp_rviz_->param_.enable_internal_path_display) {
                            this->sp_rviz_->publishPath(circle_path);
                            this->sp_rviz_->display();
                            r_.sleep();
                            //std::this_thread::sleep_for(std::chrono::microseconds(1000));
                        }
                    }
                    // this->optimizePath();
                }
            }

//            path_.clear();
//            for (const auto &circle : circle_path.circles) {
//                Vector2D<double> pt;
//                pt.x = circle->circle.position.x;
//                pt.y = circle->circle.position.y;
//                path_.push_back(pt);
//            }
            interpolateBspline();
            if (this->display_rviz_) {
                if (this->sp_rviz_->param_.enable_final_path_display) {
                    this->sp_rviz_->publishFinalPath(this->path_);
                    this->sp_rviz_->display();
                }

            }
        }
    }
}

double SpaceExplore::getLengthOfPath() {
    std::size_t size = this->circle_path.circles.size();
    double length = 0;
    if (size > 1) {
        for (std::size_t i = 0; i < size - 2; i++) {
            double x_1 = this->circle_path.circles.at(i)->circle.position.x;
            double x_2 = this->circle_path.circles.at(i + 1)->circle.position.x;
            double y_1 = this->circle_path.circles.at(i)->circle.position.y;
            double y_2 = this->circle_path.circles.at(i + 1)->circle.position.y;
            double delta =
                sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
            length += delta;
        }
        return length;
    } else {
        std::cout << "The circle path size is 0 or 1.";
        return length;
    }
}

// get the heuristic value given a pose
double SpaceExplore::getHeuristicValue(const Pose2D &p) {
    // get the nearest circle
    CircleNodePtr nearest = nearestCircleNode(p);

    if (nullptr != nearest) {
        return nearest->g + p.position.Distance(nearest->circle.position);
    }

    // return the old euclidean distance value
    return goal.position.Distance(p.position);
}

void SpaceExplore::updateCircleCenterWithoutLimit(
    const CircleRef first, CirclePtr second,
    const CircleRef third) {
    Circle perpendicular = getPerpendicularCircle(first, *second, third);
    while (second->position.Distance(perpendicular.position) > 1e-4) {
        grid_map::Position pos(perpendicular.position.x,
                               perpendicular.position.y);
        double clearance = internal_grid.getObstacleDistance(pos);
        if (clearance > second->r || clearance > this->lower_boundary_ + 0.8) {
//        if (clearance > this->lower_boundary_ + safety_margin_) {
            *second = perpendicular;
        } else {
            perpendicular.position.x =
                (perpendicular.position.x + second->position.x) / 2.0;
            perpendicular.position.y =
                (perpendicular.position.y + second->position.y) / 2.0;
            perpendicular.r = clearance;
        }
    }
}

void SpaceExplore::updateCircleCenterWithoutLimitNew(
    const CircleRef first, CirclePtr second,
    const CircleRef third) {
    grid_map::Position pos_second(second->position.x,
                                  second->position.y);
    Circle perpendicular = getPerpendicularCircle(first, *second, third);
    while (second->position.Distance(perpendicular.position) > 1e-4) {

        grid_map::Position pos(perpendicular.position.x,
                               perpendicular.position.y);
        double clearance = internal_grid.getObstacleDistance(pos);
        double potential = voronoi_.getPotential(clearance, pos);
        if ((potential < 0.25 || clearance > 3)
            && clearance > this->lower_boundary_) {
            *second = perpendicular;
        } else {
            perpendicular.position.x =
                (perpendicular.position.x + second->position.x) / 2.0;
            perpendicular.position.y =
                (perpendicular.position.y + second->position.y) / 2.0;
            perpendicular.r = clearance;
        }
    }
}

void SpaceExplore::updateCircleCenter(const CircleRef parent,
                                      const CircleRef first,
                                      CirclePtr second,
                                      const CircleRef third) {
    Circle perpendicular = getPerpendicularCircle(first, *second, third);
    /* // the code section doesn't work as expect disable now
    if (getCurvature(parent.position, first.position, second->position) >
    this->curvature_max_) {
        // get the straight line support point
        double heading1 = atan2(first.position.y - parent.position.y,
                               first.position.x - parent.position.x);
        double heading2 = atan2(second->position.y - first.position.y,
                               second->position.x - parent.position.x);
        // get the current heading change
        double delta_heading = (heading2 - heading1) / 2.0;


        // binary search on the arc to find an update rule
        do {

            astar::Circle loose;
            loose.position.x = first.position.x + cos(delta_heading +
    heading1)*first.r;
            loose.position.y = first.position.y + sin(delta_heading +
    heading1)*first.r;
            grid_map::Position pos(loose.position.x, loose.position.y);
            double clearance = internal_grid.getObstacleDistance(pos);
            if (getCurvature(parent.position, first.position, loose.position) <
    this->curvature_max_
                    && clearance > this->lower_boundary_ + safety_margin_
                    ) {
                *second = loose;
                break;
            } else {
                delta_heading = delta_heading / 2.0;
            }
        } while (delta_heading > 0.01);

        // update the point
    }*/
    while (second->position.Distance(perpendicular.position) > 0.00001) {
        grid_map::Position pos(perpendicular.position.x,
                               perpendicular.position.y);
        double clearance = internal_grid.getObstacleDistance(pos);
        const double curvature_new = hmpl::getCurvature(parent.position,
                                                        first.position,
                                                        perpendicular.position);
        const double curvature = hmpl::getCurvature(parent.position,
                                                    first.position,
                                                    second->position);
        if (clearance > second->r || clearance > this->lower_boundary_ + 0.8
            || (clearance > this->lower_boundary_
                && curvature_new < curvature)) {
//        if (clearance > this->lower_boundary_ + safety_margin_ &&
//                hmpl::getCurvature(parent.position, first.position,
//                                   perpendicular.position) <=
//                        this->curvature_max_) {
            *second = perpendicular;
        } else {
            perpendicular.position.x =
                (perpendicular.position.x + second->position.x) / 2.0;
            perpendicular.position.y =
                (perpendicular.position.y + second->position.y) / 2.0;
            perpendicular.r = clearance;
        }
    }
}

// the optimize path that matches paper description
void SpaceExplore::optimizePathImproved() {
    std::size_t size = circle_path.circles.size();
    if (size > 3) {
        double energy, new_energy;
        do {
            energy = this->getCirclePathEnergy();
            for (std::size_t i = 1; i < size - 2; i++) {
                CircleRef parent =
                    this->circle_path.circles.at(i - 1)->circle;
                CircleRef first =
                    this->circle_path.circles.at(i)->circle;
                CircleRef second =
                    this->circle_path.circles.at(i + 1)->circle;
                CircleRef third =
                    this->circle_path.circles.at(i + 2)->circle;

                updateCircleCenter(parent, first, &second, third);
                // updateCircleCenterWithoutLimit(parent, first, &second,
                // third);
            }
            new_energy = this->getCirclePathEnergy();
            double improvement = fabs(new_energy - energy) / energy;

            if (improvement == 0) {
                this->optimized_ = true;
                break;
            }

            if (new_energy < energy && improvement < 0.0001) {
                this->optimized_ = true;
                break;
            }
        } while (new_energy < energy);
    }
}

void SpaceExplore::optimizePathLength() {
    std::size_t size = this->circle_path.circles.size();
    if (size > 3) {
        double length, new_length;
        do {
            length = this->getLengthOfPath();
            if (size > 5) {
                for (std::size_t i = 0; i < size - 4; i += 1) {
                    CircleRef first =
                        this->circle_path.circles.at(i)->circle;
                    CircleRef second =
                        this->circle_path.circles.at(i + 1)->circle;
                    CircleRef third =
                        this->circle_path.circles.at(i + 2)->circle;
                    CircleRef forth =
                        this->circle_path.circles.at(i + 3)->circle;
                    CircleRef fifth =
                        this->circle_path.circles.at(i + 4)->circle;
                    updateCircleCenterWithoutLimit(first, &second, fifth);
                    updateCircleCenterWithoutLimit(first, &third, fifth);
                    updateCircleCenterWithoutLimit(first, &forth, fifth);
                }
            }

            for (std::size_t i = 0; i < size - 2; i++) {
//                CircleRef parent =
//                        this->circle_path.circles.at(i - 1)->circle;
                CircleRef first =
                    this->circle_path.circles.at(i)->circle;
                CircleRef second =
                    this->circle_path.circles.at(i + 1)->circle;
                CircleRef third =
                    this->circle_path.circles.at(i + 2)->circle;
//                updateCircleCenter(parent, first, &second, third);
                updateCircleCenterWithoutLimit(first, &second, third);
            }
            new_length = this->getLengthOfPath();
            double improvement = fabs(new_length - length) / length;

            if (improvement == 0) {
                this->optimized_ = true;
                break;
            }

            if (new_length < length && improvement < 1e-5) {
                this->optimized_ = true;
                break;
            }
            if (this->display_rviz_) {
                if (this->sp_rviz_->param_.enable_internal_path_display) {
                    this->sp_rviz_->publishPath(circle_path);
                    this->sp_rviz_->display();
                    r_.sleep();
                    //std::this_thread::sleep_for(std::chrono::microseconds(500));
                }
            }
        } while (new_length < length);
    }
}

void SpaceExplore::optimizePathLengthNew() {
    std::size_t size = this->circle_path.circles.size();
    if (size > 3) {
        double length, new_length;
        do {
            length = this->getLengthOfPath();
//            if (size > 5) {
//                for (std::size_t i = 0; i < size - 4; i += 1) {
//                    CircleRef first =
//                        this->circle_path.circles.at(i)->circle;
//                    CircleRef second =
//                        this->circle_path.circles.at(i + 1)->circle;
//                    CircleRef third =
//                        this->circle_path.circles.at(i + 2)->circle;
//                    CircleRef forth =
//                        this->circle_path.circles.at(i + 3)->circle;
//                    CircleRef fifth =
//                        this->circle_path.circles.at(i + 4)->circle;
//                    updateCircleCenterWithoutLimitNew(first, &second, fifth);
//                    updateCircleCenterWithoutLimitNew(first, &third, fifth);
//                    updateCircleCenterWithoutLimitNew(first, &forth, fifth);
//                }
//            }

            for (std::size_t i = 0; i < size - 2; i++) {
//                CircleRef parent =
//                        this->circle_path.circles.at(i - 1)->circle;
                CircleRef first =
                    this->circle_path.circles.at(i)->circle;
                CircleRef second =
                    this->circle_path.circles.at(i + 1)->circle;
                CircleRef third =
                    this->circle_path.circles.at(i + 2)->circle;
//                updateCircleCenter(parent, first, &second, third);
                updateCircleCenterWithoutLimitNew(first, &second, third);
            }
            new_length = this->getLengthOfPath();
            double improvement = fabs(new_length - length) / length;

            if (improvement == 0) {
                this->optimized_ = true;
                break;
            }

            if (new_length < length && improvement < 1e-5) {
                this->optimized_ = true;
                break;
            }
            if (this->display_rviz_) {
                if (this->sp_rviz_->param_.enable_internal_path_display) {
                    this->sp_rviz_->publishPath(circle_path);
                    this->sp_rviz_->display();
                    r_.sleep();
                    //std::this_thread::sleep_for(std::chrono::microseconds(500));
                }
            }
            if (new_length >= length)
                std::cout << "new_length >= length" << std::endl;
        } while (new_length < length);
    }
}

// my own optimization strategy
void SpaceExplore::optimizePath() {
    std::size_t size = circle_path.circles.size();
    // for two circles case , we don't need to optimize
    if (size > 2) {
        // the first point and last point should not be changed as they are
        // start and goal respectively.
        // double smoothness = this->getCirclePathSmoothness();
        double energy = this->getCirclePathEnergy();
        for (std::size_t i = 0; i < size - 2; i++) {
            // The size of the all
            // interpolation point is corresponding to i+1 th point

            CircleRef first = this->circle_path.circles.at(i)->circle;
            CircleRef second =
                this->circle_path.circles.at(i + 1)->circle;
            CircleRef third =
                this->circle_path.circles.at(i + 2)->circle;
            Circle interpolate =
                getInterpolatingCircle(first, second, third);
            // check if the interpolation is feasible
            if (i < 1) {
                continue;
            } else {
                // calculate the heading
                double x = this->circle_path.circles.at(i)->circle.position.x -
                    this->circle_path.circles.at(i)
                        ->parent->circle.position.x;
                double y = this->circle_path.circles.at(i)->circle.position.y -
                    this->circle_path.circles.at(i)
                        ->parent->circle.position.y;
                // the direction of entry of i node
                double theta = std::atan2(y, x);

                x = interpolate.position.x -
                    this->circle_path.circles.at(i)->circle.position.x;
                y = interpolate.position.y -
                    this->circle_path.circles.at(i)->circle.position.y;
                // the directoin of interpolating straight line determined by
                // i node and interpolation point
                double theta1 = std::atan2(y, x);
                double delta_theta = fabs(theta1 - theta);
                double r = this->circle_path.circles.at(i)->circle.r;
                double max_heading_change = 0;
                if (r <= 2.0 / this->curvature_max_) {
                    max_heading_change =
                        this->getMaxHeadingChange(r, this->curvature_max_);
                } else {
                    max_heading_change = M_PI;
                }

                if (delta_theta >= max_heading_change) {
                    Circle c =
                        getPerpendicularCircle(first, second, third);
                    double previous_delta;
                    while (delta_theta > max_heading_change) {
                        double x = (c.position.x + second.position.x) / 2.0;
                        double y = (c.position.y + second.position.y) / 2.0;
                        grid_map::Position mid_pos(x, y);

                        double dx = mid_pos.x() - first.position.x;
                        double dy = mid_pos.y() - first.position.y;

                        theta1 = atan2(dy, dx);

                        delta_theta = fabs(theta1 - theta);

                        c.position.x = x;
                        c.position.y = y;

                        double delta_x = mid_pos.x() - second.position.x;
                        double delta_y = mid_pos.y() - second.position.y;

                        double step_length =
                            sqrt(delta_x * delta_x + delta_y * delta_y);

                        if (step_length < internal_grid.maps.getResolution()) {
                            break;
                        }

                        std::cout << "I am trying to find the mid point."
                                  << std::endl;
                    }

                    if (delta_theta > max_heading_change) {
                        continue;
                    } else {
                        grid_map::Position pos(c.position.x, c.position.y);
                        double clearance =
                            internal_grid.getObstacleDistance(pos);
                        if (clearance >= lower_boundary_ + safety_margin_) {
                            this->circle_path.circles.at(i + 1)
                                ->circle.position = interpolate.position;
                            this->circle_path.circles.at(i + 1)->circle.r =
                                clearance;
                        }
                    }
                }
            }

            grid_map::Position interp_pos(interpolate.position.x,
                                          interpolate.position.y);
            grid_map::Index index;
            internal_grid.maps.getIndex(interp_pos, index);
            double clearance = internal_grid.getObstacleDistance(index);
            if (clearance >= lower_boundary_ + safety_margin_) {
                this->circle_path.circles.at(i + 1)->circle.position =
                    interpolate.position;
                this->circle_path.circles.at(i + 1)->circle.r = clearance;
            }
        }

        std::cout << "one optimize done." << std::endl;
        // double succesive = this->getCirclePathSmoothness();
        double energy2 = this->getCirclePathEnergy();
        double delta = fabs(energy - energy2);
        if (delta < 0.001) {
            // stop
            this->optimized_ = true;
        }
    }
}

void SpaceExplore::optimizePathC() {
    std::size_t size = circle_path.circles.size();
    // for two circle case , we don't need to optimize
    if (size > 2) {
        // the first point and the last point should not be changed as they
        // start and goal respectively
        // set start and end fixed
        circle_path.circles.front()->optimized = true;
        circle_path.circles.back()->optimized = true;
        std::size_t opt_counter = 0;
        for (std::size_t i = 0; i < size - 2; i++) {
            if (this->circle_path.circles.at(i + 1)->optimized) {
                opt_counter++;
                continue;
            }
            Circle interpolate = getInterpolatingCircle(
                this->circle_path.circles.at(i)->circle,
                this->circle_path.circles.at(i + 1)->circle,
                this->circle_path.circles.at(i + 2)->circle);
            grid_map::Position interp_pos(interpolate.position.x,
                                          interpolate.position.y);
            // double clearance =
            // grid.GetObstacleDistance(interpolate.position);
            double clearance = internal_grid.getObstacleDistance(interp_pos);
            if (clearance >= this->circle_path.circles.at(i + 1)->circle.r) {
                this->circle_path.circles.at(i)->optimized = true;
                this->circle_path.circles.at(i + 1)->optimized = true;
                this->circle_path.circles.at(i + 2)->optimized = true;
                this->circle_path.circles.at(i + 1)->circle.position =
                    interpolate.position;
                this->circle_path.circles.at(i + 1)->circle.r = clearance;
                opt_counter++;
            } else {
                // can not improve
                this->circle_path.circles.at(i + 1)->optimized = true;
                opt_counter++;
            }
        }
        std::cout << "opt counter:" << opt_counter;
        if (size - 3 <= opt_counter) {
            this->optimized_ = true;
        }
    }
}

void SpaceExplore::interpolateBspline() {
    this->path_.clear();
    this->state_path_.clear();
    const size_t ctrlpt_num = circle_path.circles.size();
    LOG_IF(ERROR, ctrlpt_num < 4)
    << "b spline interpolation requires at least 4 points!!";
    std::vector<double> ctrlp;
    for (const auto &circle:circle_path.circles) {
        ctrlp.push_back(circle->circle.position.x);
        ctrlp.push_back(circle->circle.position.y);
    }
    size_t degree = ctrlpt_num > 5 ? 4 : ctrlpt_num - 1;
    tinyspline::BSpline clamped_spline(ctrlpt_num, 2, degree);
    clamped_spline.setControlPoints(ctrlp);

    const std::size_t sample_num = std::max((std::size_t) 100, ctrlpt_num * 10);
    for (std::size_t j = 0; j < sample_num; j++) {
        double size_f = static_cast<double>(sample_num - 1);
        double knot_percent = static_cast<double>(j) / size_f;
        Vector2D<double> pt;
        pt.x = clamped_spline.eval(knot_percent).result().at(0);
        pt.y = clamped_spline.eval(knot_percent).result().at(1);
        this->path_.push_back(pt);

        hmpl::State state;
        state.x = pt.x;
        state.y = pt.y;
        if (state_path_.empty()) {
            state.s = 0;
        } else {
            state.s =
                state_path_.back().s + distance(state_path_.back(), state);
        }
        state_path_.push_back(state);
    }
}

void SpaceExplore::interpolateCurve() {
    std::size_t point_num = circle_path.circles.size();
    std::size_t knots_num = point_num * 3;
    double *pts = new double[knots_num];
    for (std::size_t i = 0; i < point_num; i++) {
        pts[3 * i] = circle_path.circles.at(i)->circle.position.x;
        pts[3 * i + 1] = circle_path.circles.at(i)->circle.position.y;
        pts[3 * i + 2] = 0;
    }

    ts_bspline_free(&this->spline_);

    ts_bspline_interpolate_cubic(pts, point_num, 3, &(this->spline_));
//    ts_bspline_interpolate(pts, point_num, 3, &this->spline_);
    delete[] pts;
    pts = nullptr;
    std::size_t sample_size = 800;
    this->path_.clear();
    tsReal *result;
    for (std::size_t j = 0; j < sample_size; j++) {
        double size_f = static_cast<double>(sample_size - 1);
        double knot_percent = static_cast<double>(j) / size_f;  // range: [0, 1]
        tsDeBoorNet net;
        ts_bspline_eval(&(this->spline_), (knot_percent), &net);
        ts_deboornet_result(&net, &result);
        Vector2D<double> pt;
        pt.x = result[0];
        pt.y = result[1];
        this->path_.push_back(pt);
    }
    std::cout << "interpolation path size:" << this->path_.size() << std::endl;
}

Circle SpaceExplore::getInterpolatingCircle(
    const CircleRef first, const CircleRef second,
    const CircleRef third) {
    Circle c;
    double ratio1 = second.r / (first.r + second.r);
    double ratio2 = first.r / (first.r + second.r);
    c.position.x = first.position.x * ratio1 + third.position.x * ratio2;
    c.position.y = first.position.y * ratio1 + third.position.y * ratio2;
    c.r = second.r;
    return c;
};

Circle SpaceExplore::getPerpendicularCircle(
    const CircleRef first, const CircleRef second,
    const CircleRef third) {
    Circle c;
    double t = 0;
    double x1 = first.position.x;
    double y1 = first.position.y;
    double x2 = second.position.x;
    double y2 = second.position.y;
    double x3 = third.position.x;
    double y3 = third.position.y;

    // parameterize the point between the start point and the end point
    double a = (x3 - x1) * (x1 - x2) + (y3 - y1) * (y1 - y2);
    double b = pow(y3 - y1, 2.0) + pow(x3 - x1, 2.0);
    t = -a / b;
    // perpendicular point
    c.position.x = x1 * (1 - t) + x3 * t;
    c.position.y = y1 * (1 - t) + y3 * t;
    grid_map::Position pos(c.position.x, c.position.y);
    c.r = internal_grid.getObstacleDistance(pos);

    return c;
}

double SpaceExplore::getCirclePathSmoothness(bool ompl) {
    std::size_t size = this->circle_path.circles.size();
    if (size < 3) {
        std::cout << "The size of the circle path points is below 3. "
            "Can't get smoothness.";
        return 0;
    }

    double f = 0;
    double smoothness = 0;
    for (std::size_t i = 1; i < size - 2; i++) {
        Vector2D<double> &first =
            this->circle_path.circles.at(i - 1)->circle.position;
        Vector2D<double> &second =
            this->circle_path.circles.at(i)->circle.position;
        Vector2D<double> &third =
            this->circle_path.circles.at(i + 1)->circle.position;

        if (ompl) {
            smoothness =
                hmpl::getOMPLSmoothness<Vector2D<double>>(first, second, third);
        } else {
            smoothness =
                hmpl::getSmoothness<Vector2D<double>>(first, second, third);
        }

        f = f + pow(smoothness, 2.0);
    }
    return f;
}

double SpaceExplore::getCirclePathEnergy() {
    std::size_t size = this->circle_path.circles.size();
    if (size < 3) {
        std::cout << "The size of the circle path points is below 3. "
            "Can't get smoothness.";
        return 0;
    }

    double f = 0;
    double smoothness = 0;
    double length = 0;
    double energy = 0;
    for (std::size_t i = 1; i < size - 2; i++) {
        Vector2D<double> &first =
            this->circle_path.circles.at(i - 1)->circle.position;
        Vector2D<double> &second =
            this->circle_path.circles.at(i)->circle.position;
        Vector2D<double> &third =
            this->circle_path.circles.at(i + 1)->circle.position;

        smoothness =
            hmpl::getSmoothness<Vector2D<double>>(first, second, third);
        length = second.Distance(first) + third.Distance(second);

        energy = pow(smoothness, 2.0) * length;
        f = f + energy;
    }
    return f;
}

void SpaceExplore::updateDisplayRvizFlagFromRqt() {
    this->display_rviz_ = this->sp_rviz_->param_.enable_display;
}

}  // namespace space_explore
