// Auto-generated. Do not edit!

// (in-package movobsplan_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Movobspoint = require('./Movobspoint.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Movobspoints {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.dymipoints = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('dymipoints')) {
        this.dymipoints = initObj.dymipoints
      }
      else {
        this.dymipoints = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Movobspoints
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [dymipoints]
    // Serialize the length for message field [dymipoints]
    bufferOffset = _serializer.uint32(obj.dymipoints.length, buffer, bufferOffset);
    obj.dymipoints.forEach((val) => {
      bufferOffset = Movobspoint.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Movobspoints
    let len;
    let data = new Movobspoints(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [dymipoints]
    // Deserialize array length for message field [dymipoints]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.dymipoints = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.dymipoints[i] = Movobspoint.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 24 * object.dymipoints.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'movobsplan_msgs/Movobspoints';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f332c1b2f057ff022a7fac3fdfcee363';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    Movobspoint[] dymipoints
    
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
    
    ================================================================================
    MSG: movobsplan_msgs/Movobspoint
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
    const resolved = new Movobspoints(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.dymipoints !== undefined) {
      resolved.dymipoints = new Array(msg.dymipoints.length);
      for (let i = 0; i < resolved.dymipoints.length; ++i) {
        resolved.dymipoints[i] = Movobspoint.Resolve(msg.dymipoints[i]);
      }
    }
    else {
      resolved.dymipoints = []
    }

    return resolved;
    }
};

module.exports = Movobspoints;
