/*
 * adc10.h
 * 10 Bit Analog To Digital Converter (ADC10) Library
 *
 * 
 * Written by: Matthew Burmeister
 *
 */
#ifndef ADC10_H
#define ADC10_H 
 
#ifndef INVERTED
	#define INVERTED 0
#endif

#ifndef TRUE
	#define TRUE 1
#endif

#ifndef TWOCOMP
	#define TWOCOMP 1
#endif 

#ifndef BINARY
	#define BINARY 0
#endif

#ifndef HOLD64
	#define HOLD64 4
#endif

#ifndef HOLD32
	#define HOLD32 3
#endif

#ifndef HOLD16
	#define HOLD16 2
#endif

#ifndef HOLD4
	#define HOLD4 1
#endif

#ifndef DEFAULT
	#define DEFAULT 0
#endif

#ifndef INTERNAL
	#define INTERNAL 1
#endif

#ifndef INTERNAL1V5
	#define INTERNAL1V5 2
#endif

#ifndef INTERNAL2V56
	#define INTERNAL2V56 3
#endif

#ifndef EXTERNAL
	#define EXTERNAL 4
#endif

//Prototypes
unsigned short int analogRead(unsigned short int); //10Bit analog value
unsigned char analogReadByte(unsigned short int); //8Bit analog value

void analogOff(void);
void analogReference(unsigned short int);
void analogConfig(unsigned short int, unsigned short int, unsigned short int);

//Vars

#include "adc10.c"

#endif

