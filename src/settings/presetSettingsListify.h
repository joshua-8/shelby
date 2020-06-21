#ifndef PRESET_SETTINGS_LISTIFY_H
#define PRESET_SETTINGS_LISTIFY_H
#include "constants/constants.h"
#include "settings.h"
#include <Arduino.h>
const byte PRESET_SETTINGS_LISTIFY_INT = 1;
const byte PRESET_SETTINGS_LISTIFY_FLOAT = 2;
const byte PRESET_SETTINGS_LISTIFY_BOOLEAN = 0;
int presetSettingsListifyGetLength(int mode);
int presetSettingsListifyGetIsBIF(int mode, int currVal);
float presetSettingsListifyGetVal(int mode, int preset, int currVal);
void presetSettingsListifySetVal(int mode, int preset, int currVal, float val);
String presetSettingsListifyGetName(int mode, int currVal);
#endif