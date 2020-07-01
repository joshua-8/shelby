#ifndef MODE_SETTINGS_LISTIFY_H
#define MODE_SETTINGS_LISTIFY_H
#include "constants/constants.h"
#include "settings.h"
#include <Arduino.h>
const byte MODE_SETTINGS_LISTIFY_INT = 1;
const byte MODE_SETTINGS_LISTIFY_FLOAT = 2;
const byte MODE_SETTINGS_LISTIFY_BOOLEAN = 0;
int modeSettingsListifyGetLength(int mode);
int modeSettingsListifyGetIsBIF(int mode, int currVal);
float modeSettingsListifyGetVal(int mode, int currVal);
void modeSettingsListifySetVal(int mode, int currVal, float val);
String modeSettingsListifyGetName(int mode, int currVal);
#endif