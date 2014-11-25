#ifndef SYSTEM_H
#	define SYSTEM_H

void panic (unsigned short int *);
void emergency (unsigned short int *);

unsigned short int getInterruptState();
void setInterruptState();

void setRegister(unsigned short int, unsigned short int);
unsigned short int readRegister(unsigned short int);


#include "system.c"

#else
asm("	.wmsg	system.h was already included in build");
#endif
/* SYSTEM_H */
