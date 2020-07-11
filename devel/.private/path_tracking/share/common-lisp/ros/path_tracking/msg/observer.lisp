; Auto-generated. Do not edit!


(cl:in-package path_tracking-msg)


;//! \htmlinclude observer.msg.html

(cl:defclass <observer> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (vehicle_state
    :reader vehicle_state
    :initarg :vehicle_state
    :type anm_msgs-msg:VehicleState
    :initform (cl:make-instance 'anm_msgs-msg:VehicleState))
   (ecu_report
    :reader ecu_report
    :initarg :ecu_report
    :type control_msgs-msg:Report
    :initform (cl:make-instance 'control_msgs-msg:Report))
   (speed_cmd
    :reader speed_cmd
    :initarg :speed_cmd
    :type cl:float
    :initform 0.0)
   (steer_cmd
    :reader steer_cmd
    :initarg :steer_cmd
    :type cl:float
    :initform 0.0)
   (lateral_error
    :reader lateral_error
    :initarg :lateral_error
    :type cl:float
    :initform 0.0)
   (heading_error
    :reader heading_error
    :initarg :heading_error
    :type cl:float
    :initform 0.0)
   (time_cost
    :reader time_cost
    :initarg :time_cost
    :type cl:float
    :initform 0.0))
)

(cl:defclass observer (<observer>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <observer>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'observer)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name path_tracking-msg:<observer> is deprecated: use path_tracking-msg:observer instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <observer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:header-val is deprecated.  Use path_tracking-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'vehicle_state-val :lambda-list '(m))
(cl:defmethod vehicle_state-val ((m <observer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:vehicle_state-val is deprecated.  Use path_tracking-msg:vehicle_state instead.")
  (vehicle_state m))

(cl:ensure-generic-function 'ecu_report-val :lambda-list '(m))
(cl:defmethod ecu_report-val ((m <observer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:ecu_report-val is deprecated.  Use path_tracking-msg:ecu_report instead.")
  (ecu_report m))

(cl:ensure-generic-function 'speed_cmd-val :lambda-list '(m))
(cl:defmethod speed_cmd-val ((m <observer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:speed_cmd-val is deprecated.  Use path_tracking-msg:speed_cmd instead.")
  (speed_cmd m))

(cl:ensure-generic-function 'steer_cmd-val :lambda-list '(m))
(cl:defmethod steer_cmd-val ((m <observer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:steer_cmd-val is deprecated.  Use path_tracking-msg:steer_cmd instead.")
  (steer_cmd m))

(cl:ensure-generic-function 'lateral_error-val :lambda-list '(m))
(cl:defmethod lateral_error-val ((m <observer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:lateral_error-val is deprecated.  Use path_tracking-msg:lateral_error instead.")
  (lateral_error m))

(cl:ensure-generic-function 'heading_error-val :lambda-list '(m))
(cl:defmethod heading_error-val ((m <observer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:heading_error-val is deprecated.  Use path_tracking-msg:heading_error instead.")
  (heading_error m))

(cl:ensure-generic-function 'time_cost-val :lambda-list '(m))
(cl:defmethod time_cost-val ((m <observer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_tracking-msg:time_cost-val is deprecated.  Use path_tracking-msg:time_cost instead.")
  (time_cost m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <observer>) ostream)
  "Serializes a message object of type '<observer>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vehicle_state) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ecu_report) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'speed_cmd))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'steer_cmd))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'lateral_error))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'heading_error))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time_cost))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <observer>) istream)
  "Deserializes a message object of type '<observer>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vehicle_state) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ecu_report) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed_cmd) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'steer_cmd) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lateral_error) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'heading_error) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time_cost) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<observer>)))
  "Returns string type for a message object of type '<observer>"
  "path_tracking/observer")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'observer)))
  "Returns string type for a message object of type 'observer"
  "path_tracking/observer")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<observer>)))
  "Returns md5sum for a message object of type '<observer>"
  "5f683c55d076db2e680be51e6dee7354")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'observer)))
  "Returns md5sum for a message object of type 'observer"
  "5f683c55d076db2e680be51e6dee7354")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<observer>)))
  "Returns full string definition for message of type '<observer>"
  (cl:format cl:nil "Header header~%~%anm_msgs/VehicleState vehicle_state~%control_msgs/Report ecu_report~%float64 speed_cmd~%float64 steer_cmd~%float64 lateral_error~%float64 heading_error~%float64 time_cost~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: anm_msgs/VehicleState~%# This message describes the complete vehicle state~%# orientation = orientation of the vehicle using euler angles~%~%Header header~%string child_frame_id~%~%geometry_msgs/Point position~%geometry_msgs/Vector3 orientation~%geometry_msgs/Twist velocity~%geometry_msgs/Twist acceleration~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: control_msgs/Report~%Header header~%ReportControl control~%~%ReportControl vcu_torque_brake~%~%ReportMotion motion~%ReportBrake brake~%ReportThrottle throttle~%ReportWheel wheel~%ReportHMI manual~%ReportVehicleWorkMode vehicle_work_mode ~%~%================================================================================~%MSG: control_msgs/ReportControl~%ControlSpeed Speed~%ControlSteer Steer~%ControlMode ordermode~%~%~%================================================================================~%MSG: control_msgs/ControlSpeed~%Header header~%uint8 priority~%uint8 gear~%float64 speed~%float64 acc~%float64 torque~%float64 brake~%~%================================================================================~%MSG: control_msgs/ControlSteer~%Header header~%uint8 priority~%float64 steer~%~%~%================================================================================~%MSG: control_msgs/ControlMode~%Header header~%uint8 RainyLight~%~%~%~%================================================================================~%MSG: control_msgs/ReportMotion~%uint8 drive_mode~%float64 steer~%uint8 gear~%float64 velocity~%~%~%~%================================================================================~%MSG: control_msgs/ReportBrake~%float64 left_pressure_back~%float64 right_pressure_back~%uint8 auto_park_state~%uint8 auto_brake_enable~%uint8 system_hot_warn~%uint8 system_error_code~%float64 left_pressure_set~%float64 right_pressure_set~%float32 brake_pedal~%~%================================================================================~%MSG: control_msgs/ReportThrottle~%float32 throttle_opening~%float32 throttle_pedal~%~%================================================================================~%MSG: control_msgs/ReportWheel~%float32 front_left~%float32 front_right~%float32 rear_left~%float32 rear_right~%uint8 statusfl~%uint8 statusfr~%uint8 statusrl~%uint8 statusrr~%~%================================================================================~%MSG: control_msgs/ReportHMI~%uint8 manual_estop~%uint8 is_human_brake ~%~%================================================================================~%MSG: control_msgs/ReportVehicleWorkMode~%uint8 work_mode~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'observer)))
  "Returns full string definition for message of type 'observer"
  (cl:format cl:nil "Header header~%~%anm_msgs/VehicleState vehicle_state~%control_msgs/Report ecu_report~%float64 speed_cmd~%float64 steer_cmd~%float64 lateral_error~%float64 heading_error~%float64 time_cost~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: anm_msgs/VehicleState~%# This message describes the complete vehicle state~%# orientation = orientation of the vehicle using euler angles~%~%Header header~%string child_frame_id~%~%geometry_msgs/Point position~%geometry_msgs/Vector3 orientation~%geometry_msgs/Twist velocity~%geometry_msgs/Twist acceleration~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: control_msgs/Report~%Header header~%ReportControl control~%~%ReportControl vcu_torque_brake~%~%ReportMotion motion~%ReportBrake brake~%ReportThrottle throttle~%ReportWheel wheel~%ReportHMI manual~%ReportVehicleWorkMode vehicle_work_mode ~%~%================================================================================~%MSG: control_msgs/ReportControl~%ControlSpeed Speed~%ControlSteer Steer~%ControlMode ordermode~%~%~%================================================================================~%MSG: control_msgs/ControlSpeed~%Header header~%uint8 priority~%uint8 gear~%float64 speed~%float64 acc~%float64 torque~%float64 brake~%~%================================================================================~%MSG: control_msgs/ControlSteer~%Header header~%uint8 priority~%float64 steer~%~%~%================================================================================~%MSG: control_msgs/ControlMode~%Header header~%uint8 RainyLight~%~%~%~%================================================================================~%MSG: control_msgs/ReportMotion~%uint8 drive_mode~%float64 steer~%uint8 gear~%float64 velocity~%~%~%~%================================================================================~%MSG: control_msgs/ReportBrake~%float64 left_pressure_back~%float64 right_pressure_back~%uint8 auto_park_state~%uint8 auto_brake_enable~%uint8 system_hot_warn~%uint8 system_error_code~%float64 left_pressure_set~%float64 right_pressure_set~%float32 brake_pedal~%~%================================================================================~%MSG: control_msgs/ReportThrottle~%float32 throttle_opening~%float32 throttle_pedal~%~%================================================================================~%MSG: control_msgs/ReportWheel~%float32 front_left~%float32 front_right~%float32 rear_left~%float32 rear_right~%uint8 statusfl~%uint8 statusfr~%uint8 statusrl~%uint8 statusrr~%~%================================================================================~%MSG: control_msgs/ReportHMI~%uint8 manual_estop~%uint8 is_human_brake ~%~%================================================================================~%MSG: control_msgs/ReportVehicleWorkMode~%uint8 work_mode~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <observer>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vehicle_state))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ecu_report))
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <observer>))
  "Converts a ROS message object to a list"
  (cl:list 'observer
    (cl:cons ':header (header msg))
    (cl:cons ':vehicle_state (vehicle_state msg))
    (cl:cons ':ecu_report (ecu_report msg))
    (cl:cons ':speed_cmd (speed_cmd msg))
    (cl:cons ':steer_cmd (steer_cmd msg))
    (cl:cons ':lateral_error (lateral_error msg))
    (cl:cons ':heading_error (heading_error msg))
    (cl:cons ':time_cost (time_cost msg))
))
