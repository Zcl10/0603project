// Generated by gencpp from file control_msgs/ReportThrottle.msg
// DO NOT EDIT!


#ifndef CONTROL_MSGS_MESSAGE_REPORTTHROTTLE_H
#define CONTROL_MSGS_MESSAGE_REPORTTHROTTLE_H


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
struct ReportThrottle_
{
  typedef ReportThrottle_<ContainerAllocator> Type;

  ReportThrottle_()
    : throttle_opening(0.0)
    , throttle_pedal(0.0)  {
    }
  ReportThrottle_(const ContainerAllocator& _alloc)
    : throttle_opening(0.0)
    , throttle_pedal(0.0)  {
  (void)_alloc;
    }



   typedef float _throttle_opening_type;
  _throttle_opening_type throttle_opening;

   typedef float _throttle_pedal_type;
  _throttle_pedal_type throttle_pedal;





  typedef boost::shared_ptr< ::control_msgs::ReportThrottle_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::control_msgs::ReportThrottle_<ContainerAllocator> const> ConstPtr;

}; // struct ReportThrottle_

typedef ::control_msgs::ReportThrottle_<std::allocator<void> > ReportThrottle;

typedef boost::shared_ptr< ::control_msgs::ReportThrottle > ReportThrottlePtr;
typedef boost::shared_ptr< ::control_msgs::ReportThrottle const> ReportThrottleConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::control_msgs::ReportThrottle_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::control_msgs::ReportThrottle_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::control_msgs::ReportThrottle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::control_msgs::ReportThrottle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_msgs::ReportThrottle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::control_msgs::ReportThrottle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_msgs::ReportThrottle_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::control_msgs::ReportThrottle_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::control_msgs::ReportThrottle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3fec449e5f78595bef42751bd36df7c4";
  }

  static const char* value(const ::control_msgs::ReportThrottle_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3fec449e5f78595bULL;
  static const uint64_t static_value2 = 0xef42751bd36df7c4ULL;
};

template<class ContainerAllocator>
struct DataType< ::control_msgs::ReportThrottle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "control_msgs/ReportThrottle";
  }

  static const char* value(const ::control_msgs::ReportThrottle_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::control_msgs::ReportThrottle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 throttle_opening\n\
float32 throttle_pedal\n\
";
  }

  static const char* value(const ::control_msgs::ReportThrottle_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::control_msgs::ReportThrottle_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.throttle_opening);
      stream.next(m.throttle_pedal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReportThrottle_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::control_msgs::ReportThrottle_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::control_msgs::ReportThrottle_<ContainerAllocator>& v)
  {
    s << indent << "throttle_opening: ";
    Printer<float>::stream(s, indent + "  ", v.throttle_opening);
    s << indent << "throttle_pedal: ";
    Printer<float>::stream(s, indent + "  ", v.throttle_pedal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CONTROL_MSGS_MESSAGE_REPORTTHROTTLE_H
