//code for Shelbytron, a robot to encourage patients during physical therapy
#include "modes/modes.h"
#include "screen/msgScreen.h"
#include "screen/screen.h"
#include "settings/settings.h"
#include "settings/settingsSD.h"
#include "shelbytron_globs.h"
#include "subsystems/!subsystems.h"
#include <Arduino.h>

MsgScreen messageScreen = MsgScreen();
Screen screen = Screen(&messageScreen);
Subsystems subsystems = Subsystems();
boolean go = false;

void setup()
{
    Serial.begin(9600);
    analogReadResolution(12);
    setupSettingsSD();
    recallAllSettingsSD();
    go=false;
    subsystems.begin();
    screen.begin();
    demomode.begin();
}

void loop()
{
    screen.run();
    subsystems.run();
    lastGenS = genS;
    demomode.run();
}