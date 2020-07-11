;; Auto-generated. Do not edit!


(when (boundp 'vertical_wall_grid::vertical_wall_grid)
  (if (not (find-package "VERTICAL_WALL_GRID"))
    (make-package "VERTICAL_WALL_GRID"))
  (shadow 'vertical_wall_grid (find-package "VERTICAL_WALL_GRID")))
(unless (find-package "VERTICAL_WALL_GRID::VERTICAL_WALL_GRID")
  (make-package "VERTICAL_WALL_GRID::VERTICAL_WALL_GRID"))

(in-package "ROS")
;;//! \htmlinclude vertical_wall_grid.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass vertical_wall_grid::vertical_wall_grid
  :super ros::object
  :slots (_header _detected _dis _angle _height _center _vertical ))

(defmethod vertical_wall_grid::vertical_wall_grid
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:detected __detected) nil)
    ((:dis __dis) 0.0)
    ((:angle __angle) 0.0)
    ((:height __height) 0.0)
    ((:center __center) (make-array 2 :initial-element 0.0 :element-type :float))
    ((:vertical __vertical) nil)
    )
   (send-super :init)
   (setq _header __header)
   (setq _detected __detected)
   (setq _dis (float __dis))
   (setq _angle (float __angle))
   (setq _height (float __height))
   (setq _center __center)
   (setq _vertical __vertical)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:detected
   (&optional __detected)
   (if __detected (setq _detected __detected)) _detected)
  (:dis
   (&optional __dis)
   (if __dis (setq _dis __dis)) _dis)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:center
   (&optional __center)
   (if __center (setq _center __center)) _center)
  (:vertical
   (&optional __vertical)
   (if __vertical (setq _vertical __vertical)) _vertical)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; bool _detected
    1
    ;; float32 _dis
    4
    ;; float32 _angle
    4
    ;; float32 _height
    4
    ;; float32[2] _center
    (* 4    2)
    ;; bool _vertical
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; bool _detected
       (if _detected (write-byte -1 s) (write-byte 0 s))
     ;; float32 _dis
       (sys::poke _dis (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _height
       (sys::poke _height (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32[2] _center
     (dotimes (i 2)
       (sys::poke (elt _center i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; bool _vertical
       (if _vertical (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; bool _detected
     (setq _detected (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _dis
     (setq _dis (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _angle
     (setq _angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _height
     (setq _height (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32[2] _center
   (dotimes (i (length _center))
     (setf (elt _center i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; bool _vertical
     (setq _vertical (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get vertical_wall_grid::vertical_wall_grid :md5sum-) "f060965c53a68944b55190b69cd4980c")
(setf (get vertical_wall_grid::vertical_wall_grid :datatype-) "vertical_wall_grid/vertical_wall_grid")
(setf (get vertical_wall_grid::vertical_wall_grid :definition-)
      "std_msgs/Header header
bool detected
float32 dis
float32 angle
float32 height
float32[2] center
bool vertical

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



(provide :vertical_wall_grid/vertical_wall_grid "f060965c53a68944b55190b69cd4980c")


