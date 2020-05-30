#include<stdio.h>
#include<stdlib.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"

void sigKill(){
    // impostare la maschera del servito

    //far terminare il processo
    printf("Eseguo una sigKill\n");

    // Resettare la maschera del servito
    // Resettare il segnale ricevuto
}