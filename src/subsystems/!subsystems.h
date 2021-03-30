#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H
#include "audio.h"
#include "batMonitor.h"
#include "distanceSensors/distanceSensors.h"
#include "drivetrain/drivetrain.h"
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
    BatMonitor batMonitor;
    GoButton goButton;
    DistanceSensors distanceSensors;
    NineDOFSensor nineDOFSensor;
    IR ir;
    Drivetrain drivetrain;
    Lights lights;
    Tail tail;
    Head head;

    void begin();
    void run();
};
#endif