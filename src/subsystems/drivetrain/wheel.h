#ifndef WHEEL_H
#define WHEEL_H
#include "constants/wheelConstants.h"
#include <Arduino.h>
void LAWheelISR();
void LBWheelISR();
void RAWheelISR();
void RBWheelISR();
class Wheel {
public:
    Wheel();
    void begin(byte _speedPin, byte _dirPin, byte _encoderAPin, byte _encoderBPin, byte _magPin, boolean _revMot, boolean _revEnc, boolean _left);
    void run();
    void ISRchA();
    void ISRchB();

    float getVelocity();
    void setVel(float vel);
    void setVolt(float volt);
    void setOutput(float val);
    int getMagCalibratedPos();
    float getPosition();
    long getRawPosition();
    void resetPosition();
    void setVoltageAllowed(float _v);

private:
    float getVel();
    boolean newSpeedData();
    float calculateControlLoop(float vel);

    byte speedPin;
    byte dirPin;
    byte encoderAPin;
    byte encoderBPin;
    byte magPin;
    boolean revMot;
    boolean revEnc;
    int magPosOffset;
    boolean left;

    volatile long tickCounter;
    int magOrientedTickCounter;
    int magTickCounterOffset;
    float vel;
    float voltOut;
    volatile boolean encForwards;
    volatile unsigned long lastEncoderCycleInterval;
    volatile unsigned long lastEncoderCycleMicros;
    boolean newSpeed;
    float velSet;
    float velWrite;
    float powerAllowed;
};
#endif
