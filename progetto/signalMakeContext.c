#include "disastrOS_constants.h"
#include "disastrOS_globals.h"
#include "signals.h"

void signalMakeContext(){
    makecontext(&running->signal_context_sigKill, signalInterrupt_Kill, 1, (void*)running->syscall_args[1]);
    makecontext(&running->signal_context_sigMovUp, signalInterrupt_MovUp, 1, (void*)running->syscall_args[1]);
}
