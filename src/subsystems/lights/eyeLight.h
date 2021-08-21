#ifndef EYE_LIGHT_H
#define EYE_LIGHT_H
#include "constants/eyeLightConstants.h"
#include "constants/pinout.h"
#include <Arduino.h>
#include <FastLED.h>
class EyeLight {
public:
    CRGB leds[16];
    CLEDController* controller;
    enum eyeMode {
        OFF,
        NORMAL,
        RAINBOW
    };
    EyeLight();
    void begin();
    void run();
    void show();
    void allOff(boolean s);
    void allColor(CRGB c, boolean s);
    void setBlink(CRGB _blinkColor, unsigned long _blinkInterval);
    void setBlinkOff();
    void setStandard(CRGB _standardColor);
    void setMode(eyeMode _mode);
    boolean winking;

private:
    CRGB blinkColor;
    CRGB standardColor;
    unsigned long blinkInterval;
    unsigned long lastBlinkedMillis;
    unsigned long specialPatternMillis;
    eyeMode mode;
    boolean blinking;
};

#endif