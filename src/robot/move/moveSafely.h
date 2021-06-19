#ifndef MOVE_SAFELY_H
#define MOVE_SAFELY_H
#include "shelbytron_globs.h"
class MoveSafe {
public:
    boolean setVelsSafe(float forward, float rotation)
    {
        if (forward > 0) {
            if (subsystems.distanceSensors.FDist.getValid()) { //obstacle
                subsystems.drivetrain.moveVel({ 0, 0, 0 });

                return false;
            } else {
                subsystems.drivetrain.moveVel({ forward, rotation, 0 });
                return true;
            }
        }
        if (forward < 0) {
            if (subsystems.distanceSensors.BDist.getValid()) { //obstacle
                subsystems.drivetrain.moveVel({ 0, 0, 0 });
                return false;
            } else {
                subsystems.drivetrain.moveVel({ forward, rotation, 0 });
                return true;
            }
        }
        subsystems.drivetrain.moveVel({ 0, rotation, 0 });
        return true;
    }
};

#endif