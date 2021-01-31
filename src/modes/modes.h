#ifndef MODES_H
#define MODES_H
#include "demoMode.h"

void modesRun()
{
    if (genS.mode != lastGenS.mode) {
        switch (genS.mode) {
        case TAG_MODE_ID:
            break;
        case CHASE_MODE_ID:
            break;
        case RACE_MODE_ID:
            break;
        case WALKER_MODE_ID:
            break;
        case STILL_MODE_ID:
            break;
        case DEMO_MODE_ID:
            demomode.begin();
            break;
        }
    }
    lastGenS = genS;

    switch (genS.mode) {
    case TAG_MODE_ID:
        break;
    case CHASE_MODE_ID:
        break;
    case RACE_MODE_ID:
        break;
    case WALKER_MODE_ID:
        break;
    case STILL_MODE_ID:
        break;
    case DEMO_MODE_ID:
        demomode.run();
        break;
    }
}

#endif