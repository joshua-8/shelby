#include "Screen_Home.h"
Screen_Home::Screen_Home(generalSetStruct* _genSettings, short* _screenMode, Adafruit_ILI9341* _tft, Screen_Predit* _preditScreen, Screen_MSedit* _mseditScreen, Screen_Tedit* _teditScreen)
{
    tft = _tft;
    genSettings = _genSettings;
    screenMode = _screenMode;
    preditScreen = _preditScreen;
    mseditScreen = _mseditScreen;
    teditScreen = _teditScreen;

    modeSettingsButton = new sButton(tft, menuScreenConstants.MODE_SETTINGS_BUTTON_POS_X, menuScreenConstants.MODE_SETTINGS_BUTTON_POS_Y, menuScreenConstants.MODE_SETTINGS_BUTTON_WIDTH, menuScreenConstants.MODE_SETTINGS_BUTTON_HEIGHT, menuScreenConstants.MODE_SETTINGS_BUTTON_SC, menuScreenConstants.MODE_SETTINGS_BUTTON_AC, menuScreenConstants.MODE_SETTINGS_BUTTON_TC, menuScreenConstants.MODE_SETTINGS_BUTTON_TC, "m set", true);
    topSettingsButton = new sButton(tft, menuScreenConstants.TOP_SETTINGS_BUTTON_POS_X, menuScreenConstants.TOP_SETTINGS_BUTTON_POS_Y, menuScreenConstants.TOP_SETTINGS_BUTTON_WIDTH, menuScreenConstants.TOP_SETTINGS_BUTTON_HEIGHT, menuScreenConstants.TOP_SETTINGS_BUTTON_SC, menuScreenConstants.TOP_SETTINGS_BUTTON_AC, menuScreenConstants.TOP_SETTINGS_BUTTON_TC, menuScreenConstants.TOP_SETTINGS_BUTTON_TC, "g set", true);

    for (int i = 0; i < modeNum; i++) {
        modeButton[i] = new sButton(tft, menuScreenConstants.MODE_SELECTOR_POS_X, menuScreenConstants.MODE_SELECTOR_POS_Y + i * menuScreenConstants.MODE_SELECTOR_HEIGHT / modeNum, menuScreenConstants.MODE_SELECTOR_WIDTH, menuScreenConstants.MODE_SELECTOR_HEIGHT / modeNum * (100 - menuScreenConstants.MODE_BUTTON_BLANK_PERCENT) / 100, menuScreenConstants.MODE_BUTTON_STANDARD_COLOR, menuScreenConstants.MODE_BUTTON_ACTIVE_COLOR, menuScreenConstants.MODE_BUTTON_TEXT_COLOR, menuScreenConstants.MODE_BUTTON_EDGE_COLOR, modeSelName[i], false);
    }
    for (int i = 0; i < presetNum; i++) {
        presetButton[i] = new sButton(tft, menuScreenConstants.PRESET_SELECTOR_POS_X + i * menuScreenConstants.PRESET_SELECTOR_WIDTH / presetNum, menuScreenConstants.PRESET_SELECTOR_POS_Y, menuScreenConstants.PRESET_SELECTOR_WIDTH / presetNum, menuScreenConstants.PRESET_SELECTOR_HEIGHT * menuScreenConstants.PRESET_SELECTOR_TOP_PERCENT / 100, menuScreenConstants.PRESET_BUTTON_STANDARD_COLOR, menuScreenConstants.PRESET_BUTTON_ACTIVE_COLOR, menuScreenConstants.PRESET_BUTTON_TEXT_COLOR, menuScreenConstants.PRESET_BUTTON_EDGE_COLOR, String("pre " + String(i + 1)), false);
        preditButton[i] = new sButton(tft, menuScreenConstants.PRESET_SELECTOR_POS_X + i * menuScreenConstants.PRESET_SELECTOR_WIDTH / presetNum, menuScreenConstants.PRESET_SELECTOR_HEIGHT * menuScreenConstants.PRESET_SELECTOR_TOP_PERCENT / 100, menuScreenConstants.PRESET_SELECTOR_WIDTH / presetNum, menuScreenConstants.PRESET_SELECTOR_HEIGHT * (100 - menuScreenConstants.PRESET_SELECTOR_TOP_PERCENT) / 100, menuScreenConstants.PRESET_BUTTON_STANDARD_COLOR, menuScreenConstants.PRESET_BUTTON_ACTIVE_COLOR, menuScreenConstants.PRESET_BUTTON_TEXT_COLOR, menuScreenConstants.PRESET_BUTTON_EDGE_COLOR, "edit", true);
    }
    wordModeButton = new sButton(tft, menuScreenConstants.WORD_MODE_BUTTON_POS_X, menuScreenConstants.ENTERTAINMENT_BUTTONS_POS_Y, menuScreenConstants.WORD_MODE_BUTTON_WIDTH, menuScreenConstants.ENTERTAINMENT_BUTTONS_HEIGHT, menuScreenConstants.ENTERTAINMENT_BUTTONS_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, "words: ", true);
    lightsModeButton = new sButton(tft, menuScreenConstants.LIGHTS_MODE_BUTTON_POS_X, menuScreenConstants.ENTERTAINMENT_BUTTONS_POS_Y, menuScreenConstants.LIGHTS_MODE_BUTTON_WIDTH, menuScreenConstants.ENTERTAINMENT_BUTTONS_HEIGHT, menuScreenConstants.ENTERTAINMENT_BUTTONS_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, "lights: ", true);
    musicModeButton = new sButton(tft, menuScreenConstants.MUSIC_MODE_BUTTON_POS_X, menuScreenConstants.ENTERTAINMENT_BUTTONS_POS_Y, menuScreenConstants.MUSIC_MODE_BUTTON_WIDTH, menuScreenConstants.ENTERTAINMENT_BUTTONS_HEIGHT, menuScreenConstants.ENTERTAINMENT_BUTTONS_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, "music: ", true);
    musicPlaylistButton = new sButton(tft, menuScreenConstants.MUSIC_PLAYLIST_BUTTON_POS_X, menuScreenConstants.ENTERTAINMENT_BUTTONS_POS_Y, menuScreenConstants.MUSIC_PLAYLIST_BUTTON_WIDTH, menuScreenConstants.ENTERTAINMENT_BUTTONS_HEIGHT, menuScreenConstants.ENTERTAINMENT_BUTTONS_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_ACTIVE_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, menuScreenConstants.ENTERTAINMENT_BUTTONS_TEXT_COLOR, "music", true);
    volSl = new volumeSlider(tft, menuScreenConstants.VOLUME_SLIDER_POS_X, menuScreenConstants.VOLUME_SLIDER_POS_Y, menuScreenConstants.VOLUME_SLIDER_WIDTH, menuScreenConstants.VOLUME_SLIDER_HEIGHT, menuScreenConstants.VOLUME_SLIDER_BACKGROUND_COLOR, menuScreenConstants.VOLUME_SLIDER_BOX_COLOR, audioConstants.AUDIO_BOARD_VOLUME_RANGE, menuScreenConstants.VOLUME_SLIDER_BOX_WIDTH, 0);
}

void Screen_Home::begin()
{
    (*tft).fillScreen(ILI9341_WHITE);
    (*tft).fillRect(menuScreenConstants.MODE_SELECTOR_POS_X, menuScreenConstants.MODE_SELECTOR_POS_Y, menuScreenConstants.MODE_SELECTOR_WIDTH, menuScreenConstants.MODE_SELECTOR_HEIGHT, menuScreenConstants.MODE_SELECTOR_BACKGROUND);
    setUndrawn();
    (*musicPlaylistButton).setSubText(audioConstants.musicListName[(*genSettings).musicList]);
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
        if ((*genSettings).musicList == sizeof(audioConstants.musicListName) / sizeof(audioConstants.musicListName[0]) - 1) {
            (*genSettings).musicList = 0;
        }
        (*musicPlaylistButton).setSubText(audioConstants.musicListName[(*genSettings).musicList]);
        saveGenSettingsSD(genSettings);
    }

    (*modeSettingsButton).run(mouseData);
    if ((*modeSettingsButton).getJustReleased() && (*genSettings).mode >= 0 && (*genSettings).mode < modeNum) {
        (*screenMode) = menuScreenConstants.SCREEN_MODE_MSEDIT;
    }

    (*topSettingsButton).run(mouseData);
    if ((*topSettingsButton).getJustReleased()) {
        (*screenMode) = menuScreenConstants.SCREEN_MODE_TEDIT;
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
            (*screenMode) = menuScreenConstants.SCREEN_MODE_PREDIT;
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
