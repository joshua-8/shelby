//code for Shelbytron, a robot to encourage patients during physical therapy
#include "modes/modes.h"
#include "screen/msgScreen.h"
#include "screen/screen.h"
#include "settings/settings.h"
#include "settings/settingsSD.h"
#include "shelbytron_globs.h"
#include "subsystems/!subsystems.h"
#include <Arduino.h>

Screen screen = Screen(&messageScreen);
Subsystems subsystems = Subsystems();
boolean go = false;
boolean DURINGModeLastGo = false;
MsgScreen messageScreen = MsgScreen(&subsystems.ir);
elapsedMicros microsTimerVal = 0;
unsigned long lastLoopTimeMicros = 0;

void setup()
{
    Serial.begin(9600);
    analogReadResolution(12);
    setupSettingsSD();
    recallAllSettingsSD();
    go = false;
    DURINGModeLastGo = false;
    subsystems.begin();
    screen.begin();

    lastLoopTimeMicros = 0;
    microsTimerVal = 0;
}

void loop()
{
    screen.run();
    subsystems.run();

    modesRun();

    lastLoopTimeMicros = microsTimerVal;
    microsTimerVal = 0;
}