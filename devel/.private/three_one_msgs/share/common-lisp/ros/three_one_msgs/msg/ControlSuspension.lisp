; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ControlSuspension.msg.html

(cl:defclass <ControlSuspension> (roslisp-msg-protocol:ros-message)
  ((priority
    :reader priority
    :initarg :priority
    :type cl:fixnum
    :initform 0)
   (cylinder_select
    :reader cylinder_select
    :initarg :cylinder_select
    :type cl:fixnum
    :initform 0)
   (suspension_select
    :reader suspension_select
    :initarg :suspension_select
    :type cl:fixnum
    :initform 0)
   (suspension_work_mode
    :reader suspension_work_mode
    :initarg :suspension_work_mode
    :type cl:fixnum
    :initform 0)
   (suspension_work_mode_detail
    :reader suspension_work_mode_detail
    :initarg :suspension_work_mode_detail
    :type cl:fixnum
    :initform 0)
   (suspension_cylinder_select_mode
    :reader suspension_cylinder_select_mode
    :initarg :suspension_cylinder_select_mode
    :type cl:fixnum
    :initform 0)
   (suspension_cylinder_motor_control
    :reader suspension_cylinder_motor_control
    :initarg :suspension_cylinder_motor_control
    :type cl:fixnum
    :initform 0)
   (vertical_wall_mode
    :reader vertical_wall_mode
    :initarg :vertical_wall_mode
    :type cl:fixnum
    :initform 0)
   (fix_two_chamber_valve
    :reader fix_two_chamber_valve
    :initarg :fix_two_chamber_valve
    :type cl:fixnum
    :initform 0)
   (entrenchment
    :reader entrenchment
    :initarg :entrenchment
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ControlSuspension (<ControlSuspension>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ControlSuspension>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ControlSuspension)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ControlSuspension> is deprecated: use three_one_msgs-msg:ControlSuspension instead.")))

(cl:ensure-generic-function 'priority-val :lambda-list '(m))
(cl:defmethod priority-val ((m <ControlSuspension>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:priority-val is deprecated.  Use three_one_msgs-msg:priority instead.")
  (priority m))

(cl:ensure-generic-function 'cylinder_select-val :lambda-list '(m))
(cl:defmethod cylinder_select-val ((m <ControlSuspension>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:cylinder_select-val is deprecated.  Use three_one_msgs-msg:cylinder_select instead.")
  (cylinder_select m))

(cl:ensure-generic-function 'suspension_select-val :lambda-list '(m))
(cl:defmethod suspension_select-val ((m <ControlSuspension>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension_select-val is deprecated.  Use three_one_msgs-msg:suspension_select instead.")
  (suspension_select m))

(cl:ensure-generic-function 'suspension_work_mode-val :lambda-list '(m))
(cl:defmethod suspension_work_mode-val ((m <ControlSuspension>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension_work_mode-val is deprecated.  Use three_one_msgs-msg:suspension_work_mode instead.")
  (suspension_work_mode m))

(cl:ensure-generic-function 'suspension_work_mode_detail-val :lambda-list '(m))
(cl:defmethod suspension_work_mode_detail-val ((m <ControlSuspension>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension_work_mode_detail-val is deprecated.  Use three_one_msgs-msg:suspension_work_mode_detail instead.")
  (suspension_work_mode_detail m))

(cl:ensure-generic-function 'suspension_cylinder_select_mode-val :lambda-list '(m))
(cl:defmethod suspension_cylinder_select_mode-val ((m <ControlSuspension>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension_cylinder_select_mode-val is deprecated.  Use three_one_msgs-msg:suspension_cylinder_select_mode instead.")
  (suspension_cylinder_select_mode m))

(cl:ensure-generic-function 'suspension_cylinder_motor_control-val :lambda-list '(m))
(cl:defmethod suspension_cylinder_motor_control-val ((m <ControlSuspension>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension_cylinder_motor_control-val is deprecated.  Use three_one_msgs-msg:suspension_cylinder_motor_control instead.")
  (suspension_cylinder_motor_control m))

(cl:ensure-generic-function 'vertical_wall_mode-val :lambda-list '(m))
(cl:defmethod vertical_wall_mode-val ((m <ControlSuspension>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:vertical_wall_mode-val is deprecated.  Use three_one_msgs-msg:vertical_wall_mode instead.")
  (vertical_wall_mode m))

(cl:ensure-generic-function 'fix_two_chamber_valve-val :lambda-list '(m))
(cl:defmethod fix_two_chamber_valve-val ((m <ControlSuspension>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:fix_two_chamber_valve-val is deprecated.  Use three_one_msgs-msg:fix_two_chamber_valve instead.")
  (fix_two_chamber_valve m))

(cl:ensure-generic-function 'entrenchment-val :lambda-list '(m))
(cl:defmethod entrenchment-val ((m <ControlSuspension>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:entrenchment-val is deprecated.  Use three_one_msgs-msg:entrenchment instead.")
  (entrenchment m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ControlSuspension>) ostream)
  "Serializes a message object of type '<ControlSuspension>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cylinder_select)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_select)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_work_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_work_mode_detail)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_cylinder_select_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_cylinder_motor_control)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vertical_wall_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'fix_two_chamber_valve)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'entrenchment)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ControlSuspension>) istream)
  "Deserializes a message object of type '<ControlSuspension>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'priority)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cylinder_select)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_select)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_work_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_work_mode_detail)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_cylinder_select_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_cylinder_motor_control)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vertical_wall_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'fix_two_chamber_valve)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'entrenchment)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ControlSuspension>)))
  "Returns string type for a message object of type '<ControlSuspension>"
  "three_one_msgs/ControlSuspension")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ControlSuspension)))
  "Returns string type for a message object of type 'ControlSuspension"
  "three_one_msgs/ControlSuspension")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ControlSuspension>)))
  "Returns md5sum for a message object of type '<ControlSuspension>"
  "4bc4d758b88c322981bcdaff503bd5e7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ControlSuspension)))
  "Returns md5sum for a message object of type 'ControlSuspension"
  "4bc4d758b88c322981bcdaff503bd5e7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ControlSuspension>)))
  "Returns full string definition for message of type '<ControlSuspension>"
  (cl:format cl:nil "uint8 priority~%uint8 cylinder_select~%uint8 suspension_select~%uint8 suspension_work_mode~%uint8 suspension_work_mode_detail~%uint8 suspension_cylinder_select_mode~%uint8 suspension_cylinder_motor_control~%uint8 vertical_wall_mode~%uint8 fix_two_chamber_valve~%uint8 entrenchment~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ControlSuspension)))
  "Returns full string definition for message of type 'ControlSuspension"
  (cl:format cl:nil "uint8 priority~%uint8 cylinder_select~%uint8 suspension_select~%uint8 suspension_work_mode~%uint8 suspension_work_mode_detail~%uint8 suspension_cylinder_select_mode~%uint8 suspension_cylinder_motor_control~%uint8 vertical_wall_mode~%uint8 fix_two_chamber_valve~%uint8 entrenchment~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ControlSuspension>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ControlSuspension>))
  "Converts a ROS message object to a list"
  (cl:list 'ControlSuspension
    (cl:cons ':priority (priority msg))
    (cl:cons ':cylinder_select (cylinder_select msg))
    (cl:cons ':suspension_select (suspension_select msg))
    (cl:cons ':suspension_work_mode (suspension_work_mode msg))
    (cl:cons ':suspension_work_mode_detail (suspension_work_mode_detail msg))
    (cl:cons ':suspension_cylinder_select_mode (suspension_cylinder_select_mode msg))
    (cl:cons ':suspension_cylinder_motor_control (suspension_cylinder_motor_control msg))
    (cl:cons ':vertical_wall_mode (vertical_wall_mode msg))
    (cl:cons ':fix_two_chamber_valve (fix_two_chamber_valve msg))
    (cl:cons ':entrenchment (entrenchment msg))
))
