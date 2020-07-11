; Auto-generated. Do not edit!


(cl:in-package path_tracking-msg)


;//! \htmlinclude ModelParameter.msg.html

(cl:defclass <ModelParameter> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (speed_parameter
    :reader speed_parameter
    :initarg :speed_parameter
    :type cl:float
    :initform 0.0)
   (steer_parameter
    :reader steer_parameter
    :initarg :steer_parameter
    :type cl:float
    :initform 0.0)
   (time_cost
    :reader time_cost
    :initarg :time_cost
    :type cl:float
    :initform 0.0))
)

(cl:defclass ModelParameter (<ModelParameter>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ModelParameter>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ModelParameter)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name path_tracking-msg:<ModelParameter> is deprecated: use path_tracking-msg:ModelParameter instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ModelParameter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:header-val is deprecated.  Use path_tracking-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'speed_parameter-val :lambda-list '(m))
(cl:defmethod speed_parameter-val ((m <ModelParameter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:speed_parameter-val is deprecated.  Use path_tracking-msg:speed_parameter instead.")
  (speed_parameter m))

(cl:ensure-generic-function 'steer_parameter-val :lambda-list '(m))
(cl:defmethod steer_parameter-val ((m <ModelParameter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:steer_parameter-val is deprecated.  Use path_tracking-msg:steer_parameter instead.")
  (steer_parameter m))

(cl:ensure-generic-function 'time_cost-val :lambda-list '(m))
(cl:defmethod time_cost-val ((m <ModelParameter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:time_cost-val is deprecated.  Use path_tracking-msg:time_cost instead.")
  (time_cost m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ModelParameter>) ostream)
  "Serializes a message object of type '<ModelParameter>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'speed_parameter))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'steer_parameter))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time_cost))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ModelParameter>) istream)
  "Deserializes a message object of type '<ModelParameter>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed_parameter) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'steer_parameter) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time_cost) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ModelParameter>)))
  "Returns string type for a message object of type '<ModelParameter>"
  "path_tracking/ModelParameter")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ModelParameter)))
  "Returns string type for a message object of type 'ModelParameter"
  "path_tracking/ModelParameter")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ModelParameter>)))
  "Returns md5sum for a message object of type '<ModelParameter>"
  "564bf96590ff731beab91211a6911188")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ModelParameter)))
  "Returns md5sum for a message object of type 'ModelParameter"
  "564bf96590ff731beab91211a6911188")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ModelParameter>)))
  "Returns full string definition for message of type '<ModelParameter>"
  (cl:format cl:nil "Header header~%~%float64 speed_parameter~%float64 steer_parameter~%float64 time_cost~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ModelParameter)))
  "Returns full string definition for message of type 'ModelParameter"
  (cl:format cl:nil "Header header~%~%float64 speed_parameter~%float64 steer_parameter~%float64 time_cost~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ModelParameter>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ModelParameter>))
  "Converts a ROS message object to a list"
  (cl:list 'ModelParameter
    (cl:cons ':header (header msg))
    (cl:cons ':speed_parameter (speed_parameter msg))
    (cl:cons ':steer_parameter (steer_parameter msg))
    (cl:cons ':time_cost (time_cost msg))
))
