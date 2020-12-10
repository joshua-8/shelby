#ifndef BAT_MONITOR_CONSTANTS_H
#define BAT_MONITOR_CONSTANTS_H
#include <Arduino.h>
class batMonitorConsts {
public:
    const float voltsPerDAC = .00785;
    const float highVoltThresh=12.75;
    const float lowVoltThresh=12.0;
    const float criticalVoltThresh=11.5;
};
static const batMonitorConsts batMonitorConstants;
#endif