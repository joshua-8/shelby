#include "RingBuf.h"
#include <Arduino.h>
#ifndef SENSE_WALL_DERIV_H
#define SENSE_WALL_DERIV_H
class SenseWallDeriv {
private:
    float angle = 0;
    float distInterval = 0.10;

    boolean reverse;

    float lastWheel = 0;
    float lastWall = 0;
    boolean first;
    boolean newData;

public:
    SenseWallDeriv(boolean _reverse);
    RingBuf<float, 5> buffer;

    void begin(float _distInterval);
    void addData(float wall, float wheel);
    float getAngle();
    boolean isDataNew();
};
#endif
