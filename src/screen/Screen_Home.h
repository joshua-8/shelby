#ifndef SCREEN_HOME_H
#define SCREEN_HOME_H

#include <Arduino.h>
#include "constants/constants.h"
#include "sButton.h"
#include "menuScreenConstants.h"
#include "MouseData.h"
#include "settings/generalSetStruct.h"
#include "volumeSlider.h"
#include "constants/hardwareConstants.h"
#include "screen_predit.h"
#include "settings/settingsSD.h"

class Screen_Home
{
public:
  Screen_Home(generalSetStruct *_genSettings, short *_screenMode, Adafruit_ILI9341 *_tft, Screen_Predit *_preditScreen);

public:
  void begin();
  void run(MouseData);

private:
  generalSetStruct *genSettings;
  Adafruit_ILI9341 *tft;
  MouseData mouseData;
  short *screenMode;

  sButton *modeButton[modeNum];
  sButton *presetButton[presetNum];
  sButton *preditButton[presetNum];
  volumeSlider *volSl;

  sButton *wordModeButton;
  sButton *lightsModeButton;
  sButton *musicModeButton;
  sButton *musicPlaylistButton;

  Screen_Predit *preditScreen;

  void modeSelector();
  void presetSelector();
  void genericButtons();
  void setUndrawn();
};
#endif
