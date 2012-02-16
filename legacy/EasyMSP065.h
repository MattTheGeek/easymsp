/* Licence Information
Fair Use Licence
======================================================
Copyright Matthew L. Burmeister Mar. 1th 2011 All Rights Reserved.

Usage of the works is permitted provided that this instrument is retained with the works, so that any entity that uses the works is notified of this instrument.

DISCLAIMER: THE WORKS ARE WITHOUT WARRANTY.
*/

/*Programmer Comments
This licence may be changed at product release and/or in other devlopmental releases.
This file is the standard EasyMSP library version 0.6.5 Alpha

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

#ifndef EASYMSP065_H
#define EASYMSP065_H

//Alright, lets define the pins
//We use a bit-mask to change the states on the pins
static const unsigned char M16 = 0x01;
static const unsigned char M12 = 0x02;
static const unsigned char M8 = 0x03;
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

static const unsigned char YES = 1;
static const unsigned char NO = 0;
static const unsigned char MSBFIRST = 0;
static const unsigned char LSBFIRST = 1;
static const unsigned char FAST = 1;
static const unsigned char SLOW = 0;

static const unsigned char DEFAULT = 1;
static const unsigned char INTERNAL = 2;
static const unsigned char INTERNAL1V1 = 3;
static const unsigned char INTERNAL2V56 = 4;
static const unsigned char EXTERNAL = 5;

//EasyMSP Prototypes
//=====================================

//GPIO
unsigned char read(unsigned char pin);
void high(unsigned char pin);
void low(unsigned char pin);

//System
void stopwd();
void delaySec(unsigned int time);
void delayMs(unsigned int time);
void setup();
void freqSet(char freq);
void reset();
void shutdown();

//SPI
void spiOut(unsigned char spidata);
unsigned char spiIn();

//I2C

//Timer

//Arduino Prototypes
//======================================
void digitalWrite(unsigned char pin, unsigned char mode);
unsigned char digitalRead(unsigned char pin);
void pinMode(unsigned char pin, unsigned char state);
unsigned int analogRead(unsigned char pin);
void analogReference(unsigned char mode);

/* Begin Functions */

//Test Main()

//high()
//=============================================
//Inputs: Pin to make high
//Returns: Nothing
//Actions: Causes a pin to go logical high
void high(unsigned char pin)
{
  P1DIR |= pin;
  P1OUT |= pin;
}

//Low()
//=============================================
//Inputs: Pin to make low
//Returns: Nothing
//Actions: Causes a pin to go logical low
void low(unsigned char pin)
{
  P1DIR |= pin;
  P1OUT &= ~pin; 
}

//read()
//=============================================
//Inputs: pin to read
//Returns: pin state
//Actions: ANDs the P*IN Register and returns a boolean value depending on the state
unsigned char read(unsigned char pin)
{
	unsigned char result;
	result = pin & P1IN;
	
	if (result > 0)
	{
		return 0;
	}
	
	else
	{
		return 1;
	}  
}

//This function mimics the arduino's digitalWrite function
void digitalWrite(unsigned char pin, unsigned char state)
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
void pinMode(unsigned char pin, unsigned char state)
{
	if(state == 0)
	{
		P1DIR &= ~pin; 
	}
	else
	{
		P1DIR |= pin;
	}
}

//This function mimics the arduinos digitalRead command
unsigned char digitalRead(unsigned char pin)
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
void delaySec(unsigned int timesec)
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
void delayMs(unsigned int time)
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
void spiOut(unsigned char spidata)
{
	USISRL = spidata;
	USICNT = 8;
}

unsigned int analogRead(unsigned char pin)
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
		break;
		
		case 0x02:
		ADC10CTL1 |= INCH_1;
		break;
		
		case 0x04:
		ADC10CTL1 |= INCH_2;
		break;
		
		case 0x08:
		ADC10CTL1 |= INCH_3;
		break;
		
		case 0x010:
		ADC10CTL1 |= INCH_4;
		break;
		
		case 0x20:
		ADC10CTL1 |= INCH_5;
		break;
		
		case 0x40:
		ADC10CTL1 |= INCH_6;
		break;
		
		case 0x80:
		ADC10CTL1 |= INCH_7;
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


void analogReference(unsigned char ref)
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
void reset()
{
	WDTCTL = 0;
}

void shutdown()
{
	//Enters the CPU into LPM4
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
		
		if (FREQ == M12)
		{
		//Set CPU to 12Mhz
		
		}
		
		if (FREQ == M8)
		{
		//Set CPU to 4Mhz
		
		}
		
		if (FREQ == M1)
		{
		//Set CPU to 1MHZ
		BCSCTL1 = CALBC1_1MHZ;
		DCOCTL = CALDCO_1MHZ;
		}	
			
		if (FREQ == K500)
		{
				//Set CPU to 500KHZ
		}
		
		if (FREQ == K100)
		{
		//Set CPU to 100KHZ
		}
		
		if (FREQ == K12)
		{
		//Set CPU to 12Khz
		}
}

#ENDIF