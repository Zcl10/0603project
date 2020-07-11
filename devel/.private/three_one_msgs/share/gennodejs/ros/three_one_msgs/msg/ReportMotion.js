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

class ReportMotion {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.spin = null;
      this.park = null;
      this.current_gear = null;
      this.left_wheel_rotate = null;
      this.right_wheel_rotate = null;
      this.left_motor_rpm = null;
      this.right_motor_rpm = null;
      this.mechanical_brake = null;
      this.vehicle_speed = null;
      this.left_wheel_speed = null;
      this.right_wheel_speed = null;
      this.curvature = null;
    }
    else {
      if (initObj.hasOwnProperty('spin')) {
        this.spin = initObj.spin
      }
      else {
        this.spin = 0;
      }
      if (initObj.hasOwnProperty('park')) {
        this.park = initObj.park
      }
      else {
        this.park = 0;
      }
      if (initObj.hasOwnProperty('current_gear')) {
        this.current_gear = initObj.current_gear
      }
      else {
        this.current_gear = 0;
      }
      if (initObj.hasOwnProperty('left_wheel_rotate')) {
        this.left_wheel_rotate = initObj.left_wheel_rotate
      }
      else {
        this.left_wheel_rotate = 0;
      }
      if (initObj.hasOwnProperty('right_wheel_rotate')) {
        this.right_wheel_rotate = initObj.right_wheel_rotate
      }
      else {
        this.right_wheel_rotate = 0;
      }
      if (initObj.hasOwnProperty('left_motor_rpm')) {
        this.left_motor_rpm = initObj.left_motor_rpm
      }
      else {
        this.left_motor_rpm = 0;
      }
      if (initObj.hasOwnProperty('right_motor_rpm')) {
        this.right_motor_rpm = initObj.right_motor_rpm
      }
      else {
        this.right_motor_rpm = 0;
      }
      if (initObj.hasOwnProperty('mechanical_brake')) {
        this.mechanical_brake = initObj.mechanical_brake
      }
      else {
        this.mechanical_brake = 0.0;
      }
      if (initObj.hasOwnProperty('vehicle_speed')) {
        this.vehicle_speed = initObj.vehicle_speed
      }
      else {
        this.vehicle_speed = 0.0;
      }
      if (initObj.hasOwnProperty('left_wheel_speed')) {
        this.left_wheel_speed = initObj.left_wheel_speed
      }
      else {
        this.left_wheel_speed = 0.0;
      }
      if (initObj.hasOwnProperty('right_wheel_speed')) {
        this.right_wheel_speed = initObj.right_wheel_speed
      }
      else {
        this.right_wheel_speed = 0.0;
      }
      if (initObj.hasOwnProperty('curvature')) {
        this.curvature = initObj.curvature
      }
      else {
        this.curvature = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReportMotion
    // Serialize message field [spin]
    bufferOffset = _serializer.uint8(obj.spin, buffer, bufferOffset);
    // Serialize message field [park]
    bufferOffset = _serializer.uint8(obj.park, buffer, bufferOffset);
    // Serialize message field [current_gear]
    bufferOffset = _serializer.uint8(obj.current_gear, buffer, bufferOffset);
    // Serialize message field [left_wheel_rotate]
    bufferOffset = _serializer.uint8(obj.left_wheel_rotate, buffer, bufferOffset);
    // Serialize message field [right_wheel_rotate]
    bufferOffset = _serializer.uint8(obj.right_wheel_rotate, buffer, bufferOffset);
    // Serialize message field [left_motor_rpm]
    bufferOffset = _serializer.uint16(obj.left_motor_rpm, buffer, bufferOffset);
    // Serialize message field [right_motor_rpm]
    bufferOffset = _serializer.uint16(obj.right_motor_rpm, buffer, bufferOffset);
    // Serialize message field [mechanical_brake]
    bufferOffset = _serializer.float32(obj.mechanical_brake, buffer, bufferOffset);
    // Serialize message field [vehicle_speed]
    bufferOffset = _serializer.float64(obj.vehicle_speed, buffer, bufferOffset);
    // Serialize message field [left_wheel_speed]
    bufferOffset = _serializer.float64(obj.left_wheel_speed, buffer, bufferOffset);
    // Serialize message field [right_wheel_speed]
    bufferOffset = _serializer.float64(obj.right_wheel_speed, buffer, bufferOffset);
    // Serialize message field [curvature]
    bufferOffset = _serializer.float32(obj.curvature, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReportMotion
    let len;
    let data = new ReportMotion(null);
    // Deserialize message field [spin]
    data.spin = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [park]
    data.park = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [current_gear]
    data.current_gear = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [left_wheel_rotate]
    data.left_wheel_rotate = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [right_wheel_rotate]
    data.right_wheel_rotate = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [left_motor_rpm]
    data.left_motor_rpm = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [right_motor_rpm]
    data.right_motor_rpm = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [mechanical_brake]
    data.mechanical_brake = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [vehicle_speed]
    data.vehicle_speed = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [left_wheel_speed]
    data.left_wheel_speed = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_wheel_speed]
    data.right_wheel_speed = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [curvature]
    data.curvature = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 41;
  }

  static datatype() {
    // Returns string type for a message object
    return 'three_one_msgs/ReportMotion';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '60fe6a6e7ba2e99db01da0cfbfd1bb49';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 spin
    uint8 park
    uint8 current_gear
    uint8 left_wheel_rotate
    uint8 right_wheel_rotate
    uint16 left_motor_rpm
    uint16 right_motor_rpm
    float32 mechanical_brake
    float64 vehicle_speed
    float64 left_wheel_speed  # signed
    float64 right_wheel_speed  # signed
    float32 curvature
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReportMotion(null);
    if (msg.spin !== undefined) {
      resolved.spin = msg.spin;
    }
    else {
      resolved.spin = 0
    }

    if (msg.park !== undefined) {
      resolved.park = msg.park;
    }
    else {
      resolved.park = 0
    }

    if (msg.current_gear !== undefined) {
      resolved.current_gear = msg.current_gear;
    }
    else {
      resolved.current_gear = 0
    }

    if (msg.left_wheel_rotate !== undefined) {
      resolved.left_wheel_rotate = msg.left_wheel_rotate;
    }
    else {
      resolved.left_wheel_rotate = 0
    }

    if (msg.right_wheel_rotate !== undefined) {
      resolved.right_wheel_rotate = msg.right_wheel_rotate;
    }
    else {
      resolved.right_wheel_rotate = 0
    }

    if (msg.left_motor_rpm !== undefined) {
      resolved.left_motor_rpm = msg.left_motor_rpm;
    }
    else {
      resolved.left_motor_rpm = 0
    }

    if (msg.right_motor_rpm !== undefined) {
      resolved.right_motor_rpm = msg.right_motor_rpm;
    }
    else {
      resolved.right_motor_rpm = 0
    }

    if (msg.mechanical_brake !== undefined) {
      resolved.mechanical_brake = msg.mechanical_brake;
    }
    else {
      resolved.mechanical_brake = 0.0
    }

    if (msg.vehicle_speed !== undefined) {
      resolved.vehicle_speed = msg.vehicle_speed;
    }
    else {
      resolved.vehicle_speed = 0.0
    }

    if (msg.left_wheel_speed !== undefined) {
      resolved.left_wheel_speed = msg.left_wheel_speed;
    }
    else {
      resolved.left_wheel_speed = 0.0
    }

    if (msg.right_wheel_speed !== undefined) {
      resolved.right_wheel_speed = msg.right_wheel_speed;
    }
    else {
      resolved.right_wheel_speed = 0.0
    }

    if (msg.curvature !== undefined) {
      resolved.curvature = msg.curvature;
    }
    else {
      resolved.curvature = 0.0
    }

    return resolved;
    }
};

module.exports = ReportMotion;
