#include "settingsSD.h"
SdFatSdio sd;
SdFile file;
void recallAllSettingsSD()
{
    recallAllPresetSettingsSd();
    recallAllModeSettingsSd();
    recallTopSettingsSD();
    recallGenSettingsSD();
    recallMusicSettingsSD();
}
void setupSettingsSD()
{
    sd.begin();
}
