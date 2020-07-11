#include "chassis_testing.h"
#include "chassis_testing/StaticTestingConfig.h"

StaticTestingParameters parameters;

void dynamic_callback(chassis_testing::StaticTestingConfig &config) {
    ROS_INFO("Reconfigure Request");
    parameters.gear = config.gear;
    parameters.target_torque = config.target_torque;
    parameters.halt = config.halt;
    parameters.steer_degree = config.steer_degree;
 
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "static_testing");
    ros::NodeHandle pnh = ros::NodeHandle("~");

    dynamic_reconfigure::Server<chassis_testing::StaticTestingConfig> server;
    dynamic_reconfigure::Server<chassis_testing::StaticTestingConfig>::CallbackType callback;
    callback = boost::bind(&dynamic_callback, _1);
    server.setCallback(callback);
    control_msgs::Control tang;
    ChassisTesting chassis_testing;

    bool get_param = true;
    get_param &= pnh.getParam("publish_rate", parameters.publish_rate);
    get_param &= pnh.getParam("gear", parameters.gear);
    get_param &= pnh.getParam("target_torque", parameters.target_torque);
    get_param &= pnh.getParam("halt", parameters.halt);
    get_param &= pnh.getParam("steer_degree", parameters.steer_degree);
   
    if (!get_param) {
        ROS_ERROR_STREAM("param not retrieved");
        ros::shutdown();
    }

    ros::Rate rate(parameters.publish_rate);

    while (ros::ok()) {
        ros::spinOnce();
        tang.Speed.priority = 0;
        tang.Speed.gear = parameters.gear;

	//tang.Speed
        tang.Speed.torque = parameters.target_torque;
        tang.Speed.brake = parameters.halt;

        tang.Steer.priority = 0;
        tang.Steer.steer = parameters.steer_degree*17.7;

        chassis_testing.messagesPublish(tang);
        rate.sleep();
    }
}
