#ifndef SCREEN_H
#define SCREEN_H

#include "MouseData.h"
#include "constants/constants.h"
#include "constants/pinout.h"
#include "screenConstants.h"
#include "settings/settings.h"
#include <Arduino.h>
//#include "SPI.h"
//#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "MenuScreen.h"

class Screen {
private:
    Adafruit_ILI9341* tft;
    MenuScreen* menuScreen;

public:
    Screen();
    void begin();
    void run();

private:
    boolean readMousePressed();
    float readMouseX();
    float readMouseY();
    MouseData readScreen();

private:
    MouseData mouseData;
};

#endif
