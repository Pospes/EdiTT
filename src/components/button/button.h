




#include <stdint.h>





class Button {
    private:
        uint16_t pin = -1;

    public:
        Button(uint16_t pin);
        bool get_state();
};