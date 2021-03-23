#include "eyeLight.h"
#include "shelbytron_globs.h"
EyeLight::EyeLight()
{
    blinkColor = CRGB::Black;
    standardColor = CRGB::Gray;
    blinkInterval = 0;
    lastBlinkedMillis = 0;
    specialPatternMillis = 0;
    mode = OFF;
    blinking = false;
}
void EyeLight::begin()
{
    controller = &FastLED.addLeds<APA102, EYE_LIGHTS_DATA_PIN, EYE_LIGHTS_CLOCK_PIN, BGR, DATA_RATE_MHZ(1)>(leds, 16);
    show();
}
void EyeLight::run()
{
    if (blinkInterval > 0) {
        if (millis() - lastBlinkedMillis > blinkInterval + eyeLightConstants.BLINK_TIME_MILLIS) {
            lastBlinkedMillis = millis();
            blinking = false;
            switch (mode) {
            case OFF:
                allOff(true);
                break;
            case NORMAL:
                allColor(standardColor, true);
                break;
            case RAINBOW:
                break;
            }
        }

        if (millis() - lastBlinkedMillis > blinkInterval && !blinking) {
            blinking = true;
            allColor(blinkColor, true);
        }
    } else {
        blinking = false;
    }

    if (blinking) {
    } else {
        switch (mode) {
        case OFF:
            break;
        case NORMAL:
            break;
        case RAINBOW:
            allColor(CHSV((millis() / 10) % 256, 255, 255), true);
            break;
        }
    }
}

void EyeLight::show()
{
    controller->showLeds(255);
}

/**
 * @brief  sets all lights to off
 * @param  s: update/show leds?
 */
void EyeLight::allOff(boolean s)
{
    for (int i = 0; i < eyeLightConstants.NUM_LEDS; i++) { //reset all lights to black
        leds[i] = CRGB::Black;
    }
    if (s) {
        show();
    }
}

/**
 * @brief  sets all lights to color
 * @param  s: update/show leds?
 */
void EyeLight::allColor(CRGB c, boolean s)
{
    for (int i = 0; i < eyeLightConstants.NUM_LEDS; i++) {
        leds[i] = c;
    }
    if (s) {
        show();
    }
}
void EyeLight::setBlink(CRGB _blinkColor, unsigned long _blinkInterval)
{
    blinkInterval = _blinkInterval;
    blinkColor = _blinkColor;
}
void EyeLight::setBlinkOff()
{
    blinkInterval = 0;
}

void EyeLight::setStandard(CRGB _standardColor)
{
    standardColor = _standardColor;
}
void EyeLight::setMode(eyeMode _mode)
{
    mode = _mode;
}