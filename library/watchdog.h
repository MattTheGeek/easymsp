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

#ifndef WDTIS_1
  #define WDTIS_1 BIT0
#endif

#ifndef WDTIS_2
  #define WDTIS_2 BIT+1
#endif

#ifndef WDTIS_3
  #define WDTIS_3 BIT0+BIT1
#endif

// System Prototypes
bool detectWatchdog(void); 
// User Prototypes
void holdWatchdog(void);
/// /brief Stops the watchdog while preserving settings.
/// /note Please do not confuse holdWatchdog() with wdstop()
/// /detail holdWatchdog() will put the internal watchdog on hold, while keeping all settings.
/// 
/// This function does not accept any parameters.
/// 
/// This function does not return any value.
/// 
/// /sa stopwd()
#if SERIES == 2
	unsigned short int startWatchdog(unsigned short int, unsigned short int);
#elif SERIES == 5
	unsigned short int startWatchdog(enum clocks, enum div);
#endif
/// /brief Arms the watchdog with said settings.
/// /note The watchdog must be cleared periodicly or the MCU will reset.
/// /detail startWatchdog()
///
///
/// /param[in] clock Clock to source for the watchdog
/// /li ACLK - Source from ACLK
/// /li SMCLK - Source from SMCLK
///
/// /param[in] div Divider for the clock
/// /li 64 - Divide clock by 64
/// /li 512 - Divide clock by 512
/// /li 8192 - Divide clock by 8192
/// /li 32768 - Divide clock by 32768
///
/// To find the time interval
/// interval = (CLOCK / CLOCK_DIV) / divider
///
/// /return 0 Success, No errors.
/// /return 1 No Watchdog present.
/// /return 2 Invaild clock source.
/// /return 3 Invaild clock divider.
/// /return 4 Unknown Error.

void resetWatchdog(void);

void clearWatchdog(void);

void holdWatchdogTimer(void);
unsigned short int startWatchdogTimer(unsigned short int, unsigned short int, void(*function)(void));
void resetWatchdogTimer(void);

void resetPinMode(unsigned short int, unsigned short int);

#ifndef NO_WDT_ISR
	static __interrupt void watchdog_timer_isr(void);
	static unsigned short int HardwareTimeCount = NULL;
	static void (*watchdogFunctionToCall)(void) = NULL;
#endif

#include "watchdog.c"

#endif
