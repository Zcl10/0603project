;; Auto-generated. Do not edit!


(when (boundp 'movobsplan_msgs::Movobspath)
  (if (not (find-package "MOVOBSPLAN_MSGS"))
    (make-package "MOVOBSPLAN_MSGS"))
  (shadow 'Movobspath (find-package "MOVOBSPLAN_MSGS")))
(unless (find-package "MOVOBSPLAN_MSGS::MOVOBSPATH")
  (make-package "MOVOBSPLAN_MSGS::MOVOBSPATH"))

(in-package "ROS")
;;//! \htmlinclude Movobspath.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass movobsplan_msgs::Movobspath
  :super ros::object
  :slots (_collision _penaltydepth _vel_to_dymicol _position ))

(defmethod movobsplan_msgs::Movobspath
  (:init
   (&key
    ((:collision __collision) 0)
    ((:penaltydepth __penaltydepth) 0.0)
    ((:vel_to_dymicol __vel_to_dymicol) 0.0)
    ((:position __position) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _collision (round __collision))
   (setq _penaltydepth (float __penaltydepth))
   (setq _vel_to_dymicol (float __vel_to_dymicol))
   (setq _position __position)
   self)
  (:collision
   (&optional __collision)
   (if __collision (setq _collision __collision)) _collision)
  (:penaltydepth
   (&optional __penaltydepth)
   (if __penaltydepth (setq _penaltydepth __penaltydepth)) _penaltydepth)
  (:vel_to_dymicol
   (&optional __vel_to_dymicol)
   (if __vel_to_dymicol (setq _vel_to_dymicol __vel_to_dymicol)) _vel_to_dymicol)
  (:position
   (&rest __position)
   (if (keywordp (car __position))
       (send* _position __position)
     (progn
       (if __position (setq _position (car __position)))
       _position)))
  (:serialization-length
   ()
   (+
    ;; uint8 _collision
    1
    ;; float64 _penaltydepth
    8
    ;; float64 _vel_to_dymicol
    8
    ;; geometry_msgs/Point _position
    (send _position :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _collision
       (write-byte _collision s)
     ;; float64 _penaltydepth
       (sys::poke _penaltydepth (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vel_to_dymicol
       (sys::poke _vel_to_dymicol (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; geometry_msgs/Point _position
       (send _position :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _collision
     (setq _collision (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _penaltydepth
     (setq _penaltydepth (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vel_to_dymicol
     (setq _vel_to_dymicol (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; geometry_msgs/Point _position
     (send _position :deserialize buf ptr-) (incf ptr- (send _position :serialization-length))
   ;;
   self)
  )

(setf (get movobsplan_msgs::Movobspath :md5sum-) "b91e4c47ca79497da4d13234e1f837d6")
(setf (get movobsplan_msgs::Movobspath :datatype-) "movobsplan_msgs/Movobspath")
(setf (get movobsplan_msgs::Movobspath :definition-)
      "uint8 collision
float64 penaltydepth
float64 vel_to_dymicol
geometry_msgs/Point position

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :movobsplan_msgs/Movobspath "b91e4c47ca79497da4d13234e1f837d6")


