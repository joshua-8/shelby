#include "turret.h"
Turret::Turret()
{
}
void Turret::begin(HardwareSerial* _serial, byte _servoControlPin, byte _servoPositionPin, float _minAngle, float _maxAngle, int _minPulse, int _maxPulse)
{
    servoPositionPin = _servoPositionPin;
    distSerial = _serial;

    (*distSerial).begin(turretConstants.baud);
    servoDriver = new JMotorDriverAvrServo(_servoControlPin);
    servo = new JServoController(*servoDriver, true, 180, INFINITY, 1000, _minAngle, _maxAngle, (_minAngle + _maxAngle) / 2.0, _minAngle, _maxAngle, _minPulse, _maxPulse);
    servo->enable();
    pinMode(servoPositionPin, INPUT);
}
void Turret::run()
{
    if (readDist()) {
        // readAngle();
    }
    // if (servo)
    servo->run();
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
void Turret::setAngle(float set)
{
    if (servo)
        servo->setAngleSmoothed(set);
}