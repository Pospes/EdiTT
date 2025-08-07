


#include "ble.h"


Ble::Ble(const uint8_t &tx, const uint8_t &rx) {
    
    //this->serial = new SoftwareSerial(tx, rx);

    Serial2.begin(9600);
    
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


void Ble::connect() {
    static bool x = false;

    if (!x) {
        x = true;
        Serial2.print("AT\r\n");
    }
}


void Ble::receive() {
    
    if (Serial2.available()) 
        Serial.write(Serial2.read());

    if (Serial.available()) 
        Serial2.write(Serial.read());


    char bleData;
    /*
    if (this->serial->available() > 0) {
        bleData = this->serial->read();

        switch (bleData) {
            case 0x00:
                logger->println("0 acc");
                break;
            
            case 0x01:
                logger->println("1 acc");
                break;

            case '\r':
            case '\n':
            default:
                logger->println("Unk cmd");
                break;
        }
    }
    */

  




}
