#ifndef MOVEDRIVE_H
#define MOVEDRIVE_H
#include "shelbytron_globs.h"
#include <Arduino.h>
class MoveDrive {
public:
    MoveDrive();
    void run();
    boolean navigating;
    boolean isNavigating();
    void setDriveTarget(float distance, float rotation, unsigned long timeMillis, boolean _safe, bool reset);
    boolean stopNavigating();

private:
    boolean navigate();
    unsigned long navTime;
    float targetDist;
    float targetTurn;
    boolean safe;
    boolean doneMoving;
    boolean doneTurning;
};
#endif