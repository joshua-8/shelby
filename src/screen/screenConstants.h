#ifndef SCREEN_CONSTANTS_H
#define SCREEN_CONSTANTS_H
#include <Arduino.h>

class screenConsts {
public:

    const short SCREEN_WIDTH = 320;
    const short SCREEN_HEIGHT = 240;

    const int SCREEN_PRESSED_THRESHOLD = 500;
    const int SCREEN_MAX_X = 650;
    const int SCREEN_MIN_X = 7300;
    const int SCREEN_MAX_Y = 7600;
    const int SCREEN_MIN_Y = 900;
    const int SCREEN_DEBOUNCE_TIME = 35;

    const byte mouseAvgArrNum = 6;
};

static screenConsts screenConstants;

#endif
