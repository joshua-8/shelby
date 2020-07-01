#include "presetSettingsSD.h"

void recallAllPresetSettingsSd()
{
    for (int i = 0; i < modeNum; i++) {
        for (int j = 0; j < presetNum; j++) {
            recallPresetSettingsSD(i, j);
        }
    }
}

void savePresetSettingsSD(int mode, int preset)
{
    if (mode >= modeNum || mode < 0)
        return;
    char fileName[25];
    getPresetSDFilePath(fileName, mode, preset);
    sd.remove(fileName);
    file.open(fileName, O_WRITE | O_CREAT);
    for (int i = 0; i < presetSettingsListifyGetLength(mode); i++) {
        file.println(presetSettingsListifyGetVal(mode, preset, i), NUMPAD_STRING_LENGTH);
    }
    file.close();
}

void recallPresetSettingsSD(int mode, int preset)
{
    if (mode >= modeNum || mode < 0)
        return;
    char fileName[25];
    getPresetSDFilePath(fileName, mode, preset);
    if (file.open(fileName)) {
        file.rewind();
        int readval = file.read();
        int charCounter = 0;
        int valCounter = 0;
        char num[NUMPAD_STRING_LENGTH * 2 + 3];
        while (readval != -1) {
            if (readval == 13) { //newline
                file.read(); //toss second part of newline
                num[charCounter] = '\0';
                presetSettingsListifySetVal(mode, preset, valCounter, atof(num));
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

void getPresetSDFilePath(char* fileName, int mode, int preset)
{
    sprintf(fileName, "modes/%s/pre%d.txt", modeSelName[mode], preset + 1);
}