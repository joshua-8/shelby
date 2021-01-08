#ifndef MSG_SCREEN_H
#define MSG_SCREEN_H
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "constants/irConstants.h"
#include "subsystems/ir.h"
#include <Arduino.h>
class MsgScreen {
private:
    Adafruit_ILI9341* tft;
    String message;
    boolean closeTimer;
    unsigned long closeTime;
    boolean show;
    boolean lastShow;

    byte selCurrDig;
    boolean valSelDone;
    boolean selecting;
    int selVal;
    byte selNumDig;
    void drawSel();
    IR* subsysir;

public:
    boolean wasShowing();
    boolean display();
    void setTFT(Adafruit_ILI9341* _tft);
    void dispMessage(String label, String message, int time);
    void dispValSelector(String label, int digits, int startVal);
    boolean valSelectorDone();
    int valSelectorValue();
    MsgScreen(IR* _subsysir);
};

#endif