/*
	EasyMSP Library 0.8.3 BETA1
*/

//EasyMSP Copyright 2011 Matthew Burmeister

/*!
	\mainpage EasyMSP Documentation
	
	Welcome to the documentation of EasyMSP. To get started quickly, I recommend the Getting Started page. Otherwise feel free to look around.
	
	if your are looking for the the programming guide, Please see \subpage program "Programming Guide"
	
	and if your just looking for some help, \subpage help "Help" or \subpage FAQ "FAQ" Might be able to help you.
	
	\page getstarted Getting Started
	
	All you need to do to use EasyMSP is to define your device name and include EasyMSP. a sample program would look like
	
	\code
	#define MSP430G2553
	#include "EasyMSP083BETA1"
	
	void main()
	{
		setup()
		
		//Your code...
	}
	\endcode
	
	\page program Programming Guide
	EasyMSP Programming Reference
	
	\subpage getstarted "Getting Started"
	\subpage preprocessors "Preprocessors"
	\subpage function "Functions"
	\subpage device "Devices"
	\subpage interrupt "Interrupts"
	
	\page preprocessors Preprocessors
	
	EasyMSP uses preprocessors defines to pass along arguments to EasyMSP. These arguments allows you to configure EasyMSP at compile time.
	
	\section Device 
		The device argument passes your device name to EasyMSP, so it can include proper libraries for that device. All that is need is to define your device name/model like this:  \code #define MSP430G2231 \endcode
		
	\section COREONLY 
		When pass COREONLY to EasyMSP. EasyMSP only include core files and will not include peripheral drivers. This is useful for using unsupported devices.
	
	\section NMIINT 
		Passing the NMIINT argument tells EasyMSP to call a routine that the user has wrote on a NMI, However this version does not include this feature yet.
		
	\section OSCINT 
	
		Passing the OSCINT argument tells EasyMSP to call a routine that the user has wrote when a crystal fault occurs.
	
	\section WDTINT
	
		Passing the WDTINT argument tells EasyMSP to call a routine that the user has wrote for the watch periodic interrupt timer.
		
	\section PORTINT1
		
		Passing PORTINT1 Tells EasyMSP that you would like to call a routine that the user has wrote on a PORT1 Interrupt. 
	
	\section PORTINT2
	
		Passing PORTINT2 Tells EasyMSP that you would like to call a routine that the user has wrote on a PORT2 Interrupt.  
	
	\section OVERRIDEDEVICEERROR
	
		Passing OVERRIDEDEVICEERROR (Override Device Error) Tells EasyMSP to ignore that the device is not supported.
	
	\page arduino Arduino mode
		\attention The AFI is not 100% working. Please expect bugs while i work on it.
		\bug Millis & micros function is not functioning. I have not written any init code to enable the WDT+ to provide a system tick yet.
		\todo Write a system tick interrupt that uses the WDT+ for the AFI
		\todo Test functions.
		\todo Write missing functions
		
		The AFI or Arduino Function Interface is a groundbreaking system for the MSP430. It allows real Arduino code to be used with very few changes on the MSP430 line of controllers.
		
		To enter into "Arduino Mode", just define your device and after that, define "Arduino" and then start writing arduino code! 
		
		These are the currently supported arduino functions:
			
			\li digitalWrite()
			\li digitalRead()
			\li pinMode()
			\li delay()
			\li delayMicroseconds()
			\li analogRead()
			\li analogReference()
			\li shiftOut()
			\li shiftIn()
			\li interrupts()
			\li noInterrupts()
			
			\li min()
			\li max()
			\li constrain()
			\li map()
			
			\li lowByte()
			\li highByte()
			\li bitRead()
			\li bitWrite()
			\li bitSet()
			\li bitClear()
			\li bit()
			
			I hope to expand the list soon.
			
	\page help Help
		We all need help once in a while. You can find the support fourm at www.43oh.com. You can also post a issue or email me.
	
	\page function Functions
		
		\section core Core Functions
		
			\subpage System.h "System" - System related functions
			
			\subpage SoftTime.h "Timing" - Software delay functions
			
			\subpage WDT.h "Watchdog" - Watchdog Functions
			
			\subpage Flash.h "Flash" - Flash Functions
			
			\subpage GPIO.h "GPIO" - Digital IO Functions
			
			\subpage SoftComm.h "Software Communication" - Software Communication
			
			If your device has full calibration for the DCO, EasyMSP will add the full version of the \subpage BCS_Full.h "BCS library". Otherwise, EasyMSP will include a \subpage BCS_Limited.h "limited version" of the BCS Library.
			
		\section peripheral Peripherals
		
		\subpage ADC10.h "ADC10" - Analog to digital converter functions
		
		\subpage Comp.h "Comparator" - Voltage Comparator functions
		
		\subpage USI.h "USI" - Universial Serial Interface functions
		
		\subpage USCI.h "USCI" - Universial Serial Communication Interface
		
			
	\page device Devices
	This page lists all of the supported devices that work with EasyMSP. All devices have:
	\li BCS
	\li Flash Controller
	\li Watchdog+
	\li One 16Bit Timer (Higher end devices have more timers)
	\li PORT1 and PORT2 IO pins.
	
	\section Devices
	
		\subpage msp430g2231 "MSP430G2231"
		
		\subpage msp430g2211 "MSP430G2211"
		
		\subpage msp430g2452 "MSP430G2452"
		
		\subpage msp430g2553 "MSP430G2553"
		
		\subpage msp430f2012 "MSP430F2012"
		
		\page msp430g2231 MSP430G2231
		The MSP430G2231 provides 2KB of flash and 128 bytes of ram. Peripherals included:
		\li \subpage BCS_Limited.h "Limited BCS"
		\li \subpage ADC10.h "ADC10"
		\li \subpage USI.h "USI"
		
		\page msp430g2211 MSP430G2211
		The MSP430G2211 provides 2KB of flash and 128 bytes of ram. Peripherals included:
		\li \subpage BCS_Limited.h "Limited BCS"
		\li \subpage Comp.h "Comparator"
		
		\page msp430g2452 MSP430G2452
		The MSP430G2211 provides 8KB of flash and 256 bytes of ram. Peripherals included:
		\li \subpage BCS_Limited.h "Limited BCS"
		\li \subpage ADC10.h "ADC10"
		\li \subpage USI.h "USI"
		\li \subpage Comp.h "Comparator"
		
		\page msp430g2553 MSP430G2553
		The MSP430G2553 has the largest set of Peripherals and memory. It Provides 16KB of Flash and 512 bytes of RAM. Peripherals included:
		\li \subpage BCS_Full.h "Full BCS"
		\li \subpage ADC10.h "ADC10"
		\li \subpage USCI.h "USCI"
		\li \subpage Comp.h "Comparator"
		\li Two timers.
		
		\page msp430f2012 MSP430F2012
		The MSP430F2012 is a "upgraded" version of the MSP430G2231. It provides 2KB of flash, 128 Bytes of ram, and supports the Full BCS library. Peripherals included:
		\li \subpage BCS_Full.h "Full BCS"
		\li \subpage ADC10.h "ADC10"
		\li \subpage USI.h "USI"
		
	\page interrupt Interrupts
	EasyMSP Provides a limited set of interrupts for the user to use. 
	
	\section Watchdog
		The watchdog can provide a periodic interrupt you can use. To setup the interrupt you need to pass WDTINT to EasyMSP, setup the timer using enableTimer() and then providing a void function called WDT_int(). WDT_int() will be called everytime the interrupt fires.
	
	\section PORT1
	PORT 1 provides a interrupt capability for all PORT pins on a logic state change. You must pass PORTINT1 to EasyMSP, configure pin interrupts using interruptEdgeSelect(), and then enable interrupts with pinInterruptEnable(). EasyMSP will call a vold function called PORT1_int() each time a interrupt is fired. The user must decode the interrupted pin by using decodeInterruptPin(). The interrupts can be stopped by pinInterruptDisable() 
	
	\section PORT2
	PORT 2 provides a interrupt capability for all PORT pins on a logic state change. You must pass PORTINT2 to EasyMSP, configure pin interrupts using interruptEdgeSelect(), and then enable interrupts with pinInterruptEnable(). EasyMSP will call a vold function called PORT2_int() each time a interrupt is fired. The user must decode the interrupted pin by using decodeInterruptPin(). The interrupts can be stopped by pinInterruptDisable()
	
	\section NMI
	Thw Watchdog+ Provides a NMI, which is triggered by a state change on RESET. 
	
	\page FAQ
*/


//Include device defs
#include <stdint.h>
#include "Define.h"

//Device dependant features

#ifdef MSP430G2231

	#ifndef __MSP430G2231__
		#define __MSP430G2231__
	#endif
	
	#include <msp430.h>
	
	#define supported
	
	#include "ADC10.h"
	#include "BCS_Limited.h"
	#include "USI.h"
	
#endif


#ifdef MSP430G2131

	#ifndef __MSP4302131__
		#define __MSP430G2131__
	#endif
	
	#include <msp430.h>

	#define supported
	
	#include "ADC10.h"

	#include "BCS_Limited.h"
	#include "USI.h"
	
#endif


#ifdef MSP430G2211

	#ifndef __MSP430G2211__
		#define __MSP430G2211__
	#endif
	
	#include <msp430.h>
	
	#define supported
	
	#include "Comp.h"
	#include "BCS_Limited.h"
	
#endif


#ifdef MSP430G2452
	
	#ifndef __MSP430G2452__
		#define __MSP430G2452__
	#endif
	
	#include <msp430.h>
	
	#define supported
	
	#include "ADC10.h"
	#include "BCS_Limited.h"
	#include "USI.h"
	#include "Comp.h"

#endif

#ifdef MSP430G2553

	#ifndef __MSP430G2553__
		#define __MSP430G2553__
	#endif
	
	#include <msp430.h>
	#define supported
	
	#define HASPORT3
	#define HASTWOTIMERS
	
	#include "USCI.h"
	#include "Comp.h"
	#include "ADC10.h"
	#include "BCS_Full.h"

#endif


#ifdef MSP430F2012
	
	#ifndef __MSP430F2012__
		#define __MSP430F2012__
	#endif
	
	#include <msp430.h>

	#define supported

	#include "ADC10.h"
	#include "BCS_Full.h"
	#include "USI.h"
	
#endif

//Do we become a Arduino?

#ifdef ARDUINO
	
	#include "Arduino.h"
	
#endif


#ifdef Arduino
	
	#define ARDUINO
	
	#include "Arduino.h"
	
#endif


#ifdef arduino

	#define ARDUINO
	
	#include "Arduino.h"
	
#endif


//Check if the defined device is supported

#ifndef supported
	
	#ifndef OVERIDEDEVICEERROR
		#error "Device not supported or wrong device name" //Whoops, looks like someone herp derped.
	#else
		
	#endif
	
#endif



#include "Flash.h"
#include "System.h" //Include system functions
#include "GPIO.h" //Include GPIO Functions
#include "SoftTime.h" //Include Software Timing
#include "SoftComm.h" //Include Software Commucations
#include "WDT.h" //Include watchdog functions 

#include "System.c"
#include "Flash.c"
#include "GPIO.c"
#include "SoftTime.c"
#include "SoftComm.c"
#include "WDT.c"

#ifdef MSP430G2231

	#define supported
	
	#include "ADC10.c"
	#include "BCS_Limited.c"
	#include "USI.c"
	
#endif


#ifdef MSP430G2131

	#define supported
	
	#include "ADC10.c"

	#include "BCS_Limited.c"
	#include "USI.c"
	
#endif


#ifdef MSP430G2211
	
	#define supported
	
	#include "Comp.c"
	#include "BCS_Limited.c"
	
#endif

#ifdef MSP430G2452
	
	#include "ADC10.c"
	#include "BCS_Limited.c"
	#include "USI.c"
	#include "Comp.c"

#endif

#ifdef MSP430G2553

	#define supported
	
	#include "USCI.c"
	#include "Comp.c"
	#include "ADC10.c"
	#include "BCS_Full.c"

#endif


#ifdef MSP430F2012
	
	#define supported

	#include "ADC10.c"
	#include "BCS_Full.c"
	#include "USI.c"
	
#endif
