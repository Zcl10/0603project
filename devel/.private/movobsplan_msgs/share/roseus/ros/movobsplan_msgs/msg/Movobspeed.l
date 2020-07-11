;; Auto-generated. Do not edit!


(when (boundp 'movobsplan_msgs::Movobspeed)
  (if (not (find-package "MOVOBSPLAN_MSGS"))
    (make-package "MOVOBSPLAN_MSGS"))
  (shadow 'Movobspeed (find-package "MOVOBSPLAN_MSGS")))
(unless (find-package "MOVOBSPLAN_MSGS::MOVOBSPEED")
  (make-package "MOVOBSPLAN_MSGS::MOVOBSPEED"))

(in-package "ROS")
;;//! \htmlinclude Movobspeed.msg.html


(defclass movobsplan_msgs::Movobspeed
  :super ros::object
  :slots (_collision _exp_vel _exp_time _vel_to_dymicol ))

(defmethod movobsplan_msgs::Movobspeed
  (:init
   (&key
    ((:collision __collision) 0)
    ((:exp_vel __exp_vel) 0.0)
    ((:exp_time __exp_time) 0.0)
    ((:vel_to_dymicol __vel_to_dymicol) 0.0)
    )
   (send-super :init)
   (setq _collision (round __collision))
   (setq _exp_vel (float __exp_vel))
   (setq _exp_time (float __exp_time))
   (setq _vel_to_dymicol (float __vel_to_dymicol))
   self)
  (:collision
   (&optional __collision)
   (if __collision (setq _collision __collision)) _collision)
  (:exp_vel
   (&optional __exp_vel)
   (if __exp_vel (setq _exp_vel __exp_vel)) _exp_vel)
  (:exp_time
   (&optional __exp_time)
   (if __exp_time (setq _exp_time __exp_time)) _exp_time)
  (:vel_to_dymicol
   (&optional __vel_to_dymicol)
   (if __vel_to_dymicol (setq _vel_to_dymicol __vel_to_dymicol)) _vel_to_dymicol)
  (:serialization-length
   ()
   (+
    ;; uint8 _collision
    1
    ;; float64 _exp_vel
    8
    ;; float64 _exp_time
    8
    ;; float64 _vel_to_dymicol
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _collision
       (write-byte _collision s)
     ;; float64 _exp_vel
       (sys::poke _exp_vel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _exp_time
       (sys::poke _exp_time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vel_to_dymicol
       (sys::poke _vel_to_dymicol (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _collision
     (setq _collision (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _exp_vel
     (setq _exp_vel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _exp_time
     (setq _exp_time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vel_to_dymicol
     (setq _vel_to_dymicol (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get movobsplan_msgs::Movobspeed :md5sum-) "5e108d72b562baf3de0c61211ba4f831")
(setf (get movobsplan_msgs::Movobspeed :datatype-) "movobsplan_msgs/Movobspeed")
(setf (get movobsplan_msgs::Movobspeed :definition-)
      "uint8 collision
float64 exp_vel
float64 exp_time
float64 vel_to_dymicol

")



(provide :movobsplan_msgs/Movobspeed "5e108d72b562baf3de0c61211ba4f831")


