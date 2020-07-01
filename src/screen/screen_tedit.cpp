#include "screen_tedit.h"
Screen_Tedit::Screen_Tedit(short* _screenMode, Adafruit_ILI9341* _tft, NumPad* _numPad)
{
    tft = _tft;
    screenMode = _screenMode;
    numPad = _numPad;
    saveButton = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH / 3, 0, NUMPAD_WIDTH * 2 / 3, NUMPAD_POS_Y, NUMPAD_YES_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_YES_COLOR, "save", true);
    cancelButton = new sButton(tft, NUMPAD_POS_X, 0, NUMPAD_WIDTH / 3, NUMPAD_POS_Y, NUMPAD_DEL_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_DEL_COLOR, "cancel", true);
    setlist = new topSetList(tft, NUMPAD_WIDTH, 0, SCREEN_WIDTH - NUMPAD_WIDTH, SCREEN_HEIGHT);
}

void Screen_Tedit::begin()
{
    (*numPad).begin();
    (*setlist).begin();
    setUndrawn();
}

void Screen_Tedit::run(MouseData mouseData)
{
    (*cancelButton).run(mouseData);
    (*saveButton).run(mouseData);
    if ((*cancelButton).getJustReleased()) {
        recallTopSettingsSD();
        (*screenMode) = SCREEN_MODE_HOME;
    }
    if ((*saveButton).getJustReleased()) {
        saveTopSettingsSD();
        (*screenMode) = SCREEN_MODE_HOME;
    }
    (*numPad).run(mouseData);
    (*setlist).run(numPad, &mouseData);
}

void Screen_Tedit::setUndrawn()
{
    (*numPad).setUndrawn();
    (*saveButton).setUndrawn();
    (*cancelButton).setUndrawn();
    (*setlist).setUndrawn();
}
