#ifndef SCREEN_PREDIT_H
#define SCREEN_PREDIT_H

#include <Arduino.h>
#include "sButton.h"
#include "MouseData.h"
#include "menuScreenConstants.h"
#include "NumPad.h"
#include "settings/generalSetStruct.h"

class Screen_Predit
{
public:
  void begin();
  void setPreset(byte _presetID);
  void run(MouseData);

private:
  Adafruit_ILI9341 *tft;
  short *screenMode;
  byte presetID;
  NumPad *numPad;
  generalSetStruct *genSettings;

  void setUndrawn();

public:
  Screen_Predit(generalSetStruct *_genSettings, short *_screenMode, Adafruit_ILI9341 *_tft, NumPad *_numpad);
};
#endif
