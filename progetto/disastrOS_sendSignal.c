// Gio: definisco il file contenente la syscall per l'invio dei segnali 
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"
#include "signals.h"

// Gio: il timer invia il segnale di kill o sposta in testa l'ultimo processo a seconda del valore del quanto temporale
void internal_signal(){
    if (disastrOS_time % TIME_KILL == 0){
    
        if (ready_list.first != 0){
            PCB* last_pcb = (PCB*) ready_list.last;


            // ZioS: impostiamo il contesto per la gestione dei segnali
            //disastrOS_debug("setting entry point for DSOS_SIGMOVUP interrupt... ");
            getcontext(&last_pcb->signal_context_sigMovUp);
            last_pcb->signal_context_sigMovUp.uc_stack.ss_sp = last_pcb->signal_stack;
            last_pcb->signal_context_sigMovUp.uc_stack.ss_size = STACK_SIZE;
            last_pcb->signal_context_sigMovUp.uc_stack.ss_flags = 0;
            last_pcb->signal_context_sigMovUp.uc_link = &main_context;
            makecontext(&last_pcb->signal_context_sigMovUp, signalInterrupt_MovUp, 1, (void*)last_pcb->syscall_args[1]);


            //disastrOS_debug("setting entry point for DSOS_SIGKILL interrupt... ");
            // Gio: il secondo contesto non serve rinizializzarlo ma basta copiare i parametri di quello precedentemente definito
            last_pcb->signal_context_sigKill = last_pcb->signal_context_sigMovUp;
            makecontext(&last_pcb->signal_context_sigKill, signalInterrupt_Kill, 1, (void*)last_pcb->syscall_args[1]); 



            //ZioS: se la maschera è già stata impostata ad un segnale simile oppure quel segnale è servito in quel momento, mi fermo
            if (last_pcb->signals == DSOS_SIGKILL || last_pcb->signal_served[DSOS_SIGKILL] == 1){
            }
                
            //ZioS: se la maschera non è già stata impostata, la imposto e metto ad 1 il relativo bit (se necessario)
            else{
                last_pcb->signals = DSOS_SIGKILL;
                if (last_pcb->signal_received[DSOS_SIGKILL] == 0)
                    last_pcb->signal_received[DSOS_SIGKILL] = 1;
            }
        }
    
        else if (waiting_list.first != 0){
            PCB* last_pcb = (PCB*) waiting_list.last;


            // ZioS: impostiamo il contesto per la gestione dei segnali
            //disastrOS_debug("setting entry point for DSOS_SIGMOVUP interrupt... ");
            getcontext(&last_pcb->signal_context_sigMovUp);
            last_pcb->signal_context_sigMovUp.uc_stack.ss_sp = last_pcb->signal_stack;
            last_pcb->signal_context_sigMovUp.uc_stack.ss_size = STACK_SIZE;
            last_pcb->signal_context_sigMovUp.uc_stack.ss_flags = 0;
            last_pcb->signal_context_sigMovUp.uc_link = &main_context;
            makecontext(&last_pcb->signal_context_sigMovUp, signalInterrupt_MovUp, 1, (void*)last_pcb->syscall_args[1]);


            //disastrOS_debug("setting entry point for DSOS_SIGKILL interrupt... ");
            // Gio: il secondo contesto non serve rinizializzarlo ma basta copiare i parametri di quello precedentemente definito
            last_pcb->signal_context_sigKill = last_pcb->signal_context_sigMovUp;
            makecontext(&last_pcb->signal_context_sigKill, signalInterrupt_Kill, 1, (void*)last_pcb->syscall_args[1]); 


            //ZioS: se la maschera è già stata impostata ad un segnale simile oppure quel segnale è servito in quel momento, mi fermo
            if (last_pcb->signals == DSOS_SIGKILL || last_pcb->signal_served[DSOS_SIGKILL] == 1){
            }
                
            //ZioS: se la maschera non è già stata impostata, la imposto e metto ad 1 il relativo bit (se necessario)
            else{
                last_pcb->signals = DSOS_SIGKILL;
                if (last_pcb->signal_received[DSOS_SIGKILL] == 0)
                    last_pcb->signal_received[DSOS_SIGKILL] = 1;
            }
        }
        // ZioS: qui non ci dovrebbe arrivare mai
    }
    else if (disastrOS_time % TIME_MOVUP == 0){
    
        if (ready_list.first != 0){
            PCB* last_pcb = (PCB*) ready_list.last;


            // ZioS: impostiamo il contesto per la gestione dei segnali
            //disastrOS_debug("setting entry point for DSOS_SIGMOVUP interrupt... ");
            getcontext(&last_pcb->signal_context_sigMovUp);
            last_pcb->signal_context_sigMovUp.uc_stack.ss_sp = last_pcb->signal_stack;
            last_pcb->signal_context_sigMovUp.uc_stack.ss_size = STACK_SIZE;
            last_pcb->signal_context_sigMovUp.uc_stack.ss_flags = 0;
            last_pcb->signal_context_sigMovUp.uc_link = &main_context;
            makecontext(&last_pcb->signal_context_sigMovUp, signalInterrupt_MovUp, 1, (void*)last_pcb->syscall_args[1]);


            //disastrOS_debug("setting entry point for DSOS_SIGKILL interrupt... ");
            // Gio: il secondo contesto non serve rinizializzarlo ma basta copiare i parametri di quello precedentemente definito
            last_pcb->signal_context_sigKill = last_pcb->signal_context_sigMovUp;
            makecontext(&last_pcb->signal_context_sigKill, signalInterrupt_Kill, 1, (void*)last_pcb->syscall_args[1]); 

            //ZioS: se la maschera è già stata impostata ad un segnale simile oppure quel segnale è servito in quel momento, mi fermo
            if (last_pcb->signals == DSOS_SIGMOVUP || last_pcb->signal_served[DSOS_SIGMOVUP] == 1){
            }
                
            //ZioS: se la maschera non è già stata impostata, la imposto e metto ad 1 il relativo bit (se necessario)
            else{
                last_pcb->signals = DSOS_SIGMOVUP;
                if (last_pcb->signal_received[DSOS_SIGMOVUP] == 0)
                    last_pcb->signal_received[DSOS_SIGMOVUP] = 1;
            }
        }
    
        else if (waiting_list.first != 0){
            PCB* last_pcb = (PCB*) waiting_list.last;


            // ZioS: impostiamo il contesto per la gestione dei segnali
            //disastrOS_debug("setting entry point for DSOS_SIGMOVUP interrupt... ");
            getcontext(&last_pcb->signal_context_sigMovUp);
            last_pcb->signal_context_sigMovUp.uc_stack.ss_sp = last_pcb->signal_stack;
            last_pcb->signal_context_sigMovUp.uc_stack.ss_size = STACK_SIZE;
            last_pcb->signal_context_sigMovUp.uc_stack.ss_flags = 0;
            last_pcb->signal_context_sigMovUp.uc_link = &main_context;
            makecontext(&last_pcb->signal_context_sigMovUp, signalInterrupt_MovUp, 1, (void*)last_pcb->syscall_args[1]);


            //disastrOS_debug("setting entry point for DSOS_SIGKILL interrupt... ");
            // Gio: il secondo contesto non serve rinizializzarlo ma basta copiare i parametri di quello precedentemente definito
            last_pcb->signal_context_sigKill = last_pcb->signal_context_sigMovUp;
            makecontext(&last_pcb->signal_context_sigKill, signalInterrupt_Kill, 1, (void*)last_pcb->syscall_args[1]); 

            //ZioS: se la maschera è già stata impostata ad un segnale simile oppure quel segnale è servito in quel momento, mi fermo
            if (last_pcb->signals == DSOS_SIGMOVUP || last_pcb->signal_served[DSOS_SIGMOVUP] == 1){
            }
                
            //ZioS: se la maschera non è già stata impostata, la imposto e metto ad 1 il relativo bit (se necessario)
            else{
                last_pcb->signals = DSOS_SIGMOVUP;
                if (last_pcb->signal_received[DSOS_SIGMOVUP] == 0)
                    last_pcb->signal_received[DSOS_SIGMOVUP] = 1;
            }
        }
        // ZioS: qui non di dovrebbe arrivare mai
    }
}