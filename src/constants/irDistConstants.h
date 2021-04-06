#ifndef IR_DIST_CONSTANTS_H
#define IR_DIST_CONSTANTS_H
#include <Arduino.h>
struct irDistConsts {
    float A;
    float B;
    float max;
};
const irDistConsts irDistConstants[] {
    { 390.0, -.0382, .35 }, //right
    { 390.0, -.0382, .35 }, //front
    { 390.0, -.0382, .35 }, //left
    { 390.0, -.0382, .35 } //back
};
#endif