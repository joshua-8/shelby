#ifndef AUDIO_H
#define AUDIO_H
#include "constants/audioConstants.h"
#include <wavTrigger.h>
class Audio {
public:
    void begin();
    void run();
    void playLong();
    void playShort();
    void say();
    void playTrack(int t);

private:
    boolean playingMusic;
    wavTrigger wTrig;
    int lastVolume;
    int playlistPos[audioConstants.musicListNum] = { 0 };
};
#endif