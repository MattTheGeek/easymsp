/*
 * EasyMSP.c
 * One of the core libraries to EasyMSP. This is what executes EasyMSP programs.
 *
 * Written by:
 * Matthew Burmeister
 * Copyright 2011 All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */

#ifndef NOSETUP

static volatile bool EasyMSP_Execute = true;

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD; /* Halt the watchdog before it issues a PUC */
	
#ifdef HASDMA /* Does the device have a DMA. If yes, configure it. */
	DMACTL4 = DMARMWDIS; /* Let write/read CPU instructions finish before halting for DMA transfer */
#endif /* HASDMA */

	/*Configure the clock system */
#if defined HASBCS
	/* Configure the Basic clock system */
#elif defined HASUCS
	/* Configure the unified clock system */
#else
	/* The device clock system type is unknown. Issue a error since we cannot continue the build */
#	error "The device clock system type is unknown and EasyMSP cannot continue to build. Please define the correct clock system type."

#endif

#ifdef ISBOARD /* Will EasyMSP be running on a board such as a OLIMEXINO or LaunchPad? */

	/* If yes, we call _initBoard() which should be located in the board description header in the directory board. */
	_boardInit();

#endif /* ISBOARD */

#ifndef NOINIT //If the user has declared NOINIT, then do not include and execute init()
	init(); //Call program init()
#endif /* NOINIT */

#ifndef NOLOOP /* If the user has declared NOLOOP, then do not include and execute loop. Otherwise, include and execute */

	do /* Keep executing loop until a system reset or until EasyMSP_Execute is 0 */
	{
		loop(); //Call program loop
	}
	while (EasyMSP_Execute == true);
	
#endif /* NOLOOP */

	_low_power_mode_4();
}

#if SERIES == 2

#pragma vector=NMI_VECTOR
void interrupt nmi_isr(void)
{
	if ((IFG1 & NMIIFG) > 0)
	{
		IFG1 &= ~NMIIFG; //Clear flag

		/* Handle the NMI */
		return;
	}

	if ((IFG1 & OFIFG) > 0)
	{
		IFG1 &= ~OFIFG; //Clear flag

		/* handle oscilator fault */
		return;
	}

	if ((IFG1 & ACCVIFG) > 0)
	{
		IFG1 &= ~ACCVIFG; //Clear flag

		/* Handle flash access violation. */
		return;
	}

	/* If we get to here, who called this? */
	return;
}

#elif SERIES == 5

#pragma vector=SYSNMI_VECTOR
void interrupt sys_nmi_isr(void)
{
	switch (__even_in_range(SYSSNIV, SYSSNIV_VLRHIFG))
	{
		case SYSSNIV_NONE:

			break;
			
		case SYSSNIV_SVMLIFG:

			break;
			
		case SYSSNIV_SVMHIFG:

			break;

		case SYSSNIV_DLYLIFG:

			break;

		case SYSSNIV_DLYHIFG:

			break;

		case SYSSNIV_VMAIFG:

			break;

		case SYSSNIV_JMBINIFG:

			break;

		case SYSSNIV_JMBOUTIFG:

			break;

		case SYSSNIV_VLRLIFG:

			break;

		case SYSSNIV_VLRHIFG:

			break;

		default:
			_never_executed();
	}
	
	return;
}

#pragma vector=UNMI_VECTOR
void interrupt user_nmi_isr(void)
{
	switch (__even_in_range(SYSUNIV, SYSUNIV_BUSIFG))
	{

		case SYSUNIV_NONE:

			break;

		case SYSUNIV_NMIIFG:

			break;

		case SYSUNIV_OFIFG:

			break;

		case SYSUNIV_ACCVIFG:

			break;

		case SYSUNIV_BUSIFG:

			break;

		default:
			_never_executed();
	}

	return;
}

#endif

#endif

