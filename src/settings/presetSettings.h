#ifndef PRESET_SETTINGS_H
#define PRESET_SETTINGS_H
#include <Arduino.h>
#include "constants/constants.h"
#include "presetSettingsStructs.h"

tagModePresetSettingsStruct tagModePresetSettings[presetNum];
chaseModePresetSettingsStruct chaseModePresetSettings[presetNum];
raceModePresetSettingsStruct raceModePresetSettings[presetNum];
walkerModePresetSettingsStruct walkerModePresetSettings[presetNum];
demoModePresetSettingsStruct demoModePresetSettings[presetNum];

#endif