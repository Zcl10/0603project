//
// Created by yangt on 7/7/18.
//
#include "waypoint_manager/waypoint_collection_node.hpp"
WayPointCollection::WayPointCollection(const Configuration &cfg,
                                       ros::NodeHandle *nh) :
        nh_(nh),
        cfg_(cfg),
        sub_(cfg, nh),
        count_(0) {
    /// initlize parametes

    timer_ = nh_->createTimer(
            ros::Duration(cfg_.save_period),
            boost::bind(&WayPointCollection::TimerCb, this));
    /// clear files
    std::remove((cfg_.package_dir +"/waypoint_files/"+cfg_.file_name).c_str());
}

void WayPointCollection::TimerCb() {
    if(sub_.IsStateUpdate()) {
        const auto &current_pose = sub_.GetVehiclePose();
        const auto &current_gps = sub_.GetVehicleGps();
        double dist = Distance(current_pose, old_pose_);
        if(dist > cfg_.interval) {
            std::ofstream txtfile;
            txtfile.open(cfg_.package_dir+"/waypoint_files/"+cfg_.file_name,
                         std::ios::out | std::ios::app );
            if(txtfile.is_open()) {
                txtfile << this->count_ << " "
                        << std::setprecision(12) << current_gps.longitude << " "
                        << std::setprecision(12) << current_gps.latitude << " "
                        << std::setprecision(12) << current_gps.altitude << " "
                        << 5 << std::endl;
                this->count_ ++;
                ROS_INFO("Save %d points, interval: %f", count_, dist);
                this->old_pose_ = current_pose;
                sub_.ResetFlag();
            }
            txtfile.close();
        }
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "waypoint_collection_node");
    ros::NodeHandlePtr nh(new ros::NodeHandle());
    ros::NodeHandlePtr pnh(new ros::NodeHandle("~"));
    Configuration cfg;
    cfg.vehicle_pose_topic = pnh.get()->param<std::string>(
            "vehicle_fuse_pose_topic", "/sensor_fusion_output");
    cfg.interval = pnh.get()->param("interval", 10.0);
    cfg.file_name=
            pnh.get()->param<std::string>("file_name", "roadMap.txt");
    cfg.save_period = pnh.get()->param("save_period", 0.1);
    cfg.is_simulation = pnh.get()->param("is_simulation", false);
    cfg.package_dir = ros::package::getPath("waypoint_manager");
    WayPointCollection waypoint(cfg, pnh.get());
    ros::spin();
    return 0;
}