#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime> 

using namespace std;

string i2c_device = "/dev/i2c-1";
int i2c_address = 0x40;

int main (void) {
    cout << "Hello and welcome to the I2c master example program" << endl;

    cout << "Trying to open I2c device '" << i2c_device << "' for reading and writing" << endl;

    // Open device file
    int file = open(i2c_device.c_str(), O_RDWR);
    if (file < 0) {
        cout << "Could not open i2c device. Exiting ..." << endl;
        exit(-1);
    }

    // Aquire bus
    if (ioctl(file, I2C_SLAVE, i2c_address) < 0) {
        cout << "Failed to acquire bus access and/or talk to slave." << endl;
        exit(-1);
    }

    // Lets check how many strings are attached to the mbed controller
    char buffer[10];

    // We can just use the file read function
    int ret = read(file, buffer, 1);        // 1 = the number of bytes to read
    if (ret != 1) {
        cout << "Failed to read from the i2c bus with ret = " << ret << endl;
    } else {
        cout << "NeoPixel driver has " << (int)buffer[0] << " strings attached" << endl;
    }

    sleep(1);

    // Lets start the diagnostic routine
    char diag[] = { 0x02 };

    cout << "Starting the diagnostic routine" << endl;
    ret = write(file, diag, sizeof(diag));
    if (ret != sizeof(diag)) {
        cout << "Failed to write to the I2c bus (diagnostic command) with ret = " << ret << endl;
    }

    cout << "Wait until the diagnostic has finished. Then press any key to continue" << endl;
    int c = getchar();

    // Lets output some colors
    char color[] = { 0x03, 0x00, 0x00, 0x00 };

    cout << "Lets get jiggy" << endl;
    srand((unsigned)time(0)); 
    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            color[1] = 0;
            color[2] = 0;
            color[3] = 0;
        } else {
            color[1] = (rand() % 256) * 0.25;
            color[2] = (rand() % 256) * 0.25;
            color[3] = (rand() % 256) * 0.25;
        }

        ret = write(file, color, sizeof(color));
        if (ret != sizeof(color)) {
            cout << "Failed to write to the I2c bus (color command) with ret = " << ret << endl;
        }

        sleep(1);
    }

    cout << "Goodbey. This was fun." << endl;

    return 0;
}