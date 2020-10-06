#ifndef GO_BUTTON_CONSTANTS_H
#define GO_BUTTON_CONSTANTS_H
#include <Arduino.h>
class goButtonConsts {
public:
    const byte switchDebounceTime = 4;
};
static goButtonConsts goButtonConstants;
#endif