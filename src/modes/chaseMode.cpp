#include "chaseMode.h"
#include "shelbytron_globs.h"
ChaseMode::ChaseMode()
{
}
void ChaseMode::begin()
{
}
void ChaseMode::run()
{

    DURINGmodeLastGenS = genS;
    runGenIR();
    runGenGoStopButton();
}
