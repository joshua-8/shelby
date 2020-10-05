#ifndef BAT_MONITOR_CONSTANTS_H
#define BAT_MONITOR_CONSTANTS_H
#include <Arduino.h>
class batMonitorConsts {
public:
    const float voltsPerDAC = .00785;
};
static batMonitorConsts batMonitorConstants;
#endif