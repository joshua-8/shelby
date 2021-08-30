#ifndef DRIVETRAIN_CONSTANTS_H
#define DRIVETRAIN_CONSTANTS_H
#include <Arduino.h>
class drivetrainConsts {
public:
    float wheelbase = 0.59; //meters
    float batMon = 127; //DAC units per volt, larger value=lower reading
};
static const drivetrainConsts drivetrainConstants;
#endif