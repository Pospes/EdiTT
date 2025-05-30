#include <Arduino.h>


#include <Servo.h>

#include "inputHandler.h"
#include "outputHandler.h"
#include "components/servomotor/servomotor.h"
#include "components/relay/relay.h"


uint64_t current_time;

InputHandler *input_handler;

OutputHandler *output_handler;

//Servomotor *vyh2 = new Servomotor(11, 35, 148);

//Servomotor *vyh2;

void setup() {
    delay(2000);
    input_handler = new InputHandler();
    output_handler = new OutputHandler();
    //vyh2 = new Servomotor(11, 35, 148);
}

void loop() {
    current_time = millis();

    

    // look inputs
        // process buttons

    // process
    



    if (input_handler->b_vyh1->get_state()) {
        //r1->turn_on();
        digitalWrite(LED_BUILTIN, HIGH);
        //output_handler.r1->blink_on(1000);
        //output_handler.r2->blink_on(750);
        //output_handler.r3->blink_on(480);
        output_handler->vyh2->switch_minus();
    }
    else {
        digitalWrite(LED_BUILTIN, LOW);
        //r1->turn_off();
        output_handler->vyh2->switch_plus();
    }
    

    // do outputs
        // process servomotors
        // process relays
    
    
    

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

