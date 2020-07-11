#ifndef ECU_COMMUNICATION_DATAUPLOAD_HPP
#define ECU_COMMUNICATION_DATAUPLOAD_HPP

#include <cmath>
#include <stdint-gcc.h>
#include <cstring>
#include "control_msgs/Report.h"
#include "control_msgs/Rawdata.h"

#include "SHandle.hpp"
#include "ThreeOne.hpp"
#include "DEFINEs.hpp"

namespace ecu_communication {

///Intel protocol     0x187
///Intel protocol    0x185
///Intel protocol    0x183
///Intel protocol    0x505

#ifndef ID_CALCULATE
    #define ID_CALCULATE
union ID_calculate_type {
    uint8_t data[4];
    uint32_t result;
};
#endif



class DataUpload {
public:
    ID_calculate_type ID_calculate;
    uint8_t WheelSpeed[13];
    uint8_t gear_steer_throttle_brakedeepth[13];
    uint8_t vehicleSpeed_Throttle_opening[13];
    uint8_t YuanFengEsc[13];
    uint8_t VehicleWorkMode[13];

    //VCU
    uint8_t BrakeFromVcu[13];
    uint8_t TorqueFromVcu[13];

    control_msgs::Report ecuReport;
    control_msgs::Rawdata recv_rawdata;

    uint8_t recv_raw_data[13];
    uint64_t recv_counter;
    shawn::handle pack_handle;
    DataUpload();
    void dataDistribution();
    bool dataIDCheck(char *p_recv_raw_data);
    bool dataCheck();
    void dataToMsg();

};

}

#endif //ECU_COMMUNICATION_DATAUPLOAD_HPP