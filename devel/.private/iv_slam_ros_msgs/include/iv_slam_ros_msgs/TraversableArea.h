// Generated by gencpp from file iv_slam_ros_msgs/TraversableArea.msg
// DO NOT EDIT!


#ifndef IV_SLAM_ROS_MSGS_MESSAGE_TRAVERSABLEAREA_H
#define IV_SLAM_ROS_MSGS_MESSAGE_TRAVERSABLEAREA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Pose.h>

namespace iv_slam_ros_msgs
{
template <class ContainerAllocator>
struct TraversableArea_
{
  typedef TraversableArea_<ContainerAllocator> Type;

  TraversableArea_()
    : header()
    , index(0)
    , width(0)
    , height(0)
    , triD_submap_pose_image_index_x(0)
    , triD_submap_pose_image_index_y(0)
    , resolution(0.0)
    , triD_submap_pose()
    , cells()
    , submap_finished_flag(false)
    , valid(false)  {
    }
  TraversableArea_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , index(0)
    , width(0)
    , height(0)
    , triD_submap_pose_image_index_x(0)
    , triD_submap_pose_image_index_y(0)
    , resolution(0.0)
    , triD_submap_pose(_alloc)
    , cells(_alloc)
    , submap_finished_flag(false)
    , valid(false)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _index_type;
  _index_type index;

   typedef int32_t _width_type;
  _width_type width;

   typedef int32_t _height_type;
  _height_type height;

   typedef int32_t _triD_submap_pose_image_index_x_type;
  _triD_submap_pose_image_index_x_type triD_submap_pose_image_index_x;

   typedef int32_t _triD_submap_pose_image_index_y_type;
  _triD_submap_pose_image_index_y_type triD_submap_pose_image_index_y;

   typedef double _resolution_type;
  _resolution_type resolution;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _triD_submap_pose_type;
  _triD_submap_pose_type triD_submap_pose;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _cells_type;
  _cells_type cells;

   typedef uint8_t _submap_finished_flag_type;
  _submap_finished_flag_type submap_finished_flag;

   typedef uint8_t _valid_type;
  _valid_type valid;





  typedef boost::shared_ptr< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> const> ConstPtr;

}; // struct TraversableArea_

typedef ::iv_slam_ros_msgs::TraversableArea_<std::allocator<void> > TraversableArea;

typedef boost::shared_ptr< ::iv_slam_ros_msgs::TraversableArea > TraversableAreaPtr;
typedef boost::shared_ptr< ::iv_slam_ros_msgs::TraversableArea const> TraversableAreaConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace iv_slam_ros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'iv_slam_ros_msgs': ['/home/bit2/0603_project/tang_ws/src/msgs/iv_slam_ros_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> >
{
  static const char* value()
  {
    return "482941e098397ea7b53454e6559ff9de";
  }

  static const char* value(const ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x482941e098397ea7ULL;
  static const uint64_t static_value2 = 0xb53454e6559ff9deULL;
};

template<class ContainerAllocator>
struct DataType< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> >
{
  static const char* value()
  {
    return "iv_slam_ros_msgs/TraversableArea";
  }

  static const char* value(const ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
std_msgs/Header header\n\
int32 index\n\
int32 width\n\
int32 height\n\
int32 triD_submap_pose_image_index_x\n\
int32 triD_submap_pose_image_index_y\n\
float64 resolution\n\
geometry_msgs/Pose triD_submap_pose\n\
uint8[] cells\n\
bool submap_finished_flag\n\
bool valid\n\
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
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.index);
      stream.next(m.width);
      stream.next(m.height);
      stream.next(m.triD_submap_pose_image_index_x);
      stream.next(m.triD_submap_pose_image_index_y);
      stream.next(m.resolution);
      stream.next(m.triD_submap_pose);
      stream.next(m.cells);
      stream.next(m.submap_finished_flag);
      stream.next(m.valid);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TraversableArea_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::iv_slam_ros_msgs::TraversableArea_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "index: ";
    Printer<int32_t>::stream(s, indent + "  ", v.index);
    s << indent << "width: ";
    Printer<int32_t>::stream(s, indent + "  ", v.width);
    s << indent << "height: ";
    Printer<int32_t>::stream(s, indent + "  ", v.height);
    s << indent << "triD_submap_pose_image_index_x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.triD_submap_pose_image_index_x);
    s << indent << "triD_submap_pose_image_index_y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.triD_submap_pose_image_index_y);
    s << indent << "resolution: ";
    Printer<double>::stream(s, indent + "  ", v.resolution);
    s << indent << "triD_submap_pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.triD_submap_pose);
    s << indent << "cells[]" << std::endl;
    for (size_t i = 0; i < v.cells.size(); ++i)
    {
      s << indent << "  cells[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.cells[i]);
    }
    s << indent << "submap_finished_flag: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.submap_finished_flag);
    s << indent << "valid: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.valid);
  }
};

} // namespace message_operations
} // namespace ros

#endif // IV_SLAM_ROS_MSGS_MESSAGE_TRAVERSABLEAREA_H
