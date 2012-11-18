/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	EasyMSP.c
 *	EasyMSP Runtime system
 *  
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
