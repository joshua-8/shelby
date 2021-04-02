#include "settingsSD.h"
SdFat sd;
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
    sd.begin(SdioConfig(FIFO_SDIO));
}
