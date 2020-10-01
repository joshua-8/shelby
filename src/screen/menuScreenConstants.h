#ifndef MENU_SCREEN_CONSTANTS_H
#define MENU_SCREEN_CONSTANTS_H
#include <Arduino.h>
#include "screenConstants.h"
class menuScreenConsts {
public:
    const short SCREEN_MODE_HOME = 0;
    const short SCREEN_MODE_PREDIT = 1;
    const short SCREEN_MODE_MSEDIT = 2;
    const short SCREEN_MODE_TEDIT = 3;

    const int SCREEN_WIDTH = screenConstants.SCREEN_WIDTH;
    const int SCREEN_HEIGHT = screenConstants.SCREEN_WIDTH;
    
    const short SCREEN_FONT_WIDTH = 6;
    const short SCREEN_FONT_HEIGHT = 8;

    const int MODE_SELECTOR_POS_X = 0;
    const int MODE_SELECTOR_POS_Y = 0;
    const int MODE_SELECTOR_WIDTH = 54;
    const int MODE_SELECTOR_HEIGHT = 211;
    const byte MODE_BUTTON_BLANK_PERCENT = 5;

    const uint16_t MODE_SELECTOR_BACKGROUND = 0; //BLACK
    const uint16_t MODE_BUTTON_STANDARD_COLOR = 50712; //GREY
    const uint16_t MODE_BUTTON_ACTIVE_COLOR = 34800; //LIGHT GREEN
    const uint16_t MODE_BUTTON_TEXT_COLOR = 128; //DARK GREEN
    const uint16_t MODE_BUTTON_EDGE_COLOR = 128; //DARK GREEN

    const int PRESET_SELECTOR_POS_X = 54;
    const int PRESET_SELECTOR_POS_Y = 0;
    const int PRESET_SELECTOR_WIDTH = 54 * 3;
    const int PRESET_SELECTOR_HEIGHT = 101;
    const byte PRESET_SELECTOR_TOP_PERCENT = 60;
    const uint16_t PRESET_BUTTON_STANDARD_COLOR = 65504; //YELLOW
    const uint16_t PRESET_BUTTON_ACTIVE_COLOR = 65535; //WHITE
    const uint16_t PRESET_BUTTON_TEXT_COLOR = 0; //BLACK
    const uint16_t PRESET_BUTTON_EDGE_COLOR = 0; //BLACK

    const int MODE_SETTINGS_BUTTON_POS_X = 216;
    const int MODE_SETTINGS_BUTTON_POS_Y = PRESET_SELECTOR_POS_Y + PRESET_SELECTOR_HEIGHT * PRESET_SELECTOR_TOP_PERCENT / 100;
    const int MODE_SETTINGS_BUTTON_WIDTH = 52;
    const int MODE_SETTINGS_BUTTON_HEIGHT = PRESET_SELECTOR_HEIGHT * (100 - PRESET_SELECTOR_TOP_PERCENT) / 100;
    const uint16_t MODE_SETTINGS_BUTTON_SC = 65504; //YELLOW
    const uint16_t MODE_SETTINGS_BUTTON_AC = 65535; //WHITE
    const uint16_t MODE_SETTINGS_BUTTON_TC = 0;

    const int TOP_SETTINGS_BUTTON_POS_X = 268;
    const int TOP_SETTINGS_BUTTON_POS_Y = PRESET_SELECTOR_POS_Y + PRESET_SELECTOR_HEIGHT * PRESET_SELECTOR_TOP_PERCENT / 100;
    const int TOP_SETTINGS_BUTTON_WIDTH = 52;
    const int TOP_SETTINGS_BUTTON_HEIGHT = PRESET_SELECTOR_HEIGHT * (100 - PRESET_SELECTOR_TOP_PERCENT) / 100;
    const uint16_t TOP_SETTINGS_BUTTON_SC = 65504; //YELLOW
    const uint16_t TOP_SETTINGS_BUTTON_AC = 65535; //WHITE
    const uint16_t TOP_SETTINGS_BUTTON_TC = 0;

    const int VOLUME_SLIDER_POS_X = 0;
    const int VOLUME_SLIDER_POS_Y = 211;
    const int VOLUME_SLIDER_WIDTH = 320;
    const int VOLUME_SLIDER_HEIGHT = 29;
    const uint16_t VOLUME_SLIDER_BACKGROUND_COLOR = 1171; //BLUE-GREEN
    const uint16_t VOLUME_SLIDER_BOX_COLOR = 2016; //GREEN
    const int VOLUME_SLIDER_BOX_WIDTH = 42;

    const int WORD_MODE_BUTTON_POS_X = 54;
    const int WORD_MODE_BUTTON_WIDTH = 54;
    const int ENTERTAINMENT_BUTTONS_HEIGHT = 50;
    const int ENTERTAINMENT_BUTTONS_POS_Y = 100;
    const int LIGHTS_MODE_BUTTON_WIDTH = 54;
    const int LIGHTS_MODE_BUTTON_POS_X = 108;
    const int MUSIC_MODE_BUTTON_WIDTH = 54;
    const int MUSIC_MODE_BUTTON_POS_X = 162;
    const int MUSIC_PLAYLIST_BUTTON_POS_X = 216;
    const int MUSIC_PLAYLIST_BUTTON_WIDTH = 52;
    const uint16_t ENTERTAINMENT_BUTTONS_COLOR = 52093; //LIGHT PURPLE
    const uint16_t ENTERTAINMENT_BUTTONS_ACTIVE_COLOR = 65535; //WHITE
    const uint16_t ENTERTAINMENT_BUTTONS_TEXT_COLOR = 0; //BLACK

    const unsigned int NUMPAD_STRING_LENGTH = 6;
    const int NUMPAD_WIDTH = 150;
    const int NUMPAD_HEIGHT = 200;
    const int NUMPAD_POS_X = 0;
    const int NUMPAD_POS_Y = 40;
    const uint16_t NUMPAD_BACKGROUND_COLOR = 65535; //white
    const uint16_t NUMPAD_ACTIVE_COLOR = 50712; //light grey
    const uint16_t NUMPAD_TEXT_COLOR = 0; //black
    const uint16_t NUMPAD_YES_COLOR = 2016; //green
    const uint16_t NUMPAD_NO_COLOR = 64008; //red
    const uint16_t NUMPAD_DEL_COLOR = 65504; //yellow
    const unsigned int NUMPAD_DEL_LONG_HOLD = 333;

    const int SETTING_LIST_ROW_HEIGHT = 36;
    const uint16_t SETTING_LIST_BACKGROUND_COLOR = 50712; //light grey
    const uint16_t SETTING_LIST_TRUE_COLOR = 1171; //BLUE-GREEN
    const uint16_t SETTING_LIST_FALSE_COLOR = 64008; //red
    const uint16_t SETTING_LIST_SEL_COLOR = 52093; //LIGHT PURPLE
    const uint16_t SETTING_LIST_OUTLINE_COLOR = 0; //BLACK
    const uint16_t SETTING_LIST_TEXT_COLOR = 0; //BLACK
    const float SETTING_LIST_VAL_POS = .63;
    const int SETTING_LIST_SCROLL_BAR_WIDTH = 30;
};

static menuScreenConsts menuScreenConstants;

#endif
