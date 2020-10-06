#ifndef GO_BUTTON_H
#define GO_BUTTON_H
#include "FastLED.h"
#include "constants/goButtonConstants.h"
#include "constants/pinout.h"
#include <Arduino.h>
class GoButton {
public:
    GoButton();
    void begin();
    void run();
    void setColor(CRGB C);
    void setRGB(byte r, byte g, byte b);
    void setHSV(byte h, byte s, byte v);
    void blink(CRGB ca, unsigned int ta, CRGB cb, unsigned int tb);
    void fade(CRGB ca, unsigned int ta, CRGB cb, unsigned int tb);

    CRGB getColor();
    boolean isPressed();
    boolean justPushed();
    boolean justReleased();
    unsigned long getTimeSincePressed();
    unsigned long getTimeSinceReleased();
    void resetAnimationTimer();

private:
    unsigned long animTime();
    enum class Modes { NOT_ANIMATED,
        BLINKING,
        FADING };
    Modes mode = Modes::NOT_ANIMATED;
    CRGB color;
    boolean state;
    boolean lastState;
    unsigned long rawStateSwitchMillis;
    boolean rawLastState;
    boolean rawToState(boolean rs);
    unsigned long pushedMillis;
    unsigned long releasedMillis;
    unsigned long animationMillis;

    CRGB colorInputA;
    CRGB colorInputB;
    unsigned long timeInputA;
    unsigned long timeInputB;
};
#endif