; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ReportControlData.msg.html

(cl:defclass <ReportControlData> (roslisp-msg-protocol:ros-message)
  ((curvature
    :reader curvature
    :initarg :curvature
    :type cl:float
    :initform 0.0)
   (speed
    :reader speed
    :initarg :speed
    :type cl:float
    :initform 0.0)
   (rpm
    :reader rpm
    :initarg :rpm
    :type cl:fixnum
    :initform 0)
   (work_mode
    :reader work_mode
    :initarg :work_mode
    :type cl:fixnum
    :initform 0)
   (gear
    :reader gear
    :initarg :gear
    :type cl:fixnum
    :initform 0)
   (turn_to
    :reader turn_to
    :initarg :turn_to
    :type cl:fixnum
    :initform 0)
   (brake
    :reader brake
    :initarg :brake
    :type cl:fixnum
    :initform 0)
   (park
    :reader park
    :initarg :park
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
   (vertical_wall_mode
    :reader vertical_wall_mode
    :initarg :vertical_wall_mode
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
   (fix_two_chamber_valve
    :reader fix_two_chamber_valve
    :initarg :fix_two_chamber_valve
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ReportControlData (<ReportControlData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportControlData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportControlData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ReportControlData> is deprecated: use three_one_msgs-msg:ReportControlData instead.")))

(cl:ensure-generic-function 'curvature-val :lambda-list '(m))
(cl:defmethod curvature-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:curvature-val is deprecated.  Use three_one_msgs-msg:curvature instead.")
  (curvature m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:speed-val is deprecated.  Use three_one_msgs-msg:speed instead.")
  (speed m))

(cl:ensure-generic-function 'rpm-val :lambda-list '(m))
(cl:defmethod rpm-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:rpm-val is deprecated.  Use three_one_msgs-msg:rpm instead.")
  (rpm m))

(cl:ensure-generic-function 'work_mode-val :lambda-list '(m))
(cl:defmethod work_mode-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:work_mode-val is deprecated.  Use three_one_msgs-msg:work_mode instead.")
  (work_mode m))

(cl:ensure-generic-function 'gear-val :lambda-list '(m))
(cl:defmethod gear-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:gear-val is deprecated.  Use three_one_msgs-msg:gear instead.")
  (gear m))

(cl:ensure-generic-function 'turn_to-val :lambda-list '(m))
(cl:defmethod turn_to-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:turn_to-val is deprecated.  Use three_one_msgs-msg:turn_to instead.")
  (turn_to m))

(cl:ensure-generic-function 'brake-val :lambda-list '(m))
(cl:defmethod brake-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:brake-val is deprecated.  Use three_one_msgs-msg:brake instead.")
  (brake m))

(cl:ensure-generic-function 'park-val :lambda-list '(m))
(cl:defmethod park-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:park-val is deprecated.  Use three_one_msgs-msg:park instead.")
  (park m))

(cl:ensure-generic-function 'cylinder_select-val :lambda-list '(m))
(cl:defmethod cylinder_select-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:cylinder_select-val is deprecated.  Use three_one_msgs-msg:cylinder_select instead.")
  (cylinder_select m))

(cl:ensure-generic-function 'suspension_select-val :lambda-list '(m))
(cl:defmethod suspension_select-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension_select-val is deprecated.  Use three_one_msgs-msg:suspension_select instead.")
  (suspension_select m))

(cl:ensure-generic-function 'vertical_wall_mode-val :lambda-list '(m))
(cl:defmethod vertical_wall_mode-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:vertical_wall_mode-val is deprecated.  Use three_one_msgs-msg:vertical_wall_mode instead.")
  (vertical_wall_mode m))

(cl:ensure-generic-function 'suspension_work_mode-val :lambda-list '(m))
(cl:defmethod suspension_work_mode-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension_work_mode-val is deprecated.  Use three_one_msgs-msg:suspension_work_mode instead.")
  (suspension_work_mode m))

(cl:ensure-generic-function 'suspension_work_mode_detail-val :lambda-list '(m))
(cl:defmethod suspension_work_mode_detail-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension_work_mode_detail-val is deprecated.  Use three_one_msgs-msg:suspension_work_mode_detail instead.")
  (suspension_work_mode_detail m))

(cl:ensure-generic-function 'suspension_cylinder_select_mode-val :lambda-list '(m))
(cl:defmethod suspension_cylinder_select_mode-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension_cylinder_select_mode-val is deprecated.  Use three_one_msgs-msg:suspension_cylinder_select_mode instead.")
  (suspension_cylinder_select_mode m))

(cl:ensure-generic-function 'suspension_cylinder_motor_control-val :lambda-list '(m))
(cl:defmethod suspension_cylinder_motor_control-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:suspension_cylinder_motor_control-val is deprecated.  Use three_one_msgs-msg:suspension_cylinder_motor_control instead.")
  (suspension_cylinder_motor_control m))

(cl:ensure-generic-function 'fix_two_chamber_valve-val :lambda-list '(m))
(cl:defmethod fix_two_chamber_valve-val ((m <ReportControlData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:fix_two_chamber_valve-val is deprecated.  Use three_one_msgs-msg:fix_two_chamber_valve instead.")
  (fix_two_chamber_valve m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportControlData>) ostream)
  "Serializes a message object of type '<ReportControlData>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'curvature))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rpm)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'rpm)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'work_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gear)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'turn_to)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'brake)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'park)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cylinder_select)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_select)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vertical_wall_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_work_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_work_mode_detail)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_cylinder_select_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_cylinder_motor_control)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'fix_two_chamber_valve)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportControlData>) istream)
  "Deserializes a message object of type '<ReportControlData>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'curvature) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rpm)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'rpm)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'work_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gear)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'turn_to)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'brake)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'park)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cylinder_select)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_select)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vertical_wall_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_work_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_work_mode_detail)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_cylinder_select_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'suspension_cylinder_motor_control)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'fix_two_chamber_valve)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportControlData>)))
  "Returns string type for a message object of type '<ReportControlData>"
  "three_one_msgs/ReportControlData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportControlData)))
  "Returns string type for a message object of type 'ReportControlData"
  "three_one_msgs/ReportControlData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportControlData>)))
  "Returns md5sum for a message object of type '<ReportControlData>"
  "a6b97385db9e76f4dfa530144bb3765f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportControlData)))
  "Returns md5sum for a message object of type 'ReportControlData"
  "a6b97385db9e76f4dfa530144bb3765f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportControlData>)))
  "Returns full string definition for message of type '<ReportControlData>"
  (cl:format cl:nil "float32 curvature~%float32 speed~%uint16 rpm~%uint8 work_mode~%uint8 gear~%uint8 turn_to~%uint8 brake~%uint8 park~%uint8 cylinder_select~%uint8 suspension_select~%uint8 vertical_wall_mode~%uint8 suspension_work_mode~%uint8 suspension_work_mode_detail~%uint8 suspension_cylinder_select_mode~%uint8 suspension_cylinder_motor_control~%uint8 fix_two_chamber_valve~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportControlData)))
  "Returns full string definition for message of type 'ReportControlData"
  (cl:format cl:nil "float32 curvature~%float32 speed~%uint16 rpm~%uint8 work_mode~%uint8 gear~%uint8 turn_to~%uint8 brake~%uint8 park~%uint8 cylinder_select~%uint8 suspension_select~%uint8 vertical_wall_mode~%uint8 suspension_work_mode~%uint8 suspension_work_mode_detail~%uint8 suspension_cylinder_select_mode~%uint8 suspension_cylinder_motor_control~%uint8 fix_two_chamber_valve~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportControlData>))
  (cl:+ 0
     4
     4
     2
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
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportControlData>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportControlData
    (cl:cons ':curvature (curvature msg))
    (cl:cons ':speed (speed msg))
    (cl:cons ':rpm (rpm msg))
    (cl:cons ':work_mode (work_mode msg))
    (cl:cons ':gear (gear msg))
    (cl:cons ':turn_to (turn_to msg))
    (cl:cons ':brake (brake msg))
    (cl:cons ':park (park msg))
    (cl:cons ':cylinder_select (cylinder_select msg))
    (cl:cons ':suspension_select (suspension_select msg))
    (cl:cons ':vertical_wall_mode (vertical_wall_mode msg))
    (cl:cons ':suspension_work_mode (suspension_work_mode msg))
    (cl:cons ':suspension_work_mode_detail (suspension_work_mode_detail msg))
    (cl:cons ':suspension_cylinder_select_mode (suspension_cylinder_select_mode msg))
    (cl:cons ':suspension_cylinder_motor_control (suspension_cylinder_motor_control msg))
    (cl:cons ':fix_two_chamber_valve (fix_two_chamber_valve msg))
))
