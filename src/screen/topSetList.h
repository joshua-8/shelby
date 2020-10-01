#ifndef tSET_LIST_H
#define tSET_LIST_H
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "MouseData.h"
#include "NumPad.h"
#include "settings/topSettingsListify.h"
#include <Arduino.h>
class topSetList {
private:
    Adafruit_ILI9341* tft;
    MouseData* mouseData;
    NumPad* numPad;
    int xPos;
    int yPos;
    int width;
    int height;
    float scroll;
    float length;
    boolean drawn;
    int currVal;
    boolean mouseStartupUnlocked;
    String valToString(float val, boolean integer);

public:
    topSetList(Adafruit_ILI9341* _tft, MouseData* _mouseData, NumPad* _numPad, int _xPos, int _yPos, int _width, int _height);
    void setUndrawn();
    void run();
    void begin();
};
#endif