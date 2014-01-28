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

#define ADC10_CONFIGURED_FLAG (1 << 1)
 
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
extern unsigned short int analogRead(unsigned short int); //10Bit analog value

#if (_EM_SERIES == 5) || (_EM_SERIES == 6)

extern unsigned char analogReadByte(unsigned short int); //8Bit analog value

#endif

extern inline void analogOff(void);
extern void analogReference(unsigned short int);
extern void analogConfig(unsigned short int, unsigned short int, unsigned short int);

static unsigned short int adc10ConfigBits = NULL;

#pragma INTERRUPT(adc10_isr);
interrupt void adc10_isr(void);

#endif /* ADC10_H */

