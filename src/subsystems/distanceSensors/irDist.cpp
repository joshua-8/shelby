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
    dist = (((float)consts.A / (float)analogRead(pin)) + consts.B) * consts.smooth + dist * (1 - consts.smooth);
}
boolean IRDist::getValid()
{
    return (dist < consts.max);
}
float IRDist::getDist()
{
    return dist;
}