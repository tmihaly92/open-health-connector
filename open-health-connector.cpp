//
// File: open-health-connector.cpp
// Name: Mihály Tóth
// Date: 2019.10.25.
// Desc: Example code for the Open-Health connector for Arduino
//

// Include library descriptor //////////////////////////////////////////////////
#include "open-health-connector.h"

// Include basic libraries for Arduino support ////////////////////////////////////
#include "Arduino.h"
#include <Wire.h>
#include <stdint.h>

// Include third-party libraries //////////////////////////////////////////////////

// Class //////////////////////////////////////////////////////////////////////////

void openhealth::openhealth_init()
{
    
}

// Sensor drivers /////////////////////////////////////////////////////////////////


void MPU9250_init(uint8_t port)
{

}


// Communication /////////////////////////////////////////////////////////////////


// I2C ///////////////////////////////////////////////////////////////////////////

void I2C_read(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data)
{
    // Set register address
    Wire.beginTransmission(Address);
    Wire.write(Register);
    Wire.endTransmission();
 
    // Read Nbytes
    Wire.requestFrom(Address, Nbytes);
    uint8_t index = 0;
    while (Wire.available())
    {
        Data[index++]=Wire.read();
    }
}

void I2C_writeByte(uint8_t Address, uint8_t Register, uint8_t Data)
{
    Wire.beginTransmission(Address);
    Wire.write(Register);
    Wire.write(Data);
    Wire.endTransmission();
}
