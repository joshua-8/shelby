#include "!subsystems.h"
void Subsystems::begin()
{
    audio.begin();
    batMonitor.begin();
    goButton.begin();
    distanceSensors.begin();
    nineDOFSensor.begin();
    ir.begin();
    //    LTurret.begin(&LEFT_TOF_SERIAL_PORT, LEFT_TOF_SERVO_CONTROL_PIN, LEFT_TOF_SERVO_POSITION_PIN);
    //    RTurret.begin(&RIGHT_TOF_SERIAL_PORT, RIGHT_TOF_SERVO_CONTROL_PIN, RIGHT_TOF_SERVO_POSITION_PIN);
}
void Subsystems::run()
{
    audio.run();
    batMonitor.run();
    goButton.run();
    distanceSensors.run();
    nineDOFSensor.run();
    //    LTurret.run();
    //    Serial.println(LTurret.getDist());
    //    RTurret.run();
    ir.run();
}