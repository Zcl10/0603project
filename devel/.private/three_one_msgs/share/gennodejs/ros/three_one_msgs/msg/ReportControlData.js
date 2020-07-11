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

class ReportControlData {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.curvature = null;
      this.speed = null;
      this.rpm = null;
      this.work_mode = null;
      this.gear = null;
      this.turn_to = null;
      this.brake = null;
      this.park = null;
      this.cylinder_select = null;
      this.suspension_select = null;
      this.vertical_wall_mode = null;
      this.suspension_work_mode = null;
      this.suspension_work_mode_detail = null;
      this.suspension_cylinder_select_mode = null;
      this.suspension_cylinder_motor_control = null;
      this.fix_two_chamber_valve = null;
    }
    else {
      if (initObj.hasOwnProperty('curvature')) {
        this.curvature = initObj.curvature
      }
      else {
        this.curvature = 0.0;
      }
      if (initObj.hasOwnProperty('speed')) {
        this.speed = initObj.speed
      }
      else {
        this.speed = 0.0;
      }
      if (initObj.hasOwnProperty('rpm')) {
        this.rpm = initObj.rpm
      }
      else {
        this.rpm = 0;
      }
      if (initObj.hasOwnProperty('work_mode')) {
        this.work_mode = initObj.work_mode
      }
      else {
        this.work_mode = 0;
      }
      if (initObj.hasOwnProperty('gear')) {
        this.gear = initObj.gear
      }
      else {
        this.gear = 0;
      }
      if (initObj.hasOwnProperty('turn_to')) {
        this.turn_to = initObj.turn_to
      }
      else {
        this.turn_to = 0;
      }
      if (initObj.hasOwnProperty('brake')) {
        this.brake = initObj.brake
      }
      else {
        this.brake = 0;
      }
      if (initObj.hasOwnProperty('park')) {
        this.park = initObj.park
      }
      else {
        this.park = 0;
      }
      if (initObj.hasOwnProperty('cylinder_select')) {
        this.cylinder_select = initObj.cylinder_select
      }
      else {
        this.cylinder_select = 0;
      }
      if (initObj.hasOwnProperty('suspension_select')) {
        this.suspension_select = initObj.suspension_select
      }
      else {
        this.suspension_select = 0;
      }
      if (initObj.hasOwnProperty('vertical_wall_mode')) {
        this.vertical_wall_mode = initObj.vertical_wall_mode
      }
      else {
        this.vertical_wall_mode = 0;
      }
      if (initObj.hasOwnProperty('suspension_work_mode')) {
        this.suspension_work_mode = initObj.suspension_work_mode
      }
      else {
        this.suspension_work_mode = 0;
      }
      if (initObj.hasOwnProperty('suspension_work_mode_detail')) {
        this.suspension_work_mode_detail = initObj.suspension_work_mode_detail
      }
      else {
        this.suspension_work_mode_detail = 0;
      }
      if (initObj.hasOwnProperty('suspension_cylinder_select_mode')) {
        this.suspension_cylinder_select_mode = initObj.suspension_cylinder_select_mode
      }
      else {
        this.suspension_cylinder_select_mode = 0;
      }
      if (initObj.hasOwnProperty('suspension_cylinder_motor_control')) {
        this.suspension_cylinder_motor_control = initObj.suspension_cylinder_motor_control
      }
      else {
        this.suspension_cylinder_motor_control = 0;
      }
      if (initObj.hasOwnProperty('fix_two_chamber_valve')) {
        this.fix_two_chamber_valve = initObj.fix_two_chamber_valve
      }
      else {
        this.fix_two_chamber_valve = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReportControlData
    // Serialize message field [curvature]
    bufferOffset = _serializer.float32(obj.curvature, buffer, bufferOffset);
    // Serialize message field [speed]
    bufferOffset = _serializer.float32(obj.speed, buffer, bufferOffset);
    // Serialize message field [rpm]
    bufferOffset = _serializer.uint16(obj.rpm, buffer, bufferOffset);
    // Serialize message field [work_mode]
    bufferOffset = _serializer.uint8(obj.work_mode, buffer, bufferOffset);
    // Serialize message field [gear]
    bufferOffset = _serializer.uint8(obj.gear, buffer, bufferOffset);
    // Serialize message field [turn_to]
    bufferOffset = _serializer.uint8(obj.turn_to, buffer, bufferOffset);
    // Serialize message field [brake]
    bufferOffset = _serializer.uint8(obj.brake, buffer, bufferOffset);
    // Serialize message field [park]
    bufferOffset = _serializer.uint8(obj.park, buffer, bufferOffset);
    // Serialize message field [cylinder_select]
    bufferOffset = _serializer.uint8(obj.cylinder_select, buffer, bufferOffset);
    // Serialize message field [suspension_select]
    bufferOffset = _serializer.uint8(obj.suspension_select, buffer, bufferOffset);
    // Serialize message field [vertical_wall_mode]
    bufferOffset = _serializer.uint8(obj.vertical_wall_mode, buffer, bufferOffset);
    // Serialize message field [suspension_work_mode]
    bufferOffset = _serializer.uint8(obj.suspension_work_mode, buffer, bufferOffset);
    // Serialize message field [suspension_work_mode_detail]
    bufferOffset = _serializer.uint8(obj.suspension_work_mode_detail, buffer, bufferOffset);
    // Serialize message field [suspension_cylinder_select_mode]
    bufferOffset = _serializer.uint8(obj.suspension_cylinder_select_mode, buffer, bufferOffset);
    // Serialize message field [suspension_cylinder_motor_control]
    bufferOffset = _serializer.uint8(obj.suspension_cylinder_motor_control, buffer, bufferOffset);
    // Serialize message field [fix_two_chamber_valve]
    bufferOffset = _serializer.uint8(obj.fix_two_chamber_valve, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReportControlData
    let len;
    let data = new ReportControlData(null);
    // Deserialize message field [curvature]
    data.curvature = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [speed]
    data.speed = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [rpm]
    data.rpm = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [work_mode]
    data.work_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [gear]
    data.gear = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [turn_to]
    data.turn_to = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [brake]
    data.brake = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [park]
    data.park = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [cylinder_select]
    data.cylinder_select = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [suspension_select]
    data.suspension_select = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [vertical_wall_mode]
    data.vertical_wall_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [suspension_work_mode]
    data.suspension_work_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [suspension_work_mode_detail]
    data.suspension_work_mode_detail = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [suspension_cylinder_select_mode]
    data.suspension_cylinder_select_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [suspension_cylinder_motor_control]
    data.suspension_cylinder_motor_control = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [fix_two_chamber_valve]
    data.fix_two_chamber_valve = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 23;
  }

  static datatype() {
    // Returns string type for a message object
    return 'three_one_msgs/ReportControlData';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a6b97385db9e76f4dfa530144bb3765f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 curvature
    float32 speed
    uint16 rpm
    uint8 work_mode
    uint8 gear
    uint8 turn_to
    uint8 brake
    uint8 park
    uint8 cylinder_select
    uint8 suspension_select
    uint8 vertical_wall_mode
    uint8 suspension_work_mode
    uint8 suspension_work_mode_detail
    uint8 suspension_cylinder_select_mode
    uint8 suspension_cylinder_motor_control
    uint8 fix_two_chamber_valve
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReportControlData(null);
    if (msg.curvature !== undefined) {
      resolved.curvature = msg.curvature;
    }
    else {
      resolved.curvature = 0.0
    }

    if (msg.speed !== undefined) {
      resolved.speed = msg.speed;
    }
    else {
      resolved.speed = 0.0
    }

    if (msg.rpm !== undefined) {
      resolved.rpm = msg.rpm;
    }
    else {
      resolved.rpm = 0
    }

    if (msg.work_mode !== undefined) {
      resolved.work_mode = msg.work_mode;
    }
    else {
      resolved.work_mode = 0
    }

    if (msg.gear !== undefined) {
      resolved.gear = msg.gear;
    }
    else {
      resolved.gear = 0
    }

    if (msg.turn_to !== undefined) {
      resolved.turn_to = msg.turn_to;
    }
    else {
      resolved.turn_to = 0
    }

    if (msg.brake !== undefined) {
      resolved.brake = msg.brake;
    }
    else {
      resolved.brake = 0
    }

    if (msg.park !== undefined) {
      resolved.park = msg.park;
    }
    else {
      resolved.park = 0
    }

    if (msg.cylinder_select !== undefined) {
      resolved.cylinder_select = msg.cylinder_select;
    }
    else {
      resolved.cylinder_select = 0
    }

    if (msg.suspension_select !== undefined) {
      resolved.suspension_select = msg.suspension_select;
    }
    else {
      resolved.suspension_select = 0
    }

    if (msg.vertical_wall_mode !== undefined) {
      resolved.vertical_wall_mode = msg.vertical_wall_mode;
    }
    else {
      resolved.vertical_wall_mode = 0
    }

    if (msg.suspension_work_mode !== undefined) {
      resolved.suspension_work_mode = msg.suspension_work_mode;
    }
    else {
      resolved.suspension_work_mode = 0
    }

    if (msg.suspension_work_mode_detail !== undefined) {
      resolved.suspension_work_mode_detail = msg.suspension_work_mode_detail;
    }
    else {
      resolved.suspension_work_mode_detail = 0
    }

    if (msg.suspension_cylinder_select_mode !== undefined) {
      resolved.suspension_cylinder_select_mode = msg.suspension_cylinder_select_mode;
    }
    else {
      resolved.suspension_cylinder_select_mode = 0
    }

    if (msg.suspension_cylinder_motor_control !== undefined) {
      resolved.suspension_cylinder_motor_control = msg.suspension_cylinder_motor_control;
    }
    else {
      resolved.suspension_cylinder_motor_control = 0
    }

    if (msg.fix_two_chamber_valve !== undefined) {
      resolved.fix_two_chamber_valve = msg.fix_two_chamber_valve;
    }
    else {
      resolved.fix_two_chamber_valve = 0
    }

    return resolved;
    }
};

module.exports = ReportControlData;
