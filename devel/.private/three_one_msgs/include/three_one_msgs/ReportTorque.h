// Generated by gencpp from file three_one_msgs/ReportTorque.msg
// DO NOT EDIT!


#ifndef THREE_ONE_MSGS_MESSAGE_REPORTTORQUE_H
#define THREE_ONE_MSGS_MESSAGE_REPORTTORQUE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace three_one_msgs
{
template <class ContainerAllocator>
struct ReportTorque_
{
  typedef ReportTorque_<ContainerAllocator> Type;

  ReportTorque_()
    : left(0)
    , right(0)  {
    }
  ReportTorque_(const ContainerAllocator& _alloc)
    : left(0)
    , right(0)  {
  (void)_alloc;
    }



   typedef int16_t _left_type;
  _left_type left;

   typedef int16_t _right_type;
  _right_type right;





  typedef boost::shared_ptr< ::three_one_msgs::ReportTorque_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::three_one_msgs::ReportTorque_<ContainerAllocator> const> ConstPtr;

}; // struct ReportTorque_

typedef ::three_one_msgs::ReportTorque_<std::allocator<void> > ReportTorque;

typedef boost::shared_ptr< ::three_one_msgs::ReportTorque > ReportTorquePtr;
typedef boost::shared_ptr< ::three_one_msgs::ReportTorque const> ReportTorqueConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::three_one_msgs::ReportTorque_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::three_one_msgs::ReportTorque_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace three_one_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'three_one_msgs': ['/home/bit2/0603_project/tang_ws/src/msgs/three_one_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::three_one_msgs::ReportTorque_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::three_one_msgs::ReportTorque_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::three_one_msgs::ReportTorque_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::three_one_msgs::ReportTorque_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::three_one_msgs::ReportTorque_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::three_one_msgs::ReportTorque_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::three_one_msgs::ReportTorque_<ContainerAllocator> >
{
  static const char* value()
  {
    return "09d1b2323a1aeae9343e81809a820b60";
  }

  static const char* value(const ::three_one_msgs::ReportTorque_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x09d1b2323a1aeae9ULL;
  static const uint64_t static_value2 = 0x343e81809a820b60ULL;
};

template<class ContainerAllocator>
struct DataType< ::three_one_msgs::ReportTorque_<ContainerAllocator> >
{
  static const char* value()
  {
    return "three_one_msgs/ReportTorque";
  }

  static const char* value(const ::three_one_msgs::ReportTorque_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::three_one_msgs::ReportTorque_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16 left\n\
int16 right\n\
";
  }

  static const char* value(const ::three_one_msgs::ReportTorque_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::three_one_msgs::ReportTorque_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.left);
      stream.next(m.right);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReportTorque_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::three_one_msgs::ReportTorque_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::three_one_msgs::ReportTorque_<ContainerAllocator>& v)
  {
    s << indent << "left: ";
    Printer<int16_t>::stream(s, indent + "  ", v.left);
    s << indent << "right: ";
    Printer<int16_t>::stream(s, indent + "  ", v.right);
  }
};

} // namespace message_operations
} // namespace ros

#endif // THREE_ONE_MSGS_MESSAGE_REPORTTORQUE_H
