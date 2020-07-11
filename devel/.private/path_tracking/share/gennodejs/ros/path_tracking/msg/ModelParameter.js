// Auto-generated. Do not edit!

// (in-package path_tracking.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ModelParameter {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.speed_parameter = null;
      this.steer_parameter = null;
      this.time_cost = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('speed_parameter')) {
        this.speed_parameter = initObj.speed_parameter
      }
      else {
        this.speed_parameter = 0.0;
      }
      if (initObj.hasOwnProperty('steer_parameter')) {
        this.steer_parameter = initObj.steer_parameter
      }
      else {
        this.steer_parameter = 0.0;
      }
      if (initObj.hasOwnProperty('time_cost')) {
        this.time_cost = initObj.time_cost
      }
      else {
        this.time_cost = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ModelParameter
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [speed_parameter]
    bufferOffset = _serializer.float64(obj.speed_parameter, buffer, bufferOffset);
    // Serialize message field [steer_parameter]
    bufferOffset = _serializer.float64(obj.steer_parameter, buffer, bufferOffset);
    // Serialize message field [time_cost]
    bufferOffset = _serializer.float64(obj.time_cost, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ModelParameter
    let len;
    let data = new ModelParameter(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [speed_parameter]
    data.speed_parameter = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [steer_parameter]
    data.steer_parameter = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [time_cost]
    data.time_cost = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'path_tracking/ModelParameter';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '564bf96590ff731beab91211a6911188';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    float64 speed_parameter
    float64 steer_parameter
    float64 time_cost
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ModelParameter(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.speed_parameter !== undefined) {
      resolved.speed_parameter = msg.speed_parameter;
    }
    else {
      resolved.speed_parameter = 0.0
    }

    if (msg.steer_parameter !== undefined) {
      resolved.steer_parameter = msg.steer_parameter;
    }
    else {
      resolved.steer_parameter = 0.0
    }

    if (msg.time_cost !== undefined) {
      resolved.time_cost = msg.time_cost;
    }
    else {
      resolved.time_cost = 0.0
    }

    return resolved;
    }
};

module.exports = ModelParameter;
