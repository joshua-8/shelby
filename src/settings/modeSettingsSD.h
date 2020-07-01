#ifndef MODE_SETTINGS_SD_H
#define MODE_SETTINGS_SD_H
#include "modeSettingsListify.h"
#include "settingsSD.h"
#include "constants/constants.h"
#include "screen/menuScreenConstants.h"
void recallAllModeSettingsSd();

void saveModeSettingsSD(int mode);

void recallModeSettingsSD(int mode);

void getModeSDFilePath(char* fileName,int mode);

#endif