; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ControlSpeed.msg.html

(cl:defclass <ControlSpeed> (roslisp-msg-protocol:ros-message)
  ((priority
    :reader priority
    :initarg :priority
    :type cl:fixnum
    :initform 0)
   (halt
    :reader halt
    :initarg :halt
    :type cl:fixnum
    :initform 0)
   (gear
    :reader gear
    :initarg :gear
    :type cl:fixnum
    :initform 0)
   (speed
    :reader speed
    :initarg :speed
    :type cl:float
    :initform 0.0))
)

(cl:defclass ControlSpeed (<ControlSpeed>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ControlSpeed>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ControlSpeed)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ControlSpeed> is deprecated: use three_one_msgs-msg:ControlSpeed instead.")))

(cl:ensure-generic-function 'priority-val :lambda-list '(m))
(cl:defmethod priority-val ((m <ControlSpeed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:priority-val is deprecated.  Use three_one_msgs-msg:priority instead.")
  (priority m))

(cl:ensure-generic-function 'halt-val :lambda-list '(m))
(cl:defmethod halt-val ((m <ControlSpeed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:halt-val is deprecated.  Use three_one_msgs-msg:halt instead.")
  (halt m))

(cl:ensure-generic-function 'gear-val :lambda-list '(m))
(cl:defmethod gear-val ((m <ControlSpeed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:gear-val is deprecated.  Use three_one_msgs-msg:gear instead.")
  (gear m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <ControlSpeed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:speed-val is deprecated.  Use three_one_msgs-msg:speed instead.")
  (speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ControlSpeed>) ostream)
  "Serializes a message object of type '<ControlSpeed>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'halt)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gear)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ControlSpeed>) istream)
  "Deserializes a message object of type '<ControlSpeed>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'halt)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gear)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ControlSpeed>)))
  "Returns string type for a message object of type '<ControlSpeed>"
  "three_one_msgs/ControlSpeed")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ControlSpeed)))
  "Returns string type for a message object of type 'ControlSpeed"
  "three_one_msgs/ControlSpeed")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ControlSpeed>)))
  "Returns md5sum for a message object of type '<ControlSpeed>"
  "cd90b94757225a2c977b45e86b71ada1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ControlSpeed)))
  "Returns md5sum for a message object of type 'ControlSpeed"
  "cd90b94757225a2c977b45e86b71ada1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ControlSpeed>)))
  "Returns full string definition for message of type '<ControlSpeed>"
  (cl:format cl:nil "uint8 priority~%uint8 halt~%uint8 gear~%float32 speed~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ControlSpeed)))
  "Returns full string definition for message of type 'ControlSpeed"
  (cl:format cl:nil "uint8 priority~%uint8 halt~%uint8 gear~%float32 speed~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ControlSpeed>))
  (cl:+ 0
     1
     1
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ControlSpeed>))
  "Converts a ROS message object to a list"
  (cl:list 'ControlSpeed
    (cl:cons ':priority (priority msg))
    (cl:cons ':halt (halt msg))
    (cl:cons ':gear (gear msg))
    (cl:cons ':speed (speed msg))
))
