#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H
#include "audio.h"
#include "batMonitor.h"
class Subsystems {
public:
    Audio audio;
    BatMonitor batMonitor;
    void begin();
    void run();
};
#endif