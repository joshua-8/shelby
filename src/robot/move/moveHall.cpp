#include "moveHall.h"
#include "robot/robot.h"
MoveHall::MoveHall()
{
}
void MoveHall::begin()
{
}
void MoveHall::run()
{

    leftTurretAngle=-90-robotHeading+hallHeading;
    rightTurretAngle=90-robotHeading+hallHeading;
    subsystems.distanceSensors.LTurret.setAngle(leftTurretAngle);
    subsystems.distanceSensors.RTurret.setAngle(rightTurretAngle);
}