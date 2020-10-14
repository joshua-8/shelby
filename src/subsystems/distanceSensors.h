#ifndef DIST_SENSORS_H
#define DIST_SENSORS_H
#include "constants/irDistConstants.h"
#include "irDist.h"
#include "constants/pinout.h"
#include "constants/irDistConstants.h"
#include <Arduino.h>
class DistanceSensors {
public:
    DistanceSensors();
    void begin();
    void run();
    IRDist RDist;
    IRDist FDist;
    IRDist LDist;
    IRDist BDist;

private:
    void beginAll();
    void runAll();
};

#endif