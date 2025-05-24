

#include <Arduino.h>

#include "relay.h"

Relay::Relay(const uint16_t pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Relay::turn_on() {
    digitalWrite(this->pin, LOW);
}

void Relay::turn_off() {
    digitalWrite(this->pin, HIGH);
}
