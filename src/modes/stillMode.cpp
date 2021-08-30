#include "stillMode.h"
StillMode::StillMode()
{
}
void StillMode::begin()
{
    subsystems.head.setServosEnabled(false);
}
void StillMode::run()
{
    subsystems.head.setServosEnabled(go);
    if (go) {
        if (subsystems.tail.getWagPeriod() == 0)
            subsystems.tail.wag(2000);
    }

    runSound();
    runLights();

    if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.UP) {
        subsystems.head.setPositions(subsystems.head.getPosX(), headConstants.upDeg);
    } else if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.DOWN) {
        subsystems.head.setPositions(subsystems.head.getPosX(), headConstants.downDeg);
    } else if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.LEFT) {
        subsystems.head.setPositions(headConstants.leftDeg, subsystems.head.getPosY());
    } else if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.RIGHT) {
        subsystems.head.setPositions(headConstants.rightDeg, subsystems.head.getPosY());
    } else {
        subsystems.head.setPositions(subsystems.head.getPosX(), subsystems.head.getPosY());
    }

    DURINGModeLastGo = go;
    DURINGmodeLastGenS = genS;

    if (subsystems.ir.newMsg && subsystems.ir.message == irConstants.VOL_UP) {
        if (genS.volume < audioConstants.AUDIO_BOARD_VOLUME_RANGE) {
            genS.volume++;
            saveGenSettingsSD();
        }
    }
    if (subsystems.ir.newMsg && subsystems.ir.message == irConstants.VOL_DOWN) {
        if (genS.volume > 0) {
            genS.volume--;
            saveGenSettingsSD();
        }
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.AUX) {
        genS.musicList++;
        if (genS.musicList >= audioConstants.musicListNum) {
            genS.musicList = 0;
        }
        saveGenSettingsSD();
        if (!go)
            messageScreen.dispMessage("music", audioConstants.musicListName[genS.musicList], 1000);
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.PRESET) {
        subsystems.audio.playTrackLoud((int)24); //bdumtisslaugh
    }
    if (subsystems.audio.isPlayingTrack(24)) {
        subsystems.lights.eyeLight.winking = true;
    } else {
        subsystems.lights.eyeLight.winking = false;
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.MODE) {
        go = false;
        genS.mode++;
        if (genS.mode >= modeNum) {
            genS.mode = 0;
        }
        saveGenSettingsSD();
        messageScreen.dispMessage("mode", modeSelName[genS.mode], 1000);
    }

    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.GO) {
        go = true;
    }
    if (subsystems.ir.newMsg && subsystems.ir.message == irConstants.STOP) {
        go = false;
    }

    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.WORD_MODE) {
        //joke
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

    runGenGoStopButton();
}

void StillMode::runLights()
{
    if (genS.lightsMode == 0) {
        subsystems.lights.eyeLight.setBlinkOff();
        subsystems.lights.eyeLight.setMode(EyeLight::OFF);
    }
    if (genS.lightsMode == 1) {
        subsystems.lights.eyeLight.setMode(EyeLight::NORMAL);
        subsystems.lights.eyeLight.setBlinkOff();
        if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.OK) {
            subsystems.lights.eyeLight.setStandard(CRGB(255, 255, 255));
        } else {
            subsystems.lights.eyeLight.setStandard(CRGB(50, 100, 255));
        }
    }
    if (genS.lightsMode == 2) {
        if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.OK) {
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
void StillMode::runSound()
{
    if (genS.musicMode == 0) { //off
    }

    if (genS.musicMode == 1) { //short
        if ((subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.OK)) {
            subsystems.audio.playNextShort();
            // encourage = false;
        }
    }

    if (genS.musicMode == 2) {
        robot.entertainment.playConstantMusicLongIR();
        if (false /*encourage*/) {
            //          encourage = false;
        }
    }
}