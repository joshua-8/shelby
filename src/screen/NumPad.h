#ifndef NUM_PAD_H
#define NUM_PAD_H
#include <Arduino.h>
#include "sButton.h"
#include "menuScreenConstants.h"
class NumPad
{

public:
    void begin();
    boolean run(MouseData);
    void setUndrawn();
    void setInteger(boolean _integer);
    void setVal(float _val);
    String getValString();
    String getString();
    float getFinalVal();
    boolean getChanged();
    boolean getFinalized();

private:
    Adafruit_ILI9341 *tft;
    sButton *button0;
    sButton *button1;
    sButton *button2;
    sButton *button3;
    sButton *button4;
    sButton *button5;
    sButton *button6;
    sButton *button7;
    sButton *button8;
    sButton *button9;
    sButton *buttonDec;
    sButton *buttonNeg;
    sButton *buttonY;
    sButton *buttonN;
    sButton *buttonDel;
    float finalVal = 0.0;
    float val = 0.0;
    String str;
    boolean constrainInteger = false;
    boolean change;
    boolean justFinalized;
    boolean justStarted;

public:
    NumPad(Adafruit_ILI9341 *_tft);
};
#endif