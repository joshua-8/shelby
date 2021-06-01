#ifndef DRIVETRAIN_CONSTANTS_H
#define DRIVETRAIN_CONSTANTS_H
#include <Arduino.h>
class drivetrainConsts {
public:
    float wheelbase = 0.605; //meters
    float batMon = 127.4;
};
static const drivetrainConsts drivetrainConstants;
#endif