#include "!subsystems.h"

void Subsystems::begin()
{
    audio.begin();
    goButton.begin();
    distanceSensors.begin();
    nineDOFSensor.begin();
    ir.begin();
    lights.begin();
    drivebase.begin();
    tail.begin();
    head.begin();
}
void Subsystems::run()
{
    drivebase.run();
    audio.run();
    goButton.run();
    distanceSensors.run();
    nineDOFSensor.run();
    ir.run();
    lights.run();
    tail.run();
    head.run();
}