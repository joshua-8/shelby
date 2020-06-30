#include "genSettingsSD.h"
// struct generalSetStruct
// {
//   int8_t mode;
//   int8_t lastMode;
//   int8_t preset;
//   int8_t musicMode;
//   int8_t lightsMode;
//   int8_t wordsMode;
// };

void saveGenSettingsSD(generalSetStruct* genSet)
{
    sd.remove("gset.txt");
    file.open("gset.txt", O_WRITE | O_CREAT);
    file.println((*genSet).mode);
    file.println((*genSet).preset);
    file.println((*genSet).musicMode);
    file.println((*genSet).lightsMode);
    file.println((*genSet).wordsMode);
    file.close();
}
void recallGenSettingsSD(generalSetStruct* genSet)
{
    if (file.open("gset.txt")) {
        file.rewind();
        int readval = file.read();
        int charCounter = 0;
        int valCounter = 0;
        char num[6];
        while (readval != -1) {
            if (readval == 13) { //newline
                file.read(); //toss second part of newline
                num[charCounter] = '\0';
                switch (valCounter) {
                case 0:
                    (*genSet).mode = atoi(num);
                    break;
                case 1:
                    (*genSet).preset = atoi(num);
                    break;
                case 2:
                    (*genSet).musicMode = atoi(num);
                    break;
                case 3:
                    (*genSet).lightsMode = atoi(num);
                    break;
                case 4:
                    (*genSet).wordsMode = atoi(num);
                    break;
                }
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
