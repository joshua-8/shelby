#include "moveHeading.h"
#include "robot/robot.h"
MoveHeading::MoveHeading()
{
}
void MoveHeading::driveHeading(float heading, float speed, boolean safe)
{
    float error = heading - subsystems.drivetrain.getDist().rz;
    float output = error * topSettings.mHeadPterm;
    output = constrain(output, -topSettings.mHeadMxRtErr, topSettings.mHeadMxRtErr);
    if (safe) {
        robot.moveSafe.setVelsSafe(speed, output);
    } else {
        subsystems.drivetrain.moveVel({ speed, output, 0 });
    }
}
void MoveHeading::resetZero()
{
    subsystems.drivetrain.resetDist();
}