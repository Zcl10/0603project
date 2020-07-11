// Auto-generated. Do not edit!

// (in-package path_tracking.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let control_msgs = _finder('control_msgs');
let std_msgs = _finder('std_msgs');
let anm_msgs = _finder('anm_msgs');

//-----------------------------------------------------------

class observer {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.vehicle_state = null;
      this.ecu_report = null;
      this.speed_cmd = null;
      this.steer_cmd = null;
      this.lateral_error = null;
      this.heading_error = null;
      this.time_cost = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('vehicle_state')) {
        this.vehicle_state = initObj.vehicle_state
      }
      else {
        this.vehicle_state = new anm_msgs.msg.VehicleState();
      }
      if (initObj.hasOwnProperty('ecu_report')) {
        this.ecu_report = initObj.ecu_report
      }
      else {
        this.ecu_report = new control_msgs.msg.Report();
      }
      if (initObj.hasOwnProperty('speed_cmd')) {
        this.speed_cmd = initObj.speed_cmd
      }
      else {
        this.speed_cmd = 0.0;
      }
      if (initObj.hasOwnProperty('steer_cmd')) {
        this.steer_cmd = initObj.steer_cmd
      }
      else {
        this.steer_cmd = 0.0;
      }
      if (initObj.hasOwnProperty('lateral_error')) {
        this.lateral_error = initObj.lateral_error
      }
      else {
        this.lateral_error = 0.0;
      }
      if (initObj.hasOwnProperty('heading_error')) {
        this.heading_error = initObj.heading_error
      }
      else {
        this.heading_error = 0.0;
      }
      if (initObj.hasOwnProperty('time_cost')) {
        this.time_cost = initObj.time_cost
      }
      else {
        this.time_cost = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type observer
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [vehicle_state]
    bufferOffset = anm_msgs.msg.VehicleState.serialize(obj.vehicle_state, buffer, bufferOffset);
    // Serialize message field [ecu_report]
    bufferOffset = control_msgs.msg.Report.serialize(obj.ecu_report, buffer, bufferOffset);
    // Serialize message field [speed_cmd]
    bufferOffset = _serializer.float64(obj.speed_cmd, buffer, bufferOffset);
    // Serialize message field [steer_cmd]
    bufferOffset = _serializer.float64(obj.steer_cmd, buffer, bufferOffset);
    // Serialize message field [lateral_error]
    bufferOffset = _serializer.float64(obj.lateral_error, buffer, bufferOffset);
    // Serialize message field [heading_error]
    bufferOffset = _serializer.float64(obj.heading_error, buffer, bufferOffset);
    // Serialize message field [time_cost]
    bufferOffset = _serializer.float64(obj.time_cost, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type observer
    let len;
    let data = new observer(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [vehicle_state]
    data.vehicle_state = anm_msgs.msg.VehicleState.deserialize(buffer, bufferOffset);
    // Deserialize message field [ecu_report]
    data.ecu_report = control_msgs.msg.Report.deserialize(buffer, bufferOffset);
    // Deserialize message field [speed_cmd]
    data.speed_cmd = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [steer_cmd]
    data.steer_cmd = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [lateral_error]
    data.lateral_error = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [heading_error]
    data.heading_error = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [time_cost]
    data.time_cost = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += anm_msgs.msg.VehicleState.getMessageSize(object.vehicle_state);
    length += control_msgs.msg.Report.getMessageSize(object.ecu_report);
    return length + 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'path_tracking/observer';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5f683c55d076db2e680be51e6dee7354';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    anm_msgs/VehicleState vehicle_state
    control_msgs/Report ecu_report
    float64 speed_cmd
    float64 steer_cmd
    float64 lateral_error
    float64 heading_error
    float64 time_cost
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    ================================================================================
    MSG: anm_msgs/VehicleState
    # This message describes the complete vehicle state
    # orientation = orientation of the vehicle using euler angles
    
    Header header
    string child_frame_id
    
    geometry_msgs/Point position
    geometry_msgs/Vector3 orientation
    geometry_msgs/Twist velocity
    geometry_msgs/Twist acceleration
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    ================================================================================
    MSG: geometry_msgs/Twist
    # This expresses velocity in free space broken into its linear and angular parts.
    Vector3  linear
    Vector3  angular
    
    ================================================================================
    MSG: control_msgs/Report
    Header header
    ReportControl control
    
    ReportControl vcu_torque_brake
    
    ReportMotion motion
    ReportBrake brake
    ReportThrottle throttle
    ReportWheel wheel
    ReportHMI manual
    ReportVehicleWorkMode vehicle_work_mode 
    
    ================================================================================
    MSG: control_msgs/ReportControl
    ControlSpeed Speed
    ControlSteer Steer
    ControlMode ordermode
    
    
    ================================================================================
    MSG: control_msgs/ControlSpeed
    Header header
    uint8 priority
    uint8 gear
    float64 speed
    float64 acc
    float64 torque
    float64 brake
    
    ================================================================================
    MSG: control_msgs/ControlSteer
    Header header
    uint8 priority
    float64 steer
    
    
    ================================================================================
    MSG: control_msgs/ControlMode
    Header header
    uint8 RainyLight
    
    
    
    ================================================================================
    MSG: control_msgs/ReportMotion
    uint8 drive_mode
    float64 steer
    uint8 gear
    float64 velocity
    
    
    
    ================================================================================
    MSG: control_msgs/ReportBrake
    float64 left_pressure_back
    float64 right_pressure_back
    uint8 auto_park_state
    uint8 auto_brake_enable
    uint8 system_hot_warn
    uint8 system_error_code
    float64 left_pressure_set
    float64 right_pressure_set
    float32 brake_pedal
    
    ================================================================================
    MSG: control_msgs/ReportThrottle
    float32 throttle_opening
    float32 throttle_pedal
    
    ================================================================================
    MSG: control_msgs/ReportWheel
    float32 front_left
    float32 front_right
    float32 rear_left
    float32 rear_right
    uint8 statusfl
    uint8 statusfr
    uint8 statusrl
    uint8 statusrr
    
    ================================================================================
    MSG: control_msgs/ReportHMI
    uint8 manual_estop
    uint8 is_human_brake 
    
    ================================================================================
    MSG: control_msgs/ReportVehicleWorkMode
    uint8 work_mode
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new observer(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.vehicle_state !== undefined) {
      resolved.vehicle_state = anm_msgs.msg.VehicleState.Resolve(msg.vehicle_state)
    }
    else {
      resolved.vehicle_state = new anm_msgs.msg.VehicleState()
    }

    if (msg.ecu_report !== undefined) {
      resolved.ecu_report = control_msgs.msg.Report.Resolve(msg.ecu_report)
    }
    else {
      resolved.ecu_report = new control_msgs.msg.Report()
    }

    if (msg.speed_cmd !== undefined) {
      resolved.speed_cmd = msg.speed_cmd;
    }
    else {
      resolved.speed_cmd = 0.0
    }

    if (msg.steer_cmd !== undefined) {
      resolved.steer_cmd = msg.steer_cmd;
    }
    else {
      resolved.steer_cmd = 0.0
    }

    if (msg.lateral_error !== undefined) {
      resolved.lateral_error = msg.lateral_error;
    }
    else {
      resolved.lateral_error = 0.0
    }

    if (msg.heading_error !== undefined) {
      resolved.heading_error = msg.heading_error;
    }
    else {
      resolved.heading_error = 0.0
    }

    if (msg.time_cost !== undefined) {
      resolved.time_cost = msg.time_cost;
    }
    else {
      resolved.time_cost = 0.0
    }

    return resolved;
    }
};

module.exports = observer;
