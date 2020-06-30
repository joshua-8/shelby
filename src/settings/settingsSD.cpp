#include "settingsSD.h"
SdFatSdio sd;
SdFile file;
void recallAllSettingsSD(generalSetStruct* gs)
{
    recallAllPresetSettingsSd();
    recallAllModeSettingsSd();
    recallTopSettingsSD();
    recallGenSettingsSD(gs);
}
void setupSettingsSD()
{
    sd.begin();
}
