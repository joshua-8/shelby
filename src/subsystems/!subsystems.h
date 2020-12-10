#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H
#include "audio.h"
#include "batMonitor.h"
#include "distanceSensors.h"
#include "goButton.h"
#include "nineDOFSensor.h"
#include "turret.h"
#include "ir.h"
class Subsystems {
public:
    Audio audio;
    BatMonitor batMonitor;
    GoButton goButton;
    DistanceSensors distanceSensors;
    NineDOFSensor nineDOFSensor;
    Turret LTurret;
    Turret RTurret;
    IR ir;

    void begin();
    void run();
};
#endif