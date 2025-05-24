

#include <stdint.h>


class Relay {
    private:
        uint16_t pin = -1;

    public:
        Relay(uint16_t pin);
        void turn_on();
        void turn_off();
};