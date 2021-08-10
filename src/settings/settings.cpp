#include "settings.h"
generalSetStruct genS = { -1, 1, 0, 0, 0, 0, 1 };
generalSetStruct premodeLastGenS = genS;
generalSetStruct DURINGmodeLastGenS = genS;

tagModePresetSettingsStruct tagModePresetSettings[presetNum];
driveModePresetSettingsStruct driveModePresetSettings[presetNum];
stillModePresetSettingsStruct stillModePresetSettings[presetNum];
demoModePresetSettingsStruct demoModePresetSettings[presetNum];

tagModeModeSettingsStruct tagModeModeSettings;
driveModeModeSettingsStruct driveModeModeSettings;
stillModeModeSettingsStruct stillModeModeSettings;
demoModeModeSettingsStruct demoModeModeSettings;

topSettingsStruct topSettings;

int shortMusicPlaylistPos[audioConstants.musicListNum];
int longMusicPlaylistPos[audioConstants.musicListNum];