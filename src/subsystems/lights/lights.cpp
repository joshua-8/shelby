#include "lights.h"
#include "shelbytron_globs.h"
Lights::Lights()
{
}
void Lights::begin()
{
    WheelLightL.begin(true);
    WheelLightR.begin(false);
}
void Lights::run()
{
    WheelLightL.run();
    WheelLightR.run();
    // WheelLightL.allOff(false);
    // WheelLightR.allOff(false);
    // WheelLightL.dropRipple(millis() % 10000 - 3000, 4000, 500, 190, 255, 195, 2, 255 * 2 / 10);
    // WheelLightR.dropRipple(millis() % 10000 - 3000, 4000, 500, 190, 255, 195, 2, 255 * 2 / 10);
    // WheelLightR.lightSector(subsystems.drivetrain.WheelR.getRawPosition(), wheelConstants.ticksPerRevolution, wheelLightConstants.RING_FIRST_INDEX[9], wheelLightConstants.RING_LAST_INDEX[9], 200, 200, 200, 100);
    // WheelLightL.lightSector(subsystems.drivetrain.WheelL.getRawPosition(), wheelConstants.ticksPerRevolution, wheelLightConstants.RING_FIRST_INDEX[9], wheelLightConstants.RING_LAST_INDEX[9], 200, 200, 200, 100);
    // WheelLightL.show();
    // WheelLightR.show();
}