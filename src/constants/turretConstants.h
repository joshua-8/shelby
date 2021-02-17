#ifndef TURRET_CONSTANTS_H
#define TURRET_CONSTANTS_H
#include <Arduino.h>
class turretConsts {
public:
    const int baud = 19200;
    const byte left = 0;
    const byte right = 1;
    const float minAngle[2] = { -142, 15 };
    const float maxAngle[2] = { -5, 150 };
    const float minPulse[2] = { 550, 550 };
    const float maxPulse[2] = { 2275, 2275 };
};
static const turretConsts turretConstants;
#endif