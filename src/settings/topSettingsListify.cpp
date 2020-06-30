#include "topSettingsListify.h"

int topSettingsListifyGetLength()
{
    return 12;
}

int topSettingsListifyGetIsBIF(int currVal)
{
    switch (currVal) {
    case 0:
        return TOP_SETTINGS_LISTIFY_INT;
    case 1:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 2:
        return TOP_SETTINGS_LISTIFY_BOOLEAN;
    case 3:
        return TOP_SETTINGS_LISTIFY_INT;
    case 4:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 5:
        return TOP_SETTINGS_LISTIFY_BOOLEAN;
    case 6:
        return TOP_SETTINGS_LISTIFY_INT;
    case 7:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 8:
        return TOP_SETTINGS_LISTIFY_BOOLEAN;
    case 9:
        return TOP_SETTINGS_LISTIFY_INT;
    case 10:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    case 11:
        return TOP_SETTINGS_LISTIFY_BOOLEAN;
    }
    return 0;
}

float topSettingsListifyGetVal(int currVal)
{
    switch (currVal) {
    case 0:
        return topSettings.settingA;
    case 1:
        return topSettings.settingB;
    case 2:
        return topSettings.settingC;
    case 3:
        return topSettings.settingD;
    case 4:
        return topSettings.settingE;
    case 5:
        return topSettings.settingF;
    case 6:
        return topSettings.settingG;
    case 7:
        return topSettings.settingH;
    case 8:
        return topSettings.settingI;
    case 9:
        return topSettings.settingJ;
    case 10:
        return topSettings.settingK;
    case 11:
        return topSettings.settingL;
    }
    return 0;
}

void topSettingsListifySetVal(int currVal, float val)
{
    switch (currVal) {
    case 0:
        topSettings.settingA = val;
        break;
    case 1:
        topSettings.settingB = val;
        break;
    case 2:
        topSettings.settingC = val;
        break;
    case 3:
        topSettings.settingD = val;
        break;
    case 4:
        topSettings.settingE = val;
        break;
    case 5:
        topSettings.settingF = val;
        break;
    case 6:
        topSettings.settingG = val;
        break;
    case 7:
        topSettings.settingH = val;
        break;
    case 8:
        topSettings.settingI = val;
        break;
    case 9:
        topSettings.settingJ = val;
        break;
    case 10:
        topSettings.settingK = val;
        break;
    case 11:
        topSettings.settingL = val;
        break;
    }
}

String topSettingsListifyGetName(int currVal)
{
    switch (currVal) {
    case 0:
        return F("settA");
    case 1:
        return F("settB");
    case 2:
        return F("settC");
    case 3:
        return F("settD");
    case 4:
        return F("settE");
    case 5:
        return F("settF");
    case 6:
        return F("settG");
    case 7:
        return F("settH");
    case 8:
        return F("settI");
    case 9:
        return F("settJ");
    case 10:
        return F("settK");
    case 11:
        return F("settL");
    }
    return "";
}