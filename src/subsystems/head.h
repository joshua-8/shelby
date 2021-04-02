#ifndef HEAD_H
#define HEAD_H
#include "constants/headConstants.h"
#include "constants/pinout.h"
#include <Arduino.h>
#include <Servo.h>
class Head {
public:
    Head();
    void begin();
    void run();
    void setServosEnabled(boolean enabled);
    void setServoXEnabled(boolean enabled);
    void setServoYEnabled(boolean enabled);
    boolean isServoXEnabled();
    boolean isServoYEnabled();
    void setPositions(float x, float y);
    void setPositionX(float x);
    void setPositionY(float y);
    float getPosX();
    float getPosY();

private:
    Servo serX;
    Servo serY;
    float xpos;
    float ypos;
    float xposW;
    float yposW;
};

#endif