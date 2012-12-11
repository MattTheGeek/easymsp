/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	watchdog.h
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

#ifndef WATCHDOG_H
#define WATCHDOG_H

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')
#	ifndef WDTIS_1
#		define WDTIS_1 BIT0
#	endif
#	ifndef WDTIS_2
#		define WDTIS_2 BIT1
#	endif
#	ifndef WDTIS_3
#		define WDTIS_3 (BIT0 | BIT1)
#	endif
#endif
 
void (*WatchdogFunctionVector)(void) = NULL;
extern inline void disableWatchdog(void);
extern inline void stopWatchdog(void);
extern inline void holdWatchdog(void);
extern inline void clearWatchdog(void);
extern inline void resumeWatchdog(void);
extern inline void resetWatchdog(void);

extern void startWatchdog(unsigned short int, unsigned short int);
extern void watchdogTimerStart(unsigned short int, unsigned short int, void (*)());

#pragma INTERRUPT(watchdog_isr);
void interrupt watchdog_isr(void);

#endif
