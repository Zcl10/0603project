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

class ReportThrottle {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.throttle_opening = null;
      this.throttle_pedal = null;
    }
    else {
      if (initObj.hasOwnProperty('throttle_opening')) {
        this.throttle_opening = initObj.throttle_opening
      }
      else {
        this.throttle_opening = 0.0;
      }
      if (initObj.hasOwnProperty('throttle_pedal')) {
        this.throttle_pedal = initObj.throttle_pedal
      }
      else {
        this.throttle_pedal = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReportThrottle
    // Serialize message field [throttle_opening]
    bufferOffset = _serializer.float32(obj.throttle_opening, buffer, bufferOffset);
    // Serialize message field [throttle_pedal]
    bufferOffset = _serializer.float32(obj.throttle_pedal, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReportThrottle
    let len;
    let data = new ReportThrottle(null);
    // Deserialize message field [throttle_opening]
    data.throttle_opening = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [throttle_pedal]
    data.throttle_pedal = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control_msgs/ReportThrottle';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3fec449e5f78595bef42751bd36df7c4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 throttle_opening
    float32 throttle_pedal
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReportThrottle(null);
    if (msg.throttle_opening !== undefined) {
      resolved.throttle_opening = msg.throttle_opening;
    }
    else {
      resolved.throttle_opening = 0.0
    }

    if (msg.throttle_pedal !== undefined) {
      resolved.throttle_pedal = msg.throttle_pedal;
    }
    else {
      resolved.throttle_pedal = 0.0
    }

    return resolved;
    }
};

module.exports = ReportThrottle;
