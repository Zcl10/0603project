// Auto-generated. Do not edit!

// (in-package three_one_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ReportDistance {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.mileage = null;
      this.left_pulse = null;
      this.right_pulse = null;
      this.left_distance = null;
      this.right_distance = null;
    }
    else {
      if (initObj.hasOwnProperty('mileage')) {
        this.mileage = initObj.mileage
      }
      else {
        this.mileage = 0;
      }
      if (initObj.hasOwnProperty('left_pulse')) {
        this.left_pulse = initObj.left_pulse
      }
      else {
        this.left_pulse = 0;
      }
      if (initObj.hasOwnProperty('right_pulse')) {
        this.right_pulse = initObj.right_pulse
      }
      else {
        this.right_pulse = 0;
      }
      if (initObj.hasOwnProperty('left_distance')) {
        this.left_distance = initObj.left_distance
      }
      else {
        this.left_distance = 0.0;
      }
      if (initObj.hasOwnProperty('right_distance')) {
        this.right_distance = initObj.right_distance
      }
      else {
        this.right_distance = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReportDistance
    // Serialize message field [mileage]
    bufferOffset = _serializer.uint32(obj.mileage, buffer, bufferOffset);
    // Serialize message field [left_pulse]
    bufferOffset = _serializer.uint32(obj.left_pulse, buffer, bufferOffset);
    // Serialize message field [right_pulse]
    bufferOffset = _serializer.uint32(obj.right_pulse, buffer, bufferOffset);
    // Serialize message field [left_distance]
    bufferOffset = _serializer.float64(obj.left_distance, buffer, bufferOffset);
    // Serialize message field [right_distance]
    bufferOffset = _serializer.float64(obj.right_distance, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReportDistance
    let len;
    let data = new ReportDistance(null);
    // Deserialize message field [mileage]
    data.mileage = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [left_pulse]
    data.left_pulse = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [right_pulse]
    data.right_pulse = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [left_distance]
    data.left_distance = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_distance]
    data.right_distance = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'three_one_msgs/ReportDistance';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '11d828c6b9eb85d8fbb317377ee4beba';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 mileage
    uint32 left_pulse
    uint32 right_pulse
    float64 left_distance
    float64 right_distance
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReportDistance(null);
    if (msg.mileage !== undefined) {
      resolved.mileage = msg.mileage;
    }
    else {
      resolved.mileage = 0
    }

    if (msg.left_pulse !== undefined) {
      resolved.left_pulse = msg.left_pulse;
    }
    else {
      resolved.left_pulse = 0
    }

    if (msg.right_pulse !== undefined) {
      resolved.right_pulse = msg.right_pulse;
    }
    else {
      resolved.right_pulse = 0
    }

    if (msg.left_distance !== undefined) {
      resolved.left_distance = msg.left_distance;
    }
    else {
      resolved.left_distance = 0.0
    }

    if (msg.right_distance !== undefined) {
      resolved.right_distance = msg.right_distance;
    }
    else {
      resolved.right_distance = 0.0
    }

    return resolved;
    }
};

module.exports = ReportDistance;
