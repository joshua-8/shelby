#include "wheel.h"
#include "shelbytron_globs.h"

Wheel::Wheel()
{
    tickCounter = 0;
    magOrientedTickCounter = 0;
    magTickCounterOffset = 0;
    vel = 0;
    voltOut = 0;
    encForwards = true;
    lastEncoderCycleInterval = 0;
    lastEncoderCycleMicros = 0;
    newSpeed = false;
    velSet = 0;
    velWrite = 0;
    powerAllowed = 15.0;
}
void Wheel::begin(byte _speedPin, byte _dirPin, byte _encoderAPin, byte _encoderBPin, byte _magPin, boolean _revMot, boolean _revEnc, boolean _left)
{
    speedPin = _speedPin;
    dirPin = _dirPin;
    encoderAPin = _encoderAPin;
    encoderBPin = _encoderBPin;
    magPin = _magPin;
    revMot = _revMot;
    revEnc = _revEnc;
    left = _left;
    pinMode(speedPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    analogWriteFrequency(speedPin, 20000);
    pinMode(encoderAPin, INPUT);
    pinMode(encoderBPin, INPUT);
    pinMode(magPin, INPUT);

    if (left) {
        magPosOffset = wheelConstants.leftMagPos;
        attachInterrupt(encoderAPin, LAWheelISR, CHANGE);
        attachInterrupt(encoderBPin, LBWheelISR, CHANGE);
    } else { //right
        magPosOffset = wheelConstants.rightMagPos;
        attachInterrupt(encoderAPin, RAWheelISR, CHANGE);
        attachInterrupt(encoderBPin, RBWheelISR, CHANGE);
    }
}
void Wheel::run()
{
    // magOrientedTickCounter = (((tickCounter) % wheelConstants.ticksPerRevolution) + wheelConstants.ticksPerRevolution) % wheelConstants.ticksPerRevolution;
    velWrite += constrain(velSet - velWrite, -topSettings.wheelAccel * lastLoopTimeMicros / 1000000, topSettings.wheelAccel * lastLoopTimeMicros / 1000000);
    vel = getVel();
    if (go) {
        if (newSpeedData() || vel == 0) {
            voltOut = calculateControlLoop(velWrite);
            setVolt(voltOut);
        }
    } else { //stop=disable motors
        setOutput(0);
        velWrite = 0;
        velSet = 0;
    }
}

float Wheel::calculateControlLoop(float vel)
{
    float FF;
    if (left)
        FF = topSettings.leftWheelFF;
    else
        FF = topSettings.rightWheelFF;

    float volt = 0;
    volt += vel * FF;
    return volt;
}

float Wheel::getVelocity()
{
    return vel;
}

float Wheel::getVel()
{
    if (lastEncoderCycleInterval == 0) {
        return 0;
    }
    if (micros() - lastEncoderCycleMicros > wheelConstants.maxSpeedCalcInterval) {
        return 0;
    }
    if (encForwards) {
        return 1000000.0 / lastEncoderCycleInterval / wheelConstants.ticksPerMeter;
    } else {
        return -1000000.0 / lastEncoderCycleInterval / wheelConstants.ticksPerMeter;
    }
}
void Wheel::setVel(float vel)
{
    velSet = vel;
}
void Wheel::setVolt(float volt)
{
    float output = constrain(volt / (subsystems.batMonitor.getBatVolt() + .001), -powerAllowed, powerAllowed);
    setOutput(output);
}

void Wheel::setOutput(float val)
{
    int output = constrain(val * 255, -255, 255);
    if (!go) {
        output = 0;
    }
    if (output > 0) {
        digitalWrite(dirPin, revMot);
        analogWrite(speedPin, output);
    } else if (output < 0) {
        digitalWrite(dirPin, !revMot);
        analogWrite(speedPin, -output);
    } else {
        analogWrite(speedPin, 0);
    }
}

int Wheel::getMagCalibratedPos()
{
    return magOrientedTickCounter;
}
float Wheel::getPosition()
{
    return (float)tickCounter / wheelConstants.ticksPerMeter;
}
long Wheel::getRawPosition()
{
    return tickCounter;
}
void Wheel::resetPosition()
{
    tickCounter = 0;
}
void Wheel::setVoltageAllowed(float _v)
{
    powerAllowed = _v;
}

boolean Wheel::newSpeedData()
{
    if (!newSpeed) {
        return false;
    }
    newSpeed = false;
    return true;
}

void Wheel::ISRchA()
{

    if (digitalRead(encoderAPin) == digitalRead(encoderBPin)) {
        encForwards = revEnc;
    } else {
        encForwards = !revEnc;
    }
    if (digitalRead(encoderAPin) == LOW) { //full cycle of encoder, arbitrarily put when pin A goes low
        lastEncoderCycleInterval = micros() - lastEncoderCycleMicros;
        lastEncoderCycleMicros = micros();
        newSpeed = true;
        if (encForwards) {
            tickCounter++;
        } else {
            tickCounter--;
        }
    }
}
void Wheel::ISRchB()
{
    if (digitalRead(encoderAPin) != digitalRead(encoderBPin)) {
        encForwards = revEnc;
    } else {
        encForwards = !revEnc;
    }
}

//ISRs can't be inside a class, so here's a workaround
void LAWheelISR()
{
    subsystems.drivetrain.WheelL.ISRchA();
}
void LBWheelISR()
{
    subsystems.drivetrain.WheelL.ISRchB();
}

void RAWheelISR()
{
    subsystems.drivetrain.WheelR.ISRchA();
}
void RBWheelISR()
{
    subsystems.drivetrain.WheelR.ISRchB();
}
