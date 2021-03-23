#include "!subsystems.h"

void Subsystems::begin()
{
    audio.begin();
    batMonitor.begin();
    goButton.begin();
    distanceSensors.begin();
    nineDOFSensor.begin();
    ir.begin();
    lights.begin();
    drivetrain.begin();
    tail.begin();
}
void Subsystems::run()
{
    drivetrain.run();
    audio.run();
    batMonitor.run();
    goButton.run();
    distanceSensors.run();
    nineDOFSensor.run();
    ir.run();
    lights.run();
    tail.run();
}