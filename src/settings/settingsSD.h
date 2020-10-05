#ifndef SETTINGS_SD_H
#define SETTINGS_SD_H
#include "SdFat.h"
#include <SPI.h>
#include "presetSettingsSD.h"
#include "modeSettingsSD.h"
#include "topSettingsSD.h"
#include "genSettingsSD.h"
#include "settings.h"

extern SdFatSdio sd;
extern SdFile file;

void setupSettingsSD();

void recallAllSettingsSD();


#endif