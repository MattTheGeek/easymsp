/*
 * watchdog.h
 * Watchdog Timer (WDT) Library
 *
 * Provides access to the watchdog and related functions
 *
 *
 * Written by: Matthew Burmeister
 * Copyright 2011 All Rights Reserved.
 *
 */

#ifndef WATCHDOG_H
#define WATCHDOG_H

#if (SERIES == 2) || (SERIES == 'V')
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
extern inline void stopWatchdog(void);
extern inline void holdWatchdog(void);
extern inline void clearWatchdog(void);
extern inline void resumeWatchdog(void);
extern inline void resetWatchdog(void);

extern void startWatchdog(unsigned short int, unsigned short int);
extern void watchdogTimerStart(unsigned short int, unsigned short int, void (*)());

#pragma FUNC_EXT_CALLED (watchdog_isr);
#pragma INTERRUPT(watchdog_isr);
void interrupt watchdog_isr(void);

#endif
