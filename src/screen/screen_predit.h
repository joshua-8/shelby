#ifndef SCREEN_PREDIT_H
#define SCREEN_PREDIT_H

#include <Arduino.h>
#include "sButton.h"
#include "MouseData.h"
#include "menuScreenConstants.h"

class Screen_Predit {
  public:
    void begin();
    void setPreset(byte _presetID);
    void run(MouseData);
  private:
    Adafruit_ILI9341 *tft;
    MouseData mouseData;
    short *screenMode;
    byte presetID;

    void setUndrawn();

  public:
    Screen_Predit(short* _screenMode, Adafruit_ILI9341* _tft);
};
#endif
