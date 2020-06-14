#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <Arduino.h>
const byte modeNum = 5;
const byte presetNum = 3;
const char musicModeName[3][5] = {"off", "low", "high"};
const char lightsModeName[3][5] = {"off", "low", "high"};
const int8_t numGenericModes = 3;
const char wordModeName[3][8] = {"younger", "older"};
const char modeSelName[5][7] = {"tag", "chase", "race", "walker", "demo"};
const int8_t numWordModes = 2;

#endif
