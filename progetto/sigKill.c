#include "disastrOS_constants.h"
#include "disastrOS_globals.h"
#include "signals.h"
#include "disastrOS_syscalls.h"

void sigKill(){
  
  printf("Eseguo una sigKill\n");

  //disastrOS_exit(disastrOS_getpid()+1);
  setcontext(&running->cpu_state);
  
}