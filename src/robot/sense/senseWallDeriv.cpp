#include "senseWallDeriv.h"
SenseWallDeriv::SenseWallDeriv(boolean _reverse)
{
    reverse = _reverse;
    angle = 0;
    lastWheel = 0;
}
void SenseWallDeriv::begin(float _distInterval)
{
    distInterval = _distInterval;
    lastWheel = 0;
    first = true;
    buffer.clear();
}
void SenseWallDeriv::addData(float wall, float wheel)
{
    newData = false;
    if (first) {
        lastWall = wall;
        first = false;
    }
    if (abs(wheel - lastWheel) > distInterval / buffer.maxSize()) {
        // if (buffer.isFull()) {
        float sumDif = 0;
        for (int i = 0; i < buffer.size(); i++) {
            sumDif += buffer[i];
        }
        angle = RAD_TO_DEG * atan(sumDif / distInterval);
        if (wheel < lastWheel) {
            angle *= -1;
        }
        if (reverse) {
            angle *= -1;
        }
        // buffer.clear();
        newData = true;
        // }
        if (buffer.isFull()) {
            float deleted;
            buffer.pop(deleted);
        }
        lastWheel = wheel;
        buffer.push(wall - lastWall);
        lastWall = wall;
    }
}
float SenseWallDeriv::getAngle()
{
    return angle;
}
boolean SenseWallDeriv::isDataNew()
{
    return newData;
}
