;; Auto-generated. Do not edit!


(when (boundp 'plan2control_msgs::Trajectoryset)
  (if (not (find-package "PLAN2CONTROL_MSGS"))
    (make-package "PLAN2CONTROL_MSGS"))
  (shadow 'Trajectoryset (find-package "PLAN2CONTROL_MSGS")))
(unless (find-package "PLAN2CONTROL_MSGS::TRAJECTORYSET")
  (make-package "PLAN2CONTROL_MSGS::TRAJECTORYSET"))

(in-package "ROS")
;;//! \htmlinclude Trajectoryset.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass plan2control_msgs::Trajectoryset
  :super ros::object
  :slots (_header _trajectories _replansucceed ))

(defmethod plan2control_msgs::Trajectoryset
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:trajectories __trajectories) (let (r) (dotimes (i 0) (push (instance plan2control_msgs::Trajectory :init) r)) r))
    ((:replansucceed __replansucceed) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _trajectories __trajectories)
   (setq _replansucceed (round __replansucceed))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:trajectories
   (&rest __trajectories)
   (if (keywordp (car __trajectories))
       (send* _trajectories __trajectories)
     (progn
       (if __trajectories (setq _trajectories (car __trajectories)))
       _trajectories)))
  (:replansucceed
   (&optional __replansucceed)
   (if __replansucceed (setq _replansucceed __replansucceed)) _replansucceed)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; plan2control_msgs/Trajectory[] _trajectories
    (apply #'+ (send-all _trajectories :serialization-length)) 4
    ;; uint8 _replansucceed
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; plan2control_msgs/Trajectory[] _trajectories
     (write-long (length _trajectories) s)
     (dolist (elem _trajectories)
       (send elem :serialize s)
       )
     ;; uint8 _replansucceed
       (write-byte _replansucceed s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; plan2control_msgs/Trajectory[] _trajectories
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _trajectories (let (r) (dotimes (i n) (push (instance plan2control_msgs::Trajectory :init) r)) r))
     (dolist (elem- _trajectories)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; uint8 _replansucceed
     (setq _replansucceed (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get plan2control_msgs::Trajectoryset :md5sum-) "7baba054cf904a3e6277282e7d205c87")
(setf (get plan2control_msgs::Trajectoryset :datatype-) "plan2control_msgs/Trajectoryset")
(setf (get plan2control_msgs::Trajectoryset :definition-)
      "std_msgs/Header header
Trajectory[] trajectories
uint8 replansucceed

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
MSG: plan2control_msgs/Trajectory
std_msgs/Header header
Traj_Node[] points
float64 issued_acc
int32 delay_index

================================================================================
MSG: plan2control_msgs/Traj_Node
bool forward
int32 id
geometry_msgs/Point position
geometry_msgs/Quaternion orientation
float64 curvature
geometry_msgs/Twist velocity


================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :plan2control_msgs/Trajectoryset "7baba054cf904a3e6277282e7d205c87")


