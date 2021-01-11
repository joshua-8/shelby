#include "batMonitor.h"
#include "shelbytron_globs.h"

BatMonitor::BatMonitor()
{
    voltage = 0;
    rawVoltage = 0;
}

void BatMonitor::begin()
{
    pinMode(BAT_MONITOR_PIN, INPUT);
    voltage = readRawVoltage();
    run();
}
void BatMonitor::run()
{
    rawVoltage = readRawVoltage();
    float d = constrain(lastLoopTimeMicros * batMonitorConstants.smoothingParameter / 1000000.0, 0, .5);
    voltage = d * rawVoltage + (1 - d) * voltage;
}
float BatMonitor::getBatVolt()
{
    return voltage;
}
float BatMonitor::readRawVoltage()
{
    return analogRead(BAT_MONITOR_PIN) * batMonitorConstants.voltsPerDAC;
}