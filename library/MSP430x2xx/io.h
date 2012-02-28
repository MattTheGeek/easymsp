/*
 * io.c
 * EasyMSP GPIO Library for MSP430Gxxxx devices.
 * Version 1.0.0
 *
 *
 *
 *
 */

#ifndef IO_H
#define IO_H

#ifndef PULLUP
	#define PULLUP 1
#endif

#ifndef PULLDOWN
	#define PULLDOWN 0
#endif

#ifndef HIGH_TO_LOW
	#define HIGH_TO_LOW 1
#endif

#ifndef LOW_TO_HIGH
	#define LOW_TO_HIGH 0
#endif

#define port1Write(data) (P1OUT = data)
#define port2Write(data) (P2OUT = data)
#define port3Write(data) (P3OUT = data)

#define port1Direction(data) (P1DIR = data)
#define port2Direction(data) (P2DIR = data)
#define port3Direction(data) (P3DIR = data)

#define port1Read() return(P1IN)
#define port2Read() return(P2IN)
    #ifdef HASPORT3
        #define port3Read() return(P3IN)
    #endif

#define port1High(pin) (P1OUT |= (1 << pin))
#define port2High(pin) (P2OUT |= (1 << pin))
    #ifdef HASPORT3
        #define port3High(pin) (P3OUT |= (1 << pin))
    #endif

	
#ifndef NO_PORT_ISR

	static void (*PortFunctionVector[15])(void) = {NULL};

	static __interrupt void port1_isr(void);
	static __interrupt void port2_isr(void);
	
	void attachInterrupt(unsigned short int, unsigned short int, void (*)());
	void removeInterrupt(unsigned short int);

#endif

void high(unsigned short int);
void high_z(unsigned short int);
void low(unsigned short int);
void input(unsigned short int);
void output(unsigned short int);

bool read(unsigned short int);

void enableResistor(unsigned short int, unsigned short int);
void disableResistor(unsigned short int);

#include "io.c"

#endif
