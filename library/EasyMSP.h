/***
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 *                                                 
 */

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
 ** Copyright (c) 2010, 2011, 2012 All rights reserved.
 ** -------------------------------------------------------------------------
*/

#ifndef EASYMSP_H
#define EASYMSP_H

#if !(defined  __MSP430__)
#	error "This compiler does not support the MSP430 architecture and thus, does not support EasyMSP."
#elif !(defined __STDC__)
#	error "This compiler does not support standard C and thus, does not support EasyMSP."
#elif (defined __GNUC__) && !(defined __TI_COMPILER_VERSION__)
#	warning "This compiler may not be compatible with EasyMSP. Exercise caution, as unexpected, surprising, and or dangerous code may be generated."
#endif

#include "define.h"

#include "config.h"

#if (ASCII_LOGO == YES) && (VERBOSE == YES)
/* EasyMSP ASCII art logo */
asm("   .mmsg   \" ___    _    ___ __   __ __  __  ___  ___  \"");
asm("   .mmsg   \"| __|  /_\\  / __|\\ \\ / /|  \\/  |/ __|| _ \\ \"");
asm("   .mmsg   \"| _|  / _ \\ \\__ \\ \\ V / | |\\/| |\\__ \\|  _/ \"");
asm("	.mmsg	\"|___|/_/ \\_\\|___/  |_|  |_|  |_||___/|_|   \"");
#else
asm("	.mmsg	\"EasyMSP\"");
#endif

#if (VERBOSE == YES)
asm("	.mmsg	\"Copyright (c) 2010 - 2012 Matthew L. Burmeister. All Rights Reserved\"");
asm("	.mmsg	\"EasyMSP is compiling...\"");
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#if (EASYTYPES == YES)
typedef char byte;
typedef unsigned short int word;
typedef bool boolean;
typedef char BYTE;
typedef unsigned short int WORD;
typedef bool BOOLEAN;
#endif

#include "board.h"
#include "device.h" /* Find out what device to include */
#include "stdinclude.h"

#ifndef NOSETUP
#	pragma FUNC_NEVER_RETURNS ( main );

#	ifndef NOINIT
extern void init(void);
#	endif

#	ifndef NOLOOP
extern void loop(void);
#	endif

#	ifdef ISBOARD
extern inline void _boardInit(void);
#	endif
#else
#	if (VERBOSE == YES)
		asm("	.mmsg	\"EasyMSP is not doing runtime setup\"");
#	endif
#endif

#if (SERIES == 2)
#		pragma INTERRUPT (nmi_isr);
#		pragma FUNC_EXT_CALLED (nmi_isr);

void interrupt nmi_isr(void);

#elif (SERIES == 5)
#		pragma INTERRUPT (user_nmi_isr);
#		pragma INTERRUPT (sys_nmi_isr);
#		pragma FUNC_EXT_CALLED (user_nmi_isr);
#		pragma FUNC_EXT_CALLED (sys_nmi_isr);

void interrupt user_nmi_isr(void);
void interrupt sys_nmi_isr(void);
#endif

/*===========================================*/

#include "EasyMSP.c"

#endif
