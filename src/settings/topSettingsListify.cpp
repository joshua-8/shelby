#include "topSettingsListify.h"

int topSettingsListifyGetLength()
{
    return 14;
}

int topSettingsListifyGetIsBIF(int currVal)
{
    switch (currVal) {
    case 0:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 1:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 2:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 3:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 4:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 5:
        return TOP_SETTINGS_LISTIFY_INT;
    case 6:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 7:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 8:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 9:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 10:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 11:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 12:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 13:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    }
    return 0;
}

float topSettingsListifyGetVal(int currVal)
{
    switch (currVal) {
    case 0:
        return topSettings.debugA;
    case 1:
        return topSettings.debugB;
    case 2:
        return topSettings.debugC;
    case 3:
        return topSettings.debugD;
    case 4:
        return topSettings.magneticDeclination;
    case 5:
        return topSettings.musicNormalGain;
    case 6:
        return topSettings.highVoltThresh;
    case 7:
        return topSettings.lowVoltThresh;
    case 8:
        return topSettings.criticalVoltThresh;
    case 9:
        return topSettings.leftWheelFF;
    case 10:
        return topSettings.rightWheelFF;
    case 11:
        return topSettings.wheelAccel;
    case 12:
        return topSettings.mHeadMxRtErr;
    case 13:
        return topSettings.mHeadPterm;
    }
    return 0;
}

void topSettingsListifySetVal(int currVal, float val)
{
    switch (currVal) {
    case 0:
        topSettings.debugA = val;
        break;
    case 1:
        topSettings.debugB = val;
        break;
    case 2:
        topSettings.debugC = val;
        break;
    case 3:
        topSettings.debugD = val;
        break;
    case 4:
        topSettings.magneticDeclination = val;
        break;
    case 5:
        topSettings.musicNormalGain = val;
        break;
    case 6:
        topSettings.highVoltThresh = val;
        break;
    case 7:
        topSettings.lowVoltThresh = val;
        break;
    case 8:
        topSettings.criticalVoltThresh = val;
        break;
    case 9:
        topSettings.leftWheelFF = val;
        break;
    case 10:
        topSettings.rightWheelFF = val;
        break;
    case 11:
        topSettings.wheelAccel = val;
        break;
    case 12:
        topSettings.mHeadMxRtErr = val;
        break;
    case 13:
        topSettings.mHeadPterm = val;
        break;
    }
}

String topSettingsListifyGetName(int currVal)
{
    switch (currVal) {
    case 0:
        return F("debugA");
    case 1:
        return F("debugB");
    case 2:
        return F("debugC");
    case 3:
        return F("debugD");
    case 4:
        return F("MagDecln");
    case 5:
        return F("MusicGain");
    case 6:
        return F("HighBat");
    case 7:
        return F("LowBat");
    case 8:
        return F("CritBat");
    case 9:
        return F("LWheelFF");
    case 10:
        return F("RWheelFF");
    case 11:
        return F("wheelAccel");
    case 12:
        return F("mHeadMxRtErr");
    case 13:
        return F("mHeadPterm");
    }
    return "";
}