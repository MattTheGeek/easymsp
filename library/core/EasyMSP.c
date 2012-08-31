/*
 * EasyMSP.c
 * One of the core libraries to EasyMSP. This is what executes EasyMSP programs.
 *
 * Written by:
 * Matthew Burmeister
 * Copyright 2011 All Rights Reserved.
 *
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
 *
 */
 
#ifndef NO_SETUP

#include "preinit.c"
#include "nmiisr.c"

volatile unsigned char _EM_Status = _EM_EXECUTE;

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD; /* Halt the watchdog before it issues a PUC */
	/* Configure system before passing control to user init() */
	_preinit();	
		
#ifndef NO_INIT
	init();
#endif /* NOINIT */

#ifndef NO_LOOP
	
	do
	{
		loop();
	}
	while ((_EM_Status & _EM_EXECUTE) > 0);
	
#endif /* NOLOOP */

	disableInterrupts();
	_low_power_mode_4();
}


#endif /* NOSETUP */
