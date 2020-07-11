// Auto-generated. Do not edit!

// (in-package control_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ReportBrake {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.left_pressure_back = null;
      this.right_pressure_back = null;
      this.auto_park_state = null;
      this.auto_brake_enable = null;
      this.system_hot_warn = null;
      this.system_error_code = null;
      this.left_pressure_set = null;
      this.right_pressure_set = null;
      this.brake_pedal = null;
    }
    else {
      if (initObj.hasOwnProperty('left_pressure_back')) {
        this.left_pressure_back = initObj.left_pressure_back
      }
      else {
        this.left_pressure_back = 0.0;
      }
      if (initObj.hasOwnProperty('right_pressure_back')) {
        this.right_pressure_back = initObj.right_pressure_back
      }
      else {
        this.right_pressure_back = 0.0;
      }
      if (initObj.hasOwnProperty('auto_park_state')) {
        this.auto_park_state = initObj.auto_park_state
      }
      else {
        this.auto_park_state = 0;
      }
      if (initObj.hasOwnProperty('auto_brake_enable')) {
        this.auto_brake_enable = initObj.auto_brake_enable
      }
      else {
        this.auto_brake_enable = 0;
      }
      if (initObj.hasOwnProperty('system_hot_warn')) {
        this.system_hot_warn = initObj.system_hot_warn
      }
      else {
        this.system_hot_warn = 0;
      }
      if (initObj.hasOwnProperty('system_error_code')) {
        this.system_error_code = initObj.system_error_code
      }
      else {
        this.system_error_code = 0;
      }
      if (initObj.hasOwnProperty('left_pressure_set')) {
        this.left_pressure_set = initObj.left_pressure_set
      }
      else {
        this.left_pressure_set = 0.0;
      }
      if (initObj.hasOwnProperty('right_pressure_set')) {
        this.right_pressure_set = initObj.right_pressure_set
      }
      else {
        this.right_pressure_set = 0.0;
      }
      if (initObj.hasOwnProperty('brake_pedal')) {
        this.brake_pedal = initObj.brake_pedal
      }
      else {
        this.brake_pedal = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReportBrake
    // Serialize message field [left_pressure_back]
    bufferOffset = _serializer.float64(obj.left_pressure_back, buffer, bufferOffset);
    // Serialize message field [right_pressure_back]
    bufferOffset = _serializer.float64(obj.right_pressure_back, buffer, bufferOffset);
    // Serialize message field [auto_park_state]
    bufferOffset = _serializer.uint8(obj.auto_park_state, buffer, bufferOffset);
    // Serialize message field [auto_brake_enable]
    bufferOffset = _serializer.uint8(obj.auto_brake_enable, buffer, bufferOffset);
    // Serialize message field [system_hot_warn]
    bufferOffset = _serializer.uint8(obj.system_hot_warn, buffer, bufferOffset);
    // Serialize message field [system_error_code]
    bufferOffset = _serializer.uint8(obj.system_error_code, buffer, bufferOffset);
    // Serialize message field [left_pressure_set]
    bufferOffset = _serializer.float64(obj.left_pressure_set, buffer, bufferOffset);
    // Serialize message field [right_pressure_set]
    bufferOffset = _serializer.float64(obj.right_pressure_set, buffer, bufferOffset);
    // Serialize message field [brake_pedal]
    bufferOffset = _serializer.float32(obj.brake_pedal, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReportBrake
    let len;
    let data = new ReportBrake(null);
    // Deserialize message field [left_pressure_back]
    data.left_pressure_back = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_pressure_back]
    data.right_pressure_back = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [auto_park_state]
    data.auto_park_state = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [auto_brake_enable]
    data.auto_brake_enable = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [system_hot_warn]
    data.system_hot_warn = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [system_error_code]
    data.system_error_code = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [left_pressure_set]
    data.left_pressure_set = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_pressure_set]
    data.right_pressure_set = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [brake_pedal]
    data.brake_pedal = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control_msgs/ReportBrake';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c8b58fe12b43fe4b1c2d9a5950b7da37';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 left_pressure_back
    float64 right_pressure_back
    uint8 auto_park_state
    uint8 auto_brake_enable
    uint8 system_hot_warn
    uint8 system_error_code
    float64 left_pressure_set
    float64 right_pressure_set
    float32 brake_pedal
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReportBrake(null);
    if (msg.left_pressure_back !== undefined) {
      resolved.left_pressure_back = msg.left_pressure_back;
    }
    else {
      resolved.left_pressure_back = 0.0
    }

    if (msg.right_pressure_back !== undefined) {
      resolved.right_pressure_back = msg.right_pressure_back;
    }
    else {
      resolved.right_pressure_back = 0.0
    }

    if (msg.auto_park_state !== undefined) {
      resolved.auto_park_state = msg.auto_park_state;
    }
    else {
      resolved.auto_park_state = 0
    }

    if (msg.auto_brake_enable !== undefined) {
      resolved.auto_brake_enable = msg.auto_brake_enable;
    }
    else {
      resolved.auto_brake_enable = 0
    }

    if (msg.system_hot_warn !== undefined) {
      resolved.system_hot_warn = msg.system_hot_warn;
    }
    else {
      resolved.system_hot_warn = 0
    }

    if (msg.system_error_code !== undefined) {
      resolved.system_error_code = msg.system_error_code;
    }
    else {
      resolved.system_error_code = 0
    }

    if (msg.left_pressure_set !== undefined) {
      resolved.left_pressure_set = msg.left_pressure_set;
    }
    else {
      resolved.left_pressure_set = 0.0
    }

    if (msg.right_pressure_set !== undefined) {
      resolved.right_pressure_set = msg.right_pressure_set;
    }
    else {
      resolved.right_pressure_set = 0.0
    }

    if (msg.brake_pedal !== undefined) {
      resolved.brake_pedal = msg.brake_pedal;
    }
    else {
      resolved.brake_pedal = 0.0
    }

    return resolved;
    }
};

module.exports = ReportBrake;
