#include "moveHeading.h"
#include "robot/robot.h"
MoveHeading::MoveHeading()
{
}
void MoveHeading::driveHeading(float heading, float speed, boolean safe)
{
    float error = heading - subsystems.drivetrain.getRotation();
    float output = constrain(error, -topSettings.debugA, topSettings.debugA);
    output *= topSettings.debugB;
    if (safe) {
        robot.moveSafe.setVelsSafe(speed, output);
    } else {
        subsystems.drivetrain.setVels(speed, output);
    }
}
void MoveHeading::resetZero()
{
    subsystems.drivetrain.resetWheelCounters();
}