#ifndef MSG_SCREEN_H
#define MSG_SCREEN_H
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <Arduino.h>
class MsgScreen {
private:
    Adafruit_ILI9341* tft;
    String message;
    boolean closeTimer;
    unsigned long closeTime;
    boolean show;
    boolean lastShow;

public:
    boolean wasShowing();
    boolean display();
    void setTFT(Adafruit_ILI9341* _tft);
    void dispMessage(String label, String message, int time);
    MsgScreen();
};

#endif