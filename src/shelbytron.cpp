//code for Shelbytron, a robot to encourage patients during physical therapy
#include <Arduino.h>
#include "constants/pinout.h"
#include "screen/screen.h"
#include "settings/generalSetStruct.h"
#include "constants/constants.h"

generalSetStruct genS = { -1, -1, 1, 0, 0, 0};
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