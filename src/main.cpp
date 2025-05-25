#include <Arduino.h>


#include <Servo.h>

#include "components/servomotor/servomotor.h"
#include "components/relay/relay.h"
#include "components/button/button.h"


Servomotor *vyh1, *vyh2, *vyh3, *vyh4, *vyh5, *nav1, *nav2, *nav3, *nav4, *nav5;
Relay *r1;
Button *b_vyh1, *b_vyh2, *b_vyh3, *b_vyh4, *b_vyh5, *b_nav1, *b_nav2, *b_nav3, *b_nav4, *b_nav5;


void setup() {
    delay(2000);

    vyh1 = new Servomotor(13, 80, 135);
    vyh2 = new Servomotor(11, 35, 148);
    vyh3 = new Servomotor(3, 84, 137); //otoc
    vyh4 = new Servomotor(14, 100, 140); // otoc
    vyh5 = new Servomotor(18, 53, 160);

    //nav1 = new Servomotor(45, 10, 50);
    //nav2 = new Servomotor(43, 70, 110);
    //nav3 = new Servomotor(22, 110, 150);
    //nav4 = new Servomotor(44, 70, 110);
    //nav5 = new Servomotor(42, 100, 140);

    //s1 = new Servomotor(14, 10, 170);
    //r1 = new Relay(14);
    //b1 = new Button(46);
}

void loop() {
  
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

