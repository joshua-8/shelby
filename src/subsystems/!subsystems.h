#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H
#include <Arduino.h>
#include "audio.h"
#include "batMonitor.h"
#include "distanceSensors/distanceSensors.h"
#include "goButton.h"
#include "ir.h"
#include "nineDOFSensor.h"
#include "drivetrain/drivetrain.h"
class Subsystems {
public:
    Audio audio;
    BatMonitor batMonitor;
    GoButton goButton;
    DistanceSensors distanceSensors;
    NineDOFSensor nineDOFSensor;
    IR ir;
    Drivetrain drivetrain;

    void begin();
    void run();
};
#endif