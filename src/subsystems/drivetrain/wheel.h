#ifndef WHEEL_H
#define WHEEL_H
#include <Arduino.h>
class Wheel {
public:
    void begin();
    void run();
    Wheel(byte _speedPin,byte _dirPin,byte _encoderAPin, byte _encoderBPin);
};
#endif