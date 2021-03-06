#ifndef prSET_LIST_H
#define prSET_LIST_H
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "MouseData.h"
#include "NumPad.h"
#include "settings/presetSettingsListify.h"
#include <Arduino.h>
class presetSetList {
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
    int preset;
    boolean mouseStartupUnlocked;
    String valToString(float val, boolean integer);

public:
    presetSetList(Adafruit_ILI9341* _tft, NumPad* _numPad, MouseData* _mouseData, int _xPos, int _yPos, int _width, int _height);
    void setUndrawn();
    void run();
    void begin();
    void setPresetAndMode(int preset, int mode);
};
#endif