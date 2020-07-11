/*
 * 与底层通信使用CAN扩展帧格式(13 byte)
*/

#include "DataUpload.hpp"

namespace ecu_communication {

    DataUpload::DataUpload() {
        memset(this->WheelSpeed, 0, sizeof(this->WheelSpeed));
        memset(this->vehicleSpeed_Throttle_opening, 0, sizeof(this->vehicleSpeed_Throttle_opening));
        memset(this->gear_steer_throttle_brakedeepth, 0, sizeof(this->gear_steer_throttle_brakedeepth));
        memset(this->YuanFengEsc, 0, sizeof(this->YuanFengEsc));
        memset(this->VehicleWorkMode, 0, sizeof(this->VehicleWorkMode));
        memset(this->recv_raw_data, 0, sizeof(this->recv_raw_data));
        this->ID_calculate.result = {};
        this->recv_counter = 0;
        this->ecuReport.manual.is_human_brake = 0;
        this->recv_rawdata.data.clear();
    }
/// recv_raw_data[2]为CANID扩展高位
    bool DataUpload::dataIDCheck(char *p_recv_raw_data) {
        memcpy(this->recv_raw_data, p_recv_raw_data, sizeof(this->recv_raw_data));
        this->ID_calculate.data[3] = this->recv_raw_data[0];
        this->ID_calculate.data[2] = this->recv_raw_data[1];
        this->ID_calculate.data[1] = this->recv_raw_data[3];
        this->ID_calculate.data[0] = this->recv_raw_data[4];

        size_t tmp_ID = -1;
        switch (this->ID_calculate.result) {
            //轮速
            case 0x08000187: {
                tmp_ID = 0;
                break;
            }
                //车速 节气门开度
            case 0x08000185: {
                tmp_ID = 1;
                break;
            }
                // 实际档位 方向盘角度 油门制动深度
            case 0x08000183: {
                tmp_ID = 2;
                break;
            }
                //元丰ESC制动量反馈
            case 0x08000505: {
                tmp_ID = 3;
                break;
            }
            case 0x08000186: {
                tmp_ID = 4;
                break;
            }
            default: {
                return false;
            }
        }
        this->pack_handle.setID(tmp_ID);
        return true;
    }

    void DataUpload::dataDistribution() {
        ++this->recv_counter;
        switch (this->pack_handle.getID()) {
            case 0: {
                memcpy(this->WheelSpeed, this->recv_raw_data, sizeof(this->recv_raw_data));
                break;
            }
            case 1: {
                memcpy(this->vehicleSpeed_Throttle_opening, this->recv_raw_data, sizeof(this->recv_raw_data));
                break;
            }
            case 2: {
                memcpy(this->gear_steer_throttle_brakedeepth, this->recv_raw_data, sizeof(this->recv_raw_data));
                break;
            }
            case 3: {
                memcpy(this->YuanFengEsc, this->recv_raw_data, sizeof(this->recv_raw_data));
                break;
            }
            case 4: {
                memcpy(this->VehicleWorkMode, this->recv_raw_data, sizeof(this->recv_raw_data));
                break;
            }
            default: {
                --this->recv_counter;
                break;
            }
        }
    }

    bool DataUpload::dataCheck() {
        //// todo modify
        return true;
    }

    void DataUpload::dataToMsg() {
        //0x186
        this->ecuReport.vehicle_work_mode.work_mode = ((this->VehicleWorkMode[7] & 0x3C) >> 2);
        /*if (0 == ecuReport.vehicle_work_mode.work_mode )
            std::cout << "system failures" << std::endl;
        else if (1 == ecuReport.vehicle_work_mode.work_mode)
            std::cout << "Pure Electric 4WD" << std::endl;
        else if (2 == ecuReport.vehicle_work_mode.work_mode)
            std::cout << "HEV 3Power-4WD " << std::endl;
        else if (3 == ecuReport.vehicle_work_mode.work_mode)
            std::cout << "HEV 4WD(RearMotor+Engine)" << std::endl;
        else if (4 == ecuReport.vehicle_work_mode.work_mode)
            std::cout << "HEV 2WD(FrontMotor+Engine)" << std::endl;
        else if (5 == ecuReport.vehicle_work_mode.work_mode)
            std::cout << "Pure petrol " << std::endl;
        else if (6 == ecuReport.vehicle_work_mode.work_mode)
            std::cout << "Pure Electric FWD" << std::endl;
        else if (7 == ecuReport.vehicle_work_mode.work_mode)
            std::cout << "Pure Electric RWD" << std::endl;
        else if (8 == ecuReport.vehicle_work_mode.work_mode)
            std::cout << "Power System OFF " << std::endl;*/

        //0x187
        //轮速
        this->ecuReport.wheel.statusfl = (this->WheelSpeed[5] & 0x01);
        this->ecuReport.wheel.front_left =
            (((this->WheelSpeed[5] >> 1) & 0x7F) + (this->WheelSpeed[6] & 0x1F) * 128) * 0.06875 / 3.6;

        this->ecuReport.wheel.statusfr = ((this->WheelSpeed[6] >> 5) & 0x01);
        this->ecuReport.wheel.front_right =
            ((this->WheelSpeed[6] >> 6) + (this->WheelSpeed[7]) * 4 + (this->WheelSpeed[8] & 0x03) * 1024) * 0.06875
                / 3.6;

        this->ecuReport.wheel.statusrl = ((this->WheelSpeed[8] >> 2) & 0x01);
        this->ecuReport.wheel.rear_left =
            ((this->WheelSpeed[8] >> 3) + (this->WheelSpeed[9] & 0x7F) * 32) * 0.06875 / 3.6;

        this->ecuReport.wheel.statusrr = ((this->WheelSpeed[9] >> 7) & 0x01);
        this->ecuReport.wheel.rear_right =
            ((this->WheelSpeed[10]) + (this->WheelSpeed[11] & 0x0F) * 256) * 0.06875 / 3.6;
        //0x185
        ///车速
        this->ecuReport.motion.velocity = ((this->vehicleSpeed_Throttle_opening[9]
            + (this->vehicleSpeed_Throttle_opening[10] & 0x0F) * 256)) * 0.06875 / 3.6;
        ///节气门开度
        this->ecuReport.throttle.throttle_opening = this->vehicleSpeed_Throttle_opening[11] * 0.392;
        //0x183
        //TCU驾驶模 0x0:正常驾驶模式 0x1:自动驾驶模式
        this->ecuReport.motion.drive_mode = (this->gear_steer_throttle_brakedeepth[5] & 0x03);
        //档位0x1:P  0x2:R  0x3:N   0x4:D
        this->ecuReport.motion.gear = ((this->gear_steer_throttle_brakedeepth[5] & 0x3C) >> 2);
        ///方向盘转角  左转向时值为正数,右转向时值为负数
        this->ecuReport.motion.steer = -(((this->gear_steer_throttle_brakedeepth[6] & 0xFC) >> 2)
            + (this->gear_steer_throttle_brakedeepth[7]) * 64
            + (this->gear_steer_throttle_brakedeepth[8] & 0x03) * 16384) * 0.1 + 780;
        ///油门深度反馈
        this->ecuReport.throttle.throttle_pedal = ((this->gear_steer_throttle_brakedeepth[9] >> 4)
            + (this->gear_steer_throttle_brakedeepth[10] & 0x0F) * 16) * 0.01;
        ///车辆原装制动深度反馈
        this->ecuReport.brake.brake_pedal = ((this->gear_steer_throttle_brakedeepth[10] >> 4)
            + (this->gear_steer_throttle_brakedeepth[11] & 0x0F) * 16) * 0.01;
        if (ecuReport.brake.brake_pedal > 0.01) {
            ecuReport.manual.is_human_brake = 1;
        }
        //0x505
        ///YuanFeng Esc制动反馈
        this->ecuReport.brake.left_pressure_back = this->YuanFengEsc[5] * 0.1;
        this->ecuReport.brake.right_pressure_back = this->YuanFengEsc[6] * 0.1;
        this->ecuReport.brake.auto_park_state = (YuanFengEsc[7] >> 7);
        this->ecuReport.brake.auto_brake_enable = ((YuanFengEsc[7] >> 6) & 0x01);
        this->ecuReport.brake.system_hot_warn = ((YuanFengEsc[7] >> 5) & 0x01);
        this->ecuReport.brake.system_error_code = YuanFengEsc[8];
        this->ecuReport.brake.left_pressure_set = int(YuanFengEsc[9]) * 0.1;
        this->ecuReport.brake.right_pressure_set = int(YuanFengEsc[10]) * 0.1;
        if (this->ecuReport.brake.system_hot_warn)
            std::cout << "Auto brake system hot warn" << std::endl;
        if (YuanFengEsc[8] == 0x01)
            std::cout << "Auto brake system voltage fault" << std::endl;
        else if (YuanFengEsc[8] == 0x02)
            std::cout << "Auto brake system regulator fault" << std::endl;
        else if (YuanFengEsc[8] == 0x04)
            std::cout << "Auto brake system ESC hardware fault" << std::endl;
        else if (YuanFengEsc[8] == 0x08)
            std::cout << "Auto brake system CAN network fault" << std::endl;
    }

}
