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
    hallTargetHeading = 0;
    processedHallError = 0;
    targetRobotHeadingHall = 0;
    targetRobotHeading = 0;
    processedTargetRobotHeading = 0;
    hallHeading = 0;
    robotHeading = 0;
    leftTurretAngle = -90;
    rightTurretAngle = 90;
    robot.leftWallDerivSensor.begin(.07);
    robot.rightWallDerivSensor.begin(.07);
}
void MoveHall::run(float speed, boolean safe)
{
    robot.leftWallDerivSensor.addData(subsystems.distanceSensors.LTurret.getDist(), subsystems.drivetrain.getDist());
    robot.rightWallDerivSensor.addData(subsystems.distanceSensors.RTurret.getDist(), subsystems.drivetrain.getDist());

    if (robot.leftWallDerivSensor.isDataNew()) { // both hall deriv sensors should update at the same time
        boolean leftGood = abs(robot.leftWallDerivSensor.getAngle() - hallHeading) < topSettings.mHallThresh;
        boolean rightGood = abs(robot.rightWallDerivSensor.getAngle() - hallHeading) < topSettings.mHallThresh;
        if (leftGood && rightGood) {
            hallTargetHeading = (robot.leftWallDerivSensor.getAngle() + robot.rightWallDerivSensor.getAngle()) / 2;
        }
        if (leftGood && !rightGood) {
            hallTargetHeading = robot.leftWallDerivSensor.getAngle();
        }
        if (!leftGood && rightGood) {
            hallTargetHeading = robot.rightWallDerivSensor.getAngle();
        }
        if (!leftGood && !rightGood && abs(robot.leftWallDerivSensor.getAngle() - robot.rightWallDerivSensor.getAngle()) < topSettings.mHallThresh) {
            hallTargetHeading = (robot.leftWallDerivSensor.getAngle() + robot.rightWallDerivSensor.getAngle()) / 2;
        }
        Serial.print("lWAng: ");
        Serial.print(robot.leftWallDerivSensor.getAngle());
        Serial.print(", ");
        Serial.print("rWAng: ");
        Serial.print(robot.rightWallDerivSensor.getAngle());
        Serial.print(", ");
        Serial.print("ldist: ");
        Serial.print(subsystems.distanceSensors.LTurret.getDist());
        Serial.print(", ");
        Serial.print("rdist: ");
        Serial.print(subsystems.distanceSensors.RTurret.getDist());
        Serial.print(", ");
        Serial.print("lgood: ");
        Serial.print(abs(robot.leftWallDerivSensor.getAngle() - hallHeading) < topSettings.mHallThresh);
        Serial.print(", ");
        Serial.print("rgood: ");
        Serial.print(abs(robot.rightWallDerivSensor.getAngle() - hallHeading) < topSettings.mHallThresh);
        Serial.print(", ");
        Serial.print("agree: ");
        Serial.print(abs(robot.leftWallDerivSensor.getAngle() - robot.rightWallDerivSensor.getAngle()) < topSettings.mHallThresh);
        Serial.print(", ");
    }
    hallHeading += constrain(hallTargetHeading - hallHeading, -topSettings.mHallHallAdj * lastLoopTimeMicros / 1000000.0, topSettings.mHallHallAdj * lastLoopTimeMicros / 1000000.0);

    hallWidth = subsystems.distanceSensors.RTurret.getDist() + subsystems.distanceSensors.LTurret.getDist();
    //left of center=positive, right of center=negative
    hallError = subsystems.distanceSensors.RTurret.getDist() - subsystems.distanceSensors.LTurret.getDist();
    robotHeading = subsystems.drivetrain.getRotation();
    //smooth error? detect doorways?
    processedHallError = hallError;
    //P (I? D?) controller
    targetRobotHeadingHall = topSettings.mHallPterm * processedHallError * (speed >= 0 ? 1.0 : -1.0);
    //add hallHeading, limit range of heading.
    targetRobotHeading = constrain(targetRobotHeadingHall, -topSettings.mHallHeadRng, topSettings.mHallHeadRng);
    //smooth targetRobotHeading
    processedTargetRobotHeading += constrain(targetRobotHeading - processedTargetRobotHeading, -topSettings.mHallHeadAdj * lastLoopTimeMicros / 1000000.0, topSettings.mHallHeadAdj * lastLoopTimeMicros / 1000000.0);

    robot.moveHeading.driveHeading(processedTargetRobotHeading + hallHeading, speed, safe);

    leftTurretAngle = -90; // - robotHeading + hallHeading;
    rightTurretAngle = 90; // - robotHeading + hallHeading;
    subsystems.distanceSensors.LTurret.setAngle(leftTurretAngle);
    subsystems.distanceSensors.RTurret.setAngle(rightTurretAngle);
    if (robot.leftWallDerivSensor.isDataNew()) {
        Serial.print("hallTarg: ");
        Serial.print(hallTargetHeading);
        Serial.print(", ");
        Serial.print("hallHead: ");
        Serial.print(hallHeading);
        Serial.print(", ");
        Serial.print("drvHead: ");
        Serial.print(processedTargetRobotHeading + hallHeading);
        Serial.print(", ");
        Serial.print("dist: ");
        Serial.print(subsystems.drivetrain.getDist());
        Serial.print(", ");
        Serial.print("rotation: ");
        Serial.print(subsystems.drivetrain.getRotation());
        Serial.println();
    }
}