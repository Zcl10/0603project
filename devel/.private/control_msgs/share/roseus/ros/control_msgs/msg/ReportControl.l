;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::ReportControl)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'ReportControl (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::REPORTCONTROL")
  (make-package "CONTROL_MSGS::REPORTCONTROL"))

(in-package "ROS")
;;//! \htmlinclude ReportControl.msg.html


(defclass control_msgs::ReportControl
  :super ros::object
  :slots (_Speed _Steer _ordermode ))

(defmethod control_msgs::ReportControl
  (:init
   (&key
    ((:Speed __Speed) (instance control_msgs::ControlSpeed :init))
    ((:Steer __Steer) (instance control_msgs::ControlSteer :init))
    ((:ordermode __ordermode) (instance control_msgs::ControlMode :init))
    )
   (send-super :init)
   (setq _Speed __Speed)
   (setq _Steer __Steer)
   (setq _ordermode __ordermode)
   self)
  (:Speed
   (&rest __Speed)
   (if (keywordp (car __Speed))
       (send* _Speed __Speed)
     (progn
       (if __Speed (setq _Speed (car __Speed)))
       _Speed)))
  (:Steer
   (&rest __Steer)
   (if (keywordp (car __Steer))
       (send* _Steer __Steer)
     (progn
       (if __Steer (setq _Steer (car __Steer)))
       _Steer)))
  (:ordermode
   (&rest __ordermode)
   (if (keywordp (car __ordermode))
       (send* _ordermode __ordermode)
     (progn
       (if __ordermode (setq _ordermode (car __ordermode)))
       _ordermode)))
  (:serialization-length
   ()
   (+
    ;; control_msgs/ControlSpeed _Speed
    (send _Speed :serialization-length)
    ;; control_msgs/ControlSteer _Steer
    (send _Steer :serialization-length)
    ;; control_msgs/ControlMode _ordermode
    (send _ordermode :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; control_msgs/ControlSpeed _Speed
       (send _Speed :serialize s)
     ;; control_msgs/ControlSteer _Steer
       (send _Steer :serialize s)
     ;; control_msgs/ControlMode _ordermode
       (send _ordermode :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; control_msgs/ControlSpeed _Speed
     (send _Speed :deserialize buf ptr-) (incf ptr- (send _Speed :serialization-length))
   ;; control_msgs/ControlSteer _Steer
     (send _Steer :deserialize buf ptr-) (incf ptr- (send _Steer :serialization-length))
   ;; control_msgs/ControlMode _ordermode
     (send _ordermode :deserialize buf ptr-) (incf ptr- (send _ordermode :serialization-length))
   ;;
   self)
  )

(setf (get control_msgs::ReportControl :md5sum-) "4cfa3145374ffabe5a1139ad8f40e485")
(setf (get control_msgs::ReportControl :datatype-) "control_msgs/ReportControl")
(setf (get control_msgs::ReportControl :definition-)
      "ControlSpeed Speed
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
MSG: control_msgs/ControlSteer
Header header
uint8 priority
float64 steer


================================================================================
MSG: control_msgs/ControlMode
Header header
uint8 RainyLight



")



(provide :control_msgs/ReportControl "4cfa3145374ffabe5a1139ad8f40e485")


