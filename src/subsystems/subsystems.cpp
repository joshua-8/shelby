#include "subsystems.h"
void subsystems::begin(){
    audio.begin();
}
void subsystems::run(){
    audio.run();
}