#ifndef SBUTTON_H
#define SBUTTON_H
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "MouseData.h"
#include "menuScreenConstants.h"
#include <Arduino.h>

class sButton {
public:
    sButton(Adafruit_ILI9341* _tft, MouseData* _mouseData, int _xPos, int _yPos, int _width, int _height, uint16_t _standardColor, uint16_t _activeColor, uint16_t _textColor, uint16_t _edgeColor, String _label, boolean _momentary);

private:
    short xPos;
    short yPos;
    unsigned short width;
    unsigned short height;
    uint16_t standardColor;
    uint16_t activeColor;
    uint16_t textColor;
    uint16_t edgeColor;
    String label;
    String secondLabel;
    boolean momentary;
    boolean state = false;
    boolean lastState = false;
    Adafruit_ILI9341* tft;
    MouseData* mouseData;
    boolean undrawn = true;

public:
    void run();
    boolean getState();
    boolean getJustPushed();
    boolean getJustReleased();
    void setState(boolean);
    boolean setText(String);
    void setUndrawn();
    boolean setSubText(String);

private:
    void draw();
};
#endif
