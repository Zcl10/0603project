/* Copyright (c) 2017, Yu Zhang, Intelligent Vehicle Research Center(IVRC), 
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: collision_checking_benchmark.cpp
 *   Created on: 11, 16, 2017 
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include <ros/package.h>
#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Path.h>
#include <car_model/car_geometry.hpp>
#include <internal_grid_map/internal_grid_map.hpp>
#include <chrono>
#include <random>
#include <yaml-cpp/yaml.h>
#include <grid_map_ros/grid_map_ros.hpp>
#include <visualization_msgs/MarkerArray.h>
#include <opt_utils/opt_utils.hpp>
#include <fstream>
#include <boost/filesystem.hpp>
#include "state_sampling/state_sampling.hpp"


// Recursive helper function that does all the work
void writeNode(const YAML::Node& node, YAML::Emitter& emitter)
{
    switch (node.Type())
    {
        case YAML::NodeType::Sequence:
        {
            emitter << YAML::BeginSeq;
            for (size_t i = 0; i < node.size(); i++)
            {
                writeNode(node[i], emitter);
            }
            emitter << YAML::EndSeq;
            break;
        }
        case YAML::NodeType::Map:
        {
            emitter << YAML::BeginMap;
            
            // First collect all the keys
            std::vector<std::string> keys(node.size());
            int key_it = 0;
            for (YAML::const_iterator it = node.begin(); it != node.end(); ++it)
            {
                keys[key_it++] = it->first.as<std::string>();
            }
            
            // Then sort them
            std::sort(keys.begin(), keys.end());
            
            // Then emit all the entries in sorted order.
            for(size_t i = 0; i < keys.size(); i++)
            {
                emitter << YAML::Key;
                emitter << keys[i];
                emitter << YAML::Value;
                writeNode(node[keys[i]], emitter);
            }
            emitter << YAML::EndMap;
            break;
        }
        default:
            emitter << node;
            break;
    }
}

// Main function that emits a yaml node to an output stream.
void writeYamlOrderedMaps(std::ostream& out, const YAML::Node& node)
{
    YAML::Emitter emitter;
    writeNode(node, emitter);
    out << emitter.c_str() << std::endl;
}



void publishFootPrint(const ros::Publisher &pub,
                      const std::vector<hmpl::Circle> &centers) {
    if (centers.empty()) {
        return;
    }
    visualization_msgs::Marker center_marker;
    visualization_msgs::MarkerArray center_set_marker;
    center_marker.header.frame_id = "/map";
    center_marker.header.stamp = ros::Time::now();
    center_marker.ns = "car";
    center_marker.id = 500;
    center_marker.type = visualization_msgs::Marker::SPHERE;
    center_marker.action = visualization_msgs::Marker::ADD;
    
    if (centers.empty()) return;
    
    center_marker.pose.orientation.x = 0.0;
    center_marker.pose.orientation.y = 0.0;
    center_marker.pose.orientation.z = 0.0;
    center_marker.pose.orientation.w = 1.0;
    
    center_marker.color.a = 0.5;
    center_marker.color.b = 1.0;
    center_marker.points.clear();
    center_set_marker.markers.clear();
    
    for (auto &center_itr : centers) {
        center_marker.id += 1;
        center_marker.pose.position.x = center_itr.position.x;
        center_marker.pose.position.y = center_itr.position.y;
        center_marker.pose.position.z = 0;
        double scale = 2 * center_itr.r;
        center_marker.scale.x = scale;
        center_marker.scale.y = scale;
        center_marker.scale.z = scale;
        center_set_marker.markers.push_back(center_marker);
    }
    
    pub.publish(center_set_marker);
}


void save_car_geometry(const hmpl::CarGeometry &car, const std::string &dir) {
    std::ofstream fout(dir);
    YAML::Node root;
    // footprint
    // footprint circle
    // wheelbase
    // track
    root["a_wheelbase"] = car.getWheelbase();
    root["b_track"] = car.getTrack();
    YAML::Node circles;
    
    // construct the footprint nodes
    for (std::size_t i = 0; i < 4; i++) {
        YAML::Node footprint;
        YAML::Node pos;
        pos["x"] = car.getFootPrint()[i].x;
        pos["y"] = car.getFootPrint()[i].y;
        root["c_footprint"].push_back(pos);
    }
    // construct the footprint circles
    
    for (auto &circle_itr: car.getCenters()) {
        YAML::Node pos;
        pos["x"] = circle_itr.position.x;
        pos["y"] = circle_itr.position.y;
        pos["r"] = circle_itr.r;
        root["d_footprint_circles"].push_back(pos);
    }
    
    YAML::Node position;
    position["x"] = car.getBoundingCircle().position.x;
    position["y"] = car.getBoundingCircle().position.y;
    position["r"] = car.getBoundingCircle().r;
    root["f_bounding_circle"].push_back(position);
    
    // save the yaml node
    writeYamlOrderedMaps(fout, root);
}

int main( int argc, char **argv )
{
    // Initialize the node, publishers and subscribers.
    ros::init(argc, argv, "benchmark");
    ros::NodeHandle nh("~");
    std::string image_dir = ros::package::getPath("state_sampling");
    std::string base_dir = image_dir;
    std::string save_dir = "/benchmark/data8_100/";
    std::string image_file = "empty.png";
    image_dir.append("/" + image_file);
    cv::Mat img_src = cv::imread(image_dir, CV_8UC1);
    hmpl::CarGeometry car;
    
    // save the car geometry information
    save_car_geometry(car, base_dir + "/benchmark/" + "car_geometry.yaml");
    
    std::string state_file = "random_states";
    std::string obstacle_file = "random_obstacles";
    
    std::cout << "saving folder:"<< base_dir+ save_dir +"benchmark.yaml" << std::endl;
    namespace fs = boost::filesystem;
    if (!fs::exists(base_dir + save_dir)) {
        fs::create_directories(base_dir + save_dir);
    }
    
    int cols = img_src.cols;
    double resolution = 0.1;  // in meter
    hmpl::InternalGridMap in_gm;
    in_gm.initializeFromImage(img_src, resolution, grid_map::Position::Zero());
    
    // random generate obstacles
    std::size_t sample_num =
            static_cast<std::size_t >((in_gm.maps.getSize()(0)*in_gm.maps.getSize()(1)));
    double threshold_for_obs = 0.5;
    
    // base image
    in_gm.addObstacleLayerFromImage(img_src, threshold_for_obs);
   
    std::cout << "map size:" << in_gm.maps.getSize()(0) << ","
              << in_gm.maps.getSize()(1) << std::endl;
   
    ///////////////////////////////////////////////////////////////////////////
    //////// random obstacle generation ///////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    std::mt19937 rng_x;
    std::mt19937 rng_y;
    std::mt19937 rng_r;
    rng_x.seed(std::random_device()());
    rng_y.seed(std::random_device()());
    rng_r.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dstb(1,800); // distribution in range [1, 6]
    
    double x = 0;
    double y = 0;
    double r = 3;
    grid_map::Position circle_pos(0, 0);
    std::size_t obstacle_number = 100;
    
    // obstacles generation, save this to csv files
    hmpl::CSVFile obs_csv(base_dir + save_dir + obstacle_file + ".csv");  // throws exceptions!
    obs_csv << "x" << "y"  << "r" << hmpl::endrow;
    
    
    for (size_t i = 0; i < obstacle_number; i++) {
        circle_pos(0) = (static_cast<double>(dstb(rng_x)) - 400.0)/10.0;
        circle_pos(1) = (static_cast<double>(dstb(rng_y)) - 400.0)/10.0;
        obs_csv << circle_pos(0) << circle_pos(1) << r << hmpl::endrow;
        
        for (grid_map::CircleIterator iterator(in_gm.maps, circle_pos, r);
             !iterator.isPastEnd(); ++iterator) {
             in_gm.maps.at(in_gm.obs, *iterator) = 0;
        }
    }
    
    // calculate the density of the grid map
    std::size_t grid_num = 0;
    std::size_t obs_num = 0;
    grid_map::Matrix& data = in_gm.maps[in_gm.obs];
    for (grid_map::GridMapIterator iterator(in_gm.maps); !iterator.isPastEnd(); ++iterator) {
        grid_num++;
        const std::size_t i = iterator.getLinearIndex();
        if (0 == data(i)) {
            obs_num++;
        }
    }
    double percentage = static_cast<double>(obs_num) / static_cast<double>(grid_num);
  
    
    
    in_gm.updateDistanceLayer();
    
    in_gm.maps.setFrameId("/map");
    ROS_INFO("Created map with size %f x %f m (%i x %i cells).",
             in_gm.maps.getLength().x(), in_gm.maps.getLength().y(),
             in_gm.maps.getSize()(0), in_gm.maps.getSize()(1));
    
   
     
    // generate random state for collision checking
    // x , y , theta
    // random generator
    std::mt19937 rng_car_x;
    std::mt19937 rng_car_y;
    std::mt19937 rng_car_t;
    rng_car_x.seed(std::random_device()());
    rng_car_y.seed(std::random_device()());
    rng_car_t.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dstb_t(0, 1000); // distribution in range [1, 6]
   
    /// random position
    std::vector<hmpl::State> curve;
    hmpl::State current_state, goal_state;
    // random position vector
    std::vector<hmpl::State> random_states;
    std::size_t state_num = 1000000;
    
    
    
    
    hmpl::StateSampling state_sampling(in_gm, curve, current_state,
                                       goal_state);
    
    // save the solving time

    auto start = hmpl::now();
    for (auto &state_itr: random_states) {
        state_sampling.isSingleStateCollisionFreeImproved(state_itr);
    }
    auto end = hmpl::now();
    double time_duraiton_improved = hmpl::getDurationInSecs(start, end);
    
    // benchemark the collision test
   
    // benchmark file
    // obstacles number
    // obstacles density
    // obstacles file name
    YAML::Node node;  // starts out as null
    // map information
    std::ofstream fout(base_dir + save_dir + "benchmark.yaml");
    node["a_obstacle_num"] = obstacle_number;
    node["b_obstacle_density"] = percentage;
    node["c_obstacle_file_name"] = obstacle_file+".csv";
    node["d_random_states_num"] = state_num;
    node["e_states_file_name"] = state_file+".csv";
    
    for (std::size_t j = 0; j < 10; j++) {
        YAML::Node time_node;
        random_states.clear();
        std::string tmp_name = state_file;
        // save the state to csv
        hmpl::CSVFile states_csv(base_dir + save_dir + state_file + std::to_string(j) + ".csv");  // throws exceptions!
        states_csv << "x" << "y"  << "t" << hmpl::endrow;
        
        // generate random states
        for (std::size_t i = 0; i < state_num; i++) {
            current_state.x = (static_cast<double>(dstb(rng_car_x)) - 400.0)/10.0;
            current_state.y = (static_cast<double>(dstb(rng_car_y)) - 400.0)/10.0;
            current_state.z = 2 * M_PI * static_cast<double>(dstb_t(rng_car_t))/1000.0;
            states_csv << current_state.x << current_state.y << current_state.z << hmpl::endrow;
            random_states.push_back(current_state);
        }
      
        
        // test the time
        auto start_old = hmpl::now();
        for (auto &state_itr: random_states) {
            state_sampling.isSingleStateCollisionFree(state_itr);
        }
        auto end_old = hmpl::now();
       
        
        
        // test the improved time
        auto start = hmpl::now();
        for (auto &state_itr: random_states) {
            state_sampling.isSingleStateCollisionFreeImproved(state_itr);
        }
        auto end = hmpl::now();
        double time_duration_improved =
                hmpl::getDurationInSecs(start, end);
        
        
        
        double time_duration = hmpl::getDurationInSecs(start_old, end_old);
        time_node["normal"] = time_duration;
        time_node["improved"] = time_duration_improved;
        std::cout << "char:" << j << ", " << std::to_string(j) << std::endl;
        time_node["state_file"] = tmp_name.append(std::to_string(j)+".csv");
        node["f_solving_time"].push_back(time_node);
    }
    
    ros::Publisher publisher =
            nh.advertise<nav_msgs::OccupancyGrid>("grid_map", 1, true);
    
    ros::Publisher vis_pub =
            nh.advertise<visualization_msgs::MarkerArray>("footprint", 1, true);
    
    ros::Rate rate(10.0);
    
    
    
    // save the yaml file
    writeYamlOrderedMaps(fout, node);
    while (nh.ok()) {
        // Add data to grid map.
        ros::Time time = ros::Time::now();
    
        // publish the grid_map
        in_gm.maps.setTimestamp(time.toNSec());
        nav_msgs::OccupancyGrid map_msg;
        grid_map::GridMapRosConverter::toOccupancyGrid(
                in_gm.maps, in_gm.obs, in_gm.FREE, in_gm.OCCUPY, map_msg);
        publisher.publish(map_msg);
    
        current_state.x = (static_cast<double>(dstb(rng_car_x)) - 400.0)/10.0;
        current_state.y = (static_cast<double>(dstb(rng_car_y)) - 400.0)/10.0;
        current_state.z = 2 * M_PI * static_cast<double>(dstb_t(rng_car_t))/1000.0;
        std::vector<hmpl::Circle> circles = car.getCurrentCenters(current_state);
        publishFootPrint(vis_pub, circles);
        std::cout << "map length:" << in_gm.maps.getLength()(0) << ","
                                   << in_gm.maps.getLength()(1) << std::endl;
        int x = static_cast<int>(dstb(rng_x)) - 4000;
        std::cout << "position:" << current_state.x << "," << current_state.y << "," << current_state.z << std::endl;
        std::cout << "theta distribution:" << current_state.z  << std::endl;
        std::cout << "grid number:" << grid_num << std::endl;
        std::cout << "obs number:" << obs_num << std::endl;
        std::cout << "obs percentage:" << percentage << std::endl;
        // std::cout << "improved time:" << time_duraiton_improved << std::endl;
        // std::cout << "old time:" << time_duraiton << std::endl;
    }
}