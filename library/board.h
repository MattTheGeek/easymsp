/* If a board was declared, include related defines and settings */
#if (defined OLIMEXINO5510) == 1 || (defined OLIMEXINO_5510) == 1 || (defined OLIMEXINO-5510) == 1
#	include "board/olimexino-5510.h"
#elif (defined MSP430F5510STK) == 1
#	include "board/msp430f5510stk.h"
#elif (defined LAUNCHPAD) == 1
#	include "board/launchpad.h"
#endif
