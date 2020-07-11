#include "map_server/map_server_node.hpp"

#include <thread>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>

MapServer::MapServer(const ConfigVariable &config, ros::NodeHandle *nh) :
    obs_layer_("obstacle"),
    nh_(nh),
    cfg_(config),
    sub_(config, nh),
    light_type_(OFF_OFF),
    gridmap_({obs_layer_}),
    dist2road_(0.0),
    is_thread_active_(false),
    fill_map_over_(false) {

    // init grid map configuration
    this->gridmap_.setFrameId(cfg_.frame_id);
    double resolution = 0.2;
    grid_map::Length length(100, 100);
    this->gridmap_.setGeometry(length, resolution);

    ocupancy_grid_pub_ = nh_->advertise<nav_msgs::OccupancyGrid>("/explore_entry_map", 1, false);
    grid_map_pub_ = nh->advertise<grid_map_msgs::GridMap>(cfg_.publish_map_topic, 1, false);
    rviz_pub_ = nh->advertise<visualization_msgs::Marker>("vehicle_geometry", 1, false);
    light_type_pub_ = nh->advertise<std_msgs::UInt8>("/light_type", 1, false);
    planning_origin_pub_ = nh->advertise<geometry_msgs::Point>("/planning_origin", 1, false);
    this->startDisplayThread();
}

void MapServer::getFootPrintMarker(visualization_msgs::Marker *marker) {
    const auto ref_pt = (sub_.planningOrigin().inverse()
        * sub_.vehicleInFusionFrame()).translation();
    geometry_msgs::Point A, B, C, D;
    double l = 2.14;// - cfg_.base_shift;
    double m = 2.16;// + cfg_.base_shift;
    double b = 1.0;
    marker->header.stamp = ros::Time::now();
    marker->header.frame_id = cfg_.frame_id;
    marker->color.a = 1.0;
    marker->color.g = 1;
    marker->type = visualization_msgs::Marker::LINE_LIST;
    marker->action = visualization_msgs::Marker::ADD;
    marker->pose.orientation.w = 1;
    marker->scale.x = 0.1;
    geometry_msgs::Point marker_pt;
    marker->id = 1;
    marker->ns = "map_server";
    marker->points.clear();
    double th = 0.0;
    if (cfg_.use_local_frame) {
        th = 0.0;
    } else {
        th = sub_.vehicleState().z;
    }
    A.x = ref_pt(0) + (l) * cos(th) - b * sin(th);
    A.y = ref_pt(1) + (l) * sin(th) + b * cos(th);
    B.x = ref_pt(0) + (l) * cos(th) + b * sin(th);
    B.y = ref_pt(1) + (l) * sin(th) - b * cos(th);
    C.x = ref_pt(0) - m * cos(th) + b * sin(th);
    C.y = ref_pt(1) - m * sin(th) - b * cos(th);
    D.x = ref_pt(0) - m * cos(th) - b * sin(th);
    D.y = ref_pt(1) - m * sin(th) + b * cos(th);
    marker->points.push_back(A);
    marker->points.push_back(B);
    marker->points.push_back(B);
    marker->points.push_back(C);
    marker->points.push_back(C);
    marker->points.push_back(D);
    marker->points.push_back(D);
    marker->points.push_back(A);
}

void MapServer::publishTfTree(const hmpl::State &pose) {
    // update odom reference pose each 100 m
    // publish ros tf
    tf::Transform trans;
    // world to odom tf
    const auto &planning_origin = sub_.planningOrigin().translation();
    trans.setOrigin(tf::Vector3(planning_origin(0), planning_origin(1), 0.0));
    trans.setRotation(tf::Quaternion(0.0, 0.0, 0.0, 1.0));
    tf::StampedTransform stampedTrans(trans, ros::Time::now(), "/world",
                                      "/odom");
    this->tf_broadcaster_.sendTransform(stampedTrans);
    // world to semi_bask_link tf
//    trans.setOrigin(tf::Vector3(pose.x, pose.y, 0.0));
//    trans.setRotation(tf::Quaternion(0.0, 0.0, 0.0, 1.0));
//    tf::StampedTransform stampedTrans2(trans, ros::Time::now(), "/world",
//                                       "/semi_base_link");
//    this->tf_broadcaster_.sendTransform(stampedTrans2);
    // semi_bask_link to base_link
    trans.setOrigin(tf::Vector3(pose.x, pose.y, 0.0));
    if (!(cfg_.use_local_frame)) {
        tf::Quaternion q = tf::createQuaternionFromYaw(pose.z);
        trans.setRotation(q);
    } else {
        trans.setRotation(tf::Quaternion(0.0, 0.0, 0.0, 1.0));
    }
    tf::StampedTransform stampedTrans3(trans, ros::Time::now(),
                                       "/world", "/base_link");
    this->tf_broadcaster_.sendTransform(stampedTrans3);

}

void MapServer::convertSimulationPointCloudToGridMap(
    grid_map::GridMap *gridmap) {
    const auto &point_cloud = sub_.SimulationPointCloud();
    const auto &vehicle_pose = sub_.vehicleState();
    pcl::PointCloud<pcl::PointXYZ>::Ptr lidar_pointcloud_ptr_ =
        boost::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
    geometry_msgs::TransformStamped tf_stamped;
    try {

        tf_stamped = sub_.TfBuffer().lookupTransform("odom",
                                                     "fastHokuyo", ros::Time(
                0));  //odom 车辆起始坐标原点
    } catch (tf2::TransformException &ex) {
        ROS_WARN("%s", ex.what());
        return;
    }
    sensor_msgs::PointCloud2 transformed_pointcloud;
    tf2::doTransform(point_cloud,
                     transformed_pointcloud,
                     tf_stamped);  //pointcloud2 = *lidar_ogm;
    pcl::fromROSMsg(transformed_pointcloud, *(lidar_pointcloud_ptr_));

    for (auto itr = lidar_pointcloud_ptr_->begin();
         itr != lidar_pointcloud_ptr_->end(); itr++) {
        //  ignore the points outside of the occupancy grid map range
        grid_map::Position pos(itr->x - vehicle_pose.x,
                               itr->y - vehicle_pose.y);
        if (gridmap->isInside(pos)) {
            // convert coordinates to cell index
            // As the grid map origin is in the center of grid, need to add
            // offsets to get the right cell index in grid map for point
            // cloud data.
            gridmap->atPosition(obs_layer_, pos) = 0;
        }
    }
}

void MapServer::convertIvMapTypeToGridMapType(grid_map::GridMap *gridmap) {
    const auto &iv_map = sub_.IVRCGridMap();
    const auto &current_task = sub_.Task();
    const auto &flag = sub_.Flag();
    // set transform frame
    cartographer::transform::TransformTools tft;
    const auto ref_pose_in_odom = sub_.planningOrigin().inverse()
        * tft.setTransform(iv_map.triD_submap_pose);
    const auto vehicle_in_odom =
        sub_.planningOrigin().inverse() * sub_.vehicleInOdomFrame();
    const auto vehicle_in_fuse =
        sub_.planningOrigin().inverse() * sub_.vehicleInFusionFrame();

    // fill into map;
    const int &map_center_index_x = iv_map.triD_submap_pose_image_index_x;
    const int &map_center_index_y = iv_map.triD_submap_pose_image_index_y;
    const double &resolution = iv_map.resolution;
//    double data_x, data_y;

    for (int i = 0; i < iv_map.height; ++i) {
        for (int j = 0; j < iv_map.width; ++j) {
            auto data_index = static_cast<size_t>(i * iv_map.width + j);
            const auto &data_cell = iv_map.cells.at(data_index);
            if (data_cell == 4 || data_cell == 2 || data_cell == 6) {
                // ignore lawn area when current task == LAWN_AREA
                if (data_cell == 4
                    && (current_task == LAWN_AREA || flag.is_on_lawn_area)) {
                    continue;
                }
                // pose in odometry map frame
                double x_map =
                    static_cast<double>(j - map_center_index_x) * resolution;
                double y_map =
                    static_cast<double>(i - map_center_index_y) * resolution;
                cartographer::transform::Rigid3d data_in_ref_pose(
                    Eigen::Vector3d(x_map, y_map, 0.0),
                    Eigen::Quaterniond(1.0, 0.0, 0.0, 0.0));
                // pose in odometry world frame
                auto data_in_odom = ref_pose_in_odom * data_in_ref_pose;
                grid_map::Position pos_in_eth_grid;
                if (current_task == SMOKE_AREA) {
                    // in smoke area, the ref_pose_in_odom is in fustion frame
                    const auto data_in_grid = data_in_odom.translation()
                        - vehicle_in_fuse.translation();

                    pos_in_eth_grid << data_in_grid(0), data_in_grid(1);
                } else {
                    // in normal area, the ref_pose_in_odom is odometry frame
                    // pose in iv-ego frame x--right; y--front
                    auto data_in_vehicle =
                        vehicle_in_odom.inverse() * data_in_odom;
                    if (cfg_.use_local_frame) {
                        const auto &tmp_x = data_in_vehicle.translation()(0);
                        const auto &tmp_y = data_in_vehicle.translation()(1);
                        // ego frame in planning: x--front; y--left
                        pos_in_eth_grid << tmp_y, -tmp_x;
                    } else {
                        // planning global frame: East--x, North--y
                        auto vec = data_in_vehicle.translation();
                        vec(1) -= cfg_.base_shift;
                        data_in_vehicle.setTranslation(vec);
                        auto data_in_fuse = vehicle_in_fuse * data_in_vehicle;
                        const auto data_in_map = data_in_fuse.translation();
                        //- vehicle_in_fuse.translation();
                        pos_in_eth_grid << data_in_map(0), data_in_map(1);
                    }
                }
                if (gridmap->isInside(pos_in_eth_grid)) {
                    gridmap->atPosition(obs_layer_, pos_in_eth_grid) = 0;
                }
            }
        }
    }
}

void MapServer::polygonExtractionCV(const grid_map::Polygon &polygon,
                                    grid_map::GridMap *map) {
    cv::Mat obs_f =
        hmpl::eigen2cv(map->get(obs_layer_));
    std::vector<cv::Point> fillContSingle;
    // one polygon
    for (const auto &pt : polygon.getVertices()) {
        grid_map::Index index;
        map->getIndex(pt, index);
        cv::Point point(index(0), index(1));
        fillContSingle.push_back(point);
    }
    // polygons vector
    std::vector<std::vector<cv::Point> > fillContAll;
    fillContAll.push_back(fillContSingle);
    cv::fillPoly(obs_f, fillContAll, 255);
}
void MapServer::polygonExtractionCV(const PointSet &points,
                                    grid_map::GridMap *map) {
    grid_map::Polygon polygon;
    polygon.setFrameId(map->getFrameId());
    for (const auto &itr : points) {
        grid_map::Position pos(itr.x, itr.y);
        polygon.addVertex(pos);
    }
    this->polygonExtractionCV(polygon, map);
}
void MapServer::initTraversibleArea(grid_map::GridMap *map) {
    const auto &global_way = sub_.GlobalWay();
    const auto &vehicle_pose = sub_.vehicleState();
    const auto &vehicle_in_fuse = sub_.vehicleInFusionFrame();
    const auto &planning_origin = sub_.planningOrigin().translation();
    const auto vehicle_in_planning =
        (sub_.planningOrigin().inverse() * vehicle_in_fuse).translation();
    grid_map::Position map_center;
    map_center(0) = vehicle_in_planning(0);
    map_center(1) = vehicle_in_planning(1);
    if (global_way.points.size() > 10) {
        size_t id = global_way.points.size() / 2;
        double path_angle =
            hmpl::angle(global_way.points.front(), global_way.points.at(id));
        path_angle += M_PI;
        path_angle = path_angle > M_PI ? path_angle - 2 * M_PI : path_angle;
        if (path_angle >= -M_PI / 8 && path_angle < M_PI / 8) {
            map_center(0) -= 30;
        } else if (path_angle >= M_PI / 8 && path_angle < 3 * M_PI / 8) {
            map_center(0) -= 30;
            map_center(1) -= 30;
        } else if (path_angle >= 3 * M_PI / 8 && path_angle < 5 * M_PI / 8) {
            map_center(1) -= 30;
        } else if (path_angle >= 5 * M_PI / 8 && path_angle < 7 * M_PI / 8) {
            map_center(0) += 30;
            map_center(1) -= 30;
        } else if (path_angle >= -3 * M_PI / 8 && path_angle < -M_PI / 8) {
            map_center(0) -= 30;
            map_center(1) += 30;
        } else if (path_angle >= -5 * M_PI / 8 && path_angle < -3 * M_PI / 8) {
            map_center(1) += 30;
        } else if (path_angle >= -7 * M_PI / 8 && path_angle < -5 * M_PI / 8) {
            map_center(0) += 30;
            map_center(1) += 30;
        } else {
            map_center(0) += 30;
        }
    }
    map->setPosition(map_center);

    if (!global_way.points.empty()) {
        double vehicle_to_path_dist = Distance(vehicle_pose.x,
                                               vehicle_pose.y,
                                               global_way.points.back().point.x,
                                               global_way.points.back().point.y);
        if (vehicle_to_path_dist < 25) {
            map->get(obs_layer_).setConstant(255);
            return;
        }
    }

    if (global_way.points.size() < 20 || sub_.Task() == BACKUP ||
        !cfg_.use_roadnet_limit_fessible_area) {
        map->get(obs_layer_).setConstant(255);
        return;
    }

    double offset_dis = 5.5 + dist2road_;
    std::vector<hmpl::State> left_boundary;
    std::vector<hmpl::State> right_boundary;
    double max_kappa = std::numeric_limits<double>::min();
    double minDis2Car = std::numeric_limits<double>::infinity();
    size_t delta = 10;
    size_t index = 0;
    size_t minDisIndex = 0;
    // negative value means right dir, possitive value means left dir;
    while (index + delta < global_way.points.size()) {
        // find minist dist to road
        const auto &cur_pt = global_way.points.at(index).point;
        const auto &next_pt = global_way.points.at(index + delta).point;
        const double s = hmpl::distance(cur_pt, next_pt);
        if (s < 1e-1) {
            index += delta;
            continue;
        }
        double dist = Distance(cur_pt.x, cur_pt.y,
                               vehicle_pose.x, vehicle_pose.y);
        if (fabs(dist) < minDis2Car) {
            minDis2Car = fabs(dist);
            minDisIndex = index;
        }
        // find the max curvature
        if (index > 0) {
            const auto &pre_pt = global_way.points.at(index - delta).point;
            double kappa = hmpl::getCurvature(pre_pt, cur_pt, next_pt);
            if (max_kappa < fabs(kappa)) {
                max_kappa = fabs(kappa);
            }
        }
        // offset the roadnet as two boundary
        double path_dir = atan2(next_pt.y - cur_pt.y, next_pt.x - cur_pt.x);
        double offset_x = offset_dis * cos(path_dir + M_PI_2);
        double offset_y = offset_dis * sin(path_dir + M_PI_2);
        hmpl::State new_pt;
        new_pt.x = cur_pt.x - planning_origin(0) + offset_x;
        new_pt.y = cur_pt.y - planning_origin(1) + offset_y;
        left_boundary.push_back(new_pt);
        new_pt.x = cur_pt.x - planning_origin(0) - offset_x;
        new_pt.y = cur_pt.y - planning_origin(1) - offset_y;
        right_boundary.push_back(new_pt);
        if (index != global_way.points.size() - 1 && index + delta > global_way.points.size()) {
            index = global_way.points.size() - 1;
        } else {
            index += delta;
        }
    }

    minDisIndex = std::max(minDisIndex, size_t(1));
    const auto &p1 = global_way.points.at(minDisIndex - 1).point;
    const auto &p2 = global_way.points.at(minDisIndex + 1).point;
    this->dist2road_ = fabs(getPointToLineDist(p1, p2, vehicle_pose));
    printf("****Debug max curvature: %f, distance to road: %f\n",
           max_kappa,
           dist2road_);
    if (fabs(max_kappa) > 1.0 || dist2road_ > 4.5) {
        map->get(obs_layer_).setConstant(255);
        return;
    }
    map->get(obs_layer_).setConstant(0);
    grid_map::Polygon polygon;
    polygon.setFrameId(map->getFrameId());
    grid_map::Position vertex;
    vertex(0) = vehicle_in_planning(0) - 20 * cos(sub_.vehicleState().z);
    vertex(1) = vehicle_in_planning(1) - 20 * sin(sub_.vehicleState().z);
    polygon.addVertex(vertex);
    for (const auto &itr : left_boundary) {
        grid_map::Position pos(itr.x, itr.y);
        polygon.addVertex(pos);
    }
    for (auto it = right_boundary.rbegin();
         it < right_boundary.rend(); ++it) {
        grid_map::Position pos(it->x, it->y);
        polygon.addVertex(pos);
    }
    polygonExtractionCV(polygon, map);
}

void MapServer::setLightType() {
    const auto &iv_map = sub_.IVRCGridMap();
    const auto &current_task = sub_.Task();
    const auto &flag = sub_.Flag();
    double normal_map_time = (ros::Time::now() - iv_map.header.stamp).toSec();
    if (current_task == SEARCH_AREA) {
        this->light_type_ = ON_ON;
    } else if (fabs(normal_map_time) > 3.0) {
        this->light_type_ = FLASH_FLASH;
    } else if (sub_.EmptyPathCount() > 0) {
        this->light_type_ = FLASH_OFF;
    } else if (this->dist2road_ > 5.0) {
        this->light_type_ = OFF_FLASH;
    } else if (current_task == LAWN_AREA || flag.is_on_lawn_area) {
        this->light_type_ = ON_OFF;
    } else {
        this->light_type_ = OFF_OFF;
    }
}
void MapServer::run() {
    auto last_time = hmpl::now();
    ros::Rate freq(30);
    while (ros::ok()) {
        ros::spinOnce();
        if (sub_.IsStateUpdate()) {
            auto t1 = hmpl::now();
            sub_.CheckLawnAreaCount();
            visualization_msgs::Marker footprint_msg;
            this->getFootPrintMarker(&footprint_msg);
            if (sub_.Flag().is_finding_moving_target) {
                ROS_WARN("Using moving target map!!!");
            }

            // fill eth grid map
            this->fill_map_over_ = false;
            this->mutex_.lock();
            this->initTraversibleArea(&gridmap_);
            if (cfg_.is_simulation) {
                convertSimulationPointCloudToGridMap(&gridmap_);
            } else {
                convertIvMapTypeToGridMapType(&(gridmap_));
            }
            polygonExtractionCV(footprint_msg.points, &gridmap_);
            this->mutex_.unlock();
            this->fill_map_over_ = true;

            auto t2 = hmpl::now();
            /// publish grid map
            grid_map_msgs::GridMap map_msgs;
            grid_map::GridMapRosConverter::toMessage(this->gridmap_, map_msgs); // <3ms
            auto t3 = hmpl::now();
            this->rviz_pub_.publish(footprint_msg);
            this->grid_map_pub_.publish(map_msgs);

            /// publish tf tree
            this->publishTfTree(sub_.vehicleState());

            // publish light type
            this->setLightType();
            std_msgs::UInt8 light_data;
            light_data.data = this->light_type_;
            this->light_type_pub_.publish(light_data);

            /// publish planning origin point
            geometry_msgs::Point origin_msgs;
            origin_msgs.x = sub_.planningOrigin().translation()(0);
            origin_msgs.y = sub_.planningOrigin().translation()(1);
            this->planning_origin_pub_.publish(origin_msgs);

            auto t4 = hmpl::now();
            std::cout << "to grid :" << hmpl::getDurationInSecs(t1, t2) << "\n";
            std::cout << "to msg :" << hmpl::getDurationInSecs(t2, t3)
                      << "\n";
            std::cout << "total time :" << hmpl::getDurationInSecs(t1, t4)
                      << "\n";
            double interval = hmpl::getDurationInSecs(last_time, t4);
            if (interval > 0.14) {
                ROS_WARN("rcv map period : %f", interval);
            }
            last_time = t4;
            sub_.ResetFlag();
        }
        freq.sleep();
    }
    this->endDisplayThread();
}
int main(int argc, char **argv) {
    ros::init(argc, argv, "map_server_node");
    ros::NodeHandlePtr nh(new ros::NodeHandle());
    ros::NodeHandlePtr pnh(new ros::NodeHandle("~"));
    ConfigVariable cfg;
    // reading parameters from config file
    cfg.is_simulation = pnh->param("is_simulation", false);
    cfg.frame_id = pnh->param<std::string>("frame_id", "/base_link");
    cfg.normal_map_topic =
        pnh->param<std::string>("normal_map_topic",
                                "/final_traversable_area_optimized_topic");
    cfg.odom_pose_topic =
        pnh->param<std::string>("odom_pose_topic",
                                "/lidar_odometry_to_earth");
    cfg.publish_map_topic =
        pnh->param<std::string>("publish_map_topic",
                                "/local_grid_map");
    cfg.road_net_topic = pnh->param<std::string>("road_net_topic",
                                                 "/topology_global_path");
    cfg.vehicle_fuse_pose_topic = pnh->param<std::string>(
        "vehicle_fuse_pose_topic", "/sensor_fusion_output");
    cfg.back_up_map_topic =
        pnh->param<std::string>("back_up_map_topic",
                                "/single_traversable_area_optimized_topic");
    cfg.smoke_area_map_topic = pnh->param<std::string>(
        "smoke_area_map_topic", "/Grid_Map_topic");
    cfg.use_roadnet_limit_fessible_area = pnh->param(
        "use_roadnet_limit_fessible_area", false);
    cfg.use_local_frame = pnh->param("use_local_frame", false);
    cfg.base_shift = pnh->param("base_point_shift", 0.0);
    MapServer map_server(cfg, nh.get());
    map_server.run();
    return 0;
}

