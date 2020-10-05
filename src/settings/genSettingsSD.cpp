#include "genSettingsSD.h"

void saveGenSettingsSD()
{
    sd.remove("gset.txt");
    file.open("gset.txt", O_WRITE | O_CREAT);
    file.println(genS.mode);
    file.println(genS.preset);
    file.println(genS.musicMode);
    file.println(genS.lightsMode);
    file.println(genS.wordsMode);
    file.println(genS.musicList);
    file.println(genS.volume);
    file.close();
}
void recallGenSettingsSD()
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
                    genS.mode = atoi(num);
                    break;
                case 1:
                    genS.preset = atoi(num);
                    break;
                case 2:
                    genS.musicMode = atoi(num);
                    break;
                case 3:
                    genS.lightsMode = atoi(num);
                    break;
                case 4:
                    genS.wordsMode = atoi(num);
                    break;
                case 5:
                    genS.musicList = atoi(num);
                    break;
                case 6:
                    genS.volume = atoi(num);
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
