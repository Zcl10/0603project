// *********************************************************
//
// File autogenerated for the manual_gui package
// by the rosparam_handler package.
// Please do not edit.
//
// ********************************************************/

#pragma once

#include <ros/param.h>
#include <ros/node_handle.h>
#include <rosparam_handler/utilities.hpp>
#ifdef DYNAMIC_RECONFIGURE_FOUND
#include <manual_gui/DemoConfig.h>
#else
struct DemoConfig{};
#endif


namespace manual_gui {

/// \brief Parameter struct generated by rosparam_handler
struct DemoParameters {

  using Config = DemoConfig;

  DemoParameters(const ros::NodeHandle& private_node_handle)
  : globalNamespace{"/"},
    privateNamespace{private_node_handle.getNamespace() + "/"},
    nodeName{rosparam_handler::getNodeName(private_node_handle)} {}

  /// \brief Get values from parameter server
  /// 
  /// Will fail if a value can not be found and no default value is given.
  void fromParamServer(){
    bool success = true;
    success &= rosparam_handler::getParam(privateNamespace + "rate", rate, int{20});
    success &= rosparam_handler::getParam(privateNamespace + "auto_mode", auto_mode, bool{false});
    success &= rosparam_handler::getParam(privateNamespace + "longitude_enable", longitude_enable, bool{false});
    success &= rosparam_handler::getParam(privateNamespace + "torque_enable", torque_enable, bool{false});
    success &= rosparam_handler::getParam(privateNamespace + "rainy_mode", rainy_mode, bool{false});
    rosparam_handler::testMin<int>(privateNamespace + "rate", rate, 10);
    rosparam_handler::testMax<int>(privateNamespace + "rate", rate, 50);
    if(!success){
      missingParamsWarning();
      rosparam_handler::exit("RosparamHandler: GetParam could net retrieve parameter.");
    }
    ROS_DEBUG_STREAM(*this);
  }

  /// \brief Set parameters on ROS parameter server.
  void toParamServer(){
  rosparam_handler::setParam(privateNamespace + "rate",rate);
  rosparam_handler::setParam(privateNamespace + "auto_mode",auto_mode);
  rosparam_handler::setParam(privateNamespace + "longitude_enable",longitude_enable);
  rosparam_handler::setParam(privateNamespace + "torque_enable",torque_enable);
  rosparam_handler::setParam(privateNamespace + "rainy_mode",rainy_mode);        
  }

  /// \brief Update configurable parameters.
  ///
  /// \param config  dynamic reconfigure struct
  /// \level ?
  void fromConfig(const Config& config, const uint32_t level = 0){
#ifdef DYNAMIC_RECONFIGURE_FOUND
    rate = config.rate;
    auto_mode = config.auto_mode;
    longitude_enable = config.longitude_enable;
    torque_enable = config.torque_enable;
    rainy_mode = config.rainy_mode;
#else
  ROS_FATAL_STREAM("dynamic_reconfigure was not found during compilation. So fromConfig() is not available. Please recompile with dynamic_reconfigure.");
  rosparam_handler::exit("dynamic_reconfigure was not found during compilation. So fromConfig() is not available. Please recompile with dynamic_reconfigure.");
#endif
  }

  void toConfig(Config& config){
#ifdef DYNAMIC_RECONFIGURE_FOUND
       config.rate = rate;
   config.auto_mode = auto_mode;
   config.longitude_enable = longitude_enable;
   config.torque_enable = torque_enable;
   config.rainy_mode = rainy_mode;
#else
      ROS_FATAL_STREAM("dynamic_reconfigure was not found during compilation. So toConfig() is not available. Please recompile with dynamic_reconfigure.");
      rosparam_handler::exit("dynamic_reconfigure was not found during compilation. So toConfig() is not available. Please recompile with dynamic_reconfigure.");
#endif
  }

  /// \brief Stream operator for printing parameter struct
  friend std::ostream& operator<<(std::ostream& os, const DemoParameters& p)
  {
    os << "[" << p.nodeName << "]\nNode " << p.nodeName << " has the following parameters:\n"
      << "	" << p.privateNamespace << "rate:" << p.rate << "\n"
      << "	" << p.privateNamespace << "auto_mode:" << p.auto_mode << "\n"
      << "	" << p.privateNamespace << "longitude_enable:" << p.longitude_enable << "\n"
      << "	" << p.privateNamespace << "torque_enable:" << p.torque_enable << "\n"
      << "	" << p.privateNamespace << "rainy_mode:" << p.rainy_mode << "\n"
;
    return os;
  }

    int rate; /*!< Rate for timer */
  bool auto_mode; /*!< Rate for timer */
  bool longitude_enable; /*!< longitude enable */
  bool torque_enable; /*!< torque_enable */
  bool rainy_mode; /*!< turn on wiper */

private:
  /// \brief Issue a warning about missing default parameters.
  void missingParamsWarning(){
    ROS_WARN_STREAM("[" << nodeName << "]\nThe following parameters do not have default values and need to be specified:\n"
    );
  }

  const std::string globalNamespace;
  const std::string privateNamespace;
  const std::string nodeName;
};

} // namespace manual_gui
