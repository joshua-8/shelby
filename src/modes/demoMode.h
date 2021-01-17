#ifndef DEMO_MODE_H
#define DEMO_MODE_H
#include "constants/irConstants.h"
#include "robot/entertainment.h"
#include "robot/genGoStopButton.h"
#include "robot/genIR.h"
#include "shelbytron_globs.h"
class DemoMode {
public:
    DemoMode();
    void begin();
    void run();

private:
    boolean mainMode = true;
};
static DemoMode demomode = DemoMode();
#endif