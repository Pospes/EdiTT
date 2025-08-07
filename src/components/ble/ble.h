
#pragma once

#include <HardwareSerial.h>
#include <SoftwareSerial.h>


#include "components/device.h"



class Ble {
    
    private:
        SoftwareSerial *serial;
        



    public:
        Ble(const uint8_t &tx, const uint8_t &rx);

        void connect();
        void receive();        

};
