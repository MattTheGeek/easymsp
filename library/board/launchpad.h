
asm("	.mmsg	\"Using board: LaunchPad\"");

#define REDLED 0
#define GREENLED 6
#define BUTTON 3

#ifndef _EM_IS_BOARD
#	define _EM_IS_BOARD
#endif

inline void _boardInit(void)
{
#	if (_EM_INIT_BOARD_GPIO == YES)
#		if (_EM_VERBOSE == YES)
			asm("	.mmsg	\"Launchpad LEDs and Button pre-initialised for use. See _EM_INIT_BOARD_GPIO in the config documentation\"	");
#		endif

		P1DIR |= (0x01 | 0x40);
		P1REN |= 0x08;
		P1OUT |= 0x08;
		
#	endif
	
	return; 
}
