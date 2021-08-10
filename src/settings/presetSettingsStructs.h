#ifndef PRESET_SETTINGS_STRUCTS_H
#define PRESET_SETTINGS_STRUCTS_H

struct tagModePresetSettingsStruct {
    float speed;
    float drvDist;
    float tagDist;
};

struct driveModePresetSettingsStruct {
    float manualDriveSpeed;
    float manualTurnSpeed;
    float hallSpeed;
};

struct stillModePresetSettingsStruct {
    bool stillsettingA;
};

struct demoModePresetSettingsStruct {
    float manualDriveSpeed;
    float manualTurnSpeed;
};

#endif