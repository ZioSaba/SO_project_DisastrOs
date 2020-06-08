#include "disastrOS.h"
#include "disastrOS_constants.h"

#define TIME_KILL   50
#define TIME_MOVUP  30

ucontext_t signal_main_context;

void sigMovUp();
void sigKill();
void signalMakeContext(PCB* proc_pcb, int signal_number);