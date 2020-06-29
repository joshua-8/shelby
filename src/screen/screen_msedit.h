#ifndef SCREEN_MSEDIT_H
#define SCREEN_MSEDIT_H

#include <Arduino.h>
#include "sButton.h"
#include "MouseData.h"
#include "menuScreenConstants.h"
#include "NumPad.h"
#include "settings/generalSetStruct.h"
#include "mseditSetList.h"
#include "settings/modeSettingsSD.h"

class Screen_MSedit
{
public:
  void begin();
  void run(MouseData);

private:
  Adafruit_ILI9341 *tft;
  short *screenMode;
  NumPad *numPad;
  generalSetStruct *genSettings;
  sButton *cancelButton;
  sButton *saveButton;
  mseditSetList *setlist;

  void setUndrawn();

public:
  Screen_MSedit(generalSetStruct *_genSettings, short *_screenMode, Adafruit_ILI9341 *_tft, NumPad *_numpad);
};
#endif
