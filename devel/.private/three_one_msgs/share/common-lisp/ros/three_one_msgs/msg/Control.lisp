; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude Control.msg.html

(cl:defclass <Control> (roslisp-msg-protocol:ros-message)
  ((priority
    :reader priority
    :initarg :priority
    :type cl:fixnum
    :initform 0)
   (speed
    :reader speed
    :initarg :speed
    :type three_one_msgs-msg:ControlSpeed
    :initform (cl:make-instance 'three_one_msgs-msg:ControlSpeed))
   (steer
    :reader steer
    :initarg :steer
    :type three_one_msgs-msg:ControlSteer
    :initform (cl:make-instance 'three_one_msgs-msg:ControlSteer))
   (suspension
    :reader suspension
    :initarg :suspension
    :type three_one_msgs-msg:ControlSuspension
    :initform (cl:make-instance 'three_one_msgs-msg:ControlSuspension))
   (weapon
    :reader weapon
    :initarg :weapon
    :type three_one_msgs-msg:ControlWeapon
    :initform (cl:make-instance 'three_one_msgs-msg:ControlWeapon)))
)

(cl:defclass Control (<Control>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Control>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Control)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<Control> is deprecated: use three_one_msgs-msg:Control instead.")))

(cl:ensure-generic-function 'priority-val :lambda-list '(m))
(cl:defmethod priority-val ((m <Control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:priority-val is deprecated.  Use three_one_msgs-msg:priority instead.")
  (priority m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <Control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:speed-val is deprecated.  Use three_one_msgs-msg:speed instead.")
  (speed m))

(cl:ensure-generic-function 'steer-val :lambda-list '(m))
(cl:defmethod steer-val ((m <Control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:steer-val is deprecated.  Use three_one_msgs-msg:steer instead.")
  (steer m))

(cl:ensure-generic-function 'suspension-val :lambda-list '(m))
(cl:defmethod suspension-val ((m <Control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension-val is deprecated.  Use three_one_msgs-msg:suspension instead.")
  (suspension m))

(cl:ensure-generic-function 'weapon-val :lambda-list '(m))
(cl:defmethod weapon-val ((m <Control>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:weapon-val is deprecated.  Use three_one_msgs-msg:weapon instead.")
  (weapon m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Control>) ostream)
  "Serializes a message object of type '<Control>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'speed) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'steer) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'suspension) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'weapon) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Control>) istream)
  "Deserializes a message object of type '<Control>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'speed) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'steer) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'suspension) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'weapon) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Control>)))
  "Returns string type for a message object of type '<Control>"
  "three_one_msgs/Control")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Control)))
  "Returns string type for a message object of type 'Control"
  "three_one_msgs/Control")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Control>)))
  "Returns md5sum for a message object of type '<Control>"
  "d0ddf03a8d19a85e773b681a9262d15c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Control)))
  "Returns md5sum for a message object of type 'Control"
  "d0ddf03a8d19a85e773b681a9262d15c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Control>)))
  "Returns full string definition for message of type '<Control>"
  (cl:format cl:nil "uint8 priority~%ControlSpeed speed~%ControlSteer steer~%ControlSuspension suspension~%ControlWeapon weapon~%================================================================================~%MSG: three_one_msgs/ControlSpeed~%uint8 priority~%uint8 halt~%uint8 gear~%float32 speed~%================================================================================~%MSG: three_one_msgs/ControlSteer~%uint8 priority~%float64 curvature~%================================================================================~%MSG: three_one_msgs/ControlSuspension~%uint8 priority~%uint8 cylinder_select~%uint8 suspension_select~%uint8 suspension_work_mode~%uint8 suspension_work_mode_detail~%uint8 suspension_cylinder_select_mode~%uint8 suspension_cylinder_motor_control~%uint8 vertical_wall_mode~%uint8 fix_two_chamber_valve~%uint8 entrenchment~%================================================================================~%MSG: three_one_msgs/ControlWeapon~%uint8 priority~%uint8 weapon_330~%uint8 weapon_28~%uint8 weapon_cmd~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Control)))
  "Returns full string definition for message of type 'Control"
  (cl:format cl:nil "uint8 priority~%ControlSpeed speed~%ControlSteer steer~%ControlSuspension suspension~%ControlWeapon weapon~%================================================================================~%MSG: three_one_msgs/ControlSpeed~%uint8 priority~%uint8 halt~%uint8 gear~%float32 speed~%================================================================================~%MSG: three_one_msgs/ControlSteer~%uint8 priority~%float64 curvature~%================================================================================~%MSG: three_one_msgs/ControlSuspension~%uint8 priority~%uint8 cylinder_select~%uint8 suspension_select~%uint8 suspension_work_mode~%uint8 suspension_work_mode_detail~%uint8 suspension_cylinder_select_mode~%uint8 suspension_cylinder_motor_control~%uint8 vertical_wall_mode~%uint8 fix_two_chamber_valve~%uint8 entrenchment~%================================================================================~%MSG: three_one_msgs/ControlWeapon~%uint8 priority~%uint8 weapon_330~%uint8 weapon_28~%uint8 weapon_cmd~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Control>))
  (cl:+ 0
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'speed))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'steer))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'suspension))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'weapon))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Control>))
  "Converts a ROS message object to a list"
  (cl:list 'Control
    (cl:cons ':priority (priority msg))
    (cl:cons ':speed (speed msg))
    (cl:cons ':steer (steer msg))
    (cl:cons ':suspension (suspension msg))
    (cl:cons ':weapon (weapon msg))
))
