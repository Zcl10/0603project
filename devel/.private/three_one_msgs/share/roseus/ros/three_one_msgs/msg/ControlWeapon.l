;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::ControlWeapon)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'ControlWeapon (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::CONTROLWEAPON")
  (make-package "THREE_ONE_MSGS::CONTROLWEAPON"))

(in-package "ROS")
;;//! \htmlinclude ControlWeapon.msg.html


(defclass three_one_msgs::ControlWeapon
  :super ros::object
  :slots (_priority _weapon_330 _weapon_28 _weapon_cmd ))

(defmethod three_one_msgs::ControlWeapon
  (:init
   (&key
    ((:priority __priority) 0)
    ((:weapon_330 __weapon_330) 0)
    ((:weapon_28 __weapon_28) 0)
    ((:weapon_cmd __weapon_cmd) 0)
    )
   (send-super :init)
   (setq _priority (round __priority))
   (setq _weapon_330 (round __weapon_330))
   (setq _weapon_28 (round __weapon_28))
   (setq _weapon_cmd (round __weapon_cmd))
   self)
  (:priority
   (&optional __priority)
   (if __priority (setq _priority __priority)) _priority)
  (:weapon_330
   (&optional __weapon_330)
   (if __weapon_330 (setq _weapon_330 __weapon_330)) _weapon_330)
  (:weapon_28
   (&optional __weapon_28)
   (if __weapon_28 (setq _weapon_28 __weapon_28)) _weapon_28)
  (:weapon_cmd
   (&optional __weapon_cmd)
   (if __weapon_cmd (setq _weapon_cmd __weapon_cmd)) _weapon_cmd)
  (:serialization-length
   ()
   (+
    ;; uint8 _priority
    1
    ;; uint8 _weapon_330
    1
    ;; uint8 _weapon_28
    1
    ;; uint8 _weapon_cmd
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _priority
       (write-byte _priority s)
     ;; uint8 _weapon_330
       (write-byte _weapon_330 s)
     ;; uint8 _weapon_28
       (write-byte _weapon_28 s)
     ;; uint8 _weapon_cmd
       (write-byte _weapon_cmd s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _priority
     (setq _priority (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _weapon_330
     (setq _weapon_330 (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _weapon_28
     (setq _weapon_28 (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _weapon_cmd
     (setq _weapon_cmd (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get three_one_msgs::ControlWeapon :md5sum-) "4cc1e4ec0b5615d8df21778e6fab18ae")
(setf (get three_one_msgs::ControlWeapon :datatype-) "three_one_msgs/ControlWeapon")
(setf (get three_one_msgs::ControlWeapon :definition-)
      "uint8 priority
uint8 weapon_330
uint8 weapon_28
uint8 weapon_cmd

")



(provide :three_one_msgs/ControlWeapon "4cc1e4ec0b5615d8df21778e6fab18ae")


