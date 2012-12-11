/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	flash.h
 *	C Library for the MSP430 Flash Module.
 *  For All MSP430 devices. 
 *
 *	Part of the EasyMSP Project
 *	www.code.google.com/p/EasyMSP/
 *
 *	Author: Matthew L. Burmeister
 *	Copyright (c) 2010, 2011, 2012 All rights reserved.
 *
 *	Contact
 *		You can contact me by email at matthewburmeister@gmail.com 
 *		or by sending mail to:
 *
 *		Matthew Burmeister
 *		11593 Autunno St
 *		Las Vegas, NV 89183
 *		United States of America
 *
 *	Licence
 *		EasyMSP is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		EasyMSP is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with EasyMSP. If not, see <http://www.gnu.org/licenses/>.
 *
*/



MOV #WDTPW+WDTHOLD,&WDTCTL ; Disable WDT
MOV #FWKEY+FSSEL1+FN0,&FCTL2 ; SMCLK/2
MOV #FWKEY, &FCTL3 ; Clear LOCK
MOV #FWKEY+ERASE, &FCTL1 ; Enable segment erase
CLR &0FC10h ; Dummy write, erase S1
MOV #FWKEY+LOCK, &FCTL3 ; Done, set LOCK
... ; Re-enable WDT?

unsigned short int eraseFlashSegment(unsigned short int key, unsigned short int bank)
{
	watchdogState(STORE); /* Store the watchdog state using watchdogState(). see the watchdog documentation for details about this function. */
	disableInterrupts(); /* Now that we have stopped the watchdog from resetting the system, our next step is to disable any interrupts */
	clockState(STORE); /* After disabling interrupts, we can now focus on setting up the clock system to clock the flash clock generator between 257 kHz to 476 kHz. */
	
	/* By using clockState and watchdogState, we can freely modify those modules state to suit our current need (In this case, reconfiguring the clock system for flash use)
		without losing the previous state.
		
		After storing the state, we can now get down to business (Changing the clock to suit the flash module needs)
	*/
	
	/* todo: Reconfigure clock here for flash use */
	
	FCTL3 = FWKEY; /* Clear any lock in the FTCL3 register. */
	FCTL1 = FWKEY + (ERASE); /* Set the flash to erase segment by segment */
	
	/* todo: Perform dummy write */
	
	FCTL3 = FWKEY + (LOCK);
	
	if (FCTL3 & FAIL) > 0)
	{
		FCTL3 = FWKEY + (((FCTL3 << 8) >> 8) & ~FAIL); 
		
		/*  We can't use bic or bis to clear a flash register, But what we can do is shift the FTCL3 register to the right 8 times (Cutting off the high nibble) and shifting back into place.
			While this looks like a simple line, This code turns out to be very complex
			
			First the CPU reads FTCL3 and stores it, performs 8 RLA, then executes a SWPB, performs a BIC, and finally writes back the result. for a total of 11 instructions! 
		*/
		
		return (FLASH_FAILURE);
	}
	else
	{
		return (SUCCESS);
	
}

/* 
void flashNuke(unsigned short int key1, unsigned short int key2)
{

}

unsigned short int verifyFlash(unsigned short int segment)
{
	
	return (SUCCESS);
}