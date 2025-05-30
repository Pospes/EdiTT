
#pragma once

#include "components/device.h"

#include "components/relay/relay.h"
#include "components/servomotor/servomotor.h"







class OutputHandler {
    public:

        //Relay *r1 = new Relay(21);
        //Relay *r2 = new Relay(20);
        //Relay *r3 = new Relay(19);


        //Servomotor *vyh1 = new Servomotor(13, 80, 135);
        Servomotor *vyh2 = new Servomotor(11, 52, 148);
        //Servomotor *vyh3 = new Servomotor(8, 84, 137, true);
        //Servomotor *vyh4 = new Servomotor(4, 100, 140, true);
        //Servomotor *vyh5 = new Servomotor(41, 53, 160);

        //Servomotor *nav1 = new Servomotor(45, 10, 50);
        //Servomotor *nav2 = new Servomotor(43, 70, 110);
        //Servomotor *nav3 = new Servomotor(22, 110, 150);
        //Servomotor *nav4 = new Servomotor(44, 70, 110);
        //Servomotor *nav5 = new Servomotor(42, 100, 140);


        Device *device_list[1] = {
            //r1, r2, r3,
            //vyh1, 
            vyh2, //vyh3, vyh4, vyh5,
            //nav1, nav2, nav3, nav4, nav5
        };



        void process_states() {
            for (auto &device : device_list)
                device->process_state();
        }
};
