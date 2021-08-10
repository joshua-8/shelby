#ifndef MODES_H
#define MODES_H
#include "demoMode.h"
#include "stillMode.h"
#include "driveMode.h"
#include "tagMode.h"

void modesRun()
{
    if (genS.mode != premodeLastGenS.mode) {
        switch (genS.mode) {
        case TAG_MODE_ID:
            tagmode.begin();
            break;
        case DRIVE_MODE_ID:
            drivemode.begin();
            break;
        case STILL_MODE_ID:
            stillmode.begin();
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
    case DRIVE_MODE_ID:
        drivemode.run();
        break;
    case STILL_MODE_ID:
        stillmode.run();
        break;
    case DEMO_MODE_ID:
        demomode.run();
        break;
    }
}

#endif