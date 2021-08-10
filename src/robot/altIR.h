#ifndef ALTIR_H
#define ALTIR_H
//NOT FOR DEMO MODE
#include "constants/audioConstants.h"
#include "constants/constants.h"
#include "screen/screen.h"
#include "shelbytron_globs.h"
/*


    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.WORD_MODE) {
        //celebrate
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.LIGHTS_MODE) {
        //encourage
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.MUSIC_LIST) {
        //goodbye
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.MUSIC_MODE) {
        //introduction
    }
    


*/
static void runAltIR()
{
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
        genS.preset++;
        if (genS.preset >= presetNum) {
            genS.preset = 0;
        }
        saveGenSettingsSD();
        if (!go)
            messageScreen.dispMessage("preset", genS.preset + 1, 1000);
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
}

#endif