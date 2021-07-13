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
    state = States::DRIVING_CORNER_DRIVE;
    lastState = States::DRIVING_CORNER;
    resetAtStartOfHall();
    where = 0;
}
void TagMode::run()
{
    subsystems.head.setServosEnabled(go);
    if (go) {
        subsystems.drivetrain.setVelLimitY(tagModePresetSettings[genS.preset].speed);
        if (state != lastState) { //start mode
            switch (state) {
            case DRIVING_HALL:
                subsystems.distanceSensors.LTurret.servo->wake();
                subsystems.distanceSensors.RTurret.servo->wake();
                subsystems.distanceSensors.LTurret.servo->setVelLimit(180);
                drivingStartDistance = subsystems.drivetrain.getDist().y;
                break;
            case DRIVING_CORNER:
                subsystems.drivetrain.moveDistRZ((tagModeModeSettings.turnLeft == (where == 1)) ? -90 : 90);
                break;
            case DRIVING_CORNER_DRIVE:
                subsystems.drivetrain.resetDist();
                subsystems.drivetrain.moveDistY(2.0);
                break;
            case END_HALL_DRIVE: //clear corner
                subsystems.drivetrain.resetDist();
                subsystems.drivetrain.moveDistY(.345);
                break;
            case STARTING_TURN:
                encourage = true;
                subsystems.head.setPositionX(-90);
                subsystems.drivetrain.moveDist({ subsystems.drivetrain.getDist().y, robot.moveHall.getHallHeading() - 90, 0 });
                // robot.moveDrive.setDriveTarget(subsystems.drivetrain.getDist().y, robot.moveHall.getHallHeading() - 85, tagModeModeSettings.turnTime, tagModeModeSettings.safe, false);
                break;
            case WAITING:
                subsystems.tail.wag(2000);
                subsystems.drivetrain.moveVel({ 0, 0, 0 });
                break;
            case ENDING_TURN:
                subsystems.head.setPositionX(0);
                subsystems.drivetrain.moveDist({ subsystems.drivetrain.getDist().y, robot.moveHall.getHallHeading(), 0 });
                subsystems.audio.playTrackLoud(21);
                // robot.moveDrive.setDriveTarget(subsystems.drivetrain.getDist().y, robot.moveHall.getHallHeading(), tagModeModeSettings.turnTime, tagModeModeSettings.safe, false);
                break;
            case STOPPING_DRIVING:
                subsystems.drivetrain.moveVel({ 0, 0, 0 });
                break;
            case STOPPING_ENDING_TURN:
                subsystems.drivetrain.moveVel({ 0, 0, 0 });
                break;
            case TURNING_180A:
                subsystems.drivetrain.moveDistRZInc(-90);
                break;
            case TURNING_180B:
                if (where == 0)
                    subsystems.drivetrain.moveDistYInc(.85);
                break;
            case TURNING_180C:
                subsystems.drivetrain.moveDistRZInc(-90);
                break;
            }
        }

        if (lastState != state) {
            lastState = state;
        } else {
            switch (state) { //run mode
            case DRIVING_HALL:
                if (where == 0 || where == 1 || where == 3)
                    robot.moveHall.hallErrorOffset = robot.moveHall.hallWidth / 4;

                robot.moveHall.run(tagModePresetSettings[genS.preset].speed, tagModeModeSettings.safe);
                subsystems.head.setPositionX(robot.moveHall.getHallHeading() - subsystems.drivetrain.getDist().rz);
                if (where == 3 && subsystems.drivetrain.getDist().y == 7 && nudge3a) {
                    nudge3a = false;
                    robot.moveHall.hallHeadingProcessed += 25;
                }
                if (abs(subsystems.drivetrain.getDist().y - drivingStartDistance) > tagModePresetSettings[genS.preset].drvDist && abs(topSettings.hallLength - subsystems.drivetrain.getDist().y) > tagModePresetSettings[genS.preset].drvDist) {
                    state = STOPPING_DRIVING;
                }
                if (((where == 0 || where == 2) && abs(subsystems.drivetrain.getDist().y) > topSettings.hallLength) || ((where == 1 || where == 3) && abs(subsystems.drivetrain.getDist().y) > topSettings.hallLength + .5)) {

                    if ((where == 0 || where == 2) && (robot.moveHall.hallWidth > 5.0 || subsystems.distanceSensors.LTurret.getDist() == 0 || subsystems.distanceSensors.RTurret.getDist() == 0)) {
                        state = END_HALL_DRIVE;
                        where++;
                    } else if ((where == 1 || where == 3)) {
                        state = TURNING_180A;
                        if (where == 1)
                            subsystems.audio.playTrackLoud(211);
                        if (where == 3) {
                            nudge3a = true;
                            subsystems.audio.playTrackLoud(210);
                        }
                        where++;
                        if (where >= 4) {
                            where = 0;
                        }
                    }
                }
                break;
            case TURNING_180A:
                if (subsystems.drivetrain.isVelZero() && subsystems.drivetrain.RZLimiter.isPosAtTarget()) {
                    state = TURNING_180B;
                }
                break;
            case TURNING_180B:
                if (subsystems.drivetrain.isVelZero() && subsystems.drivetrain.YLimiter.isPosAtTarget()) {
                    state = TURNING_180C;
                }
                break;
            case TURNING_180C:
                if (subsystems.drivetrain.isVelZero() && subsystems.drivetrain.RZLimiter.isPosAtTarget()) {
                    state = DRIVING_HALL;
                    resetAtStartOfHall();
                }
                break;
            case DRIVING_CORNER_DRIVE:
                if (subsystems.drivetrain.YLimiter.isPosAtTarget() && subsystems.drivetrain.isVelZero()) {
                    state = DRIVING_HALL;
                }
                break;
            case END_HALL_DRIVE:
                if (subsystems.drivetrain.YLimiter.isPosAtTarget() && subsystems.drivetrain.isVelZero()) {
                    state = DRIVING_CORNER;
                }
                break;
            case DRIVING_CORNER:
                if (subsystems.drivetrain.RZLimiter.isPosAtTarget() && subsystems.drivetrain.isVelZero()) {
                    state = DRIVING_CORNER_DRIVE;
                    resetAtStartOfHall();
                }
                break;
            case STARTING_TURN:
                if (subsystems.drivetrain.getDist().rz < robot.moveHall.getHallHeading() - 45 && subsystems.drivetrain.getVel().rz == 0) {
                    state = WAITING;
                    subsystems.audio.playWordMode(TAG_MODE_ID);
                }
                break;
            case WAITING:
                if (subsystems.distanceSensors.LTurret.servo->isPosAtTarget()) {
                    sweepDir = !sweepDir;
                }
                subsystems.distanceSensors.LTurret.servo->setVelLimit(80);
                subsystems.distanceSensors.LTurret.setAngle(-90 + (sweepDir ? 15 : -15));
                if ((subsystems.distanceSensors.LTurret.getDist() != 0 && subsystems.distanceSensors.LTurret.getDist() < tagModePresetSettings[genS.preset].tagDist) || (subsystems.ir.newMsg && subsystems.ir.message == irConstants.OK)) {
                    state = ENDING_TURN; //got tagged
                }
                break;
            case ENDING_TURN:
                if (subsystems.drivetrain.getDist().rz > robot.moveHall.getHallHeading() - 45 && subsystems.drivetrain.getVel().rz == 0) {
                    state = STOPPING_ENDING_TURN;
                    subsystems.tail.stopWag();
                }
                break;
            case STOPPING_DRIVING:
                if (subsystems.drivetrain.isVelZero()) {
                    state = STARTING_TURN;
                }
                break;
            case STOPPING_ENDING_TURN:
                if (subsystems.drivetrain.isVelZero()) {
                    state = DRIVING_HALL;
                }
                break;
            }
        }
    }

    runSound();
    runLights();

    DURINGModeLastGo = go;
    DURINGmodeLastGenS = genS;
    runGenIR();
    if (genS.mode == 1) { //SKIP FROM TAG TO DEMO
        genS.mode = DEMO_MODE_ID;
        saveGenSettingsSD();
    }
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
        subsystems.lights.eyeLight.setStandard(CRGB(50, 100, 255));
    }
    if (genS.lightsMode == 2) {
        if (state == WAITING) {
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
        if (encourage || (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.AUX)) {
            subsystems.audio.playTrack(30); //say hi to Luca
            encourage = false;
        }
    }

    if (genS.musicMode == 1) { //short
        if (encourage || (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.AUX)) {
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
}