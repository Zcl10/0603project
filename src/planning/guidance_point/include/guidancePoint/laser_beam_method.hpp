#ifndef ROUTE_PUBLISHER_LASER_BEAM_METHOD_HPP
#define ROUTE_PUBLISHER_LASER_BEAM_METHOD_HPP

#include <internal_grid_map/internal_grid_map.hpp>
#include <opt_utils/opt_utils.hpp>

typedef struct AngleDdist {
    double angle;
    double dist;
} AngleDdist;
typedef struct Prob_cross {
    AngleDdist d;
    double weight;
    bool update;
} Prob_cross;

typedef struct LontituteLine {
    double dist;
    double offset;
} LontituteLine;

class LaserBeamMethod {
 public:
    AngleDdist cross_prob;
    LaserBeamMethod(hmpl::InternalGridMap &map,
                    const hmpl::State &vehicle_state,
                    double resolution = 1.0,
                    double step = 0.5);
    void setParams(double pre_distance, double resolution = 1.0,
                   double step = 0.5);
    void setCollisionThrehold(double value);
    void getDistInEachAngle(double start_angle,
                            double end_angle,
                            std::vector<AngleDdist> *angle_dist);
    void getLontituteLine(double lower,
                          double upper,
                          std::vector<LontituteLine> *line);
    double getBestOffset(const std::vector<LontituteLine> &line_set);

    void getLaserBeam(const std::vector<AngleDdist> &disAngle,
                      std::vector<std::vector<AngleDdist>> *laser_beam);

    bool isCollision(double x, double y);

 private:
    double collision_circle_;
    double angle_resolution_;
    double laser_line_step_;
    double laser_length_limit_;
    double lat_offset_resolution_;
    std::vector<Prob_cross> prob_cross_pos_;

    hmpl::InternalGridMap &local_map_;
    const hmpl::State &vehicle_state_;
    /**
     * return a vectoer contains <angle-dist> parirs those (dist > laser_length_limit_)
     * @param start_angle
     * @param end_angle
     * @param angle_dist
     */



};
#endif //ROUTE_PUBLISHER_LASER_BEAM_METHOD_HPP
//1、分角度：
//    前方：0～180
//    后方：180～360
//    精度：1度
//2、计算每一个角度上的激光线的长度(该角度上能走的最远距离)
//3、遍历360个方向，找出连续的、距离大于20米的方向；
//4、计算正前方方向的概率；