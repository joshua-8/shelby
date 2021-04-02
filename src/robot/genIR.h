#ifndef GENIR_H
#define GENIR_H
#include "constants/audioConstants.h"
#include "constants/constants.h"
#include "screen/screen.h"
#include "shelbytron_globs.h"
static void runGenIR()
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
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.MUSIC_LIST) {
        genS.musicList++;
        if (genS.musicList >= audioConstants.musicListNum) {
            genS.musicList = 0;
        }
        saveGenSettingsSD();
        messageScreen.dispMessage("music", audioConstants.musicListName[genS.musicList], 1000);
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.MUSIC_MODE) {
        genS.musicMode++;
        if (genS.musicMode >= numMusicModes) {
            genS.musicMode = 0;
        }
        saveGenSettingsSD();
        messageScreen.dispMessage("music", musicModeName[genS.musicMode], 1000);
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.PRESET) {
        genS.preset++;
        if (genS.preset >= presetNum) {
            genS.preset = 0;
        }
        saveGenSettingsSD();
        messageScreen.dispMessage("preset", genS.preset + 1, 1000);
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.WORD_MODE) {
        genS.wordsMode++;
        if (genS.wordsMode >= numWordModes) {
            genS.wordsMode = 0;
        }
        saveGenSettingsSD();
        messageScreen.dispMessage("words", wordModeName[genS.wordsMode], 1000);
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.LIGHTS_MODE) {
        genS.lightsMode++;
        if (genS.lightsMode >= numLightsModes) {
            genS.lightsMode = 0;
        }
        saveGenSettingsSD();
        messageScreen.dispMessage("lights", lightsModeName[genS.lightsMode], 1000);
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