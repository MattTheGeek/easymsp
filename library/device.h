/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	device.h
 *	Preprocessor file for selecting device versions.
 *  For All MSP430 devices. 
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

#ifndef DEVICE_H
#define DEVICE_H

#if (defined MSP430F5510) || (defined __MSP430F5510__) || (defined  __MSP430F5510)
#	include "device/msp430f5510.h"

#	if (_EM_VERBOSE == YES)
		asm("	.mmsg	\"Device is MSP430F5510\"");
#	endif

#elif (defined MSP430F5529) || (defined __MSP430F5529__) || (defined __MSP430F5529)
	#include "device/msp430f5529.h"

#	if (_EM_VERBOSE == YES)
		asm("	.mmsg 	\"Device is MSP430F5529	\"");
#	endif

#elif (defined MSP430G2553) || (defined __MSP430G2553__) || (defined __MSP430G2553) 
#	include "device/msp430g2553.h"
		
#	if (_EM_VERBOSE == YES)
		asm("	.mmsg	\"Device is MSP430G2553\"");
#	endif
		
#elif (defined MSP430G2452) || (defined __MSP430G2452__) || (defined __MSP430G2452)
#	include "device/msp430g2452.h"
		
#	if (_EM_VERBOSE == YES)
		asm("	.mmsg	\"Device is MSP430G2452\"");
#	endif
		
#elif (defined MSP430G2231) || (defined __MSP430G2231__) || (defined __MSP430G2231)
#	include "device/msp430g2231.h"
		
#	if (_EM_VERBOSE == YES)
		asm("	.mmsg	\"Device is MSP430G2231\"");
#	endif

#elif (defined MSP430G2211) || (defined __MSP430G2211__) || (defined __MSP430G2211)
#	include "device/msp430g2211.h"
		
#	if (_EM_VERBOSE == YES)
		asm("	.mmsg	\"Device is MSP430G2211\"");
#	endif
		
#else
#	error "EasyMSP is not supported with this device. Please double check your config."
#endif

#if (_EM_VERBOSE == YES)
		
#	if (_EM_SERIES == 1)
		asm("	.mmsg	\"Series is F1xx line. \"");
#	elif (_EM_SERIES == 2)
		asm("	.mmsg	\"Series is F2xx line \"");
#	elif (_EM_SERIES == 3)
		asm("	.mmsg	\"Series is F3xx line. \"");
#	elif (_EM_SERIES == 4)
		asm("	.mmsg	\"Series is F4xx line. \"");
#	elif (_EM_SERIES == 5)
		asm("	.mmsg	\"Series is F5xx Performance line. \"");
#	elif (_EM_SERIES == 6)
		asm("	.mmsg	\"Series is F6xx Performance line. \"");
#	elif (_EM_SERIES == 'F')
		asm("	.mmsg	\"Series is FRAM Line \"");
#	elif (_EM_SERIES == 'C')
		asm("	.mmsg	\"Series is CC430 RF SoC \"");
#	elif (_EM_SERIES == 'W')
		asm("	.mmsg	\"Series is VOLVERINE \"");
#	elif (_EM_SERIES == 'V')
		asm("	.mmsg	\"Series is G2xx Value Line. \""); 
#	endif

#	ifdef __MSP430X__
		asm("	.mmsg	\"Using MSP430X (eXtended) CPU code\"");
#	else
		asm("	.mmsg	\"Using MSP430 (Standard) CPU code\"");
#	endif
#endif
		
#include <msp430.h>
		

#ifdef __MSP430_HAS_PORTA_R__  
#	define _EM_HASPORTA 
#endif 

#ifdef __MSP430_HAS_PORTB_R__ 
#	define _EM_HASPORTB
#endif
		
#ifdef __MSP430_HAS_PORTC_R__
#	define _EM_HASPORTC
#endif

#ifdef __MSP430_HAS_PORT1_R__  
#	define _EM_HASPORT1  
#endif 

#ifdef __MSP430_HAS_PORT2_R__ 
#	define _EM_HASPORT2
#endif
		
#ifdef __MSP430_HAS_PORT3_R__
#	define _EM_HASPORT3
#endif
			
#ifdef __MSP430_HAS_WDT__   	
#	define _EM_HASWDT
#endif

#ifdef __MSP430_HAS_ADC10__  
#	define _EM_HASADC10
#endif
		
#ifdef __MSP430_HAS_BC2__
#	define _EM_HASBCS
#endif
		
#ifdef __MSP430_HAS_UCS__
#	define _EM_HASUCS
#endif

#ifdef __MSP430_HAS_CAPLUS__
#	define _EM_HASCOMPA
#endif
		
#ifdef __MSP430_HAS_FLASH2__ 
#	define _EM_HASFLASH
#endif
			   
#ifdef __MSP430_HAS_USCI__ 
#	define _EM_HASUSCI
#endif
			   
#ifdef __MSP430_HAS_TA3__ 
#	define _EM_HAST0A3
#endif
			   
#ifdef __MSP430_HAS_T1A3__ 
#	define _EM_HAST1A3
#endif
			  

#if (_EM_SERIES == 5 || _EM_SERIES == 6 || _EM_SERIES == 'W') 
#	define _EM_HAS_WORD_PORTS == YES
#else
#	define _EM_HAS_WORD_PORTS == NO
#endif			  

#endif
