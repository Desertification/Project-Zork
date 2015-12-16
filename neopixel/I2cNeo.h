#ifndef I2CNEO_H
#define I2CNEO_H

#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime> 

class I2cNeo
{
public:
I2cNeo(std::string i2c_device, int i2c_address);
void sendMultiColor(int led, int red, int green, int blue);
void sendSingleColor(int red, int green, int blue);
void blink(int blink, int red, int green, int blue);

private:
std::string i2c_device;
int i2c_address;
int red;

int file;

};



#endif