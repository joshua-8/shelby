#include "drivetrain.h"
Drivetrain::Drivetrain()
{
}
void Drivetrain::begin()
{
    WheelL.begin(LEFT_WHEEL_SPEED_PIN, LEFT_WHEEL_DIR_PIN, LEFT_WHEEL_ENCODER_CHA_PIN, LEFT_WHEEL_ENCODER_CHB_PIN, LEFT_WHEEL_MAG_SENSOR_PIN, true, true, true);
    WheelR.begin(RIGHT_WHEEL_SPEED_PIN, RIGHT_WHEEL_DIR_PIN, RIGHT_WHEEL_ENCODER_CHA_PIN, RIGHT_WHEEL_ENCODER_CHB_PIN, RIGHT_WHEEL_MAG_SENSOR_PIN, false, false, false);
}
void Drivetrain::run()
{
    WheelL.run();
    WheelR.run();
}