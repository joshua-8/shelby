#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>
#include "MouseData.h"
#include "constants/pinout.h"
#include "menuScreenConstants.h"
#include "constants/constants.h"
#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "constants/hardwareConstants.h"
#include "settings/generalSetStruct.h"
#include "Screen_Home.h"
#include "screen_predit.h"

class Screen
{
private:
  const byte mouseAvgArrNum = 6;

private:
  Adafruit_ILI9341 tft = Adafruit_ILI9341(SCREEN_CS_PIN, SCREEN_DC_PIN);
  Screen_Home *homeScreen;
  Screen_Predit *preditScreen;

public:
  Screen(generalSetStruct *_genSettings);
  void begin();
  void run();
  void off();

public:
  short screenMode = 0;

private:
  boolean readMousePressed();
  float readMouseX();
  float readMouseY();
  MouseData readScreen();

private:
  MouseData mouseData = {-1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0, false, false, false, false};
};

#endif
