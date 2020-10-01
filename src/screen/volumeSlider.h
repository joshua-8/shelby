#ifndef VOLUME_SLIDER_H
#define VOLUME_SLIDER_H
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "MouseData.h"
#include "menuScreenConstants.h"
#include <Arduino.h>

class volumeSlider {
public:
    volumeSlider(Adafruit_ILI9341* _tft, MouseData* _mouseData, int _xPos, int _yPos, int _width, int _height, uint16_t _standardColor, uint16_t _activeColor, int _rangeMax, int _boxWidth, int _val);
    int getVal();
    void setVal(int _val);
    void run();
    void setUndrawn();
    void draw();
    boolean newValue();

private:
    Adafruit_ILI9341* tft;
    MouseData* mouseData;
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
    boolean newVal;
};
#endif
