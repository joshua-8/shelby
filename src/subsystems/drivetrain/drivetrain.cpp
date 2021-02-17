#include "drivetrain.h"
Drivetrain::Drivetrain()
{
}
void Drivetrain::begin()
{
    WheelL.begin(LEFT_WHEEL_SPEED_PIN, LEFT_WHEEL_DIR_PIN, LEFT_WHEEL_ENCODER_CHA_PIN, LEFT_WHEEL_ENCODER_CHB_PIN, LEFT_WHEEL_MAG_SENSOR_PIN, true, true, true);
    WheelR.begin(RIGHT_WHEEL_SPEED_PIN, RIGHT_WHEEL_DIR_PIN, RIGHT_WHEEL_ENCODER_CHA_PIN, RIGHT_WHEEL_ENCODER_CHB_PIN, RIGHT_WHEEL_MAG_SENSOR_PIN, true, false, false);
}
void Drivetrain::run()
{
    WheelL.run();
    WheelR.run();
}
/**
 * @brief  set linear and rotational velocities of drivetrain
 * @param  forward: forwards velocity (m/s)
 * @param  rotation: rotational velocity (deg/s) +=clockwise
 */
void Drivetrain::setVels(float forward, float rotation)
{
    rotation = rotation * drivetrainConstants.wheelbase / RAD_TO_DEG / 2;
    WheelL.setVel(forward + rotation);
    WheelR.setVel(forward - rotation);
}
/**
 *  turn at rotation rate (deg/s) +=clockwise
 */
void Drivetrain::setVelRot(float rotation)
{
    rotation = rotation * drivetrainConstants.wheelbase / RAD_TO_DEG / 2;
    WheelL.setVel(rotation);
    WheelR.setVel(-rotation);
}
/**
 * @brief  drive more like a car
 * @note   at small turning radiuses think about how fast the wheels may have to turn
 * @param  forward: forwards velocity
 * @param  radius: turning radius +=right
 */
void Drivetrain::setVelTurnRad(float forward, float radius)
{
    setVels(forward, forward / (radius * DEG_TO_RAD));
}