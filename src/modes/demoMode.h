#ifndef DEMO_MODE_H
#define DEMO_MODE_H
#include "constants/irConstants.h"
#include "shelbytron_globs.h"
#include "robot/entertainment.h"
#include "robot/genIR.h"
#include "robot/genGoStopButton.h"
class DemoMode {
public:
    DemoMode();
    void begin();
    void run();

private:
};
static DemoMode demomode = DemoMode();
#endif