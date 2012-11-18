/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	hd44780.c
 *	HD44780 based LCD Driver for EasyMSP. 
 *  
 *  
 *	Part of the EasyMSP Project
 *	www.code.google.com/p/EasyMSP/
 *
 *	Author: Matthew L. Burmeister
 *	Copyright (c) 2010, 2011, 2012 All rights reserved.
 *
 *	Contact
 *		You can contact me by email at matthewburmeister@gmail.com 
 *		or by sending mail to:
 *
 *		Matthew Burmeister
 *		11593 Autunno St
 *		Las Vegas, NV 89183
 *		United States of America
 *
 *	Licence
 *		EasyMSP is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		EasyMSP is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with EasyMSP. If not, see <http://www.gnu.org/licenses/>.
 *
*/



#include <msp430.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define D4 0x01
#define D5 0x02
#define D6 0x04
#define D7 0x08

#define RS 0x01
#define RW 0x02
#define EN 0x04

#define COMMAND 0
#define DATA 1

#define ON 1
#define OFF 0

/*
 * Register Select (RS). RS=0: Command, RS=1: Data
  Read/Write (R/W). R/W=0: Write, R/W=1: Read
   Clock (Enable). Falling edge triggered
 */

static struct _hd44780_ioPins
{
	unsigned char D4;
	unsigned char D5;
	unsigned char D6;
	unsigned char D7;
	
	unsigned char RS;
	unsigned char RW;
	unsigned char EN;
};

static unsigned char _hd44780_flags = 0;


void lcdPower(unsigned char state)
{
	if (state)
	{
		lcdWrite((BIT3 | BIT2), COMMAND);
	}
	else
	{
		lcdWrite((BIT3), COMMAND);
	}

}

void lcdString(char* string)
{
	do
	{
		lcdWrite(*string, DATA);
		string++;
	}
	while (*string != 0);
}

void lcdClear(void)
{
	lcdWrite(0x01, COMMAND);
	_delay_cycles(3000);
	return;
}

void lcdWrite(unsigned char data, unsigned char type)
{
	P1OUT &= ~(D4 | D5 | D6 | D7);
	P2OUT &= ~(EN | RS | RW);

	if (type == DATA)
	{
		P2OUT |= RS;
	}

	/* Transfer first nibble. MSB */
	P2OUT |= EN;
	P1OUT |= (data >> 4);
	P2OUT &= ~EN;

	P1OUT &= ~(D4 | D5 | D6 | D7);
	/* Transfer last nibble */
	P2OUT |= EN;
	P1OUT |= ((data << 4) >> 4);
	P2OUT &= ~EN;
	
	_delay_cycles(500);

}

void lcdSetup(void)
{
	P1OUT = 0x00;
	P1DIR = 0xFF;
	P2OUT = 0x00;
	P2DIR = 0xFF;

	P2OUT |= EN;
	P1OUT = D5; /* Set to 4bit interface */
	P2OUT &= ~EN;

	lcdWrite((BIT5 | BIT3 | BIT2), COMMAND); /* 2 line, 5x10 font */

	lcdClear();

	return;

}
