
#pragma once

#include <stdint.h>
#include <Servo.h>

#include "components/device.h"


extern uint64_t current_time;


typedef enum servomotor_fsm {
    SER_FSM_IDLE,  // todo NE?
    SER_FSM_PLUS,
    SER_FSM_MINUS
} servomotor_fsm_t;


typedef enum servo_position {
    PLUS,
    BETWEEN,
    MINUS
} servo_position_t;



class Servomotor : public Device {
    private:
        // FSM
        servomotor_fsm_t fsm_state = SER_FSM_IDLE;
        bool in_default_position = true;
        //

        Servo servo;
        servo_position_t servo_position = PLUS;
        //int pin = -1;

        int max_angle = -1;
        int min_angle = -1;

        bool set_inverse = false;

        int read_angle();
        void step_plus();
        void step_minus();


    public:
        Servomotor(uint16_t in_servo_pin, int min_angle, int max_angle);
        Servomotor(uint16_t in_servo_pin, int min_angle, int max_angle, bool set_inverse);
        void process_state() override;  // FSM

        void debug(uint16_t plus_button, uint16_t minus_button);
        void switch_plus();
        void switch_minus();
};


