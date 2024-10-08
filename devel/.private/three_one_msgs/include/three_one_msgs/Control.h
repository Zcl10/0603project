// Generated by gencpp from file three_one_msgs/Control.msg
// DO NOT EDIT!


#ifndef THREE_ONE_MSGS_MESSAGE_CONTROL_H
#define THREE_ONE_MSGS_MESSAGE_CONTROL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <three_one_msgs/ControlSpeed.h>
#include <three_one_msgs/ControlSteer.h>
#include <three_one_msgs/ControlSuspension.h>
#include <three_one_msgs/ControlWeapon.h>

namespace three_one_msgs
{
template <class ContainerAllocator>
struct Control_
{
  typedef Control_<ContainerAllocator> Type;

  Control_()
    : priority(0)
    , speed()
    , steer()
    , suspension()
    , weapon()  {
    }
  Control_(const ContainerAllocator& _alloc)
    : priority(0)
    , speed(_alloc)
    , steer(_alloc)
    , suspension(_alloc)
    , weapon(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _priority_type;
  _priority_type priority;

   typedef  ::three_one_msgs::ControlSpeed_<ContainerAllocator>  _speed_type;
  _speed_type speed;

   typedef  ::three_one_msgs::ControlSteer_<ContainerAllocator>  _steer_type;
  _steer_type steer;

   typedef  ::three_one_msgs::ControlSuspension_<ContainerAllocator>  _suspension_type;
  _suspension_type suspension;

   typedef  ::three_one_msgs::ControlWeapon_<ContainerAllocator>  _weapon_type;
  _weapon_type weapon;





  typedef boost::shared_ptr< ::three_one_msgs::Control_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::three_one_msgs::Control_<ContainerAllocator> const> ConstPtr;

}; // struct Control_

typedef ::three_one_msgs::Control_<std::allocator<void> > Control;

typedef boost::shared_ptr< ::three_one_msgs::Control > ControlPtr;
typedef boost::shared_ptr< ::three_one_msgs::Control const> ControlConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::three_one_msgs::Control_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::three_one_msgs::Control_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::three_one_msgs::Control_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::three_one_msgs::Control_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::three_one_msgs::Control_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::three_one_msgs::Control_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::three_one_msgs::Control_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::three_one_msgs::Control_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::three_one_msgs::Control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d0ddf03a8d19a85e773b681a9262d15c";
  }

  static const char* value(const ::three_one_msgs::Control_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd0ddf03a8d19a85eULL;
  static const uint64_t static_value2 = 0x773b681a9262d15cULL;
};

template<class ContainerAllocator>
struct DataType< ::three_one_msgs::Control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "three_one_msgs/Control";
  }

  static const char* value(const ::three_one_msgs::Control_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::three_one_msgs::Control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 priority\n\
ControlSpeed speed\n\
ControlSteer steer\n\
ControlSuspension suspension\n\
ControlWeapon weapon\n\
================================================================================\n\
MSG: three_one_msgs/ControlSpeed\n\
uint8 priority\n\
uint8 halt\n\
uint8 gear\n\
float32 speed\n\
================================================================================\n\
MSG: three_one_msgs/ControlSteer\n\
uint8 priority\n\
float64 curvature\n\
================================================================================\n\
MSG: three_one_msgs/ControlSuspension\n\
uint8 priority\n\
uint8 cylinder_select\n\
uint8 suspension_select\n\
uint8 suspension_work_mode\n\
uint8 suspension_work_mode_detail\n\
uint8 suspension_cylinder_select_mode\n\
uint8 suspension_cylinder_motor_control\n\
uint8 vertical_wall_mode\n\
uint8 fix_two_chamber_valve\n\
uint8 entrenchment\n\
================================================================================\n\
MSG: three_one_msgs/ControlWeapon\n\
uint8 priority\n\
uint8 weapon_330\n\
uint8 weapon_28\n\
uint8 weapon_cmd\n\
";
  }

  static const char* value(const ::three_one_msgs::Control_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::three_one_msgs::Control_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.priority);
      stream.next(m.speed);
      stream.next(m.steer);
      stream.next(m.suspension);
      stream.next(m.weapon);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Control_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::three_one_msgs::Control_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::three_one_msgs::Control_<ContainerAllocator>& v)
  {
    s << indent << "priority: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.priority);
    s << indent << "speed: ";
    s << std::endl;
    Printer< ::three_one_msgs::ControlSpeed_<ContainerAllocator> >::stream(s, indent + "  ", v.speed);
    s << indent << "steer: ";
    s << std::endl;
    Printer< ::three_one_msgs::ControlSteer_<ContainerAllocator> >::stream(s, indent + "  ", v.steer);
    s << indent << "suspension: ";
    s << std::endl;
    Printer< ::three_one_msgs::ControlSuspension_<ContainerAllocator> >::stream(s, indent + "  ", v.suspension);
    s << indent << "weapon: ";
    s << std::endl;
    Printer< ::three_one_msgs::ControlWeapon_<ContainerAllocator> >::stream(s, indent + "  ", v.weapon);
  }
};

} // namespace message_operations
} // namespace ros

#endif // THREE_ONE_MSGS_MESSAGE_CONTROL_H
