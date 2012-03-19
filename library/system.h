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

/* todo: Clean up header */

#ifndef SYSTEM_H
#define SYSTEM_H

/*
 system.h defines
 */

/*
 system.h macros
 */

inline void enterAM(void);

inline void enterLPM0(void);

inline void enterLPM1(void);

inline void enterLPM2(void);

inline void enterLPM3(void);

inline void enterLPM4(void);

inline void reset(void);

inline void shutdown(void);

void inline delaySec(register unsigned short int);

void inline delayms(register unsigned short int);

void inline delayus(register unsigned short int);

void shiftOut(unsigned short int, unsigned short int, unsigned short int,
		unsigned char);

unsigned char shiftIn(unsigned short int, unsigned short int,
		unsigned short int);

void serialOut(unsigned short int, unsigned short int, unsigned char);

#endif
