#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H
#include "audio.h"
#include "batMonitor.h"
#include "goButton.h"
class Subsystems {
public:
    Audio audio;
    BatMonitor batMonitor;
    GoButton goButton;
    void begin();
    void run();
};
#endif