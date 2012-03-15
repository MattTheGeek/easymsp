#ifndef USCI_H
#define USCI_H

#define UCA 'A'
#define UCB 'B'

#ifndef RISING_EDGE
	#define RISING_EDGE 1
#endif

#ifndef FALLING_EDGE
	#define FALLING_EDGE 2
#endif

#ifndef FALLING
#define FALLING FALLING_EDGE
#endif

#ifndef RISING
#define RISING RISING_EDGE
#endif

unsigned short int spiConfig(unsigned short int, unsigned short int, unsigned short int, unsigned short int);
void spiSetSpeed(unsigned short int, unsigned short int);
void spiOut(unsigned short int, unsigned char);
void spiString(unsigned short int,unsigned char*);
unsigned char spiIn(unsigned short int);
void usciOff(unsigned short int);

#include "usci.c"

#endif
