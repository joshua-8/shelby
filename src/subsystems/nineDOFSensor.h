#ifndef NINE_DOF_SENSOR
#define NINE_DOF_SENSOR
#include "Adafruit_BNO055.h"
#include "constants/pinout.h"
#include <Arduino.h>
class NineDOFSensor {
public:
    NineDOFSensor();
    void begin();
    void run();

private:
    Adafruit_BNO055 bno055;
};
#endif