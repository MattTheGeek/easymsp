
asm("	.mmsg	\"Using board: LaunchPad\"");

#define REDLED 0
#define GREENLED 6
#define BUTTON 3

#ifndef _EM_IS_BOARD
#	define _EM_IS_BOARD
#endif

inline void _boardInit(void)
{
	return; /* Empty function */
}
