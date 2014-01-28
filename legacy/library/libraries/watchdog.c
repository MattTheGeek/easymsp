/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	watchdog.c
 *	C Library for the MSP430 Watchdog+
 *  For All MSP430 devices. 
 *
 *	Part of the EasyMSP Project
 *	www.code.google.com/p/EasyMSP/
 *
 *	Author: Matthew L. Burmeister
 *	Copyright (c) 2010, 2011, 2012 All rights reserved.
 *
 *	Contact
 *		You can contact me by email at matthewburmeister@gmail.com 
 *		or by sending mail to:
 *
 *		Matthew Burmeister
 *		11593 Autunno St
 *		Las Vegas, NV 89183
 *		United States of America
 *
 *	Licence
 *		EasyMSP is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		EasyMSP is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with EasyMSP. If not, see <http://www.gnu.org/licenses/>.
 *
*/


extern void watchdogState(unsigned short int operation)
{
	static unsigned char _watchdogStatePending;
	static unsigned char _watchdogState;
	
	if (operation == RESTORE && _watchdogStatePending == YES)
	{
		WDTCTL = WDTPW + _watchdogState;
		_watchdogStatePending = NO;
		return;
	}
	else if (operation == STORE)
	{
		
#if (_EM_SERIES == 5) || (_EM_SERIES == 6) 
		_watchdogState = WDTCTL_L;
#else
		_watchdogState = (unsigned char)(WDTCTL); /* Trim off watchdog password and save the watchdog state */
#endif
		WDTCTL = WDTPW + WDTHOLD;
		_watchdogStatePending == YES;
		return;
	}
	else
	{
		return;
	}
}
 
extern void disableWatchdog(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	return;
}
 
extern void stopWatchdog(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	return;
}

extern void holdWatchdog(void)
{

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')
	WDTCTL = WDTPW + ((8 >> WDTCTL) | WDTHOLD);
#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)
	WDTCTL = WDTPW + (WDTCTL_L | WDTHOLD);
#endif
	return;
}

extern void clearWatchdog(void)
{

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')
	WDTCTL = WDTPW + ((8 >> WDTCTL) | WDTCNTCL);
#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)
	WDTCTL = WDTPW + (WDTCTL_L | WDTCNTCL);
#endif
	return;
}

extern void resumeWatchdog(void)
{

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')
	WDTCTL = WDTPW + ((8 >> WDTCTL) & ~WDTHOLD);
#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)
	WDTCTL = WDTPW + (WDTCTL_L & ~WDTHOLD);
#endif
	return;
}

extern void resetWatchdog(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	return;
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
