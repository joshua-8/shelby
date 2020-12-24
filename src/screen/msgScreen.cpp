#include "msgScreen.h"
MsgScreen::MsgScreen()
{
    closeTimer = false;
    closeTime = 0;
    show = false;
    lastShow = false;
}
void MsgScreen::setTFT(Adafruit_ILI9341* _tft)
{
    tft = _tft;
}
boolean MsgScreen::display()
{
    lastShow = show;
    if (closeTimer && millis() > closeTime) {
        show = false;
    }
    return show;
}
void MsgScreen::dispMessage(String label, String message, int time)
{
    if (time < 0) {
        closeTimer = false;
        show = true;
    }
    if (time == 0) {
        show = false;
    }
    if (time > 0) {
        show = true;
        closeTimer = true;
        closeTime = millis() + time;
    }
    if (show) {
        (*tft).fillScreen(ILI9341_WHITE);
        (*tft).setTextColor(ILI9341_BLACK);
        (*tft).setTextSize(8);
        (*tft).setCursor(10, 10);
        (*tft).print(label);
        (*tft).setCursor(10, 120);
        (*tft).print(message);
        (*tft).setTextSize(1);
    }
}
boolean MsgScreen::wasShowing()
{
    return (lastShow && !show);
}