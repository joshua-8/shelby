#ifndef SHELBYTRON_GLOBS_H
#define SHELBYTRON_GLOBS_H
#include "screen/msgScreen.h"
#include "subsystems/!subsystems.h"

extern boolean go;
extern boolean DURINGModeLastGo;
extern unsigned long lastLoopTimeMicros;
extern Subsystems subsystems;
extern MsgScreen messageScreen;
extern bool BAT_low_alerted;
extern bool BAT_crit_alerted;

#endif
