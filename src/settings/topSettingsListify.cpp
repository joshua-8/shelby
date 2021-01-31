#include "topSettingsListify.h"

int topSettingsListifyGetLength()
{
    return 8;
}

int topSettingsListifyGetIsBIF(int currVal)
{
    switch (currVal) {
    case 0:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 1:
        return TOP_SETTINGS_LISTIFY_INT;
    case 2:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 3:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 4:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 5:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 6:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 7:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    }
    return 0;
}

float topSettingsListifyGetVal(int currVal)
{
    switch (currVal) {
    case 0:
        return topSettings.magneticDeclination;
    case 1:
        return topSettings.musicNormalGain;
    case 2:
        return topSettings.highVoltThresh;
    case 3:
        return topSettings.lowVoltThresh;
    case 4:
        return topSettings.criticalVoltThresh;
    case 5:
        return topSettings.leftWheelFF;
    case 6:
        return topSettings.rightWheelFF;
    case 7:
        return topSettings.wheelAccel;
    }
    return 0;
}

void topSettingsListifySetVal(int currVal, float val)
{
    switch (currVal) {
    case 0:
        topSettings.magneticDeclination = val;
        break;
    case 1:
        topSettings.musicNormalGain = val;
        break;
    case 2:
        topSettings.highVoltThresh = val;
        break;
    case 3:
        topSettings.lowVoltThresh = val;
        break;
    case 4:
        topSettings.criticalVoltThresh = val;
        break;
    case 5:
        topSettings.leftWheelFF = val;
        break;
    case 6:
        topSettings.rightWheelFF = val;
        break;
    case 7:
        topSettings.wheelAccel = val;
        break;
    }
}

String topSettingsListifyGetName(int currVal)
{
    switch (currVal) {
    case 0:
        return F("MagDecln");
    case 1:
        return F("MusicGain");
    case 2:
        return F("HighBat");
    case 3:
        return F("LowBat");
    case 4:
        return F("CritBat");
    case 5:
        return F("LWheelFF");
    case 6:
        return F("RWheelFF");
    case 7:
        return F("wheelAccel");
    }
    return "";
}