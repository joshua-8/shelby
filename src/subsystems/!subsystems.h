#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H
#include "audio.h"
#include "batMonitor.h"
#include "goButton.h"
#include "distanceSensors.h"
class Subsystems {
public:
    Audio audio;
    BatMonitor batMonitor;
    GoButton goButton;
    DistanceSensors distanceSensors;
    void begin();
    void run();
};
#endif