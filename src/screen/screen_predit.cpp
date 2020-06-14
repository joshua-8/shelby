#include "screen_predit.h"
Screen_Predit::Screen_Predit(generalSetStruct *_genSettings, short *_screenMode, Adafruit_ILI9341 *_tft, NumPad *_numPad)
{
  tft = _tft;
  screenMode = _screenMode;
  numPad = _numPad;
  genSettings = _genSettings;
}

void Screen_Predit::begin()
{
  (*tft).fillScreen(ILI9341_RED);
  (*tft).setCursor(160, 30);
  (*tft).println(presetID);
  (*tft).setCursor(160, 60);
  (*tft).println((*genSettings).mode);
  (*numPad).begin();
  setUndrawn();
}

void Screen_Predit::setPreset(byte _presetID)
{
  presetID = _presetID;
}

void Screen_Predit::run(MouseData mouseData)
{
  if (mouseData.mousePressed && mouseData.millisSinceMouseDown > 1200)
  {
    (*screenMode) = SCREEN_MODE_HOME;
  }
  if ((*numPad).run(mouseData))
  {
    (*tft).fillRect(155, 120, 100, 100, ILI9341_RED);

    (*tft).setCursor(160, 130);
    (*tft).println((*numPad).getFinalValString());
    (*tft).setCursor(160, 160);
    (*tft).println((*numPad).getValString());
    (*tft).setCursor(160, 190);
    (*tft).println((*numPad).getString());
  }
}

void Screen_Predit::setUndrawn()
{
  (*numPad).setUndrawn();
}
