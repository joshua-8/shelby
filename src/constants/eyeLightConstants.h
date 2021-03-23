#ifndef EYE_LIGHT_CONSTANTS_H
#define EYE_LIGHT_CONSTANTS_H
#include <Arduino.h>
class eyeLightConsts {
public:
    static const int NUM_LEDS = 16;
    static const unsigned short BLINK_TIME_MILLIS = 250;
};
static const eyeLightConsts eyeLightConstants;
#endif