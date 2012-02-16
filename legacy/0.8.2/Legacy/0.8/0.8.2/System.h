/*This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 United States License. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/us/ or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
*/

//Copyright 2011 Matthew Burmeister

#include <stdint.h>
#include <define.h>
//Macro functions
//-------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------

static inline void setup();
static inline void stopwd();
static inline void reset();
static inline void shutdown();
static void sleep(unsigned int time, unsigned int mode);

//==========================================================================
//Start functions
//==========================================================================

static void setup()
{
	stopwd();
}	

//Reset
//-------------------------------------------------------
//Reset the microcontroller

static inline void reset(void)
{
	WDTCTL = 0;
}

//StopWD
//--------------------------------------------------------
//Stop the Watchdog from reseting the system.

static inline void stopwd(void)
{
	WDTCTL = WDTPW + WDTHOLD;
}


static inline void shutdown(void)
{
	//Enters the CPU into LPM4
  __bic_SR_register(CPUOFF + OSCOFF + SCG0 + SCG1);
}

static void sleep(unsigned int time, unsigned int mode)
{
	
}


