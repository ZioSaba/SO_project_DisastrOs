// Gio: definisco il file contenente la syscall per l'invio dei segnali 
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"

// Gio: il timer invia il segnale di kill o sposta in testa l'ultimo processo a seconda del valore del quanto temporale
void internal_signal(){

    // Gio: invia un segnale sigKill
    if (disastrOS_time % 50 == 0){

        //ZioS: se la maschera è già stata impostata ad un segnale simile oppure quel segnale è servito in quel momento, mi fermo
        if (running->signals_mask == DSOS_SIGKILL || running->signal_served[DSOS_SIGKILL] == 1)
            return;
        
        //ZioS: se la maschera non è già stata impostata, la imposto e metto ad 1 il relativo bit (se necessario)
        else{
            running->signals_mask == DSOS_SIGKILL;
            if (running->signal_received[DSOS_SIGKILL] == 0)
                running->signal_received[DSOS_SIGKILL] == 1;
        }
    }

    // Gio: invia un segnale sigMovUp
    else if (disastrOS_time % 10 == 0){

        //ZioS: se la maschera è già stata impostata ad un segnale simile oppure quel segnale è servito in quel momento, mi fermo
        if (running->signals_mask == DSOS_SIGMOVUP || running->signal_served[DSOS_SIGMOVUP] == 1)
            return;
        
        //ZioS: se la maschera non è già stata impostata, la imposto e metto ad 1 il relativo bit (se necessario)
        else{
            running->signals_mask == DSOS_SIGMOVUP;
            if (running->signal_received[DSOS_SIGMOVUP] == 0)
                running->signal_received[DSOS_SIGMOVUP] += 1;
        }
    }
}