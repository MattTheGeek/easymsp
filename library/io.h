/*
 * io.C
 * Version: 1.0.4
 * Library for accessing ports
 *
 * Author: Matthew Burmeister
 * Copyright Matthew Burmeister 2011 - 2012. All Rights Reserved.
 *
 * Part of the EasyMSP Project.
 *
 */

#ifndef IO_H
#define IO_H

/* Constants */

#ifndef HIGH_TO_LOW
#define HIGH_TO_LOW 0
#endif

#ifndef LOW_TO_HIGH
#define LOW_TO_HIGH 1
#endif

#ifndef HIGH
#define HIGH 1
#endif

#ifndef LOW
#define LOW 0
#endif

#ifndef INPUT
#define INPUT 0
#endif

#ifndef OUTPUT
#define OUTPUT 1
#endif

/* Public Functions */

inline void digitalWrite(unsigned short int, unsigned short int);

inline void setHigh(unsigned short int);
inline void setLow(unsigned short int);
inline void pinToggle(unsigned short int);
inline void pinMode(unsigned short int, unsigned short int);
inline bool readPin(unsigned short int);

#if SERIES == 5
inline void setDriveStrength(unsigned short int, unsigned short int);
#endif

inline void setPullUp(unsigned short int);
inline void setPullDown(unsigned short int);
inline void setPullOff(unsigned short int);

inline void attachInterrupt(unsigned short int, unsigned short int, void(*)());
inline void removeInterrupt(unsigned short int);

/* Interrupt ISRs */

static interrupt void port1_isr(void);
static interrupt void port2_isr(void);

/* Pin Interrupt function pointers */

/* User interrupt vectors
 *
 * Port1FunctionVector and Port2FunctionVector holds the addresses of user functions to call if a pin triggers a interrupt.
 * As always, they must be void and return nothing. The shorter the function, the better.
 */

static void (*Port1FunctionVector[8])(void) =
{	NULL};

static void (*Port2FunctionVector[8])(void) =
{	NULL};

#endif /* IO_H */
