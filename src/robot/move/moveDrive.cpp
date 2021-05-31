#include "moveDrive.h"
#include "robot/robot.h"
/**
 * @brief  drive specific distance and rotation in set time (obstacle detection safe mode option available)
 */
MoveDrive::MoveDrive()
{
    navigating = false;
    navTime = 0;
    targetDist = 0;
    targetTurn = 0;
    safe = false;
    doneMoving = false;
    doneTurning = false;
    startAngle = 0;
    startDist = 0;
}
void MoveDrive::run()
{
    if (navigating) {
        if (navigate()) {
            navigating = false;
        }
    }
}
void MoveDrive::setDriveTarget(float distance, float rotation, unsigned long timeMillis, boolean _safe, bool reset)
{
    if (reset) {
        subsystems.drivetrain.WheelL.resetPosition();
        subsystems.drivetrain.WheelR.resetPosition();
    }

    if (timeMillis > 0) { //protect against divide by zero
        navTime = timeMillis;
        navigating = true;
        startDist = subsystems.drivetrain.getDist();
        startAngle = subsystems.drivetrain.getRotation();
        targetDist = distance - startDist;
        targetTurn = rotation - startAngle;
        safe = _safe;
        doneMoving = false;
        doneTurning = false;
    }
}

boolean MoveDrive::navigate()
{
    doneMoving = doneMoving || (targetDist == 0) || (abs(subsystems.drivetrain.getDist() - startDist) > abs(targetDist));
    doneTurning = doneTurning || (targetTurn == 0) || (abs(subsystems.drivetrain.getRotation() - startAngle) > abs(targetTurn));

    if (safe) {
        robot.moveSafe.setVelsSafe(doneMoving ? 0 : (targetDist / (navTime / 1000)), doneTurning ? 0 : (targetTurn / (navTime / 1000)));
    } else {
        subsystems.drivetrain.setVels(doneMoving ? 0 : (targetDist / (navTime / 1000)), doneTurning ? 0 : (targetTurn / (navTime / 1000)));
    }
    if (doneMoving && doneTurning) {
        subsystems.drivetrain.setVels(0, 0);
        return true;
    }
    return false;
}
boolean MoveDrive::isNavigating()
{
    return navigating;
}
boolean MoveDrive::stopNavigating()
{
    if (navigating) {
        navigating = false;
        return true;
    }
    return false;
}