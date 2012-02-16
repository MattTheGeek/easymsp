#ifndef ARDUINO

static inline void setup(void)
{
	stopwd(); //stop the watchdog
	IFG1 = 0; //Clear Flags
	__bis_IE1(NMIIE);
	__bis_IE1(OFIE);
	__bis_IE1(ACCVIE);
	
}

#else

static inline void main()
{
	stopwd();
	setup();
	
	while(1)
	{
		loop();
	}
	
}

#endif

static inline void reset(void)
{
	WDTCTL = 0;
}

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
	//To be added
}

static inline void lowPowerModeOn(void)
{
	_lowpower = 1;
}

static inline void lowPowerModeOff(void)
{
	_lowpower = 0;
}

static inline void disableInterrupts(void)
{
	__bic_SR_register(GIE);
}

static inline void enableInterrupts(void)
{
	__bis_SR_register(GIE);
}

static inline void enterAM(void)
{
	__bic_SR_register(SCG1 + SCG0 + OSCOFF + CPUOFF);
}

static inline void enterLPM0(void)
{
	__bis_SR_register(CPUOFF);
}

static inline void enterLPM1(void)
{
	__bis_SR_register(SCG0 + CPUOFF);
}

static inline void enterLPM2(void)
{
	__bis_SR_register(SCG1 + CPUOFF);
}

static inline void enterLPM3(void)
{
	__bis_SR_register(SCG1 + SCG0 + CPUOFF);
}

static inline void __bis_IE1(unsigned int pos)
{
	switch (pos)
	{
		default:
		
		break;
	
		case WDTIE:
			asm("	bis.b	#1,		&0");
		break;
		
		case OFIE:
			asm("	bis.b	#2,		&0");
		break;
		
		case NMIIE:
			asm("	bis.b 	#0x10,	&0");
		break;
		
		case ACCVIE:
			asm("	bis.b 	#0x20,	&0");
		break;
	}
}

static inline void __bic_IE1(unsigned int pos)
{
	switch (pos)
	{
		default:
		
		break;
		
		case WDTIE:
			asm("	bic.b	#1,		&0");
		break;
		
		case OFIE:
			asm("	bic.b	#2,		&0");
		break;
		
		case NMIIE:
			asm("	bic.b 	#0x10,	&0");
		break;
		
		case ACCVIE:
			asm("	bic.b 	#0x20,	&0");
		break;
	}
}


#pragma vector=NMI_VECTOR
__interrupt void NMI(void)
{
	unsigned int status = IFG1 & OFIFG;
	
	if (status > 0) //Osc fault
	{
		
		#ifdef OSCINT
			OSC_int(); //Call a function if the user has one set up.
		#else
		
		unsigned int temp = 5; //Timeout counter
		
		while((IFG1 & OFIFG) > 0) //Loop while OSIFG is set.
		{	
			IFG1 &= ~OFIFG; //Clear Osc fault flag
			
			if (temp == 0) //Osc failure, Call systemFailed or Reset.
			{
				#ifdef CATCHSYSTEMFAILURE
					systemFailed();
				#else
					reset();
				#endif
			}
			
			delayus(50);
			temp--;
		}
		#endif
	}
	
	status = IFG1 & NMIIFG;
	
	if (status > 0) //NMI
	{
		IFG1 &= ~NMIIFG; //Clear NMIIFG from IFG1
		#ifdef NMIINT
		NMI_int();	//Call a function if the user has one set up.
		#endif
	}
	
	status = FCTL3 & ACCVIFG;
	
	if (status > 0) //Flash Access violation
	{
		
		unsigned int temp = FCTL3 << 8; //Read FCTL3, Shift the high byte out (the flash key)
		temp = temp >> 8; //Shift back
		temp &= ~ACCVIFG; //Clear ACCVIFG
		FCTL3 = flashKey | temp; //Commit settings
		
		#ifdef ACCVINT
			ACCV_int(); //Call a function if the user has one set up/
		#endif
	}
}
