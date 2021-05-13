#ifndef IR_DIST_CONSTANTS_H
#define IR_DIST_CONSTANTS_H
#include <Arduino.h>
struct irDistConsts {
    float A;
    float B;
    float max;
    float smooth;
};
const irDistConsts irDistConstants[] {
    { 390.0, -.0382, .25, .3 }, //right
    { 390.0, -.0382, .25, .3 }, //front
    { 390.0, -.0382, .25, .3 }, //left
    { 390.0, -.0382, .25, .3 } //back
};
#endif