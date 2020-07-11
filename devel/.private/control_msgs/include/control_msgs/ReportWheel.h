// Generated by gencpp from file control_msgs/ReportWheel.msg
// DO NOT EDIT!


#ifndef CONTROL_MSGS_MESSAGE_REPORTWHEEL_H
#define CONTROL_MSGS_MESSAGE_REPORTWHEEL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace control_msgs
{
template <class ContainerAllocator>
struct ReportWheel_
{
  typedef ReportWheel_<ContainerAllocator> Type;

  ReportWheel_()
    : front_left(0.0)
    , front_right(0.0)
    , rear_left(0.0)
    , rear_right(0.0)
    , statusfl(0)
    , statusfr(0)
    , statusrl(0)
    , statusrr(0)  {
    }
  ReportWheel_(const ContainerAllocator& _alloc)
    : front_left(0.0)
    , front_right(0.0)
    , rear_left(0.0)
    , rear_right(0.0)
    , statusfl(0)
    , statusfr(0)
    , statusrl(0)
    , statusrr(0)  {
  (void)_alloc;
    }



   typedef float _front_left_type;
  _front_left_type front_left;

   typedef float _front_right_type;
  _front_right_type front_right;

   typedef float _rear_left_type;
  _rear_left_type rear_left;

   typedef float _rear_right_type;
  _rear_right_type rear_right;

   typedef uint8_t _statusfl_type;
  _statusfl_type statusfl;

   typedef uint8_t _statusfr_type;
  _statusfr_type statusfr;

   typedef uint8_t _statusrl_type;
  _statusrl_type statusrl;

   typedef uint8_t _statusrr_type;
  _statusrr_type statusrr;





  typedef boost::shared_ptr< ::control_msgs::ReportWheel_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::control_msgs::ReportWheel_<ContainerAllocator> const> ConstPtr;

}; // struct ReportWheel_

typedef ::control_msgs::ReportWheel_<std::allocator<void> > ReportWheel;

typedef boost::shared_ptr< ::control_msgs::ReportWheel > ReportWheelPtr;
typedef boost::shared_ptr< ::control_msgs::ReportWheel const> ReportWheelConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::control_msgs::ReportWheel_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::control_msgs::ReportWheel_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace control_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_driver_msgs': ['/home/bit2/0603_project/tang_ws/src/msgs/sensor_driver_msgs/msg'], 'control_msgs': ['/home/bit2/0603_project/tang_ws/src/msgs/control_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::control_msgs::ReportWheel_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::control_msgs::ReportWheel_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_msgs::ReportWheel_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_msgs::ReportWheel_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_msgs::ReportWheel_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_msgs::ReportWheel_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::control_msgs::ReportWheel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c3a44de250eee4620714d052b512e107";
  }

  static const char* value(const ::control_msgs::ReportWheel_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc3a44de250eee462ULL;
  static const uint64_t static_value2 = 0x0714d052b512e107ULL;
};

template<class ContainerAllocator>
struct DataType< ::control_msgs::ReportWheel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "control_msgs/ReportWheel";
  }

  static const char* value(const ::control_msgs::ReportWheel_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::control_msgs::ReportWheel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 front_left\n\
float32 front_right\n\
float32 rear_left\n\
float32 rear_right\n\
uint8 statusfl\n\
uint8 statusfr\n\
uint8 statusrl\n\
uint8 statusrr\n\
";
  }

  static const char* value(const ::control_msgs::ReportWheel_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::control_msgs::ReportWheel_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.front_left);
      stream.next(m.front_right);
      stream.next(m.rear_left);
      stream.next(m.rear_right);
      stream.next(m.statusfl);
      stream.next(m.statusfr);
      stream.next(m.statusrl);
      stream.next(m.statusrr);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReportWheel_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::control_msgs::ReportWheel_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::control_msgs::ReportWheel_<ContainerAllocator>& v)
  {
    s << indent << "front_left: ";
    Printer<float>::stream(s, indent + "  ", v.front_left);
    s << indent << "front_right: ";
    Printer<float>::stream(s, indent + "  ", v.front_right);
    s << indent << "rear_left: ";
    Printer<float>::stream(s, indent + "  ", v.rear_left);
    s << indent << "rear_right: ";
    Printer<float>::stream(s, indent + "  ", v.rear_right);
    s << indent << "statusfl: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.statusfl);
    s << indent << "statusfr: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.statusfr);
    s << indent << "statusrl: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.statusrl);
    s << indent << "statusrr: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.statusrr);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CONTROL_MSGS_MESSAGE_REPORTWHEEL_H
