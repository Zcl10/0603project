// Generated by gencpp from file three_one_msgs/Report.msg
// DO NOT EDIT!


#ifndef THREE_ONE_MSGS_MESSAGE_REPORT_H
#define THREE_ONE_MSGS_MESSAGE_REPORT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <three_one_msgs/ReportControlData.h>
#include <three_one_msgs/ReportGiveBack.h>
#include <three_one_msgs/ReportCylinderPressure.h>
#include <three_one_msgs/ReportCylinderPosition.h>
#include <three_one_msgs/ReportVehicleState.h>
#include <three_one_msgs/ReportDistance.h>
#include <three_one_msgs/ReportTorque.h>
#include <three_one_msgs/ReportMotion.h>

namespace three_one_msgs
{
template <class ContainerAllocator>
struct Report_
{
  typedef Report_<ContainerAllocator> Type;

  Report_()
    : control()
    , give_back()
    , cylinder_pressure()
    , cylinder_position()
    , vehicle_state()
    , distance()
    , torque()
    , motion()
    , control_mode(0)
    , operation_mode(0)
    , counter(0)  {
    }
  Report_(const ContainerAllocator& _alloc)
    : control(_alloc)
    , give_back(_alloc)
    , cylinder_pressure(_alloc)
    , cylinder_position(_alloc)
    , vehicle_state(_alloc)
    , distance(_alloc)
    , torque(_alloc)
    , motion(_alloc)
    , control_mode(0)
    , operation_mode(0)
    , counter(0)  {
  (void)_alloc;
    }



   typedef  ::three_one_msgs::ReportControlData_<ContainerAllocator>  _control_type;
  _control_type control;

   typedef  ::three_one_msgs::ReportGiveBack_<ContainerAllocator>  _give_back_type;
  _give_back_type give_back;

   typedef  ::three_one_msgs::ReportCylinderPressure_<ContainerAllocator>  _cylinder_pressure_type;
  _cylinder_pressure_type cylinder_pressure;

   typedef  ::three_one_msgs::ReportCylinderPosition_<ContainerAllocator>  _cylinder_position_type;
  _cylinder_position_type cylinder_position;

   typedef  ::three_one_msgs::ReportVehicleState_<ContainerAllocator>  _vehicle_state_type;
  _vehicle_state_type vehicle_state;

   typedef  ::three_one_msgs::ReportDistance_<ContainerAllocator>  _distance_type;
  _distance_type distance;

   typedef  ::three_one_msgs::ReportTorque_<ContainerAllocator>  _torque_type;
  _torque_type torque;

   typedef  ::three_one_msgs::ReportMotion_<ContainerAllocator>  _motion_type;
  _motion_type motion;

   typedef uint8_t _control_mode_type;
  _control_mode_type control_mode;

   typedef uint8_t _operation_mode_type;
  _operation_mode_type operation_mode;

   typedef uint64_t _counter_type;
  _counter_type counter;





  typedef boost::shared_ptr< ::three_one_msgs::Report_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::three_one_msgs::Report_<ContainerAllocator> const> ConstPtr;

}; // struct Report_

typedef ::three_one_msgs::Report_<std::allocator<void> > Report;

typedef boost::shared_ptr< ::three_one_msgs::Report > ReportPtr;
typedef boost::shared_ptr< ::three_one_msgs::Report const> ReportConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::three_one_msgs::Report_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::three_one_msgs::Report_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::three_one_msgs::Report_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::three_one_msgs::Report_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::three_one_msgs::Report_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::three_one_msgs::Report_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::three_one_msgs::Report_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::three_one_msgs::Report_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::three_one_msgs::Report_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cb7eb1891ce051b9221ffe7f0ad827d8";
  }

  static const char* value(const ::three_one_msgs::Report_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcb7eb1891ce051b9ULL;
  static const uint64_t static_value2 = 0x221ffe7f0ad827d8ULL;
};

template<class ContainerAllocator>
struct DataType< ::three_one_msgs::Report_<ContainerAllocator> >
{
  static const char* value()
  {
    return "three_one_msgs/Report";
  }

  static const char* value(const ::three_one_msgs::Report_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::three_one_msgs::Report_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ReportControlData control\n\
ReportGiveBack give_back\n\
ReportCylinderPressure cylinder_pressure\n\
ReportCylinderPosition cylinder_position\n\
ReportVehicleState vehicle_state\n\
ReportDistance distance\n\
ReportTorque torque\n\
ReportMotion motion\n\
uint8 control_mode\n\
uint8 operation_mode\n\
uint64 counter\n\
================================================================================\n\
MSG: three_one_msgs/ReportControlData\n\
float32 curvature\n\
float32 speed\n\
uint16 rpm\n\
uint8 work_mode\n\
uint8 gear\n\
uint8 turn_to\n\
uint8 brake\n\
uint8 park\n\
uint8 cylinder_select\n\
uint8 suspension_select\n\
uint8 vertical_wall_mode\n\
uint8 suspension_work_mode\n\
uint8 suspension_work_mode_detail\n\
uint8 suspension_cylinder_select_mode\n\
uint8 suspension_cylinder_motor_control\n\
uint8 fix_two_chamber_valve\n\
================================================================================\n\
MSG: three_one_msgs/ReportGiveBack\n\
float32 left_wheel_expect_speed\n\
float32 right_wheel_expect_speed\n\
================================================================================\n\
MSG: three_one_msgs/ReportCylinderPressure\n\
uint8 left_one\n\
uint8 left_two\n\
uint8 left_three\n\
uint8 left_four\n\
uint8 right_one\n\
uint8 right_two\n\
uint8 right_three\n\
uint8 right_four\n\
================================================================================\n\
MSG: three_one_msgs/ReportCylinderPosition\n\
uint16 left_one\n\
uint16 left_two\n\
uint16 left_three\n\
uint16 left_four\n\
uint16 right_one\n\
uint16 right_two\n\
uint16 right_three\n\
uint16 right_four\n\
================================================================================\n\
MSG: three_one_msgs/ReportVehicleState\n\
uint8 error_code\n\
uint8 two_chamber_valve\n\
uint8 vertical_wall_status\n\
uint8 entrenchment\n\
uint8 weapon_330\n\
uint8 weapon_28\n\
uint8 vehicle_height\n\
uint8 tailgate_state\n\
uint8 SOC\n\
int8 vehicle_roll\n\
int8 vehicle_pitch\n\
================================================================================\n\
MSG: three_one_msgs/ReportDistance\n\
uint32 mileage\n\
uint32 left_pulse\n\
uint32 right_pulse\n\
float64 left_distance\n\
float64 right_distance\n\
================================================================================\n\
MSG: three_one_msgs/ReportTorque\n\
int16 left\n\
int16 right\n\
================================================================================\n\
MSG: three_one_msgs/ReportMotion\n\
uint8 spin\n\
uint8 park\n\
uint8 current_gear\n\
uint8 left_wheel_rotate\n\
uint8 right_wheel_rotate\n\
uint16 left_motor_rpm\n\
uint16 right_motor_rpm\n\
float32 mechanical_brake\n\
float64 vehicle_speed\n\
float64 left_wheel_speed  # signed\n\
float64 right_wheel_speed  # signed\n\
float32 curvature\n\
";
  }

  static const char* value(const ::three_one_msgs::Report_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::three_one_msgs::Report_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.control);
      stream.next(m.give_back);
      stream.next(m.cylinder_pressure);
      stream.next(m.cylinder_position);
      stream.next(m.vehicle_state);
      stream.next(m.distance);
      stream.next(m.torque);
      stream.next(m.motion);
      stream.next(m.control_mode);
      stream.next(m.operation_mode);
      stream.next(m.counter);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Report_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::three_one_msgs::Report_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::three_one_msgs::Report_<ContainerAllocator>& v)
  {
    s << indent << "control: ";
    s << std::endl;
    Printer< ::three_one_msgs::ReportControlData_<ContainerAllocator> >::stream(s, indent + "  ", v.control);
    s << indent << "give_back: ";
    s << std::endl;
    Printer< ::three_one_msgs::ReportGiveBack_<ContainerAllocator> >::stream(s, indent + "  ", v.give_back);
    s << indent << "cylinder_pressure: ";
    s << std::endl;
    Printer< ::three_one_msgs::ReportCylinderPressure_<ContainerAllocator> >::stream(s, indent + "  ", v.cylinder_pressure);
    s << indent << "cylinder_position: ";
    s << std::endl;
    Printer< ::three_one_msgs::ReportCylinderPosition_<ContainerAllocator> >::stream(s, indent + "  ", v.cylinder_position);
    s << indent << "vehicle_state: ";
    s << std::endl;
    Printer< ::three_one_msgs::ReportVehicleState_<ContainerAllocator> >::stream(s, indent + "  ", v.vehicle_state);
    s << indent << "distance: ";
    s << std::endl;
    Printer< ::three_one_msgs::ReportDistance_<ContainerAllocator> >::stream(s, indent + "  ", v.distance);
    s << indent << "torque: ";
    s << std::endl;
    Printer< ::three_one_msgs::ReportTorque_<ContainerAllocator> >::stream(s, indent + "  ", v.torque);
    s << indent << "motion: ";
    s << std::endl;
    Printer< ::three_one_msgs::ReportMotion_<ContainerAllocator> >::stream(s, indent + "  ", v.motion);
    s << indent << "control_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.control_mode);
    s << indent << "operation_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.operation_mode);
    s << indent << "counter: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.counter);
  }
};

} // namespace message_operations
} // namespace ros

#endif // THREE_ONE_MSGS_MESSAGE_REPORT_H
