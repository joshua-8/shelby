#include "lights.h"
#include "shelbytron_globs.h"
Lights::Lights()
{
}
void Lights::begin()
{
    WheelLightL.begin(true);
    WheelLightR.begin(false);
    eyeLight.begin();
}
void Lights::run()
{
    WheelLightL.run();
    WheelLightR.run();
    eyeLight.run();
}