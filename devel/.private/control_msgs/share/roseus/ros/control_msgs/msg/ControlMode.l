;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::ControlMode)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'ControlMode (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::CONTROLMODE")
  (make-package "CONTROL_MSGS::CONTROLMODE"))

(in-package "ROS")
;;//! \htmlinclude ControlMode.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass control_msgs::ControlMode
  :super ros::object
  :slots (_header _RainyLight ))

(defmethod control_msgs::ControlMode
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:RainyLight __RainyLight) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _RainyLight (round __RainyLight))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:RainyLight
   (&optional __RainyLight)
   (if __RainyLight (setq _RainyLight __RainyLight)) _RainyLight)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _RainyLight
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _RainyLight
       (write-byte _RainyLight s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _RainyLight
     (setq _RainyLight (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get control_msgs::ControlMode :md5sum-) "150f599fdfff8335bbe7a6c0f9766a68")
(setf (get control_msgs::ControlMode :datatype-) "control_msgs/ControlMode")
(setf (get control_msgs::ControlMode :definition-)
      "Header header
uint8 RainyLight



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



(provide :control_msgs/ControlMode "150f599fdfff8335bbe7a6c0f9766a68")


