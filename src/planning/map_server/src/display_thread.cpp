//
// Created by yangt on 19-5-2.
//
#include"map_server/map_server_node.hpp"

void MapServer::startDisplayThread() {
    this->is_thread_active_ = true;
    std::thread display_thread(&MapServer::callDisplayThread, this);
    display_thread.detach();
}

void MapServer::endDisplayThread() {
    this->is_thread_active_ = false;
}

void MapServer::callDisplayThread() {
    ros::Rate rate(20);
    nav_msgs::OccupancyGrid occupy_msgs;
    while (this->is_thread_active_) {
        if (this->fill_map_over_) {
            this->mutex_.lock();
            auto map = this->gridmap_;
            this->mutex_.unlock();
            grid_map::GridMapRosConverter::toOccupancyGrid(map, this->obs_layer_, 255, 0, occupy_msgs);
            this->ocupancy_grid_pub_.publish(occupy_msgs);
        }
        rate.sleep();
    }
}