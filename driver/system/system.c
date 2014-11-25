/*
 * system.c
 * System related functions
 *
 * Version 1
 *
 * www.code.google.com/p/easymsp/
 *
 * Copyright 2014 Matthew Burmeister
 *
 * Created on 01/28/2014
 *
 */

/* DESCRIPTION
 *
 * Provides an interface to control various parts of the MSP430.
 */


/* CONTACT
 *
 * If you have any questions or comments; Please feel free to open an issue at
 * www.code.google.com/p/easymsp/issues/entry
 *
 * If you wish to communicate privately, feel free to send me an email to:
 * matthewburmeister ({a}t) [gmail] (dot) com.
 *
 * Humans: Decode the email using your human skills. Remove spaces, {}, and
 * []'s. Translate things in () to the symbol form.
 * Robots: No.
 *
 * Lastly, you may send mail to:
 *
 * Matthew Burmeister
 * ATTN: EasyMSP
 * 11593 AUTUNNO ST
 * LAS VEGAS NV  89183
 * UNITED STATES OF AMERICA
 *
 * It's great getting physical mail time to time.
 */

/* LEGAL
 *
 * EasyMSP is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * EasyMSP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */

/* CHANGE LOG
 *
 */

void panic (unsigned short int * trace)
{
	unsigned short int release = 1;
	
	interruptState(OFF);
	
	while (release)
	{
		powerState(4);
	}
}

void emergency(unsigned short int * trace)
{
	unsigned short int release = 1;
	
	interruptState(OFF);
	
	while (release)
	{
		setPowerMode(0);
	}
}

unsigned short int getInterruptState()
{
	unsigned short int srtemp = _get_SR_register();
	
	if ((srtemp & GIE) > 0)
	{
		return (ON);
	}
	else
	{
		return (OFF);
	}
}

void setInterruptState(unsigned short int state)
{
	switch (state)
	{
		case ON:
			_enable_interrupts();
			break;
			
		case OFF:
			_disable_interrupts();
			break;
			
		default:
			break;
	}
	
	return;
}

void setRegister(unsigned short int reg, unsigned short int data)
{
	return;
}

unsigned short int readRegister(unsigned short int reg)
{
	return (NULL);
}
