#ifndef LIGHTS_H
#define LIGHTS_H
#include "constants/wheelLightConstants.h"
#include "wheelLight.h"
#include "eyeLight.h"
#include <Arduino.h>
class Lights {
public:
    Lights();
    void begin();
    void run();
    WheelLight WheelLightL;
    WheelLight WheelLightR;
    EyeLight eyeLight;
};
#endif