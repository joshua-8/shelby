#ifndef GENGOSTOPBUTTON_H
#define GENGOSTOPBUTTON_H
#include "shelbytron_globs.h"
static void runGenGoStopButton()
{
    if (subsystems.goButton.justReleased()) {
        go = !go;
    }
    if (go) {
        subsystems.goButton.setColor(CRGB(200, 250, 255));
    } else {
        subsystems.goButton.fade(CRGB(2, 2, 2), 1500, CRGB(150, 150, 150), 1000);
    }
}

#endif