#ifndef SCREEN_PREDIT_H
#define SCREEN_PREDIT_H

#include "MouseData.h"
#include "NumPad.h"
#include "menuScreenConstants.h"
#include "presetSetList.h"
#include "sButton.h"
#include "settings/generalSetStruct.h"
#include "settings/presetSettingsSD.h"
#include <Arduino.h>

class Screen_Predit {
public:
    void begin();
    void setPreset(byte _presetID);
    void run();

private:
    Adafruit_ILI9341* tft;
    short* screenMode;
    byte presetID;
    NumPad* numPad;
    sButton* cancelButton;
    sButton* saveButton;
    presetSetList* setlist;

    void setUndrawn();

public:
    Screen_Predit(MouseData* _mouseData, Adafruit_ILI9341* _tft, NumPad* _numpad, short* _screenMode);
};
#endif
