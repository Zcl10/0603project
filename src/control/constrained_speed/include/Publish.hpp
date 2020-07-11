#ifndef CONSTRAINED_SPEED_THREEONEPUBLISH_HPP
#define CONSTRAINED_SPEED_THREEONEPUBLISH_HPP

#include "DEFINEs.hpp"

const double_t mass = 3150;
const double_t Cd = 0.33;
const double_t A = 2.28;
const double_t fic = 0.0241;
const double_t r = 0.35;

namespace constrained_speed {

    struct speed_issue {
        double_t v;
        double_t acc;
    };

    class Publish {
    public:
        speed_issue publish(ros::NodeHandle nh,
                            std::vector<double_t> &p_time,
                            std::vector<double_t> &p_v,
                            std::vector<double_t> &p_acc,
                            double_t p_delay,
                            bool forward,
                            double collision_limit,
                            double brake_pressure) {
            /*static ros::Publisher steer_pub = nh.advertise<control_msgs::ControlSteer>("/steercmd", 1);
            static control_msgs::ControlSteer control_steer;
            control_steer.header.stamp = ros::Time().now();
            control_steer.header.frame_id = "steer";
            control_steer.priority = 1;
            control_steer.steer = 0;
            steer_pub.publish(control_steer);*/

            static ros::Publisher publisher = nh.advertise<control_msgs::ControlSpeed>("/speedcmd", 1);
            static control_msgs::ControlSpeed control_speed;
            speed_issue issue = issueCal(p_time, p_v, p_acc, p_delay);
            issue.v = std::min(issue.v, collision_limit);
            control_speed.header.stamp = ros::Time().now();
            control_speed.header.frame_id = "speed";
            control_speed.priority = 0;
            if (issue.v < 0.001) {
                control_speed.gear = (p_v[0] < 0.1) ? 3 : (forward ? 4 : 2);
                control_speed.speed = 0;
                control_speed.acc = 0;
                control_speed.torque = 0;
                control_speed.brake = (p_v[0] < 0.1) ? 0 : 1.0;
            } else {
                issue.v = std::max(issue.v, 0.1);
                control_speed.gear = forward ? 4 : 2;
                control_speed.speed = issue.v;
                control_speed.acc = issue.acc;
                double aw = -Cd * A * p_v[0] * p_v[0] / 2 / mass;
                double af = -fic * 9.8;
                if (issue.acc >= 0) {
                    control_speed.torque = brake_pressure < 0.3 ? mass * r * (issue.acc - aw - af) : 0;
                    control_speed.brake = 0;
                    ROS_INFO_STREAM("\033[1;42m Drive torque: " << control_speed.torque << "\033[0m.");
                } else if (issue.acc <= -1.0) {
                    control_speed.torque = 0;
                    control_speed.brake = 1.0;
                    ROS_INFO_STREAM("\033[1;41m Brake pressure: " << control_speed.brake << "\033[0m.");
                } else {
                    control_speed.torque = 0;
                    control_speed.brake = 0;
                }
            }
            publisher.publish(control_speed);
            return issue;
        }

        speed_issue issueCal(std::vector<double_t> &p_time,
                             std::vector<double_t> &p_v,
                             std::vector<double_t> &p_acc,
                             double_t p_delay) {
            size_t size = p_v.size();
            size_t delay_index = size - 2;
            double_t delay_ratio = 1.0;
            for (size_t i = 1; i < size; ++i) {
                if (p_time[i] > p_delay) {
                    delay_index = i - 1;
                    delay_ratio = (p_delay - p_time[i - 1]) / (p_time[i] - p_time[i - 1]);
                    break;
                }
            }
            speed_issue issue;
            issue.v = p_v[delay_index] + delay_ratio * (p_v[delay_index + 1] - p_v[delay_index]);
            issue.acc = p_acc[delay_index] + delay_ratio * (p_acc[delay_index + 1] - p_acc[delay_index]);
            return issue;
        }
    };

}

#endif //CONSTRAINED_SPEED_THREEONEPUBLISH_HPP
