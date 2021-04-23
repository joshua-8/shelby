#include "chaseMode.h"
#include "shelbytron_globs.h"
ChaseMode::ChaseMode()
{
}
void ChaseMode::begin()
{
    forwards = true;
    robot.moveHall.begin();
}
void ChaseMode::run()
{

    if (genS.musicMode == 2) {
        robot.entertainment.playConstantMusicLongIR();
    }

    if (go && !DURINGModeLastGo) {
        robot.moveHeading.resetZero();
        robot.moveHall.begin();
    }
    if (subsystems.ir.newMsg && subsystems.ir.message == irConstants.OK && !subsystems.ir.repeat) {
        forwards = !forwards;
    }
    if (go) {
        if (forwards) {
            robot.moveHall.run(chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
        } else {
            robot.moveHall.run(-chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
        }
    }

    DURINGModeLastGo = go;
    DURINGmodeLastGenS = genS;
    runGenIR();
    runGenGoStopButton();
}
