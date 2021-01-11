#ifndef BAT_MONITOR_H
#define BAT_MONITOR_H
#include "constants/batMonitorConstants.h"
#include "constants/pinout.h"
#include <Arduino.h>
class BatMonitor {
public:
    BatMonitor();
    void begin();
    void run();
    float getBatVolt();
    float readRawVoltage();

private:
    float voltage;
    float rawVoltage;
};
#endif