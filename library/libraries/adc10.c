/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	adc10.c
 *	ADC10 Library for EasyMSP. 
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

inline void analogOff(void)
{
	
}

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')

unsigned short int analogRead(unsigned short int pin)
{
	
	if (pin > 7) 
	{
		return (NULL); /* Return if pin number is out of range. */
	}

	ADC10CTL1 &= ~INCH_15; /* We can't clear the whole ADC10CTL1 register, so just NAND bits 11 to 8 */
	ADC10CTL1 |= (pin << 12);	/*  Set the analog channel to pin. By shifting pin by 12 bits*/
	ADC10AE0 = (1 << pin); /* Set the analog channel enable */
	
	return (ADC10MEM);

}

#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)
/* The F5/F6 family MSP430s have a different ADC10 features */

unsigned short int analogRead(unsigned short int pin)
{
	/* todo: Rewrite ADC10 code */
	ADC10MCTL0 &= ~ADC10INCH_15;
	ADC10MCTL0 |= (pin);

	return (ADC10MEM);
}

#endif

#pragma vector = ADC10_VECTOR;
interrupt void adc10_isr(void)
{
	return;
}
