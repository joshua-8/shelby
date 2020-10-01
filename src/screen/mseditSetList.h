#ifndef msSET_LIST_H
#define msSET_LIST_H
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "MouseData.h"
#include "NumPad.h"
#include "settings/modeSettingsListify.h"
#include <Arduino.h>
class mseditSetList {
private:
    Adafruit_ILI9341* tft;
    NumPad* numPad;
    MouseData* mouseData;
    int xPos;
    int yPos;
    int width;
    int height;
    float scroll;
    float length;
    boolean drawn;
    int currVal;
    int mode;
    boolean mouseStartupUnlocked;
    String valToString(float val, boolean integer);

public:
    mseditSetList(Adafruit_ILI9341* _tft, MouseData* _mouseData, NumPad* _numPad, int _xPos, int _yPos, int _width, int _height);
    void setUndrawn();
    void run();
    void begin();
    void setMode(int mode);
};
#endif