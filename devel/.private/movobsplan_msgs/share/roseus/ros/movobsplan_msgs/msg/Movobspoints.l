;; Auto-generated. Do not edit!


(when (boundp 'movobsplan_msgs::Movobspoints)
  (if (not (find-package "MOVOBSPLAN_MSGS"))
    (make-package "MOVOBSPLAN_MSGS"))
  (shadow 'Movobspoints (find-package "MOVOBSPLAN_MSGS")))
(unless (find-package "MOVOBSPLAN_MSGS::MOVOBSPOINTS")
  (make-package "MOVOBSPLAN_MSGS::MOVOBSPOINTS"))

(in-package "ROS")
;;//! \htmlinclude Movobspoints.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass movobsplan_msgs::Movobspoints
  :super ros::object
  :slots (_header _dymipoints ))

(defmethod movobsplan_msgs::Movobspoints
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:dymipoints __dymipoints) (let (r) (dotimes (i 0) (push (instance movobsplan_msgs::Movobspoint :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _dymipoints __dymipoints)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:dymipoints
   (&rest __dymipoints)
   (if (keywordp (car __dymipoints))
       (send* _dymipoints __dymipoints)
     (progn
       (if __dymipoints (setq _dymipoints (car __dymipoints)))
       _dymipoints)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; movobsplan_msgs/Movobspoint[] _dymipoints
    (apply #'+ (send-all _dymipoints :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; movobsplan_msgs/Movobspoint[] _dymipoints
     (write-long (length _dymipoints) s)
     (dolist (elem _dymipoints)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; movobsplan_msgs/Movobspoint[] _dymipoints
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _dymipoints (let (r) (dotimes (i n) (push (instance movobsplan_msgs::Movobspoint :init) r)) r))
     (dolist (elem- _dymipoints)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get movobsplan_msgs::Movobspoints :md5sum-) "f332c1b2f057ff022a7fac3fdfcee363")
(setf (get movobsplan_msgs::Movobspoints :datatype-) "movobsplan_msgs/Movobspoints")
(setf (get movobsplan_msgs::Movobspoints :definition-)
      "std_msgs/Header header
Movobspoint[] dymipoints

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
MSG: movobsplan_msgs/Movobspoint
geometry_msgs/Point position


================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :movobsplan_msgs/Movobspoints "f332c1b2f057ff022a7fac3fdfcee363")


