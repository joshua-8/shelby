#include "settingsSD.h"
SdFatSdio sd;
SdFile file;
void recallAllSettings(){
    recallAllPresetSettingsSd();
}
void setupSettingsSD(){
    sd.begin();
}
