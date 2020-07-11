// Auto-generated. Do not edit!

// (in-package movobsplan_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class Movobspath {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.collision = null;
      this.penaltydepth = null;
      this.vel_to_dymicol = null;
      this.position = null;
    }
    else {
      if (initObj.hasOwnProperty('collision')) {
        this.collision = initObj.collision
      }
      else {
        this.collision = 0;
      }
      if (initObj.hasOwnProperty('penaltydepth')) {
        this.penaltydepth = initObj.penaltydepth
      }
      else {
        this.penaltydepth = 0.0;
      }
      if (initObj.hasOwnProperty('vel_to_dymicol')) {
        this.vel_to_dymicol = initObj.vel_to_dymicol
      }
      else {
        this.vel_to_dymicol = 0.0;
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = new geometry_msgs.msg.Point();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Movobspath
    // Serialize message field [collision]
    bufferOffset = _serializer.uint8(obj.collision, buffer, bufferOffset);
    // Serialize message field [penaltydepth]
    bufferOffset = _serializer.float64(obj.penaltydepth, buffer, bufferOffset);
    // Serialize message field [vel_to_dymicol]
    bufferOffset = _serializer.float64(obj.vel_to_dymicol, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.position, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Movobspath
    let len;
    let data = new Movobspath(null);
    // Deserialize message field [collision]
    data.collision = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [penaltydepth]
    data.penaltydepth = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [vel_to_dymicol]
    data.vel_to_dymicol = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 41;
  }

  static datatype() {
    // Returns string type for a message object
    return 'movobsplan_msgs/Movobspath';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b91e4c47ca79497da4d13234e1f837d6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 collision
    float64 penaltydepth
    float64 vel_to_dymicol
    geometry_msgs/Point position
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Movobspath(null);
    if (msg.collision !== undefined) {
      resolved.collision = msg.collision;
    }
    else {
      resolved.collision = 0
    }

    if (msg.penaltydepth !== undefined) {
      resolved.penaltydepth = msg.penaltydepth;
    }
    else {
      resolved.penaltydepth = 0.0
    }

    if (msg.vel_to_dymicol !== undefined) {
      resolved.vel_to_dymicol = msg.vel_to_dymicol;
    }
    else {
      resolved.vel_to_dymicol = 0.0
    }

    if (msg.position !== undefined) {
      resolved.position = geometry_msgs.msg.Point.Resolve(msg.position)
    }
    else {
      resolved.position = new geometry_msgs.msg.Point()
    }

    return resolved;
    }
};

module.exports = Movobspath;
