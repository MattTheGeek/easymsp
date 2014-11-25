#ifndef LAUNCHPAD_H
#	define LAUNCHPAD_H
#ifndef NO_BOARD_DEF

#	ifndef BOARD
#		define BOARD LAUNCHPAD
#	endif

asm("	.mmsg Including board specific symbols");

#	define LED1 0
#	define LED2 6
#	define REDLED 0
#	define GREENLED 6

#	define BUTTON 3

#	define TXPIN 1
#	define RXPIN 2

#else
	asm("	.mmsg NO_BOARD_DEF was defined, NOT adding board specific symbols");
#endif

void board_init();

#	include "launchpad.c"
#else
	asm("	.wmsg	launchpad.h already included ");
#endif
