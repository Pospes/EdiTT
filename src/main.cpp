#include <Arduino.h>


#include <Servo.h>

#include "components/servomotor/servomotor.h"
#include "components/relay/relay.h"
#include "components/button/button.h"


Servomotor *s1;
Relay *r1;
Button *b1;


void setup() {
    delay(2000);
    //s1 = new Servomotor(14, 10, 170);
    r1 = new Relay(14);
    b1 = new Button(46);
}

void loop() {
  

    if (b1->get_state())
        r1->turn_on();      
    else
        r1->turn_off();



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
    //delay(10);
}

