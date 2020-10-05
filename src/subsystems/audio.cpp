#include "audio.h"

Audio::Audio()
{
}

void Audio::begin()
{
    lastVolume = audioConstants.AUDIO_BOARD_VOLUME_MIN - 1;
    wTrig.start();
    wTrig.stopAllTracks();
    wTrig.samplerateOffset(0);
    wTrig.setReporting(true);
}
void Audio::run()
{
    wTrig.update();
    if (lastVolume != genS.volume) {
        lastVolume = genS.volume;
        wTrig.masterGain(genS.volume + audioConstants.AUDIO_BOARD_VOLUME_MIN);
    }
}