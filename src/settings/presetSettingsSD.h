#ifndef PRESET_SETTINGS_SD_H
#define PRESET_SETTINGS_SD_H
#include "presetSettingsListify.h"
#include "settingsSD.h"
#include "constants/constants.h"
#include "screen/menuScreenConstants.h"
void recallAllPresetSettingsSd();

void savePresetSettingsSD(int mode, int preset);

void recallPresetSettingsSD(int mode, int preset);

void getPresetSDFilePath(char* fileName,int mode, int preset);


#endif