#include "msgScreen.h"
MsgScreen::MsgScreen(IR* _subsysir)
{
    closeTimer = false;
    closeTime = 0;
    show = false;
    lastShow = false;

    selCurrDig = 0;
    valSelDone = false;
    selecting = false;
    selVal = 0;
    selNumDig = 0;
    subsysir = _subsysir;
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

    if (selecting) {
        if (subsysir->message == irConstants.OK && subsysir->newMsg && !subsysir->repeat) {
            valSelDone = true;
            selecting = false;
        }
        if (subsysir->message == irConstants.LEFT && subsysir->newMsg && !subsysir->repeat) {
            selCurrDig++;
            if (selCurrDig >= selNumDig) {
                selCurrDig = selNumDig - 1;
            }
            drawSel();
        }
        if (subsysir->message == irConstants.RIGHT && subsysir->newMsg && !subsysir->repeat) {
            if (selCurrDig > 0) {
                selCurrDig--;
            }
            drawSel();
        }
        if (subsysir->message == irConstants.UP && subsysir->newMsg && !subsysir->repeat) {
            if ((selVal / int(pow(10, selCurrDig))) % 10 == 9) {
                selVal -= 9 * pow(10, selCurrDig);
            } else {
                selVal += pow(10, selCurrDig);
            }
            drawSel();
        }
        if (subsysir->message == irConstants.DOWN && subsysir->newMsg && !subsysir->repeat) {
            if ((selVal / int(pow(10, selCurrDig))) % 10 == 0) {
                selVal += 9 * pow(10, selCurrDig);
            } else {
                selVal -= pow(10, selCurrDig);
            }
            drawSel();
        }
    }
    if (valSelDone) {
        show = false;
    }
    return show;
}

void MsgScreen::drawSel()
{
    (*tft).fillScreen(ILI9341_WHITE);
    (*tft).setTextColor(ILI9341_BLACK);
    (*tft).setTextSize(8);
    (*tft).setCursor(10, 10);
    (*tft).print(selVal);
    (*tft).setCursor(10, 120);
    (*tft).print(message);
    (*tft).print("  ");
    (*tft).print(selCurrDig);
    (*tft).setTextSize(1);
}

void MsgScreen::dispValSelector(String label, int digits, int startVal)
{
    show = true;
    closeTimer = false;
    selCurrDig = 0;
    message = label;
    selNumDig = digits;
    selVal = startVal;
    valSelDone = false;
    selecting = true;
    (*tft).fillScreen(ILI9341_WHITE);
    drawSel();
}
boolean MsgScreen::valSelectorDone()
{
    if (valSelDone) {
        valSelDone = false;
        return true;
    }
    return false;
}
int MsgScreen::valSelectorValue()
{
    return selVal;
}
void MsgScreen::dispMessage(String label, String message, int time)
{
    valSelDone = false;
    selecting = false;
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