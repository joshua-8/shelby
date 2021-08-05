#ifndef TAG_MODE_H
#define TAG_MODE_H
#include "constants/irConstants.h"
#include "robot/genGoStopButton.h"
#include "robot/genIR.h"
#include "robot/robot.h"
#include "settings/settings.h"
#include "shelbytron_globs.h"
#include <Arduino.h>
class TagMode {
public:
    TagMode();
    void begin();
    void run();
    float drivingStartDistance;
    byte where;

private:
    void runLights();
    void runSound();
    bool sweepDir;
    bool justStarted = true;

    enum States {
        DRIVING_HALL,
        DRIVING_CORNER,
        STARTING_TURN,
        WAITING,
        ENDING_TURN,
        STOPPING_DRIVING,
        STOPPING_ENDING_TURN,
        DRIVING_CORNER_DRIVE,
        END_HALL_DRIVE,
        TURNING_180A,
        TURNING_180B,
        TURNING_180C
    };
    States state;
    States lastState;
    bool encourage;

    void resetAtStartOfHall()
    {
        robot.moveHall.begin();
        drivingStartDistance = 0;
    }
};
static TagMode tagmode = TagMode();
#endif