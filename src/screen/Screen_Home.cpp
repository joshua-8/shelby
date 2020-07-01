#include "Screen_Home.h"
Screen_Home::Screen_Home(generalSetStruct* _genSettings, short* _screenMode, Adafruit_ILI9341* _tft, Screen_Predit* _preditScreen, Screen_MSedit* _mseditScreen, Screen_Tedit* _teditScreen)
{
    tft = _tft;
    genSettings = _genSettings;
    screenMode = _screenMode;
    preditScreen = _preditScreen;
    mseditScreen = _mseditScreen;
    teditScreen = _teditScreen;

    modeSettingsButton = new sButton(tft, MODE_SETTINGS_BUTTON_POS_X, MODE_SETTINGS_BUTTON_POS_Y, MODE_SETTINGS_BUTTON_WIDTH, MODE_SETTINGS_BUTTON_HEIGHT, MODE_SETTINGS_BUTTON_SC, MODE_SETTINGS_BUTTON_AC, MODE_SETTINGS_BUTTON_TC, MODE_SETTINGS_BUTTON_TC, "m set", true);
    topSettingsButton = new sButton(tft, TOP_SETTINGS_BUTTON_POS_X, TOP_SETTINGS_BUTTON_POS_Y, TOP_SETTINGS_BUTTON_WIDTH, TOP_SETTINGS_BUTTON_HEIGHT, TOP_SETTINGS_BUTTON_SC, TOP_SETTINGS_BUTTON_AC, TOP_SETTINGS_BUTTON_TC, TOP_SETTINGS_BUTTON_TC, "g set", true);

    for (int i = 0; i < modeNum; i++) {
        modeButton[i] = new sButton(tft, MODE_SELECTOR_POS_X, MODE_SELECTOR_POS_Y + i * MODE_SELECTOR_HEIGHT / modeNum, MODE_SELECTOR_WIDTH, MODE_SELECTOR_HEIGHT / modeNum * (100 - MODE_BUTTON_BLANK_PERCENT) / 100, MODE_BUTTON_STANDARD_COLOR, MODE_BUTTON_ACTIVE_COLOR, MODE_BUTTON_TEXT_COLOR, MODE_BUTTON_EDGE_COLOR, modeSelName[i], false);
    }
    for (int i = 0; i < presetNum; i++) {
        presetButton[i] = new sButton(tft, PRESET_SELECTOR_POS_X + i * PRESET_SELECTOR_WIDTH / presetNum, PRESET_SELECTOR_POS_Y, PRESET_SELECTOR_WIDTH / presetNum, PRESET_SELECTOR_HEIGHT * PRESET_SELECTOR_TOP_PERCENT / 100, PRESET_BUTTON_STANDARD_COLOR, PRESET_BUTTON_ACTIVE_COLOR, PRESET_BUTTON_TEXT_COLOR, PRESET_BUTTON_EDGE_COLOR, String("pre " + String(i + 1)), false);
        preditButton[i] = new sButton(tft, PRESET_SELECTOR_POS_X + i * PRESET_SELECTOR_WIDTH / presetNum, PRESET_SELECTOR_HEIGHT * PRESET_SELECTOR_TOP_PERCENT / 100, PRESET_SELECTOR_WIDTH / presetNum, PRESET_SELECTOR_HEIGHT * (100 - PRESET_SELECTOR_TOP_PERCENT) / 100, PRESET_BUTTON_STANDARD_COLOR, PRESET_BUTTON_ACTIVE_COLOR, PRESET_BUTTON_TEXT_COLOR, PRESET_BUTTON_EDGE_COLOR, "edit", true);
    }
    wordModeButton = new sButton(tft, WORD_MODE_BUTTON_POS_X, ENTERTAINMENT_BUTTONS_POS_Y, WORD_MODE_BUTTON_WIDTH, ENTERTAINMENT_BUTTONS_HEIGHT, ENTERTAINMENT_BUTTONS_COLOR, ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, ENTERTAINMENT_BUTTONS_TEXT_COLOR, ENTERTAINMENT_BUTTONS_TEXT_COLOR, "words: ", true);
    lightsModeButton = new sButton(tft, LIGHTS_MODE_BUTTON_POS_X, ENTERTAINMENT_BUTTONS_POS_Y, LIGHTS_MODE_BUTTON_WIDTH, ENTERTAINMENT_BUTTONS_HEIGHT, ENTERTAINMENT_BUTTONS_COLOR, ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, ENTERTAINMENT_BUTTONS_TEXT_COLOR, ENTERTAINMENT_BUTTONS_TEXT_COLOR, "lights: ", true);
    musicModeButton = new sButton(tft, MUSIC_MODE_BUTTON_POS_X, ENTERTAINMENT_BUTTONS_POS_Y, MUSIC_MODE_BUTTON_WIDTH, ENTERTAINMENT_BUTTONS_HEIGHT, ENTERTAINMENT_BUTTONS_COLOR, ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, ENTERTAINMENT_BUTTONS_TEXT_COLOR, ENTERTAINMENT_BUTTONS_TEXT_COLOR, "music: ", true);
    musicPlaylistButton = new sButton(tft, MUSIC_PLAYLIST_BUTTON_POS_X, ENTERTAINMENT_BUTTONS_POS_Y, MUSIC_PLAYLIST_BUTTON_WIDTH, ENTERTAINMENT_BUTTONS_HEIGHT, ENTERTAINMENT_BUTTONS_COLOR, ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, ENTERTAINMENT_BUTTONS_TEXT_COLOR, ENTERTAINMENT_BUTTONS_TEXT_COLOR, "music", true);
    volSl = new volumeSlider(tft, VOLUME_SLIDER_POS_X, VOLUME_SLIDER_POS_Y, VOLUME_SLIDER_WIDTH, VOLUME_SLIDER_HEIGHT, VOLUME_SLIDER_BACKGROUND_COLOR, VOLUME_SLIDER_BOX_COLOR, AUDIO_BOARD_VOLUME_RANGE, VOLUME_SLIDER_BOX_WIDTH, 0);
}

void Screen_Home::begin()
{
    (*tft).fillScreen(ILI9341_WHITE);
    (*tft).fillRect(MODE_SELECTOR_POS_X, MODE_SELECTOR_POS_Y, MODE_SELECTOR_WIDTH, MODE_SELECTOR_HEIGHT, MODE_SELECTOR_BACKGROUND);
    setUndrawn();
    (*musicPlaylistButton).setSubText(musicListName[(*genSettings).musicList]);
    (*wordModeButton).setSubText(wordModeName[(*genSettings).wordsMode]);
    (*lightsModeButton).setSubText(lightsModeName[(*genSettings).lightsMode]);
    (*musicModeButton).setSubText(musicModeName[(*genSettings).musicMode]);
    (*volSl).setVal((*genSettings).volume);
}

void Screen_Home::run(MouseData _mouseData)
{
    mouseData = _mouseData;
    modeSelector();
    presetSelector();
    genericButtons();
    (*volSl).run(mouseData);
    (*genSettings).volume = (*volSl).getVal();
    if ((*volSl).newValue()) {
        saveGenSettingsSD(genSettings);
    }
}

void Screen_Home::setUndrawn()
{
    for (int i = 0; i < modeNum; i++) {
        if ((*genSettings).mode == i) {
            (*modeButton[i]).setState(true);
        }
        (*modeButton[i]).setUndrawn();
    }
    for (int i = 0; i < presetNum; i++) {
        if ((*genSettings).preset == i) {
            (*presetButton[i]).setState(true);
        }
        (*presetButton[i]).setUndrawn();
        (*preditButton[i]).setUndrawn();
    }
    (*wordModeButton).setUndrawn();
    (*lightsModeButton).setUndrawn();
    (*musicModeButton).setUndrawn();
    (*musicPlaylistButton).setUndrawn();
    (*volSl).setVal((*genSettings).volume);
    (*volSl).setUndrawn();
    (*modeSettingsButton).setUndrawn();
    (*topSettingsButton).setUndrawn();
}

void Screen_Home::genericButtons()
{
    (*wordModeButton).run(mouseData);
    if ((*wordModeButton).getJustPushed()) {
        (*genSettings).wordsMode++;
        if ((*genSettings).wordsMode == numWordModes) {
            (*genSettings).wordsMode = 0;
        }
        (*wordModeButton).setSubText(wordModeName[(*genSettings).wordsMode]);
        saveGenSettingsSD(genSettings);
    }

    (*lightsModeButton).run(mouseData);
    if ((*lightsModeButton).getJustPushed()) {
        (*genSettings).lightsMode++;
        if ((*genSettings).lightsMode == numGenericModes) {
            (*genSettings).lightsMode = 0;
        }
        (*lightsModeButton).setSubText(lightsModeName[(*genSettings).lightsMode]);
        saveGenSettingsSD(genSettings);
    }

    (*musicModeButton).run(mouseData);
    if ((*musicModeButton).getJustPushed()) {
        (*genSettings).musicMode++;
        if ((*genSettings).musicMode == numGenericModes) {
            (*genSettings).musicMode = 0;
        }
        (*musicModeButton).setSubText(musicModeName[(*genSettings).musicMode]);
        saveGenSettingsSD(genSettings);
    }

    (*musicPlaylistButton).run(mouseData);
    if ((*musicPlaylistButton).getJustPushed()) {
        (*genSettings).musicList++;
        if ((*genSettings).musicList == sizeof(musicListName) / sizeof(musicListName[0]) - 1) {
            (*genSettings).musicList = 0;
        }
        (*musicPlaylistButton).setSubText(musicListName[(*genSettings).musicList]);
        saveGenSettingsSD(genSettings);
    }

    (*modeSettingsButton).run(mouseData);
    if ((*modeSettingsButton).getJustReleased() && (*genSettings).mode >= 0 && (*genSettings).mode < modeNum) {
        (*screenMode) = SCREEN_MODE_MSEDIT;
    }

    (*topSettingsButton).run(mouseData);
    if ((*topSettingsButton).getJustReleased()) {
        (*screenMode) = SCREEN_MODE_TEDIT;
    }
}

void Screen_Home::presetSelector()
{
    for (int i = 0; i < presetNum; i++) {
        (*presetButton[i]).run(mouseData);
        if ((*presetButton[i]).getJustPushed()) {
            (*presetButton[i]).setState(true);
            (*genSettings).preset = i;
            for (int j = 0; j < presetNum; j++) {
                if (j != i) {
                    (*presetButton[j]).setState(false);
                }
            }
            recallPresetSettingsSD((*genSettings).mode, i);
            saveGenSettingsSD(genSettings);
        }
        if ((*presetButton[i]).getJustReleased() && i == (*genSettings).preset) {
            (*presetButton[i]).setState(true);
        }

        (*preditButton[i]).run(mouseData);
        if ((*preditButton[i]).getJustReleased() && (*genSettings).mode >= 0 && (*genSettings).mode < modeNum) {
            (*screenMode) = SCREEN_MODE_PREDIT;
            (*preditScreen).setPreset(i);
        }
    }
}

void Screen_Home::modeSelector()
{
    for (int i = 0; i < modeNum; i++) {
        (*modeButton[i]).run(mouseData);
        if ((*modeButton[i]).getJustPushed()) {
            (*genSettings).mode = i;
            (*modeButton[i]).setState(true);
            for (int j = 0; j < modeNum; j++) {
                if (j != i) {
                    (*modeButton[j]).setState(false);
                }
            }
            saveGenSettingsSD(genSettings);
        }
        if ((*modeButton[i]).getJustReleased()) {
            (*genSettings).mode = -1;
        }
    }
}
