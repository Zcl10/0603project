; Auto-generated. Do not edit!


(cl:in-package movobsplan_msgs-msg)


;//! \htmlinclude Movobspoints.msg.html

(cl:defclass <Movobspoints> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (dymipoints
    :reader dymipoints
    :initarg :dymipoints
    :type (cl:vector movobsplan_msgs-msg:Movobspoint)
   :initform (cl:make-array 0 :element-type 'movobsplan_msgs-msg:Movobspoint :initial-element (cl:make-instance 'movobsplan_msgs-msg:Movobspoint))))
)

(cl:defclass Movobspoints (<Movobspoints>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Movobspoints>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Movobspoints)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name movobsplan_msgs-msg:<Movobspoints> is deprecated: use movobsplan_msgs-msg:Movobspoints instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Movobspoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:header-val is deprecated.  Use movobsplan_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'dymipoints-val :lambda-list '(m))
(cl:defmethod dymipoints-val ((m <Movobspoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader movobsplan_msgs-msg:dymipoints-val is deprecated.  Use movobsplan_msgs-msg:dymipoints instead.")
  (dymipoints m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Movobspoints>) ostream)
  "Serializes a message object of type '<Movobspoints>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'dymipoints))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'dymipoints))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Movobspoints>) istream)
  "Deserializes a message object of type '<Movobspoints>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'dymipoints) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'dymipoints)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'movobsplan_msgs-msg:Movobspoint))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Movobspoints>)))
  "Returns string type for a message object of type '<Movobspoints>"
  "movobsplan_msgs/Movobspoints")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Movobspoints)))
  "Returns string type for a message object of type 'Movobspoints"
  "movobsplan_msgs/Movobspoints")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Movobspoints>)))
  "Returns md5sum for a message object of type '<Movobspoints>"
  "f332c1b2f057ff022a7fac3fdfcee363")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Movobspoints)))
  "Returns md5sum for a message object of type 'Movobspoints"
  "f332c1b2f057ff022a7fac3fdfcee363")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Movobspoints>)))
  "Returns full string definition for message of type '<Movobspoints>"
  (cl:format cl:nil "std_msgs/Header header~%Movobspoint[] dymipoints~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: movobsplan_msgs/Movobspoint~%geometry_msgs/Point position~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Movobspoints)))
  "Returns full string definition for message of type 'Movobspoints"
  (cl:format cl:nil "std_msgs/Header header~%Movobspoint[] dymipoints~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: movobsplan_msgs/Movobspoint~%geometry_msgs/Point position~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Movobspoints>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'dymipoints) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Movobspoints>))
  "Converts a ROS message object to a list"
  (cl:list 'Movobspoints
    (cl:cons ':header (header msg))
    (cl:cons ':dymipoints (dymipoints msg))
))
