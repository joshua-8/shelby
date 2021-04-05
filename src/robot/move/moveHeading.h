#ifndef MOVEHEADING_H
#define MOVEHEADING_H
#include "shelbytron_globs.h"
#include <Arduino.h>
class MoveHeading {
public:
    MoveHeading();
    void driveHeading(float heading, float speed, boolean safe);
    void resetZero();

private:
};
#endif