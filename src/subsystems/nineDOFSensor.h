#ifndef NINE_DOF_SENSOR
#define NINE_DOF_SENSOR
#include "constants/pinout.h"
#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <Wire.h>
#include <utility/imumaths.h>
#include "settings/settings.h"
class NineDOFSensor {
public:
    NineDOFSensor();
    void begin();
    void run();

    float heading, pitch, roll;
    imu::Quaternion quat;
    imu::Vector<3> accel;
    imu::Vector<3> gyro;

private:
    Adafruit_BNO055 bno055 = Adafruit_BNO055(55, 0x28, &Wire2);
    uint8_t systemCal, gyroCal, accelCal, magCal;
    imu::Vector<3> eulerOri;
};
#endif