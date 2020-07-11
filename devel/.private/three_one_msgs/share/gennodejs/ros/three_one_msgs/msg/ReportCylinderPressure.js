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

class ReportCylinderPressure {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.left_one = null;
      this.left_two = null;
      this.left_three = null;
      this.left_four = null;
      this.right_one = null;
      this.right_two = null;
      this.right_three = null;
      this.right_four = null;
    }
    else {
      if (initObj.hasOwnProperty('left_one')) {
        this.left_one = initObj.left_one
      }
      else {
        this.left_one = 0;
      }
      if (initObj.hasOwnProperty('left_two')) {
        this.left_two = initObj.left_two
      }
      else {
        this.left_two = 0;
      }
      if (initObj.hasOwnProperty('left_three')) {
        this.left_three = initObj.left_three
      }
      else {
        this.left_three = 0;
      }
      if (initObj.hasOwnProperty('left_four')) {
        this.left_four = initObj.left_four
      }
      else {
        this.left_four = 0;
      }
      if (initObj.hasOwnProperty('right_one')) {
        this.right_one = initObj.right_one
      }
      else {
        this.right_one = 0;
      }
      if (initObj.hasOwnProperty('right_two')) {
        this.right_two = initObj.right_two
      }
      else {
        this.right_two = 0;
      }
      if (initObj.hasOwnProperty('right_three')) {
        this.right_three = initObj.right_three
      }
      else {
        this.right_three = 0;
      }
      if (initObj.hasOwnProperty('right_four')) {
        this.right_four = initObj.right_four
      }
      else {
        this.right_four = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReportCylinderPressure
    // Serialize message field [left_one]
    bufferOffset = _serializer.uint8(obj.left_one, buffer, bufferOffset);
    // Serialize message field [left_two]
    bufferOffset = _serializer.uint8(obj.left_two, buffer, bufferOffset);
    // Serialize message field [left_three]
    bufferOffset = _serializer.uint8(obj.left_three, buffer, bufferOffset);
    // Serialize message field [left_four]
    bufferOffset = _serializer.uint8(obj.left_four, buffer, bufferOffset);
    // Serialize message field [right_one]
    bufferOffset = _serializer.uint8(obj.right_one, buffer, bufferOffset);
    // Serialize message field [right_two]
    bufferOffset = _serializer.uint8(obj.right_two, buffer, bufferOffset);
    // Serialize message field [right_three]
    bufferOffset = _serializer.uint8(obj.right_three, buffer, bufferOffset);
    // Serialize message field [right_four]
    bufferOffset = _serializer.uint8(obj.right_four, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReportCylinderPressure
    let len;
    let data = new ReportCylinderPressure(null);
    // Deserialize message field [left_one]
    data.left_one = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [left_two]
    data.left_two = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [left_three]
    data.left_three = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [left_four]
    data.left_four = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [right_one]
    data.right_one = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [right_two]
    data.right_two = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [right_three]
    data.right_three = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [right_four]
    data.right_four = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'three_one_msgs/ReportCylinderPressure';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e261355aeec2b4d716939018ae20229e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 left_one
    uint8 left_two
    uint8 left_three
    uint8 left_four
    uint8 right_one
    uint8 right_two
    uint8 right_three
    uint8 right_four
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReportCylinderPressure(null);
    if (msg.left_one !== undefined) {
      resolved.left_one = msg.left_one;
    }
    else {
      resolved.left_one = 0
    }

    if (msg.left_two !== undefined) {
      resolved.left_two = msg.left_two;
    }
    else {
      resolved.left_two = 0
    }

    if (msg.left_three !== undefined) {
      resolved.left_three = msg.left_three;
    }
    else {
      resolved.left_three = 0
    }

    if (msg.left_four !== undefined) {
      resolved.left_four = msg.left_four;
    }
    else {
      resolved.left_four = 0
    }

    if (msg.right_one !== undefined) {
      resolved.right_one = msg.right_one;
    }
    else {
      resolved.right_one = 0
    }

    if (msg.right_two !== undefined) {
      resolved.right_two = msg.right_two;
    }
    else {
      resolved.right_two = 0
    }

    if (msg.right_three !== undefined) {
      resolved.right_three = msg.right_three;
    }
    else {
      resolved.right_three = 0
    }

    if (msg.right_four !== undefined) {
      resolved.right_four = msg.right_four;
    }
    else {
      resolved.right_four = 0
    }

    return resolved;
    }
};

module.exports = ReportCylinderPressure;
