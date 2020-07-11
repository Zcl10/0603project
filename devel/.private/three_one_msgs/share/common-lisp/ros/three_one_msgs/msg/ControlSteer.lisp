; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ControlSteer.msg.html

(cl:defclass <ControlSteer> (roslisp-msg-protocol:ros-message)
  ((priority
    :reader priority
    :initarg :priority
    :type cl:fixnum
    :initform 0)
   (curvature
    :reader curvature
    :initarg :curvature
    :type cl:float
    :initform 0.0))
)

(cl:defclass ControlSteer (<ControlSteer>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ControlSteer>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ControlSteer)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ControlSteer> is deprecated: use three_one_msgs-msg:ControlSteer instead.")))

(cl:ensure-generic-function 'priority-val :lambda-list '(m))
(cl:defmethod priority-val ((m <ControlSteer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:priority-val is deprecated.  Use three_one_msgs-msg:priority instead.")
  (priority m))

(cl:ensure-generic-function 'curvature-val :lambda-list '(m))
(cl:defmethod curvature-val ((m <ControlSteer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:curvature-val is deprecated.  Use three_one_msgs-msg:curvature instead.")
  (curvature m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ControlSteer>) ostream)
  "Serializes a message object of type '<ControlSteer>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'curvature))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ControlSteer>) istream)
  "Deserializes a message object of type '<ControlSteer>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'curvature) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ControlSteer>)))
  "Returns string type for a message object of type '<ControlSteer>"
  "three_one_msgs/ControlSteer")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ControlSteer)))
  "Returns string type for a message object of type 'ControlSteer"
  "three_one_msgs/ControlSteer")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ControlSteer>)))
  "Returns md5sum for a message object of type '<ControlSteer>"
  "dfb9884ac74fdee49105f987268ecda4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ControlSteer)))
  "Returns md5sum for a message object of type 'ControlSteer"
  "dfb9884ac74fdee49105f987268ecda4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ControlSteer>)))
  "Returns full string definition for message of type '<ControlSteer>"
  (cl:format cl:nil "uint8 priority~%float64 curvature~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ControlSteer)))
  "Returns full string definition for message of type 'ControlSteer"
  (cl:format cl:nil "uint8 priority~%float64 curvature~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ControlSteer>))
  (cl:+ 0
     1
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ControlSteer>))
  "Converts a ROS message object to a list"
  (cl:list 'ControlSteer
    (cl:cons ':priority (priority msg))
    (cl:cons ':curvature (curvature msg))
))
