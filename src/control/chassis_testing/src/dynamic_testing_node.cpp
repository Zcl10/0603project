#include "chassis_testing.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "dynamic_testing");
    ros::NodeHandle pnh = ros::NodeHandle("~");
    control_msgs::Control tang;
    ChassisTesting chassis_testing;
    DynamicTestingParameters parameters;

    bool get_param = true;
    get_param &= pnh.getParam("publish_rate", parameters.publish_rate);
    get_param &= pnh.getParam("lateral_acc", parameters.lateral_acc);
    get_param &= pnh.getParam("max_speed", parameters.max_speed);
    get_param &= pnh.getParam("prepare_time", parameters.prepare_time);
    get_param &= pnh.getParam("maintain_time", parameters.maintain_time);
    if (!get_param) {
        ROS_ERROR_STREAM("param not retrieved");
        ros::shutdown();
    }

    ros::Rate rate(parameters.publish_rate);

    while (ros::ok()) {
        ros::spinOnce();
        if (parameters.prepare_time > 0) {
            ROS_INFO_STREAM("Countdown of prepare time : " << parameters.prepare_time);

            tang.Speed.priority = 0;
            tang.Speed.gear = 0;
            tang.Speed.torque = 0;
            tang.Speed.brake = 0;

            tang.Steer.priority = 0;
            tang.Steer.steer = 0;

            parameters.prepare_time -= 1.0 / parameters.publish_rate;
        } else if (parameters.maintain_time > 0) {
            ROS_INFO_STREAM("Countdown of maintain time : " << parameters.maintain_time);
            tang.Speed.priority = 0;
            tang.Speed.gear = 3;
            tang.Speed.torque  = parameters.max_speed;
            tang.Speed.brake = 0;
            tang.Steer.priority = 0;
            tang.Steer.steer = 0;
            if (parameters.lateral_acc == 0)
                tang.Steer.steer = 0;
            else
                tang.Steer.steer = 0;//转向角度

            parameters.maintain_time -= 1.0 / parameters.publish_rate;
        } else {
            ROS_INFO("Waiting for stop");

            tang.Speed.priority = 0;
            tang.Speed.gear = 0;
            tang.Speed.torque = 0;
            tang.Speed.brake = 0;
            tang.Steer.priority = 0;
            tang.Steer.steer = 0;
        }
        chassis_testing.messagesPublish(tang);
        rate.sleep();
    }
}
