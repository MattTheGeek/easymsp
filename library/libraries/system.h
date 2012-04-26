/* ---------------------------------------------------------------------------
 **
 **
 **
 ** system.h
 ** Provides functions or related functions to control the system
 **
 ** Author: Matthew L. Burmeister
 ** Copyright (c) 2011 All rights reserved.
 ** -------------------------------------------------------------------------*/

/* todo: Clean up header */

#ifndef SYSTEM_H
#define SYSTEM_H

/*
 system.h defines
 */

/*
 system.h macros
 */

static const unsigned short int delayConstants[] =
{};
#pragma FUNC_CANNOT_INLINE (delayCycles);
#pragma FUNC_EXT_CALLED (delayCycles);
#pragma FUNCTION_OPTIONS ( delayCycles, "--opt_level=0" );
extern void delayCycles(register unsigned short int cycles);
extern inline void powerMode(unsigned short int);
extern inline void powerModeOff(void);

extern inline void reset(void);

extern inline void shutdown(void);

extern void inline delaySec(register unsigned short int);

extern void inline delayms(register unsigned short int);

extern void inline delayus(register unsigned short int);

#endif
