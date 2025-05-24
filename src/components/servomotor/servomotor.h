

#include <stdint.h>
#include <Servo.h>


class Servomotor {
    private:
        Servo servo;
        int pin = -1;
        int max_angle = -1;
        int mid_angle = -1;
        int min_angle = -1;

        bool default_position = true;

        int read_angle();
        void step_plus();
        void step_minus();
        void write_angle(int target_angle);


    public:
        Servomotor(uint16_t in_servo_pin, int min_angle, int max_angle);
        void debug(uint16_t plus_button, uint16_t minus_button);
        bool switch_plus();
        bool switch_minus();
        void switch_middle();
        bool get_position();
};


