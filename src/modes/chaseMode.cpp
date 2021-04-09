#include "chaseMode.h"
#include "shelbytron_globs.h"
ChaseMode::ChaseMode()
{
}
void ChaseMode::begin()
{
    mode = 0;
    robot.moveHall.begin();
}
void ChaseMode::run()
{
    if (go && !lastGo) {
        robot.moveHall.begin();
    }
    if (go) {
        if (millis() - subsystems.ir.lastNewMsgMillis < 400 && subsystems.ir.message == irConstants.OK) {
            robot.moveHall.run(-chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
        } else {
            robot.moveHall.run(chaseModePresetSettings[genS.preset].speed, chaseModeModeSettings.safe);
        }
    }

    robot.entertainment.playConstantMusicLongIR();

    DURINGmodeLastGenS = genS;
    runGenIR();
    runGenGoStopButton();
}
