;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::Report)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'Report (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::REPORT")
  (make-package "CONTROL_MSGS::REPORT"))

(in-package "ROS")
;;//! \htmlinclude Report.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass control_msgs::Report
  :super ros::object
  :slots (_header _control _vcu_torque_brake _motion _brake _throttle _wheel _manual _vehicle_work_mode ))

(defmethod control_msgs::Report
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:control __control) (instance control_msgs::ReportControl :init))
    ((:vcu_torque_brake __vcu_torque_brake) (instance control_msgs::ReportControl :init))
    ((:motion __motion) (instance control_msgs::ReportMotion :init))
    ((:brake __brake) (instance control_msgs::ReportBrake :init))
    ((:throttle __throttle) (instance control_msgs::ReportThrottle :init))
    ((:wheel __wheel) (instance control_msgs::ReportWheel :init))
    ((:manual __manual) (instance control_msgs::ReportHMI :init))
    ((:vehicle_work_mode __vehicle_work_mode) (instance control_msgs::ReportVehicleWorkMode :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _control __control)
   (setq _vcu_torque_brake __vcu_torque_brake)
   (setq _motion __motion)
   (setq _brake __brake)
   (setq _throttle __throttle)
   (setq _wheel __wheel)
   (setq _manual __manual)
   (setq _vehicle_work_mode __vehicle_work_mode)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:control
   (&rest __control)
   (if (keywordp (car __control))
       (send* _control __control)
     (progn
       (if __control (setq _control (car __control)))
       _control)))
  (:vcu_torque_brake
   (&rest __vcu_torque_brake)
   (if (keywordp (car __vcu_torque_brake))
       (send* _vcu_torque_brake __vcu_torque_brake)
     (progn
       (if __vcu_torque_brake (setq _vcu_torque_brake (car __vcu_torque_brake)))
       _vcu_torque_brake)))
  (:motion
   (&rest __motion)
   (if (keywordp (car __motion))
       (send* _motion __motion)
     (progn
       (if __motion (setq _motion (car __motion)))
       _motion)))
  (:brake
   (&rest __brake)
   (if (keywordp (car __brake))
       (send* _brake __brake)
     (progn
       (if __brake (setq _brake (car __brake)))
       _brake)))
  (:throttle
   (&rest __throttle)
   (if (keywordp (car __throttle))
       (send* _throttle __throttle)
     (progn
       (if __throttle (setq _throttle (car __throttle)))
       _throttle)))
  (:wheel
   (&rest __wheel)
   (if (keywordp (car __wheel))
       (send* _wheel __wheel)
     (progn
       (if __wheel (setq _wheel (car __wheel)))
       _wheel)))
  (:manual
   (&rest __manual)
   (if (keywordp (car __manual))
       (send* _manual __manual)
     (progn
       (if __manual (setq _manual (car __manual)))
       _manual)))
  (:vehicle_work_mode
   (&rest __vehicle_work_mode)
   (if (keywordp (car __vehicle_work_mode))
       (send* _vehicle_work_mode __vehicle_work_mode)
     (progn
       (if __vehicle_work_mode (setq _vehicle_work_mode (car __vehicle_work_mode)))
       _vehicle_work_mode)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; control_msgs/ReportControl _control
    (send _control :serialization-length)
    ;; control_msgs/ReportControl _vcu_torque_brake
    (send _vcu_torque_brake :serialization-length)
    ;; control_msgs/ReportMotion _motion
    (send _motion :serialization-length)
    ;; control_msgs/ReportBrake _brake
    (send _brake :serialization-length)
    ;; control_msgs/ReportThrottle _throttle
    (send _throttle :serialization-length)
    ;; control_msgs/ReportWheel _wheel
    (send _wheel :serialization-length)
    ;; control_msgs/ReportHMI _manual
    (send _manual :serialization-length)
    ;; control_msgs/ReportVehicleWorkMode _vehicle_work_mode
    (send _vehicle_work_mode :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; control_msgs/ReportControl _control
       (send _control :serialize s)
     ;; control_msgs/ReportControl _vcu_torque_brake
       (send _vcu_torque_brake :serialize s)
     ;; control_msgs/ReportMotion _motion
       (send _motion :serialize s)
     ;; control_msgs/ReportBrake _brake
       (send _brake :serialize s)
     ;; control_msgs/ReportThrottle _throttle
       (send _throttle :serialize s)
     ;; control_msgs/ReportWheel _wheel
       (send _wheel :serialize s)
     ;; control_msgs/ReportHMI _manual
       (send _manual :serialize s)
     ;; control_msgs/ReportVehicleWorkMode _vehicle_work_mode
       (send _vehicle_work_mode :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; control_msgs/ReportControl _control
     (send _control :deserialize buf ptr-) (incf ptr- (send _control :serialization-length))
   ;; control_msgs/ReportControl _vcu_torque_brake
     (send _vcu_torque_brake :deserialize buf ptr-) (incf ptr- (send _vcu_torque_brake :serialization-length))
   ;; control_msgs/ReportMotion _motion
     (send _motion :deserialize buf ptr-) (incf ptr- (send _motion :serialization-length))
   ;; control_msgs/ReportBrake _brake
     (send _brake :deserialize buf ptr-) (incf ptr- (send _brake :serialization-length))
   ;; control_msgs/ReportThrottle _throttle
     (send _throttle :deserialize buf ptr-) (incf ptr- (send _throttle :serialization-length))
   ;; control_msgs/ReportWheel _wheel
     (send _wheel :deserialize buf ptr-) (incf ptr- (send _wheel :serialization-length))
   ;; control_msgs/ReportHMI _manual
     (send _manual :deserialize buf ptr-) (incf ptr- (send _manual :serialization-length))
   ;; control_msgs/ReportVehicleWorkMode _vehicle_work_mode
     (send _vehicle_work_mode :deserialize buf ptr-) (incf ptr- (send _vehicle_work_mode :serialization-length))
   ;;
   self)
  )

(setf (get control_msgs::Report :md5sum-) "0321a05248d872c4619e82c983a49c38")
(setf (get control_msgs::Report :datatype-) "control_msgs/Report")
(setf (get control_msgs::Report :definition-)
      "Header header
ReportControl control

ReportControl vcu_torque_brake

ReportMotion motion
ReportBrake brake
ReportThrottle throttle
ReportWheel wheel
ReportHMI manual
ReportVehicleWorkMode vehicle_work_mode 

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: control_msgs/ReportControl
ControlSpeed Speed
ControlSteer Steer
ControlMode ordermode


================================================================================
MSG: control_msgs/ControlSpeed
Header header
uint8 priority
uint8 gear
float64 speed
float64 acc
float64 torque
float64 brake

================================================================================
MSG: control_msgs/ControlSteer
Header header
uint8 priority
float64 steer


================================================================================
MSG: control_msgs/ControlMode
Header header
uint8 RainyLight



================================================================================
MSG: control_msgs/ReportMotion
uint8 drive_mode
float64 steer
uint8 gear
float64 velocity



================================================================================
MSG: control_msgs/ReportBrake
float64 left_pressure_back
float64 right_pressure_back
uint8 auto_park_state
uint8 auto_brake_enable
uint8 system_hot_warn
uint8 system_error_code
float64 left_pressure_set
float64 right_pressure_set
float32 brake_pedal

================================================================================
MSG: control_msgs/ReportThrottle
float32 throttle_opening
float32 throttle_pedal

================================================================================
MSG: control_msgs/ReportWheel
float32 front_left
float32 front_right
float32 rear_left
float32 rear_right
uint8 statusfl
uint8 statusfr
uint8 statusrl
uint8 statusrr

================================================================================
MSG: control_msgs/ReportHMI
uint8 manual_estop
uint8 is_human_brake 

================================================================================
MSG: control_msgs/ReportVehicleWorkMode
uint8 work_mode



")



(provide :control_msgs/Report "0321a05248d872c4619e82c983a49c38")


