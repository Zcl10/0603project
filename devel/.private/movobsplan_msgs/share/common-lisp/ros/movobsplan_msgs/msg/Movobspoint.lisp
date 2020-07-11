; Auto-generated. Do not edit!


(cl:in-package movobsplan_msgs-msg)


;//! \htmlinclude Movobspoint.msg.html

(cl:defclass <Movobspoint> (roslisp-msg-protocol:ros-message)
  ((position
    :reader position
    :initarg :position
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass Movobspoint (<Movobspoint>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Movobspoint>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Movobspoint)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name movobsplan_msgs-msg:<Movobspoint> is deprecated: use movobsplan_msgs-msg:Movobspoint instead.")))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <Movobspoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:position-val is deprecated.  Use movobsplan_msgs-msg:position instead.")
  (position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Movobspoint>) ostream)
  "Serializes a message object of type '<Movobspoint>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'position) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Movobspoint>) istream)
  "Deserializes a message object of type '<Movobspoint>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'position) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Movobspoint>)))
  "Returns string type for a message object of type '<Movobspoint>"
  "movobsplan_msgs/Movobspoint")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Movobspoint)))
  "Returns string type for a message object of type 'Movobspoint"
  "movobsplan_msgs/Movobspoint")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Movobspoint>)))
  "Returns md5sum for a message object of type '<Movobspoint>"
  "e7bb0ef028c744b081acdc57743b11d8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Movobspoint)))
  "Returns md5sum for a message object of type 'Movobspoint"
  "e7bb0ef028c744b081acdc57743b11d8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Movobspoint>)))
  "Returns full string definition for message of type '<Movobspoint>"
  (cl:format cl:nil "geometry_msgs/Point position~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Movobspoint)))
  "Returns full string definition for message of type 'Movobspoint"
  (cl:format cl:nil "geometry_msgs/Point position~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Movobspoint>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'position))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Movobspoint>))
  "Converts a ROS message object to a list"
  (cl:list 'Movobspoint
    (cl:cons ':position (position msg))
))
