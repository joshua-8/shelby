#ifndef IR_DIST_CONSTANTS_H
#define IR_DIST_CONSTANTS_H
#include <Arduino.h>
struct irDistConsts {
    float A;
    float B;
};
const irDistConsts irDistConstants[] {
    { 390.0, -.0382 }, //right
    { 390.0, -.0382 }, //front
    { 390.0, -.0382 }, //left
    { 390.0, -.0382 } //back
};
#endif