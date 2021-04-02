#ifndef WHEEL_CONSTANTS_H
#define WHEEL_CONSTANTS_H
#include <Arduino.h>
class wheelConsts {
public:
    const unsigned int ticksPerRevolution = 497;
    const float ticksPerMeter = ticksPerRevolution * 1 / (PI * .272); //wheel diameter
    const int leftMagPos = 100;
    const int rightMagPos = 100;
    const float maxSpeedCalcInterval = 100000;
};
static const wheelConsts wheelConstants;
#endif