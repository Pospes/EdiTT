


#include "ble.h"


BleInterface::BleInterface(HardwareSerial &serial) : serial(serial) {
    
    //this->serial = new SoftwareSerial(tx, rx);

    this->serial.begin(9600);
    
    //this->serial->begin(9600);
    //this->serial->println("BLE OK SER");
    //Serial.println(this->serial->available() ? "BLE OK" : "BLE OFF");
    

    
    
    
    /*
    BLE.scanForName("ESP_ELMECH_ST2_GATTS");
    logger->println("Scanning for ESP BLE");

    while (true) {
        peripheral = BLE.available();
        if (peripheral) {
            if (peripheral.localName() == "ESP_ELMECH_ST2_GATTS") {
                logger->println("Found target BLE device!");
                break;
            }
        }
        delay(100);
    }

    BLE.stopScan();

    if (peripheral.connect()) {
        logger->println("Connected to peripheral");
    } else {
        logger->println("Connection failed");
        return;
    }
    

    if (!peripheral.discoverAttributes()) {
        logger->println("Attribute discovery failed.");
        peripheral.disconnect();
        return;
    }

    logger->println("ESP BLE connected OK");
    */
}

/*
void BleInterface::connect() {
    static bool x = false;

    if (!x) {
        x = true;
        Serial2.print("AT\r\n");
    }
}
*/

void BleInterface::mirrorTest() {
    if (this->serial.available()) 
        this->serial.write(this->serial.read());

    if (Serial.available()) 
        this->serial.write(Serial.read());
}


void BleInterface::read_if_available() {
    if (this->serial.available()) {
        this->serial.readBytes(this->signal_recv_buffer, 5);

        this->ble_buffer_dirty_flag = true;
    }
}



bool BleInterface::get_ble_buffer_dirty_flag() {
    return this->ble_buffer_dirty_flag;
}

uint8_t* BleInterface::get_signal_recv_buffer() {
    return this->signal_recv_buffer;
}


