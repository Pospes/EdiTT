

#include <Arduino.h>


#include "button.h"




Button::Button(uint16_t pin) {
    this->pin = pin;
    pinMode(pin, INPUT_PULLUP);
}




bool Button::get_state() {
    return (this->pin != 0) ? !digitalRead(this->pin) : false;
}