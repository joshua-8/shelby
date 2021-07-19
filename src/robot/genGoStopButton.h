#ifndef GENGOSTOPBUTTON_H
#define GENGOSTOPBUTTON_H
#include "shelbytron_globs.h"
static void runGenGoStopButton()
{
    if (subsystems.goButton.justReleased()) {
        go = !go;
    }
    if (go) {
        subsystems.goButton.setColor(CRGB(250, 250, 200));
    } else {
        subsystems.goButton.fade(CRGB(2, 2, 10), 1500, CRGB(150, 150, 250), 1000);
    }
}

#endif