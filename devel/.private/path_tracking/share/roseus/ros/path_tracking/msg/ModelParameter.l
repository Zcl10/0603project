;; Auto-generated. Do not edit!


(when (boundp 'path_tracking::ModelParameter)
  (if (not (find-package "PATH_TRACKING"))
    (make-package "PATH_TRACKING"))
  (shadow 'ModelParameter (find-package "PATH_TRACKING")))
(unless (find-package "PATH_TRACKING::MODELPARAMETER")
  (make-package "PATH_TRACKING::MODELPARAMETER"))

(in-package "ROS")
;;//! \htmlinclude ModelParameter.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass path_tracking::ModelParameter
  :super ros::object
  :slots (_header _speed_parameter _steer_parameter _time_cost ))

(defmethod path_tracking::ModelParameter
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:speed_parameter __speed_parameter) 0.0)
    ((:steer_parameter __steer_parameter) 0.0)
    ((:time_cost __time_cost) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _speed_parameter (float __speed_parameter))
   (setq _steer_parameter (float __steer_parameter))
   (setq _time_cost (float __time_cost))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:speed_parameter
   (&optional __speed_parameter)
   (if __speed_parameter (setq _speed_parameter __speed_parameter)) _speed_parameter)
  (:steer_parameter
   (&optional __steer_parameter)
   (if __steer_parameter (setq _steer_parameter __steer_parameter)) _steer_parameter)
  (:time_cost
   (&optional __time_cost)
   (if __time_cost (setq _time_cost __time_cost)) _time_cost)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _speed_parameter
    8
    ;; float64 _steer_parameter
    8
    ;; float64 _time_cost
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _speed_parameter
       (sys::poke _speed_parameter (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _steer_parameter
       (sys::poke _steer_parameter (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _time_cost
       (sys::poke _time_cost (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _speed_parameter
     (setq _speed_parameter (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _steer_parameter
     (setq _steer_parameter (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _time_cost
     (setq _time_cost (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get path_tracking::ModelParameter :md5sum-) "564bf96590ff731beab91211a6911188")
(setf (get path_tracking::ModelParameter :datatype-) "path_tracking/ModelParameter")
(setf (get path_tracking::ModelParameter :definition-)
      "Header header

float64 speed_parameter
float64 steer_parameter
float64 time_cost

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



(provide :path_tracking/ModelParameter "564bf96590ff731beab91211a6911188")


