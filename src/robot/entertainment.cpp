#include "entertainment.h"
#include "constants/irConstants.h"
#include "shelbytron_globs.h"
Entertainment::Entertainment()
{
}
void Entertainment::playConstantMusicLongIR()
{
    if (!subsystems.audio.isPlayingLong()) {
        subsystems.audio.playNextLong();
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.SKIP_SONG) {
        subsystems.audio.playNextLong();
    }
    if (subsystems.ir.newMsg && !subsystems.ir.repeat && subsystems.ir.message == irConstants.REPLAY_SONG) {
        subsystems.audio.playLastLong();
    }
}