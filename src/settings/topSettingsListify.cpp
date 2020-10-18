#include "topSettingsListify.h"

int topSettingsListifyGetLength()
{
    return 1;
}

int topSettingsListifyGetIsBIF(int currVal)
{
    switch (currVal) {
    case 0:
        return TOP_SETTINGS_LISTIFY_FLOAT;
    }
    return 0;
}

float topSettingsListifyGetVal(int currVal)
{
    switch (currVal) {
    case 0:
        return topSettings.magneticDeclination;
    }
    return 0;
}

void topSettingsListifySetVal(int currVal, float val)
{
    switch (currVal) {
    case 0:
        topSettings.magneticDeclination = val;
        break;
    }
}

String topSettingsListifyGetName(int currVal)
{
    switch (currVal) {
    case 0:
        return F("MagDecln");
    }
    return "";
}