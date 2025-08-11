
#pragma once

#include <HardwareSerial.h>
#include <SoftwareSerial.h>


#include "components/device.h"



class BleInterface {
    
    private:
        
        HardwareSerial &serial;
        uint8_t signal_recv_buffer[64] = {0};




    public:
        BleInterface(HardwareSerial &serial);

        //void connect();
        void mirrorTest();

        void read_if_available();
        bool get_ble_buffer_dirty_flag();
        void set_ble_buffer_dirty_flag(const bool arg);
        uint8_t* get_signal_recv_buffer();


};
