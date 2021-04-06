#include "chaseMode.h"
#include "shelbytron_globs.h"
ChaseMode::ChaseMode()
{
}
void ChaseMode::begin()
{
    robot.moveHeading.resetZero();
    mode = 0;
}
void ChaseMode::run()
{
    if ((go && !lastGo) || (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.OK)) {
        robot.moveHeading.resetZero();
    }
    robot.entertainment.playConstantMusicLongIR();

    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.UP) {
        mode = 1;
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.LEFT) {
        mode = 2;
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.RIGHT) {
        mode = 3;
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.DOWN) {
        mode = 0;
    }

    if (go) {
        if (mode == 0) {
            robot.moveHeading.driveHeading(0, -topSettings.debugC, true);
        }
        if (mode == 1) {
            robot.moveHeading.driveHeading(0, topSettings.debugC, true);
        }
        if (mode == 2) {
            robot.moveHeading.driveHeading(-90, topSettings.debugC, true);
        }
        if (mode == 3) {
            robot.moveHeading.driveHeading(90, topSettings.debugC, true);
        }
    }
    if (abs(subsystems.drivetrain.getRotation()) < 45) {
        subsystems.distanceSensors.LTurret.setAngle(-90 - subsystems.drivetrain.getRotation());
        subsystems.distanceSensors.RTurret.setAngle(90 - subsystems.drivetrain.getRotation());
    }

    DURINGmodeLastGenS = genS;
    runGenIR();
    runGenGoStopButton();
}
