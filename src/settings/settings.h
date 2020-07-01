#ifndef SETTINGS_SETTINGS_H
#define SETTINGS_SETTINGS_H
#include <Arduino.h>
#include "generalSetStruct.h"
#include "presetSettingsStructs.h"
#include "modeSettingsStructs.h"
#include "topSettingsStruct.h"
#include "constants/constants.h"
extern generalSetStruct genS;

extern tagModePresetSettingsStruct tagModePresetSettings[presetNum];
extern chaseModePresetSettingsStruct chaseModePresetSettings[presetNum];
extern raceModePresetSettingsStruct raceModePresetSettings[presetNum];
extern walkerModePresetSettingsStruct walkerModePresetSettings[presetNum];
extern demoModePresetSettingsStruct demoModePresetSettings[presetNum];

extern tagModeModeSettingsStruct tagModeModeSettings;
extern chaseModeModeSettingsStruct chaseModeModeSettings;
extern raceModeModeSettingsStruct raceModeModeSettings;
extern walkerModeModeSettingsStruct walkerModeModeSettings;
extern demoModeModeSettingsStruct demoModeModeSettings;

extern topSettingsStruct topSettings;

#endif