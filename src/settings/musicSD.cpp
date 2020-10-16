#include "musicSD.h"

void saveLongMusicSettingsSD()
{
    sd.remove("lmusic.txt");
    file.open("lmusic.txt", O_WRITE | O_CREAT);
    for (int i = 0; i < audioConstants.musicListNum; i++) {
        file.println(longMusicPlaylistPos[i]);
    }
    file.close();
}
void saveShortMusicSettingsSD()
{
    sd.remove("smusic.txt");
    file.open("smusic.txt", O_WRITE | O_CREAT);
    for (int i = 0; i < audioConstants.musicListNum; i++) {
        file.println(shortMusicPlaylistPos[i]);
    }
    file.close();
}
void recallMusicSettingsSD()
{
    if (file.open("lmusic.txt")) {
        file.rewind();
        int readval = file.read();
        int charCounter = 0;
        int valCounter = 0;
        char num[6];
        while (readval != -1) {
            if (readval == 13) { //newline
                file.read(); //toss second part of newline
                num[charCounter] = '\0';

                longMusicPlaylistPos[valCounter] = atoi(num);

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

    if (file.open("smusic.txt")) {
        file.rewind();
        int readval = file.read();
        int charCounter = 0;
        int valCounter = 0;
        char num[6];
        while (readval != -1) {
            if (readval == 13) { //newline
                file.read(); //toss second part of newline
                num[charCounter] = '\0';

                shortMusicPlaylistPos[valCounter] = atoi(num);

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
