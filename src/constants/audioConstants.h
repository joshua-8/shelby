#ifndef AUDIOCONSTANTS_H
#define AUDIOCONSTANTS_H
#include <Arduino.h>
class audioConsts {
public:
    const short AUDIO_BOARD_VOLUME_RANGE = 50; //-70 to +4 dB (but I cut the quietist values off)
    const short AUDIO_BOARD_VOLUME_MIN = -46;
    const unsigned short WTRIG_LAG = 100; //milliseconds between starting a song and the board reporting it is playing the track

    const static byte musicListNum = 4;
    const char musicListName[musicListNum][6] = { "young", "chase", "calm", "older" };

    const short musicLongPlaylistLength[musicListNum] = { 14, 11, 26, 53 };
    const short musicLongPlaylistListYoung[14] = { 1072, 1007, 1078, 1017, 1074, 1008, 1076, 1005, 1075, 1002, 1077, 1004, 1073, 1056 };
    const short musicLongPlaylistListChase[11] = { 1031, 1069, 1051, 1004, 1018, 1030, 1039, 1062, 1066, 1063, 1071 };
    const short musicLongPlaylistListCalm[26] = { 1015, 1003, 1019, 1025, 1038, 1055, 1048, 1020, 1036, 1054, 1029, 1058, 1042, 1016, 1028, 1052, 1032, 1014, 1010, 1070, 1044, 1035, 1045, 1006, 1022, 1033 };
    const short musicLongPlaylistListOlder[53] = { 1034, 1063, 1059, 1033, 1025, 1036, 1010, 1068, 1029, 1045, 1023, 1027, 1021, 1035, 1070, 1012, 1020, 1053, 1051, 1071, 1014, 1043, 1022, 1015, 1041, 1030, 1040, 1069, 1042, 1039, 1058, 1054, 1062, 1061, 1067, 1013, 1026, 1046, 1038, 1066, 1047, 1060, 1024, 1052, 1009, 1028, 1049, 1032, 1018, 1055, 1019, 1044, 1031 };
    const short* musicLongPlaylist[musicListNum] = { musicLongPlaylistListYoung, musicLongPlaylistListChase, musicLongPlaylistListCalm, musicLongPlaylistListOlder };

    const short musicShortPlaylistLength[musicListNum] = { 14, 11, 25, 51 };
    const short musicShortPlaylistListYoung[14] = { 1572, 1507, 1578, 1517, 1574, 1508, 1576, 1505, 1575, 1502, 1577, 1504, 1573, 1556 };
    const short musicShortPlaylistListChase[11] = { 1531, 1569, 1551, 1504, 1518, 1530, 1562, 1566, 1557, 1563, 1571 };
    const short musicShortPlaylistListCalm[25] = { 1515, 1503, 1519, 1525, 1538, 1555, 1548, 1520, 1536, 1554, 1529, 1558, 1542, 1516, 1528, 1532, 1552, 1514, 1510, 1570, 1544, 1506, 1545, 1565, 1533 };
    const short musicShortPlaylistListOlder[51] = { 1554, 1541, 1553, 1555, 1552, 1562, 1528, 1532, 1570, 1567, 1563, 1527, 1536, 1514, 1521, 1551, 1529, 1559, 1518, 1566, 1533, 1560, 1547, 1520, 1534, 1544, 1558, 1519, 1565, 1549, 1524, 1538, 1542, 1526, 1568, 1510, 1513, 1569, 1530, 1545, 1561, 1531, 1571, 1543, 1525, 1564, 1515, 1537, 1546, 1509, 1540 };
    const short* musicShortPlaylist[musicListNum] = { musicShortPlaylistListYoung, musicShortPlaylistListChase, musicShortPlaylistListCalm, musicShortPlaylistListOlder };
};
static const audioConsts audioConstants;
#endif