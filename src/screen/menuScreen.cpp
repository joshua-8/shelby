#include "menuScreen.h"

MenuScreen::MenuScreen(MouseData* _mouseData, Adafruit_ILI9341* _tft)
{
    numPad = new NumPad(_tft, _mouseData);
    preditScreen = new Screen_Predit(_mouseData, _tft, numPad, &screenMode);
    mseditScreen = new Screen_MSedit(_mouseData, _tft, numPad, &screenMode);
    teditScreen = new Screen_Tedit(_mouseData, _tft, numPad, &screenMode);
    homeScreen = new Screen_Home(_mouseData, _tft, &screenMode, preditScreen, mseditScreen, teditScreen);
}

void MenuScreen::begin()
{
    (*homeScreen).begin();
    screenMode = 0;
}

void MenuScreen::run()
{
    if (screenMode == menuScreenConstants.SCREEN_MODE_HOME) {
        (*homeScreen).run();
        if (screenMode == menuScreenConstants.SCREEN_MODE_PREDIT) {
            (*preditScreen).begin();
        }
        if (screenMode == menuScreenConstants.SCREEN_MODE_MSEDIT) {
            (*mseditScreen).begin();
        }
        if (screenMode == menuScreenConstants.SCREEN_MODE_TEDIT) {
            (*teditScreen).begin();
        }
    }
    if (screenMode == menuScreenConstants.SCREEN_MODE_PREDIT) {
        (*preditScreen).run();
        if (screenMode == menuScreenConstants.SCREEN_MODE_HOME) {
            (*homeScreen).begin();
        }
    }
    if (screenMode == menuScreenConstants.SCREEN_MODE_MSEDIT) {
        (*mseditScreen).run();
        if (screenMode == menuScreenConstants.SCREEN_MODE_HOME) {
            (*homeScreen).begin();
        }
    }
    if (screenMode == menuScreenConstants.SCREEN_MODE_TEDIT) {
        (*teditScreen).run();
        if (screenMode == menuScreenConstants.SCREEN_MODE_HOME) {
            (*homeScreen).begin();
        }
    }
}
