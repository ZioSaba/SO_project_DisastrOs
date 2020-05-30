#include<stdlib.h>
#include<stdio.h>
#include "disastrOS.h"
#include "disastrOS_syscalls.h"

void sigMovUp(){
    // Impostare la maschera del servito

    //attivare la variabile per la sleep (?)
    printf("Eseguo una sigMovUp\n");

    // Resettare la maschera del servito
    // Resettare il segnale ricevuto
}