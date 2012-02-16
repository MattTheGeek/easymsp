/* Licence Information
Fair Use Licence
======================================================
Copyright Matthew L. Burmeister Feb. 25th 2011 All Rights Reserved.

Usage of the works is permitted provided that this instrument is retained with the works, so that any entity that uses the works is notified of this instrument.

DISCLAIMER: THE WORKS ARE WITHOUT WARRANTY.
*/

/*Programmer Comments
This licence may be changed at product release and/or in other devlopmental releases.
This file is the standard EasyMSP library version 0.4.3 Pre-Alpha

EasyMSP has gone from idea into a project in less than 10 weeks, Truly ammazing i belive.
I Hope you enjoy this pre-dev-alpha release of EasyMSP. also i've created a few sites for you to check out.

www.code.google.com/p/easymsp/  <- Holds the source
and
www.sites.google.com/site/easymsp/ <- Main site

Again, i hope you find this release to be useful

Regards,
Matthew L. Burmeister
*/
#include "msp430g2231.h"

//Alright, lets define the pins
//We use a bit-mask to change the states on the pins
const int pin0=0x01;
const int pin1=0x02;
const int pin2=0x04;
const int pin3=0x08;
const int pin4=0x10;
const int pin5=0x20;
const int pin6=0x40;
const int pin7=0x80;

//Function Prototypes
//Not thing speical here...
void delay(int cycle);
void high(int pin);
void low(int pin);
void stopwd();
void delayMs();
void delaycycle();
void read(int);
void digitalWrite(int, int);
void digitalRead(int, int);
void pinMode(int, int);

void high(int pin)
{
  P1DIR |= pin;
  P1OUT |= pin;
}

void low(int pin)
{
  P1DIR |= pin;
  P1OUT &= ~pin;
}

int read(int pin)
{
	int result;
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

void digitalWrite(int pin, int state)
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

void pinMode(int pin, int State)
{
	if(State == 0)
	{
		P1DIR &= ~pin;
	}
	else
	{
		P1DIR |= pin;
	}
}

void digitalRead(int pin)
{
	read(pin);
}

void delay(int time)
{
  while (time > 0)
  {
    delayMs();
    time = time - 1;
  }
}

void delay16()
{
  asm("NOP");
  asm("nop");
  asm("NOP");
  asm("nop");
  asm("NOP");
  asm("nop");
  asm("NOP");
  asm("nop");
  asm("NOP");
  asm("nop");
  asm("NOP");
  asm("nop");
  asm("NOP");
  asm("nop");
  asm("NOP");
}

void delaycycle()
{
}

void stopwd()
{
   //Stop the watchdog
   WDTCTL = WDTPW + WDTHOLD;
}
}
