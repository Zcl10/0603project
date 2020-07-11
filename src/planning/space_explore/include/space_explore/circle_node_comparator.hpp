/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC),
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: circle_node_comparator.hpp
 *   Created on: 11, 27, 2018
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#ifndef SPACE_EXPLORE_CIRCLE_NODE_COMPARATOR_HPP
#define SPACE_EXPLORE_CIRCLE_NODE_COMPARATOR_HPP

#include "circle_node.hpp"

namespace hmpl {
  // define a comparator class
   class CircleNodePtrDistanceComparator {
    public:
       // operator overloading
       bool operator()(CircleNodePtr a, CircleNodePtr b) {
           // the default c++ stl is a max heap, so wee need to invert here
           return a->f > b->f;
       }
   };

   // define a comparator class
   class CircleNodePtrRadiusComparator {
    public:
       // operator overloading
       bool operator()(CircleNodePtr a, CircleNodePtr b) {
           // the default c++ stl is a max heap
           return a->radius < b->radius;
       }
   };

   // define a comparator class based on value
   class CircleNodePtrValueComparator {
    public:
       // operator overloading
       bool operator()(CircleNodePtr a, CircleNodePtr b) {
           // the default c++ stl is a max heap, so we need to invert here
           return a->f > b->f;
       }
   };

   // define the CircleNodePtrArray
   class CircleNodePtrArray {
    public:
       // the vector of circle nodes
       std::vector<CircleNodePtr> circles;
   };

   // define the syntatic sugar type
   typedef CircleNodePtrArray *CircleNodePtrArrayPtr;
   typedef CircleNodePtrArray &CircleNodePtrArrayRef;

} // namespace hmpl

#endif  // SPACE_EXPLORE_CIRCLE_NODE_COMPARATOR_HPP
