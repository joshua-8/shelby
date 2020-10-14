#include "distanceSensors.h"
DistanceSensors::DistanceSensors()
{
}
void DistanceSensors::begin()
{
    beginAll();
}
void DistanceSensors::run()
{
    runAll();
}
void DistanceSensors::runAll()
{
    RDist.run();
    FDist.run();
    LDist.run();
    BDist.run();
}
void DistanceSensors::beginAll()
{
    RDist.begin(RIGHT_DIST_PIN, irDistConstants[0]);
    FDist.begin(FRONT_DIST_PIN, irDistConstants[1]);
    LDist.begin(LEFT_DIST_PIN, irDistConstants[2]);
    BDist.begin(BACK_DIST_PIN, irDistConstants[3]);
}