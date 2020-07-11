;; Auto-generated. Do not edit!


(when (boundp 'three_one_msgs::ReportVehicleState)
  (if (not (find-package "THREE_ONE_MSGS"))
    (make-package "THREE_ONE_MSGS"))
  (shadow 'ReportVehicleState (find-package "THREE_ONE_MSGS")))
(unless (find-package "THREE_ONE_MSGS::REPORTVEHICLESTATE")
  (make-package "THREE_ONE_MSGS::REPORTVEHICLESTATE"))

(in-package "ROS")
;;//! \htmlinclude ReportVehicleState.msg.html


(defclass three_one_msgs::ReportVehicleState
  :super ros::object
  :slots (_error_code _two_chamber_valve _vertical_wall_status _entrenchment _weapon_330 _weapon_28 _vehicle_height _tailgate_state _SOC _vehicle_roll _vehicle_pitch ))

(defmethod three_one_msgs::ReportVehicleState
  (:init
   (&key
    ((:error_code __error_code) 0)
    ((:two_chamber_valve __two_chamber_valve) 0)
    ((:vertical_wall_status __vertical_wall_status) 0)
    ((:entrenchment __entrenchment) 0)
    ((:weapon_330 __weapon_330) 0)
    ((:weapon_28 __weapon_28) 0)
    ((:vehicle_height __vehicle_height) 0)
    ((:tailgate_state __tailgate_state) 0)
    ((:SOC __SOC) 0)
    ((:vehicle_roll __vehicle_roll) 0)
    ((:vehicle_pitch __vehicle_pitch) 0)
    )
   (send-super :init)
   (setq _error_code (round __error_code))
   (setq _two_chamber_valve (round __two_chamber_valve))
   (setq _vertical_wall_status (round __vertical_wall_status))
   (setq _entrenchment (round __entrenchment))
   (setq _weapon_330 (round __weapon_330))
   (setq _weapon_28 (round __weapon_28))
   (setq _vehicle_height (round __vehicle_height))
   (setq _tailgate_state (round __tailgate_state))
   (setq _SOC (round __SOC))
   (setq _vehicle_roll (round __vehicle_roll))
   (setq _vehicle_pitch (round __vehicle_pitch))
   self)
  (:error_code
   (&optional __error_code)
   (if __error_code (setq _error_code __error_code)) _error_code)
  (:two_chamber_valve
   (&optional __two_chamber_valve)
   (if __two_chamber_valve (setq _two_chamber_valve __two_chamber_valve)) _two_chamber_valve)
  (:vertical_wall_status
   (&optional __vertical_wall_status)
   (if __vertical_wall_status (setq _vertical_wall_status __vertical_wall_status)) _vertical_wall_status)
  (:entrenchment
   (&optional __entrenchment)
   (if __entrenchment (setq _entrenchment __entrenchment)) _entrenchment)
  (:weapon_330
   (&optional __weapon_330)
   (if __weapon_330 (setq _weapon_330 __weapon_330)) _weapon_330)
  (:weapon_28
   (&optional __weapon_28)
   (if __weapon_28 (setq _weapon_28 __weapon_28)) _weapon_28)
  (:vehicle_height
   (&optional __vehicle_height)
   (if __vehicle_height (setq _vehicle_height __vehicle_height)) _vehicle_height)
  (:tailgate_state
   (&optional __tailgate_state)
   (if __tailgate_state (setq _tailgate_state __tailgate_state)) _tailgate_state)
  (:SOC
   (&optional __SOC)
   (if __SOC (setq _SOC __SOC)) _SOC)
  (:vehicle_roll
   (&optional __vehicle_roll)
   (if __vehicle_roll (setq _vehicle_roll __vehicle_roll)) _vehicle_roll)
  (:vehicle_pitch
   (&optional __vehicle_pitch)
   (if __vehicle_pitch (setq _vehicle_pitch __vehicle_pitch)) _vehicle_pitch)
  (:serialization-length
   ()
   (+
    ;; uint8 _error_code
    1
    ;; uint8 _two_chamber_valve
    1
    ;; uint8 _vertical_wall_status
    1
    ;; uint8 _entrenchment
    1
    ;; uint8 _weapon_330
    1
    ;; uint8 _weapon_28
    1
    ;; uint8 _vehicle_height
    1
    ;; uint8 _tailgate_state
    1
    ;; uint8 _SOC
    1
    ;; int8 _vehicle_roll
    1
    ;; int8 _vehicle_pitch
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _error_code
       (write-byte _error_code s)
     ;; uint8 _two_chamber_valve
       (write-byte _two_chamber_valve s)
     ;; uint8 _vertical_wall_status
       (write-byte _vertical_wall_status s)
     ;; uint8 _entrenchment
       (write-byte _entrenchment s)
     ;; uint8 _weapon_330
       (write-byte _weapon_330 s)
     ;; uint8 _weapon_28
       (write-byte _weapon_28 s)
     ;; uint8 _vehicle_height
       (write-byte _vehicle_height s)
     ;; uint8 _tailgate_state
       (write-byte _tailgate_state s)
     ;; uint8 _SOC
       (write-byte _SOC s)
     ;; int8 _vehicle_roll
       (write-byte _vehicle_roll s)
     ;; int8 _vehicle_pitch
       (write-byte _vehicle_pitch s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _error_code
     (setq _error_code (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _two_chamber_valve
     (setq _two_chamber_valve (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _vertical_wall_status
     (setq _vertical_wall_status (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _entrenchment
     (setq _entrenchment (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _weapon_330
     (setq _weapon_330 (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _weapon_28
     (setq _weapon_28 (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _vehicle_height
     (setq _vehicle_height (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _tailgate_state
     (setq _tailgate_state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _SOC
     (setq _SOC (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int8 _vehicle_roll
     (setq _vehicle_roll (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _vehicle_roll 127) (setq _vehicle_roll (- _vehicle_roll 256)))
   ;; int8 _vehicle_pitch
     (setq _vehicle_pitch (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _vehicle_pitch 127) (setq _vehicle_pitch (- _vehicle_pitch 256)))
   ;;
   self)
  )

(setf (get three_one_msgs::ReportVehicleState :md5sum-) "038961e65ff3db9742a20c76bdc20ca1")
(setf (get three_one_msgs::ReportVehicleState :datatype-) "three_one_msgs/ReportVehicleState")
(setf (get three_one_msgs::ReportVehicleState :definition-)
      "uint8 error_code
uint8 two_chamber_valve
uint8 vertical_wall_status
uint8 entrenchment
uint8 weapon_330
uint8 weapon_28
uint8 vehicle_height
uint8 tailgate_state
uint8 SOC
int8 vehicle_roll
int8 vehicle_pitch
")



(provide :three_one_msgs/ReportVehicleState "038961e65ff3db9742a20c76bdc20ca1")


