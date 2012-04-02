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

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "define.h" /* Include preprocessor constants and macros */
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

#endif

#if SERIES == 2
#		pragma INTERRUPT (nmi_isr);
#		pragma FUNC_EXT_CALLED (nmi_isr);

		void interrupt nmi_isr(void);

#elif SERIES == 5
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
