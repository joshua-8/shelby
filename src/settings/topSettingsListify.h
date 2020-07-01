#ifndef TOP_SETTINGS_LISTIFY_H
#define TOP_SETTINGS_LISTIFY_H
#include "constants/constants.h"
#include "settings.h"
#include <Arduino.h>
const byte TOP_SETTINGS_LISTIFY_INT = 1;
const byte TOP_SETTINGS_LISTIFY_FLOAT = 2;
const byte TOP_SETTINGS_LISTIFY_BOOLEAN = 0;
int topSettingsListifyGetLength();
int topSettingsListifyGetIsBIF(int currVal);
float topSettingsListifyGetVal(int currVal);
void topSettingsListifySetVal(int currVal, float val);
String topSettingsListifyGetName(int currVal);
#endif