#ifndef TAIL_CONSTANTS_H
#define TAIL_CONSTANTS_H
#include <Arduino.h>
class tailConsts {
public:
    int leftRange = 1000;
    int rightRange = 2000;
};
static const tailConsts tailConstants;
#endif