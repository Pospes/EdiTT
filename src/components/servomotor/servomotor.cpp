
#include <Arduino.h>
#include <stdio.h>

#include "config.h"
#include "servomotor.h"




Servomotor::Servomotor(const uint16_t in_servo_pin, const int min_angle, const int max_angle) {

    this->pin = in_servo_pin;
    this->servo.attach(pin);

    this->min_angle = min_angle;
    this->max_angle = max_angle;
    this->mid_angle = (this->min_angle + this->max_angle) / 2;

    // get servo in predictable position
    servo.write(max_angle);
}



int Servomotor::read_angle() {
    return this->servo.read();
}

void Servomotor::step_plus() {
    if (read_angle() < this->max_angle) {
        this->servo.write(read_angle() + SERVO_STEP_SIZE_ANGLE);
        delay(SERVO_STEP_DELAY_MS);
    }
}


void Servomotor::step_minus() {
    if (read_angle() > this->min_angle) {
        this->servo.write(read_angle() - SERVO_STEP_SIZE_ANGLE);
        delay(SERVO_STEP_DELAY_MS);
    }
}





void Servomotor::write_angle(int target_angle) {
    if (target_angle > this->max_angle || target_angle < this->min_angle) {
        Serial.println("[ERROR]: Write angle invalid");
        return;
    }

    if (!servo.attached())
        servo.attach(this->pin);

    int current_angle = read_angle();
    
    while (current_angle < target_angle) {
        step_plus();
        current_angle = read_angle();
    }

    while (current_angle > target_angle) {
        step_minus();
        current_angle = read_angle();
    }

    delay(400);
    servo.detach();
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




bool Servomotor::switch_plus() {
    if (!this->default_position) {
        write_angle(this->max_angle);

        this->default_position = true;
        return true;
    }
    return false;
}



bool Servomotor::switch_minus() {
    if (this->default_position) {
        write_angle(this->min_angle);

        this->default_position = false;
        return true;
    }
    return false;
}
    

void Servomotor::switch_middle() {
    write_angle(this->mid_angle);
        
    this->default_position = false;
}


bool Servomotor::get_position() {
    return this->default_position;
}