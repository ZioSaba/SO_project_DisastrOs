#include "disastrOS_constants.h"
#include "disastrOS_globals.h"
#include "signals.h"

void signalMakeContext(PCB* proc_pcb, int signal_number){
    switch (signal_number)
    {
        case DSOS_SIGKILL:
            getcontext(&proc_pcb->signal_context_sigKill);
            proc_pcb->signal_context_sigKill.uc_stack.ss_sp = proc_pcb->signal_stack;
            proc_pcb->signal_context_sigKill.uc_stack.ss_size = STACK_SIZE;
            proc_pcb->signal_context_sigKill.uc_stack.ss_flags = 0;
            proc_pcb->signal_context_sigKill.uc_link = &main_context;
            makecontext(&proc_pcb->signal_context_sigKill, signalInterrupt_Kill, 1, (void*)proc_pcb->syscall_args[1]);
        break;
        
        case DSOS_SIGMOVUP:
            getcontext(&proc_pcb->signal_context_sigMovUp);
            proc_pcb->signal_context_sigMovUp.uc_stack.ss_sp = proc_pcb->signal_stack;
            proc_pcb->signal_context_sigMovUp.uc_stack.ss_size = STACK_SIZE;
            proc_pcb->signal_context_sigMovUp.uc_stack.ss_flags = 0;
            proc_pcb->signal_context_sigMovUp.uc_link = &main_context;
            makecontext(&proc_pcb->signal_context_sigMovUp, signalInterrupt_MovUp, 1, (void*)proc_pcb->syscall_args[1]);
        break;

        default:
            // Altri segnali da implementare
        break;
    }
}