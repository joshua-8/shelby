#include "!subsystems.h"
void Subsystems::begin()
{
    audio.begin();
    batMonitor.begin();
    goButton.begin();
    distanceSensors.begin();
    nineDOFSensor.begin();
}
void Subsystems::run()
{
    audio.run();
    batMonitor.run();
    goButton.run();
    distanceSensors.run();
    nineDOFSensor.run();
}