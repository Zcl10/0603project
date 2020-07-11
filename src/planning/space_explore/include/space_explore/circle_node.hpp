/* Copyright (c) 2017, Yu Zhang, Beijing Institute of Technology
 * Waterloo Autonomouse Vehicles Laboratory (WAVELab), University of Waterloo.
 * All rights reserved.
 *        Files: circle_node.hpp
 *   Created on: Mar, 23, 2017
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */

#ifndef SPACE_EXPLORE_CIRCLE_NODE_HPP
#define SPACE_EXPLORE_CIRCLE_NODE_HPP

#include"opt_utils/circle.hpp"

namespace hmpl {

class CircleNode {
 public:
    // the current circle reference
    Circle circle;

    // the g cost value
    double g;

    // the total cost, included heuristic value
    double f;

    // the circle radius
    double radius;

    // the parent node
    CircleNode *parent;

    bool explored;

    bool optimized;

    // basic constructor
    CircleNode(const Circle c, double r, double g_, double f_,
               CircleNode *p)
        : circle(c),
          g(g_),
          f(f_),
          radius(r),
          parent(p),
          explored(false),
          optimized(false) {}

    // the copy constructor
    CircleNode(const CircleNode &cn)
        : circle(cn.circle),
          g(cn.g),
          f(cn.f),
          radius(cn.circle.r),
          parent(nullptr),
          explored(cn.explored) {}

    // basic destructor
    ~CircleNode() {
        // reset the parent node to nullptr
        parent = nullptr;
    }

    // update the node values
    void UpdateValues(const CircleNode &cn) {
        // copy the node values

        // the circle position
        circle.position = cn.circle.position;

        // the circle radius
        circle.r = cn.circle.r;

        // the cost
        g = cn.g;

        // the heuristic cost
        f = cn.f;

        // the parent pointer
        parent = cn.parent;
    }

    // < operator overloading, for priority queue compare purpose
    bool operator<(const CircleNode &cn) const { return f < cn.f; }

    // Assignment operator
    void operator=(const CircleNode &cn) {
        // copy the values
        UpdateValues(cn);
    }
};

// define the syntatic sugar types
typedef CircleNode *CircleNodePtr;
typedef CircleNode &CircleNodeRef;

}  // namespace hmpl
#endif  // SPACE_EXPLORE_CIRCLE_NODE_HPP
