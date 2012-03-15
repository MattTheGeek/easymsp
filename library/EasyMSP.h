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
** EasyMSP.h
** Primary library include file
**
** Author: Matthew L. Burmeister
** Copyright (c) 2011 All rights reserved.
** -------------------------------------------------------------------------
** */
#ifndef EASYMSP_H
#define EASYMSP_H

#ifndef __STDC__
	# error "EasyMSP is not supported with this compiler. Please use a compiler that has support for ANSI C."
#endif

#if __STDC_VERSION__ >= 199901L
	# error "EasyMSP is not supported with this compiler. Please use a compiler that supports C99 C code."
#endif

#ifndef SKIPGCCCHECK
	#ifdef __GNUC__
		# error "EasyMSP is not supported with this gcc. Please define SKIPGCCCHECK if you still want to contiune."
	#endif
#endif

#define EASYMSPVER 1_0
#define EASYMSPVERMINOR 0
#define EASYMSP

#ifndef NULL
	#define NULL 0
#endif

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

#ifndef LSBFIRST
	#define LSBFIRST 0
#endif

#ifndef MSBFIRST
	#define MSBFIRST 1
#endif

#ifndef YES
	#define YES 1
#endif

#ifndef NO
	#define NO 0
#endif

#ifndef ON
	#define ON 1
#endif

#ifndef OFF
	#define OFF 0
#endif

typedef enum clocks
{
	MCLK = 1,
	SMCLK = 2,
	ACLK = 3,
	MODOSC = 4,
	DCOCLK = 5,
	REFOCLK = 6,
	XT1CLK = 7,
	XT2CLK = 8,
	VLOCLK = 9,
	XCLK = 10
} clock;

enum port
{
	A,
	B,
	C,
	D,
	E,
	F,
	J
} port;

enum div
{
	by_1,
	by_2,
	by_4,
	by_8,
	by_16,
	by_32,
	by_64,
	by_512,
	by_8192,
	by_32K,
	by_512K,
	by_8192K,
	by_128M,
	by_2G

};

enum pins
{
	a0 = 0,
	a1 = 1,
	a2 = 2,
	a3 = 3,
	a4 = 4,
	a5 = 5,
	a6 = 6,
	a7 = 7,
	b0, b1, b2, b3, b4, b5, b6, b7,
	c0, c1, c2, c3, c4, c5, c6, c7,
	d0, d1, d2, d3, d4, d5, d6, d7,
	e0, e1, e2, e3, e4, e5, e6, e7,
	f0, f1, f2, f3, f4, f5, f6, f7,
	j0, j1, j2, j3, j4, j5, j6, j7
} pin;

enum crystalDriveStrength
{
	upTo8Mhz = 	1,
	upTo16Mhz = 2,
	upTo24Mhz = 3,
	upTo32Mhz = 4
};



/*
 *   Start parsing device
 */

/*
 * Flash and RAM sizes are in bytes.
 * This information can be used to determine if a device is suitable for a feature or not.
 * It can also be used to adjust storage requirements for features.
 */

#ifdef MSP430G2553
	#define SERIES 2
	#define RAMSIZE 512
	#define FLASHSIZE 16384
	#define BSL true
	
	#define HASUSCI
	#define HASADC10
	#define HASCOMP
	#define HASTIMER1
	
	#define HASPORT1
	#define HASPORT2
	#define HASPORT3
	
#endif

#ifdef MSP430G2452

	#define SERIES 2
	#define RAMSIZE 256
	#define FLASHSIZE 8192
	#define BSL false
	
	#define HASUSI
	#define HASADC10
	#define HASCOMP
	
	#define HASPORT1
	#define HASPORT2
	
#endif

#ifdef MSP430G2231

	#define SERIES 2
	#define RAMSIZE 128
	#define FLASHSIZE 2048
	#define BSL false
	
	#define HASUSI
	#define HASADC10
	
	#define HASPORT1
	#define HASPORT2

#endif

#ifdef MSP430G2001

	#define SERIES 2
	#define RAMSIZE 128
	#define FLASHSIZE 512
	#define BSL false
	
	#define HASCOMP
	
	#define HASPORT1
	#define HASPORT2
	
#endif

#ifdef MSP430G2211

	#define SERIES 2
	#define FLASHSIZE 1024
	#define RAMSIZE 128
	#define BSL false
	
	#define HASCOMP
		
	#define HASPORT1
	#define HASPORT2
	
#endif

#ifdef MSP430F2013

	#define SERIES 2
	#define FLASHSIZE 2048
	#define RAMSIZE 128
	#define BSL false
	
	#define HASSD16
	
	#define HASPORT1
	#define HASPORT2
	
#endif

#ifdef MSP430F5510

	#define SERIES 5
	#define FLASHSIZE 32768
	#define RAMSIZE 4096
	
	#define HASPORTA
	#define HASPORTB
	#define HASPORTC

#endif

#include <stdint.h>
#include <stdbool.h>
#include <msp430.h>
#include "io.h"
#include "system.h"

#if SERIES == 2
	#include "bcs.h"
#endif

#if SERIES == 5
	#include "ucs.h"
#endif

#include "timer.h"
#include "watchdog.h"
#include "flash.h"

//Do we need other drivers?
#ifdef HASUSI
	#include "usi.h"
#endif

#ifdef HASUSCI
	#include "usci.h"
#endif

#ifdef HASADC10
	#include "adc10.h"
#endif

#ifdef HASCOMP
	#include "comp.h"
#endif

#ifdef HASTIMER1
	#include "timer1.h"
#endif

#ifndef NOSETUP
	extern void init(void);
	extern void loop(void);
#endif

#ifndef CUSTOM_NMI
	static interrupt void nonmask_isr(void);
#endif

/*===========================================*/

#include "EasyMSP.c"

#endif
