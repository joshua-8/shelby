#ifndef IR_DIST_H
#define IR_DIST_H
#include "constants/irDistConstants.h"
#include <Arduino.h>
class IRDist {
public:
    IRDist();
    void begin(byte _pin, irDistConsts _consts);
    void run();
    float getDist();

private:
    byte pin;
    irDistConsts consts;
    float dist;
};

#endif