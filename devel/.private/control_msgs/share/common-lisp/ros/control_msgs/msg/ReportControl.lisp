; Auto-generated. Do not edit!


(cl:in-package control_msgs-msg)


;//! \htmlinclude ReportControl.msg.html

(cl:defclass <ReportControl> (roslisp-msg-protocol:ros-message)
  ((Speed
    :reader Speed
    :initarg :Speed
    :type control_msgs-msg:ControlSpeed
    :initform (cl:make-instance 'control_msgs-msg:ControlSpeed))
   (Steer
    :reader Steer
    :initarg :Steer
    :type control_msgs-msg:ControlSteer
    :initform (cl:make-instance 'control_msgs-msg:ControlSteer))
   (ordermode
    :reader ordermode
    :initarg :ordermode
    :type control_msgs-msg:ControlMode
    :initform (cl:make-instance 'control_msgs-msg:ControlMode)))
)

(cl:defclass ReportControl (<ReportControl>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportControl>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportControl)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_msgs-msg:<ReportControl> is deprecated: use control_msgs-msg:ReportControl instead.")))

(cl:ensure-generic-function 'Speed-val :lambda-list '(m))
(cl:defmethod Speed-val ((m <ReportControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:Speed-val is deprecated.  Use control_msgs-msg:Speed instead.")
  (Speed m))

(cl:ensure-generic-function 'Steer-val :lambda-list '(m))
(cl:defmethod Steer-val ((m <ReportControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:Steer-val is deprecated.  Use control_msgs-msg:Steer instead.")
  (Steer m))

(cl:ensure-generic-function 'ordermode-val :lambda-list '(m))
(cl:defmethod ordermode-val ((m <ReportControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:ordermode-val is deprecated.  Use control_msgs-msg:ordermode instead.")
  (ordermode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportControl>) ostream)
  "Serializes a message object of type '<ReportControl>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Speed) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Steer) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ordermode) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportControl>) istream)
  "Deserializes a message object of type '<ReportControl>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Speed) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Steer) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ordermode) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportControl>)))
  "Returns string type for a message object of type '<ReportControl>"
  "control_msgs/ReportControl")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportControl)))
  "Returns string type for a message object of type 'ReportControl"
  "control_msgs/ReportControl")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportControl>)))
  "Returns md5sum for a message object of type '<ReportControl>"
  "4cfa3145374ffabe5a1139ad8f40e485")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportControl)))
  "Returns md5sum for a message object of type 'ReportControl"
  "4cfa3145374ffabe5a1139ad8f40e485")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportControl>)))
  "Returns full string definition for message of type '<ReportControl>"
  (cl:format cl:nil "ControlSpeed Speed~%ControlSteer Steer~%ControlMode ordermode~%~%~%================================================================================~%MSG: control_msgs/ControlSpeed~%Header header~%uint8 priority~%uint8 gear~%float64 speed~%float64 acc~%float64 torque~%float64 brake~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: control_msgs/ControlSteer~%Header header~%uint8 priority~%float64 steer~%~%~%================================================================================~%MSG: control_msgs/ControlMode~%Header header~%uint8 RainyLight~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportControl)))
  "Returns full string definition for message of type 'ReportControl"
  (cl:format cl:nil "ControlSpeed Speed~%ControlSteer Steer~%ControlMode ordermode~%~%~%================================================================================~%MSG: control_msgs/ControlSpeed~%Header header~%uint8 priority~%uint8 gear~%float64 speed~%float64 acc~%float64 torque~%float64 brake~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: control_msgs/ControlSteer~%Header header~%uint8 priority~%float64 steer~%~%~%================================================================================~%MSG: control_msgs/ControlMode~%Header header~%uint8 RainyLight~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportControl>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Speed))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Steer))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ordermode))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportControl>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportControl
    (cl:cons ':Speed (Speed msg))
    (cl:cons ':Steer (Steer msg))
    (cl:cons ':ordermode (ordermode msg))
))
