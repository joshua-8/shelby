#ifndef MODE_SETTINGS_STRUCTS_H
#define MODE_SETTINGS_STRUCTS_H

struct tagModeModeSettingsStruct {
    bool safe;
    bool turnLeft;
};

struct chaseModeModeSettingsStruct {
    boolean safe;
};

struct raceModeModeSettingsStruct {
    int racesettingA;
    float racesettingB;
    bool racesettingC;
    int racesettingD;
    float racesettingE;
    bool racesettingF;
    int racesettingG;
    float racesettingH;
    bool racesettingI;
    int racesettingJ;
    float racesettingK;
    bool racesettingL;
};

struct walkerModeModeSettingsStruct {
    int walkersettingA;
    float walkersettingB;
    bool walkersettingC;
    int walkersettingD;
};

struct stillModeModeSettingsStruct {
    bool stillsettingA;
};

struct demoModeModeSettingsStruct {
    bool demosettingA;
    int demosettingB;
    float demosettingC;
};

#endif