#include "chaseMode.h"
#include "shelbytron_globs.h"
ChaseMode::ChaseMode()
{
}
void ChaseMode::begin()
{
}
void ChaseMode::run()
{
    if (subsystems.ir.newMsg && !subsystems.ir.repeat) {
        if (subsystems.ir.message == irConstants.UP) {
            robot.moveDrive.setDriveTarget(2, 90, 5000, true);
        }
        if (subsystems.ir.message == irConstants.DOWN) {
            robot.moveDrive.setDriveTarget(-2, -90, 5000, true);
        }
    }
    if (!go) {
        robot.moveDrive.stopNavigating();
    }
    robot.moveDrive.run();

    DURINGmodeLastGenS = genS;
    runGenIR();
    runGenGoStopButton();
}
