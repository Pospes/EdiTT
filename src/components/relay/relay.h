
#pragma once

#include <stdint.h>

#include "../device.h"


extern uint64_t current_time;

typedef enum relay_fsm {
    OFF,
    ON,
    BLINK
} relay_fsm_t;


class Relay : public Device {
    private:
        // FSM
        relay_fsm_t fsm_state = OFF;
        bool relay_state = false;
        //

        uint64_t timer = 0;
        uint64_t timer_period_ms = 0;

        void on();
        void off();

    public:
        Relay(uint16_t pin);
        void process_state() override;  // FSM

        void turn_on();
        void turn_off();
        void blink_on(uint16_t period_ms);
};