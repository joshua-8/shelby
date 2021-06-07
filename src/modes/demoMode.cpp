#include "demoMode.h"
DemoMode::DemoMode()
{
}

void DemoMode::begin()
{
    mainMode = true;
    subsystems.audio.stopLong();
    subsystems.audio.stopShort();
    subsystems.lights.eyeLight.setStandard(CRGB(100, 120, 255));
    subsystems.lights.eyeLight.setBlink(CRGB(100, 0, 0), 0);
    subsystems.drivetrain.resetDist();
}
void DemoMode::run()
{
    runLights();
    runSound();

    if (genS.lightsMode != DURINGmodeLastGenS.lightsMode) {
        subsystems.lights.WheelLightL.allOff(true);
        subsystems.lights.WheelLightR.allOff(true);
    }
    if (subsystems.audio.isPlayingTrack(30)) {
        subsystems.tail.wag(2000); //wag to Luca
    } else {
        subsystems.tail.stopWag();
    }

    if (mainMode) {
        if (millis() - subsystems.ir.lastNewMsgMillis < 400 && go) {
            // subsystems.drivetrain.setVelLimit({ .5, 50, 0 });
            // if (subsystems.ir.message == irConstants.DOWN) {
            //     subsystems.distanceSensors.LTurret.setAngle(-120);
            //     subsystems.distanceSensors.RTurret.setAngle(120);
            //      subsystems.drivetrain.movePos({ -.1, 0, 0 });
            // }
            // if (subsystems.ir.message == irConstants.UP) {
            // subsystems.distanceSensors.LTurret.setAngle(-60);
            // subsystems.distanceSensors.RTurret.setAngle(60);
            //     subsystems.drivetrain.movePos({ .3, 0, 0 });
            // }
            // if (subsystems.ir.message == irConstants.RIGHT)
            //     subsystems.drivetrain.movePos({ .3, 45, 0 });
            // if (subsystems.ir.message == irConstants.LEFT)
            //     subsystems.drivetrain.movePos({ .3, -45, 0 });
            robot.moveSafe.setVelsSafe(demoModePresetSettings[genS.preset].manualDriveSpeed * (1 * (subsystems.ir.message == irConstants.UP) - 1 * (subsystems.ir.message == irConstants.DOWN)), demoModePresetSettings[genS.preset].manualTurnSpeed * (1 * (subsystems.ir.message == irConstants.RIGHT) - 1 * (subsystems.ir.message == irConstants.LEFT)));
        } else {
            subsystems.drivetrain.moveVel({ 0, 0, 0 });
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

    DURINGModeLastGo = go;
    DURINGmodeLastGenS = genS;
    runGenIR();
    runGenGoStopButton();
}

void DemoMode::runLights()
{
    if (genS.lightsMode == 0) {
        subsystems.lights.eyeLight.setBlinkOff();
        subsystems.lights.eyeLight.setMode(EyeLight::OFF);
    }
    if (genS.lightsMode == 1) {
        subsystems.lights.eyeLight.setMode(EyeLight::NORMAL);
        subsystems.lights.eyeLight.setBlinkOff();
        if (subsystems.audio.isPlayingShort() || subsystems.audio.isPlayingTrack(30)) {
            subsystems.lights.eyeLight.setStandard(CRGB(255, 0, 255));
        } else if (subsystems.audio.isPlayingLong()) {
            subsystems.lights.eyeLight.setStandard(CRGB(0, 55, 0));
        } else {
            subsystems.lights.eyeLight.setStandard(CRGB(0, 0, 0));
        }
    }
    if (genS.lightsMode == 2) {
        if (subsystems.audio.isPlayingShort() || subsystems.audio.isPlayingTrack(30)) {
            subsystems.lights.eyeLight.setMode(EyeLight::RAINBOW);
            subsystems.lights.eyeLight.setBlinkOff();
        } else {
            subsystems.lights.eyeLight.setMode(EyeLight::NORMAL);
            subsystems.lights.eyeLight.setBlink(CRGB(0, 0, 0), 2000);
            subsystems.lights.eyeLight.setStandard(CRGB(50, 100, 255));
        }
    }
}
void DemoMode::runSound()
{

    if (genS.musicMode == 0) { //off
        if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.OK && mainMode) {
            subsystems.audio.playTrack(30); //say hi to Luca
        }
    }

    if (genS.musicMode == 1) { //short
        if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.OK && mainMode) {
            subsystems.audio.playNextShort();
        }
    }

    if (genS.musicMode == 2) {
        robot.entertainment.playConstantMusicLongIR();
    }
}