#ifndef SETTINGS_SETTINGS_H
#define SETTINGS_SETTINGS_H
#include "constants/audioConstants.h"
#include "constants/constants.h"
#include "generalSetStruct.h"
#include "modeSettingsStructs.h"
#include "presetSettingsStructs.h"
#include "topSettingsStruct.h"
#include <Arduino.h>
extern generalSetStruct genS;
extern generalSetStruct lastGenS;

extern tagModePresetSettingsStruct tagModePresetSettings[presetNum];
extern chaseModePresetSettingsStruct chaseModePresetSettings[presetNum];
extern raceModePresetSettingsStruct raceModePresetSettings[presetNum];
extern walkerModePresetSettingsStruct walkerModePresetSettings[presetNum];
extern stillModePresetSettingsStruct stillModePresetSettings[presetNum];
extern demoModePresetSettingsStruct demoModePresetSettings[presetNum];

extern tagModeModeSettingsStruct tagModeModeSettings;
extern chaseModeModeSettingsStruct chaseModeModeSettings;
extern raceModeModeSettingsStruct raceModeModeSettings;
extern walkerModeModeSettingsStruct walkerModeModeSettings;
extern stillModeModeSettingsStruct stillModeModeSettings;
extern demoModeModeSettingsStruct demoModeModeSettings;

extern topSettingsStruct topSettings;

extern int shortMusicPlaylistPos[audioConstants.musicListNum];
extern int longMusicPlaylistPos[audioConstants.musicListNum];

#endif