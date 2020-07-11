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

class ReportHMI {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.manual_estop = null;
      this.is_human_brake = null;
    }
    else {
      if (initObj.hasOwnProperty('manual_estop')) {
        this.manual_estop = initObj.manual_estop
      }
      else {
        this.manual_estop = 0;
      }
      if (initObj.hasOwnProperty('is_human_brake')) {
        this.is_human_brake = initObj.is_human_brake
      }
      else {
        this.is_human_brake = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReportHMI
    // Serialize message field [manual_estop]
    bufferOffset = _serializer.uint8(obj.manual_estop, buffer, bufferOffset);
    // Serialize message field [is_human_brake]
    bufferOffset = _serializer.uint8(obj.is_human_brake, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReportHMI
    let len;
    let data = new ReportHMI(null);
    // Deserialize message field [manual_estop]
    data.manual_estop = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [is_human_brake]
    data.is_human_brake = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control_msgs/ReportHMI';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f19a467eddf6f2a1b5c81ed415355fbf';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 manual_estop
    uint8 is_human_brake 
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReportHMI(null);
    if (msg.manual_estop !== undefined) {
      resolved.manual_estop = msg.manual_estop;
    }
    else {
      resolved.manual_estop = 0
    }

    if (msg.is_human_brake !== undefined) {
      resolved.is_human_brake = msg.is_human_brake;
    }
    else {
      resolved.is_human_brake = 0
    }

    return resolved;
    }
};

module.exports = ReportHMI;
