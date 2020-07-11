// FUCK 207

#ifndef ECU_COMMUNICATION_REMOTESEND_HPP
#define ECU_COMMUNICATION_REMOTESEND_HPP

#include <cstdint>
#include <cmath>
#include "ThreeOne.hpp"
#include "DataUpload.hpp"
#include "sensor_driver_msgs/VehicleState.h"

namespace ecu_communication {

#pragma pack(1)
union remote_send_pack_fuck_type {
    struct {
        uint8_t ID_one;
        uint8_t ID_two;
        uint8_t car_type;
        uint8_t car_ID;
        uint32_t gps_week;
        uint64_t gps_ms;
        uint8_t SOC;
        uint8_t controlled_state;
        uint8_t terminal_ID;
        uint8_t check_sum;
    };
    uint8_t pack[20];
};

union remote_send_pack_one_type {
    struct {
        uint8_t ID_one;
        uint8_t ID_two;
        uint8_t gear;
        uint8_t park_status;
        uint16_t mechanical_brake;
        uint16_t vehicle_speed;
        uint64_t mileage;
        uint8_t error_code;
        uint16_t left_wheel_expect_speed;
        uint16_t right_wheel_expect_speed;
        uint16_t vehicle_height;

        double_t longitude;
        double_t latitude;
        int32_t altitude;
        float_t yaw;
        float_t roll;
        float_t pitch;

        int32_t north_speed;
        int32_t east_speed;
        int32_t up_speed;
        uint8_t SOC;
        uint8_t reserve_byte1;
    };
    uint8_t pack[69];
};

union remote_send_pack_two_type {
    struct {
        uint8_t ID_one;
        uint8_t ID_two;
        uint16_t left_wheel_expect_speed;
        uint16_t mechanical_brake;
        uint16_t right_wheel_expect_speed;
        uint8_t vehicle_speed;
        uint8_t gear;
    };
    uint8_t pack[10];
};

union remote_send_pack_three_type {
    struct {
        uint8_t ID_one;
        uint8_t ID_two;
        uint16_t left_motor_actual_speed;
        uint8_t left_motor_gear;
        uint8_t right_motor_gear;
        uint16_t right_motor_actual_speed;
        uint8_t SOC;
        uint8_t tailgate_state;
    };
    uint8_t pack[10];
};

union remote_send_pack_four_type {
    struct {
        uint8_t ID_one;
        uint8_t ID_two;
        uint8_t left_one_cylinder_position;
        uint8_t left_two_cylinder_position;
        uint8_t left_three_cylinder_position;
        uint8_t left_four_cylinder_position;
        uint8_t right_one_cylinder_position;
        uint8_t right_two_cylinder_position;
        uint8_t right_three_cylinder_position;
        uint8_t right_four_cylinder_position;
    };
    uint8_t pack[10];
};

union remote_send_pack_five_type {
    struct {
        uint8_t ID_one;
        uint8_t ID_two;
        uint8_t left_one_cylinder_pressure;
        uint8_t left_two_cylinder_pressure;
        uint8_t left_three_cylinder_pressure;
        uint8_t left_four_cylinder_pressure;
        uint8_t right_one_cylinder_pressure;
        uint8_t right_two_cylinder_pressure;
        uint8_t right_three_cylinder_pressure;
        uint8_t right_four_cylinder_pressure;
    };
    uint8_t pack[10];
};

union remote_send_pack_six_type {
    struct {
        uint8_t ID_one;
        uint8_t ID_two;
        uint32_t mileage;
        int8_t vehicle_roll;
        int8_t vehicle_pitch;
        int16_t left_torque;
    };
    uint8_t pack[10];
};

union remote_send_pack_seven_type {
    struct {
        uint8_t ID_one;
        uint8_t ID_two;
        int16_t right_torque;
        uint8_t vertical_wall_status;
        uint8_t error_code;
        uint32_t left_pulse;
    };
    uint8_t pack[10];
};

union remote_send_pack_eight_type {
    struct {
        uint8_t ID_one;
        uint8_t ID_two;
        uint32_t right_pulse;
        uint8_t vehicle_height;
        uint8_t park_status;
        union {
            struct {
                uint8_t operation_mode: 1;
                uint8_t two_chamber_valve: 1;
                uint8_t weapon_330: 1;
                uint8_t entrenchment: 1;
                uint8_t weapon_28: 1;
                uint8_t reserve_bits: 3;
            };
            uint8_t functions1;
        };
        uint8_t reserve_bytes1;
    };
    uint8_t pack[10];
};

#pragma pack()

class RemoteSend {
public:
    remote_send_pack_fuck_type pack_fuck;
    remote_send_pack_one_type pack_one;
    remote_send_pack_two_type pack_two;
    remote_send_pack_three_type pack_three;
    remote_send_pack_four_type pack_four;
    remote_send_pack_five_type pack_five;
    remote_send_pack_six_type pack_six;
    remote_send_pack_seven_type pack_seven;
    remote_send_pack_eight_type pack_eight;

    shawn::handle pack_handle;
    uint8_t data_to_send[2048];

    size_t prepareSend(DataUpload *p_data_upload, three_one_feedback::control_mode *p_control_mode, sensor_driver_msgs::VehicleState gps);

    void checkSum();
};

}

#endif //ECU_COMMUNICATION_REMOTESEND_HPP