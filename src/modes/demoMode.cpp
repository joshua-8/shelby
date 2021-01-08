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

    ////////////////////////////////////////////////////////manual track select
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.AUX) {
        messageScreen.dispValSelector("trk", 4, 0);
    }
    if (messageScreen.valSelectorDone()) {
        if (subsystems.audio.isPlayingTrack(messageScreen.valSelectorValue())) {
            subsystems.audio.stopTrack(messageScreen.valSelectorValue());
        } else {
            subsystems.audio.playTrack(messageScreen.valSelectorValue());
        }
    }

    runGenIR(); //remove for demo mode?
    runGenGoStopButton();
}