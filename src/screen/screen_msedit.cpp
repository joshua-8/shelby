#include "screen_msedit.h"
Screen_MSedit::Screen_MSedit(MouseData* _mouseData, Adafruit_ILI9341* _tft, NumPad* _numPad, short* _screenMode)
{
    tft = _tft;
    screenMode = _screenMode;
    numPad = _numPad;
    saveButton = new sButton(tft, _mouseData, menuScreenConstants.NUMPAD_POS_X + menuScreenConstants.NUMPAD_WIDTH / 3, 0, menuScreenConstants.NUMPAD_WIDTH * 2 / 3, menuScreenConstants.NUMPAD_POS_Y, menuScreenConstants.NUMPAD_YES_COLOR, menuScreenConstants.NUMPAD_ACTIVE_COLOR, menuScreenConstants.NUMPAD_TEXT_COLOR, menuScreenConstants.NUMPAD_YES_COLOR, "save", true);
    cancelButton = new sButton(tft, _mouseData, menuScreenConstants.NUMPAD_POS_X, 0, menuScreenConstants.NUMPAD_WIDTH / 3, menuScreenConstants.NUMPAD_POS_Y, menuScreenConstants.NUMPAD_DEL_COLOR, menuScreenConstants.NUMPAD_ACTIVE_COLOR, menuScreenConstants.NUMPAD_TEXT_COLOR, menuScreenConstants.NUMPAD_DEL_COLOR, "cancel", true);
    setlist = new mseditSetList(tft, _mouseData, _numPad, menuScreenConstants.NUMPAD_WIDTH, 0, menuScreenConstants.SCREEN_WIDTH - menuScreenConstants.NUMPAD_WIDTH, menuScreenConstants.SCREEN_HEIGHT);
}

void Screen_MSedit::begin()
{
    (*numPad).begin();
    (*setlist).begin();
    (*setlist).setMode(genS.mode);
    setUndrawn();
}

void Screen_MSedit::run()
{
    (*cancelButton).run();
    (*saveButton).run();
    if ((*cancelButton).getJustReleased()) {
        recallModeSettingsSD(genS.mode);
        (*screenMode) = menuScreenConstants.SCREEN_MODE_HOME;
    }
    if ((*saveButton).getJustReleased()) {
        saveModeSettingsSD(genS.mode);
        (*screenMode) = menuScreenConstants.SCREEN_MODE_HOME;
    }
    (*numPad).run();
    (*setlist).run();
}

void Screen_MSedit::setUndrawn()
{
    (*numPad).setUndrawn();
    (*saveButton).setUndrawn();
    (*cancelButton).setUndrawn();
    (*setlist).setUndrawn();
}
