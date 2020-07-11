;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::ReportMotion)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'ReportMotion (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::REPORTMOTION")
  (make-package "CONTROL_MSGS::REPORTMOTION"))

(in-package "ROS")
;;//! \htmlinclude ReportMotion.msg.html


(defclass control_msgs::ReportMotion
  :super ros::object
  :slots (_drive_mode _steer _gear _velocity ))

(defmethod control_msgs::ReportMotion
  (:init
   (&key
    ((:drive_mode __drive_mode) 0)
    ((:steer __steer) 0.0)
    ((:gear __gear) 0)
    ((:velocity __velocity) 0.0)
    )
   (send-super :init)
   (setq _drive_mode (round __drive_mode))
   (setq _steer (float __steer))
   (setq _gear (round __gear))
   (setq _velocity (float __velocity))
   self)
  (:drive_mode
   (&optional __drive_mode)
   (if __drive_mode (setq _drive_mode __drive_mode)) _drive_mode)
  (:steer
   (&optional __steer)
   (if __steer (setq _steer __steer)) _steer)
  (:gear
   (&optional __gear)
   (if __gear (setq _gear __gear)) _gear)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:serialization-length
   ()
   (+
    ;; uint8 _drive_mode
    1
    ;; float64 _steer
    8
    ;; uint8 _gear
    1
    ;; float64 _velocity
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _drive_mode
       (write-byte _drive_mode s)
     ;; float64 _steer
       (sys::poke _steer (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint8 _gear
       (write-byte _gear s)
     ;; float64 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _drive_mode
     (setq _drive_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _steer
     (setq _steer (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint8 _gear
     (setq _gear (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _velocity
     (setq _velocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get control_msgs::ReportMotion :md5sum-) "8a2097da0492d806d521147d3f4fe664")
(setf (get control_msgs::ReportMotion :datatype-) "control_msgs/ReportMotion")
(setf (get control_msgs::ReportMotion :definition-)
      "uint8 drive_mode
float64 steer
uint8 gear
float64 velocity



")



(provide :control_msgs/ReportMotion "8a2097da0492d806d521147d3f4fe664")


