#include "moveHall.h"
#include "robot/robot.h"
/*
*  point is invalid if delta is above a threshold (or range 0), average delta if both valid
*  save angle and valid distance
*  add arctan scaled for distance to average
*/
MoveHall::MoveHall()
{
    hallTargetHeading = 0;
    hallWidth = 0;
    hallError = 0;
    targetRobotHeadingHall = 0;
    targetRobotHeading = 0;
    processedTargetRobotHeading = 0;
    hallHeading = 0;
    hallHeadingProcessed = 0;
    robotHeading = 0;
    leftTurretAngle = -90;
    rightTurretAngle = 90;
    leftDist = 0;
    rightDist = 0;
    lastLeftDist = 0;
    lastRightDist = 0;
    leftDelta = 0;
    rightDelta = 0;
    delta = 0;
    goodReadingDist = 0;
    leftValid = false;
    rightValid = false;
    lastDriveDist = 0;
    driveDeltaDist = 0;
    instantAngle = 0;
}
void MoveHall::begin()
{
    robot.moveHeading.resetZero();

    hallTargetHeading = 0;
    hallWidth = 0;
    hallError = 0;
    targetRobotHeadingHall = 0;
    targetRobotHeading = 0;
    processedTargetRobotHeading = 0;
    hallHeading = 0;
    hallHeadingProcessed = 0;
    robotHeading = 0;
    leftTurretAngle = -90;
    rightTurretAngle = 90;
    leftDist = 0;
    rightDist = 0;
    lastLeftDist = 0;
    lastRightDist = 0;
    leftDelta = 0;
    rightDelta = 0;
    delta = 0;
    goodReadingDist = 0;
    leftValid = false;
    rightValid = false;
    lastDriveDist = 0;
    driveDeltaDist = 0;
    instantAngle = 0;
}
void MoveHall::run(float speed, boolean safe)
{

    hallWidth = rightDist + leftDist;
    //left of center=positive, right of center=negative
    hallError = rightDist - .4; //leftDist;

    robotHeading = subsystems.drivetrain.getRotation();

    //P (I? D?) controller
    targetRobotHeadingHall = topSettings.mHallPterm * hallError * (speed >= 0 ? 1.0 : -1.0);
    //add hallHeading, limit range of heading.
    targetRobotHeading = constrain(targetRobotHeadingHall, -topSettings.mHallHeadRng, topSettings.mHallHeadRng);
    //smooth targetRobotHeading
    processedTargetRobotHeading += constrain(targetRobotHeading - processedTargetRobotHeading, -topSettings.mHallHeadAdj * lastLoopTimeMicros / 1000000.0, topSettings.mHallHeadAdj * lastLoopTimeMicros / 1000000.0);

    /////////////////hall Heading calculation
    if (abs(subsystems.drivetrain.getDist()) - abs(lastDriveDist) > topSettings.mHallDinc) {

        leftDist = subsystems.distanceSensors.LTurret.getDist();
        rightDist = subsystems.distanceSensors.RTurret.getDist();
        leftDelta = -(leftDist - lastLeftDist);
        rightDelta = (rightDist - lastRightDist);

        driveDeltaDist = subsystems.drivetrain.getDist() - lastDriveDist;

        leftValid = abs(leftDelta) <= topSettings.mHallThresh && leftDist != 0 && leftDist < 3;
        rightValid = abs(rightDelta) <= topSettings.mHallThresh && rightDist != 0 && rightDist < 3;
        if (leftValid || rightValid) {
            if (leftValid && rightValid) {
                delta = (leftDelta + rightDelta) / 2.0;
            }
            if (leftValid && !rightValid) {
                delta = leftDelta;
            }
            if (!leftValid && rightValid) {
                delta = rightDelta;
            }

            instantAngle = RAD_TO_DEG * atan(delta / driveDeltaDist);
            goodReadingDist += abs(driveDeltaDist);

            hallHeading -= robotHeading;
            hallHeading += (instantAngle - hallHeading) * abs(driveDeltaDist) / (goodReadingDist + .1);
            hallHeading += robotHeading;
        }

        lastDriveDist = subsystems.drivetrain.getDist();
        lastLeftDist = leftDist;
        lastRightDist = rightDist;

        Serial.print(subsystems.distanceSensors.FDist.getValid() ? subsystems.distanceSensors.FDist.getDist() : INFINITY);
        Serial.print(",");
        Serial.print(leftDist, 3);
        Serial.print(",");
        Serial.print(rightDist, 3);
        Serial.print(",");
        Serial.print(leftDelta, 3);
        Serial.print(",");
        Serial.print(rightDelta, 3);
        Serial.print(",");
        Serial.print(delta, 3);
        Serial.print(",");
        Serial.print(instantAngle);
        Serial.print(",");
        Serial.println(hallHeading);
    }
    hallHeadingProcessed += constrain(hallHeading - hallHeadingProcessed, -topSettings.mHallHallAdj * lastLoopTimeMicros / 1000000.0, topSettings.mHallHallAdj * lastLoopTimeMicros / 1000000.0);

    robot.moveHeading.driveHeading(processedTargetRobotHeading + hallHeadingProcessed, speed, safe);

    leftTurretAngle = -90; // - robotHeading + hallHeading;
    rightTurretAngle = 90; // - robotHeading + hallHeading;
    subsystems.distanceSensors.LTurret.setAngle(leftTurretAngle);
    subsystems.distanceSensors.RTurret.setAngle(rightTurretAngle);
}
float MoveHall::getHallHeading()
{
    return hallHeadingProcessed;
}