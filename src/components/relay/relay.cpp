

#include <Arduino.h>

#include "relay.h"

Relay::Relay(const uint16_t pin) : Device(pin) {
    //this->pin = pin;
    pinMode(pin, OUTPUT);
}




void Relay::on() {
    digitalWrite(this->pin, LOW);
    this->relay_state = true;
}

void Relay::off() {
    digitalWrite(this->pin, HIGH);
    this->relay_state = false;
}



void Relay::process_state() {
    switch (this->fsm_state) {
        case ON:
            this->on();
            this->fsm_state = OFF;  // todo toggleable
            break;

        case BLINK:
            if (this->timer == 0)
                this->timer = current_time;
            if (current_time >= this->timer + this->timer_period_ms) {
                this->timer = 0;
                this->relay_state ? this->off() : this->on();
            }
            this->fsm_state = OFF;  // todo toggleable
            break;
        
        case OFF:
        default:
            this->off();
            break;
    }
}





void Relay::turn_on() {
    this->fsm_state = ON;
}

void Relay::turn_off() {
    this->fsm_state = OFF;
}

void Relay::blink_on(const uint16_t period_ms) {
    this->fsm_state = BLINK;
    this->timer_period_ms = period_ms;
}




