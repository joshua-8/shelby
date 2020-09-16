#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <Arduino.h>
const byte modeNum = 6;
const byte presetNum = 3;
const char musicModeName[3][5] = { "off", "low", "high" };
const char lightsModeName[3][5] = { "off", "low", "high" };
const int8_t numGenericModes = 3;
const char wordModeName[3][8] = { "younger", "older" };
const char modeSelName[6][7] = { "tag", "chase", "race", "walker", "still", "demo" };
const byte TAG_MODE_ID = 0;
const byte CHASE_MODE_ID = 1;
const byte RACE_MODE_ID = 2;
const byte WALKER_MODE_ID = 3;
const byte STILL_MODE_ID = 4;
const byte DEMO_MODE_ID = 5;
const int8_t numWordModes = 2;

#endif
