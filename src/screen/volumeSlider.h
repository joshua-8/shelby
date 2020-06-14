#ifndef VOLUME_SLIDER_H
#define VOLUME_SLIDER_H
#include <Arduino.h>
#include "menuScreenConstants.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "MouseData.h"

class volumeSlider
{
public:
  volumeSlider(Adafruit_ILI9341 *_tft, int _xPos, int _yPos, int _width, int _height, uint16_t _standardColor, uint16_t _activeColor, int _rangeMax, int _boxWidth, int _val);
  boolean getVal();
  void setVal(int _val);
  void run(MouseData mouseData);
  void setUndrawn();
  void draw();

private:
  Adafruit_ILI9341 *tft;
  int xPos;
  int yPos;
  int width;
  int height;
  uint16_t standardColor;
  uint16_t activeColor;
  int rangeMax;
  int boxWidth;
  boolean undrawn = true;
  int val;
  int lastVal;
  boolean state;
};
#endif
