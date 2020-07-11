; Auto-generated. Do not edit!


(cl:in-package control_msgs-msg)


;//! \htmlinclude ReportBrake.msg.html

(cl:defclass <ReportBrake> (roslisp-msg-protocol:ros-message)
  ((left_pressure_back
    :reader left_pressure_back
    :initarg :left_pressure_back
    :type cl:float
    :initform 0.0)
   (right_pressure_back
    :reader right_pressure_back
    :initarg :right_pressure_back
    :type cl:float
    :initform 0.0)
   (auto_park_state
    :reader auto_park_state
    :initarg :auto_park_state
    :type cl:fixnum
    :initform 0)
   (auto_brake_enable
    :reader auto_brake_enable
    :initarg :auto_brake_enable
    :type cl:fixnum
    :initform 0)
   (system_hot_warn
    :reader system_hot_warn
    :initarg :system_hot_warn
    :type cl:fixnum
    :initform 0)
   (system_error_code
    :reader system_error_code
    :initarg :system_error_code
    :type cl:fixnum
    :initform 0)
   (left_pressure_set
    :reader left_pressure_set
    :initarg :left_pressure_set
    :type cl:float
    :initform 0.0)
   (right_pressure_set
    :reader right_pressure_set
    :initarg :right_pressure_set
    :type cl:float
    :initform 0.0)
   (brake_pedal
    :reader brake_pedal
    :initarg :brake_pedal
    :type cl:float
    :initform 0.0))
)

(cl:defclass ReportBrake (<ReportBrake>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportBrake>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportBrake)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_msgs-msg:<ReportBrake> is deprecated: use control_msgs-msg:ReportBrake instead.")))

(cl:ensure-generic-function 'left_pressure_back-val :lambda-list '(m))
(cl:defmethod left_pressure_back-val ((m <ReportBrake>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:left_pressure_back-val is deprecated.  Use control_msgs-msg:left_pressure_back instead.")
  (left_pressure_back m))

(cl:ensure-generic-function 'right_pressure_back-val :lambda-list '(m))
(cl:defmethod right_pressure_back-val ((m <ReportBrake>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:right_pressure_back-val is deprecated.  Use control_msgs-msg:right_pressure_back instead.")
  (right_pressure_back m))

(cl:ensure-generic-function 'auto_park_state-val :lambda-list '(m))
(cl:defmethod auto_park_state-val ((m <ReportBrake>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:auto_park_state-val is deprecated.  Use control_msgs-msg:auto_park_state instead.")
  (auto_park_state m))

(cl:ensure-generic-function 'auto_brake_enable-val :lambda-list '(m))
(cl:defmethod auto_brake_enable-val ((m <ReportBrake>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:auto_brake_enable-val is deprecated.  Use control_msgs-msg:auto_brake_enable instead.")
  (auto_brake_enable m))

(cl:ensure-generic-function 'system_hot_warn-val :lambda-list '(m))
(cl:defmethod system_hot_warn-val ((m <ReportBrake>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:system_hot_warn-val is deprecated.  Use control_msgs-msg:system_hot_warn instead.")
  (system_hot_warn m))

(cl:ensure-generic-function 'system_error_code-val :lambda-list '(m))
(cl:defmethod system_error_code-val ((m <ReportBrake>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:system_error_code-val is deprecated.  Use control_msgs-msg:system_error_code instead.")
  (system_error_code m))

(cl:ensure-generic-function 'left_pressure_set-val :lambda-list '(m))
(cl:defmethod left_pressure_set-val ((m <ReportBrake>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:left_pressure_set-val is deprecated.  Use control_msgs-msg:left_pressure_set instead.")
  (left_pressure_set m))

(cl:ensure-generic-function 'right_pressure_set-val :lambda-list '(m))
(cl:defmethod right_pressure_set-val ((m <ReportBrake>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:right_pressure_set-val is deprecated.  Use control_msgs-msg:right_pressure_set instead.")
  (right_pressure_set m))

(cl:ensure-generic-function 'brake_pedal-val :lambda-list '(m))
(cl:defmethod brake_pedal-val ((m <ReportBrake>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:brake_pedal-val is deprecated.  Use control_msgs-msg:brake_pedal instead.")
  (brake_pedal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportBrake>) ostream)
  "Serializes a message object of type '<ReportBrake>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_pressure_back))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_pressure_back))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'auto_park_state)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'auto_brake_enable)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'system_hot_warn)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'system_error_code)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_pressure_set))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_pressure_set))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'brake_pedal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportBrake>) istream)
  "Deserializes a message object of type '<ReportBrake>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_pressure_back) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_pressure_back) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'auto_park_state)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'auto_brake_enable)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'system_hot_warn)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'system_error_code)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_pressure_set) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_pressure_set) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'brake_pedal) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportBrake>)))
  "Returns string type for a message object of type '<ReportBrake>"
  "control_msgs/ReportBrake")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportBrake)))
  "Returns string type for a message object of type 'ReportBrake"
  "control_msgs/ReportBrake")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportBrake>)))
  "Returns md5sum for a message object of type '<ReportBrake>"
  "c8b58fe12b43fe4b1c2d9a5950b7da37")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportBrake)))
  "Returns md5sum for a message object of type 'ReportBrake"
  "c8b58fe12b43fe4b1c2d9a5950b7da37")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportBrake>)))
  "Returns full string definition for message of type '<ReportBrake>"
  (cl:format cl:nil "float64 left_pressure_back~%float64 right_pressure_back~%uint8 auto_park_state~%uint8 auto_brake_enable~%uint8 system_hot_warn~%uint8 system_error_code~%float64 left_pressure_set~%float64 right_pressure_set~%float32 brake_pedal~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportBrake)))
  "Returns full string definition for message of type 'ReportBrake"
  (cl:format cl:nil "float64 left_pressure_back~%float64 right_pressure_back~%uint8 auto_park_state~%uint8 auto_brake_enable~%uint8 system_hot_warn~%uint8 system_error_code~%float64 left_pressure_set~%float64 right_pressure_set~%float32 brake_pedal~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportBrake>))
  (cl:+ 0
     8
     8
     1
     1
     1
     1
     8
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportBrake>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportBrake
    (cl:cons ':left_pressure_back (left_pressure_back msg))
    (cl:cons ':right_pressure_back (right_pressure_back msg))
    (cl:cons ':auto_park_state (auto_park_state msg))
    (cl:cons ':auto_brake_enable (auto_brake_enable msg))
    (cl:cons ':system_hot_warn (system_hot_warn msg))
    (cl:cons ':system_error_code (system_error_code msg))
    (cl:cons ':left_pressure_set (left_pressure_set msg))
    (cl:cons ':right_pressure_set (right_pressure_set msg))
    (cl:cons ':brake_pedal (brake_pedal msg))
))
