#include "moveHall.h"
#include "robot/robot.h"
MoveHall::MoveHall()
{
    hallWidth = 0;
    hallError = 0;
    processedHallError = 0;
    targetRobotHeadingHall = 0;
    targetRobotHeading = 0;
    processedTargetRobotHeading = 0;
    hallHeading = 0;
    robotHeading = 0;
    leftTurretAngle = -90;
    rightTurretAngle = 90;
}
void MoveHall::begin()
{
    robot.moveHeading.resetZero();
    hallWidth = 0;
    hallError = 0;
    processedHallError = 0;
    targetRobotHeadingHall = 0;
    targetRobotHeading = 0;
    processedTargetRobotHeading = 0;
    hallHeading = 0;
    robotHeading = 0;
    leftTurretAngle = -90;
    rightTurretAngle = 90;
}
void MoveHall::run(float speed, boolean safe)
{
    hallWidth = subsystems.distanceSensors.RTurret.getDist() + subsystems.distanceSensors.LTurret.getDist();
    //left of center=positive, right of center=negative
    hallError = subsystems.distanceSensors.RTurret.getDist() - subsystems.distanceSensors.LTurret.getDist();
    robotHeading = subsystems.drivetrain.getRotation();
    //smooth error? detect doorways?
    processedHallError = hallError;
    //P (I? D?) controller
    targetRobotHeadingHall = topSettings.mHallPterm * processedHallError * (speed >= 0 ? 1.0 : -1.0);
    //add hallHeading, limit range of heading.
    targetRobotHeading = constrain(targetRobotHeadingHall, -topSettings.mHallHeadRng, topSettings.mHallHeadRng) + hallHeading;
    //smooth targetRobotHeading
    processedTargetRobotHeading += constrain(targetRobotHeading - processedTargetRobotHeading, -topSettings.mHallHeadAdj * lastLoopTimeMicros / 1000000.0, topSettings.mHallHeadAdj * lastLoopTimeMicros / 1000000.0);
    //hallHeading approach processedTargetRobotHeading
    hallHeading += (processedTargetRobotHeading - hallHeading) * lastLoopTimeMicros / 1000000.0 * topSettings.mHallHallAdj;

    robot.moveHeading.driveHeading(processedTargetRobotHeading, speed, safe);

    leftTurretAngle = -90 - robotHeading + hallHeading;
    rightTurretAngle = 90 - robotHeading + hallHeading;
    subsystems.distanceSensors.LTurret.setAngle(leftTurretAngle);
    subsystems.distanceSensors.RTurret.setAngle(rightTurretAngle);
}