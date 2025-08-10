

#pragma once


#include "outputHandler.h"


extern OutputHandler *output_handler;



const uint8_t zav_table[5][5] = {
/*         switch 1  2  3  4  5
From/to rail 1:*/{1, 1, 0, 0, 0}, /* 
From/to rail 2:*/{2, 0, 2, 0 ,0}, /*
From/to rail 3:*/{1, 2, 0, 0, 2}, /*
From/to rail 4:*/{2, 0, 1, 2, 0}, /*
From/to rail 5:*/{2, 0, 1, 1, 0}  /*
/*
0 = indifferent
1 = plus,
2 = minus
*/
};


typedef enum signal_speed {
    HALT,
    FULL_SPEED,
    REDUCED_SPEED_40,
    REDUCED_SPEED_60,
    REDUCED_SPEED_80,
    REDUCED_SPEED_100
} signal_speed_t;




class SignalLogic {
    private:
        static void go_default_aspect();
        static void go_expect_green();
        static void go_expect_40();
        static void go_expect_60();
        static void go_expect_80();
        static void go_expect_100();

    public:
        static bool k1_route_set();
        static bool k2_route_set();
        static bool k3_route_set();
        static bool k4_route_set();
        static bool k6_route_set();

        static void set_expected_signal(const uint8_t signal_state);
};