#include "modeSettingsListify.h"

int modeSettingsListifyGetLength(int mode)
{
    switch (mode) {
    case TAG_MODE_ID:
        return 2;
    case STILL_MODE_ID:
        return 1;
    case DRIVE_MODE_ID:
        return 1;
    case DEMO_MODE_ID:
        return 1;
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
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        }
        break;
    case DRIVE_MODE_ID:
        switch (currVal) {
        case 0:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return MODE_SETTINGS_LISTIFY_BOOLEAN;
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
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return stillModeModeSettings.stillsettingA;
        }
        break;
    case DRIVE_MODE_ID:
        switch (currVal) {
        case 0:
            return driveModeModeSettings.drivesettingA;
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return demoModeModeSettings.demosettingA;
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
    case DRIVE_MODE_ID:
        switch (currVal) {
        case 0:
            driveModeModeSettings.drivesettingA = val;
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
    case STILL_MODE_ID:
        switch (currVal) {
        case 0:
            return F("stillA");
        }
        break;
    case DRIVE_MODE_ID:
        switch (currVal) {
        case 0:
            return F("driveA");
        }
        break;
    case DEMO_MODE_ID:
        switch (currVal) {
        case 0:
            return F("demosettA");
        }
        break;
    }
    return "";
}