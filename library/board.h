/* If a board was declared, include related defines and settings */
#if defined OLIMEXINO5510 || defined OLIMEXINO_5510 || defined OLIMEXINO-5510
#	include "board/olimexino-5510.h"

#elif defined MSP430F5510STK
#	include "board/msp430f5510stk.h"

#elif defined LAUNCHPAD
#	include "board/launchpad.h"
#endif
