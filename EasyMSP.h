/* 
	EasyMSP Main Library
	
	Include this file to include the EasyMSP Library for all device and board variants 
	
*/
#ifdef BOARD

	#if BOARD == OLIMEXINO5510
				#include "/board/olimexino5510/boardInfo.h"
	
	#elif BOARD == MSP430F5510STK
				#include "board/msp430f5510stk/boardInfo.h"

	#elif BOARD == EZ430F2013
				#include "board/ez430f2013/boardInfo.h"
				
	#elif BOARD == EZ430F2012
				#include "board/ez430f2012/boardInfo.h"
	
	#else
				#error "Could not find development board: "  + BOARD
	#endif

#endif /* Done searching for boards, Start looking for the declared device */

#ifndef BOARD

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
