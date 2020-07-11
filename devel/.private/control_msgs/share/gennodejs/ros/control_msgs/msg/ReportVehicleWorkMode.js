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

class ReportVehicleWorkMode {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.work_mode = null;
    }
    else {
      if (initObj.hasOwnProperty('work_mode')) {
        this.work_mode = initObj.work_mode
      }
      else {
        this.work_mode = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReportVehicleWorkMode
    // Serialize message field [work_mode]
    bufferOffset = _serializer.uint8(obj.work_mode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReportVehicleWorkMode
    let len;
    let data = new ReportVehicleWorkMode(null);
    // Deserialize message field [work_mode]
    data.work_mode = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a message object
    return 'control_msgs/ReportVehicleWorkMode';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fcfe851405844897c8730da81110283d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 work_mode
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReportVehicleWorkMode(null);
    if (msg.work_mode !== undefined) {
      resolved.work_mode = msg.work_mode;
    }
    else {
      resolved.work_mode = 0
    }

    return resolved;
    }
};

module.exports = ReportVehicleWorkMode;
