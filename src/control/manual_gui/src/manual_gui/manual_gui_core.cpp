#include "../../include/manual_gui_core.hpp"

namespace manual_gui {

manual_gui_demo::manual_gui_demo(ros::NodeHandle node_handle, ros::NodeHandle private_node_handle)
        : reconfigSrv_{private_node_handle}, params_{private_node_handle} {

    /**
     * Initialization
     */
    params_.fromParamServer();

    /**
     * Set up timer and dynamic reconfigure server
     */
    timer_ = private_node_handle.createTimer(ros::Duration(1. / params_.rate), &manual_gui_demo::timerCallback, this);
    reconfigSrv_.setCallback(boost::bind(&manual_gui_demo::reconfigureRequest, this, _1, _2));

    params_pub = n.advertise<control_msgs::ControlMode>("modecmd",1);
}

manual_gui_demo::~manual_gui_demo(){
    params_.rainy_light = 0;// rainy_mode
    params_.toParamServer();
}
/*
 * Use const ConstPtr for your callbacks.
 * The 'const' assures that you can not edit incoming messages.
 * The Ptr type guarantees zero copy transportation within nodelets.
 */
void manual_gui_demo::timerCallback(const ros::TimerEvent& event) {
//    ROS_INFO_STREAM("Timer callback. auto_mode = " << params_.auto_mode);
}

/**
  * This callback is called whenever a change was made in the dynamic_reconfigure window
*/
void manual_gui_demo::reconfigureRequest(DemoConfig& config, uint32_t level) {
    params_.fromConfig(config);
    timer_.setPeriod(ros::Duration(1. / params_.rate));
    ROS_WARN_STREAM("Parameter update:\n" << params_);
}
DemoParameters manual_gui_demo::GetParams(){
    return params_;
}

void manual_gui_demo::run() {
    DemoParameters node_params = GetParams();

    ros::Rate loop_rate(node_params.rate);
    while(ros::ok()){
        ros::spinOnce();
        control_msgs::ControlMode modecmd_;
        modecmd_.RainyLight = params_.rainy_light;// Rainy

        params_pub.publish(modecmd_);
        ROS_INFO("rainy_light:%d",modecmd_.RainyLight);
        loop_rate.sleep();
    }
}
} // namespace rosparam_handler_tutorial
