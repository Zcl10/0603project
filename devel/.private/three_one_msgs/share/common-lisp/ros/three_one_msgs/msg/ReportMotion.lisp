; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ReportMotion.msg.html

(cl:defclass <ReportMotion> (roslisp-msg-protocol:ros-message)
  ((spin
    :reader spin
    :initarg :spin
    :type cl:fixnum
    :initform 0)
   (park
    :reader park
    :initarg :park
    :type cl:fixnum
    :initform 0)
   (current_gear
    :reader current_gear
    :initarg :current_gear
    :type cl:fixnum
    :initform 0)
   (left_wheel_rotate
    :reader left_wheel_rotate
    :initarg :left_wheel_rotate
    :type cl:fixnum
    :initform 0)
   (right_wheel_rotate
    :reader right_wheel_rotate
    :initarg :right_wheel_rotate
    :type cl:fixnum
    :initform 0)
   (left_motor_rpm
    :reader left_motor_rpm
    :initarg :left_motor_rpm
    :type cl:fixnum
    :initform 0)
   (right_motor_rpm
    :reader right_motor_rpm
    :initarg :right_motor_rpm
    :type cl:fixnum
    :initform 0)
   (mechanical_brake
    :reader mechanical_brake
    :initarg :mechanical_brake
    :type cl:float
    :initform 0.0)
   (vehicle_speed
    :reader vehicle_speed
    :initarg :vehicle_speed
    :type cl:float
    :initform 0.0)
   (left_wheel_speed
    :reader left_wheel_speed
    :initarg :left_wheel_speed
    :type cl:float
    :initform 0.0)
   (right_wheel_speed
    :reader right_wheel_speed
    :initarg :right_wheel_speed
    :type cl:float
    :initform 0.0)
   (curvature
    :reader curvature
    :initarg :curvature
    :type cl:float
    :initform 0.0))
)

(cl:defclass ReportMotion (<ReportMotion>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportMotion>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportMotion)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ReportMotion> is deprecated: use three_one_msgs-msg:ReportMotion instead.")))

(cl:ensure-generic-function 'spin-val :lambda-list '(m))
(cl:defmethod spin-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:spin-val is deprecated.  Use three_one_msgs-msg:spin instead.")
  (spin m))

(cl:ensure-generic-function 'park-val :lambda-list '(m))
(cl:defmethod park-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:park-val is deprecated.  Use three_one_msgs-msg:park instead.")
  (park m))

(cl:ensure-generic-function 'current_gear-val :lambda-list '(m))
(cl:defmethod current_gear-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:current_gear-val is deprecated.  Use three_one_msgs-msg:current_gear instead.")
  (current_gear m))

(cl:ensure-generic-function 'left_wheel_rotate-val :lambda-list '(m))
(cl:defmethod left_wheel_rotate-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_wheel_rotate-val is deprecated.  Use three_one_msgs-msg:left_wheel_rotate instead.")
  (left_wheel_rotate m))

(cl:ensure-generic-function 'right_wheel_rotate-val :lambda-list '(m))
(cl:defmethod right_wheel_rotate-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_wheel_rotate-val is deprecated.  Use three_one_msgs-msg:right_wheel_rotate instead.")
  (right_wheel_rotate m))

(cl:ensure-generic-function 'left_motor_rpm-val :lambda-list '(m))
(cl:defmethod left_motor_rpm-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_motor_rpm-val is deprecated.  Use three_one_msgs-msg:left_motor_rpm instead.")
  (left_motor_rpm m))

(cl:ensure-generic-function 'right_motor_rpm-val :lambda-list '(m))
(cl:defmethod right_motor_rpm-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_motor_rpm-val is deprecated.  Use three_one_msgs-msg:right_motor_rpm instead.")
  (right_motor_rpm m))

(cl:ensure-generic-function 'mechanical_brake-val :lambda-list '(m))
(cl:defmethod mechanical_brake-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:mechanical_brake-val is deprecated.  Use three_one_msgs-msg:mechanical_brake instead.")
  (mechanical_brake m))

(cl:ensure-generic-function 'vehicle_speed-val :lambda-list '(m))
(cl:defmethod vehicle_speed-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:vehicle_speed-val is deprecated.  Use three_one_msgs-msg:vehicle_speed instead.")
  (vehicle_speed m))

(cl:ensure-generic-function 'left_wheel_speed-val :lambda-list '(m))
(cl:defmethod left_wheel_speed-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_wheel_speed-val is deprecated.  Use three_one_msgs-msg:left_wheel_speed instead.")
  (left_wheel_speed m))

(cl:ensure-generic-function 'right_wheel_speed-val :lambda-list '(m))
(cl:defmethod right_wheel_speed-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_wheel_speed-val is deprecated.  Use three_one_msgs-msg:right_wheel_speed instead.")
  (right_wheel_speed m))

(cl:ensure-generic-function 'curvature-val :lambda-list '(m))
(cl:defmethod curvature-val ((m <ReportMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:curvature-val is deprecated.  Use three_one_msgs-msg:curvature instead.")
  (curvature m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportMotion>) ostream)
  "Serializes a message object of type '<ReportMotion>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'spin)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'park)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'current_gear)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_wheel_rotate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_wheel_rotate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_motor_rpm)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_motor_rpm)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_motor_rpm)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_motor_rpm)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'mechanical_brake))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'vehicle_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_wheel_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_wheel_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'curvature))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportMotion>) istream)
  "Deserializes a message object of type '<ReportMotion>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'spin)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'park)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'current_gear)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_wheel_rotate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_wheel_rotate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_motor_rpm)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_motor_rpm)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_motor_rpm)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_motor_rpm)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'mechanical_brake) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vehicle_speed) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_wheel_speed) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_wheel_speed) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'curvature) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportMotion>)))
  "Returns string type for a message object of type '<ReportMotion>"
  "three_one_msgs/ReportMotion")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportMotion)))
  "Returns string type for a message object of type 'ReportMotion"
  "three_one_msgs/ReportMotion")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportMotion>)))
  "Returns md5sum for a message object of type '<ReportMotion>"
  "60fe6a6e7ba2e99db01da0cfbfd1bb49")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportMotion)))
  "Returns md5sum for a message object of type 'ReportMotion"
  "60fe6a6e7ba2e99db01da0cfbfd1bb49")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportMotion>)))
  "Returns full string definition for message of type '<ReportMotion>"
  (cl:format cl:nil "uint8 spin~%uint8 park~%uint8 current_gear~%uint8 left_wheel_rotate~%uint8 right_wheel_rotate~%uint16 left_motor_rpm~%uint16 right_motor_rpm~%float32 mechanical_brake~%float64 vehicle_speed~%float64 left_wheel_speed  # signed~%float64 right_wheel_speed  # signed~%float32 curvature~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportMotion)))
  "Returns full string definition for message of type 'ReportMotion"
  (cl:format cl:nil "uint8 spin~%uint8 park~%uint8 current_gear~%uint8 left_wheel_rotate~%uint8 right_wheel_rotate~%uint16 left_motor_rpm~%uint16 right_motor_rpm~%float32 mechanical_brake~%float64 vehicle_speed~%float64 left_wheel_speed  # signed~%float64 right_wheel_speed  # signed~%float32 curvature~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportMotion>))
  (cl:+ 0
     1
     1
     1
     1
     1
     2
     2
     4
     8
     8
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportMotion>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportMotion
    (cl:cons ':spin (spin msg))
    (cl:cons ':park (park msg))
    (cl:cons ':current_gear (current_gear msg))
    (cl:cons ':left_wheel_rotate (left_wheel_rotate msg))
    (cl:cons ':right_wheel_rotate (right_wheel_rotate msg))
    (cl:cons ':left_motor_rpm (left_motor_rpm msg))
    (cl:cons ':right_motor_rpm (right_motor_rpm msg))
    (cl:cons ':mechanical_brake (mechanical_brake msg))
    (cl:cons ':vehicle_speed (vehicle_speed msg))
    (cl:cons ':left_wheel_speed (left_wheel_speed msg))
    (cl:cons ':right_wheel_speed (right_wheel_speed msg))
    (cl:cons ':curvature (curvature msg))
))
