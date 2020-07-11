;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::ReportWheel)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'ReportWheel (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::REPORTWHEEL")
  (make-package "CONTROL_MSGS::REPORTWHEEL"))

(in-package "ROS")
;;//! \htmlinclude ReportWheel.msg.html


(defclass control_msgs::ReportWheel
  :super ros::object
  :slots (_front_left _front_right _rear_left _rear_right _statusfl _statusfr _statusrl _statusrr ))

(defmethod control_msgs::ReportWheel
  (:init
   (&key
    ((:front_left __front_left) 0.0)
    ((:front_right __front_right) 0.0)
    ((:rear_left __rear_left) 0.0)
    ((:rear_right __rear_right) 0.0)
    ((:statusfl __statusfl) 0)
    ((:statusfr __statusfr) 0)
    ((:statusrl __statusrl) 0)
    ((:statusrr __statusrr) 0)
    )
   (send-super :init)
   (setq _front_left (float __front_left))
   (setq _front_right (float __front_right))
   (setq _rear_left (float __rear_left))
   (setq _rear_right (float __rear_right))
   (setq _statusfl (round __statusfl))
   (setq _statusfr (round __statusfr))
   (setq _statusrl (round __statusrl))
   (setq _statusrr (round __statusrr))
   self)
  (:front_left
   (&optional __front_left)
   (if __front_left (setq _front_left __front_left)) _front_left)
  (:front_right
   (&optional __front_right)
   (if __front_right (setq _front_right __front_right)) _front_right)
  (:rear_left
   (&optional __rear_left)
   (if __rear_left (setq _rear_left __rear_left)) _rear_left)
  (:rear_right
   (&optional __rear_right)
   (if __rear_right (setq _rear_right __rear_right)) _rear_right)
  (:statusfl
   (&optional __statusfl)
   (if __statusfl (setq _statusfl __statusfl)) _statusfl)
  (:statusfr
   (&optional __statusfr)
   (if __statusfr (setq _statusfr __statusfr)) _statusfr)
  (:statusrl
   (&optional __statusrl)
   (if __statusrl (setq _statusrl __statusrl)) _statusrl)
  (:statusrr
   (&optional __statusrr)
   (if __statusrr (setq _statusrr __statusrr)) _statusrr)
  (:serialization-length
   ()
   (+
    ;; float32 _front_left
    4
    ;; float32 _front_right
    4
    ;; float32 _rear_left
    4
    ;; float32 _rear_right
    4
    ;; uint8 _statusfl
    1
    ;; uint8 _statusfr
    1
    ;; uint8 _statusrl
    1
    ;; uint8 _statusrr
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _front_left
       (sys::poke _front_left (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _front_right
       (sys::poke _front_right (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _rear_left
       (sys::poke _rear_left (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _rear_right
       (sys::poke _rear_right (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8 _statusfl
       (write-byte _statusfl s)
     ;; uint8 _statusfr
       (write-byte _statusfr s)
     ;; uint8 _statusrl
       (write-byte _statusrl s)
     ;; uint8 _statusrr
       (write-byte _statusrr s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _front_left
     (setq _front_left (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _front_right
     (setq _front_right (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _rear_left
     (setq _rear_left (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _rear_right
     (setq _rear_right (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8 _statusfl
     (setq _statusfl (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _statusfr
     (setq _statusfr (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _statusrl
     (setq _statusrl (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _statusrr
     (setq _statusrr (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get control_msgs::ReportWheel :md5sum-) "c3a44de250eee4620714d052b512e107")
(setf (get control_msgs::ReportWheel :datatype-) "control_msgs/ReportWheel")
(setf (get control_msgs::ReportWheel :definition-)
      "float32 front_left
float32 front_right
float32 rear_left
float32 rear_right
uint8 statusfl
uint8 statusfr
uint8 statusrl
uint8 statusrr

")



(provide :control_msgs/ReportWheel "c3a44de250eee4620714d052b512e107")


