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

 /* The WDTCTL register and bitwise operations.
  * It seems like password protected registers do not like to be ORed, NANDed, and NOTed, As this would change the watchdog password and cause a system reset.
  * So it is wise to perform bitwise operations before commiting to the WDTCTL register.
  *
  * Save WDTCTL data
  * Since WDTCTL holds more than just a watchdog, We need to be careful not to change any data we don't need to.
  *
  * WDTCTL timer interrupt is maskable.
  * One thing to think about when using the watchdog as a timer is that it's interrupts can be masked.
  * Make sure to enable global interrupts and set the watchdog interrupt enable bit in the interrupt enable 1 register.
  *
  * Clear before Setting
  * It's a good thing to clear the watchdog count register before changing settings, Otherwise, You might end up with a PUC when you do change it.
  */

  #if SERIES == 2
  
/*

bool detectWatchdog(void)
{
    auto unsigned char tempwdt = (unsigned char)WDTCTL;

	WDTCTL = WDTPW + (tempwdt | WDTHOLD);

	if((unsigned char)WDTCTL > 0) //Values were stored, So a watchdog must exist.
	{
		return(true); //Yes, We do have a watchdog!
	}
	else
	{
		return(false); //Nope, A watchdog does no exist OR isn't the right watchdog on the MCU
	}
}

*/

void holdWatchdog(void)
{
    auto unsigned short int tempwdt = (unsigned char)WDTCTL;
	WDTCTL = WDTPW + (tempwdt | WDTHOLD);
	return;
}

unsigned short int startWatchdog(unsigned short int source, unsigned short int interval)
{
	WDTCTL = WDTPW + WDTHOLD;
	auto unsigned short int watchdogbits = WDTHOLD | WDTCNTCL;

	if(clocksource == ACLK)
	{
		watchdogbits |= WDTSSEL;
	}
	else
	{
		if (clocksource != SMCLK)
		{
			return(1);
		}
	}

	switch (divider)
	{
		case 64:
			watchdogbits |= WDTIS_3;
			break;


		case 512:
			watchdogbits |= WDTIS_2;
			break;


		case 8912:
			watchdogbits |= WDTIS_1;
			break;


		case 32768:
			//Do nothing.
			break;

		default:
			return(2);
	}

	WDTCTL = WDTPW | watchdogbits; //Commit

	return(0);
}


void resetWatchdog(void)
{
	WDTCTL = WDTPW;
	return;
}

void clearWatchdog(void)
{
	WDTCTL = WDTPW + ((unsigned char)WDTCTL | WDTCNTCL);
	return;
}

void holdWatchdogTimer(void)
{
	WDTCTL = WDTPW + ((unsigned char)WDTCTL | WDTHOLD);
	return;
}

unsigned short int startWatchdogTimer(unsigned short int source, unsigned short int interval, void (*function)())
{
	WDTCTL = WDTPW + WDTHOLD;
	auto unsigned short int watchdogbits = WDTTMSEL | WDTCNTCL;

	if(clocksource == ACLK)
	{
		watchdogbits |= WDTSSEL;
	}
	else
	{
		if (clocksource != SMCLK)
		{
			return(1);
		}
	}

	switch (divider)
	{
		case 64:
			watchdogbits |= WDTIS_3;
			break;


		case 512:
			watchdogbits |= WDTIS_2;
			break;


		case 8912:
			watchdogbits |= WDTIS_1;
			break;

		case 32768:
			//Do nothing
			break;

		default:
			return(2);
	}

		IE1 |= WDTIE;

	#ifndef NO_WDT_ISR
		watchdogFunctionToCall = function;
	#endif

	WDTCTL = WDTPW | watchdogbits; //Start Watchdog timer.

	return(0);

}

void resetWatchdogTimer(void)
{
	WDTCTL = WDTPW + ((unsigned char)WDTCTL | WDTTMSEL);
	return;
}

void resetPinMode(unsigned short int mode, unsigned short int edge)
{
	if (mode == NMI)
	{
		WDTCTL = WDTPW + ((unsigned char)WDTCTL | WDTNMI);
	}
	else
	{
		WDTCTL = WDTPW + ((unsigned char)WDTCTL & ~WDTNMI);
	}

	if (edge == FALLING)
	{
		WDTCTL = WDTPW + ((unsigned char)WDTCTL | WDTNMIES);
	}
	else
	{
		WDTCTL = WDTPW + ((unsigned char)WDTCTL & ~WDTNMIES);
	}

	return;
}

//=================
#ifndef NO_WDT_ISR
	#pragma vector=WDT_VECTOR
	static __interrupt void watchdog_timer_isr(void)
	{
			(*watchdogFunctionToCall)();
	}
#endif 

#endif

#if SERIES == 5


unsigned short int startWatchdog(enum clocks source, enum div interval)
{
	WDTCTL = WDTPW + (WDTHOLD | WDTCNTCL);
	
	switch (source)
	{
		case SMCLK:

		break;
		
		case ACLK:
			WDTCTL = WDTPW + (WDTCTL_L | WDTSSEL_1);
		break;
		
		case VLOCLK:
			WDTCTL = WDTPW + (WDTCTL_L | WDTSSEL_2);
		break;
		
		case XCLK:
			WDTCTL = WDTPW + (WDTCTL_L | WDTSSEL_3);
		break;
		
		default:
			return(1);
	}
	
	switch (interval)
	{
		case by_64:
			WDTCTL = WDTPW + (WDTCTL_L | WDTIS_7);
		break;
		
		case by_512:
			WDTCTL = WDTPW + (WDTCTL_L | WDTIS_6);
		break;
		
		case by_8192:
			WDTCTL = WDTPW + (WDTCTL_L | WDTIS_5);
		break;
		
		case by_32K:
			WDTCTL = WDTPW + (WDTCTL_L | WDTIS_4);
		break;
		
		case by_512K:
			WDTCTL = WDTPW + (WDTCTL_L | WDTIS_3);
		break;
		
		case by_8192K:
			WDTCTL = WDTPW + (WDTCTL_L | WDTIS_2);
		break;
		
		case by_128M:
			WDTCTL = WDTPW + (WDTCTL_L | WDTIS_1);
		break;
		
		case by_2G:
			/* Do nothing */
		break;
		
		default:
			return(2);
	}
	
	WDTCTL = WDTPW + (WDTCTL_L & ~WDTHOLD);
	
	return (0);

}

#endif
