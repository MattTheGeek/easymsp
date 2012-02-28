/* EasyMSP Example Program
 * Bare Requirements
 *
 * For EasyMSP 1.0.0 and above.
 *
 * Written by:
 * Matthew Burmeister
 * Copyright 2011 All Rights Reserved.
 *
 *
 */
 
 // <-- This is a one line comment
 
/*
	<-- and this is a multi line comment
*/

//Just to be clear...

//When using EasyMSP, Your very first line of code should be:
#define MSP430G2553
//This tells what device you are using and adds in the correct support libraries.
//So just remember, Always define your device model.

//The next line should be this:
#include "EasyMSP.h"
//This tells your compiler to include EasyMSP in this project. This is always required.

/* When you compile a EasyMSP program, it looks for two C functions called init() and loop(),
 * However this can be suppressed by defining NOSETUP
 */
 
 /* void init(void) is for configuring your program before the main loop runs.
  * If you don't require a init() function, just declare NOINIT and EasyMSP will ignore looking for init.
  */
  
 void init(void)
 {
	//Init code ... If required.
 }
 
 /*	void loop(void) is where you write your program. This function gets called after init().
	As the name implies, This function will loop forever until endEasyMSP is called or the system
	encounters a reset.
	
	Your main program doesn't have to loop, and can become less Arduinoish by defining NOLOOP.
	NOLOOP Tells EasyMSP to look for code() function instead.
	
 */
 void loop(void)
 {
	//Your code
 }
 
 /*
	And thats about it. This is the bare requirements for running EasyMSP, Other than the device.
	If you run into any trouble, Remember help is aways here.
	
	You can:
		Post a help request at www.43oh.com in the forums under Community projects
		Issue a ticket at code.google.com/p/easymsp/issues/entry
		Hit me up on IRC on freenode.net. You can find me as MattTheGeek in these rooms:
			#43oh
			#sparkfun
		Email If you need help now, please feel free to contact matthewburmeister@gmail.com
		I might also be able to arrange a chat, and or voice and video call to better assist you.
		
		And if your problem is extremely urgent or need the answer right now, Please call (360) 830-6024
		If i don't pickup, Leave a message of the problem and i will try to call as soon as possible.
		
	And again, Thank you for using EasyMSP!
	
	Regards,
	Matthew Burmeister
	Owner/Head Developer
	
 */