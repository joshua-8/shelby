#include "modeSettingsListify.h"

int modeSettingsListifyGetLength(int mode)
{
    switch (mode) {
    case TAG_MODE_ID:
        return 2;
    case CHASE_MODE_ID:
        return 1;
    case RACE_MODE_ID:
        return 12;
    case WALKER_MODE_ID:
        return 4;
    case STILL_MODE_ID:
        return 1;
    case DEMO_MODE_ID:
        return 3;
    }
    return 0;
}

int modeSettingsListifyGetIsBIF(int mode, int currVal)
{

    switch (mode) {
    case TAG_MODE_ID:
        switch (currVal) {
        case 0:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        case 1:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        }
        break;
    case RACE_MODE_ID:
        switch (currVal) {
        case 0:
            return MODE_SETTINGS_LISTIFY_INT;
        case 1:
            return MODE_SETTINGS_LISTIFY_FLOAT;
        case 2:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        case 3:
            return MODE_SETTINGS_LISTIFY_INT;
        case 4:
            return MODE_SETTINGS_LISTIFY_FLOAT;
        case 5:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        case 6:
            return MODE_SETTINGS_LISTIFY_INT;
        case 7:
            return MODE_SETTINGS_LISTIFY_FLOAT;
        case 8:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        case 9:
            return MODE_SETTINGS_LISTIFY_INT;
        case 10:
            return MODE_SETTINGS_LISTIFY_FLOAT;
        case 11:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        }
        break;
    case WALKER_MODE_ID:
        switch (currVal) {
        case 0:
            return MODE_SETTINGS_LISTIFY_INT;
        case 1:
            return MODE_SETTINGS_LISTIFY_FLOAT;
        case 2:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        case 3:
            return MODE_SETTINGS_LISTIFY_INT;
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        case 1:
            return MODE_SETTINGS_LISTIFY_INT;
        case 2:
            return MODE_SETTINGS_LISTIFY_FLOAT;
        }
        break;
    }
    return -1;
}

float modeSettingsListifyGetVal(int mode, int currVal)
{
    switch (mode) {
    case TAG_MODE_ID:
        switch (currVal) {
        case 0:
            return tagModeModeSettings.safe;
        case 1:
            return tagModeModeSettings.turnLeft;
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            return chaseModeModeSettings.safe;
        }
        break;
    case RACE_MODE_ID:
        switch (currVal) {
        case 0:
            return raceModeModeSettings.racesettingA;
        case 1:
            return raceModeModeSettings.racesettingB;
        case 2:
            return raceModeModeSettings.racesettingC;
        case 3:
            return raceModeModeSettings.racesettingD;
        case 4:
            return raceModeModeSettings.racesettingE;
        case 5:
            return raceModeModeSettings.racesettingF;
        case 6:
            return raceModeModeSettings.racesettingG;
        case 7:
            return raceModeModeSettings.racesettingH;
        case 8:
            return raceModeModeSettings.racesettingI;
        case 9:
            return raceModeModeSettings.racesettingJ;
        case 10:
            return raceModeModeSettings.racesettingK;
        case 11:
            return raceModeModeSettings.racesettingL;
        }
        break;
    case WALKER_MODE_ID:
        switch (currVal) {
        case 0:
            return walkerModeModeSettings.walkersettingA;
        case 1:
            return walkerModeModeSettings.walkersettingB;
        case 2:
            return walkerModeModeSettings.walkersettingC;
        case 3:
            return walkerModeModeSettings.walkersettingD;
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return stillModeModeSettings.stillsettingA;
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return demoModeModeSettings.demosettingA;
        case 1:
            return demoModeModeSettings.demosettingB;
        case 2:
            return demoModeModeSettings.demosettingC;
        }
        break;
    }
    return 0;
}

void modeSettingsListifySetVal(int mode, int currVal, float val)
{
    switch (mode) {
    case TAG_MODE_ID:
        switch (currVal) {
        case 0:
            tagModeModeSettings.safe = val;
            break;
        case 1:
            tagModeModeSettings.turnLeft = val;
            break;
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            chaseModeModeSettings.safe = val;
            break;
        }
        break;
    case RACE_MODE_ID:
        switch (currVal) {
        case 0:
            raceModeModeSettings.racesettingA = val;
            break;
        case 1:
            raceModeModeSettings.racesettingB = val;
            break;
        case 2:
            raceModeModeSettings.racesettingC = val;
            break;
        case 3:
            raceModeModeSettings.racesettingD = val;
            break;
        case 4:
            raceModeModeSettings.racesettingE = val;
            break;
        case 5:
            raceModeModeSettings.racesettingF = val;
            break;
        case 6:
            raceModeModeSettings.racesettingG = val;
            break;
        case 7:
            raceModeModeSettings.racesettingH = val;
            break;
        case 8:
            raceModeModeSettings.racesettingI = val;
            break;
        case 9:
            raceModeModeSettings.racesettingJ = val;
            break;
        case 10:
            raceModeModeSettings.racesettingK = val;
            break;
        case 11:
            raceModeModeSettings.racesettingL = val;
            break;
        }
        break;
    case WALKER_MODE_ID:
        switch (currVal) {
        case 0:
            walkerModeModeSettings.walkersettingA = val;
            break;
        case 1:
            walkerModeModeSettings.walkersettingB = val;
            break;
        case 2:
            walkerModeModeSettings.walkersettingC = val;
            break;
        case 3:
            walkerModeModeSettings.walkersettingD = val;
            break;
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            stillModeModeSettings.stillsettingA = val;
            break;
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            demoModeModeSettings.demosettingA = val;
            break;
        case 1:
            demoModeModeSettings.demosettingB = val;
            break;
        case 2:
            demoModeModeSettings.demosettingC = val;
            break;
        }
        break;
    }
}

String modeSettingsListifyGetName(int mode, int currVal)
{
    switch (mode) {
    case TAG_MODE_ID:
        switch (currVal) {
        case 0:
            return F("safe");
        case 1:
            return F("turnLeft");
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            return F("safe");
        }
        break;
    case RACE_MODE_ID:
        switch (currVal) {
        case 0:
            return F("racesettA");
        case 1:
            return F("racesettB");
        case 2:
            return F("racesettC");
        case 3:
            return F("racesettD");
        case 4:
            return F("racesettE");
        case 5:
            return F("racesettF");
        case 6:
            return F("racesettG");
        case 7:
            return F("racesettH");
        case 8:
            return F("racesettI");
        case 9:
            return F("racesettJ");
        case 10:
            return F("racesettK");
        case 11:
            return F("racesettL");
        }
        break;
    case WALKER_MODE_ID:
        switch (currVal) {
        case 0:
            return F("walkersettA");
        case 1:
            return F("walkersettB");
        case 2:
            return F("walkersettC");
        case 3:
            return F("walkersettD");
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return F("stillsetA");
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return F("demosettA");
        case 1:
            return F("demosettB");
        case 2:
            return F("demosettC");
        }
        break;
    }
    return "";
}