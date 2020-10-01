//code for Shelbytron, a robot to encourage patients during physical therapy
#include "screen/screen.h"
#include "settings/settings.h"
#include "settings/settingsSD.h"
#include "subsystems/subsystems.h"
#include <Arduino.h>

Screen screen = Screen();

void setup()
{
    Serial.begin(250000);
    analogReadResolution(12);
    setupSettingsSD();
    recallAllSettingsSD();
    screen.begin();
    //subsystems.begin();
}

void loop()
{
    genS.lastMode = genS.mode;
    screen.run();
    //subsystems.run();
}