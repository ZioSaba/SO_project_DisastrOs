#include "disastrOS.h"
#include "disastrOS_constants.h"


#define TIME_KILL   50
#define TIME_MOVUP  30


void sigMovUp();
void sigKill();
void signalMakeContext();