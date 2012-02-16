
 //Do we become a Arduino?

extern void setup();
extern void loop();

#ifndef ARDUINO

void main(void)
{
	stopwd();
	setup();
	
	while(1)
	{
		loop();
	}
}

#endif



/*
	Alright, it's time to call system variables and buffers.
*/

static unsigned int currentclock = 1; //This varible holds the system current clock.


//And now we start our functions

//==========================================================================
//Start functions
//==========================================================================


static inline void setup()
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


static void compareConfig(register unsigned int ref, register unsigned int _short, register unsigned int filter)
{

	if (ref == DIODE)
		{
			CACTL1 |= BIT4 + BIT5;
		}
		
		if (ref == EXTERNAL)
		{
			CACTL1 &= ~BIT4 + ~BIT5;
		}
		
		if (ref == VDDHALF)
		{
			CACTL1 |= BIT5;
			CACTL1 &= ~BIT4;
		}
		
		
		if (ref == VDDQUATER)
		{
			CACTL1 |= BIT4;
			CACTL1 &= ~BIT5;
		}
		
	if (_short == YES)
	{
		CACTL2 |= CASHORT;
	}	
		else
		{
			CACTL2 &= ~CASHORT;
		}
			
	if (filter == FILTERON)
	{
		CACTL2 |= CAF;
	}
		
		else
		{
			CACTL2 &= ~CAF;
		}
}

static unsigned int compare(register unsigned int pin)
{
	pin = pin << 3;
	CACTL2 |= pin;
	
	CACTL1 |= CAON;
	
	register unsigned int result=0;
	
	result = CACTL2 & CAOUT;
	if (result > 0)
	{
		CACTL1 &= ~CAON;
		return (0);
	}
	else
	{
		CACTL1 &= ~CAON;
		return (1);
	}
}



static void setFreq(register unsigned int FREQ)
{
	//BCSCTL2 = 0;
	//BCSCTL1 = 0;
	

	
	if (FREQ == M16)
	{
		//Set CPU to 16MHZ
		currentclock = M16;
		BCSCTL1 = CALBC1_16MHZ;
		DCOCTL = CALDCO_16MHZ;
	}
		
		if (FREQ == M12)
	{
		//Set CPU to 12Mhz
		currentclock = M12;
		BCSCTL1 = CALBC1_12MHZ;
		DCOCTL = CALDCO_12MHZ;
	}
		
	if (FREQ == M8)
	{
		//Set CPU to 4Mhz
		currentclock = M8;
		BCSCTL1 = CALBC1_8MHZ;
		DCOCTL = CALDCO_8MHZ;
	}
		
    

	if (FREQ == M1)
	{
		//Set CPU to 1MHZ
		currentclock = M1;
		BCSCTL1 = CALBC1_1MHZ;
		DCOCTL = CALDCO_1MHZ;
	}	
		
	if (FREQ == K500)
	{
		currentclock = K500;
		BCSCTL1 = CALBC1_1MHZ;
		BCSCTL2 = DIVM_1 + DIVS_1;
		DCOCTL = CALDCO_1MHZ;
	}
		
	if (FREQ == K100)
	{
		//Set CPU to around 100KHZ
		currentclock = K100;
		BCSCTL1 = CALBC1_1MHZ;
		BCSCTL2 = DIVM_1 + DIVS_3;
		DCOCTL = CALDCO_1MHZ;
	}
		
	if (FREQ == K12)
	{
		//Set CPU to 12Khz
	}
}


static unsigned int analogRead(unsigned int pin)
{
	//Ok, we need to setup the ADC10.
	//ADC10CTL0 |= SREF_0; //Set Ref to VCC and VDD
	ADC10CTL0 |= ADC10SHT_0; //Sample And Hold 4 clokcs
	//ADC10CTL0 |= ADC10SR; // enable for low power mode
	//ADC10CTL0 |= REFBURST;
	switch(pin)
	{
		case 0:
		ADC10CTL1 |= INCH_0;
		ADC10AE0 |= 0x01;
		break;
		
		case 1:
		ADC10CTL1 |= INCH_1;
		ADC10AE0 |= 0x02;
		break;
		
		case 2:
		ADC10CTL1 |= INCH_2;
		ADC10AE0 |= 0x04;
		break;
		
		case 3:
		ADC10CTL1 |= INCH_3;
		ADC10AE0 |= 0x08;
		break;
		
		case 4:
		ADC10CTL1 |= INCH_4;
		ADC10AE0 |= 0x10;
		break;
		
		case 5:
		ADC10CTL1 |= INCH_5;
		ADC10AE0 |= 0x20;
		break;
		
		case 6:
		ADC10CTL1 |= INCH_6;
		ADC10AE0 |= 0x40;
		break;
		
		case 7:
		ADC10CTL1 |= INCH_7;
		ADC10AE0 |= 0x80;
		break;
		
		case 0xFF:
		ADC10CTL1 |= INCH_10;
		break;
	}
	
	//ADC10CTL1 |= ISSH;
	ADC10CTL0 |= ADC10ON + ENC;
	ADC10CTL0 |= ADC10SC;
	
	while ((ADC10CTL1 & ADC10BUSY) != 1)
	{
	}
	
	return (ADC10MEM);
	
}


static void analogReference(unsigned int ref)
{
	switch (ref)
	{
		
		default:
			
		break;
		
		case DEFAULT:

			ADC10CTL0 &= ~SREF_7; //Clear the register
			ADC10CTL0 |= SREF_0;
		break;
	
	
		case INTERNAL:
	
			ADC10CTL0 &= ~SREF_7; //Clear the register
			ADC10CTL0 |= SREF_0;
		break;
	
		case INTERNAL1V1:
	
			ADC10CTL0 &= ~SREF_7; //Clear the register
			ADC10CTL0 |= SREF_1 + REFON;
			ADC10CTL0 &= ~REF2_5V;
		break;
	
		case INTERNAL2V56:
	
			ADC10CTL0 &= ~SREF_7; //Clear the register
			ADC10CTL0 |= SREF_1 + REFON + REF2_5V;
		break;
	
		case EXTERNAL:
		
			ADC10CTL0 &= ~SREF_7; //Clear the register
			ADC10CTL0 |= SREF_2;
		break;
		
	}
}


static void hspiConfig(int bitorder, int clockphase, int clockpol)
{
	UCA0CTL1 = UCSWRST;
	UCA0CTL1 |= UCSSEL_2;
	
	if (bitorder == MSBFIRST)
	{
		UCA0CTL0 |= UCMSB;
	}
	else
	{
		UCA0CTL0 &= ~UCMSB;
	}
	
	if (clockpol == HIGH)
	{
		UCA0CTL0 |= UCCKPL;
	}
	else
	{
		UCA0CTL0 &= ~UCCKPL;
	}
	
	if (clockphase == 1)
	{
		UCA0CTL0 |= UCCKPH;
	}
	else
	{	
		UCA0CTL0 &= ~UCCKPH;
	}
	
	UCA0CTL0 |= UC7BIT + UCMST + UCMODE_0; //Took out USYNC
	
	UCA0CTL1 &= ~UCSWRST; //Clear the reset
}

static void hspiOut(char data)
{
	unsigned int status = UCA0STAT & UCBUSY;
	
	while(status > 0)
	{
		status = UCA0STAT & UCBUSY;
	}
	
	UCA0TXBUF = data;
}

static char hspiIn(void)
{
	unsigned int status = UCA0STAT & UCBUSY;
	
	while(status > 0)
	{
		status = UCA0STAT & UCBUSY;
	}
	
	return(UCA0RXBUF);
}



static inline void delayus(register unsigned int time)
{
     while(time != 0)
     {
              _us();
              time--;
     }
}  

//_us
//Used for internal use only
static inline void _us(void)
{
	register int nop = 2;
	nop = 1;
	nop = 0;
	nop = 1;
	nop = 0;
	nop = 1;
	nop = 0;
	nop = 1;
	nop = 0;
	nop = 1;
	nop = 0;
	nop = 1;
	nop = 0;
	nop = 1;
	nop = 0;
	nop = 1;
	nop = 0;
	nop = 1;
}

//delayms
//--------------------------------------------------------
//Delay execution by "x" miliseconds

static inline void delayms(register unsigned int time)
{
	
	while (time != 0)
	{
          register unsigned int us = 28;
          
          while(us != 0)
          {
			delayus(1);
            us--;
          }
          
          time--;
     }
}


//delaysec
//--------------------------------------------------------
//Delay execution by "x" seconds.

static inline void delaysec(register unsigned int time)
{
	while(time != 0)
	{
		delayms(1000);
		time--;
	}
}




static void shiftOut(unsigned int DOUT, unsigned int SCLK, unsigned int bitorder, char data)
{
	register unsigned char bits=8;
	register unsigned char value=0;
	
	while(bits != 0)
	{
		if (bitorder == MSBFIRST)
		{
			value = data & 0x80;
		}
		else
		{
			value = data & 0x01;
		}
		
		low(SCLK);
		
		if (value > 0)
		{
			high(DOUT);
		}
		else
		{
			low(DOUT);
		}
		
		high(SCLK);
		
		if (bitorder == MSBFIRST)
		{
			data = data << 1;
		}
		else
		{
			data = data >> 1;
		}
		
		bits--;
	}
}

static char shiftIn(unsigned int DIN, unsigned int SCLK, unsigned int bitorder)
{
	unsigned int bit=0;
	unsigned int clock=0;
	unsigned char bits=8;
	unsigned char data=0;
	unsigned int bit_unvalid_time = 5000;
	
	while (bits != 0)
	{
		clock = read(SCLK);
		
		while (clock == 0)
		{
			if (bit_unvalid_time == 0)
			{
				return (0);
			}
			
			clock = read(SCLK);
			
			bit_unvalid_time--;
		}
		
		bit = read(DIN);
		
		if (bit > 0)
		{
			if (bitorder == MSBFIRST)
			{
				data |= 0x80;
			}
			else
			{
				data |= 0x01;
			}
		}
		else
		{
			if (bitorder == MSBFIRST)
			{
				data |= 0x80;
			}
			else
			{
				data |= 0x01;
			}
		}
		
		if (bitorder == MSBFIRST)
		{
			data = data >> 1;
		}
		else
		{
			data = data << 1;
		}
		
		bits--;
		
		clock = read(SCLK);
		
		while(clock > 0)
		{
			
			if (bit_unvalid_time == 0)
			{
				return (0);
			}
			
			clock = read(SCLK);
			
			bit_unvalid_time--;
		}
		
	}
	
	return (data);
}
		


static void hspiConfig(unsigned int bitorder, unsigned int clockspeed, unsigned int pol, unsigned int phase)
{
	USICTL0 = USISWRST; //Reset the USI
	
	USICTL0 |= USIOE; //Enable output
	USICTL0 |= USIGE; //Output latch always on
	USICTL0 |= USIMST; //Set USI to SPI Master mode
	USICTL0 |= USIPE5; //SCLK Enable
	USICTL0 |= USIPE6; //SDO Enable
	USICTL0 |= USIPE7; //SDI Enable
	
	if (bitorder == LSBFIRST)
	{
		USICTL0 |= USILSB; //LSB First
	}
	
	if (phase = FALLING_EDGE)
	{
		USICTL1 |= USICKPH; 
	}
	
	
	if (clockspeed == SLOW)
	{
		USICKCTL |= USIDIV_4; // MCLK / 16 = SPI Clk
	}
	
	USICKCTL |= USISEL_1;
	
	if (USICKPL == HIGH)
	{
		USICKCTL |= USICKPL;
		USICKCTL |= USISWCLK; 
	}
	
	USICTL0 &= ~USISWRST;
}

static void hspiOut(unsigned char data)
{
	
	USISRL = data;
	USICNT = 0x08;
	
	if (CLOCKSPEED == FAST)
	{
		delayus(1);
	}
	else
	{
		delayus(16)
	}
	
}

static unsigned char hspiIn()
{	
	while (status != 8)
	{
		unsigned char status = USICNT & ~0xF0;
	}
	
	USICNT = 0;
	
	return(USISRL);
}
	
static void usiOff(void)
{
	USICTL0 = USISWRST;
}



//High
//---------------------------------------------------------
static void high(unsigned int pin)
{
	if (pin <= 7)
	{
		if (pin == 0)
		{
			pin = 0x01;
		}
		else
		{
			
			pin = bit(pin);
		}
		
			
		P1DIR |= pin;
		P1OUT |= pin;
	}
	
	if (pin <= 16 && pin >= 8)
	{
		pin = pin - 8;
		pin = bit(pin);
		
		P2DIR |= pin;
		P2OUT |= pin;
	}


	if (pin <= 32 && pin >= 17)
	{
		pin = pin - 16;
		pin = bit(pin);
		
		P3DIR |= pin;
		P3OUT |= pin;
	}

}


//Low
//----------------------------------------------------
static void low(unsigned int pin)
{
	if (pin <= 7)
	{
		pin = bit(pin);
		
		P1DIR |= pin;
		P1OUT &= ~pin;
	}
	
	if (pin <= 16 && pin >= 8)
	{
		pin = pin - 8;
		pin = bit(pin);
		
		P2DIR |= pin;
		P2OUT &= ~pin;
	}
	


	if (pin <= 32 && pin >= 17)
	{
		pin = pin - 16;
		pin = bit(pin);
		
		P3DIR |= pin;
		P3OUT &= ~pin;
	}



}

//output
//----------------------------------------------------------------------------

static void output(unsigned int pin)
{
	if (pin <= 7)
	{
		pin = bit(pin);
		
		P1DIR |= pin;
	}
	
	if (pin <= 16 && pin >= 8)
	{
		pin = pin - 8;
		pin = bit(pin);
		
		P2DIR |= pin;
	}
	


	if (pin <= 32 && pin >= 17)
	{
		pin = pin - 16;
		pin = bit(pin);
		
		P3DIR |= pin;
	}



}

//input
//--------------------------------------------------------------------------------------

static void input(unsigned int pin)
{
	if (pin <= 7)
	{
		pin = bit(pin);
		
		P1DIR &= ~pin;
	}
	
	if (pin <= 16 && pin >= 8)
	{
		pin = pin - 8;
		pin = bit(pin);
		
		P2DIR &= ~pin;
	}
	


	if (pin <= 32 && pin >= 17)
	{
		pin = pin - 16;
		pin = bit(pin);
		
		P3DIR &= ~pin;
	}



}

//Read
//---------------------------------------------------------------

static unsigned int read(unsigned int pin)
{
	if (pin <= 7){
		return (P1IN & bit(pin));}
		
	if (pin <= 16 && pin >= 8){
		return (P2IN & bit(pin));}
	

	
	if (pin <= 32 && pin >= 17){
		return (P3IN & bit(pin));}
		


	return(0);
}




static void main()
{
	stopwd();
	setup();
	
	while(1)
	{
		loop()
	}
}

static void digitalWrite(unsigned int pin, unsigned int state)
{
	if(state == HIGH)
	{
		high(pin);
	}
	else
	{
		low(pin);
	}
}

static unsigned int digitalRead(unsigned int pin)
{
	register unsigned int val = read(pin);
	return(val);
}

static void pinMode(unsigned int pin, unsigned int mode)
{
	if (mode == INPUT)
	{
		input(pin);
	}
	else
	{
		output(pin);
	}
}

static void delay(unsigned int time);
{
	delayms(time);
}

static void delayMicroseconds(unsigned int time)
{
	delayus(time);
}

static void micros(unsigned int time)
{
	delayus(time);
}

static void millis(unsigned int time)
{
	delayms(time);
}




//Interrupts
//==============================================================================

#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
	if (timerEnabled = 1)
	{
		WDT_int();
	}
}

#pragma vector=RESET
__interrupt void reset(void)
{
	
}
