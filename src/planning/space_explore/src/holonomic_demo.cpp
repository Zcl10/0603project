/* Copyright (c) 2017, Yu Zhang, Beijing Institute of Technology
 * Waterloo Autonomouse Vehicles Laboratory (WAVELab), University of Waterloo.
 * All rights reserved.
 *        Files: holonomic_demo.cpp
 *   Created on: Mar, 23, 2017
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */

#include <ros/package.h>
#include <ros/ros.h>
#include <opt_utils/opt_utils.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "space_explore/space_explore.hpp"

std::vector<int8_t> getMapData(std::size_t rows, std::size_t cols,
                               int8_t init_value) {
    std::size_t size = rows * cols;
    std::vector<int8_t> data(size, init_value);
    return data;
}

int main(int argc, char **argv) {
    // Initialize the node, publishers and subscribers.
    ros::init(argc, argv, "holonomic_node");
    ros::NodeHandle nh("~");

    std::string image_dir = ros::package::getPath("space_explore");
    std::string base_dir = image_dir;
    if (argc < 2) {
        std::cerr << "Expect providing an image file name." << std::endl;
        std::cerr << "Usage:" << argv[0] << " image_name" << std::endl;
        return 1;
    } else if (argc > 2) {
        std::cerr << "Too many arguments." << std::endl;
        std::cerr << "Usage:" << argv[0] << " image_name" << std::endl;
        return 1;
    }
    std::string image_file = argv[1];
    image_dir.append("/" + image_file);
    cv::Mat img_src = cv::imread(image_dir, CV_8UC1);
    // cv::namedWindow("map_display_origin", cv::WINDOW_AUTOSIZE);

    int rows = img_src.rows;
    int cols = img_src.cols;
    double resolution = 0.2;
    ROS_INFO("map resolution: %f", resolution);
    hmpl::InternalGridMap in_gm;
    in_gm.initializeFromImage(img_src, resolution, grid_map::Position::Zero());
    in_gm.addObstacleLayerFromImage(img_src, 0.5);
    in_gm.updateDistanceLayer();

    bool display_flag = true;
    hmpl::SpaceExplore holonomic(in_gm, display_flag);

    hmpl::Pose2D start(35.0, 30.0, M_PI);
    hmpl::Pose2D end(-30.0, 30.0, M_PI);

    auto start_t = std::chrono::steady_clock::now();
    holonomic.solve(in_gm, start, end);
    std::string circle_path = base_dir;
    int dense = 100;
    if (display_flag) {
        cv::Scalar color = cv::Scalar(200, 200, 200);
        holonomic.drawCircleCenterPath(&holonomic.display_, color);
        std::string file = image_file;
        file.erase(file.find_last_of("."), std::string::npos);
        circle_path.append("/" + file);
        std::string first_res = circle_path;
        first_res.append("_first.jpg");
        cv::imwrite(first_res, holonomic.display_);
    }

    if (display_flag) {
        cvWaitKey(-1);
    }
    while (!holonomic.getOptimizedFlag()) {
        // holonomic.optimizePath();
        // holonomic.optimizePathImproved();
        holonomic.optimizePathLength();
        std::cout << "length of the path:" << holonomic.getLengthOfPath()
                  << std::endl;
        if (dense < 0) {
            dense = 0;
        }
        cv::Scalar col = cv::Scalar(dense, dense, dense);
        holonomic.drawCircleCenterPath(&holonomic.display_, col);
        dense = dense - 10;
        if (display_flag) {
            cv::imshow(holonomic.window_name_, holonomic.display_);
            cvWaitKey(-1);
        }
    }

    holonomic.interpolateBspline();
    holonomic.drawDensePath(&holonomic.display_, "random");

    auto end_t = std::chrono::steady_clock::now();
    double duration = hmpl::getDurationInSecs(start_t, end_t);
    std::cout << "search time:" << duration << std::endl;

    std::string second_res = circle_path;
    second_res.append("_final.jpg");
    if (display_flag) {
        cv::imwrite(second_res, holonomic.display_);
    }
    std::cout << "Smoothness of dense path:"
              << holonomic.getDensePathSmoothness() << std::endl;
    std::cout << "OMPL smoothness of the dense path"
              << holonomic.getDensePathSmoothness(true) << std::endl;
    std::cout << "The length of dense path:" << holonomic.getLengthOfDensePath()
              << std::endl;
    cv::waitKey(-1);

    return 0;
}
