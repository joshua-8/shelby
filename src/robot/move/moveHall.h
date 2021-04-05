#ifndef MOVEHALL_H
#define MOVEHALL_H
#include "shelbytron_globs.h"
#include <Arduino.h>
class MoveHall {
public:
    MoveHall();
    void run();
    void begin();

private:
    float hallWidth;
    float hallError;
    float processedHallError;
    float targetRobotHeadingHall;
    float processedTargetRobotHeading;
    float hallHeading;
    float robotHeading;
    float wheelDifferential;
    float leftTurretAngle;
    float rightTurretAngle;
};
#endif