#include "presetSettingsListify.h"

int presetSettingsListifyGetLength(int mode)
{
    switch (mode) {
    case TAG_MODE_ID:
        return 3;
    case CHASE_MODE_ID:
        return 3;
    case RACE_MODE_ID:
        return 12;
    case WALKER_MODE_ID:
        return 4;
    case DEMO_MODE_ID:
        return 3;
    }
    return 0;
}

int presetSettingsListifyGetIsBIF(int mode, int currVal)
{

    switch (mode) {
    case TAG_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_INT;
        case 1:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 2:
            return PRESET_SETTINGS_LISTIFY_BOOLEAN;
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_INT;
        case 1:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 2:
            return PRESET_SETTINGS_LISTIFY_BOOLEAN;
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
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_BOOLEAN;
        case 1:
            return PRESET_SETTINGS_LISTIFY_INT;
        case 2:
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
            return tagModePresetSettings[preset].tagsettingA;
        case 1:
            return tagModePresetSettings[preset].tagsettingB;
        case 2:
            return tagModePresetSettings[preset].tagsettingC;
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            return chaseModePresetSettings[preset].chasesettingA;
        case 1:
            return chaseModePresetSettings[preset].chasesettingB;
        case 2:
            return chaseModePresetSettings[preset].chasesettingC;
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
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return demoModePresetSettings[preset].demosettingA;
        case 1:
            return demoModePresetSettings[preset].demosettingB;
        case 2:
            return demoModePresetSettings[preset].demosettingC;
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
            tagModePresetSettings[preset].tagsettingA = val;
            break;
        case 1:
            tagModePresetSettings[preset].tagsettingB = val;
            break;
        case 2:
            tagModePresetSettings[preset].tagsettingC = val;
            break;
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            chaseModePresetSettings[preset].chasesettingA = val;
            break;
        case 1:
            chaseModePresetSettings[preset].chasesettingB = val;
            break;
        case 2:
            chaseModePresetSettings[preset].chasesettingC = val;
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
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            demoModePresetSettings[preset].demosettingA = val;
            break;
        case 1:
            demoModePresetSettings[preset].demosettingB = val;
            break;
        case 2:
            demoModePresetSettings[preset].demosettingC = val;
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
            return F("tagsettA");
        case 1:
            return F("tagsettB");
        case 2:
            return F("tagsettC");
        }
        break;
    case CHASE_MODE_ID:
        switch (currVal) {
        case 0:
            return F("chasesettA");
        case 1:
            return F("chasesettB");
        case 2:
            return F("chasesettC");
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