#include "topSettingsListify.h"

int topSettingsListifyGetLength()
{
    return 17;
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
    case 14:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 15:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 16:
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
        return topSettings.mHeadMxRtErr;
    case 10:
        return topSettings.mHeadPterm;
    case 11:
        return topSettings.mHallPterm;
    case 12:
        return topSettings.mHallHeadRng;
    case 13:
        return topSettings.mHallHallAdj;
    case 14:
        return topSettings.mHallHeadAdj;
    case 15:
        return topSettings.mHallThresh;
    case 16:
        return topSettings.mHallDinc;
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
        topSettings.mHeadMxRtErr = val;
        break;
    case 10:
        topSettings.mHeadPterm = val;
        break;
    case 11:
        topSettings.mHallPterm = val;
        break;
    case 12:
        topSettings.mHallHeadRng = val;
        break;
    case 13:
        topSettings.mHallHallAdj = val;
        break;
    case 14:
        topSettings.mHallHeadAdj = val;
        break;
    case 15:
        topSettings.mHallThresh = val;
        break;
    case 16:
        topSettings.mHallDinc = val;
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
        return F("mHeadMxRtErr");
    case 10:
        return F("mHeadPterm");
    case 11:
        return F("mHallPterm");
    case 12:
        return F("mHallHeadRng");
    case 13:
        return F("mHallHallAdj");
    case 14:
        return F("mHallHeadAdj");
    case 15:
        return F("mHallThresh");
    case 16:
        return F("mHallDinc");
    }
    return "";
}
