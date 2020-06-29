#include "screen_msedit.h"
Screen_MSedit::Screen_MSedit(generalSetStruct* _genSettings, short* _screenMode, Adafruit_ILI9341* _tft, NumPad* _numPad)
{
    tft = _tft;
    screenMode = _screenMode;
    numPad = _numPad;
    genSettings = _genSettings;
    saveButton = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH / 3, 0, NUMPAD_WIDTH * 2 / 3, NUMPAD_POS_Y, NUMPAD_YES_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_YES_COLOR, "save", true);
    cancelButton = new sButton(tft, NUMPAD_POS_X, 0, NUMPAD_WIDTH / 3, NUMPAD_POS_Y, NUMPAD_DEL_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_DEL_COLOR, "cancel", true);
    setlist = new mseditSetList(tft, NUMPAD_WIDTH, 0, SCREEN_WIDTH - NUMPAD_WIDTH, SCREEN_HEIGHT);
}

void Screen_MSedit::begin()
{
    (*numPad).begin();
    (*setlist).begin();
    (*setlist).setMode((*genSettings).mode);
    setUndrawn();
}

void Screen_MSedit::run(MouseData mouseData)
{
    (*cancelButton).run(mouseData);
    (*saveButton).run(mouseData);
    if ((*cancelButton).getJustReleased()) {
        recallModeSettingsSD((*genSettings).mode);
        (*screenMode) = SCREEN_MODE_HOME;
    }
    if ((*saveButton).getJustReleased()) {
        saveModeSettingsSD((*genSettings).mode);
        (*screenMode) = SCREEN_MODE_HOME;
    }
    (*numPad).run(mouseData);
    (*setlist).run(numPad, &mouseData);
}

void Screen_MSedit::setUndrawn()
{
    (*numPad).setUndrawn();
    (*saveButton).setUndrawn();
    (*cancelButton).setUndrawn();
    (*setlist).setUndrawn();
}
