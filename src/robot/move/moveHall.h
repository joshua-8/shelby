#ifndef MOVEHALL_H
#define MOVEHALL_H
#include "shelbytron_globs.h"
#include <Arduino.h>
class MoveHall {
public:
    MoveHall();
    void run(float speed, boolean safe);
    void begin();

private:
    float hallTargetHeading;
    float hallWidth;
    float hallError;
    float processedHallError;
    float targetRobotHeadingHall;
    float targetRobotHeading;
    float processedTargetRobotHeading;
    float hallHeading;
    float robotHeading;
    float leftTurretAngle;
    float rightTurretAngle;
};
#endif