#include "!subsystems.h"
void Subsystems::begin()
{
    audio.begin();
    batMonitor.begin();
    goButton.begin();
}
void Subsystems::run()
{
    audio.run();
    batMonitor.run();
    goButton.run();
}