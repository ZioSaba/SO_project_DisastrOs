#include "disastrOS.h"
#include "disastrOS_constants.h"

// Gio: definisco delle macro per gestire gli intervalli a cui invio i segnali
#define TIME_KILL   50
#define TIME_MOVUP  30

// Gio: definisco le funzioni che utilizziamo
void sigMovUp();
void sigKill();
void signalMakeContext(PCB* proc_pcb, int signal_number);
void signalInterrupt_Kill();
void signalInterrupt_MovUp();