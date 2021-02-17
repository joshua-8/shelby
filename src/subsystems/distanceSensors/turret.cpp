#include "turret.h"
Turret::Turret()
{
}
void Turret::begin(HardwareSerial* _serial, byte _servoControlPin, byte _servoPositionPin, float _minAngle, float _maxAngle, int _minPulse, int _maxPulse)
{
    servoControlPin = _servoControlPin;
    servoPositionPin = _servoPositionPin;
    distSerial = _serial;
    minAngle = _minAngle;
    maxAngle = _maxAngle;
    minPulse = _minPulse;
    maxPulse = _maxPulse;
    (*distSerial).begin(turretConstants.baud);
    servo.attach(servoControlPin);
    pinMode(servoPositionPin, INPUT);
}
void Turret::run()
{
    if (readDist()) {
        // readAngle();
    }
}
boolean Turret::readDist()
{
    if (distSerial->available() > 8) {
        if (distSerial->read() == 0x59) {
            distIn[0] = 0x59;
            if (distSerial->read() == 0x59) {
                distIn[1] = 0x59;
                for (int i = 2; i < 9; i++) {
                    distIn[i] = distSerial->read();
                }
                //checksum checking skipped since it wasn't working
                distance = (distIn[2] + (distIn[3] << 8)) / 1000.0; //to meters
                signalStrength = distIn[4] + (distIn[5] << 8);
                return true;
            }
        }
    }
    return false;
}
// void Turret::readAngle()
// {
//     angle = analogRead(servoPositionPin);
// }

float Turret::getDist()
{
    return distance;
}
float Turret::getAngle()
{
    return angle;
}
boolean Turret::setAngle(float set)
{
    if (set > maxAngle || set < minAngle) {
        return false;
    }
    angle = set;
    servo.writeMicroseconds(map(angle, minAngle, maxAngle, minPulse, maxPulse));
    return true;
}