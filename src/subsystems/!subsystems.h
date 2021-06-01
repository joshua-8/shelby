#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H
#include "audio.h"
#include "constants/drivetrainConstants.h"
#include "distanceSensors/distanceSensors.h"
#include "drivetrain/drivebase.h"
#include "goButton.h"
#include "head.h"
#include "ir.h"
#include "lights/lights.h"
#include "nineDOFSensor.h"
#include "tail.h"
#include <Arduino.h>
class Subsystems {
public:
    Audio audio;
    GoButton goButton;
    DistanceSensors distanceSensors;
    NineDOFSensor nineDOFSensor;
    IR ir;
    Drivebase drivebase;
    JDrivetrainControllerBasic& drivetrain = drivebase.drivetrain;
    Lights lights;
    Tail tail;
    Head head;
    JVoltageCompMeasure<32> batMonitor = JVoltageCompMeasure<32>(BAT_MONITOR_PIN, drivetrainConstants.batMon);
    void begin();
    void run();
};
#endif