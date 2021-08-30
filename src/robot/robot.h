#ifndef ROBOT_H
#define ROBOT_H
#include "entertainment.h"
#include "move/moveHall.h"
#include "move/moveHeading.h"
#include "move/moveSafely.h"
#include "lights.h"

class Robot {
public:
    Entertainment entertainment;
    MoveHall moveHall;
    MoveHeading moveHeading;
    MoveSafe moveSafe;
    RobotLights rLights;
};
static Robot robot = Robot();
#endif