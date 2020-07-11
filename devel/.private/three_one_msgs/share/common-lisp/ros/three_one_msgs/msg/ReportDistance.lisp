; Auto-generated. Do not edit!


(cl:in-package three_one_msgs-msg)


;//! \htmlinclude ReportDistance.msg.html

(cl:defclass <ReportDistance> (roslisp-msg-protocol:ros-message)
  ((mileage
    :reader mileage
    :initarg :mileage
    :type cl:integer
    :initform 0)
   (left_pulse
    :reader left_pulse
    :initarg :left_pulse
    :type cl:integer
    :initform 0)
   (right_pulse
    :reader right_pulse
    :initarg :right_pulse
    :type cl:integer
    :initform 0)
   (left_distance
    :reader left_distance
    :initarg :left_distance
    :type cl:float
    :initform 0.0)
   (right_distance
    :reader right_distance
    :initarg :right_distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass ReportDistance (<ReportDistance>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportDistance>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportDistance)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name three_one_msgs-msg:<ReportDistance> is deprecated: use three_one_msgs-msg:ReportDistance instead.")))

(cl:ensure-generic-function 'mileage-val :lambda-list '(m))
(cl:defmethod mileage-val ((m <ReportDistance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:mileage-val is deprecated.  Use three_one_msgs-msg:mileage instead.")
  (mileage m))

(cl:ensure-generic-function 'left_pulse-val :lambda-list '(m))
(cl:defmethod left_pulse-val ((m <ReportDistance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_pulse-val is deprecated.  Use three_one_msgs-msg:left_pulse instead.")
  (left_pulse m))

(cl:ensure-generic-function 'right_pulse-val :lambda-list '(m))
(cl:defmethod right_pulse-val ((m <ReportDistance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_pulse-val is deprecated.  Use three_one_msgs-msg:right_pulse instead.")
  (right_pulse m))

(cl:ensure-generic-function 'left_distance-val :lambda-list '(m))
(cl:defmethod left_distance-val ((m <ReportDistance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:left_distance-val is deprecated.  Use three_one_msgs-msg:left_distance instead.")
  (left_distance m))

(cl:ensure-generic-function 'right_distance-val :lambda-list '(m))
(cl:defmethod right_distance-val ((m <ReportDistance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader three_one_msgs-msg:right_distance-val is deprecated.  Use three_one_msgs-msg:right_distance instead.")
  (right_distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportDistance>) ostream)
  "Serializes a message object of type '<ReportDistance>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mileage)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mileage)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mileage)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mileage)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_pulse)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_pulse)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'left_pulse)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'left_pulse)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_pulse)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_pulse)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'right_pulse)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'right_pulse)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportDistance>) istream)
  "Deserializes a message object of type '<ReportDistance>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mileage)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mileage)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mileage)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mileage)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_pulse)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'left_pulse)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'left_pulse)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'left_pulse)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_pulse)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'right_pulse)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'right_pulse)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'right_pulse)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_distance) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_distance) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportDistance>)))
  "Returns string type for a message object of type '<ReportDistance>"
  "three_one_msgs/ReportDistance")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportDistance)))
  "Returns string type for a message object of type 'ReportDistance"
  "three_one_msgs/ReportDistance")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportDistance>)))
  "Returns md5sum for a message object of type '<ReportDistance>"
  "11d828c6b9eb85d8fbb317377ee4beba")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportDistance)))
  "Returns md5sum for a message object of type 'ReportDistance"
  "11d828c6b9eb85d8fbb317377ee4beba")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportDistance>)))
  "Returns full string definition for message of type '<ReportDistance>"
  (cl:format cl:nil "uint32 mileage~%uint32 left_pulse~%uint32 right_pulse~%float64 left_distance~%float64 right_distance~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportDistance)))
  "Returns full string definition for message of type 'ReportDistance"
  (cl:format cl:nil "uint32 mileage~%uint32 left_pulse~%uint32 right_pulse~%float64 left_distance~%float64 right_distance~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportDistance>))
  (cl:+ 0
     4
     4
     4
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportDistance>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportDistance
    (cl:cons ':mileage (mileage msg))
    (cl:cons ':left_pulse (left_pulse msg))
    (cl:cons ':right_pulse (right_pulse msg))
    (cl:cons ':left_distance (left_distance msg))
    (cl:cons ':right_distance (right_distance msg))
))
