#include "chaseMode.h"
#include "shelbytron_globs.h"
ChaseMode::ChaseMode()
{
    forwards = true;
}
void ChaseMode::begin()
{
    robot.moveHall.begin();
}
void ChaseMode::run()
{

    if (genS.musicMode == 2) {
        robot.entertainment.playConstantMusicLongIR();
    }

    if (go && !DURINGModeLastGo) {
        begin();
    }
    if (subsystems.ir.newMsg && subsystems.ir.message == irConstants.OK && !subsystems.ir.repeat) {
        forwards = !forwards;
        begin();
    }

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
