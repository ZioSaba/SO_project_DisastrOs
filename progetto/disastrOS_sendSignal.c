// Gio: definisco il file contenente la syscall per l'invio dei segnali 
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"

// Gio: il timer invia il segnale di kill o sposta in testa l'ultimo processo a seconda del valore del quanto temporale
void internal_signal(){
    if (disastrOS_time % 50 == 0){
    
        if (ready_list.first != 0){
            PCB* last_pcb = (PCB*) ready_list.last;

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
    else if (disastrOS_time % 10 == 0){
    
        if (ready_list.first != 0){
            PCB* last_pcb = (PCB*) ready_list.last;

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