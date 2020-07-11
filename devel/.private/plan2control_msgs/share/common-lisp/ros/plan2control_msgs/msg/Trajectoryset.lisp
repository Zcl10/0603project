; Auto-generated. Do not edit!


(cl:in-package plan2control_msgs-msg)


;//! \htmlinclude Trajectoryset.msg.html

(cl:defclass <Trajectoryset> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (trajectories
    :reader trajectories
    :initarg :trajectories
    :type (cl:vector plan2control_msgs-msg:Trajectory)
   :initform (cl:make-array 0 :element-type 'plan2control_msgs-msg:Trajectory :initial-element (cl:make-instance 'plan2control_msgs-msg:Trajectory)))
   (replansucceed
    :reader replansucceed
    :initarg :replansucceed
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Trajectoryset (<Trajectoryset>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Trajectoryset>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Trajectoryset)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name plan2control_msgs-msg:<Trajectoryset> is deprecated: use plan2control_msgs-msg:Trajectoryset instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Trajectoryset>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader plan2control_msgs-msg:header-val is deprecated.  Use plan2control_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'trajectories-val :lambda-list '(m))
(cl:defmethod trajectories-val ((m <Trajectoryset>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader plan2control_msgs-msg:trajectories-val is deprecated.  Use plan2control_msgs-msg:trajectories instead.")
  (trajectories m))

(cl:ensure-generic-function 'replansucceed-val :lambda-list '(m))
(cl:defmethod replansucceed-val ((m <Trajectoryset>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader plan2control_msgs-msg:replansucceed-val is deprecated.  Use plan2control_msgs-msg:replansucceed instead.")
  (replansucceed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Trajectoryset>) ostream)
  "Serializes a message object of type '<Trajectoryset>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'trajectories))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'trajectories))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'replansucceed)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Trajectoryset>) istream)
  "Deserializes a message object of type '<Trajectoryset>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'trajectories) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'trajectories)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'plan2control_msgs-msg:Trajectory))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'replansucceed)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Trajectoryset>)))
  "Returns string type for a message object of type '<Trajectoryset>"
  "plan2control_msgs/Trajectoryset")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Trajectoryset)))
  "Returns string type for a message object of type 'Trajectoryset"
  "plan2control_msgs/Trajectoryset")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Trajectoryset>)))
  "Returns md5sum for a message object of type '<Trajectoryset>"
  "7baba054cf904a3e6277282e7d205c87")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Trajectoryset)))
  "Returns md5sum for a message object of type 'Trajectoryset"
  "7baba054cf904a3e6277282e7d205c87")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Trajectoryset>)))
  "Returns full string definition for message of type '<Trajectoryset>"
  (cl:format cl:nil "std_msgs/Header header~%Trajectory[] trajectories~%uint8 replansucceed~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: plan2control_msgs/Trajectory~%std_msgs/Header header~%Traj_Node[] points~%float64 issued_acc~%int32 delay_index~%~%================================================================================~%MSG: plan2control_msgs/Traj_Node~%bool forward~%int32 id~%geometry_msgs/Point position~%geometry_msgs/Quaternion orientation~%float64 curvature~%geometry_msgs/Twist velocity~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Trajectoryset)))
  "Returns full string definition for message of type 'Trajectoryset"
  (cl:format cl:nil "std_msgs/Header header~%Trajectory[] trajectories~%uint8 replansucceed~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: plan2control_msgs/Trajectory~%std_msgs/Header header~%Traj_Node[] points~%float64 issued_acc~%int32 delay_index~%~%================================================================================~%MSG: plan2control_msgs/Traj_Node~%bool forward~%int32 id~%geometry_msgs/Point position~%geometry_msgs/Quaternion orientation~%float64 curvature~%geometry_msgs/Twist velocity~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Trajectoryset>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'trajectories) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Trajectoryset>))
  "Converts a ROS message object to a list"
  (cl:list 'Trajectoryset
    (cl:cons ':header (header msg))
    (cl:cons ':trajectories (trajectories msg))
    (cl:cons ':replansucceed (replansucceed msg))
))
