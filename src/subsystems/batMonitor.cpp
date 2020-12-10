#include "batMonitor.h"

BatMonitor::BatMonitor()
{
    voltage = 0;
}

void BatMonitor::begin()
{
    pinMode(BAT_MONITOR_PIN, INPUT);
    run();
}
void BatMonitor::run()
{
    voltage = analogRead(BAT_MONITOR_PIN) * batMonitorConstants.voltsPerDAC;
}
float BatMonitor::getBatVolt()
{
    return voltage;
}