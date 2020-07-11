; Auto-generated. Do not edit!


(cl:in-package movobsplan_msgs-msg)


;//! \htmlinclude Movobspeed.msg.html

(cl:defclass <Movobspeed> (roslisp-msg-protocol:ros-message)
  ((collision
    :reader collision
    :initarg :collision
    :type cl:fixnum
    :initform 0)
   (exp_vel
    :reader exp_vel
    :initarg :exp_vel
    :type cl:float
    :initform 0.0)
   (exp_time
    :reader exp_time
    :initarg :exp_time
    :type cl:float
    :initform 0.0)
   (vel_to_dymicol
    :reader vel_to_dymicol
    :initarg :vel_to_dymicol
    :type cl:float
    :initform 0.0))
)

(cl:defclass Movobspeed (<Movobspeed>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Movobspeed>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Movobspeed)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name movobsplan_msgs-msg:<Movobspeed> is deprecated: use movobsplan_msgs-msg:Movobspeed instead.")))

(cl:ensure-generic-function 'collision-val :lambda-list '(m))
(cl:defmethod collision-val ((m <Movobspeed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:collision-val is deprecated.  Use movobsplan_msgs-msg:collision instead.")
  (collision m))

(cl:ensure-generic-function 'exp_vel-val :lambda-list '(m))
(cl:defmethod exp_vel-val ((m <Movobspeed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:exp_vel-val is deprecated.  Use movobsplan_msgs-msg:exp_vel instead.")
  (exp_vel m))

(cl:ensure-generic-function 'exp_time-val :lambda-list '(m))
(cl:defmethod exp_time-val ((m <Movobspeed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:exp_time-val is deprecated.  Use movobsplan_msgs-msg:exp_time instead.")
  (exp_time m))

(cl:ensure-generic-function 'vel_to_dymicol-val :lambda-list '(m))
(cl:defmethod vel_to_dymicol-val ((m <Movobspeed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:vel_to_dymicol-val is deprecated.  Use movobsplan_msgs-msg:vel_to_dymicol instead.")
  (vel_to_dymicol m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Movobspeed>) ostream)
  "Serializes a message object of type '<Movobspeed>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'collision)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'exp_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'exp_time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vel_to_dymicol))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Movobspeed>) istream)
  "Deserializes a message object of type '<Movobspeed>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'collision)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'exp_vel) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'exp_time) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vel_to_dymicol) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Movobspeed>)))
  "Returns string type for a message object of type '<Movobspeed>"
  "movobsplan_msgs/Movobspeed")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Movobspeed)))
  "Returns string type for a message object of type 'Movobspeed"
  "movobsplan_msgs/Movobspeed")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Movobspeed>)))
  "Returns md5sum for a message object of type '<Movobspeed>"
  "5e108d72b562baf3de0c61211ba4f831")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Movobspeed)))
  "Returns md5sum for a message object of type 'Movobspeed"
  "5e108d72b562baf3de0c61211ba4f831")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Movobspeed>)))
  "Returns full string definition for message of type '<Movobspeed>"
  (cl:format cl:nil "uint8 collision~%float64 exp_vel~%float64 exp_time~%float64 vel_to_dymicol~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Movobspeed)))
  "Returns full string definition for message of type 'Movobspeed"
  (cl:format cl:nil "uint8 collision~%float64 exp_vel~%float64 exp_time~%float64 vel_to_dymicol~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Movobspeed>))
  (cl:+ 0
     1
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Movobspeed>))
  "Converts a ROS message object to a list"
  (cl:list 'Movobspeed
    (cl:cons ':collision (collision msg))
    (cl:cons ':exp_vel (exp_vel msg))
    (cl:cons ':exp_time (exp_time msg))
    (cl:cons ':vel_to_dymicol (vel_to_dymicol msg))
))
