#ifndef SCREEN_H
#define SCREEN_H

#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "MouseData.h"
#include "SPI.h"
#include "constants/constants.h"
#include "constants/pinout.h"
#include "menuScreen.h"
#include "msgScreen.h"
#include "screenConstants.h"
#include "settings/settings.h"
#include <Arduino.h>

class Screen {
private:
    Adafruit_ILI9341* tft;
    MenuScreen* menuScreen;
    MsgScreen* msgScreen;

public:
    Screen(MsgScreen* _msgScreen);

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
