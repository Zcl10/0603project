// Generated by gencpp from file iv_slam_ros_msgs/OptimizationImuRequest.msg
// DO NOT EDIT!


#ifndef IV_SLAM_ROS_MSGS_MESSAGE_OPTIMIZATIONIMUREQUEST_H
#define IV_SLAM_ROS_MSGS_MESSAGE_OPTIMIZATIONIMUREQUEST_H


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
struct OptimizationImuRequest_
{
  typedef OptimizationImuRequest_<ContainerAllocator> Type;

  OptimizationImuRequest_()
    : trajectory_id(0)
    , time(0.0)
    , linear_acceleration_x(0.0)
    , linear_acceleration_y(0.0)
    , linear_acceleration_z(0.0)
    , angular_velocity_x(0.0)
    , angular_velocity_y(0.0)
    , angular_velocity_z(0.0)  {
    }
  OptimizationImuRequest_(const ContainerAllocator& _alloc)
    : trajectory_id(0)
    , time(0.0)
    , linear_acceleration_x(0.0)
    , linear_acceleration_y(0.0)
    , linear_acceleration_z(0.0)
    , angular_velocity_x(0.0)
    , angular_velocity_y(0.0)
    , angular_velocity_z(0.0)  {
  (void)_alloc;
    }



   typedef int32_t _trajectory_id_type;
  _trajectory_id_type trajectory_id;

   typedef double _time_type;
  _time_type time;

   typedef double _linear_acceleration_x_type;
  _linear_acceleration_x_type linear_acceleration_x;

   typedef double _linear_acceleration_y_type;
  _linear_acceleration_y_type linear_acceleration_y;

   typedef double _linear_acceleration_z_type;
  _linear_acceleration_z_type linear_acceleration_z;

   typedef double _angular_velocity_x_type;
  _angular_velocity_x_type angular_velocity_x;

   typedef double _angular_velocity_y_type;
  _angular_velocity_y_type angular_velocity_y;

   typedef double _angular_velocity_z_type;
  _angular_velocity_z_type angular_velocity_z;





  typedef boost::shared_ptr< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> const> ConstPtr;

}; // struct OptimizationImuRequest_

typedef ::iv_slam_ros_msgs::OptimizationImuRequest_<std::allocator<void> > OptimizationImuRequest;

typedef boost::shared_ptr< ::iv_slam_ros_msgs::OptimizationImuRequest > OptimizationImuRequestPtr;
typedef boost::shared_ptr< ::iv_slam_ros_msgs::OptimizationImuRequest const> OptimizationImuRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a9d47262566a779b3929228069472871";
  }

  static const char* value(const ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa9d47262566a779bULL;
  static const uint64_t static_value2 = 0x3929228069472871ULL;
};

template<class ContainerAllocator>
struct DataType< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "iv_slam_ros_msgs/OptimizationImuRequest";
  }

  static const char* value(const ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 trajectory_id\n\
float64 time\n\
float64 linear_acceleration_x\n\
float64 linear_acceleration_y\n\
float64 linear_acceleration_z\n\
float64 angular_velocity_x\n\
float64 angular_velocity_y\n\
float64 angular_velocity_z\n\
";
  }

  static const char* value(const ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.trajectory_id);
      stream.next(m.time);
      stream.next(m.linear_acceleration_x);
      stream.next(m.linear_acceleration_y);
      stream.next(m.linear_acceleration_z);
      stream.next(m.angular_velocity_x);
      stream.next(m.angular_velocity_y);
      stream.next(m.angular_velocity_z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct OptimizationImuRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::iv_slam_ros_msgs::OptimizationImuRequest_<ContainerAllocator>& v)
  {
    s << indent << "trajectory_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.trajectory_id);
    s << indent << "time: ";
    Printer<double>::stream(s, indent + "  ", v.time);
    s << indent << "linear_acceleration_x: ";
    Printer<double>::stream(s, indent + "  ", v.linear_acceleration_x);
    s << indent << "linear_acceleration_y: ";
    Printer<double>::stream(s, indent + "  ", v.linear_acceleration_y);
    s << indent << "linear_acceleration_z: ";
    Printer<double>::stream(s, indent + "  ", v.linear_acceleration_z);
    s << indent << "angular_velocity_x: ";
    Printer<double>::stream(s, indent + "  ", v.angular_velocity_x);
    s << indent << "angular_velocity_y: ";
    Printer<double>::stream(s, indent + "  ", v.angular_velocity_y);
    s << indent << "angular_velocity_z: ";
    Printer<double>::stream(s, indent + "  ", v.angular_velocity_z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // IV_SLAM_ROS_MSGS_MESSAGE_OPTIMIZATIONIMUREQUEST_H
