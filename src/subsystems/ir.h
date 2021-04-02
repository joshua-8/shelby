#ifndef IR_H
#define IR_H
#include "constants/irConstants.h"
#include "constants/pinout.h"
#include <Arduino.h>
void irISR();
class IR {
public:
    IR();
    void begin();
    void run();
    byte message;
    boolean repeat;
    boolean newMsg;
    void irInternalISR();
    unsigned long lastNewMsgMillis;

private:
    volatile unsigned long lastRiseMicros = 0;
    volatile unsigned long lastFallMicros = 0;
    volatile boolean msg[irConstants.msgLength - irConstants.msgStartIgnoreLength] = { 0 };
    volatile byte pos = 0;
};

#endif
