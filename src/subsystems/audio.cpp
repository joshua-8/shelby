#include "audio.h"

Audio::Audio()
{
    longMusicPlaying = 0;
    longTrackStartMillis = 0;
    longTrackPlaying = false;
    wordTrackStartMillis = 0;
    shortMusicPlaying = 0;
    shortTrackStartMillis = 0;
    shortTrackPlaying = false;
    wordToPlay = -1;
    wordToPlayJoke = -1;
}

void Audio::begin()
{
    wordToPlay = -1;
    wordToPlayJoke = -1;
    lastVolume = audioConstants.AUDIO_BOARD_VOLUME_MIN - 1;
    wTrig.start();
    wTrig.setReporting(true);
    wTrig.stopAllTracks();
    wTrig.samplerateOffset(0);
    wTrig.masterGain(audioConstants.AUDIO_BOARD_VOLUME_MIN);
}
void Audio::run()
{
    if (genS.musicMode != premodeLastGenS.musicMode) {
        stopShort();
        stopLong();
    }
    if (genS.musicList != premodeLastGenS.musicList) {
        stopShort();
        stopLong();
    }

    if (wordStarted && millis() - wordTrackStartMillis > audioConstants.WTRIG_LAG && !wTrig.isTrackPlaying(wordPlaying)) {
        wordStarted = false;
        wTrig.trackFade(longMusicPlaying, topSettings.musicNormalGain, 200, false);
        wTrig.trackFade(shortMusicPlaying, topSettings.musicNormalGain, 200, false);
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
    wTrig.trackGain(longMusicPlaying, topSettings.musicNormalGain);
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
    wTrig.trackGain(longMusicPlaying, topSettings.musicNormalGain);
    longTrackStartMillis = millis();
    longTrackPlaying = true;
    wTrig.trackPlayPoly(longMusicPlaying);
    saveLongMusicSettingsSD();
}
boolean Audio::isPlayingLong()
{
    if (millis() - longTrackStartMillis > audioConstants.WTRIG_LAG) {
        longTrackPlaying = wTrig.isTrackPlaying(longMusicPlaying);
    }

    return longTrackPlaying;
}

void Audio::playWordMode(int m)
{
    if (genS.wordsMode == 0)
        return;

    if (m == -10) { //joke
        wordToPlayJoke++;
        if (wordToPlayJoke >= audioConstants.wordsPlaylistJokeLength || wordToPlayJoke < 0) {
            wordToPlayJoke = 0;
        }
        playTrackOthersQuiet(audioConstants.wordsPlaylistJoke[wordToPlayJoke]);
    }
    if (m == TAG_MODE_ID || m == DRIVE_MODE_ID || m == STILL_MODE_ID) {
        wordToPlay++;
        if (wordToPlay >= audioConstants.wordsPlaylistYayLength || wordToPlay < 0) {
            wordToPlay = 0;
        }
        playTrackOthersQuiet(audioConstants.wordsPlaylistYay[wordToPlay]);
    }
}

void Audio::playTrackOthersQuiet(int t)
{
    wordStarted = true;
    wordPlaying = t;
    wTrig.trackGain(longMusicPlaying, topSettings.musicNormalGain - topSettings.musicVolumeDecrease);
    wTrig.trackGain(shortMusicPlaying, topSettings.musicNormalGain - topSettings.musicVolumeDecrease);
    playTrackLoud((int)wordPlaying);
    wordTrackStartMillis = millis();
}

void Audio::playNextShort()
{
    stopShort();
    shortMusicPlaylistPos[genS.musicList]++;
    if (shortMusicPlaylistPos[genS.musicList] >= audioConstants.musicShortPlaylistLength[genS.musicList]) {
        shortMusicPlaylistPos[genS.musicList] = 0;
    }
    shortMusicPlaying = audioConstants.musicShortPlaylist[genS.musicList][shortMusicPlaylistPos[genS.musicList]];
    wTrig.trackGain(shortMusicPlaying, topSettings.musicNormalGain);
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
    wTrig.trackGain(shortMusicPlaying, topSettings.musicNormalGain);
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
void Audio::playTrack(int t)
{
    wTrig.trackPlayPoly(t);
    wTrig.trackGain(t, topSettings.musicNormalGain);
}
void Audio::playTrackLoud(int t)
{
    wTrig.trackPlayPoly(t);
    wTrig.trackGain(t, 0);
}
boolean Audio::isPlayingTrack(int t)
{
    return wTrig.isTrackPlaying(t);
}

void Audio::stopTrack(int t)
{
    wTrig.trackStop(t);
}
