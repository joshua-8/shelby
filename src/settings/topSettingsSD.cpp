#include "topSettingsSD.h"

void saveTopSettingsSD()
{
    sd.remove("setings.txt");
    file.open("setings.txt", O_WRITE | O_CREAT);
    for (int i = 0; i < topSettingsListifyGetLength(); i++) {
        file.println(topSettingsListifyGetVal(i), menuScreenConstants.NUMPAD_STRING_LENGTH);
    }
    file.close();
}

void recallTopSettingsSD()
{
    if (file.open("setings.txt")) {
        file.rewind();
        int readval = file.read();
        int charCounter = 0;
        int valCounter = 0;
        char num[menuScreenConstants.NUMPAD_STRING_LENGTH * 2 + 3];
        while (readval != -1) {
            if (readval == 13) { //newline
                file.read(); //toss second part of newline
                num[charCounter] = '\0';
                topSettingsListifySetVal(valCounter, atof(num));
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
