
#pragma once


#include <stdint.h>


extern uint64_t current_time;


class Device {
    protected:
        int16_t pin = -1;
        uint64_t timer = 0;

    public:
        Device(int16_t pin_num) : pin(pin_num) {}
        virtual void process_state() = 0;
        virtual ~Device() {}
};