#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "I2cNeo.h"

using namespace std;

string i2c_device = "/dev/i2c-1";
int i2c_address = 0x40;

int main (void) {
    I2cNeo neoled(i2c_device, i2c_address);
   
    while(true) {
        neoled.blink(0,255,255,255);
        sleep(5);
        neoled.blink(0,255,255,255);	
        sleep(5);	
    }
}
