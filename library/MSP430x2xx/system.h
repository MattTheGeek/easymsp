/* ---------------------------------------------------------------------------
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
** system.h
** Provides functions or related functions to control the system 
**
** Author: Matthew L. Burmeister
** Copyright (c) 2011 All rights reserved.
** -------------------------------------------------------------------------*/

#ifndef SYSTEM_H
#define SYSTEM_H

/*
	system.h defines
*/


/*
	system.h macros
*/

	#define stopwd() WDTCTL = WDTPW + WDTHOLD
	#define shutdown() asm("	bis.w	#0xF0,	SR")
	#define reset() WDTCTL = NULL

	#define enterAM() (asm("	bic.w	 #0xF0,	0(SP)"))

	#define enterLPM0() asm("	bis.w	#0x10,	SR")
	#define enterLPM1() asm("	bis.w	#0x50,	SR")
	#define enterLPM2() asm("	bis.w	#0x90,	SR")
	#define enterLPM3() asm("	bis.w	#0xD0,	SR")
	#define enterLPM4() asm("	bis.w	#0xF0,	SR")
	
	#define enableInterrupts() asm("	EINT	")
	#define disableInterrupts() asm("	DINT	")
	
	#define _usK125() _delay_cycles(16 / 8)
	#define _usK500() _delay_cycles(16 / 2)
	#define _usM1() _delay_cycles(16)
	#define _usM2() _delay_cycles(16 * 2)
	#define _usM4() _delay_cycles(16 * 4)
	#define _usM6() _delay_cycles(16 * 6)
	#define _usM8() _delay_cycles(16 * 8)
	#define _usM10() _delay_cycles(16 * 10)
	#define _usM12() _delay_cycles(16 * 12)
	#define _usM16() _delay_cycles(16 * 16)
/*
	system.h varibles
*/

	static volatile bool lowPowerMode = 0;

/*
	External includes
*/

	extern void high(unsigned short int);
	extern void low(unsigned short int);
	extern void input(unsigned short int);
	extern void output(unsigned short int);
	extern bool read(unsigned short int);
	
/*
	System control functions
*/

//These have been mostly moved to preprocessor macros.

/*
	Memory Access
*/
	unsigned short int ramRead(unsigned short int);
	unsigned short int ramCopy(unsigned short int, unsigned short int, unsigned short int);

/*
	Timing functions
*/

	void inline delaySec(register unsigned short int);
	void inline delayms(register unsigned short int);
	void inline delayus(register unsigned short int);

/*
	Misc. Functions
*/

	void shiftOut(unsigned short int DOUT, unsigned short int SCLK, unsigned short int bitorder, unsigned char data);
	unsigned char shiftIn(unsigned short int DIN, unsigned short int SCLK, unsigned short int bitorder);

/* 
	Source include
*/

#include "system.c"
	
#endif
