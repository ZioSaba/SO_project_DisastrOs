//qui me la gestisco
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"

// Gio: il timer invia il segnale di kill o sposta in testa l'ultimo processo a seconda del valore del quanto temporale
void internal_signal(){
    if (disastrOS_time % 50 == 0){
        printf("INVIO SIGKILL\n");
    }
    else if (disastrOS_time % 10 == 0){
        printf("INVIO SIGMOVUP\n");
    }
}