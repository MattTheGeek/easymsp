/*
 * System.c
 *
 *
 *
 */

#if (defined _EM_HAS_BCS)
 
extern void clockState(unsigned short int state)
{
	static unsigned char _clockStatePending;
	static unsigned char _clockState[4];
	
	
	if (operation == RESTORE && _clockStatePending == YES)
	{
		DCOCTL = _clockState[0];
		BCSCTL1 = _clockState[1];
		BCSCTL2 = _clockState[2];
		BCSCTL3 = _clockState[3];
		
		_clockStatePending = NO;
		
		return;
	}
	else if (operation == STORE)
	{
		_clockState[0] = DCOCTL;
		_clockState[1] = BCSCTL1;
		_clockState[2] = BCSCTL2;
		_clockState[3] = BCSCTL3;
		
		_clockStatePending = YES;
		
		return;
	}
	else
	{
		return;
	}
}

#elif (defined _EM_HAS_UCS)

extern void clockState(unsigned short int state)
{
	static unsigned char _clockStatePending;
	static unsigned short int _clockState[4];
	
	
	if (operation == RESTORE && _clockStatePending == YES)
	{
		DCOCTL = _clockState[0];
		BCSCTL1 = _clockState[1];
		BCSCTL2 = _clockState[2];
		BCSCTL3 = _clockState[3];
		
		_clockStatePending = NO;
		
		return;
	}
	else if (operation == STORE)
	{
		_clockState[0] = DCOCTL;
		_clockState[1] = BCSCTL1;
		_clockState[2] = BCSCTL2;
		_clockState[3] = BCSCTL3;
		
		_clockStatePending = YES;
		
		return;
	}
	else
	{
		return;
	}
}

#end
 
extern void powerMode(unsigned short int mode)
{
	switch (mode)
	{
		case 0:
			_low_power_mode_0();
			break;

		case 1:
			_low_power_mode_1();
			break;

		case 2:
			_low_power_mode_2();
			break;

		case 3:
			_low_power_mode_3();
			break;

		case 4:
			_low_power_mode_4();
			break;

		default:
			break;
	}
}

inline void exitPowerMode(void)
{
	asm("	BIC.W #0xF0, 0(SP)");
	return;
}

inline void powerModeOff(void)
{
	asm("	BIC.W #0xF0, 0(SP)");
	return;
}

extern inline void reset(void)
{

#if _EM_SERIES == 2
	WDTCTL = 0; //Cause a PUC
#elif _EM_SERIES == 5
	PMMCTL0 = PMMPW + PMMSWPOR;
#else
	return;
#endif

}

extern inline void shutdown(void)
{

#if (_EM_SERIES == 2)
	powerMode(4);
#elif (_EM_SERIES == 5)
	powerMode(4);
#endif

}

extern inline void disableInterrupts(void)
{
	_disable_interrupts();
	
#ifdef _EM_CPU39_BUG
		/* Compiler already includes the workaround. */
		_no_operation(); /* Work around for CPU39 bug */		
#endif
}

extern inline void enableInterrupts(void)
{
	_enable_interrupts();
}

extern inline void swapBytes(register unsigned short int* data)
{

#ifdef __MSP430X__
	asm ("	swpbx.w	@r12	");
#else
	asm	("	swpb.w	@r12	");
#endif

}

extern void delayCycles(register volatile unsigned short int cycles)
{

#ifndef __MSP430X__
	asm("	sub		#26,	r12		");
	asm("delay_cycles_loop:			");
	asm("	sub.w	#4,	r12			");
	asm("	nop						");
	asm("	jc	delay_cycles_loop	");
	asm("	inv		r12				");
	asm("	rla		r12				");
	asm("	add.w	r12, PC			");
	asm("	nop						");
	asm("	nop						");
	asm("	nop						");
#else
	/* TODO: Write cycle adjusted code for CPUX MSP430s */
	asm("	sub		#26,	r12		");
	asm("delay_cycles_loop:			");
	asm("	sub.w	#4,	r12			");
	asm("	nop						");
	asm("	jc	delay_cycles_loop	");
	asm("	inv		r12				");
	asm("	rla		r12				");
	asm("	add.w	r12, PC			");
	asm("	nop						");
	asm("	nop						");
	asm("	nop						");
#endif
	return;
}

extern void inline delaySec(register unsigned short int time)
{
	/* todo: Write correct delay loop */
}

extern void inline delayms(register unsigned short int time)
{
	/* todo: Write correct delay loop */
}

extern void inline delayus(register unsigned short int time)
{
	do
	{
		delayCycles(16);
		time--;
	}
	while (time);
}
