; Auto-generated. Do not edit!


(cl:in-package control_msgs-msg)


;//! \htmlinclude ReportThrottle.msg.html

(cl:defclass <ReportThrottle> (roslisp-msg-protocol:ros-message)
  ((throttle_opening
    :reader throttle_opening
    :initarg :throttle_opening
    :type cl:float
    :initform 0.0)
   (throttle_pedal
    :reader throttle_pedal
    :initarg :throttle_pedal
    :type cl:float
    :initform 0.0))
)

(cl:defclass ReportThrottle (<ReportThrottle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportThrottle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportThrottle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_msgs-msg:<ReportThrottle> is deprecated: use control_msgs-msg:ReportThrottle instead.")))

(cl:ensure-generic-function 'throttle_opening-val :lambda-list '(m))
(cl:defmethod throttle_opening-val ((m <ReportThrottle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:throttle_opening-val is deprecated.  Use control_msgs-msg:throttle_opening instead.")
  (throttle_opening m))

(cl:ensure-generic-function 'throttle_pedal-val :lambda-list '(m))
(cl:defmethod throttle_pedal-val ((m <ReportThrottle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:throttle_pedal-val is deprecated.  Use control_msgs-msg:throttle_pedal instead.")
  (throttle_pedal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportThrottle>) ostream)
  "Serializes a message object of type '<ReportThrottle>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'throttle_opening))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'throttle_pedal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportThrottle>) istream)
  "Deserializes a message object of type '<ReportThrottle>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'throttle_opening) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'throttle_pedal) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportThrottle>)))
  "Returns string type for a message object of type '<ReportThrottle>"
  "control_msgs/ReportThrottle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportThrottle)))
  "Returns string type for a message object of type 'ReportThrottle"
  "control_msgs/ReportThrottle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportThrottle>)))
  "Returns md5sum for a message object of type '<ReportThrottle>"
  "3fec449e5f78595bef42751bd36df7c4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportThrottle)))
  "Returns md5sum for a message object of type 'ReportThrottle"
  "3fec449e5f78595bef42751bd36df7c4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportThrottle>)))
  "Returns full string definition for message of type '<ReportThrottle>"
  (cl:format cl:nil "float32 throttle_opening~%float32 throttle_pedal~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportThrottle)))
  "Returns full string definition for message of type 'ReportThrottle"
  (cl:format cl:nil "float32 throttle_opening~%float32 throttle_pedal~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportThrottle>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportThrottle>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportThrottle
    (cl:cons ':throttle_opening (throttle_opening msg))
    (cl:cons ':throttle_pedal (throttle_pedal msg))
))
