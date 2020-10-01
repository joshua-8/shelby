#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "MouseData.h"
#include "NumPad.h"
#include "Screen_Home.h"
#include "constants/constants.h"
#include "menuScreenConstants.h"
#include "screen_msedit.h"
#include "screen_predit.h"
#include "screen_tedit.h"
#include "settings/generalSetStruct.h"
#include <Arduino.h>

class MenuScreen {
private:
    Screen_Home *homeScreen;
    Screen_Predit *preditScreen;
    Screen_MSedit *mseditScreen;
    Screen_Tedit *teditScreen;
    NumPad *numPad;

public:
    MenuScreen(MouseData* _mouseData, Adafruit_ILI9341* _tft);
    void begin();
    void run();

public:
    short screenMode = 0;
};

#endif
