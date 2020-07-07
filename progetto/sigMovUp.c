#include "disastrOS_constants.h"
#include "disastrOS_globals.h"
#include "signals.h"

void sigMovUp(){
  
  // ZioS: setto a true la variabile relativa al segnale per dimezzarne lo sleepTime
  printf("Eseguo una sigMovUp!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  running->movUp = true;

}