// Generated by gencpp from file iv_slam_ros_msgs/OptimizationInsertResultResponse.msg
// DO NOT EDIT!


#ifndef IV_SLAM_ROS_MSGS_MESSAGE_OPTIMIZATIONINSERTRESULTRESPONSE_H
#define IV_SLAM_ROS_MSGS_MESSAGE_OPTIMIZATIONINSERTRESULTRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace iv_slam_ros_msgs
{
template <class ContainerAllocator>
struct OptimizationInsertResultResponse_
{
  typedef OptimizationInsertResultResponse_<ContainerAllocator> Type;

  OptimizationInsertResultResponse_()
    {
    }
  OptimizationInsertResultResponse_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> const> ConstPtr;

}; // struct OptimizationInsertResultResponse_

typedef ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<std::allocator<void> > OptimizationInsertResultResponse;

typedef boost::shared_ptr< ::iv_slam_ros_msgs::OptimizationInsertResultResponse > OptimizationInsertResultResponsePtr;
typedef boost::shared_ptr< ::iv_slam_ros_msgs::OptimizationInsertResultResponse const> OptimizationInsertResultResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace iv_slam_ros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'iv_slam_ros_msgs': ['/home/bit2/0603_project/tang_ws/src/msgs/iv_slam_ros_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "iv_slam_ros_msgs/OptimizationInsertResultResponse";
  }

  static const char* value(const ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
";
  }

  static const char* value(const ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct OptimizationInsertResultResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::iv_slam_ros_msgs::OptimizationInsertResultResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // IV_SLAM_ROS_MSGS_MESSAGE_OPTIMIZATIONINSERTRESULTRESPONSE_H
