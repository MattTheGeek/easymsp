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

extern inline void stopWatchdog(void);
extern inline void holdWatchdog(void);
extern inline void clearWatchdog(void);
extern inline void resumeWatchdog(void);
extern inline void resetWatchdog(void);

extern void startWatchdog(unsigned short int, unsigned short int);

#endif
