#ifndef ROBOT_H
#define ROBOT_H
#include "move/moveSafely.h"
#include "entertainment.h"
class Robot {
public:
    MoveSafe moveSafe;
    Entertainment entertainment;
};
static Robot robot = Robot();
#endif