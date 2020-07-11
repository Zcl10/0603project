//
// Created by yangt on 7/7/18.
//
#include <lanelet_map_msgs/Way.h>
#include <ros/package.h>
#include <fstream>
#include <tinyspline_ros/tinysplinecpp.h>
#include "waypoint_manager/route_publisher_node.hpp"
RoutePublisher::RoutePublisher(const Configuration &config,
                               ros::NodeHandle *nh) :
    nh_(nh),
    cfg_(config),
    sub_(config, nh),
    pub_(config, nh),
    nearest_id_(0) {
    lanelet_map_msgs::Way raw_points;
    if (!(this->readWaypointFromFile(&raw_points))) {
        ROS_ERROR("no txt file!!!");
        return;
    }
    if (cfg_.interpolate_type == "spline") {
        linearInterpolation(raw_points, &waypoint_);
        raw_points = waypoint_;
        this->InterpolationBspline(raw_points);
    } else if (cfg_.interpolate_type == "line") {
        linearInterpolation(raw_points, &waypoint_);
    } else {
        waypoint_ = raw_points;
    }
    /// timer
    timer_ = nh_->createTimer(ros::Duration(0.05),
                              boost::bind(&RoutePublisher::TimerCb, this));
}

bool RoutePublisher::readWaypointFromFile(lanelet_map_msgs::Way *raw_points) {
    std::string file_path =
        cfg_.package_dir + "/waypoint_files/" + cfg_.file_name;
    std::ifstream fin(file_path);
    if (fin.fail()) {
        ROS_ERROR("No Such file: %s", file_path.c_str());
        return false;
    }
    int index;
    int type;
    raw_points->points.clear();
    geometry_msgs::Point pt;
    lanelet_map_msgs::Node pt_xy;
    pt.z = 0.0;
    pt_xy.point.z = 0.0;
    while (fin >> index >> pt.x >> pt.y >> pt.z >> type) {
        if (cfg_.use_gps_point && !cfg_.is_simulation) {
            /// geograpic to utm
            cartographer::transform::TransformTools tft;
            tft.geographic_to_utm(pt.x,
                                  pt.y,
                                  &(pt_xy.point.x),
                                  &(pt_xy.point.y));
        } else {
            pt_xy.point = pt;
        }
        raw_points->points.push_back(pt_xy);
    }
    fin.close();
    std::cout << "read " << raw_points->points.size() << " points from file."
              << std::endl;
    return true;
}
void RoutePublisher::linearInterpolation(const lanelet_map_msgs::Way &origin_way,
                                         lanelet_map_msgs::Way *result) {
    result->points.clear();
    if (origin_way.points.size() < 2) {
        return;
    }
    result->points.push_back(origin_way.points.front());
    size_t control_point_num = origin_way.points.size();
    for (size_t i = 0; i < control_point_num - 1; i++) {
        const auto &x1 = origin_way.points.at(i).point.x;
        const auto &y1 = origin_way.points.at(i).point.y;
        const auto &x2 = origin_way.points.at(i + 1).point.x;
        const auto &y2 = origin_way.points.at(i + 1).point.y;
        double dis_xy;
        double theta;
        double line_segment, sum_seg;

        theta = atan2(y2 - y1, x2 - x1);
        dis_xy = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); //计算两点之间的距离
        int n = static_cast<int>(dis_xy / 10.0);
        line_segment = dis_xy / n;
        sum_seg = line_segment;
        lanelet_map_msgs::Node node;
        for (int j = 0; j < n - 1; j++) {
            node.point.x = x1 + sum_seg * std::cos(theta);
            node.point.y = y1 + sum_seg * std::sin(theta);
            result->points.push_back(node);
            sum_seg = sum_seg + line_segment;
        }
        result->points.push_back(origin_way.points[i + 1]);
    }
}
void RoutePublisher::InterpolationBspline(
    const lanelet_map_msgs::Way &raw_points) {
    waypoint_.points.clear();
    if (raw_points.points.size() < 4) {
        waypoint_ = raw_points;
        return;
    }
    std::vector<double> ctrlp;
    double path_length = 0.0;
    for (const auto pt:raw_points.points) {
        if (ctrlp.empty()) {
            ctrlp.push_back(pt.point.x);
            ctrlp.push_back(pt.point.y);
        } else {
            double dx = pt.point.x - *(ctrlp.end() - 2);
            double dy = pt.point.y - ctrlp.back();
            double dist = sqrt(dx * dx + dy * dy);
            if (dist > 1) {
                ctrlp.push_back(pt.point.x);
                ctrlp.push_back(pt.point.y);
                path_length += dist;
            }
        }
    }
    size_t ctrlpt_num = ctrlp.size() / 2;
    size_t degree = ctrlpt_num > 8 ? 8 : ctrlpt_num - 1;
    tinyspline::BSpline clamped_spline(ctrlpt_num, 2, degree, TS_CLAMPED);
    clamped_spline.setControlPoints(ctrlp);

    std::size_t sample_num = static_cast<size_t >(path_length * 4);
    printf("****Debug path length is %f, sample point number is %d\n",
           path_length,
           sample_num);
    for (std::size_t j = 0; j < sample_num; j++) {
        double size_f = static_cast<double>(sample_num - 1);
        double knot_percent = static_cast<double>(j) / size_f;  // range: [0, 1]
        lanelet_map_msgs::Node node;
        node.point.x = clamped_spline.eval(knot_percent).result().at(0);
        node.point.y = clamped_spline.eval(knot_percent).result().at(1);
        node.id = j;
        waypoint_.points.push_back(node);
    }
}

void RoutePublisher::TimerCb() {
    if (!(cfg_.wait_vehicle_pos)) {
        pub_.PublishWay(waypoint_);
        return;
    } else if (sub_.IsStateUpdate()) {
        const VehicleState &current_state = sub_.GetVehiclePose();
        int start_id = std::max(nearest_id_ - 5, 0);
        /// for multi_circle mode
        if (cfg_.is_multi_circle_mode) {
            if (start_id + 100 > waypoint_.points.size()) {
                double dist = Distance(waypoint_.points.at(start_id),
                                       waypoint_.points.back());
                if (dist < 8) {
                    start_id = 1;
                }
            }
        }
        int end_id = std::min(start_id + 100, (int) (waypoint_.points.size()));
        if (nearest_id_ == 0 && start_id == 0) {
            end_id = waypoint_.points.size();
        }
        std::cout << "****find nearest point: start_id: " << start_id
                  << ", end_id: " << end_id << std::endl;
        double min_dis = std::numeric_limits<double>::infinity();
        int min_id;
        for (int i = start_id; i < end_id; ++i) {
            double dist = Distance(waypoint_.points.at(i), current_state);
//            printf("[%d]dist: %f\n", i, dist);
            if (dist < min_dis) {
                min_id = i;
                min_dis = dist;
            }
        }
        nearest_id_ = min_id;
        if (!cfg_.is_multi_circle_mode) {
            /// final point stop
            if (min_id + 20 < waypoint_.points.size()) {
                start_id = std::max(min_id - 20, 0);
            } else {
                start_id = min_id;
            }
        }
        end_id = waypoint_.points.size();
        std::cout << "min_id: " << min_id << ", start_id: " << start_id
                  << std::endl;
        lanelet_map_msgs::Way way_msgs;
        way_msgs.is_forward = 1;
        way_msgs.open_dynamic_obs_det = 1;
        way_msgs.vel_limit = 200.0;
        for (int i = start_id; i < end_id; ++i) {
            if (i < min_id) {
                way_msgs.points.push_back(waypoint_.points[i]);
            } else {
                double dist = Distance(waypoint_.points.at(i), current_state);
                if (dist < 100.0) {
                    way_msgs.points.push_back(waypoint_.points[i]);
                } else {
                    break;
                }
            }
        }
        std::cout << "way point size: " << way_msgs.points.size() << std::endl;

        pub_.PublishWay(way_msgs);
        sub_.ResetFlag();
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "route_publisher_node");
    ros::NodeHandlePtr nh(new ros::NodeHandle());
    ros::NodeHandlePtr pnh(new ros::NodeHandle("~"));
    Configuration cfg;
    cfg.vehicle_pose_topic = pnh.get()->param<std::string>(
        "vehicle_fuse_pose_topic", "/sensor_fusion_output");
    cfg.file_name =
        pnh.get()->param<std::string>("file_name", "10_kilemeter.txt");
    cfg.wait_vehicle_pos = pnh.get()->param("wait_vehicle_pos", true);
    cfg.use_gps_point = pnh.get()->param("use_gps_point", true);
    cfg.interpolate_type =
        pnh.get()->param<std::string>("roadnet_interpolate_type", "spline");
    cfg.is_simulation = pnh.get()->param("is_simulation", false);
    cfg.is_multi_circle_mode = pnh.get()->param("multi_circle_mode", false);
    cfg.package_dir = ros::package::getPath("waypoint_manager");

    RoutePublisher route_publisher(cfg, nh.get());
    ros::spin();
    return 0;
}
