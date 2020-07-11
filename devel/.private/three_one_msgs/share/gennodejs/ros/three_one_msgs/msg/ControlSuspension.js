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

class ControlSuspension {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.priority = null;
      this.cylinder_select = null;
      this.suspension_select = null;
      this.suspension_work_mode = null;
      this.suspension_work_mode_detail = null;
      this.suspension_cylinder_select_mode = null;
      this.suspension_cylinder_motor_control = null;
      this.vertical_wall_mode = null;
      this.fix_two_chamber_valve = null;
      this.entrenchment = null;
    }
    else {
      if (initObj.hasOwnProperty('priority')) {
        this.priority = initObj.priority
      }
      else {
        this.priority = 0;
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
      if (initObj.hasOwnProperty('vertical_wall_mode')) {
        this.vertical_wall_mode = initObj.vertical_wall_mode
      }
      else {
        this.vertical_wall_mode = 0;
      }
      if (initObj.hasOwnProperty('fix_two_chamber_valve')) {
        this.fix_two_chamber_valve = initObj.fix_two_chamber_valve
      }
      else {
        this.fix_two_chamber_valve = 0;
      }
      if (initObj.hasOwnProperty('entrenchment')) {
        this.entrenchment = initObj.entrenchment
      }
      else {
        this.entrenchment = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ControlSuspension
    // Serialize message field [priority]
    bufferOffset = _serializer.uint8(obj.priority, buffer, bufferOffset);
    // Serialize message field [cylinder_select]
    bufferOffset = _serializer.uint8(obj.cylinder_select, buffer, bufferOffset);
    // Serialize message field [suspension_select]
    bufferOffset = _serializer.uint8(obj.suspension_select, buffer, bufferOffset);
    // Serialize message field [suspension_work_mode]
    bufferOffset = _serializer.uint8(obj.suspension_work_mode, buffer, bufferOffset);
    // Serialize message field [suspension_work_mode_detail]
    bufferOffset = _serializer.uint8(obj.suspension_work_mode_detail, buffer, bufferOffset);
    // Serialize message field [suspension_cylinder_select_mode]
    bufferOffset = _serializer.uint8(obj.suspension_cylinder_select_mode, buffer, bufferOffset);
    // Serialize message field [suspension_cylinder_motor_control]
    bufferOffset = _serializer.uint8(obj.suspension_cylinder_motor_control, buffer, bufferOffset);
    // Serialize message field [vertical_wall_mode]
    bufferOffset = _serializer.uint8(obj.vertical_wall_mode, buffer, bufferOffset);
    // Serialize message field [fix_two_chamber_valve]
    bufferOffset = _serializer.uint8(obj.fix_two_chamber_valve, buffer, bufferOffset);
    // Serialize message field [entrenchment]
    bufferOffset = _serializer.uint8(obj.entrenchment, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ControlSuspension
    let len;
    let data = new ControlSuspension(null);
    // Deserialize message field [priority]
    data.priority = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [cylinder_select]
    data.cylinder_select = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [suspension_select]
    data.suspension_select = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [suspension_work_mode]
    data.suspension_work_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [suspension_work_mode_detail]
    data.suspension_work_mode_detail = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [suspension_cylinder_select_mode]
    data.suspension_cylinder_select_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [suspension_cylinder_motor_control]
    data.suspension_cylinder_motor_control = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [vertical_wall_mode]
    data.vertical_wall_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [fix_two_chamber_valve]
    data.fix_two_chamber_valve = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [entrenchment]
    data.entrenchment = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 10;
  }

  static datatype() {
    // Returns string type for a message object
    return 'three_one_msgs/ControlSuspension';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4bc4d758b88c322981bcdaff503bd5e7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 priority
    uint8 cylinder_select
    uint8 suspension_select
    uint8 suspension_work_mode
    uint8 suspension_work_mode_detail
    uint8 suspension_cylinder_select_mode
    uint8 suspension_cylinder_motor_control
    uint8 vertical_wall_mode
    uint8 fix_two_chamber_valve
    uint8 entrenchment
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ControlSuspension(null);
    if (msg.priority !== undefined) {
      resolved.priority = msg.priority;
    }
    else {
      resolved.priority = 0
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

    if (msg.vertical_wall_mode !== undefined) {
      resolved.vertical_wall_mode = msg.vertical_wall_mode;
    }
    else {
      resolved.vertical_wall_mode = 0
    }

    if (msg.fix_two_chamber_valve !== undefined) {
      resolved.fix_two_chamber_valve = msg.fix_two_chamber_valve;
    }
    else {
      resolved.fix_two_chamber_valve = 0
    }

    if (msg.entrenchment !== undefined) {
      resolved.entrenchment = msg.entrenchment;
    }
    else {
      resolved.entrenchment = 0
    }

    return resolved;
    }
};

module.exports = ControlSuspension;
