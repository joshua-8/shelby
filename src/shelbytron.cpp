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
bool BAT_low_alerted = false;
bool BAT_crit_alerted = false;

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

    if (subsystems.batMonitor.getSupplyVoltage() < topSettings.lowVoltThresh) {
        if (BAT_low_alerted == false) {
            if (genS.volume < 30) {
                genS.volume = 30;
            }
            subsystems.audio.playTrackLoud(220); //I need a nap
            BAT_low_alerted = true;
        }
    }
    if (subsystems.batMonitor.getSupplyVoltage() < topSettings.criticalVoltThresh || subsystems.batMonitor.getSupplyVoltage() <= 10) {
        if (BAT_crit_alerted == false) {
            if (genS.volume < 30) {
                genS.musicMode = 0;
                genS.volume = 30;
            }
            subsystems.audio.playTrackLoud(221); //I really need a nap
            BAT_crit_alerted = true;
            go = false;
        }
    }
    if (BAT_crit_alerted) {
        genS.lightsMode = 0;
        if (go == true) {
            messageScreen.dispMessage("charge", "battery", 3000);
            subsystems.audio.playTrack(14); //low battery
        }
        go = false;
    }

    subsystems.run();

    modesRun();

    lastLoopTimeMicros = microsTimerVal;
    microsTimerVal = 0;
}