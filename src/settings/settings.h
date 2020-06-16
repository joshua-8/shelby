#ifndef SETTINGS_SETTINGS_H
#define SETTINGS_SETTINGS_H
#include <Arduino.h>
#include "generalSetStruct.h"
#include "presetSettingsStructs.h"
#include "constants/constants.h"
generalSetStruct genS = { -1, -1, 1, 0, 0, 0};
tagModePresetSettingsStruct tagModePresetSettings[presetNum];
chaseModePresetSettingsStruct chaseModePresetSettings[presetNum];
raceModePresetSettingsStruct raceModePresetSettings[presetNum];
walkerModePresetSettingsStruct walkerModePresetSettings[presetNum];
demoModePresetSettingsStruct demoModePresetSettings[presetNum];
#endif