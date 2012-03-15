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

inline void high(unsigned short int);
inline void low(unsigned short int);
inline void digitalWrite(unsigned short int, unsigned short int);
inline void pinMode(unsigned short int, unsigned short int);
inline bool read(unsigned short int);

#if SERIES == 2
	
	#ifndef NO_PORT_ISR

		static void (*PortFunctionVector[15])(void) = {NULL};

		static __interrupt void port1_isr(void);
		static __interrupt void port2_isr(void);
	
		void attachInterrupt(unsigned short int, unsigned short int, void (*)());
		void removeInterrupt(unsigned short int);

	#endif

#endif

#if SERIES == 5

	void portWriteByte(unsigned short int, unsigned char);
	void portWrite(unsigned short int, unsigned short int);
	
#endif

#include "io.c"

#endif
