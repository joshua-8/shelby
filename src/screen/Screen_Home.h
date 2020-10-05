#ifndef SCREEN_HOME_H
#define SCREEN_HOME_H

#include "MouseData.h"
#include "constants/audioConstants.h"
#include "constants/constants.h"
#include "menuScreenConstants.h"
#include "sButton.h"
#include "screen_msedit.h"
#include "screen_predit.h"
#include "screen_tedit.h"
#include "settings/generalSetStruct.h"
#include "settings/settingsSD.h"
#include "shelbytron_globs.h"
#include "volumeSlider.h"
#include <Arduino.h>

class Screen_Home {
public:
    Screen_Home(MouseData* _mouseData, Adafruit_ILI9341* _tft, short* _screenMode, Screen_Predit* _preditScreen, Screen_MSedit* _mseditScreen, Screen_Tedit* _teditScreen);

public:
    void begin();
    void run();

private:
    MouseData* mouseData;
    Adafruit_ILI9341* tft;
    short* screenMode;

    volumeSlider* volSl;

    sButton* modeButton[modeNum];
    sButton* presetButton[presetNum];
    sButton* preditButton[presetNum];

    sButton* modeSettingsButton;
    sButton* topSettingsButton;

    sButton* wordModeButton;
    sButton* lightsModeButton;
    sButton* musicModeButton;
    sButton* musicPlaylistButton;

    Screen_Predit* preditScreen;
    Screen_MSedit* mseditScreen;
    Screen_Tedit* teditScreen;

    float lastBatVolt;
    unsigned long lastBatDispUpdateMillis;

    void modeSelector();
    void presetSelector();
    void genericButtons();
    void setUndrawn();
    void batteryDisplay();
};
#endif
