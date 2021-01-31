#ifndef WHEEL_LIGHT_CONSTANTS_H
#define WHEEL_LIGHT_CONSTANTS_H
#include <Arduino.h>
class wheelLightConsts {
public:
    const byte RING_FIRST_INDEX[10] = { 254, 248, 236, 216, 192, 164, 132, 92, 48, 0 };
    const byte RING_LAST_INDEX[10] = { 254, 253, 247, 235, 215, 191, 163, 131, 91, 47 };
    const byte RING_NUM_LEDS[10] = { 1, 6, 12, 20, 24, 28, 32, 40, 44, 48 };
    static const int NUM_LEDS = 255;
    const byte NUM_RINGS = 10;
};
static const wheelLightConsts wheelLightConstants;
#endif