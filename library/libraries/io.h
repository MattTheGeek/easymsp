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
 
#if !(defined _EM_SERIES)
#	error "Device series unknown. io.c requires that the device series is declared in SERIES"
#elif !(defined _EM_EASYMSP)
#	error "io.c requires including the main EasyMSP header file (EasyMSP.h) to operate correctly. Please include EasyMSP.h rather than just incluing this file."
#endif	

#ifndef IO_H
#define IO_H

/* Define constants */

/* PRAGMAs */
#pragma INTERRUPT (port_isr);
#pragma RETAIN (Port1FunctionVector);
#pragma RETAIN (Port2FunctionVector);
#pragma FUNCTION_OPTIONS (pinHigh, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (pinLow, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (pinToggle, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (pinMode, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (pinRead, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (portWrite, "--opt_level=4 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (portWriteDir, "--opt_level=4 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (portRead, "--opt_level=4 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (pinPullUp, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (pinPullDown, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (pinPullOff, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (attachInterrupt, "--opt_level=3 --opt_for_speed=5" );
#pragma FUNCTION_OPTIONS (removeInterrupt, "--opt_level=3 --opt_for_speed=5" );

#if (_EM_SERIES != 5) || (_EM_SERIES != 6)
#	pragma FUNC_IS_PURE (pinDriveStrength);
#	pragma FUNC_IS_PURE (portWriteWord);
#	pragma FUNC_IS_PURE (portWriteDirWord);
#	pragma FUNC_IS_PURE (portReadWord);
#else
#	pragma FUNCTION_OPTIONS (pinDriveStrength, "--opt_level=3 --opt_for_speed=5" );
#	pragma FUNCTION_OPTIONS (portWriteWord, "--opt_level=4 --opt_for_speed=5" );
#	pragma FUNCTION_OPTIONS (portWriteDirWord, "--opt_level=4 --opt_for_speed=5" );
#	pragma FUNCTION_OPTIONS (portReadWord, "--opt_level=4 --opt_for_speed=5" );
#endif 

/* Prototypes */

extern void digitalWrite(unsigned short int, unsigned short int);

extern void pinHigh(unsigned short int);
extern void pinLow(unsigned short int);
extern void pinToggle(unsigned short int);
extern void pinMode(unsigned short int, unsigned short int);
extern bool pinRead(unsigned short int);
extern void pinDriveStrength(unsigned short int, unsigned short int);

extern void pinPullUp(unsigned short int);
extern void pinPullDown(unsigned short int);
extern void pinPullOff(unsigned short int);

extern void portWrite(const unsigned short int, unsigned char);
extern void portWriteDir(const unsigned short int, unsigned char);
extern unsigned char portRead(const unsigned short int);

extern void portWriteWord(const unsigned short int, unsigned short int);
extern void portWriteDirWord(const unsigned short int, unsigned short int);
extern unsigned short int portReadWord(const unsigned short int);

interrupt void port_isr(void);

extern void attachInterrupt(unsigned short int, unsigned short int, void(*)(void));
extern void removeInterrupt(unsigned short int);

extern void shiftConfig(unsigned short int, unsigned short int);
extern void shiftOut(unsigned short int, unsigned short int, unsigned char);

#endif /* IO_H */
