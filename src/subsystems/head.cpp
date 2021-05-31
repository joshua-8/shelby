#include "head.h"
#include "settings/settings.h"
#include "shelbytron_globs.h"
Head::Head()
{
    xpos = 0;
    ypos = 0;
    xposW = 0;
    yposW = 0;
}
void Head::begin()
{
}
void Head::run()
{

    xposW += constrain(xpos - xposW, -headConstants.panSpeed * lastLoopTimeMicros / 1000, headConstants.panSpeed * lastLoopTimeMicros / 1000);
    yposW += constrain(ypos - yposW, -headConstants.tiltSpeed * lastLoopTimeMicros / 1000, headConstants.tiltSpeed * lastLoopTimeMicros / 1000);

    if (serX.attached()) {
        serX.writeMicroseconds(map(xposW, headConstants.leftDeg, headConstants.rightDeg, headConstants.leftRange, headConstants.rightRange));
    }
    if (serY.attached()) {
        serY.writeMicroseconds(map(yposW, headConstants.downDeg, headConstants.upDeg, headConstants.downRange, headConstants.upRange));
    }
}
void Head::setServosEnabled(boolean enabled)
{
    setServoXEnabled(enabled);
    setServoYEnabled(enabled);
}
void Head::setServoXEnabled(boolean enabled)
{
    if (enabled != serX.attached()) {
        if (enabled) {
            serX.attach(HEAD_PAN_SERVO_PIN);
        } else {
            serX.detach();
        }
    }
}
void Head::setServoYEnabled(boolean enabled)
{
    if (enabled != serY.attached()) {
        if (enabled) {
            serY.attach(HEAD_TILT_SERVO_PIN);
        } else {
            serY.detach();
        }
    }
}
boolean Head::isServoXEnabled()
{
    return serX.attached();
}
boolean Head::isServoYEnabled()
{
    return serY.attached();
}
void Head::setPositions(float x, float y)
{
    setPositionX(x);
    setPositionY(y);
}

void Head::setPositionX(float x)
{
    if (serX.attached()) {
        xpos = constrain(x, headConstants.leftDeg, headConstants.rightDeg);
    }
}
void Head::setPositionY(float y)
{
    if (serY.attached()) {
        ypos = constrain(y, headConstants.downDeg, headConstants.upDeg);
    }
}
float Head::getPosX()
{
    return xposW;
}
float Head::getPosY()
{
    return yposW;
}