#include "tagMode.h"
TagMode::TagMode()
{
}
void TagMode::begin()
{
    sweepDir = true;
    encourage = false;
    subsystems.audio.stopLong();
    subsystems.audio.stopShort();
    state = States::DRIVING_HALL;
    lastState = States::DRIVING_CORNER;
    resetAtStartOfHall();
}
void TagMode::run()
{
    if (state != lastState) { //start mode
        switch (state) {
        case DRIVING_HALL:
            drivingStartDistance = subsystems.drivetrain.getDist().y;
            break;
        case DRIVING_CORNER:
            break;
        case STARTING_TURN:
            encourage = true;
            subsystems.drivetrain.movePos({ subsystems.drivetrain.getDist().y, robot.moveHall.getHallHeading() - 90, 0 });
            // robot.moveDrive.setDriveTarget(subsystems.drivetrain.getDist().y, robot.moveHall.getHallHeading() - 85, tagModeModeSettings.turnTime, tagModeModeSettings.safe, false);
            break;
        case WAITING:
            subsystems.drivetrain.moveVel({ 0, 0, 0 });
            break;
        case ENDING_TURN:
            subsystems.drivetrain.movePos({ subsystems.drivetrain.getDist().y, robot.moveHall.getHallHeading(), 0 });
            // robot.moveDrive.setDriveTarget(subsystems.drivetrain.getDist().y, robot.moveHall.getHallHeading(), tagModeModeSettings.turnTime, tagModeModeSettings.safe, false);
            break;
        case STOPPING_DRIVING:
            subsystems.drivetrain.moveVel({ 0, 0, 0 });
            break;
        case STOPPING_ENDING_TURN:
            subsystems.drivetrain.moveVel({ 0, 0, 0 });
            break;
        }
    }

    lastState = state;

    switch (state) { //run mode
    case DRIVING_HALL:
        robot.moveHall.run(tagModePresetSettings[genS.preset].speed, tagModeModeSettings.safe);
        if (abs(subsystems.drivetrain.getDist().y - drivingStartDistance) > tagModePresetSettings[genS.preset].drvDist) {
            state = STOPPING_DRIVING;
        }
        //state=DRIVING_CORNER
        break;
    case DRIVING_CORNER:
        /*resetAtStartOfHall();
          state=DRIVING_HALL;*/
        break;
    case STARTING_TURN:
        if (subsystems.drivetrain.getDist().rz < robot.moveHall.getHallHeading() - 45 && subsystems.drivetrain.getVel().rz == 0) {
            state = WAITING;
        }
        break;
    case WAITING:
        if (subsystems.distanceSensors.LTurret.getAngle() > -90 + 15)
            sweepDir = false;
        if (subsystems.distanceSensors.LTurret.getAngle() < -90 - 15)
            sweepDir = true;
        subsystems.distanceSensors.LTurret.setAngle(subsystems.distanceSensors.LTurret.getAngle() + lastLoopTimeMicros / 1000000.0 * 45 * (sweepDir ? 1 : -1));
        if (subsystems.distanceSensors.LTurret.getDist() != 0 && subsystems.distanceSensors.LTurret.getDist() < tagModePresetSettings[genS.preset].tagDist) {
            state = ENDING_TURN;
        }
        break;
    case ENDING_TURN:
        if (subsystems.drivetrain.getDist().rz > robot.moveHall.getHallHeading() - 45 && subsystems.drivetrain.getVel().rz == 0) {
            state = STOPPING_ENDING_TURN;
        }
        break;
    case STOPPING_DRIVING:
        if (subsystems.drivetrain.getMotorVel(0) == 0 && subsystems.drivetrain.getMotorVel(1) == 0) {
            state = STARTING_TURN;
        }
        break;
    case STOPPING_ENDING_TURN:
        if (subsystems.drivetrain.getMotorVel(0) == 0 && subsystems.drivetrain.getMotorVel(1) == 0) {
            state = DRIVING_HALL;
        }
        break;
    }

    if (genS.musicMode == 0) { //off
        if (encourage || (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.OK)) {
            subsystems.audio.playTrack(30); //say hi to Luca
            encourage = false;
        }
    }

    if (genS.musicMode == 1) { //short
        if (encourage || (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.OK)) {
            subsystems.audio.playNextShort();
            encourage = false;
        }
    }

    if (genS.musicMode == 2) {
        robot.entertainment.playConstantMusicLongIR();
        if (encourage) {
            encourage = false;
        }
    }

    DURINGModeLastGo = go;
    DURINGmodeLastGenS = genS;
    runGenIR();
    runGenGoStopButton();
}

void TagMode::runLights()
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
void TagMode::runSound()
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