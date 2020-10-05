#include "settingsSD.h"
SdFatSdio sd;
SdFile file;
void recallAllSettingsSD()
{
    recallAllPresetSettingsSd();
    recallAllModeSettingsSd();
    recallTopSettingsSD();
    recallGenSettingsSD();
}
void setupSettingsSD()
{
    sd.begin();
}
