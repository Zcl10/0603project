; Auto-generated. Do not edit!


(cl:in-package control_msgs-msg)


;//! \htmlinclude ReportWheel.msg.html

(cl:defclass <ReportWheel> (roslisp-msg-protocol:ros-message)
  ((front_left
    :reader front_left
    :initarg :front_left
    :type cl:float
    :initform 0.0)
   (front_right
    :reader front_right
    :initarg :front_right
    :type cl:float
    :initform 0.0)
   (rear_left
    :reader rear_left
    :initarg :rear_left
    :type cl:float
    :initform 0.0)
   (rear_right
    :reader rear_right
    :initarg :rear_right
    :type cl:float
    :initform 0.0)
   (statusfl
    :reader statusfl
    :initarg :statusfl
    :type cl:fixnum
    :initform 0)
   (statusfr
    :reader statusfr
    :initarg :statusfr
    :type cl:fixnum
    :initform 0)
   (statusrl
    :reader statusrl
    :initarg :statusrl
    :type cl:fixnum
    :initform 0)
   (statusrr
    :reader statusrr
    :initarg :statusrr
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ReportWheel (<ReportWheel>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportWheel>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportWheel)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_msgs-msg:<ReportWheel> is deprecated: use control_msgs-msg:ReportWheel instead.")))

(cl:ensure-generic-function 'front_left-val :lambda-list '(m))
(cl:defmethod front_left-val ((m <ReportWheel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:front_left-val is deprecated.  Use control_msgs-msg:front_left instead.")
  (front_left m))

(cl:ensure-generic-function 'front_right-val :lambda-list '(m))
(cl:defmethod front_right-val ((m <ReportWheel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:front_right-val is deprecated.  Use control_msgs-msg:front_right instead.")
  (front_right m))

(cl:ensure-generic-function 'rear_left-val :lambda-list '(m))
(cl:defmethod rear_left-val ((m <ReportWheel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:rear_left-val is deprecated.  Use control_msgs-msg:rear_left instead.")
  (rear_left m))

(cl:ensure-generic-function 'rear_right-val :lambda-list '(m))
(cl:defmethod rear_right-val ((m <ReportWheel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:rear_right-val is deprecated.  Use control_msgs-msg:rear_right instead.")
  (rear_right m))

(cl:ensure-generic-function 'statusfl-val :lambda-list '(m))
(cl:defmethod statusfl-val ((m <ReportWheel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:statusfl-val is deprecated.  Use control_msgs-msg:statusfl instead.")
  (statusfl m))

(cl:ensure-generic-function 'statusfr-val :lambda-list '(m))
(cl:defmethod statusfr-val ((m <ReportWheel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:statusfr-val is deprecated.  Use control_msgs-msg:statusfr instead.")
  (statusfr m))

(cl:ensure-generic-function 'statusrl-val :lambda-list '(m))
(cl:defmethod statusrl-val ((m <ReportWheel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:statusrl-val is deprecated.  Use control_msgs-msg:statusrl instead.")
  (statusrl m))

(cl:ensure-generic-function 'statusrr-val :lambda-list '(m))
(cl:defmethod statusrr-val ((m <ReportWheel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:statusrr-val is deprecated.  Use control_msgs-msg:statusrr instead.")
  (statusrr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportWheel>) ostream)
  "Serializes a message object of type '<ReportWheel>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'front_left))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'front_right))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'rear_left))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'rear_right))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'statusfl)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'statusfr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'statusrl)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'statusrr)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportWheel>) istream)
  "Deserializes a message object of type '<ReportWheel>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'front_left) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'front_right) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rear_left) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rear_right) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'statusfl)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'statusfr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'statusrl)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'statusrr)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportWheel>)))
  "Returns string type for a message object of type '<ReportWheel>"
  "control_msgs/ReportWheel")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportWheel)))
  "Returns string type for a message object of type 'ReportWheel"
  "control_msgs/ReportWheel")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportWheel>)))
  "Returns md5sum for a message object of type '<ReportWheel>"
  "c3a44de250eee4620714d052b512e107")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportWheel)))
  "Returns md5sum for a message object of type 'ReportWheel"
  "c3a44de250eee4620714d052b512e107")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportWheel>)))
  "Returns full string definition for message of type '<ReportWheel>"
  (cl:format cl:nil "float32 front_left~%float32 front_right~%float32 rear_left~%float32 rear_right~%uint8 statusfl~%uint8 statusfr~%uint8 statusrl~%uint8 statusrr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportWheel)))
  "Returns full string definition for message of type 'ReportWheel"
  (cl:format cl:nil "float32 front_left~%float32 front_right~%float32 rear_left~%float32 rear_right~%uint8 statusfl~%uint8 statusfr~%uint8 statusrl~%uint8 statusrr~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportWheel>))
  (cl:+ 0
     4
     4
     4
     4
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportWheel>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportWheel
    (cl:cons ':front_left (front_left msg))
    (cl:cons ':front_right (front_right msg))
    (cl:cons ':rear_left (rear_left msg))
    (cl:cons ':rear_right (rear_right msg))
    (cl:cons ':statusfl (statusfl msg))
    (cl:cons ':statusfr (statusfr msg))
    (cl:cons ':statusrl (statusrl msg))
    (cl:cons ':statusrr (statusrr msg))
))
