/*
 * System.c
 *
 *
 *
 */

extern inline void powerMode(unsigned short int mode)
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
			_never_executed();
	}
}

extern inline void powerModeOff(void)
{
	_low_power_mode_off_on_exit();
}

extern inline void reset(void)
{

#if SERIES == 2
	WDTCTL = 0; //Cause a PUC
#elif SERIES == 5
	PMMCTL0 = PMMPW + PMMSWPOR;
#else
	return;
#endif

}

extern inline void shutdown(void)
{

#if SERIES == 2
	powerMode(4);
#elif SERIES == 5
	powerMode(4);
#endif

}

extern inline void disableInterrupts(void)
{
	_disable_interrupts();
	_no_operation(); /* Work around for CPU39 bug */
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
	/* todo: Write correct delay loop */
}
