/*
	system.c	Version 1.0A
	System library for 5/6 Series MSP430 devices.
		
	Part of the EasyMSP system
	
	This file is under GPL v3
	Copyright Matthew Burmeister 2012. All Rights Reserved.
	
*/



/*
	Interrupt Service Routines
	
	Handles non-maskable interrupts such as JTAG mailbox operations, and osc faults, and any other errors.
*/

void main(void)
{
	/* Do setup tasks here */

	init(); /* Call init() */

	while(EasyMSPExecute == true)
	{
		loop();
	}
}

void interrupt system_nmi_isr(void)
{

}

void interrupt user_nmi_isr(void)
{

}
