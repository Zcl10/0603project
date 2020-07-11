;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::ControlSteer)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'ControlSteer (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::CONTROLSTEER")
  (make-package "CONTROL_MSGS::CONTROLSTEER"))

(in-package "ROS")
;;//! \htmlinclude ControlSteer.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass control_msgs::ControlSteer
  :super ros::object
  :slots (_header _priority _steer ))

(defmethod control_msgs::ControlSteer
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:priority __priority) 0)
    ((:steer __steer) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _priority (round __priority))
   (setq _steer (float __steer))
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
  (:steer
   (&optional __steer)
   (if __steer (setq _steer __steer)) _steer)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _priority
    1
    ;; float64 _steer
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
     ;; float64 _steer
       (sys::poke _steer (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _priority
     (setq _priority (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _steer
     (setq _steer (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get control_msgs::ControlSteer :md5sum-) "169c822d498086ce7e8deec25291da54")
(setf (get control_msgs::ControlSteer :datatype-) "control_msgs/ControlSteer")
(setf (get control_msgs::ControlSteer :definition-)
      "Header header
uint8 priority
float64 steer


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



(provide :control_msgs/ControlSteer "169c822d498086ce7e8deec25291da54")


