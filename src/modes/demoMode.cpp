#include "demoMode.h"
DemoMode::DemoMode()
{
}

void DemoMode::begin()
{
    mainMode = true;
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
    if (mainMode) {
        if (millis() - subsystems.ir.lastNewMsgMillis < 150 && go) {
            if (subsystems.ir.message == irConstants.UP) {
                subsystems.drivetrain.WheelL.setVel(.1);
            } else if (subsystems.ir.message == irConstants.DOWN) {
                subsystems.drivetrain.WheelL.setVel(-.1);
            } else {
                subsystems.drivetrain.WheelL.setVel(0);
            }
        } else {
            subsystems.drivetrain.WheelL.setVel(0);
        }
    }

    ////////////////////////////////////////////////////////manual track select
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.AUX) {
        messageScreen.dispValSelector("trk", 4, 0);
        mainMode = false;
    }
    if (messageScreen.valSelectorDone()) {
        mainMode = true;
        if (subsystems.audio.isPlayingTrack(messageScreen.valSelectorValue())) {
            subsystems.audio.stopTrack(messageScreen.valSelectorValue());
        } else {
            subsystems.audio.playTrack(messageScreen.valSelectorValue());
        }
    }

    runGenIR(); //remove for demo mode?
    runGenGoStopButton();
}