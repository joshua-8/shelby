#include "Screen_Home.h"
Screen_Home::Screen_Home(MouseData* _mouseData, Adafruit_ILI9341* _tft, short* _screenMode, Screen_Predit* _preditScreen, Screen_MSedit* _mseditScreen, Screen_Tedit* _teditScreen)
{
    screenMode = _screenMode;
    mouseData = _mouseData;
    preditScreen = _preditScreen;
    mseditScreen = _mseditScreen;
    teditScreen = _teditScreen;
    tft = _tft;
    modeSettingsButton = new sButton(tft, mouseData, menuScreenConstants.MODE_SETTINGS_BUTTON_POS_X, menuScreenConstants.MODE_SETTINGS_BUTTON_POS_Y, menuScreenConstants.MODE_SETTINGS_BUTTON_WIDTH, menuScreenConstants.MODE_SETTINGS_BUTTON_HEIGHT, menuScreenConstants.MODE_SETTINGS_BUTTON_SC, menuScreenConstants.MODE_SETTINGS_BUTTON_AC, menuScreenConstants.MODE_SETTINGS_BUTTON_TC, menuScreenConstants.MODE_SETTINGS_BUTTON_TC, "m set", true);
    topSettingsButton = new sButton(tft, mouseData, menuScreenConstants.TOP_SETTINGS_BUTTON_POS_X, menuScreenConstants.TOP_SETTINGS_BUTTON_POS_Y, menuScreenConstants.TOP_SETTINGS_BUTTON_WIDTH, menuScreenConstants.TOP_SETTINGS_BUTTON_HEIGHT, menuScreenConstants.TOP_SETTINGS_BUTTON_SC, menuScreenConstants.TOP_SETTINGS_BUTTON_AC, menuScreenConstants.TOP_SETTINGS_BUTTON_TC, menuScreenConstants.TOP_SETTINGS_BUTTON_TC, "g set", true);

    for (int i = 0; i < modeNum; i++) {
        modeButton[i] = new sButton(tft, mouseData, menuScreenConstants.MODE_SELECTOR_POS_X, menuScreenConstants.MODE_SELECTOR_POS_Y + i * menuScreenConstants.MODE_SELECTOR_HEIGHT / modeNum, menuScreenConstants.MODE_SELECTOR_WIDTH, menuScreenConstants.MODE_SELECTOR_HEIGHT / modeNum * (100 - menuScreenConstants.MODE_BUTTON_BLANK_PERCENT) / 100, menuScreenConstants.MODE_BUTTON_STANDARD_COLOR, menuScreenConstants.MODE_BUTTON_ACTIVE_COLOR, menuScreenConstants.MODE_BUTTON_TEXT_COLOR, menuScreenConstants.MODE_BUTTON_EDGE_COLOR, modeSelName[i], false);
    }
    for (int i = 0; i < presetNum; i++) {
        presetButton[i] = new sButton(tft, mouseData, menuScreenConstants.PRESET_SELECTOR_POS_X + i * menuScreenConstants.PRESET_SELECTOR_WIDTH / presetNum, menuScreenConstants.PRESET_SELECTOR_POS_Y, menuScreenConstants.PRESET_SELECTOR_WIDTH / presetNum, menuScreenConstants.PRESET_SELECTOR_HEIGHT * menuScreenConstants.PRESET_SELECTOR_TOP_PERCENT / 100, menuScreenConstants.PRESET_BUTTON_STANDARD_COLOR, menuScreenConstants.PRESET_BUTTON_ACTIVE_COLOR, menuScreenConstants.PRESET_BUTTON_TEXT_COLOR, menuScreenConstants.PRESET_BUTTON_EDGE_COLOR, String("pre " + String(i + 1)), false);
        preditButton[i] = new sButton(tft, mouseData, menuScreenConstants.PRESET_SELECTOR_POS_X + i * menuScreenConstants.PRESET_SELECTOR_WIDTH / presetNum, menuScreenConstants.PRESET_SELECTOR_HEIGHT * menuScreenConstants.PRESET_SELECTOR_TOP_PERCENT / 100, menuScreenConstants.PRESET_SELECTOR_WIDTH / presetNum, menuScreenConstants.PRESET_SELECTOR_HEIGHT * (100 - menuScreenConstants.PRESET_SELECTOR_TOP_PERCENT) / 100, menuScreenConstants.PRESET_BUTTON_STANDARD_COLOR, menuScreenConstants.PRESET_BUTTON_ACTIVE_COLOR, menuScreenConstants.PRESET_BUTTON_TEXT_COLOR, menuScreenConstants.PRESET_BUTTON_EDGE_COLOR, "edit", true);
    }
    wordModeButton = new sButton(tft, mouseData, menuScreenConstants.WORD_MODE_BUTTON_POS_X, menuScreenConstants.ENTERTAINMENT_BUTTONS_POS_Y, menuScreenConstants.WORD_MODE_BUTTON_WIDTH, menuScreenConstants.ENTERTAINMENT_BUTTONS_HEIGHT, menuScreenConstants.ENTERTAINMENT_BUTTONS_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, "words: ", true);
    lightsModeButton = new sButton(tft, mouseData, menuScreenConstants.LIGHTS_MODE_BUTTON_POS_X, menuScreenConstants.ENTERTAINMENT_BUTTONS_POS_Y, menuScreenConstants.LIGHTS_MODE_BUTTON_WIDTH, menuScreenConstants.ENTERTAINMENT_BUTTONS_HEIGHT, menuScreenConstants.ENTERTAINMENT_BUTTONS_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, "lights: ", true);
    musicModeButton = new sButton(tft, mouseData, menuScreenConstants.MUSIC_MODE_BUTTON_POS_X, menuScreenConstants.ENTERTAINMENT_BUTTONS_POS_Y, menuScreenConstants.MUSIC_MODE_BUTTON_WIDTH, menuScreenConstants.ENTERTAINMENT_BUTTONS_HEIGHT, menuScreenConstants.ENTERTAINMENT_BUTTONS_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, "music: ", true);
    musicPlaylistButton = new sButton(tft, mouseData, menuScreenConstants.MUSIC_PLAYLIST_BUTTON_POS_X, menuScreenConstants.ENTERTAINMENT_BUTTONS_POS_Y, menuScreenConstants.MUSIC_PLAYLIST_BUTTON_WIDTH, menuScreenConstants.ENTERTAINMENT_BUTTONS_HEIGHT, menuScreenConstants.ENTERTAINMENT_BUTTONS_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, "music", true);
    volSl = new volumeSlider(tft, mouseData, menuScreenConstants.VOLUME_SLIDER_POS_X, menuScreenConstants.VOLUME_SLIDER_POS_Y, menuScreenConstants.VOLUME_SLIDER_WIDTH, menuScreenConstants.VOLUME_SLIDER_HEIGHT, menuScreenConstants.VOLUME_SLIDER_BACKGROUND_COLOR, menuScreenConstants.VOLUME_SLIDER_BOX_COLOR, audioConstants.AUDIO_BOARD_VOLUME_RANGE, menuScreenConstants.VOLUME_SLIDER_BOX_WIDTH, 0);
    lastBatVolt = -1;
    lastBatDispUpdateMillis = -1;
}

void Screen_Home::begin()
{
    (*tft).fillScreen(ILI9341_WHITE);
    (*tft).fillRect(menuScreenConstants.MODE_SELECTOR_POS_X, menuScreenConstants.MODE_SELECTOR_POS_Y, menuScreenConstants.MODE_SELECTOR_WIDTH, menuScreenConstants.MODE_SELECTOR_HEIGHT, menuScreenConstants.MODE_SELECTOR_BACKGROUND);
    setUndrawn();
    (*musicPlaylistButton).setSubText(audioConstants.musicListName[genS.musicList]);
    (*wordModeButton).setSubText(wordModeName[genS.wordsMode]);
    (*lightsModeButton).setSubText(lightsModeName[genS.lightsMode]);
    (*musicModeButton).setSubText(musicModeName[genS.musicMode]);
    (*volSl).setVal(genS.volume);
    for (int j = 0; j < modeNum; j++) {
        if (j != genS.mode) {
            (*modeButton[j]).setState(false);
        } else {
            (*modeButton[j]).setState(true);
        }
    }
}

void Screen_Home::run()
{
    modeSelector();
    presetSelector();
    genericButtons();
    if (genS.volume != (*volSl).getVal()) {
        (*volSl).setVal(genS.volume);
    }
    (*volSl).run();
    genS.volume = (*volSl).getVal();
    if ((*volSl).newValue()) {
        saveGenSettingsSD();
    }
    batteryDisplay();
}

void Screen_Home::batteryDisplay()
{
    if (millis() - lastBatDispUpdateMillis > menuScreenConstants.BATTERY_DISPLAY_INTERVAL) {
        lastBatDispUpdateMillis = millis();
        if (abs(subsystems.batMonitor.getBatVolt() - lastBatVolt) >= menuScreenConstants.BATTERY_DISPLAY_ERROR) {
            lastBatVolt = subsystems.batMonitor.getBatVolt();
            (*tft).fillRect(menuScreenConstants.BATTERY_DISPLAY_X_POS, menuScreenConstants.BATTERY_DISPLAY_Y_POS + menuScreenConstants.BATTERY_DISPLAY_HEIGHT * menuScreenConstants.BATTERY_GAUGE_PORTION, menuScreenConstants.BATTERY_DISPLAY_WIDTH, menuScreenConstants.BATTERY_DISPLAY_HEIGHT * (1 - menuScreenConstants.BATTERY_GAUGE_PORTION), menuScreenConstants.BATTERY_DISPLAY_BACKGROUND_COLOR);
            (*tft).setTextColor(menuScreenConstants.BATTERY_DISPLAY_TEXT_COLOR);
            (*tft).setTextSize(3);
            (*tft).setCursor(menuScreenConstants.BATTERY_DISPLAY_X_POS, menuScreenConstants.BATTERY_DISPLAY_Y_POS + .6 * menuScreenConstants.BATTERY_DISPLAY_HEIGHT);
            (*tft).print(subsystems.batMonitor.getBatVolt(), 2);
            (*tft).fillRect(menuScreenConstants.BATTERY_DISPLAY_X_POS, menuScreenConstants.BATTERY_DISPLAY_Y_POS, menuScreenConstants.BATTERY_DISPLAY_WIDTH / 4 - 1, menuScreenConstants.BATTERY_DISPLAY_HEIGHT * menuScreenConstants.BATTERY_GAUGE_PORTION, subsystems.batMonitor.getBatVolt() > batMonitorConstants.highVoltThresh ? ILI9341_GREEN : ILI9341_RED);
            (*tft).fillRect(menuScreenConstants.BATTERY_DISPLAY_X_POS + menuScreenConstants.BATTERY_DISPLAY_WIDTH / 4, menuScreenConstants.BATTERY_DISPLAY_Y_POS, menuScreenConstants.BATTERY_DISPLAY_WIDTH / 2 - 1, menuScreenConstants.BATTERY_DISPLAY_HEIGHT * menuScreenConstants.BATTERY_GAUGE_PORTION, subsystems.batMonitor.getBatVolt() > batMonitorConstants.lowVoltThresh ? ILI9341_GREEN : ILI9341_RED);
            (*tft).fillRect(menuScreenConstants.BATTERY_DISPLAY_X_POS + menuScreenConstants.BATTERY_DISPLAY_WIDTH * 3 / 4, menuScreenConstants.BATTERY_DISPLAY_Y_POS, menuScreenConstants.BATTERY_DISPLAY_WIDTH / 3, menuScreenConstants.BATTERY_DISPLAY_HEIGHT * menuScreenConstants.BATTERY_GAUGE_PORTION, subsystems.batMonitor.getBatVolt() > batMonitorConstants.criticalVoltThresh ? ILI9341_GREEN : ILI9341_RED);
        }
    }
}

void Screen_Home::setUndrawn()
{
    lastBatDispUpdateMillis = -1;
    lastBatVolt = -1;
    for (int i = 0; i < modeNum; i++) {
        if (genS.mode == i) {
            (*modeButton[i]).setState(true);
        }
        (*modeButton[i]).setUndrawn();
    }
    for (int i = 0; i < presetNum; i++) {
        if (genS.preset == i) {
            (*presetButton[i]).setState(true);
        }
        (*presetButton[i]).setUndrawn();
        (*preditButton[i]).setUndrawn();
    }
    (*wordModeButton).setUndrawn();
    (*lightsModeButton).setUndrawn();
    (*musicModeButton).setUndrawn();
    (*musicPlaylistButton).setUndrawn();
    (*volSl).setVal(genS.volume);
    (*volSl).setUndrawn();
    (*modeSettingsButton).setUndrawn();
    (*topSettingsButton).setUndrawn();
    (*tft).fillRect(menuScreenConstants.BATTERY_DISPLAY_X_POS, menuScreenConstants.BATTERY_DISPLAY_Y_POS, menuScreenConstants.BATTERY_DISPLAY_WIDTH, menuScreenConstants.BATTERY_DISPLAY_HEIGHT, menuScreenConstants.BATTERY_DISPLAY_BACKGROUND_COLOR);
}

void Screen_Home::genericButtons()
{
    (*wordModeButton).run();
    if ((*wordModeButton).getJustPushed()) {
        genS.wordsMode++;
        if (genS.wordsMode >= numWordModes) {
            genS.wordsMode = 0;
        }
        (*wordModeButton).setSubText(wordModeName[genS.wordsMode]);
        saveGenSettingsSD();
    }

    (*lightsModeButton).run();
    if ((*lightsModeButton).getJustPushed()) {
        genS.lightsMode++;
        if (genS.lightsMode >= numLightsModes) {
            genS.lightsMode = 0;
        }
        (*lightsModeButton).setSubText(lightsModeName[genS.lightsMode]);
        saveGenSettingsSD();
    }

    (*musicModeButton).run();
    if ((*musicModeButton).getJustPushed()) {
        genS.musicMode++;
        if (genS.musicMode >= numMusicModes) {
            genS.musicMode = 0;
        }
        (*musicModeButton).setSubText(musicModeName[genS.musicMode]);
        saveGenSettingsSD();
    }

    (*musicPlaylistButton).run();
    if ((*musicPlaylistButton).getJustPushed()) {
        genS.musicList++;
        if (genS.musicList >= audioConstants.musicListNum) {
            genS.musicList = 0;
        }
        (*musicPlaylistButton).setSubText(audioConstants.musicListName[genS.musicList]);
        saveGenSettingsSD();
    }

    (*modeSettingsButton).run();
    if ((*modeSettingsButton).getJustReleased() && genS.mode >= 0 && genS.mode < modeNum) {
        (*screenMode) = menuScreenConstants.SCREEN_MODE_MSEDIT;
    }

    (*topSettingsButton).run();
    if ((*topSettingsButton).getJustReleased()) {
        (*screenMode) = menuScreenConstants.SCREEN_MODE_TEDIT;
    }
}

void Screen_Home::presetSelector()
{
    for (int i = 0; i < presetNum; i++) {
        if (i != genS.preset) {
            (*presetButton[i]).run();
        }
        if ((*presetButton[i]).getJustPushed()) {
            (*presetButton[i]).setState(true);
            genS.preset = i;
            for (int j = 0; j < presetNum; j++) {
                if (j != i) {
                    (*presetButton[j]).setState(false);
                }
            }
            recallPresetSettingsSD(genS.mode, i);
            saveGenSettingsSD();
        }

        (*preditButton[i]).run();
        if ((*preditButton[i]).getJustReleased() && genS.mode >= 0 && genS.mode < modeNum) {
            (*screenMode) = menuScreenConstants.SCREEN_MODE_PREDIT;
            (*preditScreen).setPreset(i);
        }
    }
}

void Screen_Home::modeSelector()
{
    for (int i = 0; i < modeNum; i++) {
        (*modeButton[i]).run();
        if ((*modeButton[i]).getJustPushed()) {
            genS.mode = i;
            go = false;
            (*modeButton[i]).setState(true);
            for (int j = 0; j < modeNum; j++) {
                if (j != i) {
                    (*modeButton[j]).setState(false);
                }
            }
            saveGenSettingsSD();
        }
        if ((*modeButton[i]).getJustReleased()) {
            genS.mode = -1;
            go = false;
        }
    }
}
