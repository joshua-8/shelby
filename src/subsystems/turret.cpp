#include "turret.h"
Turret::Turret()
{
}
void Turret::begin(HardwareSerial* _serial, byte _servoControlPin, byte _servoPositionPin)
{
    servoControlPin = _servoControlPin;
    servoPositionPin = _servoPositionPin;
    distSerial = _serial;
    (*distSerial).begin(turretConstants.baud);
    servo.attach(servoControlPin);
    pinMode(servoPositionPin, INPUT);
}
void Turret::run()
{
    if (readDist()) {
        readAngle();
    }
    int interval = 3000;
    if (millis() % interval < interval / 2) {
        //    myservo1.write(140);
        servo.write(map(millis() % interval, 0, interval / 2, 0, 180));
    } else {
        //    myservo1.write(50);
        servo.write(map(millis() % interval, interval / 2, interval, 180, 0));
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
void Turret::readAngle()
{
    angle = analogRead(servoPositionPin);
}

float Turret::getDist()
{
    return distance;
}
float Turret::getAngle()
{
    return angle;
}