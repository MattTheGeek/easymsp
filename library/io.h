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

#define PORTA 'A'
#define PORTB 'B'
#define PORTC 'C'
#define PORTJ 'J'

#ifdef HASPORTA
#define HASPORT1
#define HASPORT2

#define PORT1 1
#define PORT2 2

#endif

#ifdef HASPORTB
#define HASPORT3
#define HASPORT4

#define PORT3 3
#define PORT4 4

#endif

#ifdef HASPORTC
#define HASPORT5
#define HASPORT6

#define PORT5 5
#define PORT6 6

#endif

#ifdef HASPORTD
#define HASPORT7
#define HASPORT8

#define PORT7 7
#define PORT8 8

#endif

#ifdef HASPORTE
#define HASPORT9
#define HASPORT10

#define PORT9 9
#define PORT10 10

#endif

#ifdef HASPORTF
#define HASPORT11

#define PORT11 11

#endif

/* Public Functions */
#ifndef __GNUC__

#pragma FUNCTION_OPTIONS (setHigh, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (setLow, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (pinToggle, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (pinMode, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (readPin, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (portWrite, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (portWriteDir, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (portRead, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (setPullUp, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (setPullDown, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (setPullOff, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (attachInterrupt, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (removeInterrupt, "--opt_level=4 --opt_for_speed=0" );

#endif /* NOT GNUC */

inline void digitalWrite(unsigned short int, unsigned short int);

inline void setHigh(unsigned short int);
inline void setLow(unsigned short int);
inline void pinToggle(unsigned short int);
inline void pinMode(unsigned short int, unsigned short int);
inline bool readPin(unsigned short int);

inline void portWrite(unsigned short int, unsigned char);
inline void portWriteDir(unsigned short int, unsigned char);
inline unsigned char portRead(unsigned short int);

inline void setPullUp(unsigned short int);
inline void setPullDown(unsigned short int);
inline void setPullOff(unsigned short int);

#if SERIES == 5

#ifndef __GNUC__

#pragma FUNCTION_OPTIONS (setDriveStrength, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (portWriteWord, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (portWriteDirWord, "--opt_level=4 --opt_for_speed=0" );
#pragma FUNCTION_OPTIONS (portReadWord, "--opt_level=4 --opt_for_speed=0" );

#endif /* NOT __GNUC__ */

inline void setDriveStrength(unsigned short int, unsigned short int);
inline void portWriteWord(unsigned short int, unsigned short int);
inline void portWriteDirWord(unsigned short int, unsigned short int);
inline unsigned short int portReadWord(unsigned short int);

#endif


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
