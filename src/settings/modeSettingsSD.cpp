#include "modeSettingsSD.h"

void recallAllModeSettingsSd()
{
    for (int i = 0; i < modeNum; i++) {
        recallModeSettingsSD(i); //TODO: CHANGE BACK TO RECALL
    }
}

void saveModeSettingsSD(int mode)
{
    if (mode >= modeNum || mode < 0)
        return;
    char fileName[25];
    getModeSDFilePath(fileName, mode);
    sd.remove(fileName);
    file.open(fileName, O_WRITE | O_CREAT);
    for (int i = 0; i < modeSettingsListifyGetLength(mode); i++) {
        file.println(modeSettingsListifyGetVal(mode, i), menuScreenConstants.NUMPAD_STRING_LENGTH);
    }
    file.close();
}

void recallModeSettingsSD(int mode)
{
    if (mode >= modeNum || mode < 0)
        return;
    char fileName[25];
    getModeSDFilePath(fileName, mode);
    if (file.open(fileName)) {
        file.rewind();
        int readval = file.read();
        int charCounter = 0;
        int valCounter = 0;
        char num[menuScreenConstants.NUMPAD_STRING_LENGTH * 2 + 3];
        while (readval != -1) {
            if (readval == 13) { //newline
                file.read(); //toss second part of newline
                num[charCounter] = '\0';
                modeSettingsListifySetVal(mode, valCounter, atof(num));
                valCounter++;
                charCounter = 0;
            } else {
                num[charCounter] = readval;
                charCounter++;
            }
            readval = file.read();
        }
    }
    file.close();
}

void getModeSDFilePath(char* fileName, int mode)
{
    sprintf(fileName, "modes/%s/setings.txt", modeSelName[mode]);
}