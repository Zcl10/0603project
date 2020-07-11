// Auto-generated. Do not edit!

// (in-package control_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ReportControl = require('./ReportControl.js');
let ReportMotion = require('./ReportMotion.js');
let ReportBrake = require('./ReportBrake.js');
let ReportThrottle = require('./ReportThrottle.js');
let ReportWheel = require('./ReportWheel.js');
let ReportHMI = require('./ReportHMI.js');
let ReportVehicleWorkMode = require('./ReportVehicleWorkMode.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Report {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.control = null;
      this.vcu_torque_brake = null;
      this.motion = null;
      this.brake = null;
      this.throttle = null;
      this.wheel = null;
      this.manual = null;
      this.vehicle_work_mode = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('control')) {
        this.control = initObj.control
      }
      else {
        this.control = new ReportControl();
      }
      if (initObj.hasOwnProperty('vcu_torque_brake')) {
        this.vcu_torque_brake = initObj.vcu_torque_brake
      }
      else {
        this.vcu_torque_brake = new ReportControl();
      }
      if (initObj.hasOwnProperty('motion')) {
        this.motion = initObj.motion
      }
      else {
        this.motion = new ReportMotion();
      }
      if (initObj.hasOwnProperty('brake')) {
        this.brake = initObj.brake
      }
      else {
        this.brake = new ReportBrake();
      }
      if (initObj.hasOwnProperty('throttle')) {
        this.throttle = initObj.throttle
      }
      else {
        this.throttle = new ReportThrottle();
      }
      if (initObj.hasOwnProperty('wheel')) {
        this.wheel = initObj.wheel
      }
      else {
        this.wheel = new ReportWheel();
      }
      if (initObj.hasOwnProperty('manual')) {
        this.manual = initObj.manual
      }
      else {
        this.manual = new ReportHMI();
      }
      if (initObj.hasOwnProperty('vehicle_work_mode')) {
        this.vehicle_work_mode = initObj.vehicle_work_mode
      }
      else {
        this.vehicle_work_mode = new ReportVehicleWorkMode();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Report
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [control]
    bufferOffset = ReportControl.serialize(obj.control, buffer, bufferOffset);
    // Serialize message field [vcu_torque_brake]
    bufferOffset = ReportControl.serialize(obj.vcu_torque_brake, buffer, bufferOffset);
    // Serialize message field [motion]
    bufferOffset = ReportMotion.serialize(obj.motion, buffer, bufferOffset);
    // Serialize message field [brake]
    bufferOffset = ReportBrake.serialize(obj.brake, buffer, bufferOffset);
    // Serialize message field [throttle]
    bufferOffset = ReportThrottle.serialize(obj.throttle, buffer, bufferOffset);
    // Serialize message field [wheel]
    bufferOffset = ReportWheel.serialize(obj.wheel, buffer, bufferOffset);
    // Serialize message field [manual]
    bufferOffset = ReportHMI.serialize(obj.manual, buffer, bufferOffset);
    // Serialize message field [vehicle_work_mode]
    bufferOffset = ReportVehicleWorkMode.serialize(obj.vehicle_work_mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Report
    let len;
    let data = new Report(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [control]
    data.control = ReportControl.deserialize(buffer, bufferOffset);
    // Deserialize message field [vcu_torque_brake]
    data.vcu_torque_brake = ReportControl.deserialize(buffer, bufferOffset);
    // Deserialize message field [motion]
    data.motion = ReportMotion.deserialize(buffer, bufferOffset);
    // Deserialize message field [brake]
    data.brake = ReportBrake.deserialize(buffer, bufferOffset);
    // Deserialize message field [throttle]
    data.throttle = ReportThrottle.deserialize(buffer, bufferOffset);
    // Deserialize message field [wheel]
    data.wheel = ReportWheel.deserialize(buffer, bufferOffset);
    // Deserialize message field [manual]
    data.manual = ReportHMI.deserialize(buffer, bufferOffset);
    // Deserialize message field [vehicle_work_mode]
    data.vehicle_work_mode = ReportVehicleWorkMode.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += ReportControl.getMessageSize(object.control);
    length += ReportControl.getMessageSize(object.vcu_torque_brake);
    return length + 89;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control_msgs/Report';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0321a05248d872c4619e82c983a49c38';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new Report(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.control !== undefined) {
      resolved.control = ReportControl.Resolve(msg.control)
    }
    else {
      resolved.control = new ReportControl()
    }

    if (msg.vcu_torque_brake !== undefined) {
      resolved.vcu_torque_brake = ReportControl.Resolve(msg.vcu_torque_brake)
    }
    else {
      resolved.vcu_torque_brake = new ReportControl()
    }

    if (msg.motion !== undefined) {
      resolved.motion = ReportMotion.Resolve(msg.motion)
    }
    else {
      resolved.motion = new ReportMotion()
    }

    if (msg.brake !== undefined) {
      resolved.brake = ReportBrake.Resolve(msg.brake)
    }
    else {
      resolved.brake = new ReportBrake()
    }

    if (msg.throttle !== undefined) {
      resolved.throttle = ReportThrottle.Resolve(msg.throttle)
    }
    else {
      resolved.throttle = new ReportThrottle()
    }

    if (msg.wheel !== undefined) {
      resolved.wheel = ReportWheel.Resolve(msg.wheel)
    }
    else {
      resolved.wheel = new ReportWheel()
    }

    if (msg.manual !== undefined) {
      resolved.manual = ReportHMI.Resolve(msg.manual)
    }
    else {
      resolved.manual = new ReportHMI()
    }

    if (msg.vehicle_work_mode !== undefined) {
      resolved.vehicle_work_mode = ReportVehicleWorkMode.Resolve(msg.vehicle_work_mode)
    }
    else {
      resolved.vehicle_work_mode = new ReportVehicleWorkMode()
    }

    return resolved;
    }
};

module.exports = Report;
