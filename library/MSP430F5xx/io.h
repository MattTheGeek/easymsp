/*
	io.h	Version 1.0A
	IO System Library for 16-bit IO port modules.
		
	Part of the EasyMSP system
	
	This file is under GPL v3
	Copyright Matthew Burmeister 2012. All Rights Reserved.
	
*/

#ifndef HIGH
	#define HIGH 1
#endif

#ifndef LOW
	#define LOW 0
#endif

#ifndef INPUT
	#define INPUT 0
#endif

#ifndef OUTPUT 
	#define OUTPUT 1
#endif

#ifndef PORTA
	#define PORTA 'A'
#endif

#ifndef PORTB
	#define PORTB 'B'
#endif

#ifndef PORTC
	#define PORTC 'C'
#endif

#ifndef PORTD
	#define PORTD 'D'
#endif

#ifndef PORTE
	#define PORTE 'E'
#endif

#ifndef PORTF
	#define PORTF 'F'
#endif

#ifndef PORTJ
	#define PORTJ 'J'
#endif

inline void high(const unsigned short int);
inline void low(const unsigned short int);
inline void pinMode(const unsigned short int, unsigned short int);
inline unsigned short int read(const unsigned short int);
void portWriteByte(unsigned short int, unsigned char);

