#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <Arduino.h>
const byte presetNum = 3;

const int8_t numMusicModes = 3;
const char musicModeName[numMusicModes][5] = { "off", "low", "high" };

const int8_t numLightsModes = 3;
const char lightsModeName[numLightsModes][5] = { "off", "low", "high" };

const int8_t numWordModes = 2;
const char wordModeName[2][8] = { "younger", "older" };


const int8_t modeNum = 6;
const char modeSelName[modeNum][7] = { "tag", "chase", "race", "walker", "still", "demo" };
const byte TAG_MODE_ID = 0;
const byte CHASE_MODE_ID = 1;
const byte RACE_MODE_ID = 2;
const byte WALKER_MODE_ID = 3;
const byte STILL_MODE_ID = 4;
const byte DEMO_MODE_ID = 5;

#endif
