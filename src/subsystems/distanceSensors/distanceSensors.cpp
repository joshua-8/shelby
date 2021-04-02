#include "distanceSensors.h"
String inString = "";
DistanceSensors::DistanceSensors()
{
}
void DistanceSensors::begin()
{
    beginAll();
}
void DistanceSensors::run()
{
    runAll();
}
void DistanceSensors::runAll()
{
    RDist.run();
    FDist.run();
    LDist.run();
    BDist.run();
    LTurret.run();
    RTurret.run();
}
void DistanceSensors::beginAll()
{
    RDist.begin(RIGHT_DIST_PIN, irDistConstants[0]);
    FDist.begin(FRONT_DIST_PIN, irDistConstants[1]);
    LDist.begin(LEFT_DIST_PIN, irDistConstants[2]);
    BDist.begin(BACK_DIST_PIN, irDistConstants[3]);
    LTurret.begin(&LEFT_TOF_SERIAL_PORT, LEFT_TOF_SERVO_CONTROL_PIN, LEFT_TOF_SERVO_POSITION_PIN, turretConstants.minAngle[turretConstants.left], turretConstants.maxAngle[turretConstants.left], turretConstants.minPulse[turretConstants.left], turretConstants.maxPulse[turretConstants.left]);
    RTurret.begin(&RIGHT_TOF_SERIAL_PORT, RIGHT_TOF_SERVO_CONTROL_PIN, RIGHT_TOF_SERVO_POSITION_PIN, turretConstants.minAngle[turretConstants.right], turretConstants.maxAngle[turretConstants.right], turretConstants.minPulse[turretConstants.right], turretConstants.maxPulse[turretConstants.right]);
    LTurret.setAngle(-90);
    RTurret.setAngle(90);
}