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
            PCB* last_proc = (PCB*) ready_list.last;
            printf("L'ultimo processo nella ready_list è il %d\n", last_proc->pid);
            ListHead stack = last_proc->signal_stack;
            printf("INVIATO DALLA READY_LIST\n");
        }
        else if (waiting_list.first != 0){
            PCB* last_proc = (PCB*) waiting_list.last;
            printf("L'ultimo processo nella waiting_list è il %d\n", last_proc->pid);
            ListHead stack = last_proc->signal_stack;
            printf("INVIATO DALLA WAITING_LIST\n");
            if (stack.last == 0)   printf("STACK VUOTO\n");
            int* j = malloc(sizeof(ListItem));
            *j = 4;
            List_insert(&stack, last_proc->signal_stack.last, (ListItem*) j);
        }
        else{
            printf("ONLY 1 PROCESS ON THE MACHINE");
        }
        //printf("Inviato un SIGKILL al processo: %d \n", last_proc->pid);
        //List_insert(&(last_proc->signal_stack), (ListItem*) last_proc->signal_stack.last, (ListItem*)DSOS_SIGKILL);
    }
    else if (disastrOS_time % 10 == 0){
        if (ready_list.first != 0){
            PCB* last_proc = (PCB*) ready_list.last;
            printf("L'ultimo processo nella ready_list è il %d\n", last_proc->pid);
        }
        else if (waiting_list.first != 0){
            PCB* last_proc = (PCB*) waiting_list.last;
            printf("L'ultimo processo nella waiting_list è il %d\n", last_proc->pid);
        }
        else{
            printf("ONLY 1 PROCESS ON THE MACHINE");
        }

        //PCB* last_proc = (PCB*) waiting_list.last;
        //printf("L'ultimo processo in esecuzione è il %d\n", last_proc->pid);
        //printf("Inviato un SIGMOVUP al processo: %d \n", last_proc->pid);
        //List_insert(&(last_proc->signal_stack), (ListItem*) last_proc->signal_stack.last, (ListItem*)DSOS_SIGMOVUP);
    }
}