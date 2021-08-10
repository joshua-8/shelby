#include "presetSettingsListify.h"

int presetSettingsListifyGetLength(int mode)
{
    switch (mode) {
    case TAG_MODE_ID:
        return 3;
    case DRIVE_MODE_ID:
        return 3;
    case STILL_MODE_ID:
        return 1;
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
    case DRIVE_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 1:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        case 2:
            return PRESET_SETTINGS_LISTIFY_FLOAT;
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return PRESET_SETTINGS_LISTIFY_BOOLEAN;
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
    case DRIVE_MODE_ID:
        switch (currVal) {
        case 0:
            return driveModePresetSettings[preset].manualDriveSpeed;
        case 1:
            return driveModePresetSettings[preset].manualTurnSpeed;
        case 2:
            return driveModePresetSettings[preset].hallSpeed;
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return stillModePresetSettings[preset].stillsettingA;
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
    case DRIVE_MODE_ID:
        switch (currVal) {
        case 0:
            driveModePresetSettings[preset].manualDriveSpeed = val;
            break;
        case 1:
            driveModePresetSettings[preset].manualTurnSpeed = val;
            break;
        case 2:
            driveModePresetSettings[preset].hallSpeed = val;
            break;
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            stillModePresetSettings[preset].stillsettingA = val;
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
    case DRIVE_MODE_ID:
        switch (currVal) {
        case 0:
            return F("mDrive");
        case 1:
            return F("mTurn");
        case 2:
            return F("hallSp");
        }
        break;
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return F("stillsettA");
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