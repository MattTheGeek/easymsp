/* Licence Information

This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/3.0/ or send a letter to Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.

*/

/*Programmer Comments
This licence may be changed at product release and/or in other devlopmental releases.
This file is the standard EasyMSP library version 0.6.7 Alpha

EasyMSP has gone from idea into a project in less than 14 weeks, Truly ammazing i belive. 
I Hope you enjoy this pre-dev-alpha release of EasyMSP. also i've created a few sites for you to check out.

www.code.google.com/p/easymsp/  <- Holds the source
and
www.sites.google.com/site/easymsp/ <- Main site

Again, i hope you find this release to be useful

Regards,
Matthew L. Burmeister
Owner and Head Dev.
*/

//Alright, lets define the pins
//We use a bit-mask to change the states on the pins
static const unsigned char M16 = 0x01;
static const unsigned char M8 = 0x02;
static const unsigned char M4 = 0x03;
static const unsigned char M1 = 0x04;
static const unsigned char K500 = 0x05;
static const unsigned char K100 = 0x06;
static const unsigned char K12 = 0x07;

static const unsigned char pin0=0x01;
static const unsigned char pin1=0x02;
static const unsigned char pin2=0x04;
static const unsigned char pin3=0x08;
static const unsigned char pin4=0x10;
static const unsigned char pin5=0x20;
static const unsigned char pin6=0x40;
static const unsigned char pin7=0x80;

//P2 Pins
//These pins are not masks
static const unsigned char pin8=0x81;
static const unsigned char pin9=0x82;

static const unsigned char YES = 1;
static const unsigned char NO = 0;
static const unsigned char MSB = 0;
static const unsigned char LSB = 1;
static const unsigned char FAST = 1;
static const unsigned char SLOW = 0;

static const unsigned char DEFAULT = 1;
static const unsigned char INTERNAL = 2;
static const unsigned char INTERNAL1V1 = 3;
static const unsigned char INTERNAL2V56 = 4;
static const unsigned char EXTERNAL = 5;

static unsigned char CLKM;

//EasyMSP Prototypes
//=====================================

//GPIO
static unsigned char read(unsigned char pin);
static void high(unsigned char pin);
static void low(unsigned char pin);

//System
static void stopwd();
static void delaySec(unsigned int time);
static void delayMs(unsigned int time);
static void setup();
static void freqSet(char freq);
static void reset();
static void shutdown();

//SPI
static void spiOut(unsigned char spidata);
static unsigned char spiIn();

//I2C

//Timer

//Arduino Prototypes
//======================================
static void digitalWrite(unsigned char pin, unsigned char mode);
static unsigned char digitalRead(unsigned char pin);
static void pinMode(unsigned char pin, unsigned char state);
static unsigned int analogRead(unsigned char pin);
static void analogReference(unsigned char mode);
static void shiftOut(unsigned char SCK, unsigned char DOUT, unsigned char byteorder, unsigned char data);
static unsigned char shiftIn(unsigned char SCK, unsigned char DIN, unsigned char byteorder);
static void bit(unsigned char bit);

/* Begin Functions */

//Test Main()
//We use this main to test out the library

//high()
//=============================================
//Inputs: Pin to make high
//Returns: Nothing
//Actions: Causes a pin to go logical high
void high(unsigned char pin)
{
	switch (pin)
	{
		default:
  		P1DIR |= pin;
 		P1OUT |= pin;
 		break;
 		
		case 0x81:
		P2DIR |= 0x01;
		P2OUT |= 0x01;
		break; 
		
		case 0x82:
		P2DIR |= 0x02;
		P2OUT |= 0x02;
		break;
		
	}
}

//Low()
//=============================================
//Inputs: Pin to make low
//Returns: Nothing
//Actions: Causes a pin to go logical low
void low(unsigned char pin)
{
	switch (pin)
	{
		default:
  		P1DIR |= pin;
  		P1OUT &= ~pin; 
  		break;
  		
  		case 0x81:
  		P2DIR |= 0x40;
  		P2OUT &= ~0x40;
  		break;
  		
  		case 0x82:
  		P2DIR |= 0x80;
  		P2OUT &= ~0x80;
	}
}

//read()
//=============================================
//Inputs: pin to read
//Returns: pin state
//Actions: ANDs the P*IN Register and returns a boolean value depending on the state
unsigned char read(unsigned char pin)
{
	unsigned char result;
	
	switch (pin)
	{
		default:
		result = pin & P1IN;
		break;
		
		case 0x81:
		result = 0x40 & P2IN;
		break;
		
		case 0x82:
		result = 0x80 & P2IN;
		break;
	}
		if (result > 0)
		{
			return(0);
		}
	
		else
		{
			return(1);
		}		  
}

//This function mimics the arduino's digitalWrite function
static void digitalWrite(unsigned char pin, unsigned char state)
{
	if (state == 0)
	{
		low(pin);
	}
	else
	{
		high(pin);
	}
}

//this function mimics the arduinos pinMode command
static void pinMode(unsigned char pin, unsigned char state)
{
	if(state == 0)
	{
		switch (pin)
		{
			default:
			P1DIR &= ~pin;
			break;
			
			case 0x81:
			P2DIR &= ~0x40;
			break;
			
			case 0x82:
			P2DIR &= ~0x80;
		} 
	}
	else
	{
		switch (pin)
		{
			default:
			P1DIR |= pin;
			break;
			
			case 0x81:
			P2DIR |= 0x40;
			break;
			
			case 0x82:
			P2DIR |= 0x80;
		} 
	}
}

//This function mimics the arduinos digitalRead command
static unsigned char digitalRead(unsigned char pin)
{
	unsigned char var;
	var = read(pin);
	return (var);
}

//delayMS(time)
//=============================================
//Inputs: Delay time.
//Returns: Nothing
//Actions: Delays the MCU for said mS.
static void delaySec(unsigned int timesec)
{
	while(timesec > 0)
	{
		delayMs(1000);
		timesec--;
	}
}

//delayMS(time)
//=============================================
//Inputs: Delay time.
//Returns: Nothing
//Actions: Delays the MCU for said mS.
static void delayMs(unsigned int time)
{
	unsigned int timens=0;
	unsigned int timeus=0;
	
	while(time > 0)
	{
		while (timeus != 50)
		{
			while(timens != 8)
			{
				timens++;
			}
			
			timeus++;
		}
		
		time--;
		timens=0;
		timeus=0;
	}	
}

//spiOut
//=============================================
//Inputs: Data to be sent
//Returns: Nothing
static void spiOut(unsigned char spidata)
{
	USISRL = spidata;
	USICNT = 8;
}

static unsigned int analogRead(unsigned char pin)
{
	//Ok, we need to setup the ADC10.
	//ADC10CTL0 |= SREF_0; //Set Ref to VCC and VDD
	ADC10CTL0 |= ADC10SHT_0; //Sample And Hold 4 clokcs
	//ADC10CTL0 |= ADC10SR; // enable for low power mode
	//ADC10CTL0 |= REFBURST;
	switch(pin)
	{
		case 0x01:
		ADC10CTL1 |= INCH_0;
		ADC10AE0 |= 0x01;
		break;
		
		case 0x02:
		ADC10CTL1 |= INCH_1;
		ADC10AE0 |= 0x02;
		break;
		
		case 0x04:
		ADC10CTL1 |= INCH_2;
		ADC10AE0 |= 0x04;
		break;
		
		case 0x08:
		ADC10CTL1 |= INCH_3;
		ADC10AE0 |= 0x08;
		break;
		
		case 0x010:
		ADC10CTL1 |= INCH_4;
		ADC10AE0 |= 0x10;
		break;
		
		case 0x20:
		ADC10CTL1 |= INCH_5;
		ADC10AE0 |= 0x20;
		break;
		
		case 0x40:
		ADC10CTL1 |= INCH_6;
		ADC10AE0 |= 0x40;
		break;
		
		case 0x80:
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
	
	int ADCBUSY=0;
	
	while (ADCBUSY != 1)
	{
		ADCBUSY = ADC10CTL1 & ADC10BUSY;
	}
	
	return (ADC10MEM);
	
}


static void analogReference(unsigned char ref)
{
	if (ref == DEFAULT)
	{
		ADC10CTL0 &= ~SREF_7; //Clear the register
		ADC10CTL0 |= SREF_0;
	}
	
	if (ref == INTERNAL)
	{
		ADC10CTL0 &= ~SREF_7; //Clear the register
		ADC10CTL0 |= SREF_0;
	}
	
	if (ref == INTERNAL1V1)
	{
		ADC10CTL0 &= ~SREF_7; //Clear the register
		ADC10CTL0 |= SREF_1 + REFON;
		ADC10CTL0 &= ~REF2_5V;
	}
	
	if (ref == INTERNAL2V56)
	{
		ADC10CTL0 &= ~SREF_7; //Clear the register
		ADC10CTL0 |= SREF_1 + REFON + REF2_5V;
	}
	
	if (ref == EXTERNAL)
	{
		ADC10CTL0 &= ~SREF_7; //Clear the register
		ADC10CTL0 |= SREF_2;
	}
}


//Reset the controller
static void reset()
{
	WDTCTL = 0;//We take a shortcut to make a PUC. With a incorrect watchdog password, the controller preforms a PUC(Reset)
}

void shutdown()
{
	//Enters the CPU into LPM4
  __bic_SR_register(CPUOFF + OSCOFF + SCG0 + SCG1);
}

//stopwd()
//=============================================
//Inputs: Nothing
//Returns: Nothing
//Actions: Stops the system watchdog.
void stopwd()
{
   //Stop the watchdog
   WDTCTL = WDTPW + WDTHOLD;
}

//setup()
//=============================================
//Inputs: Nothing
//Returns: Nothing
//Actions: Setups the EasyMSP System.
void setup()
{
  	stopwd();
  //Other tasks required here
}

//Changes the systems clock
//Unfunctional Prototype
void setfreq(unsigned char FREQ)
{
	
		if (FREQ == M16)
		{
		//Set CPU to 16MHZ
		
		}
		
		if (FREQ == M8)
		{
		//Set CPU to 12Mhz
		
		}
		
		if (FREQ == M4)
		{
		//Set CPU to 4Mhz
		
		}
		
		if (FREQ == M1)
		{
		//Set CPU to 1MHZ
		CLKM = M1;
		BCSCTL1 = CALBC1_1MHZ;
		DCOCTL = CALDCO_1MHZ;
		}	
			
		if (FREQ == K500)
		{
				CLKM = K500;
				BCSCTL1 = CALBC1_1MHZ;
				BCSCTL2 = DIVM_1 + DIVS_1;
				DCOCTL = CALDCO_1MHZ;
				
		}
		
		if (FREQ == K100)
		{
		//Set CPU to 100KHZ
		CLKM = K100;
		BCSCTL1 |= 0x80;
		BCSCTL2 |= DIVM_0 + DIVS_0;
		DCOCTL = 0x40;
		
		
		}
		
		if (FREQ == K12)
		{
		//Set CPU to 12Khz
		}
}

void shiftOut(unsigned char SCK, unsigned char DOUT, unsigned char byteorder, unsigned char data)
{
	unsigned char bitnum=0;
	unsigned char val=0;
	
	while(bitnum != 8)
	{
		if (byteorder == MSB)
		{
			val = data & 0x80;
		}
		else
		{
			val = data & 0x01;
		}
				
		if (val == 128)
		{
			high(DOUT);
		}
		else
		{
			low(DOUT);
		}
		high(SCK);
		delayMs(1);
		low(SCK);
		
		if (byteorder == MSB)
		{
			data >> 1;
		}
		else
		{
			1 << data;
		}
		
		bitnum++;
		val=0;
	}
}
		
unsigned char shiftIn(unsigned char SCK, unsigned char DIN, unsigned char byteorder)
{
	unsigned char clock=0;
	unsigned char bit=0;
	unsigned char byte=0;
	unsigned char bitnum=0;
	
	while(bitnum != 8)
	{
		while(clock == 0)
		{
			clock = read(SCK);
		}
		
		bit = read(DIN);
		
		if (byteorder == MSB)
		{
			byte = bit |= 0x80;
			byte >> 1;
		}
		else
		{
			byte = bit |= 0x01;
			1 << byte;
		}
		
		while(clock == 1)
		{
			clock = read(SCK);
		}
		bitnum++;
	}
	return (byte);
}

static unsigned char bit(unsigned char bit)
{
	unsigned char bitreturn=0;
	
	switch (bit)
	{
		default:
		bitreturn = 0;
		break;
		
		case 0:
		bitreturn = 0x01;
		break;
		
		case 1:
		bitreturn = 0x02;
		break;
		
		case 2:
		bitreturn = 0x04;
		break;
		
		case 3:
		bitreturn = 0x08;
		break;
		
		case 4:
		bitreturn = 0x10;
		break;
		
		case 5:
		bitreturn = 0x20;
		break;
		
		case 6:
		bitreturn = 0x40;
		break;
		
		case 7:
		bitreturn = 0x80;
		break;
	}
	
	return (bitreturn);
}
