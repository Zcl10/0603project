// Auto-generated. Do not edit!

// (in-package three_one_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ReportControlData = require('./ReportControlData.js');
let ReportGiveBack = require('./ReportGiveBack.js');
let ReportCylinderPressure = require('./ReportCylinderPressure.js');
let ReportCylinderPosition = require('./ReportCylinderPosition.js');
let ReportVehicleState = require('./ReportVehicleState.js');
let ReportDistance = require('./ReportDistance.js');
let ReportTorque = require('./ReportTorque.js');
let ReportMotion = require('./ReportMotion.js');

//-----------------------------------------------------------

class Report {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.control = null;
      this.give_back = null;
      this.cylinder_pressure = null;
      this.cylinder_position = null;
      this.vehicle_state = null;
      this.distance = null;
      this.torque = null;
      this.motion = null;
      this.control_mode = null;
      this.operation_mode = null;
      this.counter = null;
    }
    else {
      if (initObj.hasOwnProperty('control')) {
        this.control = initObj.control
      }
      else {
        this.control = new ReportControlData();
      }
      if (initObj.hasOwnProperty('give_back')) {
        this.give_back = initObj.give_back
      }
      else {
        this.give_back = new ReportGiveBack();
      }
      if (initObj.hasOwnProperty('cylinder_pressure')) {
        this.cylinder_pressure = initObj.cylinder_pressure
      }
      else {
        this.cylinder_pressure = new ReportCylinderPressure();
      }
      if (initObj.hasOwnProperty('cylinder_position')) {
        this.cylinder_position = initObj.cylinder_position
      }
      else {
        this.cylinder_position = new ReportCylinderPosition();
      }
      if (initObj.hasOwnProperty('vehicle_state')) {
        this.vehicle_state = initObj.vehicle_state
      }
      else {
        this.vehicle_state = new ReportVehicleState();
      }
      if (initObj.hasOwnProperty('distance')) {
        this.distance = initObj.distance
      }
      else {
        this.distance = new ReportDistance();
      }
      if (initObj.hasOwnProperty('torque')) {
        this.torque = initObj.torque
      }
      else {
        this.torque = new ReportTorque();
      }
      if (initObj.hasOwnProperty('motion')) {
        this.motion = initObj.motion
      }
      else {
        this.motion = new ReportMotion();
      }
      if (initObj.hasOwnProperty('control_mode')) {
        this.control_mode = initObj.control_mode
      }
      else {
        this.control_mode = 0;
      }
      if (initObj.hasOwnProperty('operation_mode')) {
        this.operation_mode = initObj.operation_mode
      }
      else {
        this.operation_mode = 0;
      }
      if (initObj.hasOwnProperty('counter')) {
        this.counter = initObj.counter
      }
      else {
        this.counter = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Report
    // Serialize message field [control]
    bufferOffset = ReportControlData.serialize(obj.control, buffer, bufferOffset);
    // Serialize message field [give_back]
    bufferOffset = ReportGiveBack.serialize(obj.give_back, buffer, bufferOffset);
    // Serialize message field [cylinder_pressure]
    bufferOffset = ReportCylinderPressure.serialize(obj.cylinder_pressure, buffer, bufferOffset);
    // Serialize message field [cylinder_position]
    bufferOffset = ReportCylinderPosition.serialize(obj.cylinder_position, buffer, bufferOffset);
    // Serialize message field [vehicle_state]
    bufferOffset = ReportVehicleState.serialize(obj.vehicle_state, buffer, bufferOffset);
    // Serialize message field [distance]
    bufferOffset = ReportDistance.serialize(obj.distance, buffer, bufferOffset);
    // Serialize message field [torque]
    bufferOffset = ReportTorque.serialize(obj.torque, buffer, bufferOffset);
    // Serialize message field [motion]
    bufferOffset = ReportMotion.serialize(obj.motion, buffer, bufferOffset);
    // Serialize message field [control_mode]
    bufferOffset = _serializer.uint8(obj.control_mode, buffer, bufferOffset);
    // Serialize message field [operation_mode]
    bufferOffset = _serializer.uint8(obj.operation_mode, buffer, bufferOffset);
    // Serialize message field [counter]
    bufferOffset = _serializer.uint64(obj.counter, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Report
    let len;
    let data = new Report(null);
    // Deserialize message field [control]
    data.control = ReportControlData.deserialize(buffer, bufferOffset);
    // Deserialize message field [give_back]
    data.give_back = ReportGiveBack.deserialize(buffer, bufferOffset);
    // Deserialize message field [cylinder_pressure]
    data.cylinder_pressure = ReportCylinderPressure.deserialize(buffer, bufferOffset);
    // Deserialize message field [cylinder_position]
    data.cylinder_position = ReportCylinderPosition.deserialize(buffer, bufferOffset);
    // Deserialize message field [vehicle_state]
    data.vehicle_state = ReportVehicleState.deserialize(buffer, bufferOffset);
    // Deserialize message field [distance]
    data.distance = ReportDistance.deserialize(buffer, bufferOffset);
    // Deserialize message field [torque]
    data.torque = ReportTorque.deserialize(buffer, bufferOffset);
    // Deserialize message field [motion]
    data.motion = ReportMotion.deserialize(buffer, bufferOffset);
    // Deserialize message field [control_mode]
    data.control_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [operation_mode]
    data.operation_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [counter]
    data.counter = _deserializer.uint64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 149;
  }

  static datatype() {
    // Returns string type for a message object
    return 'three_one_msgs/Report';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'cb7eb1891ce051b9221ffe7f0ad827d8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    ReportControlData control
    ReportGiveBack give_back
    ReportCylinderPressure cylinder_pressure
    ReportCylinderPosition cylinder_position
    ReportVehicleState vehicle_state
    ReportDistance distance
    ReportTorque torque
    ReportMotion motion
    uint8 control_mode
    uint8 operation_mode
    uint64 counter
    ================================================================================
    MSG: three_one_msgs/ReportControlData
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
    ================================================================================
    MSG: three_one_msgs/ReportGiveBack
    float32 left_wheel_expect_speed
    float32 right_wheel_expect_speed
    ================================================================================
    MSG: three_one_msgs/ReportCylinderPressure
    uint8 left_one
    uint8 left_two
    uint8 left_three
    uint8 left_four
    uint8 right_one
    uint8 right_two
    uint8 right_three
    uint8 right_four
    ================================================================================
    MSG: three_one_msgs/ReportCylinderPosition
    uint16 left_one
    uint16 left_two
    uint16 left_three
    uint16 left_four
    uint16 right_one
    uint16 right_two
    uint16 right_three
    uint16 right_four
    ================================================================================
    MSG: three_one_msgs/ReportVehicleState
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
    ================================================================================
    MSG: three_one_msgs/ReportDistance
    uint32 mileage
    uint32 left_pulse
    uint32 right_pulse
    float64 left_distance
    float64 right_distance
    ================================================================================
    MSG: three_one_msgs/ReportTorque
    int16 left
    int16 right
    ================================================================================
    MSG: three_one_msgs/ReportMotion
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
    const resolved = new Report(null);
    if (msg.control !== undefined) {
      resolved.control = ReportControlData.Resolve(msg.control)
    }
    else {
      resolved.control = new ReportControlData()
    }

    if (msg.give_back !== undefined) {
      resolved.give_back = ReportGiveBack.Resolve(msg.give_back)
    }
    else {
      resolved.give_back = new ReportGiveBack()
    }

    if (msg.cylinder_pressure !== undefined) {
      resolved.cylinder_pressure = ReportCylinderPressure.Resolve(msg.cylinder_pressure)
    }
    else {
      resolved.cylinder_pressure = new ReportCylinderPressure()
    }

    if (msg.cylinder_position !== undefined) {
      resolved.cylinder_position = ReportCylinderPosition.Resolve(msg.cylinder_position)
    }
    else {
      resolved.cylinder_position = new ReportCylinderPosition()
    }

    if (msg.vehicle_state !== undefined) {
      resolved.vehicle_state = ReportVehicleState.Resolve(msg.vehicle_state)
    }
    else {
      resolved.vehicle_state = new ReportVehicleState()
    }

    if (msg.distance !== undefined) {
      resolved.distance = ReportDistance.Resolve(msg.distance)
    }
    else {
      resolved.distance = new ReportDistance()
    }

    if (msg.torque !== undefined) {
      resolved.torque = ReportTorque.Resolve(msg.torque)
    }
    else {
      resolved.torque = new ReportTorque()
    }

    if (msg.motion !== undefined) {
      resolved.motion = ReportMotion.Resolve(msg.motion)
    }
    else {
      resolved.motion = new ReportMotion()
    }

    if (msg.control_mode !== undefined) {
      resolved.control_mode = msg.control_mode;
    }
    else {
      resolved.control_mode = 0
    }

    if (msg.operation_mode !== undefined) {
      resolved.operation_mode = msg.operation_mode;
    }
    else {
      resolved.operation_mode = 0
    }

    if (msg.counter !== undefined) {
      resolved.counter = msg.counter;
    }
    else {
      resolved.counter = 0
    }

    return resolved;
    }
};

module.exports = Report;
