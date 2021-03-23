#ifndef ROBOT_H
#define ROBOT_H
#include "entertainment.h"
#include "move/moveDrive.h"
#include "move/moveSafely.h"
class Robot {
public:
    MoveDrive moveDrive;
    MoveSafe moveSafe;
    Entertainment entertainment;
};
static Robot robot = Robot();
#endif