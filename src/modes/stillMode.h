#ifndef STILL_MODE_H
#define STILL_MODE_H
#include "constants/irConstants.h"
#include "robot/genGoStopButton.h"
#include "robot/altIR.h"
#include "robot/robot.h"
#include "settings/settings.h"
#include "shelbytron_globs.h"
#include <Arduino.h>
class StillMode {
public:
    StillMode();
    void begin();
    void run();

private:
    void runLights();
    void runSound();
};
static StillMode stillmode = StillMode();
#endif