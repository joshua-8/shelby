#ifndef TURRET_H
#define TURRET_H
#include "constants/turretConstants.h"
#include <Arduino.h>
#include <JMotor.h>
class Turret {
public:
    Turret();
    void begin(HardwareSerial* _serial, byte _servoControlPin, byte _servoPositionPin, float _minAngle, float _maxAngle, int _minPulse, int _maxPulse);
    void run();
    float getDist();
    float getAngle();
    void setAngle(float angle);
    JServoController* servo = NULL;

private:
    HardwareSerial* distSerial;
    boolean readDist();
    int distIn[9]; //save data measured by LiDAR
    float distance;
    int signalStrength;

    // void readAngle();
    float angle;
    byte servoPositionPin;
    JMotorDriverAvrServo* servoDriver = NULL;
};
#endif