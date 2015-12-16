#include <iostream>
#include "StartClass.h"
#include "neopixel/I2cNeo.h"

using namespace std;


int main() {
    //let the game begin
    //startClass startClass;
    string i2c_device = "";
    int i2c_address = 0x40;
    I2cNeo neoled(i2c_device, i2c_address);

    while(true) {
        neoled.blink(0,255,255,255);
        sleep(5);
        neoled.blink(0,255,255,255);
        sleep(5);
        break;
    }
    return 0;
}
