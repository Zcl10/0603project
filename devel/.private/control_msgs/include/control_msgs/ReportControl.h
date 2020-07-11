// Generated by gencpp from file control_msgs/ReportControl.msg
// DO NOT EDIT!


#ifndef CONTROL_MSGS_MESSAGE_REPORTCONTROL_H
#define CONTROL_MSGS_MESSAGE_REPORTCONTROL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <control_msgs/ControlSpeed.h>
#include <control_msgs/ControlSteer.h>
#include <control_msgs/ControlMode.h>

namespace control_msgs
{
template <class ContainerAllocator>
struct ReportControl_
{
  typedef ReportControl_<ContainerAllocator> Type;

  ReportControl_()
    : Speed()
    , Steer()
    , ordermode()  {
    }
  ReportControl_(const ContainerAllocator& _alloc)
    : Speed(_alloc)
    , Steer(_alloc)
    , ordermode(_alloc)  {
  (void)_alloc;
    }



   typedef  ::control_msgs::ControlSpeed_<ContainerAllocator>  _Speed_type;
  _Speed_type Speed;

   typedef  ::control_msgs::ControlSteer_<ContainerAllocator>  _Steer_type;
  _Steer_type Steer;

   typedef  ::control_msgs::ControlMode_<ContainerAllocator>  _ordermode_type;
  _ordermode_type ordermode;





  typedef boost::shared_ptr< ::control_msgs::ReportControl_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::control_msgs::ReportControl_<ContainerAllocator> const> ConstPtr;

}; // struct ReportControl_

typedef ::control_msgs::ReportControl_<std::allocator<void> > ReportControl;

typedef boost::shared_ptr< ::control_msgs::ReportControl > ReportControlPtr;
typedef boost::shared_ptr< ::control_msgs::ReportControl const> ReportControlConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::control_msgs::ReportControl_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::control_msgs::ReportControl_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace control_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_driver_msgs': ['/home/bit2/0603_project/tang_ws/src/msgs/sensor_driver_msgs/msg'], 'control_msgs': ['/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::control_msgs::ReportControl_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::control_msgs::ReportControl_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_msgs::ReportControl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_msgs::ReportControl_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_msgs::ReportControl_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_msgs::ReportControl_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::control_msgs::ReportControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4cfa3145374ffabe5a1139ad8f40e485";
  }

  static const char* value(const ::control_msgs::ReportControl_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4cfa3145374ffabeULL;
  static const uint64_t static_value2 = 0x5a1139ad8f40e485ULL;
};

template<class ContainerAllocator>
struct DataType< ::control_msgs::ReportControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "control_msgs/ReportControl";
  }

  static const char* value(const ::control_msgs::ReportControl_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::control_msgs::ReportControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ControlSpeed Speed\n\
ControlSteer Steer\n\
ControlMode ordermode\n\
\n\
\n\
================================================================================\n\
MSG: control_msgs/ControlSpeed\n\
Header header\n\
uint8 priority\n\
uint8 gear\n\
float64 speed\n\
float64 acc\n\
float64 torque\n\
float64 brake\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: control_msgs/ControlSteer\n\
Header header\n\
uint8 priority\n\
float64 steer\n\
\n\
\n\
================================================================================\n\
MSG: control_msgs/ControlMode\n\
Header header\n\
uint8 RainyLight\n\
\n\
\n\
";
  }

  static const char* value(const ::control_msgs::ReportControl_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::control_msgs::ReportControl_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Speed);
      stream.next(m.Steer);
      stream.next(m.ordermode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReportControl_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::control_msgs::ReportControl_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::control_msgs::ReportControl_<ContainerAllocator>& v)
  {
    s << indent << "Speed: ";
    s << std::endl;
    Printer< ::control_msgs::ControlSpeed_<ContainerAllocator> >::stream(s, indent + "  ", v.Speed);
    s << indent << "Steer: ";
    s << std::endl;
    Printer< ::control_msgs::ControlSteer_<ContainerAllocator> >::stream(s, indent + "  ", v.Steer);
    s << indent << "ordermode: ";
    s << std::endl;
    Printer< ::control_msgs::ControlMode_<ContainerAllocator> >::stream(s, indent + "  ", v.ordermode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CONTROL_MSGS_MESSAGE_REPORTCONTROL_H
