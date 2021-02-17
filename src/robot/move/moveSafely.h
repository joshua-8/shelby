#ifndef MOVE_SAFELY_H
#define MOVE_SAFELY_H
#include "shelbytron_globs.h"
class MoveSafe {
public:
    boolean setVelsSafe(float forward, float rotation)
    {
        if (forward > 0) {
            if (subsystems.distanceSensors.FDist.getValid()) { //obstacle
                subsystems.drivetrain.setVels(0, 0);
                return false;
            } else {
                subsystems.drivetrain.setVels(forward, rotation);
                return true;
            }
        }
        if (forward < 0) {
            if (subsystems.distanceSensors.BDist.getValid()) { //obstacle
                subsystems.drivetrain.setVels(0, 0);
                return false;
            } else {
                subsystems.drivetrain.setVels(forward, rotation);
                return true;
            }
        }
        subsystems.drivetrain.setVels(0, rotation);
        return true;
    }
    boolean setVelTurnRadSafe(float forward, float radius)
    {
        if (forward > 0) {
            if (subsystems.distanceSensors.FDist.getValid()) { //obstacle
                subsystems.drivetrain.setVels(0, 0);
                return false;
            } else {
                subsystems.drivetrain.setVels(forward, radius);
                return true;
            }
        }
        if (forward < 0) {
            if (subsystems.distanceSensors.BDist.getValid()) { //obstacle
                subsystems.drivetrain.setVels(0, 0);
                return false;
            } else {
                subsystems.drivetrain.setVels(forward, radius);
                return true;
            }
        }
    }
};

#endif