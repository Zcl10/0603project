#include "DataDownload.hpp"
namespace ecu_communication {

    DataDownload::DataDownload() {
        memset(this->data_to_send, 0, sizeof(this->data_to_send));
        this->send_rawdata.data.clear();
        this->auto_enable_counter = 3;
    }
    void DataDownload::gearprocess(int temp_gear) {
        switch (temp_gear) {
            case 0: {
                this->data_to_send[9] = 0x00;            //Invalid档
                break;
            }
            case 1: {
                this->data_to_send[9] = 0x01;            //P档
                break;
            }
            case 2: {
                this->data_to_send[9] = 0x02;            //R档
                break;
            }
            case 3: {
                this->data_to_send[9] = 0x03;            //N档
                break;
            }
            case 4: {
                this->data_to_send[9] = 0x04;            //D档
                break;
            }
            default: {
                this->data_to_send[9] = 0x01;            //误操作档位置为P
                break;
            }
        }
    }
    void DataDownload::TurnOnWipersLight(int on_off) {
        switch (on_off) {
            case 0: {
                this->data_to_send[5] |= 0x08;
                this->data_to_send[8] = 0x10;
                break;
            }
            case 1: {
                this->data_to_send[8] = 0x08 << 4; //慢刮
                break;
            }
            case 2: {
                //灯光AUTO档
//                this->data_to_send[5] |= 0x04;
                break;
            }
            default: {
                break;
            }
        }

    }
    void DataDownload::prepareSend(shawn::handle p_handle) {
        switch (p_handle.getID()) {
            case 0: {
                memset(this->data_to_send, 0, sizeof(this->data_to_send));
                this->data_to_send[0] = 0b00001000;
                this->data_to_send[1] = 0b00000000;
                this->data_to_send[2] = 0b00000000;
                this->data_to_send[3] = 0x03;
                this->data_to_send[4] = 0xA3;
                if (speed_cmd_receive && steer_cmd_receive) {
                    //开启自动驾驶模式
                    if (this->auto_enable_counter > 0) {
                        this->data_to_send[5] = 0x01;
                        this->auto_enable_counter--;
                    }
                    //转向控制  方向盘左右极限：-30°~+30°
                    int steer = this->SendECUData.steering_ctrl;
                    if (steer >= 13110 || steer <= 2490) {
                        if (steer >= 13110) {
                            steer = 13110;
                        } else {
                            steer = 2490;
                        }
                    }
                    //目标方向盘角度
                    this->data_to_send[6] = steer & 0x00ff;
                    this->data_to_send[7] = ((steer & 0xff00) >> 8);
                    // 目标档位
                    int targetgear = SendECUData.shift;
                    gearprocess(targetgear);
                    //wipers control
//                    int turnWipersLight = SendECUData.wipers_enable;
//                    TurnOnWipersLight(turnWipersLight);
                    //目标方向盘角速度
                    this->data_to_send[10] = 0xf4;
                    this->data_to_send[11] = 0x01;
                } else {
                    this->auto_enable_counter = 3;
                    this->data_to_send[5] = 0x02;
                    this->data_to_send[6] = 0x78;
                    this->data_to_send[7] = 0x1E;
                }
                //校验码
                unsigned char checknum = 0;
                for (int i = 5; i < 12; i++) {
                    checknum += this->data_to_send[i];
                }
                this->data_to_send[12] = (checknum ^ 0xFF);
                break;
            }
            case 1: {
                memset(this->data_to_send, 0, sizeof(this->data_to_send));
                this->data_to_send[0] = 0b00001000;
                this->data_to_send[1] = 0b00000000;
                this->data_to_send[2] = 0b00000000;
                this->data_to_send[3] = 0x03;
                this->data_to_send[4] = 0xA4;
                if (speed_cmd_receive) {
                    torque2byte torquetemp;
                    torquetemp._int = SendECUData.torque_ctrl;
                    uint16_t torque_value = torquetemp._int;
                    //车辆纵向控制状态 & 扭矩请求值状态
                    this->data_to_send[5] = 0x03;
                    //扭矩请求值
                    if (torquetemp._int > 15000)
                        torquetemp._int = 15000;
                    this->data_to_send[6] = torque_value & 0x00ff;
                    this->data_to_send[7] = ((torque_value & 0xff00) >> 8);

                    this->data_to_send[6] = torquetemp._char[0];
                    this->data_to_send[7] = torquetemp._char[1];
                }else{
                    uint16_t torque_value = 12000;
                    this->data_to_send[6] = torque_value & 0x00ff;
                    this->data_to_send[7] = ((torque_value & 0xff00) >> 8);
                }
                break;
            }
            case 2: {
                memset(this->data_to_send, 0, sizeof(this->data_to_send));
                this->data_to_send[0] = 0b00001000;
                this->data_to_send[1] = 0b00000000;
                this->data_to_send[2] = 0b00000000;
                this->data_to_send[3] = 0x05;
                this->data_to_send[4] = 0x10;
                if (speed_cmd_receive) {
                    ///刹车
                    if (SendECUData.brake_ctrl > 20.0) {
                        SendECUData.brake_ctrl = 20.0;
                    }
                    //刹车有效
                    this->data_to_send[7] = 0x40;
                    this->data_to_send[5] = SendECUData.brake_ctrl * 10;
                    this->data_to_send[6] = SendECUData.brake_ctrl * 10;
                }
                break;
            }
            default: {
                break;
            }
        }
    }
}
