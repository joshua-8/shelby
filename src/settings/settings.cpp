#include "settings.h"
generalSetStruct genS = { -1, 1, 0, 0, 0, 0, 1 };
generalSetStruct lastGenS = genS;

tagModePresetSettingsStruct tagModePresetSettings[presetNum];
chaseModePresetSettingsStruct chaseModePresetSettings[presetNum];
raceModePresetSettingsStruct raceModePresetSettings[presetNum];
walkerModePresetSettingsStruct walkerModePresetSettings[presetNum];
stillModePresetSettingsStruct stillModePresetSettings[presetNum];
demoModePresetSettingsStruct demoModePresetSettings[presetNum];

tagModeModeSettingsStruct tagModeModeSettings;
chaseModeModeSettingsStruct chaseModeModeSettings;
raceModeModeSettingsStruct raceModeModeSettings;
walkerModeModeSettingsStruct walkerModeModeSettings;
stillModeModeSettingsStruct stillModeModeSettings;
demoModeModeSettingsStruct demoModeModeSettings;

topSettingsStruct topSettings;

int shortMusicPlaylistPos[audioConstants.musicListNum];
int longMusicPlaylistPos[audioConstants.musicListNum];