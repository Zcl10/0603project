//
// Created by yangt on 5/28/18.
//
#include "map_server/ros_interface.hpp"
#include <mutex>

#ifndef MAP_SERVER_MAP_SERVER_NODE_HPP
#define MAP_SERVER_MAP_SERVER_NODE_HPP

class MapServer {
 public:

    enum LightType {
        OFF_OFF = 0,
        ON_OFF = 1,
        OFF_ON = 2,
        ON_ON = 3,
        FLASH_OFF = 4,
        OFF_FLASH = 5,
        FLASH_FLASH = 6,
        FLASH_ON = 7,
        ON_FLASH = 8
    };

    /**
     * default constructor, in which parameters and ros topic are initialized
     */
    explicit MapServer(const ConfigVariable &config, ros::NodeHandle *nh);

    /**
     * main loop, in which we transform and publish the map message
     */
    void run();

    /**
     * calculate the distance from a point to a line
     * @param line_p1 one of the point on the line
     * @param line_p2 another different point on the line
     * @param pt given point
     * @return the signed distance which possitive value means that the point
     * is upon the line
     */
    template<typename PointType1, typename PointType2, typename PointType3>
    double getPointToLineDist(const PointType1 &line_p1,
                              const PointType2 &line_p2,
                              const PointType3 &pt) {
        Eigen::Vector2d v1(pt.x - line_p1.x, pt.y - line_p1.y);
        Eigen::Vector2d v2(line_p2.x - line_p1.x, line_p2.y - line_p1.y);
        double d1 = v1.dot(v2);
        if(d1 <= 0) {
            return v1.norm();
        } else {
            double d2 = v2.norm();
            if(d2 < 1e-3) {
                return d1;
            }
            double d3 = d1 / d2;
            if(d3 > d2) {
                auto v3 = v2 - v1;
                return v3.norm();
            } else {
                return sqrt(pow(v1.norm(), 2) + pow(d3, 2));
            }
        }
    }


    void startDisplayThread();
    void callDisplayThread();
    void endDisplayThread();

 private:

    /**
     * initializing parameters, reading from config file
     */
    void initParameters();

    /**
     * initialize grid map value.
     * if flag "use_roadnet_limit_fessible_area_"  = true, the drivable area
     * may be limited using global roadnet. otherwise the whole map will be
     * initialize a free map
     * @param map input the map need to be initialized
     */
    void initTraversibleArea(grid_map::GridMap *map);

    /**
     * filling specified polygon area into "free area"
     * @param map input map, which will be changed since filling polygon area
     * @param polygon specified polygon area
     */
    void polygonExtractionCV(const grid_map::Polygon &polygon,
                             grid_map::GridMap *map);

    /**
     * a refactor function, input diffirent type parammeters
     * @param points
     * @param map
     */
    void polygonExtractionCV(const PointSet &points, grid_map::GridMap *map);

    /**
     * the core function that convert RCIV map type to ETH grid map type.
     * RCIV type map may come from delphi radar or laser radar, we choose the
     * source in term of current task type. If task = SMOKE_AREA, we'll convert
     * the map from delphi radar. Otherwise we the map from laser radar
     * @param gridmap the result of ETH grid map
     */
    void convertIvMapTypeToGridMapType(grid_map::GridMap *gridmap);

    void convertSimulationPointCloudToGridMap(grid_map::GridMap *gridmap);

    /**
     * calculate the footprint of our vehicle, restored in rviz Marker type for
     * display
     * @param marker input a rviz marker, in which restore vehicle footprint
     */
    void getFootPrintMarker(visualization_msgs::Marker *marker);

    /**
     * set the value of variable light_type
     */
    void setLightType();

    /**
     * publish transform tree for rviz display
     * @param pose input current vehicle state
     */
    void publishTfTree(const hmpl::State &pose);

 private:
    /// coresponding flag variable
    const ConfigVariable &cfg_;

    /// the name of obstacle layer in grid_map
    const std::string obs_layer_;

    /// ros node handle
    ros::NodeHandle *nh_;
    RosSubscriber sub_;

    /// ros publisher of occupancy map
    ros::Publisher ocupancy_grid_pub_;
    /// ros publisher of ETH grid map
    ros::Publisher grid_map_pub_;
    /// ros publisher of rviz marker
    ros::Publisher rviz_pub_;
    /// ros publisher of light type
    ros::Publisher light_type_pub_;

    ros::Publisher planning_origin_pub_;

    /// final ETH grid map
    grid_map::GridMap gridmap_;
    /// transform tree broadcaster
    tf::TransformBroadcaster tf_broadcaster_;
    /// light type
    LightType light_type_;
    /// the distance from vehcle to roadnet
    double dist2road_;
    bool is_thread_active_;
    bool fill_map_over_;
    std::mutex mutex_;
};
#endif //MAP_SERVER_MAP_SERVER_NODE_HPP
