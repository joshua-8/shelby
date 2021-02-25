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
        robot.entertainment.playConstantMusicLongIR();
    }

    if (genS.lightsMode != DURINGmodeLastGenS.lightsMode) {
        subsystems.lights.WheelLightL.allOff(true);
        subsystems.lights.WheelLightR.allOff(true);
    }

    if (genS.musicMode == 0) { //off
        if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.OK) {
            subsystems.audio.playTrack(30); //say hi to Luca
        }
    }

    if (genS.musicMode == 1) { //short
        if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.OK) {
            subsystems.audio.playNextShort();
        }
    }
    if (mainMode) {
        if (millis() - subsystems.ir.lastNewMsgMillis < 150 && go) {
            robot.moveSafe.setVelsSafe(demoModePresetSettings[genS.preset].manualDriveSpeed * (1 * (subsystems.ir.message == irConstants.UP) - 1 * (subsystems.ir.message == irConstants.DOWN)), demoModePresetSettings[genS.preset].manualTurnSpeed * (1 * (subsystems.ir.message == irConstants.RIGHT) - 1 * (subsystems.ir.message == irConstants.LEFT)));
        } else {
            subsystems.drivetrain.WheelL.setVel(0);
            subsystems.drivetrain.WheelR.setVel(0);
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
    DURINGmodeLastGenS = genS;
    runGenIR(); //remove for demo mode?
    runGenGoStopButton();
}