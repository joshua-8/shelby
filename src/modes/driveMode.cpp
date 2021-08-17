#include "driveMode.h"
DriveMode::DriveMode()
{
}
void DriveMode::begin()
{
    youdrive = true;
    subsystems.drivetrain.resetDist();
    robot.moveHall.begin();
}
void DriveMode::run()
{
    subsystems.head.setServosEnabled(go);

    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.OK) {
        youdrive = !youdrive;
        if (youdrive) {
            subsystems.audio.playTrackOthersQuiet(229);
        } else {
            robot.moveHall.begin();
            subsystems.audio.playTrackOthersQuiet(228);
        }
    }

    if (go) {
        if (youdrive) {
            if (millis() - subsystems.ir.lastNewMsgMillis < 400) {
                subsystems.drivetrain.setVelLimitY(driveModePresetSettings[genS.preset].manualDriveSpeed);
                robot.moveSafe.setVelsSafe(driveModePresetSettings[genS.preset].manualDriveSpeed * (1 * (subsystems.ir.message == irConstants.UP) - 1 * (subsystems.ir.message == irConstants.DOWN)), demoModePresetSettings[genS.preset].manualTurnSpeed * (1 * (subsystems.ir.message == irConstants.RIGHT) - 1 * (subsystems.ir.message == irConstants.LEFT)));
            } else {
                subsystems.drivetrain.moveVel({ 0, 0, 0 });
            }
        } else { //helpdrive
            subsystems.drivetrain.setVelLimitY(driveModePresetSettings[genS.preset].hallSpeed);

            if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.UP) {
                if (!subsystems.ir.repeat)
                    robot.moveHall.begin();
                robot.moveHall.run(driveModePresetSettings[genS.preset].hallSpeed, true);
            } else if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.DOWN) {
                if (!subsystems.ir.repeat)
                    robot.moveHall.begin();
                robot.moveHall.run(-driveModePresetSettings[genS.preset].hallSpeed, true);
            } else if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.LEFT) {
                if (!subsystems.ir.repeat)
                    subsystems.drivetrain.moveDistRZInc(-90);
            } else if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.RIGHT) {
                if (!subsystems.ir.repeat)
                    subsystems.drivetrain.moveDistRZInc(90);
            } else {
                subsystems.drivetrain.moveVel({ 0, 0, 0 });
            }
        }
    }

    runSound();
    runLights();

    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.WORD_MODE) {
        //celebrate
        subsystems.audio.playWordMode(-10);
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.LIGHTS_MODE) {
        //encourage
        subsystems.audio.playWordMode(DRIVE_MODE_ID);
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.MUSIC_LIST) {
        //goodbye
        subsystems.audio.playTrackOthersQuiet(521);
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.MUSIC_MODE) {
        //introduction
        subsystems.audio.playTrackOthersQuiet(520);
    }

    DURINGModeLastGo = go;
    DURINGmodeLastGenS = genS;
    runAltIR();
    runGenGoStopButton();
}

void DriveMode::runLights()
{
    if (genS.lightsMode == 0) {
        subsystems.lights.eyeLight.setBlinkOff();
        subsystems.lights.eyeLight.setMode(EyeLight::OFF);
    }
    if (genS.lightsMode == 1) {
        subsystems.lights.eyeLight.setMode(EyeLight::NORMAL);
        subsystems.lights.eyeLight.setBlinkOff();
        subsystems.lights.eyeLight.setStandard(CRGB(50, 100, 255));
    }
    if (genS.lightsMode == 2) {
        if (false /*rainbow*/) {
            subsystems.lights.eyeLight.setMode(EyeLight::RAINBOW);
            subsystems.lights.eyeLight.setBlinkOff();
        } else {
            subsystems.lights.eyeLight.setMode(EyeLight::NORMAL);
            subsystems.lights.eyeLight.setBlink(CRGB(0, 0, 0), 2000);
            subsystems.lights.eyeLight.setStandard(CRGB(50, 100, 255));
        }
    }
    
    robot.rLights.genLights();
}
void DriveMode::runSound()
{
    if (genS.musicMode == 0) { //off
    }

    if (genS.musicMode == 1) { //short
        if ((/*encourage*/ subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.LIGHTS_MODE) || (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.AUX)) {
            subsystems.audio.playNextShort();
        }
    }

    if (genS.musicMode == 2) {
        robot.entertainment.playConstantMusicLongIR();
    }
}