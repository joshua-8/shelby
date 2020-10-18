#include "nineDOFSensor.h"
NineDOFSensor::NineDOFSensor()
{
    systemCal = gyroCal = accelCal = magCal = 0;
    heading = pitch = roll = 0.0;
}
void NineDOFSensor::begin()
{
    Wire2.begin();
    bno055.begin();
    bno055.setExtCrystalUse(true);
    bno055.setMode(bno055.OPERATION_MODE_NDOF);
}
void NineDOFSensor::run()
{
    bno055.getCalibration(&systemCal, &gyroCal, &accelCal, &magCal);
    quat = bno055.getQuat();
    accel = bno055.getVector(bno055.VECTOR_ACCELEROMETER);
    gyro = bno055.getVector(bno055.VECTOR_GYROSCOPE);
    gyro.scale(RAD_TO_DEG);
    eulerOri = quat.toEuler();
    heading = fmod(eulerOri.x() * RAD_TO_DEG - topSettings.magneticDeclination + 360, 360.0);
    pitch = eulerOri.z();
    roll = eulerOri.y();
}