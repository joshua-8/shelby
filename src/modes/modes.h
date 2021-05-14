#ifndef MODES_H
#define MODES_H
#include "chaseMode.h"
#include "demoMode.h"
#include "tagMode.h"

void modesRun()
{
    if (genS.mode != premodeLastGenS.mode) {
        switch (genS.mode) {
        case TAG_MODE_ID:
            tagmode.begin();
            break;
        case CHASE_MODE_ID:
            chasemode.begin();
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
    premodeLastGenS = genS;

    switch (genS.mode) {
    case TAG_MODE_ID:
        tagmode.run();
        break;
    case CHASE_MODE_ID:
        chasemode.run();
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