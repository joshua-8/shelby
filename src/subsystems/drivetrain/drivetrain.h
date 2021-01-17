#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include <Arduino.h>
#include "wheel.h"
#include "constants/pinout.h"
class Drivetrain {
public:
    Drivetrain();
    void begin();
    void run();
    Wheel WheelL;
    Wheel WheelR;
};

#endif