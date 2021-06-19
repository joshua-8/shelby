#include "chaseMode.h"
#include "shelbytron_globs.h"
ChaseMode::ChaseMode()
{
    forwards = true;
}
void ChaseMode::begin()
{
    subsystems.audio.stopLong();
    subsystems.audio.stopShort();
    robot.moveHall.begin();
}
void ChaseMode::run()
{

    runSound();
    runLights();

    if (go && !DURINGModeLastGo) {
        begin();
    }
    if (subsystems.ir.newMsg && subsystems.ir.message == irConstants.OK && !subsystems.ir.repeat) {
        forwards = !forwards;
        begin();
    }
    subsystems.drivetrain.setVelLimitY(chaseModePresetSettings[genS.preset].speed);
    if (go) {
        if (forwards) {
            // robot.moveHeading.driveHeading(0, chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
            robot.moveHall.run(chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
        } else {
            // robot.moveHeading.driveHeading(0, -chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
            robot.moveHall.run(-chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
        }
    }

    DURINGModeLastGo = go;
    DURINGmodeLastGenS = genS;
    runGenIR();
    runGenGoStopButton();
}

void ChaseMode::runSound()
{

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

    if (genS.musicMode == 2) {
        robot.entertainment.playConstantMusicLongIR();
    }
}

void ChaseMode::runLights()
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