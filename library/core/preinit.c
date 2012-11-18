/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	preinit.c
 *	Presetup functions for EasyMSP.
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

#pragma RETAIN (_preinit);
#pragma RETAIN (_clockinit);
#pragma RETAIN (_preinit);
#pragma RETAIN (_dmainit);

inline void _preinit(void);
inline void _clockinit(void);
inline void _portinit(void);

inline void _dmainit(void);

inline void _preinit(void)
{
	_portinit();
	_clockinit();
	
	_enable_interrupts();
	
#if (defined _EM_HASDMA) /* Does the device have a DMA. If yes, configure it. */
	_dmainit(); /* Let write/read CPU instructions finish before halting for DMA transfer */
#endif /* HASDMA */

#if (defined _EM_IS_BOARD) /* Will EasyMSP be running on a board such as a OLIMEXINO or LaunchPad? */
/* If yes, we call _initBoard() which should be located in the board description header in the directory board. */
	_boardInit();
#endif /* ISBOARD */

	return;
}

inline void _clockinit(void)
{
	return;
}

inline void _portinit(void)
{
#if (_EM_SERIES == 5) || (_EM_SERIES == 6)
	
#	ifdef __MSP430_HAS_PORTA_R__
	PADIR = 0xFFFF;
	PAOUT = 0x0000;
#	endif
	
#	ifdef __MSP430_HAS_PORTB_R__
	PBDIR = 0xFFFF;
	PBOUT = 0x0000;
#	endif
	
#	ifdef __MSP430_HAS_PORTC_R__
	PCDIR = 0xFFFF;
	PCOUT = 0x0000;
#	endif
	
#	ifdef __MSP430_HAS_PORTD_R__
	PDDIR = 0xFFFF;
	PDOUT = 0x0000;
#	endif
	
#	ifdef __MSP430_HAS_PORTE_R__
	PEDIR = 0xFFFF;
	PEOUT = 0x0000;
#	endif
	
#	ifdef __MSP430_HAS_PORTF_R__
	PFDIR = 0xFFFF;
	PFOUT = 0x0000;
#	endif
	
#	ifdef __MSP430_HAS_PORTJ_R__
	PJDIR = 0xFFFF;
	PJOUT = 0x0000;
#	endif
#else
#	ifdef __MSP430_HAS_PORT1_R__
	P1DIR = 0xFF;
	P1OUT = 0x00;
#	endif
	
#	ifdef __MSP430_HAS_PORT2_R__
	P2DIR = 0xFF;
	P2OUT = 0x00;
#	endif
	
#	ifdef __MSP430_HAS_PORT3_R__
	P3DIR = 0xFF;
	P3OUT = 0x00;
#	endif
	
#	ifdef __MSP430_HAS_PORT4_R__
	P4DIR = 0xFF;
	P4OUT = 0x00;
#	endif
	
#	ifdef __MSP430_HAS_PORT5_R__
	P5DIR = 0xFF;
	P5OUT = 0x00;
#	endif
	
#	ifdef __MSP430_HAS_PORT6_R__
	P6DIR = 0xFF;
	P6OUT = 0x00;
#	endif
	
#	ifdef __MSP430_HAS_PORT7_R__
	P7DIR = 0xFF;
	P7OUT = 0x00;
#	endif
	
#	ifdef __MSP430_HAS_PORT8_R__
	P8DIR = 0xFF;
	P8OUT = 0x00;
#	endif
	
#	ifdef __MSP430_HAS_PORT9_R__
	P9DIR = 0xFF;
	P9OUT = 0x00;
#	endif
	
#	ifdef __MSP430_HAS_PORT10_R__
	P10DIR = 0xFF;
	P10OUT = 0x00;
#	endif
	
#	ifdef __MSP430_HAS_PORT11_R__
	P11DIR = 0xFF;
	P11OUT = 0x00;
#	endif
#endif
	return;
}

inline void _dmainit(void)
{
#if (defined _EM_HASDMA) /* Does the device have a DMA. If yes, configure it. */
	
#endif
	return;
}
