/*
 *	EasyMSP Blinking LEDs (Hello World) - Using the Watchdog.
 *
 *	Requirements
 *		This demo requires a LaunchPad Value Line development kit
 *		and of course, Version 1 or higher of the EasyMSP system.
 *		The recommended MCU is a MSP430G2553, But others may work.
 *
 * 	Description
 * 		This example program blinks both LEDs on the launchpad
 * 		development board using the built in watchdog timer while
 * 		in a low power mode.
 *
 *	Pinout
 *				  -MSP430G2xxx-
 *				 _______________
 *				|				|
 *				|				|
 *		REDLED<-|P1.0			|
 *				|				|
 *				|				|
 *				|			P1.6|->GREENLED
 *				|				|
 *
 *	Comments
 *		This demo should work on any board, as long the LED names as well the device and board define are changed.
 *
 *	About
 *		This example was created by Matthew Burmeister for the
 *		EasyMSP system.
 *
 *		(c) 2012 Matthew Burmeister
 */


/* Setup and include EasyMSP here */
#define MSP430G2553 /* We are using a MSP430G2553 MCU */
#define LAUNCHPAD /* We are also using a TI MSP430 Value Line LaunchPad */
#include <path\library\EasyMSP.h> /* Include the EasyMSP libraries. Replace path with the exact location on your computer */

void blink(void); /* Prototype for our blink function */

void init(void)
{
	setACLK(VLOCLK, by_2); /* Set ACLK to source the internal VLO and divide it by 2 */
	pinMode(REDLED, OUTPUT); /* Set the REDLED (P1.0) to become a output */
	pinMode(GREENLED, OUTPUT); /* Set the GREENLED (P1.6) to become a output */
	setHigh(REDLED); /* Turn on the REDLED(P1.0) */
}

void loop(void)
{
	watchdogTimerStart(ACLK, by_512, &blink); /* Setup the Watchdog timer to source ACLK, prescaled by 512, and call blink() when the timer overflows. */
	powerMode(3); /* Enter low power mode 3 */
}

void blink(void)
{
	/* Toggle the states of the LEDs */
	pinToggle(GREENLED);
	pinToggle(REDLED);
}
