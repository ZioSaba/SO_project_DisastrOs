#include "disastrOS_constants.h"
#include "disastrOS_globals.h"
#include "signals.h"

void signalMakeContext(PCB* proc_pcb, int signal_number){
    makecontext(&proc_pcb->context_signals_array[DSOS_SIGKILL], signalInterrupt_Kill, 1, (void*)proc_pcb->syscall_args[1]);
    makecontext(&proc_pcb->context_signals_array[DSOS_SIGMOVUP], signalInterrupt_MovUp, 1, (void*)proc_pcb->syscall_args[1]);
}