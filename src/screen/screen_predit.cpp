#include "screen_predit.h"

Screen_Predit::Screen_Predit(short *_screenMode, Adafruit_ILI9341 *_tft)
{
  tft = _tft;
  screenMode = _screenMode;
}

void Screen_Predit::begin()
{
  (*tft).fillScreen(ILI9341_RED);
  (*tft).print(presetID);
  setUndrawn();
}

void Screen_Predit::setPreset(byte _presetID)
{
  presetID = _presetID;
}

void Screen_Predit::run(MouseData _mouseData)
{
  mouseData = _mouseData;
  if (mouseData.mousePressed && mouseData.millisSinceMouseDown > 1200)
  {
    (*screenMode) = SCREEN_MODE_HOME;
  }
}

void Screen_Predit::setUndrawn()
{
}
