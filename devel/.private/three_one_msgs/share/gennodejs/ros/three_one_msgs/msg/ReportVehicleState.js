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

class ReportVehicleState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.error_code = null;
      this.two_chamber_valve = null;
      this.vertical_wall_status = null;
      this.entrenchment = null;
      this.weapon_330 = null;
      this.weapon_28 = null;
      this.vehicle_height = null;
      this.tailgate_state = null;
      this.SOC = null;
      this.vehicle_roll = null;
      this.vehicle_pitch = null;
    }
    else {
      if (initObj.hasOwnProperty('error_code')) {
        this.error_code = initObj.error_code
      }
      else {
        this.error_code = 0;
      }
      if (initObj.hasOwnProperty('two_chamber_valve')) {
        this.two_chamber_valve = initObj.two_chamber_valve
      }
      else {
        this.two_chamber_valve = 0;
      }
      if (initObj.hasOwnProperty('vertical_wall_status')) {
        this.vertical_wall_status = initObj.vertical_wall_status
      }
      else {
        this.vertical_wall_status = 0;
      }
      if (initObj.hasOwnProperty('entrenchment')) {
        this.entrenchment = initObj.entrenchment
      }
      else {
        this.entrenchment = 0;
      }
      if (initObj.hasOwnProperty('weapon_330')) {
        this.weapon_330 = initObj.weapon_330
      }
      else {
        this.weapon_330 = 0;
      }
      if (initObj.hasOwnProperty('weapon_28')) {
        this.weapon_28 = initObj.weapon_28
      }
      else {
        this.weapon_28 = 0;
      }
      if (initObj.hasOwnProperty('vehicle_height')) {
        this.vehicle_height = initObj.vehicle_height
      }
      else {
        this.vehicle_height = 0;
      }
      if (initObj.hasOwnProperty('tailgate_state')) {
        this.tailgate_state = initObj.tailgate_state
      }
      else {
        this.tailgate_state = 0;
      }
      if (initObj.hasOwnProperty('SOC')) {
        this.SOC = initObj.SOC
      }
      else {
        this.SOC = 0;
      }
      if (initObj.hasOwnProperty('vehicle_roll')) {
        this.vehicle_roll = initObj.vehicle_roll
      }
      else {
        this.vehicle_roll = 0;
      }
      if (initObj.hasOwnProperty('vehicle_pitch')) {
        this.vehicle_pitch = initObj.vehicle_pitch
      }
      else {
        this.vehicle_pitch = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReportVehicleState
    // Serialize message field [error_code]
    bufferOffset = _serializer.uint8(obj.error_code, buffer, bufferOffset);
    // Serialize message field [two_chamber_valve]
    bufferOffset = _serializer.uint8(obj.two_chamber_valve, buffer, bufferOffset);
    // Serialize message field [vertical_wall_status]
    bufferOffset = _serializer.uint8(obj.vertical_wall_status, buffer, bufferOffset);
    // Serialize message field [entrenchment]
    bufferOffset = _serializer.uint8(obj.entrenchment, buffer, bufferOffset);
    // Serialize message field [weapon_330]
    bufferOffset = _serializer.uint8(obj.weapon_330, buffer, bufferOffset);
    // Serialize message field [weapon_28]
    bufferOffset = _serializer.uint8(obj.weapon_28, buffer, bufferOffset);
    // Serialize message field [vehicle_height]
    bufferOffset = _serializer.uint8(obj.vehicle_height, buffer, bufferOffset);
    // Serialize message field [tailgate_state]
    bufferOffset = _serializer.uint8(obj.tailgate_state, buffer, bufferOffset);
    // Serialize message field [SOC]
    bufferOffset = _serializer.uint8(obj.SOC, buffer, bufferOffset);
    // Serialize message field [vehicle_roll]
    bufferOffset = _serializer.int8(obj.vehicle_roll, buffer, bufferOffset);
    // Serialize message field [vehicle_pitch]
    bufferOffset = _serializer.int8(obj.vehicle_pitch, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReportVehicleState
    let len;
    let data = new ReportVehicleState(null);
    // Deserialize message field [error_code]
    data.error_code = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [two_chamber_valve]
    data.two_chamber_valve = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [vertical_wall_status]
    data.vertical_wall_status = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [entrenchment]
    data.entrenchment = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [weapon_330]
    data.weapon_330 = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [weapon_28]
    data.weapon_28 = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [vehicle_height]
    data.vehicle_height = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [tailgate_state]
    data.tailgate_state = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [SOC]
    data.SOC = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [vehicle_roll]
    data.vehicle_roll = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [vehicle_pitch]
    data.vehicle_pitch = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 11;
  }

  static datatype() {
    // Returns string type for a message object
    return 'three_one_msgs/ReportVehicleState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '038961e65ff3db9742a20c76bdc20ca1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 error_code
    uint8 two_chamber_valve
    uint8 vertical_wall_status
    uint8 entrenchment
    uint8 weapon_330
    uint8 weapon_28
    uint8 vehicle_height
    uint8 tailgate_state
    uint8 SOC
    int8 vehicle_roll
    int8 vehicle_pitch
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReportVehicleState(null);
    if (msg.error_code !== undefined) {
      resolved.error_code = msg.error_code;
    }
    else {
      resolved.error_code = 0
    }

    if (msg.two_chamber_valve !== undefined) {
      resolved.two_chamber_valve = msg.two_chamber_valve;
    }
    else {
      resolved.two_chamber_valve = 0
    }

    if (msg.vertical_wall_status !== undefined) {
      resolved.vertical_wall_status = msg.vertical_wall_status;
    }
    else {
      resolved.vertical_wall_status = 0
    }

    if (msg.entrenchment !== undefined) {
      resolved.entrenchment = msg.entrenchment;
    }
    else {
      resolved.entrenchment = 0
    }

    if (msg.weapon_330 !== undefined) {
      resolved.weapon_330 = msg.weapon_330;
    }
    else {
      resolved.weapon_330 = 0
    }

    if (msg.weapon_28 !== undefined) {
      resolved.weapon_28 = msg.weapon_28;
    }
    else {
      resolved.weapon_28 = 0
    }

    if (msg.vehicle_height !== undefined) {
      resolved.vehicle_height = msg.vehicle_height;
    }
    else {
      resolved.vehicle_height = 0
    }

    if (msg.tailgate_state !== undefined) {
      resolved.tailgate_state = msg.tailgate_state;
    }
    else {
      resolved.tailgate_state = 0
    }

    if (msg.SOC !== undefined) {
      resolved.SOC = msg.SOC;
    }
    else {
      resolved.SOC = 0
    }

    if (msg.vehicle_roll !== undefined) {
      resolved.vehicle_roll = msg.vehicle_roll;
    }
    else {
      resolved.vehicle_roll = 0
    }

    if (msg.vehicle_pitch !== undefined) {
      resolved.vehicle_pitch = msg.vehicle_pitch;
    }
    else {
      resolved.vehicle_pitch = 0
    }

    return resolved;
    }
};

module.exports = ReportVehicleState;
