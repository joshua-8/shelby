#include "screen_predit.h"
Screen_Predit::Screen_Predit(generalSetStruct* _genSettings, short* _screenMode, Adafruit_ILI9341* _tft, NumPad* _numPad)
{
    tft = _tft;
    screenMode = _screenMode;
    numPad = _numPad;
    genSettings = _genSettings;
    saveButton = new sButton(tft, menuScreenConstants.NUMPAD_POS_X + menuScreenConstants.NUMPAD_WIDTH / 3, 0, menuScreenConstants.NUMPAD_WIDTH * 2 / 3, menuScreenConstants.NUMPAD_POS_Y, menuScreenConstants.NUMPAD_YES_COLOR, menuScreenConstants.NUMPAD_ACTIVE_COLOR, menuScreenConstants.NUMPAD_TEXT_COLOR, menuScreenConstants.NUMPAD_YES_COLOR, "save", true);
    cancelButton = new sButton(tft, menuScreenConstants.NUMPAD_POS_X, 0, menuScreenConstants.NUMPAD_WIDTH / 3, menuScreenConstants.NUMPAD_POS_Y, menuScreenConstants.NUMPAD_DEL_COLOR, menuScreenConstants.NUMPAD_ACTIVE_COLOR, menuScreenConstants.NUMPAD_TEXT_COLOR, menuScreenConstants.NUMPAD_DEL_COLOR, "cancel", true);
    setlist = new presetSetList(tft, menuScreenConstants.NUMPAD_WIDTH, 0, menuScreenConstants.SCREEN_WIDTH - menuScreenConstants.NUMPAD_WIDTH, menuScreenConstants.SCREEN_HEIGHT);
}

void Screen_Predit::begin()
{
    (*numPad).begin();
    (*setlist).begin();
    setUndrawn();
}

void Screen_Predit::setPreset(byte _presetID)
{
    presetID = _presetID;
    (*saveButton).setSubText(String(presetID + 1));
    (*setlist).setPresetAndMode(presetID, (*genSettings).mode);
}

void Screen_Predit::run(MouseData mouseData)
{
    (*cancelButton).run(mouseData);
    (*saveButton).run(mouseData);
    if ((*cancelButton).getJustReleased()) {
        recallPresetSettingsSD((*genSettings).mode,presetID);
        (*screenMode) = menuScreenConstants.SCREEN_MODE_HOME;
    }
    if ((*saveButton).getJustReleased()) {
        savePresetSettingsSD((*genSettings).mode,presetID);
        (*screenMode) = menuScreenConstants.SCREEN_MODE_HOME;
    }
    (*numPad).run(mouseData);
    (*setlist).run(numPad, &mouseData);
}

void Screen_Predit::setUndrawn()
{
    (*numPad).setUndrawn();
    (*saveButton).setUndrawn();
    (*cancelButton).setUndrawn();
    (*setlist).setUndrawn();
}
