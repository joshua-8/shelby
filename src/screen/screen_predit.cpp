#include "screen_predit.h"
Screen_Predit::Screen_Predit(generalSetStruct* _genSettings, short* _screenMode, Adafruit_ILI9341* _tft, NumPad* _numPad)
{
    tft = _tft;
    screenMode = _screenMode;
    numPad = _numPad;
    genSettings = _genSettings;
    saveButton = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH / 3, 0, NUMPAD_WIDTH * 2 / 3, NUMPAD_POS_Y, PREDIT_SAVE_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, PREDIT_SAVE_COLOR, "save", true);
    cancelButton = new sButton(tft, NUMPAD_POS_X, 0, NUMPAD_WIDTH / 3, NUMPAD_POS_Y, PREDIT_CANCEL_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, PREDIT_CANCEL_COLOR, "cancel", true);
}

void Screen_Predit::begin()
{
    (*tft).fillScreen(ILI9341_RED);
    (*numPad).begin();
    setUndrawn();
}

void Screen_Predit::setPreset(byte _presetID)
{
    presetID = _presetID;
    (*saveButton).setSubText(String(presetID + 1));
}

void Screen_Predit::run(MouseData mouseData)
{
  (*cancelButton).run(mouseData);
  (*saveButton).run(mouseData);
    if ((*cancelButton).getJustReleased()) {
        //TODO: RECALL PRESETS
        (*screenMode) = SCREEN_MODE_HOME;
    }
    if ((*saveButton).getJustReleased()) {
        //TODO: SAVE PRESETS
        (*screenMode) = SCREEN_MODE_HOME;
    }

    if ((*numPad).run(mouseData)) {
        (*tft).fillRect(155, 120, 100, 100, ILI9341_RED);

        (*tft).setCursor(160, 130);
        (*tft).println((*numPad).getFinalValString());
        (*tft).setCursor(160, 190);
        (*tft).println((*numPad).getString());
    }
}

void Screen_Predit::setUndrawn()
{
    (*numPad).setUndrawn();
    (*saveButton).setUndrawn();
    (*cancelButton).setUndrawn();
}
