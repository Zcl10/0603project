#ifndef ECU_COMMUNICATION_DATADOWNLOAD_HPP
#define ECU_COMMUNICATION_DATADOWNLOAD_HPP

#include <cstring>
#include <cmath>
#include <stdint-gcc.h>
#include "control_msgs/Control.h"
#include "ThreeOne.hpp"
#include "SHandle.hpp"
#include "geometry_msgs/Vector3Stamped.h"
#include "DataUpload.hpp"
#include "control_msgs/Rawdata.h"

namespace ecu_communication {

#pragma pack(1)
struct struct_SenToECU			// 车辆底层控制,udp通信用
{
    int shift;
    double expect_speed;
    double torque_ctrl;
    double brake_ctrl;
    double steering_ctrl;
    int wipers_enable;
};
union torque2byte
{
    short _int;
    char  _char[2];
};
union ExpectSpeed
{
    short _int;
    char  _char[2];
};

class DataDownload {
public:

    control_msgs::Rawdata send_rawdata;
    control_msgs::Control received_control_data;
    bool speed_cmd_receive;
    bool steer_cmd_receive;
    bool mode_cmd_receive;

    struct_SenToECU SendECUData;
    uint8_t data_to_send[13];
    uint8_t package_zero[13];
    uint8_t package_one[13];
    uint8_t package_two[13];

    DataDownload();
    void init(bool chamber_fix);
    void prepareSend(shawn::handle p_handle);
    void gearprocess(int temp_gear);
    void TurnOnWipersLight(int on_off);

    bool durex(bool move, bool parked, bool need_force_stop, double limit_speed, int limit_thousand_curv);
    void devicesControl(three_one_feedback::control_mode control_mode);
};

}

#endif //ECU_COMMUNICATION_DATADOWNLOAD_HPP