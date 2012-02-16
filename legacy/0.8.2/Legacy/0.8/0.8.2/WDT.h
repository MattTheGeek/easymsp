/*This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 United States License. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/us/ or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
*/

//Copyright 2011 Matthew Burmeister

//WDT+

static void enableTimer(unsigned int clocksource, unsigned int divs);
static void disableTimer();
static unsigned char timerEnabled = 0;
extern WDT_int();

#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
	if (timerEnabled = 1)
	{
		WDT_int();
	}
}
