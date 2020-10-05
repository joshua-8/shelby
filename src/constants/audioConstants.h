#ifndef AUDIOCONSTANTS_H
#define AUDIOCONSTANTS_H
#include <Arduino.h>
class audioConsts {
public:
    const int AUDIO_BOARD_VOLUME_RANGE = 50; //-70 to +4 dB
    const int AUDIO_BOARD_VOLUME_MIN = -46;
    const static byte musicListNum = 2;
    const char musicListName[musicListNum][6] = { "listA", "listB" };

    const int musicLongPlaylistListA[2] = { 1002, 1008 };
    const int musicLongPlaylistListB[3] = { 1014, 1038, 1032 };
    const int musicLongPlaylistLength[musicListNum] = { 2, 3 };
    const int* musicLongPlaylist[musicListNum] = { musicLongPlaylistListA, musicLongPlaylistListB };

    const int musicShortPlaylistListA[2] = { 2002, 2008 };
    const int musicShortPlaylistListB[3] = { 2014, 2038, 2032 };
    const int musicShortPlaylistLength[musicListNum] = { 2, 3 };
    const int* musicShortPlaylist[musicListNum] = { musicShortPlaylistListA, musicShortPlaylistListB };
};
static audioConsts audioConstants;
#endif