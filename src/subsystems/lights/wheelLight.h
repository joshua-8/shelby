#ifndef WHEEL_LIGHT_H
#define WHEEL_LIGHT_H
#include "constants/pinout.h"
#include "constants/wheelLightConstants.h"
#include <Arduino.h>
#include <FastLED.h>
class WheelLight {
public:
    CRGB leds[255];
    CLEDController* controller;
    WheelLight();
    void begin(boolean _left);
    void run();
    void show();
    void lightRingSet(int n, CRGB color);
    void lightSector(long val, long valCycle, int firstLight, int numLights, byte hue, byte sat, byte maxBright, int sector);
    void ripple(long val, byte hue, byte sat, byte maxBright, int width);
    void dropRipple(long t, long timeRange, long drop, byte hue, byte sat, byte maxBright, byte numRipples, int space);
    void allOff(boolean s);

private:
    int mmod(long x, int m);
    boolean left;
};

#endif