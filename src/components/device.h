
#pragma once


#include <stdint.h>



class Device {
    protected:
        int16_t pin = -1;

    public:
        Device(int16_t pin_num) : pin(pin_num) {}
        virtual void process_state() = 0;
        virtual ~Device() {}
};