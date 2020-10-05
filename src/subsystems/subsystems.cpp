#include "subsystems.h"
void Subsystems::begin()
{
    audio.begin();
    batMonitor.begin();
}
void Subsystems::run()
{
    audio.run();
    batMonitor.run();
}