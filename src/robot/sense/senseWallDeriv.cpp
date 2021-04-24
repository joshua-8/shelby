#include "senseWallDeriv.h"
SenseWallDeriv::SenseWallDeriv()
{
}
void SenseWallDeriv::begin()
{
    lastWheel = 0;
    first = true;
    buffer.clear();
}
void SenseWallDeriv::addData(float wall, float wheel)
{
    if (first) {
        lastWall = wall;
        first = false;
    }
    newData = false;
    if (abs(wheel) - lastWheel > distInterval / buffer.maxSize()) {
        lastWheel = abs(wheel);
        buffer.push(wall - lastWall);
        lastWall = wall;
        newData = true;
    }
}
float SenseWallDeriv::getAngle()
{
    float sumDif = 0;
    for (int i = 0; i < buffer.size(); i++) {
        sumDif += buffer[i];
    }
    sumDif /= buffer.size();
    return RAD_TO_DEG * atan(sumDif / distInterval);
}
boolean SenseWallDeriv::isDataNew()
{
    return newData;
}
