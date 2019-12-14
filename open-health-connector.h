//
// File: open-health-connector.h
// Name: Mihály Tóth
// Date: 2019.10.25.
// Desc: Example code for the Open-Health connector for Arduino
//

#ifndef open-health-connector
#define open-health-connector

// Include basic libraries for Arduino support ////////////////////////////////////
#include "Arduino.h"
#include <Wire.h>
#include <stdint.h>

// Include third-party libraries //////////////////////////////////////////////////


// Open health class //////////////////////////////////////////////////////////////

class openhealth
{
    public:
        openhealth();
        void openhealth_init();                             // Initalization of the class
        void openhealth_timer_set();                        // Set the timer for the appropriete measurement cycle
        void openhealth_alert_set();                        // Set an alarm for defined thresholds
        virtual ~openhealth();
    private:
};

// Sensor - Motion sensors /////////////////////////////////////////

class MPU9250
{
    public:
        MPU9250();
        float acc_x, acc_y, acc_z;
        float gyro_x, gyro_y, gyro_z;
        float mag_x, mag_y, mag_z;
        const void MPU9250_init(uint8_t addr = 0x68);
        const void MPU9250_read();
        virtual ~MPU9250();
    private:
    
};

class LSM303D
{
    public:
        LSM303D();
        float acc_x, acc_y, acc_z;
        float gyro_x, gyro_y, gyro_z;
        float mag_x, mag_y, mag_z;
        const void LSM303D_init(uint8_t addr = 0x1D);
        const void LSM303D_read();
        virtual ~LSM303D();
    private:
};

class MMA7260
{
    public:
        MMA7260();
        float acc_x, acc_y, acc_z;
        void MMA7260_init(uint8_t addr = 0x4c);
        void MMA7260_read();
        virtual ~MMA7260();
    private:
};

// Sensor - ECG ////////////////////////////////////////////////////////

class AD8232
{
    public:
        AD8232();
        float data;
        void MMA7260_init(uint8_t port);
        void MMA7260_read();
        virtual ~AD8232();
    private:
};

// Communication - Bluetooth //////////////////////////////////////////////////

// Communication - ESP ////////////////////////////////////////////////////////



// Communication //////////////////////////////////////////////////////////////

float I2C_read(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data);   
uint8_t I2C_writeByte(uint8_t Address, uint8_t Register, uint8_t Data);
float analogRead(uint8_t port);

#endif