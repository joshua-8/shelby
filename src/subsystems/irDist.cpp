#include "irDist.h"
IRDist::IRDist()
{
    dist = -1;
}
void IRDist::begin(byte _pin, irDistConsts _consts)
{
    pin = _pin;

    dist = -1;
    consts = _consts;
    pinMode(pin, INPUT);
}
void IRDist::run()
{
    int read = analogRead(pin);
    dist = ((float)consts.A / (float)read) + consts.B;
}
float IRDist::getDist()
{
    return dist;
}