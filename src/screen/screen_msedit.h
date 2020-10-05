#ifndef SCREEN_MSEDIT_H
#define SCREEN_MSEDIT_H

#include "MouseData.h"
#include "NumPad.h"
#include "menuScreenConstants.h"
#include "mseditSetList.h"
#include "sButton.h"
#include "settings/generalSetStruct.h"
#include "settings/modeSettingsSD.h"
#include <Arduino.h>

class Screen_MSedit {
public:
    void begin();
    void run();

private:
    Adafruit_ILI9341* tft;
    short* screenMode;
    NumPad* numPad;
    sButton* cancelButton;
    sButton* saveButton;
    mseditSetList* setlist;

    void setUndrawn();

public:
    Screen_MSedit(MouseData* _mouseData, Adafruit_ILI9341* _tft, NumPad* _numPad, short* _screenMode);
};
#endif
