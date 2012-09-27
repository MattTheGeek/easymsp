/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	io.c
 *	Library for high level access of GPIO ports.   
 *
 *	Part of the EasyMSP Project
 *	www.code.google.com/p/EasyMSP/
 *
 *	Author: Matthew L. Burmeister
 *	Copyright (c) 2010, 2011, 2012 All rights reserved.
 *
 *	You can contact me at matthewburmeister@gmail.com
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

/* Info
 *
 *	Library merge
 *		Since the library merge of the 2 _EM_SERIES library and the newer 5 _EM_SERIES library, the IO library is split up into three sections. The First section is for global functions
 *		that rely on the lower level functions below.
 *
 *		The second section is the 2 _EM_SERIES (or just 8-bit port) library functions. and the third is currently the 5 _EM_SERIES (16 bit port) library functions.
 *
 *		The library will issue a preprocessor error if the device _EM_SERIES is not declared or incorrect.
 *
 *	Function Name Changes
 *		Most function names have been changed, as they were quite vague on what they do. A example would be readPin(), since read() could mean anything and the old input() and
 *		output() functions have been consolidated into one specific function, pinMode(). However, this change does break compatibility with obsolete versions.
 *
 *	Inlining
 *		All functions should created inline, as if the exact code was generated, the code size and processing time would increase substantially and performance will deteriorate.
 *
 *	Bitmasks
 *		EasyMSP generates bitmasks by shifting 1 by x times.
 *
 *	Figuring out ports
 *		The IO library determines what port to operate on by following a simple algorithm.
 *
 *		If pin is less than or equal to the (port width - 1)...
 *			Operate on port and return.
 *		if pin is higher than the (port width - 1)
 *			Subtract the port width from pin.
 *			Goto next port block if it exists, otherwise subtract again and goto the next port block.
 *
 */
 
#ifndef IO_H
#	include "io.h"
#endif
 
#ifndef IO_C
#define IO_C

#ifdef _EM_SERIES 
#	if (_EM_PREINIT_VECTORS == YES)
		void (*Port1FunctionVector[8])(void) = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
		void (*Port2FunctionVector[8])(void) = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
#	else
		void (*Port1FunctionVector[8])(void);
		void (*Port2FunctionVector[8])(void);
#	endif /* PREINIT_VECTORS */
		
	static unsigned char _shiftConfigBits = 0;	
#endif /* _EM_SERIES */
	
#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')

void pinHigh(unsigned short int pin)
{

#ifdef _EM_HASPORT1 /* Does the device has PORT1? */
	
	if (pin <= 7) /* If pin is equal or less than 7, then we operate on PORT1 */
	{
		/* We need to generate a bitmask for P1OUT, we do this by shifting 0x01 by pin. This produces a bitmask that for the desired bit and pin. */
		P1OUT |= (1 << pin); /* OR the generated bit mask to PxOUT to set the bit and make the pin high */
		return;
	}

#endif /* _EM_HASPORT1 */
	
	pin = pin - 8; /* Since the value was higher than 8, subtract by 8 and later compare */

	/* The next code blocks are generally the same as above, just operating on a different port */

#ifdef _EM_HASPORT2 /* Does the device has PORT2? */
	
	if (pin <= 7)
	{
		P2OUT |= (1 << pin);
		return;
	}

#endif /* _EM_HASPORT2 */
	
	pin = pin - 8;

#ifdef _EM_HASPORT3 /* Does the device has PORT3? */
	
	if (pin <= 7)
	{
		P3OUT |= (1 << pin);
		return;
	}

#endif /* _EM_HASPORT3 */
	
#ifdef _EM_HASPORT4 /* Does the device has PORT4? */

	pin = pin - 8;

	if (pin <= 7)
	{
		P4OUT |= (1 << pin);
		return;
	}

#endif /* _EM_HASPORT4 */
	
	return;
}

void pinLow(unsigned short int pin)
{

#ifdef _EM_HASPORT1 /* Does the device has PORT1? */
	
	if (pin <= 7) /* If pin is equal or less than 7, then we operate on PORT1 */
	{
		/* We need to generate a bitmask for P1OUT, we do this by shifting 0x01 by pin. This produces a bitmask that for the desired bit and pin. */

		P1OUT &= ~(1 << pin); /* NAND the generated bit mask to PxOUT to clear the bit and set the pin low */

		return; /* Feturn from function */
	}

#endif /* _EM_HASPORT1 */
	
	pin = pin - 8; /* Since the value was higher than 8, subtract by 8 and later compare */

	/* The next code blocks are generally the same as above. */

#ifdef _EM_HASPORT2  /* Does the device has PORT2? */
	
	if (pin <= 7)
	{
		P2OUT &= ~(1 << pin);

		return;
	}

#endif /* _EM_HASPORT2 */
	
	pin = pin - 8;

#ifdef _EM_HASPORT3  /* Does the device has PORT3? */
	
	if (pin <= 7)
	{
		P3OUT &= ~(1 << pin);

		return;
	}

#endif /* _EM_HASPORT3 */
	
#ifdef _EM_HASPORT4  /* Does the device has PORT4? */
	
	pin = pin - 8;

	if (pin <= 7)
	{
		P4OUT &= ~(1 << pin);
	}

#endif /* _EM_HASPORT4 */
	
	return; /* Return from the last function or the pin was out of range. */
}

void pinMode(unsigned short int pin, unsigned short int state)
{

	if (state > 1) /* Check for invaild state */
	{
		return; /* State was higher than 1, return */

		/* Since we have two states
		 *
		 * INPUT 0
		 * OUTPUT 1
		 *
		 * we can assume that anything higher is invaild.
		 *
		 */
	}

#ifdef _EM_HASPORT1 /* Does the device have PORT1? */

	if (pin <= 7) /* Is pin equal or lower to 7? */
	{
		if (state == OUTPUT)
		{
			/* If the state is output, We need to set the PxDIR bit */

			P1DIR |= (1 << pin); /* Produce bitmask by shifting 1 by pin, and then OR to PxDIR */
		}
		else
		{
			/* Otherwise we can assume state is input, So we need to clear the PxDIR bit */

			P1DIR &= ~(1 << pin); /* Produce bitmask by shifting 1 by pin, and then NAND to PxDIR */
		}

		return; /* Return */
	}

#endif /* _EM_HASPORT1 */

	pin = pin - 8; /* Since the pin is higher than 8, subtract by 8 and then compare again. */

	/* The next blocks of code are like the above block */

#ifdef _EM_HASPORT2 /* Does the device have PORT2 */

	if (pin <= 7)
	{
		if (state == OUTPUT)
		{
			P2DIR |= (1 << pin);
		}
		else
		{
			P2DIR &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORT2 */

	pin = pin - 8;

#ifdef _EM_HASPORT3 /* Does the device have PORT3? */
	
	if (pin <= 7)
	{
		if (state == OUTPUT)
		{
			P3DIR |= (1 << pin);
		}
		else
		{
			P3DIR &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORT3 */

#ifdef _EM_HASPORT4 /* Does the device has PORT4? */
	
	pin = pin - 8;

	if (pin <= 7)
	{
		if (state == OUTPUT)
		{
			P4DIR |= (1 << pin);
		}
		else
		{
			P4DIR &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORT4 */

	return;
}

bool pinRead(unsigned short int pin)
{

#ifdef _EM_HASPORT1
	
	if (pin <= 7) /* is pin less than or equal to 7? Then operate on PORT1 */
	{
		/* We get the state of the pin by doing a bitwise AND between PxIN and the calculated bitmask */

		auto unsigned short int result = P1IN & (1 << pin);

		/* If the value stored in result is not zero, then the bit was set (pin was high). */

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			/* Otherwise, if the value stored in result IS zero, than the bit is cleared (pin is low). */

			return(LOW);
		}
	}

#endif /* _EM_HASPORT1 */

	pin = pin - 8; /* Subtract 8 from pin since pin was higher than 8 */

	/* The next blocks of code are like the above block */

#ifdef _EM_HASPORT2
	
	if (pin <= 7)
	{
		auto unsigned short int result = P2IN & (1 << pin);

		if (result > 0)
		{
			return (HIGH);
		}
		else
		{
			return (LOW);
		}

	}

#endif /* _EM_HASPORT2 */
	
	pin = pin - 8;

#ifdef _EM_HASPORT3
	
	if (pin <= 7)
	{
		auto unsigned short int result = P3IN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return (LOW);
		}
	}

#endif /* _EM_HASPORT3 */
	
#ifdef _EM_HASPORT4
	
	pin = pin - 8;

	if (pin <= 7)
	{
		auto unsigned short int result = P4IN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return (LOW);
		}
	}

#endif /* _EM_HASPORT4 */

	/* If we get here, the pin was out of range of the device. Return with the pin state as LOW. */

	return (LOW);
}

void pinToggle(unsigned short int pin)
{

#ifdef _EM_HASPORT1
	
	if (pin <= 7) /* Is pin less than or equal to 7? If yes, then operate on port1 */
	{
		/* Calculate a bitmask by shifting 1 by pin. */

		P1OUT ^= (1 << pin); /* XOR PxOUT with the bitmask, Which toggles the current state of the bit (and pin). */
		return;
	}

#endif /* _EM_HASPORT1 */
	
	pin = pin - 8; /* Since pin was higher than 8, subtract by 8 and compare again next block */

	/* The next blocks of code are like the above block */

#ifdef _EM_HASPORT2
	
	if (pin <= 7)
	{
		P2OUT ^= (1 << pin);
		return;
	}

#endif /* _EM_HASPORT2 */
	
	pin = pin - 8;

#ifdef _EM_HASPORT3
	
	if (pin <= 7)
	{
		P3OUT ^= (1 << pin);
		return;
	}

#endif /* _EM_HASPORT3 */
	
#ifdef _EM_HASPORT4
	
	pin = pin - 8;

	if (pin <= 7)
	{
		P4OUT ^= (1 << pin);
	}

#endif /* _EM_HASPORT4 */
	
	return;
}

void pinPullUp(unsigned short int pin)
{

#ifdef _EM_HASPORT1

	if (pin <= 7)
	{
		P1REN |= (1 << pin);
		P1OUT |= (1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef _EM_HASPORT2

	if (pin <= 7)
	{
		P2REN |= (1 << pin);
		P2OUT |= (1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef _EM_HASPORT3

	if (pin <= 7)
	{
		P3REN |= (1 << pin);
		P3OUT |= (1 << pin);
		return;
	}

#endif

#ifdef _EM_HASPORT4

	pin = pin - 8;

	if (pin <= 7)
	{
		P4REN |= (1 << pin);
		P4OUT |= (1 << pin);
	}

#endif

	return;
}

void pinPullDown(unsigned short int pin)
{

#ifdef _EM_HASPORT1

	if (pin <= 7)
	{
		P1REN |= (1 << pin);
		P1OUT &= ~(1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef _EM_HASPORT2

	if (pin <= 7)
	{
		P2REN |= (1 << pin);
		P2OUT &= ~(1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef _EM_HASPORT3

	if (pin <= 7)
	{
		P3REN |= (1 << pin);
		P3OUT &= ~(1 << pin);
		return;
	}

#endif

#ifdef _EM_HASPORT4

	pin = pin - 8;

	if (pin <= 7)
	{
		P4REN |= (1 << pin);
		P4OUT &= ~(1 << pin);
	}

#endif

	return;
}

void pinPullOff(unsigned short int pin)
{

#ifdef _EM_HASPORT1

	if (pin <= 7)
	{
		P1REN &= ~(1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef _EM_HASPORT2

	if (pin <= 7)
	{
		P2REN &= ~(1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef _EM_HASPORT3

	if (pin <= 7)
	{
		P3REN &= ~(1 << pin);
		return;
	}

#endif

#ifdef _EM_HASPORT4

	pin = pin - 8;

	if (pin <= 7)
	{
		P4REN &= ~(1 << pin);
	}

#endif

	return;
}

void attachInterrupt(unsigned short int pin, unsigned short int edge, void (*function)(void))
{

	/*
		todo: Need to find a proper way to check what address a function resides at.
		
		if ((unsigned short int)function <= 0x01FF) // Do not allow a function pointer to reference Peripheral module memory
		{
			return;
		}
	*/
		
	if (pin <= 7)
	{
		if (edge == HIGH_TO_LOW)
		{
			P1IES |= (1 << pin);
		}
		else if (edge == LOW_TO_HIGH)
		{
			P1IES &= ~(1 << pin);
		}
		else
		{
			return;
		}

		Port1FunctionVector[pin] = function;

		P1IFG &= ~(1 << pin);
		P1IE |= (1 << pin);

		return;
	}
	else
	{
		pin = pin - 8;

		if (pin <= 7)
		{
			if (edge == HIGH_TO_LOW)
			{
				P2IES |= (1 << pin);
			}
			else if (edge == LOW_TO_HIGH)
			{
				P2IES &= ~(1 << pin);
			}
			else
			{
				return;
			}

			Port2FunctionVector[pin] = function;

			P2IFG &= ~(1 << pin);
			P2IE |= (1 << pin);

			return;
		}
	}

	return;
}

void removeInterrupt(unsigned short int pin)
{
	if (pin <= 7) //If pin is less or equal to 7, then we need to operate on Port1
	{
		P1IE &= ~(1 << pin); //Clear Interrupt Enable flag
		
		return;//Exit
	}
	else //Check again if pin is less or equal to 7
	{
		pin = pin - 8; //Offset pin by 8.

		if (pin <= 7)//If pin is less than or equal to 7, then we need to operate on Port2
		{
			P2IE &= ~(1 << pin); //Clear Interrupt Enable Flag
			
		}

		return; //If pin does not match anything above, then return. 
	}
}


#pragma vector=PORT1_VECTOR, PORT2_VECTOR 

interrupt void port_isr(void)
{
	register volatile unsigned char count = 0;
	
	if (P1IFG > 0)
	{
		while(count < 8)
		{
			if (((P1IFG & bitmaskLookup[count]) > 0) && ((P1IE & bitmaskLookup[count]) > 0 ))
			{
				(*Port1FunctionVector[count])();  /* Call a function in array. No offset is needed since this is Port 1. */
				P1IFG &= ~(bitmaskLookup[count]); /* Clear the interrupt flag in P1IFG. */
				break;
			}
			else
			{
				count++;
			}
		}
	}
	
	if (P2IFG > 0)
	{
		while(count < 8)
		{
			if ( ((P2IFG & bitmaskLookup[count] ) > 0) && ((P2IE & bitmaskLookup[count] ) > 0 ))
			{
				(*Port2FunctionVector[count])();  /*Call a function in array. No offset is needed since this is Port 1. */
				P2IFG &= ~(bitmaskLookup[count]); /*Clear the interrupt flag in P1IFG. */
				break;
			}
			else
			{
				count++;
			}
		}
	}
	
	return;
}

#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)

void pinHigh(unsigned short int pin)
{

#ifdef _EM_HASPORTA
	
	if (pin <= 15)
	{
		PAOUT |= (1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTB
	
	if (pin <= 15)
	{
		PBOUT |= (1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTC
	
	if (pin <= 15)
	{

		PCOUT |= (1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTD
	
	if (pin <= 15)
	{
		PDOUT |= (1 << pin);

		return;
	}
#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTE
	
	if (pin <= 15)
	{

		PEOUT |= (1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTF
	
	if (pin <= 15)
	{

		PFOUT |= (1 << pin);

		return;
	}

#endif
	
#ifdef _EM_HASPORTJ
	
	if (pin <= 15)
	{

		PJOUT |= (1 << pin);

	}

#endif
	
	return; /* Seems like the pin number was out of range, so just return */
}

void pinLow(unsigned short int pin)
{

#ifdef _EM_HASPORTA
	
	if (pin <= 15)
	{

		PAOUT &= ~(1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTB
	
	if (pin <= 15)
	{

		PBOUT &= ~(1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTC
	
	if (pin <= 15)
	{
		PCOUT &= ~(1 << pin);

		return;
	}

#endif

	pin = pin - 16;

#ifdef _EM_HASPORTD
	
	if (pin <= 15)
	{
		PDOUT &= ~(1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTE
	
	if (pin <= 15)
	{

		PEOUT &= ~(1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTF
	
	if (pin <= 15)
	{

		PFOUT &= ~(1 << pin);

		return;
	}

#endif

#ifdef _EM_HASPORTJ
	
	if (pin <= 15)
	{

		PJOUT &= ~(1 << pin);

	}

#endif
	
	return; /* Seems like the pin number was out of range, so just return. Also somewhat pointless if this function is inlined... */
}

void pinMode(unsigned short int pin, unsigned short int state)
{
	/* Function flow

	 This function first checks state by checking if it is higher than 1.

	 0 - Which would be INPUT
	 1 - Which would be OUTPUT

	 */

	if (state > OUTPUT)
	{
		return;
	}

#ifdef _EM_HASPORTA
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PADIR |= (1 << pin);
		}
		else
		{
			PADIR &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORTA */
	
	pin = pin - 16;

#ifdef _EM_HASPORTB
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PBDIR |= (1 << pin);
		}
		else
		{
			PBDIR &= ~(1 << pin);
		}

		return;
	}

#endif /*_EM_HASPORTB*/
	
	pin = pin - 16;

#ifdef _EM_HASPORTC
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PCDIR |= (1 << pin);
		}
		else
		{
			PCDIR &= ~(1 << pin);
		}

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTD
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PDDIR |= (1 << pin);
		}
		else
		{
			PDDIR &= ~(1 << pin);
		}

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTE
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PEDIR |= (1 << pin);
		}
		else
		{
			PEDIR &= ~(1 << pin);
		}

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef _EM_HASPORTF
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PFDIR |= (1 << pin);
		}
		else
		{
			PFDIR &= ~(1 << pin);
		}

		return;
	}

#endif
	
#ifdef _EM_HASPORTJ
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PJDIR |= (1 << pin);
		}
		else
		{
			PJDIR &= ~(1 << pin);
		}
	}
#endif
	
	return;
}

void pinToggle(unsigned short int pin)
{

#ifdef _EM_HASPORTA

	if (pin <= 15)
	{
		PAOUT ^= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTA */

	pin = pin - 16;

#ifdef _EM_HASPORTB

	if (pin <= 15)
	{
		PBOUT ^= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTB */

	pin = pin - 16;

#ifdef _EM_HASPORTC

	if (pin <= 15)
	{
		PCOUT ^= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTC */

	pin = pin - 16;

#ifdef _EM_HASPORTD

	if (pin <= 15)
	{
		PDOUT ^= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTD */

	pin = pin - 16;

#ifdef _EM_HASPORTE

	if (pin <= 15)
	{
		PEOUT ^= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTE */

	pin = pin - 16;

#ifdef _EM_HASPORTF

	if (pin <= 15)
	{
		PFOUT ^= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTF */

#ifdef _EM_HASPORTJ

	if (pin <= 15)
	{
		PJOUT ^= (1 << pin);

	}

#endif /* _EM_HASPORTJ */

	return;
}

bool pinRead(unsigned short int pin)
{

#ifdef _EM_HASPORTA

	if (pin <= 15)
	{
		if ((PAIN & (1 << pin)) > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* _EM_HASPORTA */
	
	pin = pin - 16;

#ifdef _EM_HASPORTB
	
	if (pin <= 15)
	{
		auto unsigned short int result = PBIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /*_EM_HASPORTB*/
	
	pin = pin - 16;

#ifdef _EM_HASPORTC
	
	if (pin <= 15)
	{
		auto unsigned short int result = PCIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* _EM_HASPORTC */
	
	pin = pin - 16;

#ifdef _EM_HASPORTD

	if (pin <= 15)
	{
		auto unsigned short int result = PDIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* _EM_HASPORTD */
	
	pin = pin - 16;

#ifdef _EM_HASPORTE

	if (pin <= 15)
	{
		auto unsigned short int result = PEIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* _EM_HASPORTE */
	
	pin = pin - 16;

#ifdef _EM_HASPORTF
	
	if (pin <= 15)
	{
		auto unsigned short int result = PFIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* _EM_HASPORTF */
	
#ifdef _EM_HASPORTJ

	if (pin <= 15)
	{
		auto unsigned short int result = PJIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* _EM_HASPORTJ */
	
	return (LOW);
}

void pinDriveStrength(unsigned short int pin, unsigned short int level)
{

#if (_EM_SERIES == 5) || (_EM_SERIES == 6)

	if (level > 1)
	{
		return;
	}

#ifdef _EM_HASPORTA
	
	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PADS |= (1 << pin);
		}
		else
		{
			PADS &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORTA */
	
	pin = pin - 16;

#ifdef _EM_HASPORTB
	
	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PBDS |= (1 << pin);
		}
		else
		{
			PBDS &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORTB */

	pin = pin - 16;

#ifdef _EM_HASPORTC

	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PCDS |= (1 << pin);
		}
		else
		{
			PCDS &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORTC */
	
	pin = pin - 16;

#ifdef _EM_HASPORTD

	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PDDS |= (1 << pin);
		}
		else
		{
			PDDS &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORTD */
	
	pin = pin - 16;

#ifdef _EM_HASPORTE
	
	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PEDS |= (1 << pin);
		}
		else
		{
			PEDS &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORTE */
	
	pin = pin - 16;

#ifdef _EM_HASPORTF
	
	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PFDS |= (1 << pin);
		}
		else
		{
			PFDS &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORTF */
	
#ifdef _EM_HASPORTJ
	
	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PJDS |= (1 << pin);
		}
		else
		{
			PJDS &= ~(1 << pin);
		}

		return;
	}

#endif /* _EM_HASPORTJ */
	
	return;

#else

	asm("	.wmsg	\" pinDriveStrength() is not supported on this device. Error code FUNCNOTSUPPORTED \"");
	return;
#endif
}

void pinPullUp(unsigned short int pin)
{
#ifdef _EM_HASPORTA

	if (pin <= 15)
	{
		PAREN |= (1 << pin);
		PAOUT |= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTA */

	pin = pin - 16;

#ifdef _EM_HASPORTB

	if (pin <= 15)
	{
		PBREN |= (1 << pin);
		PBOUT |= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTB */

	pin = pin - 16;

#ifdef _EM_HASPORTC

	if (pin <= 15)
	{
		PCREN |= (1 << pin);
		PCOUT |= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTC */

	pin = pin - 16;

#ifdef _EM_HASPORTD

	if (pin <= 15)
	{
		PDREN |= (1 << pin);
		PDOUT |= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTD */

	pin = pin - 16;

#ifdef _EM_HASPORTE

	if (pin <= 15)
	{
		PEREN |= (1 << pin);
		PEOUT |= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTE */

	pin = pin - 16;

#ifdef _EM_HASPORTF

	if (pin <= 15)
	{
		PFREN |= (1 << pin);
		PFOUT |= (1 << pin);
		return;
	}

#endif /* _EM_HASPORTF */

#ifdef _EM_HASPORTJ

	if (pin <= 15)
	{
		PJREN |= (1 << pin);
		PJOUT |= (1 << pin);
	}

#endif /* _EM_HASPORTJ */

	return;

}

void pinPullDown(unsigned short int pin)
{
#ifdef _EM_HASPORTA

	if (pin <= 15)
	{
		PAREN |= (1 << pin);
		PAOUT &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTA */

	pin = pin - 16;

#ifdef _EM_HASPORTB

	if (pin <= 15)
	{
		PBREN |= (1 << pin);
		PBOUT &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTB */

	pin = pin - 16;

#ifdef _EM_HASPORTC

	if (pin <= 15)
	{
		PCREN |= (1 << pin);
		PCOUT &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTC */

	pin = pin - 16;

#ifdef _EM_HASPORTD

	if (pin <= 15)
	{
		PDREN |= (1 << pin);
		PDOUT &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTD */

	pin = pin - 16;

#ifdef _EM_HASPORTE

	if (pin <= 15)
	{
		PEREN |= (1 << pin);
		PEOUT &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTE */

	pin = pin - 16;

#ifdef _EM_HASPORTF

	if (pin <= 15)
	{
		PFREN |= (1 << pin);
		PFOUT &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTF */

#ifdef _EM_HASPORTJ

	if (pin <= 15)
	{
		PJREN |= (1 << pin);
		PJOUT &= ~(1 << pin);
	}

#endif /* _EM_HASPORTJ */

	return;
}

void pinPullOff(unsigned short int pin)
{
#ifdef _EM_HASPORTA

	if (pin <= 15)
	{
		PAREN &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTA */

	pin = pin - 16;

#ifdef _EM_HASPORTB

	if (pin <= 15)
	{
		PBREN &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTB */

	pin = pin - 16;

#ifdef _EM_HASPORTC

	if (pin <= 15)
	{
		PCREN &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTC */

	pin = pin - 16;

#ifdef _EM_HASPORTD

	if (pin <= 15)
	{
		PDREN &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTD */

	pin = pin - 16;

#ifdef _EM_HASPORTE

	if (pin <= 15)
	{
		PEREN &= ~(1 << pin);
		return;
	}

#endif /*  _EM_HASPORTE */

	pin = pin - 16;

#ifdef _EM_HASPORTF

	if (pin <= 15)
	{
		PFREN &= ~(1 << pin);
		return;
	}

#endif /* _EM_HASPORTF */

#ifdef _EM_HASPORTJ

	if (pin <= 15)
	{
		PJREN &= ~(1 << pin);
	}

#endif /* _EM_HASPORTJ */

	return;
}

void portWriteWord(const unsigned short int port, unsigned short int data)
{

#if (_EM_SERIES == 5) || (_EM_SERIES == 6)

	switch (port)
	{

#	ifdef _EM_HASPORTA

		case PORTA:
			PAOUT = data;
			break;

#	endif /* _EM_HASPORTA */

#	ifdef _EM_HASPORTB

		case PORTB:
			PBOUT = data;
			break;

#	endif /* _EM_HASPORTB */

#	ifdef _EM_HASPORTC

		case PORTC:
			PCOUT = data;
			break;

#	endif /* _EM_HASPORTC */

#	ifdef _EM_HASPORTD

		case PORTD:
			PDOUT = data;
			break;

#	endif /* _EM_HASPORTD */

#	ifdef _EM_HASPORTE

		case PORTE:
			PEOUT = data;
			break;

#	endif /* _EM_HASPORTE */

#	ifdef _EM_HASPORTF

		case PORTF:
			PFOUT = data;
			break;

#	endif /* _EM_HASPORTF */

#	ifdef _EM_HASPORTJ

		case PORTJ:
			PJOUT = data;
			break;

#	endif /* _EM_HASPORTJ */

		default:
			break;

	}

#else
	asm("	.wmsg	\" portWriteWord() is not supported on this device. Error code FUNCNOTSUPPORTED \"");
	return;
#endif
}

unsigned short int portReadWord(const unsigned short int port)
{

#if (_EM_SERIES == 5) || (_EM_SERIES == 6)

	switch (port)
	{

#	ifdef _EM_HASPORTA

		case PORTA:
			return (PAIN);

#	endif /* _EM_HASPORTA */

#	ifdef _EM_HASPORTB

		case PORTB:
			return (PBIN);

#	endif /* _EM_HASPORTB */

#	ifdef _EM_HASPORTC

		case PORTC:
			return (PCIN);

#	endif /* _EM_HASPORTC */

#	ifdef _EM_HASPORTD

		case PORTD:
			return (PDIN);

#	endif /* _EM_HASPORTD */

#	ifdef _EM_HASPORTE

		case PORTE:
			return (PEIN);

#	endif /* _EM_HASPORTE */

#	ifdef _EM_HASPORTF

		case PORTF:
			return (PFIN);

#	endif /* _EM_HASPORTF */

#	ifdef _EM_HASPORTJ

		case PORTJ:
			return (PJIN);

#	endif /* _EM_HASPORTJ */

		default:
			return (0); /* Would love to use _never_executed() here, but we have to return something */

	}

#else

	asm("	.wmsg	\" PortReadWord() is not supported on this device. Error code FUNCNOTSUPPORTED \"");
	return (NULL);

#endif

}

void portWriteDirWord(const unsigned short int port, unsigned short int data)
{

#if (_EM_SERIES == 5) || (_EM_SERIES == 6)

	switch (port)
	{

#	ifdef _EM_HASPORTA

		case PORTA:
			PADIR = data;
			break;

#	endif /* _EM_HASPORTA */

#	ifdef _EM_HASPORTB

		case PORTB:
			PBDIR = data;
			break;

#	endif /* _EM_HASPORTB */

#	ifdef _EM_HASPORTC

		case PORTC:
			PCDIR = data;
			break;

#	endif /* _EM_HASPORTC */

#	ifdef _EM_HASPORTD

		case PORTD:
			PDDIR = data;
			break;
#	endif /* _EM_HASPORTD */

#	ifdef _EM_HASPORTE

		case PORTE:
			PEDIR = data;
			break;

#	endif /* _EM_HASPORTE */

#	ifdef _EM_HASPORTF

		case PORTF:
			PFDIR = data;
			break;

#	endif /* _EM_HASPORTF */

#	ifdef _EM_HASPORTJ

		case PORTJ:
			PJDIR = data;
			break;

#	endif /* _EM_HASPORTJ */

		default:
			break;

	}

#else

	asm("	.wmsg	\" portWriteDirWord() is not supported on this device. Error code FUNCNOTSUPPORTED \"");
	return;

#endif
}

void attachInterrupt(unsigned short int pin, unsigned short int edge, void (*function)(void))
{
	if (pin <= 7)
	{
		if (edge == HIGH_TO_LOW)
		{
			P1IES |= (1 << pin);
		}
		else if (edge == LOW_TO_HIGH)
		{
			P1IES &= ~(1 << pin);
		}
		else
		{
			return;
		}

		Port1FunctionVector[pin] = function;

		P1IFG &= ~(1 << pin);
		P1IE |= (1 << pin);

		return;
	}
	else
	{
		pin = pin - 8;

		if (pin <= 7)
		{
			if (edge == HIGH_TO_LOW)
			{
				P2IES |= (1 << pin);
			}
			else if (edge == LOW_TO_HIGH)
			{
				P2IES &= ~(1 << pin);
			}
			else
			{
				return;
			}

			Port2FunctionVector[pin] = function;

			P2IFG &= ~(1 << pin);
			P2IE |= (1 << pin);

			return;
		}
	}

	return;
}

void removeInterrupt(unsigned short int pin)
{
	if (pin <= 7) //If pin is less or equal to 7, then we need to operate on Port1
	{
		P1IE &= ~(1 << pin); //Clear Interrupt Enable flag

		return;//Exit
	}
	else //Check again if pin is less or equal to 7
	{
		pin = pin - 8; //Offset pin by 8.

		if (pin <= 7)//If pin is less than or equal to 7, then we need to operate on Port2
		{
			P2IE &= ~(1 << pin); //Clear Interrupt Enable Flag

			return;//Exit
		}

		return; //If pin does not match anything above, then return.
	}
}

extern void portWriteWord(const unsigned short int na0, unsigned short int na1)
{
	return;
}

extern void portWriteDirWord(const unsigned short int na0, unsigned short int na1)
{
	return;
}

extern unsigned short int portReadWord(const unsigned short int na0)
{
	return (NULL);
}

extern void pinDriveStrength(unsigned short int na0, unsigned short int na1)
{
	return;
}

#pragma vector=PORT1_VECTOR
interrupt void port1_isr(void)
{
	switch (__even_in_range(P1IV, P1IV_P1IFG7))
	{
		case P1IV_NONE:
			break;

		case P1IV_P1IFG0:
			(*Port1FunctionVector[0])();
			break;

		case P1IV_P1IFG1:
			(*Port1FunctionVector[1])();
			break;

		case P1IV_P1IFG2:
			(*Port1FunctionVector[2])();
			break;

		case P1IV_P1IFG3:
			(*Port1FunctionVector[3])();
			break;

		case P1IV_P1IFG4:
			(*Port1FunctionVector[4])();
			break;

		case P1IV_P1IFG5:
			(*Port1FunctionVector[5])();
			break;

		case P1IV_P1IFG6:
			(*Port1FunctionVector[6])();
			break;

		case P1IV_P1IFG7:
			(*Port1FunctionVector[7])();
			break;

		default:
			break;

	}
}

#pragma vector = PORT2_VECTOR
interrupt void port2_isr(void)
{
	switch (__even_in_range(P2IV, P1IV_P1IFG7))
	{
		case P2IV_NONE:
			break;

		case P2IV_P2IFG0:
			(*Port2FunctionVector[0])();
			break;

		case P2IV_P2IFG1:
			(*Port2FunctionVector[1])();
			break;

		case P2IV_P2IFG2:
			(*Port2FunctionVector[2])();
			break;

		case P2IV_P2IFG3:
			(*Port2FunctionVector[3])();
			break;

		case P2IV_P2IFG4:
			(*Port2FunctionVector[4])();
			break;

		case P2IV_P2IFG5:
			(*Port2FunctionVector[5])();
			break;

		case P2IV_P2IFG6:
			(*Port2FunctionVector[6])();
			break;

		case P2IV_P2IFG7:
			(*Port2FunctionVector[7])();
			break;

		default:
			break;

	}

}

#endif 


#ifdef _EM_SERIES

void shiftConfig(unsigned short int order, unsigned short int pol)
{

	if (order == LSBFIRST)
	{
		_shiftConfigBits |= BIT0;
	}
	else
	{
		_shiftConfigBits &= ~BIT0;
	}

	if (pol)
	{
		_shiftConfigBits |= BIT1;
	}
	else
	{
		_shiftConfigBits &= ~BIT1;
	}
}

void shiftOut(unsigned short int sdat, unsigned short int sclk, unsigned char data)
{
	auto unsigned short int bits = 8;

	do
	{
		if ( (_shiftConfigBits & BIT0) > 0)
		{
			if ( (data & 0x01) > 0)
			{
				pinHigh(sdat);
			}
			else
			{
				pinLow(sdat);
			}

			data >>= 1;
		}
		else
		{
			if ( (data & 0x80) > 0)

			{
				pinHigh(sdat);
			}
			else
			{
				pinLow(sdat);
			}

			data <<= 1;
		}

		if ( (_shiftConfigBits & BIT1) > 0)
		{
			pinLow(sclk);
		}
		else
		{
			pinHigh(sclk);
		}

		bits--;

		if ( (_shiftConfigBits & BIT1) > 0)
		{
			pinHigh(sclk);
		}
		else
		{
			pinLow(sclk);
		}
	}
	while (bits > 0);

	return;
}

void portWrite(const unsigned short int port, unsigned char data)
{
	switch (port)
	{

#	ifdef _EM_HASPORT1

		case PORT1:
			P1OUT = data;
			break;

#	endif /* _EM_HASPORT1 */

#	ifdef _EM_HASPORT2

		case PORT2:
			P2OUT = data;
			break;

#	endif /* _EM_HASPORT2 */

#	ifdef _EM_HASPORT3

		case PORT3:
			P3OUT = data;
			break;

#	endif /* _EM_HASPORT3 */

#	ifdef _EM_HASPORT4

		case PORT4:
			P4OUT = data;
			break;

#	endif /* _EM_HASPORT4 */

#	ifdef _EM_HASPORT5

		case PORT5:
			P5OUT = data;
			break;

#	endif /* _EM_HASPORT5 */

#	ifdef _EM_HASPORT6

		case PORT6:
			P6OUT = data;
			break;

#	endif /* _EM_HASPORT6 */

#	ifdef _EM_HASPORT7

		case PORT7:
			P7OUT = data;
			break;

#	endif /* _EM_HASPORT7 */

#	ifdef _EM_HASPORT8

		case PORT8:
			P8OUT = data;
			break;

#	endif /* _EM_HASPORT8 */

#	ifdef _EM_HASPORT9

		case PORT9:
			P9OUT = data;
			break;

#	endif /* _EM_HASPORT9 */

#	ifdef _EM_HASPORT10

		case PORT10:
			P10OUT = data;
			break;

#	endif /* _EM_HASPORT10 */

#	ifdef _EM_HASPORT11

		case PORT11:
			P11OUT = data;
			break;

#	endif /* _EM_HASPORT11 */

		default:
			break;
	}
}

unsigned char portRead(const unsigned short int port)
{
	switch (port)
	{

#	ifdef _EM_HASPORT1

		case PORT1:
			return(P1IN);

#	endif /* _EM_HASPORT1 */

#	ifdef _EM_HASPORT2

		case PORT2:
			return(P2IN);

#	endif /* _EM_HASPORT2 */

#	ifdef _EM_HASPORT3

		case PORT3:
			return(P3IN);

#	endif /* _EM_HASPORT3 */

#	ifdef _EM_HASPORT4

		case PORT4:
			return(P4IN);

#	endif /* _EM_HASPORT4 */

#	ifdef _EM_HASPORT5

		case PORT5:
			return(P5IN);

#	endif /* _EM_HASPORT5 */

#	ifdef _EM_HASPORT6

		case PORT6:
			return(P6IN);

#	endif /* _EM_HASPORT6 */

#	ifdef _EM_HASPORT7

		case PORT7:
			return(P7IN);

#	endif /* _EM_HASPORT7 */

#	ifdef _EM_HASPORT8

		case PORT8:
			return(P8IN);

#	endif /* _EM_HASPORT8 */

#	ifdef _EM_HASPORT9

		case PORT9:
			return(P9IN);

#	endif /* _EM_HASPORT9 */

#	ifdef _EM_HASPORT10

		case PORT10:
			return(P10IN);

#	endif /* _EM_HASPORT10 */

#	ifdef _EM_HASPORT11

		case PORT11:
			return(P11IN);

#	endif /* _EM_HASPORT11 */

		default:
			return (NULL);

	}
}

void portWriteDir(const unsigned short int port, unsigned char data)
{
	switch (port)
	{

#	ifdef _EM_HASPORT1
		case PORT1:
			P1DIR = data;
			return;
#	endif /* _EM_HASPORT1 */

#	ifdef _EM_HASPORT2
		case PORT2:
			P2DIR = data;
			return;
#	endif /* _EM_HASPORT2 */

#	ifdef _EM_HASPORT3
		case PORT3:
			P3DIR = data;
			return;
#	endif /* _EM_HASPORT3 */

#	ifdef _EM_HASPORT4
		case PORT4:
			P4DIR = data;
			return;
#	endif /* _EM_HASPORT4 */

#	ifdef _EM_HASPORT5
		case PORT5:
			P5DIR = data;
			return;
#	endif /* _EM_HASPORT5 */

#	ifdef _EM_HASPORT6
		case PORT6:
			P6DIR = data;
			return;
#	endif /* _EM_HASPORT6 */

#	ifdef _EM_HASPORT7
		case PORT7:
			P7DIR = data;
			return;
#	endif /* _EM_HASPORT7 */

#	ifdef _EM_HASPORT8
		case PORT8:
			P8DIR = data;
			return;
#	endif /* _EM_HASPORT8 */

#	ifdef _EM_HASPORT9
		case PORT9:
			P9DIR = data;
			return;
#	endif /* _EM_HASPORT9 */

#	ifdef _EM_HASPORT10
		case PORT10:
			P10DIR = data;
			return;
#	endif /* _EM_HASPORT10 */

#	ifdef _EM_HASPORT11
		case PORT11:
			P11DIR = data;
			return;
#	endif /* _EM_HASPORT11 */

		default:
			return;
	}
}

void digitalWrite(unsigned short int pin, unsigned short int state)
{
	if (state == HIGH)
	{
		pinHigh(pin);
	}
	else if (state == LOW)
	{
		pinLow(pin);
	}
	else
	{
		return;
	}
}

#endif /* End All device block */

#endif /* IO_C */
