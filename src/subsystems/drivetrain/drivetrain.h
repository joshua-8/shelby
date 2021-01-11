#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include <Arduino.h>
#include "wheel.h"
class Drivetrain {
public:
    void begin();
    void run();
    Drivetrain();
};

#endif