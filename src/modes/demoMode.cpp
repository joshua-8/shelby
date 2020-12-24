#include "demoMode.h"
DemoMode::DemoMode()
{
}

void DemoMode::begin()
{
    subsystems.audio.stopLong();
    subsystems.audio.stopShort();
}
void DemoMode::run()
{
    if (genS.musicMode == 2) {
        entertainment.playConstantMusicLongIR();
    }

    if (genS.musicMode == 1) { //short
        if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.OK) {
            subsystems.audio.playNextShort();
        }
    }

    runGenIR();
    runGenGoStopButton();
}