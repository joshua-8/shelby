#include "topSetList.h"

topSetList::topSetList(Adafruit_ILI9341* _tft, MouseData* _mouseData, NumPad* _numPad, int _xPos, int _yPos, int _width, int _height)
{
    tft = _tft;
    mouseData = _mouseData;
    numPad = _numPad;
    xPos = _xPos;
    yPos = _yPos;
    width = _width - menuScreenConstants.SETTING_LIST_SCROLL_BAR_WIDTH;
    height = _height;
    drawn = false;
    currVal = -1;
    scroll = 0;
    mouseStartupUnlocked = false;
    length = (float)topSettingsListifyGetLength() * menuScreenConstants.SETTING_LIST_ROW_HEIGHT / height;
}
void topSetList::run()
{
    if (mouseStartupUnlocked && (*mouseData).mouseUp && abs((*mouseData).mouseYDown - (*mouseData).mouseYUp) < menuScreenConstants.SETTING_LIST_ROW_HEIGHT && (*mouseData).mouseXUp > xPos && (*mouseData).mouseXUp < xPos + width && (*mouseData).mouseYUp > yPos && (*mouseData).mouseYUp < yPos + height) {
        currVal = ((*mouseData).mouseYUp - yPos + scroll * height) / menuScreenConstants.SETTING_LIST_ROW_HEIGHT;
        (*numPad).setVal(topSettingsListifyGetVal(currVal));
        (*numPad).setInteger(topSettingsListifyGetIsBIF(currVal) == TOP_SETTINGS_LISTIFY_INT);
        drawn = false;
    }
    if (length > 1.0) {
        if ((*mouseData).mousePressed && (*mouseData).lastMouseX > xPos + width && (*mouseData).lastMouseX < xPos + width + menuScreenConstants.SETTING_LIST_SCROLL_BAR_WIDTH && (*mouseData).lastMouseY > yPos && (*mouseData).lastMouseY < yPos + height) {
            scroll = map((*mouseData).lastMouseY, yPos + .05 * height, yPos + .95 * height, 0, length - 1);
            drawn = false;
            scroll = constrain(scroll, 0, length - 1);
        }
    }
    if (!(*mouseData).mousePressed) {
        mouseStartupUnlocked = true;
    }
    if (currVal != -1 && (*numPad).getChanged()) {
        drawn = false;
    }

    if (currVal != -1 && topSettingsListifyGetIsBIF(currVal) != TOP_SETTINGS_LISTIFY_BOOLEAN && (*numPad).getFinalized()) {
        topSettingsListifySetVal(currVal, (*numPad).getFinalVal());
        currVal = -1;
        drawn = false;
    }
    if (currVal != -1 && topSettingsListifyGetIsBIF(currVal) == TOP_SETTINGS_LISTIFY_BOOLEAN) {
        topSettingsListifySetVal(currVal, !topSettingsListifyGetVal(currVal)); //toggle
        currVal = -1;
        drawn = false;
    }

    if (!drawn) {
        (*tft).setTextColor(menuScreenConstants.SETTING_LIST_TEXT_COLOR);
        (*tft).setTextSize(1);
        for (int i = 0; i < topSettingsListifyGetLength(); i++) {
            float y = i * menuScreenConstants.SETTING_LIST_ROW_HEIGHT - scroll * height + yPos;
            if (y - yPos >= -menuScreenConstants.SETTING_LIST_ROW_HEIGHT || y - yPos <= height) { //show
                if (topSettingsListifyGetIsBIF(i) == TOP_SETTINGS_LISTIFY_BOOLEAN) { //boolean
                    (*tft).fillRect(xPos, y, width, menuScreenConstants.SETTING_LIST_ROW_HEIGHT, menuScreenConstants.SETTING_LIST_BACKGROUND_COLOR);
                    if (topSettingsListifyGetVal(i)) { //boolean true
                        (*tft).fillRect(xPos + width * menuScreenConstants.SETTING_LIST_VAL_POS, y + menuScreenConstants.SETTING_LIST_ROW_HEIGHT * .1, width / 4, menuScreenConstants.SETTING_LIST_ROW_HEIGHT * .8, menuScreenConstants.SETTING_LIST_TRUE_COLOR);
                        (*tft).setCursor(xPos + width * menuScreenConstants.SETTING_LIST_VAL_POS, y + menuScreenConstants.SETTING_LIST_ROW_HEIGHT * .3);
                        (*tft).print("true");
                    } else {
                        (*tft).fillRect(xPos + width * menuScreenConstants.SETTING_LIST_VAL_POS, y + menuScreenConstants.SETTING_LIST_ROW_HEIGHT * .1, width / 4, menuScreenConstants.SETTING_LIST_ROW_HEIGHT * .8, menuScreenConstants.SETTING_LIST_FALSE_COLOR);
                        (*tft).setCursor(xPos + width * menuScreenConstants.SETTING_LIST_VAL_POS, y + menuScreenConstants.SETTING_LIST_ROW_HEIGHT * .3);
                        (*tft).print("false");
                    }
                } else { //number
                    if (currVal == i) {
                        (*tft).fillRect(xPos, y, width, menuScreenConstants.SETTING_LIST_ROW_HEIGHT, menuScreenConstants.SETTING_LIST_SEL_COLOR);
                        (*tft).setCursor(xPos + width * menuScreenConstants.SETTING_LIST_VAL_POS, y + menuScreenConstants.SETTING_LIST_ROW_HEIGHT / 2 - menuScreenConstants.SCREEN_FONT_HEIGHT);
                        (*tft).print((*numPad).getString());
                    } else {
                        (*tft).fillRect(xPos, y, width, menuScreenConstants.SETTING_LIST_ROW_HEIGHT, menuScreenConstants.SETTING_LIST_BACKGROUND_COLOR);
                        (*tft).setCursor(xPos + width * menuScreenConstants.SETTING_LIST_VAL_POS, y + menuScreenConstants.SETTING_LIST_ROW_HEIGHT / 2 - menuScreenConstants.SCREEN_FONT_HEIGHT);
                        (*tft).print(valToString(topSettingsListifyGetVal(i), topSettingsListifyGetIsBIF(i) == TOP_SETTINGS_LISTIFY_INT));
                    }
                }
                (*tft).setCursor(xPos + menuScreenConstants.SCREEN_FONT_WIDTH, y + menuScreenConstants.SETTING_LIST_ROW_HEIGHT / 2 - menuScreenConstants.SCREEN_FONT_HEIGHT);
                (*tft).print(topSettingsListifyGetName(i));
                (*tft).drawRect(xPos, y, width, menuScreenConstants.SETTING_LIST_ROW_HEIGHT, menuScreenConstants.SETTING_LIST_OUTLINE_COLOR);
            }
            (*tft).fillRect(xPos + width, yPos, menuScreenConstants.SETTING_LIST_SCROLL_BAR_WIDTH, height, menuScreenConstants.SETTING_LIST_BACKGROUND_COLOR);
        }
        if (length < 1.0) {
            (*tft).fillRect(xPos, yPos + height * (length), width, height * (1.0 - length), menuScreenConstants.SETTING_LIST_BACKGROUND_COLOR);
        } else {
            (*tft).fillRect(xPos + width, yPos + map(scroll, 0, length - 1, 0, height * .9), menuScreenConstants.SETTING_LIST_SCROLL_BAR_WIDTH, height * .1, menuScreenConstants.SETTING_LIST_SEL_COLOR);
        }
        drawn = true;
    }
}
void topSetList::begin()
{
    scroll = 0;
    currVal = -1;
    mouseStartupUnlocked = false;
    setUndrawn();
}
void topSetList::setUndrawn()
{
    drawn = false;
}

String topSetList::valToString(float val, boolean integer)
{
    if (integer) {
        return String(val, 0);
    }
    return String(val, menuScreenConstants.NUMPAD_STRING_LENGTH - 1 - max(int(log10(abs(val))), 0));
}