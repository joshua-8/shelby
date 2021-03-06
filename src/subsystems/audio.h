#ifndef AUDIO_H
#define AUDIO_H
#include "constants/audioConstants.h"
#include "settings/musicSD.h"
#include "settings/settings.h"
#include "wavTrigger.h"
class Audio {
public:
    Audio();
    void begin();
    void run();
    void playNextLong();
    boolean isPlayingLong();
    void playLastLong();
    void playNextShort();
    void playLastShort();
    boolean isPlayingShort();
    void stopShort();
    void stopLong();

    // void playTrack(int t);

private:
    boolean playingMusic;
    wavTrigger wTrig;
    int lastVolume;
    int longMusicPlaying;
    unsigned long longTrackStartMillis = 0;
    boolean longTrackPlaying = false;
    int shortMusicPlaying;
    unsigned long shortTrackStartMillis = 0;
    boolean shortTrackPlaying = false;
};
#endif