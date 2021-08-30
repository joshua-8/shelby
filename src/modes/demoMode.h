#ifndef DEMO_MODE_H
#define DEMO_MODE_H
#include "constants/irConstants.h"
#include "robot/genGoStopButton.h"
#include "robot/genIR.h"
#include "robot/robot.h"
#include "shelbytron_globs.h"
#include <Arduino.h>
class DemoMode {
public:
    DemoMode();
    void begin();
    void run();
    void runLights();
    void runSound();

private:
    boolean mainMode = true;
    int song = 1;
};
static DemoMode demomode = DemoMode();
#endif