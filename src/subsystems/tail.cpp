#include "tail.h"
#include "shelbytron_globs.h"
Tail::Tail()
{

    period = 0;
    pos = (tailConstants.rightRange + tailConstants.leftRange) / 2;
    increa = false;
}

void Tail::begin()
{
    period = 0;
    pos = (tailConstants.rightRange + tailConstants.leftRange) / 2;
}
void Tail::run()
{
    if (period > 0) {

        float movement = constrain(1.0 * (tailConstants.rightRange - tailConstants.leftRange) * lastLoopTimeMicros / period * 2, -(tailConstants.rightRange - tailConstants.leftRange) / 5, (tailConstants.rightRange - tailConstants.leftRange) / 5);

        if (increa) {
            if (pos + movement > max(tailConstants.rightRange, tailConstants.leftRange)) {
                increa = false;
            }
        } else {
            if (pos - movement < min(tailConstants.rightRange, tailConstants.leftRange)) {
                increa = true;
            }
        }
        if (increa) {
            pos += movement;
        } else {
            pos -= movement;
        }
        if (!servo.attached()) {
            servo.attach(TAIL_SERVO_PIN);
        }
        servo.writeMicroseconds(pos);
    } else {
        if (servo.attached()) {
            servo.detach();
        }
    }
}
void Tail::wag(unsigned int _period)
{
    period = _period;
}
void Tail::stopWag()
{
    period = 0;
}