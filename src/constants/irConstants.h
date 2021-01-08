#ifndef IR_CONSTANTS_H
#define IR_CONSTANTS_H
#include <Arduino.h>
class irConsts {
public:
    static const byte msgLength = 34;
    static const byte msgStartIgnoreLength = 18;
    const int pulseThresh = 1200;
    const int messageDoneTime = 22000;
    enum irBEnum {
        GO = 102,
        STOP = 3,
        UP = 25,
        DOWN = 51,
        LEFT = 30,
        RIGHT = 45,
        OK = 42,
        REPLAY_SONG = 120,
        SKIP_SONG = 97,
        VOL_DOWN = 52,
        VOL_UP = 85,
        AUX = 76,
        MODE = 16,
        PRESET = 8,
        MUSIC_LIST = 66,
        WORD_MODE = 75,
        LIGHTS_MODE = 82,
        MUSIC_MODE = 127
    };
};
static const irConsts irConstants;
#endif