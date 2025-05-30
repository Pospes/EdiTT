
#include <Arduino.h>
#include <stdio.h>

#include "config.h"
#include "servomotor.h"




Servomotor::Servomotor(const uint16_t in_servo_pin, const int min_angle, const int max_angle) : Device(in_servo_pin) {

    //this->pin = in_servo_pin;
    this->servo.attach(in_servo_pin);

    this->min_angle = min_angle;
    this->max_angle = max_angle;

    // get servo in predictable position
    servo.write(max_angle);
}

Servomotor::Servomotor(const uint16_t in_servo_pin, const int min_angle, const int max_angle, const bool set_inverse) : Device(in_servo_pin) {

    //this->pin = in_servo_pin;
    this->servo.attach(in_servo_pin);

    this->min_angle = min_angle;
    this->max_angle = max_angle;

    this->set_inverse = set_inverse;

    // get servo in predictable position
    servo.write(set_inverse ? min_angle : max_angle);
}



int Servomotor::read_angle() {
    return this->servo.read();
}

void Servomotor::step_plus() {
    if (read_angle() < this->max_angle) {
        this->servo.write(read_angle() + SERVO_STEP_SIZE_ANGLE);
        //delay(SERVO_STEP_DELAY_MS);
    }
}


void Servomotor::step_minus() {
    if (read_angle() > this->min_angle) {
        this->servo.write(read_angle() - SERVO_STEP_SIZE_ANGLE);
        //delay(SERVO_STEP_DELAY_MS);
    }
}







void Servomotor::process_state() {
    switch (this->fsm_state) {
        case SER_FSM_PLUS:
            if (this->servo_position == PLUS)
                break;

            //if (!servo.attached())
            //    servo.attach(this->pin);

            step_plus();
            this->servo_position = BETWEEN;
            if (read_angle() >= this->max_angle) {
                this->in_default_position = true;
                this->servo_position = PLUS;
                this->fsm_state = SER_FSM_IDLE;
            }
            break;

        case SER_FSM_MINUS:
            if (this->servo_position == MINUS)
                break;

            //if (!servo.attached())
            //    servo.attach(this->pin);
                
            step_minus();
            this->servo_position = BETWEEN;
            if (read_angle() <= this->min_angle) {
                this->in_default_position = false;
                this->servo_position = MINUS;
                this->fsm_state = SER_FSM_IDLE;
            }
            break;
        
        case SER_FSM_IDLE:
        default:
            //if (servo.attached())
            //    servo.detach();
            break;
    }
}






void Servomotor::debug(const uint16_t plus_button, const uint16_t minus_button) {
    if (!servo.attached())
        servo.attach(this->pin);

    while (true) {
        if (!digitalRead(plus_button)) {
            step_plus();
            Serial.print("INFO: switch plus: ");
            Serial.println(read_angle());
            while (!digitalRead(plus_button));
        }
        if (!digitalRead(minus_button)) {
            step_minus();
            Serial.print("INFO: switch minus: ");
            Serial.println(read_angle());
            while (!digitalRead(minus_button));
        }
        delay(10);
    }
}







void Servomotor::switch_plus() {
    this->fsm_state = this->set_inverse ? SER_FSM_MINUS : SER_FSM_PLUS;
    //this->in_default_position = true;
}



void Servomotor::switch_minus() {
    this->fsm_state = this->set_inverse ? SER_FSM_PLUS : SER_FSM_MINUS;
    //this->in_default_position = false;
}




