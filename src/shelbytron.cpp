//code for Shelbytron, a robot to encourage patients during physical therapy
#include "screen/screen.h"
#include "settings/settings.h"
#include "settings/settingsSD.h"
#include "shelbytron_globs.h"
#include "subsystems/subsystems.h"
#include <Arduino.h>

Screen screen = Screen();
Subsystems subsystems = Subsystems();

void setup()
{
    analogReadResolution(12);
    setupSettingsSD();
    recallAllSettingsSD();
    screen.begin();
    subsystems.begin();
}

void loop()
{
    genS.lastMode = genS.mode;
    screen.run();
    subsystems.run();
}