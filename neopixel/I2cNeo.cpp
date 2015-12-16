#include "I2cNeo.h"

using namespace std;


I2cNeo::I2cNeo(string i2c_device, int i2c_address) {
	this->i2c_device=i2c_device;
	this->i2c_address=i2c_address;

	//std::cout << "Starting up the i2c" << std::endl;
	//std::cout << "Trying to open I2c device '" << i2c_device << "' for reading and writing" << std::endl;
	//Open de i2c en controleer of dit gelukt is
	file = open(i2c_device.c_str(), O_RDWR);
    if (file < 0) {
        //std::cout << "Could not open i2c device. Exiting ..." << std::endl;
        //exit(-1);
    }

    // Aquire bus
    if (ioctl(file, I2C_SLAVE, i2c_address) < 0) {
        //cout << "Failed to acquire bus access and/or talk to slave." << endl;
        //exit(-1);
    }
    
    // Lets check how many strings are attached to the mbed controller
    char buffer[10];

    // We can just use the file read function
    int ret = read(file, buffer, 1);        // 1 = the number of bytes to read
    if (ret != 1) {
        //std::cout << "Failed to read from the i2c bus with ret = " << ret << std::endl;
    } else {
        //std::cout << "NeoPixel driver has " << (int)buffer[0] << " strings attached" << std::endl;

    }
    sleep(1);

}

void I2cNeo::sendMultiColor(int led, int red, int green, int blue) {
	char color[5];
    color[0] = 4;
    color[1] = led;
    color[2] = red;
    color[3] = green;
    color[4] = blue;
    int ret = write(file, color, sizeof(color));
    if (ret != sizeof(color)) {
        //std::cout << "Failed to write to the I2c bus (diagnostic command) with ret = " << ret << std::endl;
    }
}

void I2cNeo::sendSingleColor(int red, int green, int blue) {
    char color[] = { 0x03, 0x00, 0x00, 0x00 };
    color[1] = red;
    color[2] = green;
    color[3] = blue;
    int ret = write(file, color, sizeof(color));
    if (ret != sizeof(color)) {
        //std::cout << "Failed to write to the I2c bus (diagnostic command) with ret = " << ret << std::endl;
    }
}

void I2cNeo::blink(int blink, int red, int green, int blue) {
    char color[5];
    color[0] = 5;
    color[1] = blink;
    color[2] = red;
    color[3] = green;
    color[4] = blue;
    int ret = write(file, color, sizeof(color));
    if (ret != sizeof(color)) {
        //std::cout << "Failed to write to the I2c bus (diagnostic command) with ret = " << ret << std::endl;
    }
}