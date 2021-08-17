#include "stillMode.h"
StillMode::StillMode()
{
}
void StillMode::begin()
{
}
void StillMode::run()
{
    subsystems.head.setServosEnabled(go);
    if (go) {

    }

    runSound();
    runLights();

    DURINGModeLastGo = go;
    DURINGmodeLastGenS = genS;
    runAltIR();
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
void StillMode::runSound()
{
    if (genS.musicMode == 0) { //off
    }

    if (genS.musicMode == 1) { //short
        if (false /*encourage*/ || (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.AUX)) {
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