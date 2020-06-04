#include "disastrOS_constants.h"
#include "disastrOS_globals.h"
#include "signals.h"

void sigMovUp(){
  

  // ZioS: setto a true la variabile relativa al segnale
  printf("Eseguo una sigMovUp\n");
  running->movUp = true;

  // ZioS: verifico se nel frattempo ho ricevuto un segnale di sigKill
  /*if (running->signal_received[DSOS_SIGKILL] == 1)
    setcontext(&running->signal_context_sigKill);
  
  else
    setcontext(&running->cpu_state);
  */
  
}