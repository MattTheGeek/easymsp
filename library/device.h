#ifndef DEVICE_H
#define DEVICE_H

#if (defined MSP430F5510) || (defined __MSP430F5510__) || (defined  __MSP430F5510)
#	include "device/msp430f5510.h"

#	if (VERBOSE == YES)
		asm("	.mmsg	\"Device is MSP430F5510\"");
#	endif
		
#elif (defined MSP430G2553) || (defined __MSP430G2553__) || (defined __MSP430G2553) 
#	include "device/msp430g2553.h"
		
#	if (VERBOSE == YES)
		asm("	.mmsg	\"Device is MSP430G2553\"");
#	endif
		
#elif (defined MSP430G2452) || (defined __MSP430G2452__) || (defined __MSP430G2452)
#	include "device/msp430g2452.h"
		
#	if (VERBOSE == YES)
		asm("	.mmsg	\"Device is MSP430G2452\"");
#	endif
		
#elif (defined MSP430G2231) || (defined __MSP430G2231__) || (defined __MSP430G2231)
#	include "device/msp430g2231.h"
		
#	if (VERBOSE == YES)
		asm("	.mmsg	\"Device is MSP430G2231\"");
#	endif

#elif (defined MSP430G2211) || (defined __MSP430G2211__) || (defined __MSP430G2211)
#	include "device/msp430g2211.h"
		
#	if (VERBOSE == YES)
		asm("	.mmsg	\"Device is MSP430G2211\"");
#	endif
		
#else
#	error "EasyMSP is not supported with this device. Please double check your define."
#endif

#if (VERBOSE == YES)
		
#	if (SERIES == 1)
		asm("	.mmsg	\"Series is F1xx line. \"");
#	elif (SERIES == 2)
		asm("	.mmsg	\"Series is F2xx line OR G2xx Value Line. \"");
#	elif (SERIES == 3)
		asm("	.mmsg	\"Series is F3xx line. \"");
#	elif (SERIES == 4)
		asm("	.mmsg	\"Series is F4xx line. \"");
#	elif (SERIES == 5)
		asm("	.mmsg	\"Series is F5xx Performance line. \"");
#	elif (SERIES == 6)
		asm("	.mmsg	\"Series is F6xx Performance line. \"");
#	elif (SERIES == 'FRAM')
		asm("	.mmsg	\"Series is FRAM Line \"");
#	elif (SERIES == 'VOLVERINE')
		asm("	.mmsg	\"Series is VOLVERINE \"");
#	endif

#	ifdef __MSP430X__
		asm("	.mmsg	\"Using MSP430X (eXtended) CPU code\"");
#	else
		asm("	.mmsg	\"Using MSP430 (Standard) CPU code\"");
#	endif
#endif
		
#include <msp430.h>

#endif
