#ifndef GENGOSTOPBUTTON_H
#define GENGOSTOPBUTTON_H
#include "shelbytron_globs.h"
static void runGenGoStopButton()
{
    if (subsystems.goButton.justReleased()) {
        go = !go;
    }
    if (go) {
        subsystems.goButton.setColor(CRGB(255, 255, 170));
    } else {
        subsystems.goButton.fade(CRGB(4, 4, 18), 1500, CRGB(120, 120, 255), 1000);
    }
}

#endif