/* EasyMSP Example Program
 * Bare Requirements
 *
 * For EasyMSP 1.0.0 and above.
 *
 * Written by:
 * Matthew Burmeister
 * Copyright 2011-2012 All Rights Reserved.
 *
 *
 */

/* 
	Compile time options
		When using EasyMSP, always add compile time options before
		including EasyMSP. In CCSv5, you are no longer required to 
		declare your device. However, having it doesn't hurt.

*/

#define MSP430G2553

/*
	Including EasyMSP
		After defining all compile time options, you are ready to
		include the EasyMSP system. If you have used the EasyMSP
		installer, you do not need to include the full path. 
		
		#include <EasyMSP.h>
		
		If you didn't use the installer or your PATH does not have
		a entry for EasyMSP, you will need to include the full path
		name of where EasyMSP is located.
		
		#include "[Path]\EasyMSP.h"
*/
	
#include <EasyMSP.h>
  
	
void init(void)
{
	/* The code here will only be executed once on startup */
}

void loop(void)
{
	/* 
		Once EasyMSP has finished configuring the device, Execution will
		be passed on to your code here. EasyMSP will continue executing
		this code until "stop()" is called.
	*/
}