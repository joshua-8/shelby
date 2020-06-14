#ifndef GENERAL_SET_STRUCT_H
#define GENERAL_SET_STRUCT_H
#include <Arduino.h>
struct generalSetStruct
{
  int8_t mode;
  int8_t lastMode;
  int8_t preset;
  int8_t musicMode;
  int8_t lightsMode;
  int8_t wordsMode;
};
#endif
