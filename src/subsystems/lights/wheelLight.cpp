#include "wheelLight.h"
#include "shelbytron_globs.h"
WheelLight::WheelLight()
{
}
void WheelLight::begin(boolean _left)
{
    left = _left;
    if (left) {
        controller = &FastLED.addLeds<APA102, LEFT_WHEEL_LIGHTS_DATA_PIN, LEFT_WHEEL_LIGHTS_CLOCK_PIN, BGR, DATA_RATE_MHZ(1)>(leds, 255);
    } else {
        controller = &FastLED.addLeds<APA102, RIGHT_WHEEL_LIGHTS_DATA_PIN, RIGHT_WHEEL_LIGHTS_CLOCK_PIN, BGR, DATA_RATE_MHZ(1)>(leds, 255);
    }
    show();
}
void WheelLight::run()
{
}

void WheelLight::show()
{
    controller->showLeds(255);
}

/**
 * @brief set a whole ring to a color
 * @param  n: which ring, from center, zero indexed
 * @param  color: color to set ring (CRGB, CHSV)
 */
void WheelLight::lightRingSet(int n, CRGB color)
{
    if (n >= 0 && n < wheelLightConstants.NUM_RINGS) {
        for (int i = wheelLightConstants.RING_FIRST_INDEX[n]; i <= wheelLightConstants.RING_LAST_INDEX[n]; i++) {
            leds[i] = color;
        }
    }
}

/**
 * @brief  light a portion of a ring, fading towards the edges
 * @param  val: make the sector move around the wheel
 * @param  valCycle: full circle rotation units
 * @param  firstLight: index of light circle starts at
 * @param  numLights: number of lights in circle
 * @param  hue: 
 * @param  sat: 
 * @param  maxBright: brightest part of lit sector, center
 * @param  sector: portion of valCycle that gets lit
 * @retval None
 */
void WheelLight::lightSector(long val, long valCycle, int firstLight, int numLights, byte hue, byte sat, byte maxBright, int sector)
{
    if (!left) {
        val = -val;
    }
    //the CRGB array to write into, wheel rotation, full circle rotation units, index of light circle starts at, number of lights in circle, hue, sat, max brightness, portion of valCycle that gets lit
    for (int i = firstLight; i < firstLight + numLights; i++) {
        int dist = abs(mmod(val - (long)(i - firstLight) * valCycle / numLights, valCycle) - valCycle / 2);
        if (dist <= sector / 2) {
            leds[i] = CHSV(hue, sat, map(dist, 0, sector / 2, maxBright, 0));
        }
    }
}
/**
 * @brief  makes a single ring grow or shrink
 * @param  val: 0-255
 * @param  hue: 
 * @param  sat: 
 * @param  maxBright: 
 * @param  width: width of ring, in units of val
 */
void WheelLight::ripple(long val, byte hue, byte sat, byte maxBright, int width)
{
    val = val * (255 * (wheelLightConstants.NUM_RINGS) + width / 2) / 255 - width / 2;
    for (int i = 0; i < 10; i++) {
        if (abs(val - i * 255) <= width / 2) {
            lightRingSet(i, CHSV(hue, sat, map(abs(val - i * 255), 0, width / 2, maxBright, 0)));
        }
    }
}
/**
 * @brief  pond ripple effect
 * @param  t: time, controls animation
 * @param  timeRange: t should be increased from 0 to timeRange
 * @param  drop: how much of timeRange for initial drop
 * @param  hue: 
 * @param  sat: 
 * @param  maxBright: 
 * @param  numRipples: 
 * @param  space: space between rings, around 255*numRipples/numRings is good
 */
void WheelLight::dropRipple(long t, long timeRange, long drop, byte hue, byte sat, byte maxBright, byte numRipples, int space)
{
    if (t >= 0 && t <= timeRange) {
        if (t < drop) {
            ripple(120 - t * 150 / drop, hue, sat, map(t, 0, drop, 0, maxBright), 255 * 3);
        } else {
            for (byte i = 0; i < numRipples; i++) {
                ripple((t - drop) * (255 + space * (numRipples - 1)) / (timeRange - drop) - space * i, hue, sat, map(t, drop, timeRange, maxBright, 0), 255 * 3);
            }
        }
    }
}
/**
 * @brief  sets all lights to off
 * @param  s: update/show leds?
 */
void WheelLight::allOff(boolean s)
{
    for (int i = 0; i < wheelLightConstants.NUM_LEDS; i++) { //reset all lights to black, the sector functions don't do that so patterns can be displayed under them.
        leds[i] = CRGB::Black;
    }
    if (s) {
        show();
    }
}
int WheelLight::mmod(long x, int m)
{
    //always positive version of modulo
    return ((x % m) + m) % m;
}