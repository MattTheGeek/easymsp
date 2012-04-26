/*
 * io.C
 * Version: 1.1.0A
 * Library for accessing ports
 *
 * Author: Matthew Burmeister
 * Copyright Matthew Burmeister 2011 - 2012. All Rights Reserved.
 *
 * Part of the EasyMSP Project.
 *
 */

/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
 
#ifndef SERIES
#	error "Device series unknown. io.c requires that the device series is declared in SERIES"
#endif

#ifndef __EASYMSP__
#	error "io.c requires including the main EasyMSP header file (EasyMSP.h) to operate correctly. Please include EasyMSP.h rather than just incluing this file."
#endif	

#ifndef IO_H
#define IO_H

/* Define constants */

/* If we have 16 bit ports, we also have 8 bit ports as well. */

#ifdef HASPORTA
#	ifndef	HASPORT1
#		define HASPORT1
#	endif

#	ifndef	HASPORT2
#		define HASPORT2
#	endif
#endif /* HASPORTA */

/* ============ */

#ifdef HASPORTB
#	ifndef HASPORT3
#		define HASPORT3
#	endif

#	ifndef HASPORT4
#		define HASPORT4
#	endif
#endif /* HASPORTB */

/* ============ */

#ifdef HASPORTC
#	ifndef HASPORT5
#		define HASPORT5
#	endif

#	ifndef HASPORT6
#		define HASPORT6
#	endif
#endif /* HASPORTC */

/* ============ */

#ifdef HASPORTD
#	ifndef HASPORT7
#		define HASPORT7
#	endif

#	ifndef HASPORT8
#		define HASPORT8
#	endif
#endif /* HASPORTD */

/* ============ */

#ifdef HASPORTE
#	ifndef HASPORT9
#		define HASPORT9
#	endif

#	ifndef HASPORT10
#		define HASPORT10
#	endif
#endif /* HASPORTE */

/* ============ */

#ifdef HASPORTF
#	ifndef HASPORT11
#		define HASPORT11
#	endif
#endif /* HASPORTF */

/* ============ */

/* Set function level compile options */
#pragma FUNC_NO_GLOBAL_ASG (setHigh);
#pragma FUNCTION_OPTIONS (setHigh, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (setLow, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (pinToggle, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (pinMode, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (readPin, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (portWrite, "--opt_level=4 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (portWriteDir, "--opt_level=4 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (portRead, "--opt_level=4 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (setPullUp, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (setPullDown, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (setPullOff, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (attachInterrupt, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (removeInterrupt, "--opt_level=3 --opt_for_speed=5" );
#if SERIES == 5
#pragma FUNCTION_OPTIONS (setDriveStrength, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (portWriteWord, "--opt_level=4 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (portWriteDirWord, "--opt_level=4 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (portReadWord, "--opt_level=4 --opt_for_speed=5" );
#endif

/* ============ */

inline void portInit(void);

inline void digitalWrite(unsigned short int, unsigned short int);

inline void setHigh(unsigned short int);
inline void setLow(unsigned short int);
inline void pinToggle(unsigned short int);
inline void pinMode(unsigned short int, unsigned short int);
inline bool readPin(unsigned short int);

inline void portWrite(const unsigned short int, unsigned char);
inline void portWriteDir(const unsigned short int, unsigned char);
inline unsigned char portRead(const unsigned short int);

inline void setPullUp(unsigned short int);
inline void setPullDown(unsigned short int);
inline void setPullOff(unsigned short int);

#if SERIES == 5

inline void setDriveStrength(unsigned short int, unsigned short int);
inline void portWriteWord(const unsigned short int, unsigned short int);
inline void portWriteDirWord(const unsigned short int, unsigned short int);
inline unsigned short int portReadWord(const unsigned short int);

#endif

inline void attachInterrupt(unsigned short int, unsigned short int, void(*)(void));
inline void removeInterrupt(unsigned short int);

/* Interrupt ISRs */

/* #pragma FUNC_EXT_CALLED (port1_isr); */
#pragma INTERRUPT (port1_isr);

/* #pragma FUNC_EXT_CALLED (port2_isr); */
#pragma INTERRUPT (port2_isr);

interrupt void port1_isr(void);
interrupt void port2_isr(void);

/* Pin Interrupt function pointers */

/* User interrupt vectors
 *
 * Port1FunctionVector and Port2FunctionVector holds the addresses of user functions to call if a pin triggers a interrupt.
 * As always, they must be void and return nothing. The shorter the function, the better.
 */

void (*Port1FunctionVector[8])(void) =
{	NULL};

void (*Port2FunctionVector[8])(void) =
{	NULL};

#endif /* IO_H */
