
#pragma once

#include "config.h"

#include "components/device.h"

#include "components/relay/relay.h"
#include "components/servomotor/servomotor.h"
#include "components/speaker/speaker.h"




class OutputHandler {
    public:

        Relay *r4 = new Relay(40);
    #ifdef FZ1_POWER
        Relay *r1 = new Relay(37);
        Relay *r2 = new Relay(39);
        Relay *r3 = new Relay(38);
        // SSR
        Relay *r5 = new Relay(49);
        Relay *r6 = new Relay(48);
    #endif

        Servomotor *vyh1 = new Servomotor(11, 80, 135, true);
        Servomotor *nav1 = new Servomotor(44, 20, 60);
    #ifdef FZ1_POWER
        Servomotor *vyh2 = new Servomotor(13, 52, 148);
        Servomotor *vyh3 = new Servomotor(12, 90, 137, true);
        Servomotor *vyh4 = new Servomotor(10, 100, 140, true);
        Servomotor *vyh5 = new Servomotor(45, 53, 155);

        Servomotor *nav2 = new Servomotor(43, 70, 110);
        Servomotor *nav3 = new Servomotor(46, 110, 150);
        Servomotor *nav4 = new Servomotor(42, 70, 110);
        Servomotor *nav5 = new Servomotor(41, 100, 140, true);
    #endif
        Speaker *crossing = new Speaker(Serial1, 10);  // 18=TX, 19=RX


        Device *device_list[
            #ifdef FZ1_POWER 
                17
            #else
                4
            #endif
        ] = {
            r4,
            vyh1,
            nav1,
            crossing,

            #ifdef FZ1_POWER
                r1, r2, r3, r5, r6,
                vyh2, vyh3, vyh4, vyh5,
                nav2, nav3, nav4, nav5
            #endif
        };



        void process_states() {
            for (auto &device : device_list)
                device->process_state();
        }
};
