; Auto-generated. Do not edit!


(cl:in-package control_msgs-msg)


;//! \htmlinclude Report.msg.html

(cl:defclass <Report> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (control
    :reader control
    :initarg :control
    :type control_msgs-msg:ReportControl
    :initform (cl:make-instance 'control_msgs-msg:ReportControl))
   (vcu_torque_brake
    :reader vcu_torque_brake
    :initarg :vcu_torque_brake
    :type control_msgs-msg:ReportControl
    :initform (cl:make-instance 'control_msgs-msg:ReportControl))
   (motion
    :reader motion
    :initarg :motion
    :type control_msgs-msg:ReportMotion
    :initform (cl:make-instance 'control_msgs-msg:ReportMotion))
   (brake
    :reader brake
    :initarg :brake
    :type control_msgs-msg:ReportBrake
    :initform (cl:make-instance 'control_msgs-msg:ReportBrake))
   (throttle
    :reader throttle
    :initarg :throttle
    :type control_msgs-msg:ReportThrottle
    :initform (cl:make-instance 'control_msgs-msg:ReportThrottle))
   (wheel
    :reader wheel
    :initarg :wheel
    :type control_msgs-msg:ReportWheel
    :initform (cl:make-instance 'control_msgs-msg:ReportWheel))
   (manual
    :reader manual
    :initarg :manual
    :type control_msgs-msg:ReportHMI
    :initform (cl:make-instance 'control_msgs-msg:ReportHMI))
   (vehicle_work_mode
    :reader vehicle_work_mode
    :initarg :vehicle_work_mode
    :type control_msgs-msg:ReportVehicleWorkMode
    :initform (cl:make-instance 'control_msgs-msg:ReportVehicleWorkMode)))
)

(cl:defclass Report (<Report>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Report>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Report)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_msgs-msg:<Report> is deprecated: use control_msgs-msg:Report instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:header-val is deprecated.  Use control_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'control-val :lambda-list '(m))
(cl:defmethod control-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:control-val is deprecated.  Use control_msgs-msg:control instead.")
  (control m))

(cl:ensure-generic-function 'vcu_torque_brake-val :lambda-list '(m))
(cl:defmethod vcu_torque_brake-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:vcu_torque_brake-val is deprecated.  Use control_msgs-msg:vcu_torque_brake instead.")
  (vcu_torque_brake m))

(cl:ensure-generic-function 'motion-val :lambda-list '(m))
(cl:defmethod motion-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:motion-val is deprecated.  Use control_msgs-msg:motion instead.")
  (motion m))

(cl:ensure-generic-function 'brake-val :lambda-list '(m))
(cl:defmethod brake-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:brake-val is deprecated.  Use control_msgs-msg:brake instead.")
  (brake m))

(cl:ensure-generic-function 'throttle-val :lambda-list '(m))
(cl:defmethod throttle-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:throttle-val is deprecated.  Use control_msgs-msg:throttle instead.")
  (throttle m))

(cl:ensure-generic-function 'wheel-val :lambda-list '(m))
(cl:defmethod wheel-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:wheel-val is deprecated.  Use control_msgs-msg:wheel instead.")
  (wheel m))

(cl:ensure-generic-function 'manual-val :lambda-list '(m))
(cl:defmethod manual-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:manual-val is deprecated.  Use control_msgs-msg:manual instead.")
  (manual m))

(cl:ensure-generic-function 'vehicle_work_mode-val :lambda-list '(m))
(cl:defmethod vehicle_work_mode-val ((m <Report>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:vehicle_work_mode-val is deprecated.  Use control_msgs-msg:vehicle_work_mode instead.")
  (vehicle_work_mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Report>) ostream)
  "Serializes a message object of type '<Report>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'control) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vcu_torque_brake) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'motion) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'brake) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'throttle) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'wheel) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'manual) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vehicle_work_mode) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Report>) istream)
  "Deserializes a message object of type '<Report>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'control) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vcu_torque_brake) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'motion) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'brake) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'throttle) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'wheel) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'manual) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vehicle_work_mode) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Report>)))
  "Returns string type for a message object of type '<Report>"
  "control_msgs/Report")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Report)))
  "Returns string type for a message object of type 'Report"
  "control_msgs/Report")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Report>)))
  "Returns md5sum for a message object of type '<Report>"
  "0321a05248d872c4619e82c983a49c38")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Report)))
  "Returns md5sum for a message object of type 'Report"
  "0321a05248d872c4619e82c983a49c38")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Report>)))
  "Returns full string definition for message of type '<Report>"
  (cl:format cl:nil "Header header~%ReportControl control~%~%ReportControl vcu_torque_brake~%~%ReportMotion motion~%ReportBrake brake~%ReportThrottle throttle~%ReportWheel wheel~%ReportHMI manual~%ReportVehicleWorkMode vehicle_work_mode ~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: control_msgs/ReportControl~%ControlSpeed Speed~%ControlSteer Steer~%ControlMode ordermode~%~%~%================================================================================~%MSG: control_msgs/ControlSpeed~%Header header~%uint8 priority~%uint8 gear~%float64 speed~%float64 acc~%float64 torque~%float64 brake~%~%================================================================================~%MSG: control_msgs/ControlSteer~%Header header~%uint8 priority~%float64 steer~%~%~%================================================================================~%MSG: control_msgs/ControlMode~%Header header~%uint8 RainyLight~%~%~%~%================================================================================~%MSG: control_msgs/ReportMotion~%uint8 drive_mode~%float64 steer~%uint8 gear~%float64 velocity~%~%~%~%================================================================================~%MSG: control_msgs/ReportBrake~%float64 left_pressure_back~%float64 right_pressure_back~%uint8 auto_park_state~%uint8 auto_brake_enable~%uint8 system_hot_warn~%uint8 system_error_code~%float64 left_pressure_set~%float64 right_pressure_set~%float32 brake_pedal~%~%================================================================================~%MSG: control_msgs/ReportThrottle~%float32 throttle_opening~%float32 throttle_pedal~%~%================================================================================~%MSG: control_msgs/ReportWheel~%float32 front_left~%float32 front_right~%float32 rear_left~%float32 rear_right~%uint8 statusfl~%uint8 statusfr~%uint8 statusrl~%uint8 statusrr~%~%================================================================================~%MSG: control_msgs/ReportHMI~%uint8 manual_estop~%uint8 is_human_brake ~%~%================================================================================~%MSG: control_msgs/ReportVehicleWorkMode~%uint8 work_mode~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Report)))
  "Returns full string definition for message of type 'Report"
  (cl:format cl:nil "Header header~%ReportControl control~%~%ReportControl vcu_torque_brake~%~%ReportMotion motion~%ReportBrake brake~%ReportThrottle throttle~%ReportWheel wheel~%ReportHMI manual~%ReportVehicleWorkMode vehicle_work_mode ~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: control_msgs/ReportControl~%ControlSpeed Speed~%ControlSteer Steer~%ControlMode ordermode~%~%~%================================================================================~%MSG: control_msgs/ControlSpeed~%Header header~%uint8 priority~%uint8 gear~%float64 speed~%float64 acc~%float64 torque~%float64 brake~%~%================================================================================~%MSG: control_msgs/ControlSteer~%Header header~%uint8 priority~%float64 steer~%~%~%================================================================================~%MSG: control_msgs/ControlMode~%Header header~%uint8 RainyLight~%~%~%~%================================================================================~%MSG: control_msgs/ReportMotion~%uint8 drive_mode~%float64 steer~%uint8 gear~%float64 velocity~%~%~%~%================================================================================~%MSG: control_msgs/ReportBrake~%float64 left_pressure_back~%float64 right_pressure_back~%uint8 auto_park_state~%uint8 auto_brake_enable~%uint8 system_hot_warn~%uint8 system_error_code~%float64 left_pressure_set~%float64 right_pressure_set~%float32 brake_pedal~%~%================================================================================~%MSG: control_msgs/ReportThrottle~%float32 throttle_opening~%float32 throttle_pedal~%~%================================================================================~%MSG: control_msgs/ReportWheel~%float32 front_left~%float32 front_right~%float32 rear_left~%float32 rear_right~%uint8 statusfl~%uint8 statusfr~%uint8 statusrl~%uint8 statusrr~%~%================================================================================~%MSG: control_msgs/ReportHMI~%uint8 manual_estop~%uint8 is_human_brake ~%~%================================================================================~%MSG: control_msgs/ReportVehicleWorkMode~%uint8 work_mode~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Report>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'control))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vcu_torque_brake))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'motion))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'brake))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'throttle))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'wheel))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'manual))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vehicle_work_mode))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Report>))
  "Converts a ROS message object to a list"
  (cl:list 'Report
    (cl:cons ':header (header msg))
    (cl:cons ':control (control msg))
    (cl:cons ':vcu_torque_brake (vcu_torque_brake msg))
    (cl:cons ':motion (motion msg))
    (cl:cons ':brake (brake msg))
    (cl:cons ':throttle (throttle msg))
    (cl:cons ':wheel (wheel msg))
    (cl:cons ':manual (manual msg))
    (cl:cons ':vehicle_work_mode (vehicle_work_mode msg))
))
