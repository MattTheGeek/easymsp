void board_init()
{
	/*
		Way to simple...
	*/
	
	asm("	.mmsg board_init() added to program");

	P1DIR &= ~BIT3;
	P1REN |= BIT3;
	P1OUT |= BIT3;
	
	return;
}
	
	
