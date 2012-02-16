
#ifdef WDTINT

extern void WDT_int(void);

#endif

static inline void clearWD(void)
{	
	unsigned int temp = WDTCTL << 8;
	temp = temp >> 8;
	temp |= WDTCNTCL;
	WDTCTL = WDTPW + temp;
}

static inline void disableWD(void)
{
	WDTCTL = WDTPW + WDTHOLD; //Disables the watchdog by setting the hold bit(WDTHOLD)
}

static inline void disableTimer(void)
{
	WDTCTL = WDTPW + WDTHOLD;
}

static int enableWD(unsigned int divider, unsigned int clocksource)
{
	unsigned int wdt=0;
	
	if (clocksource == ACLK)
	{
		wdt |= WDTPW + WDTSSEL;
	}
	
	switch (divider)
	{
		default:
			return(-1);

		
		case 64:
			clearWD();
			wdt |= WDTPW + BIT1 + BIT0;
		break;
		
		case 512:
			clearWD();
			wdt |= WDTPW + BIT1;
		break;
		
		case 8192:
			clearWD();
			wdt |= WDTPW + BIT0;
		break;
		
		case 32768:
			clearWD();
		break;
	}
		
	WDTCTL = wdt;
	
	return(1);
	
}

static int enableTimer(unsigned int clocksource, unsigned int divider)
{

	unsigned int wdt=0;
	
	
	wdt |= WDTPW + WDTTMSEL; //Set WDTTMSEL to enable timer mode.
	
	if (clocksource == ACLK) //What clock did the user select?
	{
		wdt |= WDTPW + WDTSSEL; //Looks like ALCK, so set thw WDTSSEL bit.
	}
	
	switch (divider) //Lets do a switch to find the selected clock divider.
	{
		default:
			return(-1); //Whoops, user entered wrong settings, so lets abort.
		
		case 64:
			clearWD();
			wdt |= WDTPW + BIT1 + BIT0; 
		break;
		
		case 512:
			clearWD();
			wdt |= WDTPW + BIT1;
		break;
		
		case 8192:
			clearWD();
			wdt |= WDTPW + BIT0;
		break;
		
		case 32768:
			clearWD(); //Do nothing, As BIT0 and BIT1 are already clear
		break;
	}
	
	WDTCTL = wdt; //Transfer settings
	IE1 |= WDTIE;
	
	//All of the config is done, We can return control to the user program
	
	return(1); //Return config success

}	
	
#ifdef WDTINT
#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
	WDT_int();
}

#endif
