; Auto-generated. Do not edit!


(cl:in-package movobsplan_msgs-msg)


;//! \htmlinclude Movobspath.msg.html

(cl:defclass <Movobspath> (roslisp-msg-protocol:ros-message)
  ((collision
    :reader collision
    :initarg :collision
    :type cl:fixnum
    :initform 0)
   (penaltydepth
    :reader penaltydepth
    :initarg :penaltydepth
    :type cl:float
    :initform 0.0)
   (vel_to_dymicol
    :reader vel_to_dymicol
    :initarg :vel_to_dymicol
    :type cl:float
    :initform 0.0)
   (position
    :reader position
    :initarg :position
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass Movobspath (<Movobspath>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Movobspath>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Movobspath)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name movobsplan_msgs-msg:<Movobspath> is deprecated: use movobsplan_msgs-msg:Movobspath instead.")))

(cl:ensure-generic-function 'collision-val :lambda-list '(m))
(cl:defmethod collision-val ((m <Movobspath>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:collision-val is deprecated.  Use movobsplan_msgs-msg:collision instead.")
  (collision m))

(cl:ensure-generic-function 'penaltydepth-val :lambda-list '(m))
(cl:defmethod penaltydepth-val ((m <Movobspath>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:penaltydepth-val is deprecated.  Use movobsplan_msgs-msg:penaltydepth instead.")
  (penaltydepth m))

(cl:ensure-generic-function 'vel_to_dymicol-val :lambda-list '(m))
(cl:defmethod vel_to_dymicol-val ((m <Movobspath>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:vel_to_dymicol-val is deprecated.  Use movobsplan_msgs-msg:vel_to_dymicol instead.")
  (vel_to_dymicol m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <Movobspath>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:position-val is deprecated.  Use movobsplan_msgs-msg:position instead.")
  (position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Movobspath>) ostream)
  "Serializes a message object of type '<Movobspath>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'collision)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'penaltydepth))))
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
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'position) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Movobspath>) istream)
  "Deserializes a message object of type '<Movobspath>"
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
    (cl:setf (cl:slot-value msg 'penaltydepth) (roslisp-utils:decode-double-float-bits bits)))
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
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'position) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Movobspath>)))
  "Returns string type for a message object of type '<Movobspath>"
  "movobsplan_msgs/Movobspath")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Movobspath)))
  "Returns string type for a message object of type 'Movobspath"
  "movobsplan_msgs/Movobspath")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Movobspath>)))
  "Returns md5sum for a message object of type '<Movobspath>"
  "b91e4c47ca79497da4d13234e1f837d6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Movobspath)))
  "Returns md5sum for a message object of type 'Movobspath"
  "b91e4c47ca79497da4d13234e1f837d6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Movobspath>)))
  "Returns full string definition for message of type '<Movobspath>"
  (cl:format cl:nil "uint8 collision~%float64 penaltydepth~%float64 vel_to_dymicol~%geometry_msgs/Point position~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Movobspath)))
  "Returns full string definition for message of type 'Movobspath"
  (cl:format cl:nil "uint8 collision~%float64 penaltydepth~%float64 vel_to_dymicol~%geometry_msgs/Point position~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Movobspath>))
  (cl:+ 0
     1
     8
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'position))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Movobspath>))
  "Converts a ROS message object to a list"
  (cl:list 'Movobspath
    (cl:cons ':collision (collision msg))
    (cl:cons ':penaltydepth (penaltydepth msg))
    (cl:cons ':vel_to_dymicol (vel_to_dymicol msg))
    (cl:cons ':position (position msg))
))
