#include "presetSettingsListify.h"

int presetSettingsListifyGetLength(int mode)
{
    switch (mode) {
    case TAG_MODE_ID:
        return 3;
    case CHASE_MODE_ID:
        return 1;
    case RACE_MODE_ID:
        return 12;
    case WALKER_MODE_ID:
        return 4;
    case STILL_MODE_ID:
        return 2;
    case DEMO_MODE_ID:
        return 2;
    }
    return 0;
}

int presetSettingsListifyGetIsBIF(int mode, int currVal)
{

    switch (mode) {
    case TAG_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 1:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 2:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        }
        break;
    case RACE_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_INT;
        case 1:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 2:
            return PRESET_SETTINGS_LISTIFY_BOOLEAN;
        case 3:
            return PRESET_SETTINGS_LISTIFY_INT;
        case 4:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 5:
            return PRESET_SETTINGS_LISTIFY_BOOLEAN;
        case 6:
            return PRESET_SETTINGS_LISTIFY_INT;
        case 7:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 8:
            return PRESET_SETTINGS_LISTIFY_BOOLEAN;
        case 9:
            return PRESET_SETTINGS_LISTIFY_INT;
        case 10:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 11:
            return PRESET_SETTINGS_LISTIFY_BOOLEAN;
        }
        break;
    case WALKER_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_INT;
        case 1:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 2:
            return PRESET_SETTINGS_LISTIFY_BOOLEAN;
        case 3:
            return PRESET_SETTINGS_LISTIFY_INT;
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_BOOLEAN;
        case 1:
            return PRESET_SETTINGS_LISTIFY_INT;
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 1:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        }
        break;
    }
    return -1;
}

float presetSettingsListifyGetVal(int mode, int preset, int currVal)
{
    switch (mode) {
    case TAG_MODE_ID:
        switch (currVal) {
        case 0:
            return tagModePresetSettings[preset].speed;
        case 1:
            return tagModePresetSettings[preset].drvDist;
        case 2:
            return tagModePresetSettings[preset].tagDist;
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            return chaseModePresetSettings[preset].speed;
        }
        break;
    case RACE_MODE_ID:
        switch (currVal) {
        case 0:
            return raceModePresetSettings[preset].racesettingA;
        case 1:
            return raceModePresetSettings[preset].racesettingB;
        case 2:
            return raceModePresetSettings[preset].racesettingC;
        case 3:
            return raceModePresetSettings[preset].racesettingD;
        case 4:
            return raceModePresetSettings[preset].racesettingE;
        case 5:
            return raceModePresetSettings[preset].racesettingF;
        case 6:
            return raceModePresetSettings[preset].racesettingG;
        case 7:
            return raceModePresetSettings[preset].racesettingH;
        case 8:
            return raceModePresetSettings[preset].racesettingI;
        case 9:
            return raceModePresetSettings[preset].racesettingJ;
        case 10:
            return raceModePresetSettings[preset].racesettingK;
        case 11:
            return raceModePresetSettings[preset].racesettingL;
        }
        break;
    case WALKER_MODE_ID:
        switch (currVal) {
        case 0:
            return walkerModePresetSettings[preset].walkersettingA;
        case 1:
            return walkerModePresetSettings[preset].walkersettingB;
        case 2:
            return walkerModePresetSettings[preset].walkersettingC;
        case 3:
            return walkerModePresetSettings[preset].walkersettingD;
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return stillModePresetSettings[preset].stillsettingA;
        case 1:
            return stillModePresetSettings[preset].stillsettingB;
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return demoModePresetSettings[preset].manualDriveSpeed;
        case 1:
            return demoModePresetSettings[preset].manualTurnSpeed;
        }
        break;
    }
    return 0;
}

void presetSettingsListifySetVal(int mode, int preset, int currVal, float val)
{
    switch (mode) {
    case TAG_MODE_ID:
        switch (currVal) {
        case 0:
            tagModePresetSettings[preset].speed = val;
            break;
        case 1:
            tagModePresetSettings[preset].drvDist = val;
            break;
        case 2:
            tagModePresetSettings[preset].tagDist = val;
            break;
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            chaseModePresetSettings[preset].speed = val;
            break;
        }
        break;
    case RACE_MODE_ID:
        switch (currVal) {
        case 0:
            raceModePresetSettings[preset].racesettingA = val;
            break;
        case 1:
            raceModePresetSettings[preset].racesettingB = val;
            break;
        case 2:
            raceModePresetSettings[preset].racesettingC = val;
            break;
        case 3:
            raceModePresetSettings[preset].racesettingD = val;
            break;
        case 4:
            raceModePresetSettings[preset].racesettingE = val;
            break;
        case 5:
            raceModePresetSettings[preset].racesettingF = val;
            break;
        case 6:
            raceModePresetSettings[preset].racesettingG = val;
            break;
        case 7:
            raceModePresetSettings[preset].racesettingH = val;
            break;
        case 8:
            raceModePresetSettings[preset].racesettingI = val;
            break;
        case 9:
            raceModePresetSettings[preset].racesettingJ = val;
            break;
        case 10:
            raceModePresetSettings[preset].racesettingK = val;
            break;
        case 11:
            raceModePresetSettings[preset].racesettingL = val;
            break;
        }
        break;
    case WALKER_MODE_ID:
        switch (currVal) {
        case 0:
            walkerModePresetSettings[preset].walkersettingA = val;
            break;
        case 1:
            walkerModePresetSettings[preset].walkersettingB = val;
            break;
        case 2:
            walkerModePresetSettings[preset].walkersettingC = val;
            break;
        case 3:
            walkerModePresetSettings[preset].walkersettingD = val;
            break;
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            stillModePresetSettings[preset].stillsettingA = val;
            break;
        case 1:
            stillModePresetSettings[preset].stillsettingB = val;
            break;
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            demoModePresetSettings[preset].manualDriveSpeed = val;
            break;
        case 1:
            demoModePresetSettings[preset].manualTurnSpeed = val;
            break;
        }
        break;
    }
}

String presetSettingsListifyGetName(int mode, int currVal)
{
    switch (mode) {
    case TAG_MODE_ID:
        switch (currVal) {
        case 0:
            return F("speed");
        case 1:
            return F("drvDist");
        case 2:
            return F("tagDist");
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            return F("speed");
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
            return F("stillsettA");
        case 1:
            return F("stillsettB");
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return F("drvSpd");
        case 1:
            return F("drvTrn");
        }
        break;
    }
    return "";
}