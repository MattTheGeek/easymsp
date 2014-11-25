#ifndef TIMEOUT_H
#	define TIMEOUT_H

static unsigned short int _timeoutValue;

void timeoutSet(unsigned short int);
unsigned short int timeout(void);

#include "timeout.c"

#endif
