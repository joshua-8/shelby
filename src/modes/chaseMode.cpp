#include "chaseMode.h"
#include "shelbytron_globs.h"
ChaseMode::ChaseMode()
{
}
void ChaseMode::begin()
{
    forwards = true;
    robot.moveHall.begin();

    robot.leftWallDerivSensor.begin();
    robot.rightWallDerivSensor.begin();
}
void ChaseMode::run()
{

    if (genS.musicMode == 2) {
        robot.entertainment.playConstantMusicLongIR();
    }

    if (go && !DURINGModeLastGo) {
        robot.moveHall.begin();
    }
    if (subsystems.ir.newMsg && subsystems.ir.message == irConstants.OK && !subsystems.ir.repeat) {
        forwards = !forwards;
    }

    if (go) {
        robot.leftWallDerivSensor.addData(subsystems.distanceSensors.LTurret.getDist(), subsystems.drivetrain.getDist());
        robot.rightWallDerivSensor.addData(subsystems.distanceSensors.LTurret.getDist(), subsystems.drivetrain.getDist());
        if (forwards) {
            robot.moveHeading.driveHeading(0, chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
            // robot.moveHall.run(chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
        } else {
            robot.moveHeading.driveHeading(0, -chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
            // robot.moveHall.run(-chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
        }
        if (robot.leftWallDerivSensor.isDataNew()) {
            Serial.print(robot.leftWallDerivSensor.getAngle());
            Serial.print(",");
            Serial.print(robot.rightWallDerivSensor.getAngle());
            Serial.println();
        }
    }

    DURINGModeLastGo = go;
    DURINGmodeLastGenS = genS;
    runGenIR();
    runGenGoStopButton();
}
