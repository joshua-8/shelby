#ifndef MOVEHALL_H
#define MOVEHALL_H
#include "shelbytron_globs.h"
#include <Arduino.h>
class MoveHall {
public:
    MoveHall();
    void run(float speed, boolean safe);
    void begin();
    float getHallHeading();

private:
    float hallTargetHeading;
    float hallWidth;
    float hallError;
    float targetRobotHeadingHall;
    float targetRobotHeading;
    float processedTargetRobotHeading;
    float hallHeading;
    float hallHeadingProcessed;
    float robotHeading;
    float leftTurretAngle;
    float rightTurretAngle;
    float leftDist;
    float rightDist;
    float lastLeftDist;
    float lastRightDist;
    float leftDelta;
    float rightDelta;
    float delta;
    float goodReadingDist;
    bool leftValid;
    bool rightValid;
    float lastDriveDist;
    float driveDeltaDist;
    float instantAngle;
};
#endif