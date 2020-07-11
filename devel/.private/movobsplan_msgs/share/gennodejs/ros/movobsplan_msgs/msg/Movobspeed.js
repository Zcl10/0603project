// Auto-generated. Do not edit!

// (in-package movobsplan_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Movobspeed {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.collision = null;
      this.exp_vel = null;
      this.exp_time = null;
      this.vel_to_dymicol = null;
    }
    else {
      if (initObj.hasOwnProperty('collision')) {
        this.collision = initObj.collision
      }
      else {
        this.collision = 0;
      }
      if (initObj.hasOwnProperty('exp_vel')) {
        this.exp_vel = initObj.exp_vel
      }
      else {
        this.exp_vel = 0.0;
      }
      if (initObj.hasOwnProperty('exp_time')) {
        this.exp_time = initObj.exp_time
      }
      else {
        this.exp_time = 0.0;
      }
      if (initObj.hasOwnProperty('vel_to_dymicol')) {
        this.vel_to_dymicol = initObj.vel_to_dymicol
      }
      else {
        this.vel_to_dymicol = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Movobspeed
    // Serialize message field [collision]
    bufferOffset = _serializer.uint8(obj.collision, buffer, bufferOffset);
    // Serialize message field [exp_vel]
    bufferOffset = _serializer.float64(obj.exp_vel, buffer, bufferOffset);
    // Serialize message field [exp_time]
    bufferOffset = _serializer.float64(obj.exp_time, buffer, bufferOffset);
    // Serialize message field [vel_to_dymicol]
    bufferOffset = _serializer.float64(obj.vel_to_dymicol, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Movobspeed
    let len;
    let data = new Movobspeed(null);
    // Deserialize message field [collision]
    data.collision = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [exp_vel]
    data.exp_vel = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [exp_time]
    data.exp_time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [vel_to_dymicol]
    data.vel_to_dymicol = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 25;
  }

  static datatype() {
    // Returns string type for a message object
    return 'movobsplan_msgs/Movobspeed';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5e108d72b562baf3de0c61211ba4f831';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 collision
    float64 exp_vel
    float64 exp_time
    float64 vel_to_dymicol
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Movobspeed(null);
    if (msg.collision !== undefined) {
      resolved.collision = msg.collision;
    }
    else {
      resolved.collision = 0
    }

    if (msg.exp_vel !== undefined) {
      resolved.exp_vel = msg.exp_vel;
    }
    else {
      resolved.exp_vel = 0.0
    }

    if (msg.exp_time !== undefined) {
      resolved.exp_time = msg.exp_time;
    }
    else {
      resolved.exp_time = 0.0
    }

    if (msg.vel_to_dymicol !== undefined) {
      resolved.vel_to_dymicol = msg.vel_to_dymicol;
    }
    else {
      resolved.vel_to_dymicol = 0.0
    }

    return resolved;
    }
};

module.exports = Movobspeed;
