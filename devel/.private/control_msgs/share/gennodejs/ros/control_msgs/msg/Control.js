// Auto-generated. Do not edit!

// (in-package control_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ControlSpeed = require('./ControlSpeed.js');
let ControlSteer = require('./ControlSteer.js');
let ControlMode = require('./ControlMode.js');

//-----------------------------------------------------------

class Control {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Speed = null;
      this.Steer = null;
      this.ordermode = null;
    }
    else {
      if (initObj.hasOwnProperty('Speed')) {
        this.Speed = initObj.Speed
      }
      else {
        this.Speed = new ControlSpeed();
      }
      if (initObj.hasOwnProperty('Steer')) {
        this.Steer = initObj.Steer
      }
      else {
        this.Steer = new ControlSteer();
      }
      if (initObj.hasOwnProperty('ordermode')) {
        this.ordermode = initObj.ordermode
      }
      else {
        this.ordermode = new ControlMode();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Control
    // Serialize message field [Speed]
    bufferOffset = ControlSpeed.serialize(obj.Speed, buffer, bufferOffset);
    // Serialize message field [Steer]
    bufferOffset = ControlSteer.serialize(obj.Steer, buffer, bufferOffset);
    // Serialize message field [ordermode]
    bufferOffset = ControlMode.serialize(obj.ordermode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Control
    let len;
    let data = new Control(null);
    // Deserialize message field [Speed]
    data.Speed = ControlSpeed.deserialize(buffer, bufferOffset);
    // Deserialize message field [Steer]
    data.Steer = ControlSteer.deserialize(buffer, bufferOffset);
    // Deserialize message field [ordermode]
    data.ordermode = ControlMode.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += ControlSpeed.getMessageSize(object.Speed);
    length += ControlSteer.getMessageSize(object.Steer);
    length += ControlMode.getMessageSize(object.ordermode);
    return length;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control_msgs/Control';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4cfa3145374ffabe5a1139ad8f40e485';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    MSG: control_msgs/ControlSteer
    Header header
    uint8 priority
    float64 steer
    
    
    ================================================================================
    MSG: control_msgs/ControlMode
    Header header
    uint8 RainyLight
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Control(null);
    if (msg.Speed !== undefined) {
      resolved.Speed = ControlSpeed.Resolve(msg.Speed)
    }
    else {
      resolved.Speed = new ControlSpeed()
    }

    if (msg.Steer !== undefined) {
      resolved.Steer = ControlSteer.Resolve(msg.Steer)
    }
    else {
      resolved.Steer = new ControlSteer()
    }

    if (msg.ordermode !== undefined) {
      resolved.ordermode = ControlMode.Resolve(msg.ordermode)
    }
    else {
      resolved.ordermode = new ControlMode()
    }

    return resolved;
    }
};

module.exports = Control;
