#ifndef CHASE_MODE_H
#define CHASE_MODE_H
#include "constants/irConstants.h"
#include "robot/genGoStopButton.h"
#include "robot/genIR.h"
#include "robot/robot.h"
#include "settings/settings.h"
#include "shelbytron_globs.h"
#include <Arduino.h>
class ChaseMode {
public:
    ChaseMode();
    void begin();
    void run();

private:
    boolean forwards = true;
};
static ChaseMode chasemode = ChaseMode();
#endif