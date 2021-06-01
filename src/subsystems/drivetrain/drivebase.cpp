#include "drivebase.h"
#include "shelbytron_globs.h"

void leftWheelEncoder_jENCODER_ISR_A();
void leftWheelEncoder_jENCODER_ISR_B();
void rightWheelEncoder_jENCODER_ISR_A();
void rightWheelEncoder_jENCODER_ISR_B();
void Drivebase::run()
{
    drivetrain.setEnable(go);
    drivetrain.run();
}
void Drivebase::begin()
{
    leftWheelEncoder.setUpInterrupts(leftWheelEncoder_jENCODER_ISR_A, leftWheelEncoder_jENCODER_ISR_B);
    rightWheelEncoder.setUpInterrupts(rightWheelEncoder_jENCODER_ISR_A, rightWheelEncoder_jENCODER_ISR_B);
}

void leftWheelEncoder_jENCODER_ISR_A()
{
    subsystems.drivebase.leftWheelEncoder.ISRA();
}
void leftWheelEncoder_jENCODER_ISR_B()
{
    subsystems.drivebase.leftWheelEncoder.ISRB();
}
void rightWheelEncoder_jENCODER_ISR_A()
{
    subsystems.drivebase.rightWheelEncoder.ISRA();
}
void rightWheelEncoder_jENCODER_ISR_B()
{
    subsystems.drivebase.rightWheelEncoder.ISRB();
}
