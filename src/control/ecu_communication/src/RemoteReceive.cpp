#include "RemoteReceive.hpp"

namespace ecu_communication {
bool RemoteReceive::receiveIDCheck(char *p_recv_raw_data, uint16_t p_recv_len) {
    if ((((uint8_t)p_recv_raw_data[0]) == 0xF3) && (((uint8_t)p_recv_raw_data[1]) == 0x00)) {
        if (p_recv_len != sizeof(this->pack_one.result_data)) {
            return false;
        }
        pack_handle.setID(0);
        return true;
    }
    if ((((uint8_t)p_recv_raw_data[0]) == 0xF3) && (((uint8_t)p_recv_raw_data[1]) == 0x01)) {
        if (p_recv_len != sizeof(this->pack_two.result_data)) {
            return false;
        }
        pack_handle.setID(1);
        return true;
    }
    return false;
}

void RemoteReceive::dataDistribution(char *p_recv_raw_data, DataDownload *p_data_download) {
    switch (this->pack_handle.getID()) {
        case 0: {
            memcpy(this->pack_one.result_data, p_recv_raw_data, sizeof(this->pack_one.result_data));
            break;
        }
        case 1: {
            memcpy(this->pack_two.result_data, p_recv_raw_data, sizeof(this->pack_two.result_data));
            break;
        }
        default: {
            break;
        }
    }
}

}