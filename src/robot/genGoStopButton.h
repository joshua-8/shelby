#ifndef GENGOSTOPBUTTON_H
#define GENGOSTOPBUTTON_H
#include "shelbytron_globs.h"
static void runGenGoStopButton()
{
    if (subsystems.goButton.justReleased()) {
        go = !go;
    }
    if (go) {
        if (BAT_crit_alerted)
            subsystems.goButton.setColor(CRGB(255, 0, 0));
        else if (BAT_low_alerted)
            subsystems.goButton.setColor(CRGB(255, 255, 0));
        else
            subsystems.goButton.setColor(CRGB(255, 255, 170));
    } else {
        if (BAT_crit_alerted)
            subsystems.goButton.fade(CRGB(4, 0, 0), 1500, CRGB(120, 0, 0), 1000);
        else if (BAT_low_alerted)
            subsystems.goButton.fade(CRGB(4, 0, 0), 1500, CRGB(120, 120, 0), 1000);
        else
            subsystems.goButton.fade(CRGB(4, 4, 18), 1500, CRGB(120, 120, 255), 1000);
    }
}

#endif