


#include "signal_logic.h"




bool SignalLogic::k1_route_set() {
    return 
        output_handler->vyh1->is_set_plus() && 
        output_handler->vyh2->is_set_plus();
}

bool SignalLogic::k2_route_set() {
    return 
        !output_handler->vyh1->is_set_plus() && 
        !output_handler->vyh3->is_set_plus();
}

bool SignalLogic::k3_route_set() {
    return 
        output_handler->vyh1->is_set_plus() && 
        !output_handler->vyh2->is_set_plus() &&
        !output_handler->vyh5->is_set_plus();
}

bool SignalLogic::k4_route_set() {
    return 
        !output_handler->vyh1->is_set_plus() && 
        output_handler->vyh3->is_set_plus() &&
        !output_handler->vyh4->is_set_plus();
}

bool SignalLogic::k6_route_set() {
    return 
        !output_handler->vyh1->is_set_plus() && 
        output_handler->vyh3->is_set_plus() &&
        output_handler->vyh4->is_set_plus();
}




// TODO
void SignalLogic::go_default_aspect() {
    Serial.print("[LOG]: signal going DEFAULT");
}

void SignalLogic::go_expect_green() {
    Serial.print("[LOG]: signal going GREEN");
}

void SignalLogic::go_expect_40() {
    Serial.print("[LOG]: signal going 40");
}

void SignalLogic::go_expect_60() {
    Serial.print("[LOG]: signal going 60");
}

void SignalLogic::go_expect_80() {
    Serial.print("[LOG]: signal going 80");
}

void SignalLogic::go_expect_100() {
    Serial.print("[LOG]: signal going 100");
}




void SignalLogic::set_expected_signal(const uint8_t signal_state) {
    switch (signal_state) {
        case 0x01:
            go_expect_green();
            break;

        case 0x02:
            go_expect_40();
            break;

        case 0x03:
            go_expect_60();
            break;

        case 0x04:
            go_expect_80();
            break;

        case 0x05:
            go_expect_100();
            break;
        
        case 0x00:
        default:
            go_default_aspect();
            break;
        }
}




