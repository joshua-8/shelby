#include "settingsSD.h"
SdFatSdio sd;
SdFile file;
void recallAllSettings(){
    recallAllPresetSettingsSd();
    recallAllModeSettingsSd();
}
void setupSettingsSD(){
    sd.begin();
}
