

#include "speaker.h"




Speaker::Speaker(HardwareSerial &serial, const uint8_t volume) : Device(-1) {

    serial.begin(9600);
    delay(100);  // Allow hardware to settle

    //Serial.begin(9600);

    this->DFPlayer.begin(serial, /*isACK = */true, /*doReset = */true);
    //if (!this->DFPlayer.begin(serial, /*isACK = */true, /*doReset = */true))  //Use serial to communicate with mp3.
        //Serial.println(F("Unable to setup mp3"));

    delay(200);

    //Serial.println(F("OK"));

    this->DFPlayer.enableLoop();
    this->DFPlayer.volume((volume > 30) ? 30 : volume);
}



void Speaker::process_state() {
    switch (this->fsm_state) {
        case PLAY:
            if (this->is_busy)
                return;

            this->is_busy = true;
            this->DFPlayer.play(2);
            break;

        default:
        case STOP:
            if (!this->is_busy)
                return;

            this->DFPlayer.stop();
            this->is_busy = false;
            break;
    }
}


void Speaker::play() {
    this->fsm_state = PLAY;
}


void Speaker::stop() {
    this->fsm_state = STOP;
}


