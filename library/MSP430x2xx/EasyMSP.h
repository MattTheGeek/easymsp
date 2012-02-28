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
** -------------------------------------------------------------------------*/
#ifndef EASYMSP_H
#define EASYMSP_H

#if __STDC__ != 1
	#error "EasyMSP is not supported with this compiler. Please use a compiler that has support for ANSI C"
#endif

#if __STDC_VERSION__ >= 199901L
	#error "EasyMSP is not supported with this compiler. Please use a compiler that supports C99 C code."
#endif

#define EASYMSPVER 1.0
#define EASYMSPVERMINOR 0
#define EASYMSP

#include <stdint.h>
#include <stdbool.h>

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

#ifndef PORT1
	#define PORT1 1
#endif

#ifndef PORT2
	#define PORT2 2
#endif

#ifndef PORT3
	#define PORT3 3
#endif

/* Flash Settings */

#define FLASH_SETTINGS_BASE         (0x1000 + 64)

#define FLASH_SETTINGS_SIG          (FLASH_SETTINGS_BASE)
#define FLASH_SETTINGS_ENABLED      (FLASH_SETTINGS_BASE + 2)

#define FLASH_SETTINGS_IE1          (FLASH_SETTINGS_BASE + 3)
#define FLASH_SETTINGS_IE2          (FLASH_SETTINGS_BASE + 4)

#define FLASH_SETTINGS_BCSCTL1      (FLASH_SETTINGS_BASE + 5)
#define FLASH_SETTINGS_BCSCTL2      (FLASH_SETTINGS_BASE + 6)
#define FLASH_SETTINGS_BCSCTL3      (FLASH_SETTINGS_BASE + 7)

#define FLASH_SETTINGS_WDTCTL       (FLASH_SETTINGS_BASE + 8)

#define FLASH_SETTINGS_PORT1_DIR    (FLASH_SETTINGS_BASE + 9)
#define FLASH_SETTINGS_PORT1_OUT    (FLASH_SETTINGS_BASE + 10)

#define FLASH_SETTINGS_PORT2_DIR    (FLASH_SETTINGS_BASE + 11)
#define FLASH_SETTINGS_PORT2_OUT    (FLASH_SETTINGS_BASE + 12)

#define FLASH_SETTINGS_PORT3_DIR    (FLASH_SETTINGS_BASE + 13)
#define FLASH_SETTINGS_PORT3_OUT    (FLASH_SETTINGS_BASE + 14)

/*
 *   Start parsing device
 */

/*
 * Flash and RAM sizes are in bytes.
 * This information can be used to determine if a device is suitable for a feature or not.
 * It can also be used to adjust storage requirements for features.
 */

#ifdef MSP430G2553
	#define HASUSCI
	#define HASADC10
	#define HASCOMP
	#define HASTIMER1
	#define RAMSIZE 512
	#define FLASHSIZE 16384
	#define BSL true
#endif

#ifdef MSP430G2452
	#define HASUSI
	#define HASADC10
	#define HASCOMP
	#define RAMSIZE 256
	#define FLASHSIZE 8192
	#define BSL false
#endif

#ifdef MSP430G2231
	#define HASUSI
	#define HASADC10
	#define RAMSIZE 128
	#define FLASHSIZE 2048
	#define BSL false
#endif

#ifdef MSP430G2001
	#define HASCOMP
	#define RAMSIZE 128
	#define FLASHSIZE 512
	#define BSL false
#endif

#ifdef MSP430G2211
	#define HASCOMP
	#define FLASHSIZE 1024
	#define RAMSIZE 128
	#define BSL false
#endif

#ifdef MSP430F2013
#define FLASHSIZE 2048
#define RAMSIZE 128
#define BSL false
#endif

#include <msp430.h>

//Start include required files.
#include "system.h"
#include "io.h"
#include "bcs.h"
#include "timer0.h"
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
	static __interrupt void nonmask_isr(void);
#endif

#include "EasyMSP.c"

#endif
