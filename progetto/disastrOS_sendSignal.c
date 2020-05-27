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
        }
    
        else if (waiting_list.first != 0){
        }
        // ZioS: qui non ci dovrebbe arrivare mai
    }
    else if (disastrOS_time % 10 == 0){
    
        if (ready_list.first != 0){
        }
    
        else if (waiting_list.first != 0){
        }
        // ZioS: qui non di dovrebbe arrivare mai
    }
}