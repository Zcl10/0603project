; Auto-generated. Do not edit!


(cl:in-package control_msgs-msg)


;//! \htmlinclude ReportHMI.msg.html

(cl:defclass <ReportHMI> (roslisp-msg-protocol:ros-message)
  ((manual_estop
    :reader manual_estop
    :initarg :manual_estop
    :type cl:fixnum
    :initform 0)
   (is_human_brake
    :reader is_human_brake
    :initarg :is_human_brake
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ReportHMI (<ReportHMI>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportHMI>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportHMI)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_msgs-msg:<ReportHMI> is deprecated: use control_msgs-msg:ReportHMI instead.")))

(cl:ensure-generic-function 'manual_estop-val :lambda-list '(m))
(cl:defmethod manual_estop-val ((m <ReportHMI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:manual_estop-val is deprecated.  Use control_msgs-msg:manual_estop instead.")
  (manual_estop m))

(cl:ensure-generic-function 'is_human_brake-val :lambda-list '(m))
(cl:defmethod is_human_brake-val ((m <ReportHMI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:is_human_brake-val is deprecated.  Use control_msgs-msg:is_human_brake instead.")
  (is_human_brake m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportHMI>) ostream)
  "Serializes a message object of type '<ReportHMI>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'manual_estop)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'is_human_brake)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportHMI>) istream)
  "Deserializes a message object of type '<ReportHMI>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'manual_estop)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'is_human_brake)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportHMI>)))
  "Returns string type for a message object of type '<ReportHMI>"
  "control_msgs/ReportHMI")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportHMI)))
  "Returns string type for a message object of type 'ReportHMI"
  "control_msgs/ReportHMI")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportHMI>)))
  "Returns md5sum for a message object of type '<ReportHMI>"
  "f19a467eddf6f2a1b5c81ed415355fbf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportHMI)))
  "Returns md5sum for a message object of type 'ReportHMI"
  "f19a467eddf6f2a1b5c81ed415355fbf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportHMI>)))
  "Returns full string definition for message of type '<ReportHMI>"
  (cl:format cl:nil "uint8 manual_estop~%uint8 is_human_brake ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportHMI)))
  "Returns full string definition for message of type 'ReportHMI"
  (cl:format cl:nil "uint8 manual_estop~%uint8 is_human_brake ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportHMI>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportHMI>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportHMI
    (cl:cons ':manual_estop (manual_estop msg))
    (cl:cons ':is_human_brake (is_human_brake msg))
))
