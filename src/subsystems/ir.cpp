#include "ir.h"
#include "shelbytron_globs.h"
IR::IR()
{
    message = 0;
    repeat = 0;
    newMsg = 0;
    lastNewMsgMillis = 0;
}

void IR::begin()
{
    pinMode(IR_RECEIVER_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(IR_RECEIVER_PIN), irISR, CHANGE);
}
void IR::run()
{
    newMsg = false;
    if (micros() - lastFallMicros > irConstants.messageDoneTime && pos != 0) {
        if (pos == irConstants.msgLength - 1) {
            byte message1 = 0;
            byte message2 = 0;
            for (int i = 0; i < 7; i++) {
                message1 |= msg[i] << i;
                message2 |= (!msg[i + 8]) << i;
            }
            if (message1 == message2) { //valid
                message = message1;
                newMsg = true;
                lastNewMsgMillis = millis();
                repeat = (msg[7] == 1 && msg[15] == 0);
                if (message == 66) { //wierd inconsistency in ir remote's protocol
                    repeat = !repeat;
                }
            }
        }
        pos = 0;
    }
}
void IR::irInternalISR()
{
    if (digitalRead(IR_RECEIVER_PIN) == HIGH) {
        lastRiseMicros = micros();
    } else {
        lastFallMicros = micros();
        if (pos >= irConstants.msgStartIgnoreLength) {
            msg[pos - irConstants.msgStartIgnoreLength] = (micros() - lastRiseMicros) > irConstants.pulseThresh;
        }
        if (pos < irConstants.msgLength - 1) {
            pos++;
        }
    }
}

void irISR()
{
    subsystems.ir.irInternalISR();
}