#include "disastrOS_constants.h"
#include "disastrOS_globals.h"
#include "signals.h"

void sigMovUp(){
  // Impostare la maschera del servito

  //attivare la variabile per la sleep (?)
  printf("Eseguo una sigMovUp\n");

  // Resettare la maschera del servito
  // Resettare il segnale ricevuto
  running->signal_received[DSOS_SIGMOVUP] = 0;

  if (running->signal_received[DSOS_SIGKILL] == 1)
    setcontext(&running->signal_context_sigKill);
  
  else
    setcontext(&running->cpu_state);
}