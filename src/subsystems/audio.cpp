#include "audio.h"

Audio::Audio()
{
    longMusicPlaying = 0;
    longTrackStartMillis = 0;
    longTrackPlaying = false;
}

void Audio::begin()
{
    lastVolume = audioConstants.AUDIO_BOARD_VOLUME_MIN - 1;
    wTrig.start();
    wTrig.setReporting(true);
    wTrig.stopAllTracks();
    wTrig.samplerateOffset(0);
    wTrig.masterGain(audioConstants.AUDIO_BOARD_VOLUME_MIN);
}
void Audio::run()
{
    if (genS.musicMode != lastGenS.musicMode) {
        stopShort();
        stopLong();
    }
    
    wTrig.update();
    if (lastVolume != genS.volume) {
        lastVolume = genS.volume;
        wTrig.masterGain(genS.volume + audioConstants.AUDIO_BOARD_VOLUME_MIN);
    }
}
void Audio::playNextLong()
{
    stopLong();
    longMusicPlaylistPos[genS.musicList]++;
    if (longMusicPlaylistPos[genS.musicList] >= audioConstants.musicLongPlaylistLength[genS.musicList]) {
        longMusicPlaylistPos[genS.musicList] = 0;
    }
    longMusicPlaying = audioConstants.musicLongPlaylist[genS.musicList][longMusicPlaylistPos[genS.musicList]];
    wTrig.trackGain(longMusicPlaying, audioConstants.MUSIC_NORMAL_GAIN);
    longTrackStartMillis = millis();
    longTrackPlaying = true;
    wTrig.trackPlayPoly(longMusicPlaying);
    saveLongMusicSettingsSD();
}
void Audio::stopLong()
{
    wTrig.trackStop(longMusicPlaying);
}
void Audio::playLastLong()
{
    stopLong();
    longMusicPlaylistPos[genS.musicList]--;
    if (longMusicPlaylistPos[genS.musicList] < 0) {
        longMusicPlaylistPos[genS.musicList] = audioConstants.musicLongPlaylistLength[genS.musicList] - 1;
    }
    longMusicPlaying = audioConstants.musicLongPlaylist[genS.musicList][longMusicPlaylistPos[genS.musicList]];
    wTrig.trackGain(longMusicPlaying, audioConstants.MUSIC_NORMAL_GAIN);
    longTrackStartMillis = millis();
    longTrackPlaying = true;
    wTrig.trackPlayPoly(longMusicPlaying);
    saveShortMusicSettingsSD();
}
boolean Audio::isPlayingLong()
{
    if (millis() - longTrackStartMillis > audioConstants.WTRIG_LAG) {
        longTrackPlaying = wTrig.isTrackPlaying(longMusicPlaying);
    }

    return longTrackPlaying;
}

void Audio::playNextShort()
{
    stopShort();
    shortMusicPlaylistPos[genS.musicList]++;
    if (shortMusicPlaylistPos[genS.musicList] >= audioConstants.musicShortPlaylistLength[genS.musicList]) {
        shortMusicPlaylistPos[genS.musicList] = 0;
    }
    shortMusicPlaying = audioConstants.musicShortPlaylist[genS.musicList][shortMusicPlaylistPos[genS.musicList]];
    wTrig.trackGain(shortMusicPlaying, audioConstants.MUSIC_NORMAL_GAIN);
    shortTrackStartMillis = millis();
    shortTrackPlaying = true;
    wTrig.trackPlayPoly(shortMusicPlaying);
    saveShortMusicSettingsSD();
}
void Audio::stopShort()
{
    wTrig.trackStop(shortMusicPlaying);
}
void Audio::playLastShort()
{
    stopShort();
    shortMusicPlaylistPos[genS.musicList]--;
    if (shortMusicPlaylistPos[genS.musicList] < 0) {
        shortMusicPlaylistPos[genS.musicList] = audioConstants.musicShortPlaylistLength[genS.musicList] - 1;
    }
    shortMusicPlaying = audioConstants.musicShortPlaylist[genS.musicList][shortMusicPlaylistPos[genS.musicList]];
    wTrig.trackGain(shortMusicPlaying, audioConstants.MUSIC_NORMAL_GAIN);
    shortTrackStartMillis = millis();
    shortTrackPlaying = true;
    wTrig.trackPlayPoly(shortMusicPlaying);
    saveShortMusicSettingsSD();
}
boolean Audio::isPlayingShort()
{
    if (millis() - shortTrackStartMillis > audioConstants.WTRIG_LAG) {
        shortTrackPlaying = wTrig.isTrackPlaying(shortMusicPlaying);
    }
    return shortTrackPlaying;
}
