#include "goButton.h"
GoButton::GoButton()
{
    color = CRGB(0, 0, 0);
    mode = Modes::NOT_ANIMATED;
    state = false;
    lastState = false;
    pushedMillis = 0;
    releasedMillis = 0;
    animationMillis = 0;
    rawStateSwitchMillis = 0;
    rawLastState = false;

    colorInputA = CRGB(0, 0, 0);
    colorInputB = CRGB(0, 0, 0);
    timeInputB = 0;
    timeInputB = 0;
}
void GoButton::begin()
{
    pinMode(GO_STOP_BUTTON_PIN, INPUT_PULLDOWN);
    pinMode(GO_BUTTON_RED_PIN, OUTPUT);
    pinMode(GO_BUTTON_GREEN_PIN, OUTPUT);
    pinMode(GO_BUTTON_BLUE_PIN, OUTPUT);
    color = CRGB(0, 0, 0);
    mode = Modes::NOT_ANIMATED;
    state = false;
    lastState = false;
    pushedMillis = 0;
    releasedMillis = 0;
    animationMillis = 0;
    rawStateSwitchMillis = 0;
    rawLastState = 0;
}
void GoButton::run()
{
    lastState = state;
    state = rawToState(!digitalRead(GO_STOP_BUTTON_PIN));
    if (justPushed()) {
        pushedMillis = millis();
    }
    if (justReleased()) {
        releasedMillis = millis();
    }

    if (mode == Modes::BLINKING) {
        color = (animTime() % (timeInputA + timeInputB) < timeInputA) ? colorInputA : colorInputB;
    }
    if (mode == Modes::FADING) {
        unsigned long t = animTime() % (timeInputA + timeInputB);
        if (t < timeInputA) {
            color = CRGB(
                map(t, 0, timeInputA, colorInputA.red, colorInputB.red),
                map(t, 0, timeInputA, colorInputA.green, colorInputB.green),
                map(t, 0, timeInputA, colorInputA.blue, colorInputB.blue));
        } else {
            color = CRGB(
                map(t, timeInputA, timeInputA + timeInputB, colorInputB.red, colorInputA.red),
                map(t, timeInputA, timeInputA + timeInputB, colorInputB.green, colorInputA.green),
                map(t, timeInputA, timeInputA + timeInputB, colorInputB.blue, colorInputA.blue));
        }
    }

    analogWrite(GO_BUTTON_RED_PIN, 255 - color.r);
    analogWrite(GO_BUTTON_GREEN_PIN, 255 - color.g);
    analogWrite(GO_BUTTON_BLUE_PIN, 255 - color.b);
}

void GoButton::blink(CRGB ca, unsigned int ta, CRGB cb, unsigned int tb)
{
    colorInputA = ca;
    timeInputA = ta;
    colorInputB = cb;
    timeInputB = tb;
    mode = Modes::BLINKING;
}
void GoButton::fade(CRGB ca, unsigned int ta, CRGB cb, unsigned int tb)
{
    colorInputA = ca;
    timeInputA = ta;
    colorInputB = cb;
    timeInputB = tb;
    mode = Modes::FADING;
}

void GoButton::resetAnimationTimer()
{
    animationMillis = millis();
}
unsigned long GoButton::animTime()
{
    return millis() - animationMillis;
}
void GoButton::setColor(CRGB C)
{
    color = C;
    mode = Modes::NOT_ANIMATED;
}
void GoButton::setRGB(byte r, byte g, byte b)
{
    color = CRGB(r, g, b);
    mode = Modes::NOT_ANIMATED;
}
void GoButton::setHSV(byte h, byte s, byte v)
{
    color = CHSV(h, s, v);
    mode = Modes::NOT_ANIMATED;
}
CRGB GoButton::getColor()
{
    return color;
}
boolean GoButton::isPressed()
{
    return state;
}
boolean GoButton::justPushed()
{
    return state == true && lastState == false;
}
boolean GoButton::justReleased()
{
    return state == false && lastState == true;
}
unsigned long GoButton::getTimeSincePressed()
{
    return millis() - pushedMillis;
}
unsigned long GoButton::getTimeSinceReleased()
{
    return millis() - releasedMillis;
}
boolean GoButton::rawToState(boolean rs)
{
    if (rs != rawLastState) {
        rawLastState = rs;
        rawStateSwitchMillis = millis();
    }
    if (millis() - rawStateSwitchMillis > goButtonConstants.switchDebounceTime) {
        return rs;
    } else {
        return state;
    }
}