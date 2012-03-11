/* 
	EasyMSP Main Library
	
	Include this file to include the EasyMSP Library for all device and board variants 
	
*/

#define YES 1
#define NO 0

#define LIBRARY5 Library\MSP430x5xx

#ifdef BOARD

	#if BOARD == OLIMEXINO5510
		#include <Board\olimexino5510.h>	
		
	#elif BOARD == MSP430F5510STK
		#include <Board\msp430f5510stk.h>			

	#elif BOARD == EZ430F2013
		#include <Board\f2013target.h>	
				
	#elif BOARD == EZ430F2012
		#include <Board\f2012target.h>	
			
	#else
				#error "Could not find the development board: "  + BOARD
	#endif

#endif /* Done searching for boards, Start looking for the declared device */


#ifdef MSP430G2553
	#include <device/msp430g2553.h>

#elif defined MSP430G2452
	#include <device/msp430g2452.h>

#elif defined MSP430G2231
	#include <device/msp430g2231.h>

#elif defined MSP430G2211
	#include <device/msp430g2211.h>

#elif defined MSP430G2001
	#include <device/msp430g2001.h>
		
#elif defined MSP430F2012
	#include <device/msp430f2012.h>

#elif defined MSP430F2013
	#include <device/msp430f2013.h>

#elif defined MSP430F5510
	#include <device/msp430f5510.h>

#else
	#error "Unsupported or invaild device declared. Aborting build.
#endif

#ifndef SERIES
	#error "Device series not defined."
#endif

#if SERIES == 5 || SERIES == 6
	
	#include <LIBRARY5\system.h>
	#include <LIBRARY5\wdt.h>
	#include <LIBRARY5\io.h>
	#include <LIBRARY5\ucs.h>
	#include <LIBRARY5\usci.h>
	#include <LIBRARY5\crc16.h>
	#include <LIBRARY5\dma.h>
	#include <LIBRARY5\timer.h>
	#include <LIBRARY5\rtca.h>
	#include <LIBRARY5\ref.h>
	#include <LIBRARY5\adc10.h>
	#include <LIBRARY5\comp.h
	
#endif
	
	
