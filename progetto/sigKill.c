#include "disastrOS_constants.h"
#include "disastrOS_globals.h"
#include "signals.h"

void sigKill(){
  // Impostare la maschera del servito

  //attivare la variabile per la sleep (?)
  printf("Eseguo una sigMovKill\n");

  // Resettare la maschera del servito
  // Resettare il segnale ricevuto
  running->signal_received[DSOS_SIGKILL] = 0;

  if (running->signal_received[DSOS_SIGMOVUP] == 1){
    setcontext(&running->signal_context_sigMovUp);
  }
  else
    setcontext(&running->cpu_state);
}