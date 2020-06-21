//code for Shelbytron, a robot to encourage patients during physical therapy
#include <Arduino.h>
#include "screen/screen.h"
#include "settings/settings.h"
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