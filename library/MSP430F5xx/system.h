/*
	system.h	Version 1.0A
	System library for 5/6 Series MSP430 devices.
		
	Part of the EasyMSP system
	
	This file is under GPL v3
	Copyright Matthew Burmeister 2012. All Rights Reserved.
	
*/

static volatile unsigned short int EasyMSPExecute = true;

/* Prototypes */

#ifndef NOSETUP

	#ifndef NOINIT
		void init(void);
	#endif

	#ifndef NOLOOP
		void loop(void);
	#endif

#endif

void interrupt system_nmi_isr(void);
void interrupt user_nmi_isr(void);
