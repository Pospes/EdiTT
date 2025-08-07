
#pragma once


#include "DFRobotDFPlayerMini.h"

#include "components/device.h"



typedef enum speaker_fsm {
    STOP,
    PLAY
} speaker_fsm_t;



class Speaker : public Device {
    private:

       DFRobotDFPlayerMini DFPlayer; 
       speaker_fsm_t fsm_state = STOP;
       bool is_busy = false;


    public:
        Speaker(HardwareSerial &serial, uint8_t volume);

        void process_state() override; //FSM

        void play();
        void stop();
};