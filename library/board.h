/* If a board was declared, include related defines and settings */
#if (defined OLIMEXINO5510) == 1 || (defined OLIMEXINO_5510) == 1 || (defined OLIMEXINO-5510) == 1
#	include "board/olimexino-5510.h"
#endif

#ifdef MSP430F5510STK
#	include "board/msp430f5510stk.h"
#endif

#ifdef LAUNCHPAD
#	include "board/launchpad.h"
#endif
