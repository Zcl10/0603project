; Auto-generated. Do not edit!


(cl:in-package control_msgs-msg)


;//! \htmlinclude ReportVehicleWorkMode.msg.html

(cl:defclass <ReportVehicleWorkMode> (roslisp-msg-protocol:ros-message)
  ((work_mode
    :reader work_mode
    :initarg :work_mode
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ReportVehicleWorkMode (<ReportVehicleWorkMode>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReportVehicleWorkMode>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReportVehicleWorkMode)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_msgs-msg:<ReportVehicleWorkMode> is deprecated: use control_msgs-msg:ReportVehicleWorkMode instead.")))

(cl:ensure-generic-function 'work_mode-val :lambda-list '(m))
(cl:defmethod work_mode-val ((m <ReportVehicleWorkMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:work_mode-val is deprecated.  Use control_msgs-msg:work_mode instead.")
  (work_mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReportVehicleWorkMode>) ostream)
  "Serializes a message object of type '<ReportVehicleWorkMode>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'work_mode)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReportVehicleWorkMode>) istream)
  "Deserializes a message object of type '<ReportVehicleWorkMode>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'work_mode)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReportVehicleWorkMode>)))
  "Returns string type for a message object of type '<ReportVehicleWorkMode>"
  "control_msgs/ReportVehicleWorkMode")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReportVehicleWorkMode)))
  "Returns string type for a message object of type 'ReportVehicleWorkMode"
  "control_msgs/ReportVehicleWorkMode")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReportVehicleWorkMode>)))
  "Returns md5sum for a message object of type '<ReportVehicleWorkMode>"
  "fcfe851405844897c8730da81110283d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReportVehicleWorkMode)))
  "Returns md5sum for a message object of type 'ReportVehicleWorkMode"
  "fcfe851405844897c8730da81110283d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReportVehicleWorkMode>)))
  "Returns full string definition for message of type '<ReportVehicleWorkMode>"
  (cl:format cl:nil "uint8 work_mode~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReportVehicleWorkMode)))
  "Returns full string definition for message of type 'ReportVehicleWorkMode"
  (cl:format cl:nil "uint8 work_mode~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReportVehicleWorkMode>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReportVehicleWorkMode>))
  "Converts a ROS message object to a list"
  (cl:list 'ReportVehicleWorkMode
    (cl:cons ':work_mode (work_mode msg))
))
