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

class ReportWheel {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.front_left = null;
      this.front_right = null;
      this.rear_left = null;
      this.rear_right = null;
      this.statusfl = null;
      this.statusfr = null;
      this.statusrl = null;
      this.statusrr = null;
    }
    else {
      if (initObj.hasOwnProperty('front_left')) {
        this.front_left = initObj.front_left
      }
      else {
        this.front_left = 0.0;
      }
      if (initObj.hasOwnProperty('front_right')) {
        this.front_right = initObj.front_right
      }
      else {
        this.front_right = 0.0;
      }
      if (initObj.hasOwnProperty('rear_left')) {
        this.rear_left = initObj.rear_left
      }
      else {
        this.rear_left = 0.0;
      }
      if (initObj.hasOwnProperty('rear_right')) {
        this.rear_right = initObj.rear_right
      }
      else {
        this.rear_right = 0.0;
      }
      if (initObj.hasOwnProperty('statusfl')) {
        this.statusfl = initObj.statusfl
      }
      else {
        this.statusfl = 0;
      }
      if (initObj.hasOwnProperty('statusfr')) {
        this.statusfr = initObj.statusfr
      }
      else {
        this.statusfr = 0;
      }
      if (initObj.hasOwnProperty('statusrl')) {
        this.statusrl = initObj.statusrl
      }
      else {
        this.statusrl = 0;
      }
      if (initObj.hasOwnProperty('statusrr')) {
        this.statusrr = initObj.statusrr
      }
      else {
        this.statusrr = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReportWheel
    // Serialize message field [front_left]
    bufferOffset = _serializer.float32(obj.front_left, buffer, bufferOffset);
    // Serialize message field [front_right]
    bufferOffset = _serializer.float32(obj.front_right, buffer, bufferOffset);
    // Serialize message field [rear_left]
    bufferOffset = _serializer.float32(obj.rear_left, buffer, bufferOffset);
    // Serialize message field [rear_right]
    bufferOffset = _serializer.float32(obj.rear_right, buffer, bufferOffset);
    // Serialize message field [statusfl]
    bufferOffset = _serializer.uint8(obj.statusfl, buffer, bufferOffset);
    // Serialize message field [statusfr]
    bufferOffset = _serializer.uint8(obj.statusfr, buffer, bufferOffset);
    // Serialize message field [statusrl]
    bufferOffset = _serializer.uint8(obj.statusrl, buffer, bufferOffset);
    // Serialize message field [statusrr]
    bufferOffset = _serializer.uint8(obj.statusrr, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReportWheel
    let len;
    let data = new ReportWheel(null);
    // Deserialize message field [front_left]
    data.front_left = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [front_right]
    data.front_right = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [rear_left]
    data.rear_left = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [rear_right]
    data.rear_right = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [statusfl]
    data.statusfl = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [statusfr]
    data.statusfr = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [statusrl]
    data.statusrl = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [statusrr]
    data.statusrr = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control_msgs/ReportWheel';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c3a44de250eee4620714d052b512e107';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 front_left
    float32 front_right
    float32 rear_left
    float32 rear_right
    uint8 statusfl
    uint8 statusfr
    uint8 statusrl
    uint8 statusrr
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReportWheel(null);
    if (msg.front_left !== undefined) {
      resolved.front_left = msg.front_left;
    }
    else {
      resolved.front_left = 0.0
    }

    if (msg.front_right !== undefined) {
      resolved.front_right = msg.front_right;
    }
    else {
      resolved.front_right = 0.0
    }

    if (msg.rear_left !== undefined) {
      resolved.rear_left = msg.rear_left;
    }
    else {
      resolved.rear_left = 0.0
    }

    if (msg.rear_right !== undefined) {
      resolved.rear_right = msg.rear_right;
    }
    else {
      resolved.rear_right = 0.0
    }

    if (msg.statusfl !== undefined) {
      resolved.statusfl = msg.statusfl;
    }
    else {
      resolved.statusfl = 0
    }

    if (msg.statusfr !== undefined) {
      resolved.statusfr = msg.statusfr;
    }
    else {
      resolved.statusfr = 0
    }

    if (msg.statusrl !== undefined) {
      resolved.statusrl = msg.statusrl;
    }
    else {
      resolved.statusrl = 0
    }

    if (msg.statusrr !== undefined) {
      resolved.statusrr = msg.statusrr;
    }
    else {
      resolved.statusrr = 0
    }

    return resolved;
    }
};

module.exports = ReportWheel;
