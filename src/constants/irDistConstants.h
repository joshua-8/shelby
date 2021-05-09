#ifndef IR_DIST_CONSTANTS_H
#define IR_DIST_CONSTANTS_H
#include <Arduino.h>
struct irDistConsts {
    float A;
    float B;
    float max;
};
const irDistConsts irDistConstants[] {
    { 390.0, -.0382, .25 }, //right
    { 390.0, -.0382, .25 }, //front
    { 390.0, -.0382, .25 }, //left
    { 390.0, -.0382, .25 } //back
};
#endif