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

    if (genS.musicMode == 1) { //music low
        if (subsystems.goButton.justPressed()) {
            subsystems.audio.stopShort();
        }
        if (subsystems.goButton.isPressed() && (subsystems.goButton.getTimeSincePressed() > 500 || !subsystems.audio.isPlayingShort())) {
            if (subsystems.goButton.usePress()) {
                subsystems.audio.playNextShort();
            }
        }
    }
    if (genS.musicMode == 2) { //music high
        if (subsystems.goButton.justPressed()) {
            subsystems.audio.stopLong();
        }
        if (subsystems.goButton.isPressed() && (subsystems.goButton.getTimeSincePressed() > 500 || !subsystems.audio.isPlayingLong())) {
            if (subsystems.goButton.usePress()) {
                subsystems.audio.playNextLong();
            }
        }
    }
    lastGenS = genS;
}