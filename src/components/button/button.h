
#pragma once

#include <stdint.h>




class Button {
    private:
        uint16_t pin = 0;

    public:
        Button(uint16_t pin);
        Button() {}
        bool get_state();
};