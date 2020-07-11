/* Copyright (c) 2017, Yu Zhang, Intelligent Vehicle Research Center(IVRC),
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: state_sampling_test.cpp
 *   Created on: 05, 11, 2017
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include <gtest/gtest.h>
#include <vector>
#define private public
#include <opt_utils/vector2d.hpp>
#include <internal_grid_map/internal_grid_map.hpp>
#include <opt_utils/opt_utils.hpp>
#include "state_sampling/state_sampling.hpp"

// test fixture
class StateSamplingTest : public testing::Test {
 public:
    StateSamplingTest() {
        unsigned int rows, cols;
        rows = 800;
        cols = 800;
        double resolution = 0.1;
        cv::Mat img(rows, cols, CV_8UC1, 255);
        grid_map_.initializeFromImage(img, resolution,
                                      grid_map::Position::Zero());
        grid_map_.addObstacleLayerFromImage(img);
        grid_map_.updateDistanceLayer();

        //
        end_.x = 30;
        end_.y = 30;
        end_.z = M_PI / 4.0;

        // the curve, a straight line from start state to goal state
        std::size_t point_num =
                static_cast<std::size_t>(fabs(end_.x - start_.x) / resolution);
        hmpl::State tmp_state;
        double h_x = (end_.x - start_.x) / static_cast<double>(point_num - 1);
        double h_y = (end_.y - start_.y) / static_cast<double>(point_num - 1);
        for (std::size_t i = 0; i < point_num; i++) {
            tmp_state.x = start_.x + i * h_x;
            tmp_state.y = start_.y + i * h_y;
            curve_.push_back(tmp_state);
        }
        // curve
        this->fillCurve(&curve_);
    }

    // fill the curve data,  fill the heading, curvature, arclength
    void fillCurve(std::vector<hmpl::State> *curve) {
        std::size_t size = curve->size();
        double s = 0;
        for (std::size_t i = 0; i < size - 1; i++) {
            if (i == 0) {
                curve->at(i).k = 0;
                curve->at(i).s = 0;
            }
            hmpl::State &state1 = curve->at(i);
            hmpl::State &state2 = curve->at(i + 1);
            double dx = state2.x - state1.x;
            double dy = state2.y - state1.y;
            double delta_s = sqrt(dx * dx + dy * dy);
            curve->at(i).z = atan2(dy, dx);
            s += delta_s;
            curve->at(i + 1).s = s;
            if (i + 2 < size - 2) {
                hmpl::Vector2D<double> pt1(state1.x, state1.y);
                hmpl::Vector2D<double> pt2(state2.x, state2.y);
                hmpl::Vector2D<double> pt3(curve->at(i + 2).x,
                                            curve->at(i + 2).y);
                curve->at(i + 1).k = hmpl::getCurvature(pt1, pt2, pt3);
            }
        }
    }

    ~StateSamplingTest() {}

    hmpl::InternalGridMap grid_map_;
    std::vector<hmpl::State> curve_{};
    hmpl::State start_{};
    hmpl::State end_{};
};

TEST_F(StateSamplingTest, getClosestPointOnPath) {
    hmpl::StateSampling state_sampling(this->grid_map_, this->curve_,
                                       this->start_, this->end_);
    hmpl::State closest_state;
    std::size_t closest_index;
    EXPECT_TRUE(state_sampling.getClosestPointOnPath(
            this->start_, this->curve_, &closest_state, &closest_index));
    EXPECT_DOUBLE_EQ(start_.x, closest_state.x);
    EXPECT_DOUBLE_EQ(start_.y, closest_state.y);
}

TEST_F(StateSamplingTest, generateSequentialGoals) {
    hmpl::StateSampling state_sampling(this->grid_map_, this->curve_,
                                       this->start_, this->end_);

    state_sampling.setLookaheadDistance(5.0);
    std::vector<hmpl::State> lon_goal_set;
    state_sampling.generateSequentialGoals(
            this->start_, this->curve_, &lon_goal_set,
            state_sampling.getLookaheadDistance());
    EXPECT_DOUBLE_EQ(this->end_.x, lon_goal_set.back().x);
    EXPECT_DOUBLE_EQ(this->end_.y, lon_goal_set.back().y);
    EXPECT_DOUBLE_EQ(M_PI / 4.0, lon_goal_set.front().z);
    EXPECT_NEAR(0, lon_goal_set.back().k, 1e-5);
}

TEST_F(StateSamplingTest, getLatGoalSetInEgoFrame) {
    hmpl::StateSampling state_sampling(this->grid_map_, this->curve_,
                                       this->start_, this->end_);

    state_sampling.setLookaheadDistance(5.0);
    std::vector<hmpl::State> lon_goal_set;

    state_sampling.generateSequentialGoals(
            this->start_, this->curve_, &lon_goal_set,
            state_sampling.getLookaheadDistance());
    std::vector<hmpl::State> lat =
            state_sampling.getLatGoalSetInEgoFrame(lon_goal_set.front());
    auto end_time = std::chrono::steady_clock::now();

    EXPECT_DOUBLE_EQ(lat.at(state_sampling.getHalfNum()).x,
                     lon_goal_set.front().x);
    EXPECT_DOUBLE_EQ(lat.at(state_sampling.getHalfNum()).y,
                     lon_goal_set.front().y);
    EXPECT_DOUBLE_EQ(lat.at(state_sampling.getHalfNum()).z,
                     lon_goal_set.front().z);
}

TEST_F(StateSamplingTest, ) {
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
