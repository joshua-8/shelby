//code for Shelbytron, a robot to encourage patients during physical therapy
#include <Arduino.h>
#include "constants/pinout.h"
#include "constants/constants.h"
#include "screen/screen.h"
#include "settings/generalSetStruct.h"
#include "settings/presetSettingsStructs.h"
generalSetStruct genS = { -1, -1, 1, 0, 0, 0};
tagModePresetSettingsStruct tagModePresetSettings[presetNum];
chaseModePresetSettingsStruct chaseModePresetSettings[presetNum];
raceModePresetSettingsStruct raceModePresetSettings[presetNum];
walkerModePresetSettingsStruct walkerModePresetSettings[presetNum];
demoModePresetSettingsStruct demoModePresetSettings[presetNum];

Screen screen(&genS);

void setup() {
  Serial.begin(250000);
  analogReadResolution(12);
  screen.begin();

}

void loop() {
  genS.lastMode = genS.mode;
  screen.run();
}