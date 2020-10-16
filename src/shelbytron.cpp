//code for Shelbytron, a robot to encourage patients during physical therapy
#include "screen/screen.h"
#include "settings/settings.h"
#include "settings/settingsSD.h"
#include "shelbytron_globs.h"
#include "subsystems/!subsystems.h"
#include <Arduino.h>

Screen screen = Screen();
Subsystems subsystems = Subsystems();

void setup()
{
    Serial.begin(9600);
    analogReadResolution(12);
    setupSettingsSD();
    recallAllSettingsSD();
    screen.begin();
    subsystems.begin();
}

void loop()
{
    screen.run();
    subsystems.run();

    lastGenS = genS;
}