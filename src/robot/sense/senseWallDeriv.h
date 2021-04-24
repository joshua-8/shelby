#include "RingBuf.h"
#include <Arduino.h>
#ifndef SENSE_WALL_DERIV_H
#define SENSE_WALL_DERIV_H
class SenseWallDeriv {
private:
    float distInterval = 0.20;

    float lastWheel = 0;
    float lastWall = 0;
    boolean first;
    boolean newData;

public:
    SenseWallDeriv();
    RingBuf<float, 20> buffer;

    void begin();
    void addData(float wall, float wheel);
    float getAngle();
    boolean isDataNew();
};
#endif
