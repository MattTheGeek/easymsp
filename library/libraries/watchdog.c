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

extern inline void stopWatchdog(void)
{
	WDTCTL = WDTPW + WDTHOLD;
}

extern inline void holdWatchdog(void)
{

#if SERIES == 2
	WDTCTL = WDTPW + ((unsigned char)WDTCTL | WDTHOLD);
#elif SERIES == 5
	WDTCTL = WDTPW + (WDTCTL_L | WDTHOLD);
#endif

}

extern inline void clearWatchdog(void)
{

#if SERIES == 2
	WDTCTL = WDTPW + ((unsigned char)WDTCTL | WDTCNTCL);
#elif SERIES == 5
	WDTCTL = WDTPW + (WDTCTL_L | WDTCNTCL);
#endif

}

extern inline void resumeWatchdog(void)
{

#if SERIES == 2
	WDTCTL = WDTPW + ((unsigned char)WDTCTL & ~WDTHOLD);
#elif SERIES == 5
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

#if SERIES == 2

	switch (source)
	{
		case ACLK:
			wdtbits |= WDTSSEL;
		break;

		case SMCLK:
		default:
			_never_executed();
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
			_never_executed();
	}
	
#elif SERIES == 5

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
			_never_executed();
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
			_never_executed();
	}
	
#endif

	WDTCTL = WDTPW + wdtbits;

	return;
}
