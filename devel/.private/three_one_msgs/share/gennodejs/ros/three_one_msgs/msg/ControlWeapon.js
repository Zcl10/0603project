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

class ControlWeapon {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.priority = null;
      this.weapon_330 = null;
      this.weapon_28 = null;
      this.weapon_cmd = null;
    }
    else {
      if (initObj.hasOwnProperty('priority')) {
        this.priority = initObj.priority
      }
      else {
        this.priority = 0;
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
      if (initObj.hasOwnProperty('weapon_cmd')) {
        this.weapon_cmd = initObj.weapon_cmd
      }
      else {
        this.weapon_cmd = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ControlWeapon
    // Serialize message field [priority]
    bufferOffset = _serializer.uint8(obj.priority, buffer, bufferOffset);
    // Serialize message field [weapon_330]
    bufferOffset = _serializer.uint8(obj.weapon_330, buffer, bufferOffset);
    // Serialize message field [weapon_28]
    bufferOffset = _serializer.uint8(obj.weapon_28, buffer, bufferOffset);
    // Serialize message field [weapon_cmd]
    bufferOffset = _serializer.uint8(obj.weapon_cmd, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ControlWeapon
    let len;
    let data = new ControlWeapon(null);
    // Deserialize message field [priority]
    data.priority = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [weapon_330]
    data.weapon_330 = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [weapon_28]
    data.weapon_28 = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [weapon_cmd]
    data.weapon_cmd = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'three_one_msgs/ControlWeapon';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4cc1e4ec0b5615d8df21778e6fab18ae';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new ControlWeapon(null);
    if (msg.priority !== undefined) {
      resolved.priority = msg.priority;
    }
    else {
      resolved.priority = 0
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

    if (msg.weapon_cmd !== undefined) {
      resolved.weapon_cmd = msg.weapon_cmd;
    }
    else {
      resolved.weapon_cmd = 0
    }

    return resolved;
    }
};

module.exports = ControlWeapon;
