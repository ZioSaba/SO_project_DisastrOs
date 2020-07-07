#include "disastrOS_constants.h"
#include "disastrOS_globals.h"
#include "signals.h"

// ZioS: quando viene inviato un segnale, mi baso sul suo numero per la creazione del giusto contesto
void signalMakeContext(PCB* proc_pcb, int signal_number){
    switch (signal_number)
    {
    case DSOS_SIGKILL:
            makecontext(&proc_pcb->context_signals_array[DSOS_SIGKILL], signalInterrupt_Kill, 1, (void*)proc_pcb->syscall_args[1]);
        break;
    
    case DSOS_SIGMOVUP:
            makecontext(&proc_pcb->context_signals_array[DSOS_SIGMOVUP], signalInterrupt_MovUp, 1, (void*)proc_pcb->syscall_args[1]);
        break;

    default:
            // Qui non ci arriva
        break;
    }
}