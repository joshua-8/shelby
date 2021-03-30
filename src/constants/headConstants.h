#ifndef HEAD_CONSTANTS_H
#define HEAD_CONSTANTS_H
#include <Arduino.h>
class headConsts {
public:
    int leftRange = 1845;
    float leftDeg = -90;
    int rightRange = 555;
    float rightDeg = 90;
    int upRange = 1305;
    float upDeg = 27;
    int downRange = 1650;
    float downDeg = -20;
    float panSpeed = 0.04;
    float tiltSpeed = 0.015;
    //RIGHT VAL= -63
    //LEFT VAL = +23
    //UP VAL   = -13
    //DOWN VAL = +10
};
static const headConsts headConstants;
#endif