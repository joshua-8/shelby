#ifndef ROBOT_H
#define ROBOT_H
#include "entertainment.h"
#include "move/moveDrive.h"
#include "move/moveHall.h"
#include "move/moveHeading.h"
#include "move/moveSafely.h"
class Robot {
public:
    Entertainment entertainment;
    MoveDrive moveDrive;
    MoveHall moveHall;
    MoveHeading moveHeading;
    MoveSafe moveSafe;
};
static Robot robot = Robot();
#endif