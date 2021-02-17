#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "constants/drivetrainConstants.h"
#include "constants/pinout.h"
#include "wheel.h"
#include <Arduino.h>
class Drivetrain {
public:
    Drivetrain();
    void begin();
    void run();
    void setVels(float forward, float rotation);
    void setVelRot(float rotation);
    void setVelTurnRad(float forward, float radius);
    Wheel WheelL;
    Wheel WheelR;
};

#endif