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

class Rawdata {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ros_time = null;
      this.data = null;
    }
    else {
      if (initObj.hasOwnProperty('ros_time')) {
        this.ros_time = initObj.ros_time
      }
      else {
        this.ros_time = 0.0;
      }
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Rawdata
    // Serialize message field [ros_time]
    bufferOffset = _serializer.float64(obj.ros_time, buffer, bufferOffset);
    // Serialize message field [data]
    bufferOffset = _arraySerializer.uint8(obj.data, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Rawdata
    let len;
    let data = new Rawdata(null);
    // Deserialize message field [ros_time]
    data.ros_time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.data.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control_msgs/Rawdata';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a34d701bf319ec12f678fa7cb20e57e3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 ros_time
    uint8[] data
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Rawdata(null);
    if (msg.ros_time !== undefined) {
      resolved.ros_time = msg.ros_time;
    }
    else {
      resolved.ros_time = 0.0
    }

    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = []
    }

    return resolved;
    }
};

module.exports = Rawdata;
