#ifndef DRIVE_MODE_H
#define DRIVE_MODE_H
#include "constants/irConstants.h"
#include "robot/altIR.h"
#include "robot/genGoStopButton.h"
#include "robot/robot.h"
#include "settings/settings.h"
#include "shelbytron_globs.h"
#include <Arduino.h>
class DriveMode {
public:
    DriveMode();
    void begin();
    void run();

private:
    bool youdrive;
    void runLights();
    void runSound();
};
static DriveMode drivemode = DriveMode();
#endif