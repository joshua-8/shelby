#ifndef SCREEN_tEDIT_H
#define SCREEN_tEDIT_H

#include "MouseData.h"
#include "NumPad.h"
#include "menuScreenConstants.h"
#include "sButton.h"
#include "settings/topSettingsSD.h"
#include "topSetList.h"
#include <Arduino.h>

class Screen_Tedit {
public:
    void begin();
    void run();

private:
    Adafruit_ILI9341* tft;
    short* screenMode;
    NumPad* numPad;
    sButton* cancelButton;
    sButton* saveButton;
    topSetList* setlist;

    void setUndrawn();

public:
    Screen_Tedit(MouseData* _mouseData, Adafruit_ILI9341* _tft, NumPad* _numpad, short* _screenMode);
};
#endif
