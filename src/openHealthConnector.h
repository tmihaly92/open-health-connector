//
// File: open-health-connector.h
// Name: Mihály Tóth
// Date: 2019.10.25.
// Desc: Example code for the Open-Health connector for Arduino
//

#ifndef openHealthConnector
#define openHealthConnector

// Include libraries  ////////////////////////////////////
#include <stdint.h>
#include <Arduino.h>
#include <Wire.h>

// Include third-party libraries //////////////////////////////////////////////////


// Open health class //////////////////////////////////////////////////////////////

class openHealth
{
    public:
        openHealth();
        void openHealth_init();                             // Initalization of the class
        void openHealth_timer_set(uint16_t minutes, uint8_t seconds);                        // Set the timer for the appropriete measurement cycle
        void openHealth_alert_set();                        // Set an alarm for defined thresholds
        virtual ~openHealth();
    private:
};

// Sensor - Motion sensors /////////////////////////////////////////

class MPU9250
{
    #define RESOLUTION 0x1
    public:
        MPU9250();
        float acc_x, acc_y, acc_z;
        float gyro_x, gyro_y, gyro_z;
        float mag_x, mag_y, mag_z;
        void MPU9250_init(uint8_t addr = 0x4c, uint16_t clock = 400);
        void MPU9250_readAcc();
        void MPU9250_readGyr();
        void MPU9250_readMag();
        void MPU9250_set();
        virtual ~MPU9250();
    private:
        uint8_t addr;
        uint8_t clock;
        uint8_t status = 0;
};

class LSM303D
{
    public:
        LSM303D();
        float acc_x, acc_y, acc_z;
        float gyro_x, gyro_y, gyro_z;
        float mag_x, mag_y, mag_z;
        void LSM303D_init(uint8_t addr = 0x1D);
        void LSM303D_readAcc();
        void LSM303D_readGyr();
        void LSM303D_readMag();
        virtual ~LSM303D();
    private:
        uint8_t addr;
        uint8_t clock;
        uint8_t status = 0;
};

class MMA7260
{
    public:
        MMA7260();
        float acc_x, acc_y, acc_z;
        void MMA7260_init(uint8_t addr = 0x4c, uint16_t clock = 400);
        void MMA7260_readAcc();
        virtual ~MMA7260();
    private:
        uint8_t addr;
        uint8_t clock;
        uint8_t status = 0;
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
        uint8_t port;
        uint8_t status = 0;
};

// Sensor - Pulse oximetry

class MAX30102
{
    public:
        MAX30102();
        float data;
        void MAX30102_init(uint8_t addr);
        void MAX30102_read();
        void MAX30102_set();
    private:
        uint8_t addr;
        uint8_t clock;
        uint8_t status = 0;
};

// Communication //////////////////////////////////////////////////

class openHealthBluetooth
{
    public:
        openHealthBluetooth();
        static void btInit();
        static void btStatus();
        static void btConnect();
        static void btSendData();
        static uint8_t btReceiveData();
        virtual ~openHealthBluetooth();
    private:
        uint8_t status = 0;
};

class openHealthWifi
{
    public:
        openHealthWifi();
        void wifiInit();
        uint8_t wifiStatus();
        void wifiConnect();
        void wifiSendData();
        uint8_t wifiReceiveData();
        virtual ~openHealthWifi();
    private:
        uint8_t status = 0;
};

class openHealthSerial
{
    public:
        openHealthSerial();
        void serialInit();
        ~openHealthSerial();
    private:
};

// Internal peripherials //////////////////////////////////////////////////////////////

float I2C_read(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data);   
uint8_t I2C_writeByte(uint8_t Address, uint8_t Register, uint8_t Data);
uint16_t analogRead(uint8_t port);
uint8_t digitalRead(uint8_t port);

#endif