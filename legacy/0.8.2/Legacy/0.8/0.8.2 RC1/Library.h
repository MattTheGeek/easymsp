/*
	Copyright 2011 Matthew Burmeister. All rights reserved.
*/

/*/
	Introduction
		Put introduction here
*/

/*
	Change Log
		List changes here
*/

/*	Functions

		Function list
*/

/*
	Legal
		Because this work is a beta, a restrictive license is used to prevent use in Commercial uses and to
	prevent remixing of untested work. Please use at your own risk.
	
	This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License. 
	To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/3.0/ or send a letter
	to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
	
*/

#include <stdint.h>

#define I2C 1
#define SPI 2
#define NONE 0

#define MSBFIRST 1
#define LSBFIRST 0

#define HIGH 1
#define LOW 0

#define FILTERON 1
#define FILTEROFF 0
#define YES 1
#define NO 0
#define EXTERN 9
#define DIODE 6
#define VDDHALF 7
#define VDDQUATER 8

#define M16 6
#define M12 12
#define M8 8
#define M1 1
#define K500 2
#define K100 10
#define K12 15

#define DEFAULT 1
#define INTERNAL 2
#define INTERNAL1V1 3
#define INTERNAL2V56 4
#define EXTERNAL 5

#define FASTCLOCK 1
#define SLOWCLOCK 0

#define FALLING_EDGE 1
#define RISING_EDGE 0

//Function Macros
//========================================================================================================================

#define constrain(x, min, max)   if(x > max) { x = max; } else if(x < min) { x = min; }
#define map(x, in_min, in_max, out_min, out_max) ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
#define min(x, max_value)  if((x) > max_value) { (x) = max_value; }
#define max(x, min_value)  if((x) < min_value) { (x) = min_value; }
#define bit(n)             (1 << n)
#define bitClear(x, n)     x &= ~bit(1)
#define bitSet(x, n)       x |= bit(1)
#define bitRead(x, n)      ((x & bit(1)) >> n)
#define bitWrite(x, n, b)  if(!b) { bitClear(x, n); } else { bitSet(x, n); }
#define lowByte(x)         ((unsigned char)(x & 0xFF))
#define highByte(x)        ((unsigned char)(x >> 8))

//========================================================================================================================



//Device Check
//========================================================================================================================
/*
	alright, here we check to see if the device selected is supported or not. If a device is not supported or has not been
	added, a error will occur.
	
	Current devices supported are:
	
	Value Line
		MSP430G2131
		MSP430G2211
		MSP430G2231
		MSP430G2553
	
	2xx Series
		MSP430F2012
		
*/

#ifdef MSP430G2231

	#define HASUSI
	#define HASADC10
	#define supported
	
#endif

#ifdef MSP430G2131

	#define HASUSI
	#define HASADC10
	#define supported
	
#endif

#ifdef MSP430G2211

	#define HASCOMP
	#define supported
	
#endif


#ifdef MSP430G2553

	#define HASADC10
	#define HASCOMP
	#define HASUSCI
	#define HASPORT3
	#define HASFULLUCS
	#define TWOTIMERAS
	#define supported
	
#endif

#ifdef MSP430F2012 

	#define HASADC10
	#define HASFULLUCS
	#define USI
	#define supported
	
#endif

#ifndef supported

	#error "Fatal Error: This device is not supported or defined."
	#error "Perhaps you forgot to include your device?"
	
#endif

#include <MSP430.h> //And we include the MSP430.h

//=======================================================================================================================




//Function Prototypes
//========================================================================================================================
/*
	Just declaring some prototypes.
*/


//Your basic prototypes

//Main System
static inline void setup();
static inline void stopwd();
static inline void reset();
static inline void shutdown();
static void sleep(unsigned int time, unsigned int mode);

//Delays
static inline void delayus(register unsigned int time);
static inline void _us(void);
static inline void delayms(register unsigned int time);
static inline void delaysec(register unsigned int time);

//Software SPI
static void shiftOut(unsigned int DOUT, unsigned int SCLK, unsigned int bitorder, char data);
static char shiftIn(unsigned int DIN, unsigned int SCLK, unsigned int bitorder);

//WDT
extern void WDT_int();

static unsigned int analogRead(unsigned int pin);
static void analogReference(unsigned int ref);

#endif


#ifdef HASUSCI //Do we have a USCI?


static void enableTimer(unsigned int clocksource, unsigned int divs);
static void disableTimer();
static unsigned char timerEnabled = 0;

static void hspiConfig(int bitorder, int clockphase, int clockpol);
static void hspiOut(char data);
static char hspiIn(void);

static void hi2cConfig();
static void hi2cOut(unsigned char);
static unsigned char hi2cIn();

static void uartConfig();
static void uartOut();
static unsigned char uartIn();

static void releaseUSCI()

#endif



#ifdef HASUSI //Do we have a USI?


static void hspiConfig(unsigned int bitorder, unsigned int clockspeed, unsigned int pol, unsigned int phase);
static void hspiOut(unsigned char);
static unsigned char hspiIn();

static void releaseUSI(void);

static void hi2cConfig();
static void hi2cOut(unsigned char);
static unsigned char hi2cIn();


#endif



#ifdef HASCOMP //Do we have a OP COMP?
	
static void compareConfig(unsigned int, unsigned int, unsigned int);
static unsigned int compare(unsigned int pin);
	
#endif


//This next preprocessors are for future functions

#ifdef TWOTIMERAS

#endif


#ifdef ADC12

#endif


#ifdef SD16

#endif

#include "Library.c"

