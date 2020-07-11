;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::ControlSuspension)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'ControlSuspension (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::CONTROLSUSPENSION")
  (make-package "THREE_ONE_MSGS::CONTROLSUSPENSION"))

(in-package "ROS")
;;//! \htmlinclude ControlSuspension.msg.html


(defclass three_one_msgs::ControlSuspension
  :super ros::object
  :slots (_priority _cylinder_select _suspension_select _suspension_work_mode _suspension_work_mode_detail _suspension_cylinder_select_mode _suspension_cylinder_motor_control _vertical_wall_mode _fix_two_chamber_valve _entrenchment ))

(defmethod three_one_msgs::ControlSuspension
  (:init
   (&key
    ((:priority __priority) 0)
    ((:cylinder_select __cylinder_select) 0)
    ((:suspension_select __suspension_select) 0)
    ((:suspension_work_mode __suspension_work_mode) 0)
    ((:suspension_work_mode_detail __suspension_work_mode_detail) 0)
    ((:suspension_cylinder_select_mode __suspension_cylinder_select_mode) 0)
    ((:suspension_cylinder_motor_control __suspension_cylinder_motor_control) 0)
    ((:vertical_wall_mode __vertical_wall_mode) 0)
    ((:fix_two_chamber_valve __fix_two_chamber_valve) 0)
    ((:entrenchment __entrenchment) 0)
    )
   (send-super :init)
   (setq _priority (round __priority))
   (setq _cylinder_select (round __cylinder_select))
   (setq _suspension_select (round __suspension_select))
   (setq _suspension_work_mode (round __suspension_work_mode))
   (setq _suspension_work_mode_detail (round __suspension_work_mode_detail))
   (setq _suspension_cylinder_select_mode (round __suspension_cylinder_select_mode))
   (setq _suspension_cylinder_motor_control (round __suspension_cylinder_motor_control))
   (setq _vertical_wall_mode (round __vertical_wall_mode))
   (setq _fix_two_chamber_valve (round __fix_two_chamber_valve))
   (setq _entrenchment (round __entrenchment))
   self)
  (:priority
   (&optional __priority)
   (if __priority (setq _priority __priority)) _priority)
  (:cylinder_select
   (&optional __cylinder_select)
   (if __cylinder_select (setq _cylinder_select __cylinder_select)) _cylinder_select)
  (:suspension_select
   (&optional __suspension_select)
   (if __suspension_select (setq _suspension_select __suspension_select)) _suspension_select)
  (:suspension_work_mode
   (&optional __suspension_work_mode)
   (if __suspension_work_mode (setq _suspension_work_mode __suspension_work_mode)) _suspension_work_mode)
  (:suspension_work_mode_detail
   (&optional __suspension_work_mode_detail)
   (if __suspension_work_mode_detail (setq _suspension_work_mode_detail __suspension_work_mode_detail)) _suspension_work_mode_detail)
  (:suspension_cylinder_select_mode
   (&optional __suspension_cylinder_select_mode)
   (if __suspension_cylinder_select_mode (setq _suspension_cylinder_select_mode __suspension_cylinder_select_mode)) _suspension_cylinder_select_mode)
  (:suspension_cylinder_motor_control
   (&optional __suspension_cylinder_motor_control)
   (if __suspension_cylinder_motor_control (setq _suspension_cylinder_motor_control __suspension_cylinder_motor_control)) _suspension_cylinder_motor_control)
  (:vertical_wall_mode
   (&optional __vertical_wall_mode)
   (if __vertical_wall_mode (setq _vertical_wall_mode __vertical_wall_mode)) _vertical_wall_mode)
  (:fix_two_chamber_valve
   (&optional __fix_two_chamber_valve)
   (if __fix_two_chamber_valve (setq _fix_two_chamber_valve __fix_two_chamber_valve)) _fix_two_chamber_valve)
  (:entrenchment
   (&optional __entrenchment)
   (if __entrenchment (setq _entrenchment __entrenchment)) _entrenchment)
  (:serialization-length
   ()
   (+
    ;; uint8 _priority
    1
    ;; uint8 _cylinder_select
    1
    ;; uint8 _suspension_select
    1
    ;; uint8 _suspension_work_mode
    1
    ;; uint8 _suspension_work_mode_detail
    1
    ;; uint8 _suspension_cylinder_select_mode
    1
    ;; uint8 _suspension_cylinder_motor_control
    1
    ;; uint8 _vertical_wall_mode
    1
    ;; uint8 _fix_two_chamber_valve
    1
    ;; uint8 _entrenchment
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _priority
       (write-byte _priority s)
     ;; uint8 _cylinder_select
       (write-byte _cylinder_select s)
     ;; uint8 _suspension_select
       (write-byte _suspension_select s)
     ;; uint8 _suspension_work_mode
       (write-byte _suspension_work_mode s)
     ;; uint8 _suspension_work_mode_detail
       (write-byte _suspension_work_mode_detail s)
     ;; uint8 _suspension_cylinder_select_mode
       (write-byte _suspension_cylinder_select_mode s)
     ;; uint8 _suspension_cylinder_motor_control
       (write-byte _suspension_cylinder_motor_control s)
     ;; uint8 _vertical_wall_mode
       (write-byte _vertical_wall_mode s)
     ;; uint8 _fix_two_chamber_valve
       (write-byte _fix_two_chamber_valve s)
     ;; uint8 _entrenchment
       (write-byte _entrenchment s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _priority
     (setq _priority (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _cylinder_select
     (setq _cylinder_select (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _suspension_select
     (setq _suspension_select (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _suspension_work_mode
     (setq _suspension_work_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _suspension_work_mode_detail
     (setq _suspension_work_mode_detail (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _suspension_cylinder_select_mode
     (setq _suspension_cylinder_select_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _suspension_cylinder_motor_control
     (setq _suspension_cylinder_motor_control (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _vertical_wall_mode
     (setq _vertical_wall_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _fix_two_chamber_valve
     (setq _fix_two_chamber_valve (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _entrenchment
     (setq _entrenchment (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get three_one_msgs::ControlSuspension :md5sum-) "4bc4d758b88c322981bcdaff503bd5e7")
(setf (get three_one_msgs::ControlSuspension :datatype-) "three_one_msgs/ControlSuspension")
(setf (get three_one_msgs::ControlSuspension :definition-)
      "uint8 priority
uint8 cylinder_select
uint8 suspension_select
uint8 suspension_work_mode
uint8 suspension_work_mode_detail
uint8 suspension_cylinder_select_mode
uint8 suspension_cylinder_motor_control
uint8 vertical_wall_mode
uint8 fix_two_chamber_valve
uint8 entrenchment
")



(provide :three_one_msgs/ControlSuspension "4bc4d758b88c322981bcdaff503bd5e7")


