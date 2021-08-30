#ifndef TAIL_H
#define TAIL_H
#include "constants/pinout.h"
#include "constants/tailConstants.h"
#include <Arduino.h>
#include <Servo.h>
class Tail {
public:
    Tail();
    void begin();
    void run();
    void wag(unsigned int _period);
    void stopWag();
    unsigned int getWagPeriod();

private:
    Servo servo;
    unsigned int period;
    int pos;
    boolean increa;
};

#endif