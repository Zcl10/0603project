;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::ControlSpeed)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'ControlSpeed (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::CONTROLSPEED")
  (make-package "CONTROL_MSGS::CONTROLSPEED"))

(in-package "ROS")
;;//! \htmlinclude ControlSpeed.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass control_msgs::ControlSpeed
  :super ros::object
  :slots (_header _priority _gear _speed _acc _torque _brake ))

(defmethod control_msgs::ControlSpeed
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:priority __priority) 0)
    ((:gear __gear) 0)
    ((:speed __speed) 0.0)
    ((:acc __acc) 0.0)
    ((:torque __torque) 0.0)
    ((:brake __brake) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _priority (round __priority))
   (setq _gear (round __gear))
   (setq _speed (float __speed))
   (setq _acc (float __acc))
   (setq _torque (float __torque))
   (setq _brake (float __brake))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:priority
   (&optional __priority)
   (if __priority (setq _priority __priority)) _priority)
  (:gear
   (&optional __gear)
   (if __gear (setq _gear __gear)) _gear)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:acc
   (&optional __acc)
   (if __acc (setq _acc __acc)) _acc)
  (:torque
   (&optional __torque)
   (if __torque (setq _torque __torque)) _torque)
  (:brake
   (&optional __brake)
   (if __brake (setq _brake __brake)) _brake)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _priority
    1
    ;; uint8 _gear
    1
    ;; float64 _speed
    8
    ;; float64 _acc
    8
    ;; float64 _torque
    8
    ;; float64 _brake
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _priority
       (write-byte _priority s)
     ;; uint8 _gear
       (write-byte _gear s)
     ;; float64 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _acc
       (sys::poke _acc (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _torque
       (sys::poke _torque (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _brake
       (sys::poke _brake (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _priority
     (setq _priority (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _gear
     (setq _gear (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _speed
     (setq _speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _acc
     (setq _acc (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _torque
     (setq _torque (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _brake
     (setq _brake (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get control_msgs::ControlSpeed :md5sum-) "c33d47e548336f34d9a633e1ea676a97")
(setf (get control_msgs::ControlSpeed :datatype-) "control_msgs/ControlSpeed")
(setf (get control_msgs::ControlSpeed :definition-)
      "Header header
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

")



(provide :control_msgs/ControlSpeed "c33d47e548336f34d9a633e1ea676a97")


