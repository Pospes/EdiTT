#include <Arduino.h>


#include <Servo.h>

#include "inputHandler.h"
#include "outputHandler.h"
#include "components/servomotor/servomotor.h"
#include "components/relay/relay.h"
#include "signal_logic/signal_logic.h"


uint64_t current_time;

InputHandler *input_handler;

OutputHandler *output_handler;










void setup() {
    //delay(2000);
    Serial.begin(9600);
    input_handler = new InputHandler();
    output_handler = new OutputHandler();
}

void loop() {
    current_time = millis();

    input_handler->b_vyh1->get_state() ? output_handler->vyh1->switch_minus() : output_handler->vyh1->switch_plus();
    input_handler->b_nav1->get_state() ? output_handler->nav1->switch_minus() : output_handler->nav1->switch_plus();
#ifdef FZ1_POWER 
    input_handler->b_vyh2->get_state() ? output_handler->vyh2->switch_minus() : output_handler->vyh2->switch_plus();
    input_handler->b_vyh3->get_state() ? output_handler->vyh3->switch_minus() : output_handler->vyh3->switch_plus();
    input_handler->b_vyh4->get_state() ? output_handler->vyh4->switch_minus() : output_handler->vyh4->switch_plus();

    if (input_handler->b_vyh5->get_state()) {
        output_handler->r4->turn_on();
        output_handler->vyh5->switch_minus();
    }
    else {
        output_handler->r4->turn_off();
        output_handler->vyh5->switch_plus();
    }
    
    input_handler->b_nav2->get_state() ? output_handler->nav2->switch_minus() : output_handler->nav2->switch_plus();
    input_handler->b_nav3->get_state() ? output_handler->nav3->switch_minus() : output_handler->nav3->switch_plus();
    input_handler->b_nav4->get_state() ? output_handler->nav4->switch_minus() : output_handler->nav4->switch_plus();
    input_handler->b_nav5->get_state() ? output_handler->nav5->switch_minus() : output_handler->nav5->switch_plus();
#endif
    
    //input_handler->ble->mirrorTest();

    input_handler->ble->read_if_available();

    if (input_handler->ble->get_ble_buffer_dirty_flag()) {
        uint8_t* signal_ble_recv_buffer = input_handler->ble->get_signal_recv_buffer();

        if (SignalLogic::k1_route_set())
            SignalLogic::set_expected_signal(signal_ble_recv_buffer[0]);
        else if (SignalLogic::k2_route_set())
            SignalLogic::set_expected_signal(signal_ble_recv_buffer[1]);
        else if (SignalLogic::k3_route_set())
            SignalLogic::set_expected_signal(signal_ble_recv_buffer[2]);
        else if (SignalLogic::k4_route_set())
            SignalLogic::set_expected_signal(signal_ble_recv_buffer[3]);
        else if (SignalLogic::k6_route_set())
            SignalLogic::set_expected_signal(signal_ble_recv_buffer[4]);
    }
    

/*
    delay(2000);
    vyh1->switch_minus();
    delay(2000);
    vyh2->switch_minus();
    delay(2000);
    vyh3->switch_minus();
    delay(2000);
    vyh4->switch_minus();
    delay(2000);
    vyh5->switch_minus();
    delay(2000);

    vyh1->switch_plus();
    delay(2000);
    vyh2->switch_plus();
    delay(2000);
    vyh3->switch_plus();
    delay(2000);
    vyh4->switch_plus();
    delay(2000);
    vyh5->switch_plus();
    delay(2000);
*/







  /*
  int i;

  for(i=0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);

    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
  
  delay(500);
  
  for(i=0; i < 2; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);

    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  */

    output_handler->process_states();
    delay(30);
}

