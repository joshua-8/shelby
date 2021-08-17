#ifndef ROBOT_LIGHTS_H
#define ROBOT_LIGHTS_H
#include "Arduino.h"
#include "shelbytron_globs.h"
#include "subsystems/!subsystems.h"
class RobotLights {
public:
    bool wasStopped;
    bool stopped;
    RobotLights()
    {
        stopped = true;
        wasStopped = false;
    }
    void genLights()
    {
        wasStopped = stopped;
        stopped = (!go || (subsystems.drivebase.leftMotorController.getDriverSetVal() == 0 && subsystems.drivebase.rightMotorController.getDriverSetVal() == 0));

        if (genS.lightsMode == 0 && (genS.lightsMode != premodeLastGenS.lightsMode || (stopped && !wasStopped))) {
            subsystems.lights.WheelLightL.allOff(true);
            subsystems.lights.WheelLightR.allOff(true);
        }
        if (genS.lightsMode > 0 && stopped) {
            subsystems.lights.WheelLightL.allOff(false);
            subsystems.lights.WheelLightR.allOff(false);
            if (genS.lightsMode == 2) {
                subsystems.lights.WheelLightL.dropRipple(millis() % 5000 - 500, 4000, 500, millis() / 100, 255, 195, 2, 255 * 2 / 10);
                subsystems.lights.WheelLightR.dropRipple(millis() % 5000 - 500, 4000, 500, millis() / 100, 255, 195, 2, 255 * 2 / 10);
            } else {
                subsystems.lights.WheelLightR.lightRingSet(3, CHSV(millis() / 100, 255, 100));
                subsystems.lights.WheelLightR.lightRingSet(6, CHSV(millis() / 100, 255, 100));
                subsystems.lights.WheelLightL.lightRingSet(3, CHSV(millis() / 100, 255, 100));
                subsystems.lights.WheelLightL.lightRingSet(6, CHSV(millis() / 100, 255, 100));
            }
            subsystems.lights.WheelLightL.show();
            subsystems.lights.WheelLightR.show();
        }
    }
};
#endif