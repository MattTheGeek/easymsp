/*
 * watchdog.c
 * Watchdog library source code
 *
 * Written by:
 * Matthew Burmeister
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

extern inline void disableWatchdog(void)
{
	WDTCTL = WDTPW + WDTHOLD;
}
 
extern inline void stopWatchdog(void)
{
	WDTCTL = WDTPW + WDTHOLD;
}

extern inline void holdWatchdog(void)
{

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')
	WDTCTL = WDTPW + ((unsigned char)WDTCTL | WDTHOLD);
#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)
	WDTCTL = WDTPW + (WDTCTL_L | WDTHOLD);
#endif

}

extern inline void clearWatchdog(void)
{

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')
	WDTCTL = WDTPW + ((unsigned char)WDTCTL | WDTCNTCL);
#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)
	WDTCTL = WDTPW + (WDTCTL_L | WDTCNTCL);
#endif

}

extern inline void resumeWatchdog(void)
{

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')
	WDTCTL = WDTPW + ((unsigned char)WDTCTL & ~WDTHOLD);
#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)
	WDTCTL = WDTPW + (WDTCTL_L & ~WDTHOLD);
#endif

}

extern inline void resetWatchdog(void)
{
	WDTCTL = WDTPW + WDTHOLD;
}

extern void watchdogStart(unsigned short int source, unsigned short int interval)
{
	auto unsigned char wdtbits = NULL;

	WDTCTL = WDTPW + (WDTHOLD | WDTCNTCL);

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')

	switch (source)
	{
		case ACLK:
			wdtbits |= WDTSSEL;
		break;

		case SMCLK:
		default:
			break;
	}

	switch (interval)
	{
		case by_8192:
			wdtbits |= WDTIS_1;
			break;

		case by_512:
			wdtbits |= WDTIS_2;
			break;

		case by_64:
			wdtbits |= WDTIS_3;
			break;

		case by_32768:
		default:
			break;
	}
	
#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)

	switch (source)
	{
		case ACLK:
		wdtbits |= WDTSSEL_1;
		break;

		case VLOCLK:
		wdtbits |= WDTSSEL_2;
		break;

		case XCLK:
		wdtbits |= WDTSSEL_3;
		break;

		case SMCLK:
		default:
			break;
	}
	
	switch (interval)
	{
		case by_128m:
			wdtbits |= WDTIS_1;
			break;

		case by_8192k:
			wdtbits |= WDTIS_2;
			break;

		case by_512k:
			wdtbits |= WDTIS_3;
			break;

		case by_32k:
			wdtbits |= WDTIS_4;
			break;

		case by_8192:
			wdtbits |= WDTIS_5;
			break;

		case by_512:
			wdtbits |= WDTIS_6;
			break;

		case by_64:
			wdtbits |= WDTIS_7;
			break;

		case by_2g:
		default:
			break;
	}
	
#endif

	WDTCTL = WDTPW + wdtbits;

	return;
}

extern void watchdogTimerStart(unsigned short int source, unsigned short int interval, void (*function)())
{
	auto unsigned char wdtbits = WDTTMSEL;

	WDTCTL = WDTPW + (WDTHOLD | WDTCNTCL);

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')

	switch (source)
	{
		case ACLK:
			wdtbits |= WDTSSEL;
		break;

		case SMCLK:
		default:
			break;
	}

	switch (interval)
	{
		case by_8192:
			wdtbits |= WDTIS_1;
			break;

		case by_512:
			wdtbits |= WDTIS_2;
			break;

		case by_64:
			wdtbits |= WDTIS_3;
			break;

		case by_32768:
		default:
			break;
	}
	
#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)

	switch (source)
	{
		case ACLK:
		wdtbits |= WDTSSEL_1;
		break;

		case VLOCLK:
		wdtbits |= WDTSSEL_2;
		break;

		case XCLK:
		wdtbits |= WDTSSEL_3;
		break;

		case SMCLK:
		default:
			break;
	}
	
	switch (interval)
	{
		case by_128m:
			wdtbits |= WDTIS_1;
			break;

		case by_8192k:
			wdtbits |= WDTIS_2;
			break;

		case by_512k:
			wdtbits |= WDTIS_3;
			break;

		case by_32k:
			wdtbits |= WDTIS_4;
			break;

		case by_8192:
			wdtbits |= WDTIS_5;
			break;

		case by_512:
			wdtbits |= WDTIS_6;
			break;

		case by_64:
			wdtbits |= WDTIS_7;
			break;

		case by_2g:
		default:
			break;
	}
	
#endif

	WatchdogFunctionVector = function;

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')
	IFG1 &= ~WDTIFG;
	IE1 |= WDTIE;
#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)
	SFRIFG1 &= ~WDTIFG;
	SFRIE1 |= WDTIE;
#endif

	WDTCTL = WDTPW + wdtbits; /* Commit watchdog settings */

	return;
}

#pragma vector = WDT_VECTOR
void interrupt watchdog_isr(void)
{
	(*WatchdogFunctionVector)();
	return;
}
