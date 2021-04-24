#ifndef ROBOT_H
#define ROBOT_H
#include "entertainment.h"
#include "move/moveDrive.h"
#include "move/moveHall.h"
#include "move/moveHeading.h"
#include "move/moveSafely.h"

#include "sense/senseWallDeriv.h"

class Robot {
public:
    Entertainment entertainment;
    MoveDrive moveDrive;
    MoveHall moveHall;
    MoveHeading moveHeading;
    MoveSafe moveSafe;

    SenseWallDeriv leftWallDerivSensor;
    SenseWallDeriv rightWallDerivSensor;
};
static Robot robot = Robot();
#endif