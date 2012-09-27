/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	EasyMSP.h
 *	Main header for EasyMSP   
 *
 *	Part of the EasyMSP Project
 *	www.code.google.com/p/EasyMSP/
 *
 *	Author: Matthew L. Burmeister
 *	Copyright (c) 2010, 2011, 2012 All rights reserved.
 *
 *	Contact
 *		You can contact me by email at matthewburmeister@gmail.com 
 *		or by sending mail to:
 *
 *		Matthew Burmeister
 *		11593 Autunno St
 *		Las Vegas, NV 89183
 *		United States of America
 *
 *	Licence
 *		EasyMSP is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		EasyMSP is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with EasyMSP. If not, see <http://www.gnu.org/licenses/>.
 *
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

#if (__STDC_VERSION__ == 201112L)
#	if (_EM_VERBOSE == YES)
		asm("	.mmsg	\"C11 or C1X is supported\"	");
#	endif
#endif

/* C Standard library includes */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "core/define.h" /* Include the pre-processor defines for EasyMSP */
#if !(defined OPTIONS)
#	include "core/config.h" /* Include the default option file */
#else
#	include #OPTIONS
#endif
	
#if (_EM_BITMASK_LOOKUP == YES)
#	include "core/lookup.c"
	extern const unsigned char bitmaskLookup[8];
#endif /* _EM_BITMASK_LOOKUP */

#if (_EM_EASYTYPES == YES)
#	include "core/easytypes.c"
#endif /* _EM_EASYTYPES */

#include "board.h"
#include "device.h" /* Find out what device to include */
#include "stdinclude.h"
	
#include "core/splash.c" /* Include EasyMSP console splash */

/* Decide if we need to declare function prototypes for runtime functions */
#if (defined NO_SETUP) /*Is NOSETUP not declared? */
#	if (_EM_VERBOSE == YES)
		asm("	.mmsg	\"Excluding loop() and loop logic \"");
#	endif
#else
#	pragma FUNC_NEVER_RETURNS (main);
#	ifdef NO_INIT
#		if (_EM_VERBOSE == YES)
			asm("	.mmsg	\"EasyMSP Runtime setup is disabled. init() and loop() functions excluded \"");
#		endif
#	else
#		pragma RETAIN (init);
#		pragma FUNC_EXT_CALLED (init);
		extern void init(void);
#	endif /* NOINIT */
#	ifdef NO_LOOP
#		if (_EM_VERBOSE == YES)
			asm("	.mmsg	\"Excluding init() function	\"");
#		endif
#	else
#		pragma RETAIN (loop);
#		pragma FUNC_EXT_CALLED (loop);
		void loop(void);
#	endif /* NOLOOP */			
#	ifdef _EM_IS_BOARD
#		pragma RETAIN (_boardInit);
#		pragma FUNC_EXT_CALLED (_boardInit);
		extern inline void _boardInit(void);
#	endif /* _EM_IS_BOARD */
#	include "core/EasyMSP.c"
#endif /* NOSETUP */

#endif /* EASYMSP_H */
