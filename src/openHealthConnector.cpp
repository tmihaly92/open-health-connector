//
// File: open-health-connector.cpp
// Name: Mihály Tóth
// Date: 2019.10.25.
// Desc: Example code for the Open-Health connector for Arduino
//

// Include library descriptor //////////////////////////////////////////////////
#include "openHealthConnector.h"

// Include libraries ////////////////////////////////////
#include <stdint.h>
#include "Arduino.h"
#include "Wire.h"

// Functions //////////////////////////////////////////////////////////////////////////

openHealth::openHealth()
{
    
}

void openHealth::openHealth_init()
{
    
}

void openHealth::openHealth_timer_set(uint16_t minutes, uint8_t seconds)
{

}

void openHealth::openHealth_alert_set()
{

}

openHealth::~openHealth()
{

}



MPU9250::MPU9250()
{

}

void MPU9250::MPU9250_init(uint8_t addr, uint16_t clock)
{
    
}

void MPU9250::MPU9250_readAcc()
{
    
}

void MPU9250::MPU9250_readGyr()
{

}

void MPU9250::MPU9250_readMag()
{

}



LSM303D::LSM303D()
{

}

void LSM303D::LSM303D_init(uint8_t addr)
{

}

void LSM303D::LSM303D_readAcc()
{

}

void LSM303D::LSM303D_readGyr()
{
    gyro_x = 0;
}

void LSM303D::LSM303D_readMag()
{

}



MMA7260::MMA7260()
{

}

void MMA7260::MMA7260_init(uint8_t addr, uint16_t clock)
{

}

void MMA7260::MMA7260_readAcc()
{
    acc_y = 0;
}



float I2C_read(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data)
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

uint8_t I2C_writeByte(uint8_t Address, uint8_t Register, uint8_t Data)
{
    Wire.beginTransmission(Address);
    Wire.write(Register);
    Wire.write(Data);
    Wire.endTransmission();
}

uint16_t analogRead(uint8_t port)
{

}
