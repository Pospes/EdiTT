
#pragma once

#include "components/button/button.h"
#include "components/ble/ble.h"

class InputHandler {
    public:

        Button *b_vyh1 = new Button(22);
        Button *b_vyh2 = new Button(23);
        Button *b_vyh3 = new Button(24);
        Button *b_vyh4 = new Button(25);
        Button *b_vyh5 = new Button(26);

        Button *b_nav1 = new Button(27);
        Button *b_nav2 = new Button(28);
        Button *b_nav3 = new Button(29);
        Button *b_nav4 = new Button(30);
        Button *b_nav5 = new Button(31);

        BleInterface *ble = new BleInterface(Serial2);  // 16=TX, 17=RX




};