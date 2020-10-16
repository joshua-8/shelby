#ifndef AUDIOCONSTANTS_H
#define AUDIOCONSTANTS_H
#include <Arduino.h>
class audioConsts {
public:
    const int AUDIO_BOARD_VOLUME_RANGE = 50; //-70 to +4 dB (but I cut the quietist values off)
    const int AUDIO_BOARD_VOLUME_MIN = -46;
    const byte MUSIC_NORMAL_GAIN=0;
    const unsigned int WTRIG_LAG=100;//milliseconds between starting a song and the board reporting it is playing the track

    const static byte musicListNum = 2;
    const char musicListName[musicListNum][6] = { "young", "chase" };

    const int musicLongPlaylistLength[musicListNum] = { 6, 11 };
    const int musicLongPlaylistListYoung[6] = { 1002, 1005, 1056, 1008, 1004, 1007 };
    const int musicLongPlaylistListChase[11] = { 1031, 1069, 1051, 1004, 1018, 1030, 1039, 1062, 1066, 1063, 1071 };

    const int* musicLongPlaylist[musicListNum] = { musicLongPlaylistListYoung, musicLongPlaylistListChase };

    const int musicShortPlaylistLength[musicListNum] = { 6, 10 };
    const int musicShortPlaylistListYoung[6] = { 1502, 1505, 1556, 1508, 1504, 1507 };
    const int musicShortPlaylistListChase[10] = {  1531, 1569, 1551, 1504, 1518, 1530, 1562, 1566, 1563, 1571 };

    const int* musicShortPlaylist[musicListNum] = { musicShortPlaylistListYoung, musicShortPlaylistListChase };
};
static audioConsts audioConstants;
#endif