#ifndef PRESET_SETTINGS_STRUCTS_H
#define PRESET_SETTINGS_STRUCTS_H

struct tagModePresetSettingsStruct {
    int tagsettingA;
    float tagsettingB;
    bool tagsettingC;
};

struct chaseModePresetSettingsStruct {
    int chasesettingA;
    float chasesettingB;
    bool chasesettingC;
};

struct raceModePresetSettingsStruct {
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

struct walkerModePresetSettingsStruct {
    int walkersettingA;
    float walkersettingB;
    bool walkersettingC;
    int walkersettingD;
};

struct stillModePresetSettingsStruct {
    bool stillsettingA;
    int stillsettingB;
};
struct demoModePresetSettingsStruct {
    float manualDriveSpeed;
    float manualTurnSpeed;
};

#endif