#ifndef TURRET_H
#define TURRET_H
#include "constants/turretConstants.h"
#include <Arduino.h>
#include <Servo.h>
class Turret {
public:
    Turret();
    void begin(HardwareSerial* _serial, byte _servoControlPin, byte _servoPositionPin);
    void run();
    float getDist();
    float getAngle();

private:
    HardwareSerial* distSerial;
    boolean readDist();
    int distIn[9]; //save data measured by LiDAR
    float distance;
    int signalStrength;

    void readAngle();
    byte servoControlPin;
    byte servoPositionPin;
    Servo servo;
    float angle;
};
#endif