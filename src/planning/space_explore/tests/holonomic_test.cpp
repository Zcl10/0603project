/* Copyright (c) 2017, Yu Zhang, Beijing Institute of Technology
 * Waterloo Autonomouse Vehicles Laboratory (WAVELab), University of Waterloo.
 * All rights reserved.
 *        Files: holonomic_test.cpp
 *   Created on: Mar, 23, 2017
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */

#include <gtest/gtest.h>
#include <vector>
#define private public
#include <internal_grid_map/internal_grid_map.hpp>
#include "space_explore/space_explore.hpp"
#include <wave/geometry/geometry.hpp>

// helper functions
std::vector<int8_t> getMapData(std::size_t rows, std::size_t cols,
                               int8_t init_value) {
    std::size_t size = rows * cols;
    std::vector<int8_t> data(size, init_value);
    std::size_t count = 0;
    return data;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*TEST(SpaceExploreTest, constructor) {
    hmpl::InternalGridMap gm;
    unsigned int rows, cols;
    rows = 500;
    cols = 500;
    double resolution = 1.0;
    cv::Mat img(rows, cols, CV_8UC1, 255);
    gm.initializeFromImage(img, resolution, grid_map::Position::Zero());
    gm.addObstacleLayerFromImage(img);
    gm.updateDistanceLayer();

    hmpl::SpaceExplore h(gm);
}

TEST(SpaceExploreTest, getSmoothness) {
    hmpl::InternalGridMap gm;
    unsigned int rows, cols;
    rows = 500;
    cols = 500;
    double resolution = 1.0;
    cv::Mat img(rows, cols, CV_8UC1, 255);
    gm.initializeFromImage(img, 1.0, grid_map::Position::Zero());
    gm.addObstacleLayerFromImage(img);
    gm.updateDistanceLayer();

    hmpl::SpaceExplore h(gm);
    hmpl::Vector2D<double> first(0, 0);
    hmpl::Vector2D<double> second(1, 0);
    hmpl::Vector2D<double> third(2, 0);
    EXPECT_DOUBLE_EQ(0, h.getSmoothness(first, second, third));

    second.x = 1.0;
    second.y = 1.0;

    third.x = 0;
    third.y = 2;

    EXPECT_NEAR(1.0, h.getSmoothness(first, second, third), 1e-5);

    third.x = 2.0;
    third.y = 0;
    EXPECT_NEAR(-1.0, h.getSmoothness(first, second, third), 1e-5);
}

TEST(SpaceExploreTest, getOMPLSmoothness) {
    hmpl::InternalGridMap gm;
    unsigned int rows, cols;
    rows = 500;
    cols = 500;
    double resolution = 1.0;
    cv::Mat img(rows, cols, CV_8UC1, 255);
    gm.initializeFromImage(img, 1.0, grid_map::Position::Zero());
    gm.addObstacleLayerFromImage(img);
    gm.updateDistanceLayer();

    hmpl::SpaceExplore h(gm);
    hmpl::Vector2D<double> first(0, 0);
    hmpl::Vector2D<double> second(1, 0);
    hmpl::Vector2D<double> third(2, 0);
    EXPECT_DOUBLE_EQ(0, h.getOMPLSmoothness(first, second, third));

    second.x = 1.0;
    second.y = 1.0;

    third.x = 0;
    third.y = 2;

    EXPECT_DOUBLE_EQ(1.2337005501361697,
                     h.getOMPLSmoothness(first, second, third));
}

TEST(SpaceExploreTest, optimizedPathC) {
    // setup the data
    hmpl::InternalGridMap gm;
    unsigned int rows, cols;
    rows = 500;
    cols = 500;
    double resolution = 1.0;
    cv::Mat img(rows, cols, CV_8UC1, 255);
    gm.initializeFromImage(img, 1.0, grid_map::Position::Zero());
    gm.addObstacleLayerFromImage(img);
    gm.updateDistanceLayer();

    hmpl::SpaceExplore h(gm);

    // setup the inputs of the optimizePath
    hmpl::Circle circle(50, 50, 1);
    h.circle_path.circles.push_back(
            new hmpl::CircleNode(circle, circle.r, 0, 0, nullptr));
    circle.position.x = 51.0;
    h.circle_path.circles.push_back(
            new hmpl::CircleNode(circle, circle.r, 0, 0, nullptr));
    circle.position.x = 52.0;
    circle.position.y = 51.0;
    h.circle_path.circles.push_back(
            new hmpl::CircleNode(circle, circle.r, 0, 0, nullptr));
    h.optimizePathC();
    EXPECT_EQ(3, h.circle_path.circles.size());
    EXPECT_TRUE(h.optimized_);
}

TEST(SpaceExploreTest, optmizedPath) {
    // setup the data
    hmpl::InternalGridMap gm;
    unsigned int rows, cols;
    rows = 500;
    cols = 500;
    double resolution = 1.0;
    cv::Mat img(rows, cols, CV_8UC1, 255);
    gm.initializeFromImage(img, 1.0, grid_map::Position::Zero());
    gm.addObstacleLayerFromImage(img);
    gm.updateDistanceLayer();

    hmpl::SpaceExplore h(gm);

    // setup the inputs of the optimizePath
    hmpl::Circle circle(50, 50, 1);
    h.circle_path.circles.push_back(
            new hmpl::CircleNode(circle, circle.r, 0, 0, nullptr));
    circle.position.x = 51.0;
    h.circle_path.circles.push_back(
            new hmpl::CircleNode(circle, circle.r, 0, 0, nullptr));
    circle.position.x = 52.0;
    circle.position.y = 51.0;
    h.circle_path.circles.push_back(
            new hmpl::CircleNode(circle, circle.r, 0, 0, nullptr));
    while (!h.optimized_) {
        h.optimizePath();
    }
    EXPECT_EQ(3, h.circle_path.circles.size());
    EXPECT_TRUE(h.optimized_);
}

TEST(SpaceExploreTest, getMaxHeadingChange) {
    // setup the data
    hmpl::InternalGridMap gm;
    unsigned int rows, cols;
    rows = 500;
    cols = 500;
    double resolution = 1.0;
    cv::Mat img(rows, cols, CV_8UC1, 255);
    gm.initializeFromImage(img, 1.0, grid_map::Position::Zero());
    gm.addObstacleLayerFromImage(img);
    gm.updateDistanceLayer();

    hmpl::SpaceExplore h(gm);

    double r = 2;
    double max_curvature = 0.2;
    double delta_heading = h.getMaxHeadingChange(r, max_curvature);

    // calculate the third side of the triangle
    double c = sqrt(4 * r * r - pow(r, 4.0) * max_curvature * max_curvature);
    double exp_delta = 2 * std::acos(c / (2 * r));

    EXPECT_DOUBLE_EQ(exp_delta, delta_heading);

    delta_heading = h.getMaxHeadingChange(20, 1.0);
    std::cout << "test heading change:" << delta_heading << std::endl;
}

TEST(SpaceExploreTest, getPerpendicular) {
    hmpl::InternalGridMap gm;
    unsigned int rows, cols;
    rows = 500;
    cols = 500;
    double resolution = 1.0;
    cv::Mat img(rows, cols, CV_8UC1, 255);
    gm.initializeFromImage(img, 1.0, grid_map::Position::Zero());
    gm.addObstacleLayerFromImage(img);
    gm.updateDistanceLayer();

    hmpl::SpaceExplore h(gm);
    hmpl::Circle first;
    hmpl::Circle second;
    hmpl::Circle third;
    first.position.x = 0;
    first.position.y = 0;

    second.position.x = 1;
    second.position.y = 2;

    third.position.x = 2;
    third.position.y = 0;

    hmpl::Circle c = h.getPerpendicularCircle(first, second, third);
    EXPECT_DOUBLE_EQ(1.0, c.position.x);
    EXPECT_DOUBLE_EQ(0, c.position.y);

    first.position.x = 0;
    first.position.y = 1;
    second.position.x = 2;
    second.position.y = 1;
    third.position.x = 2;
    third.position.y = -1;

    c = h.getPerpendicularCircle(first, second, third);
    EXPECT_DOUBLE_EQ(1.0, c.position.x);
    EXPECT_DOUBLE_EQ(0, c.position.y);
}*/

TEST(WaveGeometry, test) {
    struct BodyFrame;
    struct CameraFrame;
    struct WorldFrame;
    
    wave::RotationMFd<WorldFrame, BodyFrame> r1;
    wave::RotationMFd<CameraFrame, WorldFrame> r2;
    wave::RotationMFd<CameraFrame, BodyFrame> result = r2 * r1;
    wave::
    
    
}