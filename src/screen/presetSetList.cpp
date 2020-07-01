#include "presetSetList.h"

presetSetList::presetSetList(Adafruit_ILI9341* _tft, int _xPos, int _yPos, int _width, int _height)
{
    tft = _tft;
    xPos = _xPos;
    yPos = _yPos;
    width = _width - SETTING_LIST_SCROLL_BAR_WIDTH;
    height = _height;
    length = 0;
    drawn = false;
    currVal = -1;
    mode = 0;
    preset = 0;
    mouseStartupUnlocked = false;
}
void presetSetList::run(NumPad* numpad, MouseData* mouseData)
{
    if (mouseStartupUnlocked && (*mouseData).mouseUp && abs((*mouseData).mouseYDown - (*mouseData).mouseYUp) < SETTING_LIST_ROW_HEIGHT && (*mouseData).mouseXUp > xPos && (*mouseData).mouseXUp < xPos + width && (*mouseData).mouseYUp > yPos && (*mouseData).mouseYUp < yPos + height) {
        currVal = ((*mouseData).mouseYUp - yPos + scroll * height) / SETTING_LIST_ROW_HEIGHT;
        (*numpad).setVal(presetSettingsListifyGetVal(mode, preset, currVal));
        (*numpad).setInteger(presetSettingsListifyGetIsBIF(mode, currVal) == PRESET_SETTINGS_LISTIFY_INT);
        drawn = false;
    }
    if (length > 1) {
        if ((*mouseData).mousePressed && (*mouseData).lastMouseX > xPos + width && (*mouseData).lastMouseX < xPos + width + SETTING_LIST_SCROLL_BAR_WIDTH && (*mouseData).lastMouseY > yPos && (*mouseData).lastMouseY < yPos + height) {
            scroll = map((*mouseData).lastMouseY, yPos + .05 * height, yPos + .95 * height, 0, length - 1);
            drawn = false;
            scroll = constrain(scroll, 0, length - 1);
        }
    }
    if (!(*mouseData).mousePressed) {
        mouseStartupUnlocked = true;
    }
    if (currVal != -1 && (*numpad).getChanged()) {
        drawn = false;
    }

    if (currVal != -1 && presetSettingsListifyGetIsBIF(mode, currVal) != PRESET_SETTINGS_LISTIFY_BOOLEAN && (*numpad).getFinalized()) {
        presetSettingsListifySetVal(mode, preset, currVal, (*numpad).getFinalVal());
        currVal = -1;
        drawn = false;
    }
    if (currVal != -1 && presetSettingsListifyGetIsBIF(mode, currVal) == PRESET_SETTINGS_LISTIFY_BOOLEAN) {
        presetSettingsListifySetVal(mode, preset, currVal, !presetSettingsListifyGetVal(mode, preset, currVal)); //toggle
        currVal = -1;
        drawn = false;
    }

    if (!drawn) {
        (*tft).setTextColor(SETTING_LIST_TEXT_COLOR);
        (*tft).setTextSize(1);
        for (int i = 0; i < presetSettingsListifyGetLength(mode); i++) {
            float y = i * SETTING_LIST_ROW_HEIGHT - scroll * height + yPos;
            if (y - yPos >= -SETTING_LIST_ROW_HEIGHT || y - yPos <= height) { //show
                if (presetSettingsListifyGetIsBIF(mode, i) == PRESET_SETTINGS_LISTIFY_BOOLEAN) { //boolean
                    (*tft).fillRect(xPos, y, width, SETTING_LIST_ROW_HEIGHT, SETTING_LIST_BACKGROUND_COLOR);
                    if (presetSettingsListifyGetVal(mode, preset, i)) { //boolean true
                        (*tft).fillRect(xPos + width * SETTING_LIST_VAL_POS, y + SETTING_LIST_ROW_HEIGHT * .1, width / 4, SETTING_LIST_ROW_HEIGHT * .8, SETTING_LIST_TRUE_COLOR);
                        (*tft).setCursor(xPos + width * SETTING_LIST_VAL_POS, y + SETTING_LIST_ROW_HEIGHT * .3);
                        (*tft).print("true");
                    } else {
                        (*tft).fillRect(xPos + width * SETTING_LIST_VAL_POS, y + SETTING_LIST_ROW_HEIGHT * .1, width / 4, SETTING_LIST_ROW_HEIGHT * .8, SETTING_LIST_FALSE_COLOR);
                        (*tft).setCursor(xPos + width * SETTING_LIST_VAL_POS, y + SETTING_LIST_ROW_HEIGHT * .3);
                        (*tft).print("false");
                    }
                } else { //number
                    if (currVal == i) {
                        (*tft).fillRect(xPos, y, width, SETTING_LIST_ROW_HEIGHT, SETTING_LIST_SEL_COLOR);
                        (*tft).setCursor(xPos + width * SETTING_LIST_VAL_POS, y + SETTING_LIST_ROW_HEIGHT / 2 - SCREEN_FONT_HEIGHT);
                        (*tft).print((*numpad).getString());
                    } else {
                        (*tft).fillRect(xPos, y, width, SETTING_LIST_ROW_HEIGHT, SETTING_LIST_BACKGROUND_COLOR);
                        (*tft).setCursor(xPos + width * SETTING_LIST_VAL_POS, y + SETTING_LIST_ROW_HEIGHT / 2 - SCREEN_FONT_HEIGHT);
                        (*tft).print(valToString(presetSettingsListifyGetVal(mode, preset, i), presetSettingsListifyGetIsBIF(mode, i) == PRESET_SETTINGS_LISTIFY_INT));
                    }
                }
                (*tft).setCursor(xPos + SCREEN_FONT_WIDTH, y + SETTING_LIST_ROW_HEIGHT / 2 - SCREEN_FONT_HEIGHT);
                (*tft).print(presetSettingsListifyGetName(mode, i));
                (*tft).drawRect(xPos, y, width, SETTING_LIST_ROW_HEIGHT, SETTING_LIST_OUTLINE_COLOR);
            }
            (*tft).fillRect(xPos + width, yPos, SETTING_LIST_SCROLL_BAR_WIDTH, height, SETTING_LIST_BACKGROUND_COLOR);
        }
        if (length < 1) {
            (*tft).fillRect(xPos, yPos + height * (length), width, height * (1.0 - length), SETTING_LIST_BACKGROUND_COLOR);
        } else {
            (*tft).fillRect(xPos + width, yPos + map(scroll, 0, length - 1, 0, height * .9), SETTING_LIST_SCROLL_BAR_WIDTH, height * .1, SETTING_LIST_SEL_COLOR);
        }
        drawn = true;
    }
}
void presetSetList::presetSetList::begin()
{
    scroll = 0;
    currVal = -1;
    mouseStartupUnlocked = false;
    setUndrawn();
}
void presetSetList::setPresetAndMode(int _preset, int _mode)
{
    preset = _preset;
    mode = _mode;
    length = (float)presetSettingsListifyGetLength(mode) * SETTING_LIST_ROW_HEIGHT / height;
}
void presetSetList::setUndrawn()
{
    drawn = false;
}

String presetSetList::valToString(float val, boolean integer)
{
    if (integer) {
        return String(val, 0);
    }
    return String(val, NUMPAD_STRING_LENGTH - 1 - max(int(log10(abs(val))), 0));
}