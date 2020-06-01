#include "disastrOS_constants.h"
#include "disastrOS_globals.h"
#include "signals.h"
#include "disastrOS_syscalls.h"

void sigKill(){
  // Gio: Impostare la maschera del servito
  running->signal_served[DSOS_SIGKILL] = 1;
  
  printf("Eseguo una sigKill\n");

  // Gio: resetto la maschera del servito
  //running->signal_served[DSOS_SIGKILL] = 0;
  
  disastrOS_exit(disastrOS_getpid()+1);
  setcontext(&running->cpu_state);
  
}