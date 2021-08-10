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
extern generalSetStruct premodeLastGenS;
extern generalSetStruct DURINGmodeLastGenS;

extern tagModePresetSettingsStruct tagModePresetSettings[presetNum];
extern driveModePresetSettingsStruct driveModePresetSettings[presetNum];
extern stillModePresetSettingsStruct stillModePresetSettings[presetNum];
extern demoModePresetSettingsStruct demoModePresetSettings[presetNum];

extern tagModeModeSettingsStruct tagModeModeSettings;
extern driveModeModeSettingsStruct driveModeModeSettings;
extern stillModeModeSettingsStruct stillModeModeSettings;
extern demoModeModeSettingsStruct demoModeModeSettings;

extern topSettingsStruct topSettings;

extern int shortMusicPlaylistPos[audioConstants.musicListNum];
extern int longMusicPlaylistPos[audioConstants.musicListNum];

#endif