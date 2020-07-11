// Auto-generated. Do not edit!

// (in-package three_one_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ControlSpeed = require('./ControlSpeed.js');
let ControlSteer = require('./ControlSteer.js');
let ControlSuspension = require('./ControlSuspension.js');
let ControlWeapon = require('./ControlWeapon.js');

//-----------------------------------------------------------

class Control {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.priority = null;
      this.speed = null;
      this.steer = null;
      this.suspension = null;
      this.weapon = null;
    }
    else {
      if (initObj.hasOwnProperty('priority')) {
        this.priority = initObj.priority
      }
      else {
        this.priority = 0;
      }
      if (initObj.hasOwnProperty('speed')) {
        this.speed = initObj.speed
      }
      else {
        this.speed = new ControlSpeed();
      }
      if (initObj.hasOwnProperty('steer')) {
        this.steer = initObj.steer
      }
      else {
        this.steer = new ControlSteer();
      }
      if (initObj.hasOwnProperty('suspension')) {
        this.suspension = initObj.suspension
      }
      else {
        this.suspension = new ControlSuspension();
      }
      if (initObj.hasOwnProperty('weapon')) {
        this.weapon = initObj.weapon
      }
      else {
        this.weapon = new ControlWeapon();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Control
    // Serialize message field [priority]
    bufferOffset = _serializer.uint8(obj.priority, buffer, bufferOffset);
    // Serialize message field [speed]
    bufferOffset = ControlSpeed.serialize(obj.speed, buffer, bufferOffset);
    // Serialize message field [steer]
    bufferOffset = ControlSteer.serialize(obj.steer, buffer, bufferOffset);
    // Serialize message field [suspension]
    bufferOffset = ControlSuspension.serialize(obj.suspension, buffer, bufferOffset);
    // Serialize message field [weapon]
    bufferOffset = ControlWeapon.serialize(obj.weapon, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Control
    let len;
    let data = new Control(null);
    // Deserialize message field [priority]
    data.priority = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [speed]
    data.speed = ControlSpeed.deserialize(buffer, bufferOffset);
    // Deserialize message field [steer]
    data.steer = ControlSteer.deserialize(buffer, bufferOffset);
    // Deserialize message field [suspension]
    data.suspension = ControlSuspension.deserialize(buffer, bufferOffset);
    // Deserialize message field [weapon]
    data.weapon = ControlWeapon.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 31;
  }

  static datatype() {
    // Returns string type for a message object
    return 'three_one_msgs/Control';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd0ddf03a8d19a85e773b681a9262d15c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 priority
    ControlSpeed speed
    ControlSteer steer
    ControlSuspension suspension
    ControlWeapon weapon
    ================================================================================
    MSG: three_one_msgs/ControlSpeed
    uint8 priority
    uint8 halt
    uint8 gear
    float32 speed
    ================================================================================
    MSG: three_one_msgs/ControlSteer
    uint8 priority
    float64 curvature
    ================================================================================
    MSG: three_one_msgs/ControlSuspension
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
    ================================================================================
    MSG: three_one_msgs/ControlWeapon
    uint8 priority
    uint8 weapon_330
    uint8 weapon_28
    uint8 weapon_cmd
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Control(null);
    if (msg.priority !== undefined) {
      resolved.priority = msg.priority;
    }
    else {
      resolved.priority = 0
    }

    if (msg.speed !== undefined) {
      resolved.speed = ControlSpeed.Resolve(msg.speed)
    }
    else {
      resolved.speed = new ControlSpeed()
    }

    if (msg.steer !== undefined) {
      resolved.steer = ControlSteer.Resolve(msg.steer)
    }
    else {
      resolved.steer = new ControlSteer()
    }

    if (msg.suspension !== undefined) {
      resolved.suspension = ControlSuspension.Resolve(msg.suspension)
    }
    else {
      resolved.suspension = new ControlSuspension()
    }

    if (msg.weapon !== undefined) {
      resolved.weapon = ControlWeapon.Resolve(msg.weapon)
    }
    else {
      resolved.weapon = new ControlWeapon()
    }

    return resolved;
    }
};

module.exports = Control;
